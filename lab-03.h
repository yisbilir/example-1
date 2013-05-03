#define MAX_WORDLEN 50
#define MAX_WORDS   30000 /* Don't change this or you might overflow your allotted stack space. */
#define true 1
#define false 0

/* Use the following Macros to print EVERYTHING while executing the menu function */

/* Menu print */
#define printMenu() printf("Choose: 'P'rint, 'S'earch, 'I'nsert, 'R'emove, 'C'ount, 'Q'uit :\n")
#define optP() printf("You chose to 'P'rint:\n")
#define optS() printf("Enter word to 'S'earch:\n")
#define optI() printf("Enter word to 'I'nsert:\n")
#define optR() printf("Enter word to 'R'emove:\n")
#define optC() printf("You chose to 'C'ount:\n")
#define optQ() printf("You chose to 'Q'uit:\n")

/* Insert print */
#define printInserted(word) printf("%s was successfully inserted.\n", word)
#define printFailedToInsert(word) printf("Duplicate found, %s was not inserted.\n", word)

/* Remove print */
#define printRemove(word) printf("%s was successfully removed.\n", word)
#define printFailedToRemove(word) printf("%s cannot be found, and was not removed.\n", word)

/* Search print */
#define printFound(word) printf("%s was successfully found.\n", word)
#define printNotFound(word) printf("%s was not found.\n", word)

#define printCount(count) printf("%d words currently in the dictionary.\n", count)
void doMenu( char *outfileName, char ***dictionary, int *count, int *wordcapacity);
void printDictionary( char **dictionary, int count, FILE *stream );
int  binarysearch(char *word, char ***dictionary,int *count);
void removeWord( char ***dictionary, int *count, char *word );
void loadDictionary( char *infilname, char ***dictionary, int *count, int *wordcapacity );
void freeArray( char **arr, int wordcount);
void resize(char  ***oldarray, int *wordcapacity);
int insertInOrder(char ***dictionary,char *wordBuffer,  int *count, int *wordcapacity  );


