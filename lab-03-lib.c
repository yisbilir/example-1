#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> /* toupper() function and others */
#include "getline.h"
#include "lab-03.h"

void doMenu( char *outfileName, char ***dictionary, int *count, int *wordcapacity)
{
FILE *outfile;
char ch;
char *bufferword;
int i;
        while(true)
{
printMenu();
scanf(" %c%*[^\n]", &ch);
getchar();

if ( ch=='p'||ch=='P'){
optP();
printDictionary(*dictionary, *count,stdout);
}
if (ch=='s' || ch=='S' ){
optS();
fgetline_123(&bufferword,stdin);
i=binarysearch(bufferword,dictionary,count);
        if(i<=0)
        {
           printFound(bufferword);
        }
        else
        {
          printNotFound(bufferword);
        }
free(bufferword);
}


if  (ch== 'i' ||  ch=='I')
{optI();
fgetline_123(&bufferword , stdin);
if(insertInOrder(dictionary,bufferword, count,wordcapacity) )
{
        printInserted(bufferword);
}

}
if  (ch== 'r' ||ch== 'R') {
optR();
fgetline_123(&bufferword, stdin);
removeWord(dictionary,count,bufferword);
free(bufferword);
}

if  (ch=='c' ||ch== 'C')
{optC();
printCount(*count);
}
if (ch== 'q' ||ch== 'Q')
{optQ();
outfile=fopen(outfileName, "wt");
printDictionary(*dictionary,*count,outfile );
fclose(outfile);
return;}
}}



/* From the menu this gets called everytime the user selects 'P'rint. In this case you just pass in stdout
    for the st:0:ream arg.  If the user type 'Q'uit then you must first open up the output file and pass in the
    file handle.  Be sure to close that file as soon as this function is done. */

void printDictionary( char **dictionary, int count, FILE *stream )
{
        FILE *output;

        int i,ali;
        int sum=0;
        output=stream;

        for(i=0; i<count; i++)
        {
                ali=strlen(dictionary[i]);
                sum+=ali + 1;



                if(sum>80 && i!=0)
                {
                        fprintf(output, "\n");
                        sum = ali + 1;
                }

                fprintf(output,"%s ", dictionary[i]);
                if(i==(count-1))

                fprintf(output,"\n");
        }
        return;
}
int  binarysearch(char *word, char ***dictionary,int *count)

{
int high,low,mid;
high=*count;
low=0;
while(low<high)
{
        mid= (low+high)/2;
        if ( strcmp ((*dictionary)[mid],word)==0)
        {
                return -mid-1;

        }
        if ( strcmp((*dictionary)[mid],word)<0)
              low=mid+1;
        else if( strcmp((*dictionary)[mid],word)>0)

              high=mid;
}

         if ( low<(*count) && strcmp((*dictionary)[low],word)==0)
         {
                return -low-1;

         }
         else
         {
                return low;
         }

 }


void removeWord( char ***dictionary, int *count, char *word )
{ int i,j;
  i=binarysearch(word,dictionary,count);
  if(i>=0)
  {
    printFailedToRemove(word);
  }
  else
  {
    i = -i-1;
    free((*dictionary)[i]);
    for(j=i ;j<(*count)-1; j++)
                                  {

                                         (*dictionary)[j]=(*dictionary)[j+1];




                                  }
                                        printRemove(word);
                                        (*count)-- ;
                              }
  return;
  }




/* LOADDICTIONARY

*/
void loadDictionary( char *infilname, char ***dictionary, int *count, int *wordcapacity )
{       FILE *infile;
        char *wordBuffer;
        infile=fopen( infilname, "rt");
        if (infile==NULL)
        { fprintf(stdout," Can't open %s for input.\n", infilname);
          exit(EXIT_FAILURE);}
        /* open file as text for reading.  Test for failure.   Abort program (exit)  with errmsg if open fails */

        while ( fgetline_123(&wordBuffer,infile )  )
        {

                insertInOrder( dictionary, wordBuffer, count,wordcapacity );
        }
        fclose( infile );

return;
}

void freeArray( char **arr, int wordcount)
{       int i;
        for(i=0 ; i <(wordcount) ; i++)
                free( arr[i] );
        free(arr);

}
void resize( char  ***dictionary, int *wordcapacity)
{
   int i;

        char **newarray = malloc(2*(*wordcapacity)*sizeof(char *));
        for(i=0;i<(*wordcapacity); i++)
          /*memmove(&(newarray)[i],&(*dictionary)[i],sizeof(char *));*/
          newarray[i]= (*dictionary)[i];

        free(*dictionary);
        (*wordcapacity)*=2;
        *dictionary=newarray;
        return ;
}
int insertInOrder(char ***dictionary,char *wordBuffer,  int *count, int *wordcapacity  )
{
        int i, j;


        if ((*count)==0){
                (*dictionary)[0] = wordBuffer;

                (*count)=(*count)+1;

                return 1;
        }
        else if ((*count)!=0)
 {

                         if(((*count)+1)>(*wordcapacity))
                         {
                           resize(dictionary,wordcapacity);

                         }
                         i=binarysearch(wordBuffer,dictionary,count);
                                 if(i<0)
                                         {
                                               printFailedToInsert(wordBuffer);
                                               free(wordBuffer);
                                               return 0;
                                         }
                                 else if(i>=0)
                                {
                                  for(j=(*count) ;i<j; j--)
                                  {


                                         (*dictionary)[j]=(*dictionary)[j-1];

                                  }

                                         (*dictionary)[i] = wordBuffer;

                                         (*count)++;
                                         return 1;
                                 }
 }
return 1;

}
                                      
