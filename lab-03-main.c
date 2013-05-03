#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> /* toupper() function and others */
#include "getline.h"
#include "lab-03.h"
int main( int argc, char *argv[] )
{
        time_t startTime, stopTime;
        clock_t startCPU, stopCPU;
        double elapsedCPUsecs;



        char **dictionary=malloc(50*sizeof(char*));
        int count=0;
        int wordcapacity=50;
        if (argc < 3 )
        {
                printf("usage: ./%s <infileName> <outFilename>\n",argv[0]); /* you gotta put in & out file names on cmd line! */
                return EXIT_FAILURE;
        }       startTime = time( NULL );
        printf("\nStarting load of %s at %s", argv[1], ctime( &startTime) );

        startCPU = clock();
        loadDictionary( argv[1],&dictionary, &count, &wordcapacity);
        stopCPU = clock();
        stopTime = time( NULL );
        printf("Finished load of %s at %s", argv[1], ctime( &stopTime) );
        elapsedCPUsecs = ((double)(stopCPU-startCPU)) / CLOCKS_PER_SEC;
        printf("Elapsed CPU seconds: %f\n",  elapsedCPUsecs );
        doMenu( argv[2],  &dictionary, &count, &wordcapacity);
        freeArray(dictionary, count);
        return EXIT_SUCCESS; /* EXIT_SUCCESS defined as 0 in stdlib.h */
}


