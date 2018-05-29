#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "util_keyword.h"
#include "util_datatype.h"

/* function declaration */
int getValue(char *key, int fileLength, char **array);


int main(int argc, char *argv[]) {
    if(argc <= 1) {
        printf("Kein Argument wurde uebermittelt.");
        return 0;
    }
    int fileLength = 0;
    char *fileName = argv[1];
    int * keywordLocation = NULL;
    char ** keywordArray  = NULL;
    struct keywordRecord *keywordRecord;

    // Read and check file
    fileLength = readFile(fileName, keywordLocation, keywordArray);
    printf("leudeee was ist den des: %s", &(keywordArray[0])[0]);
//        if (fileLength > 0) {
////            dummy();
//            return 0;
//        }
//    }
//    int size          = (int) sizeof(keywordArray);
    printf("fileLenght size : %i\n", fileLength);
    // Speicher zuweisen
    int memAllocated      = 1;
    int tmpCounter        = 0;
    char **tmpArray       = calloc(fileLength, sizeof(char*));
    int *tmpLocationArray = calloc(fileLength, sizeof(int));
    int *tmpDuplicates    = calloc(fileLength, sizeof(int));

//    keywordArray          = calloc(5, sizeof(char*));
//    keywordLocation       = calloc(5, sizeof(int));
    keywordRecord         = calloc(fileLength, sizeof(struct keywordRecord));

    for (int i = 0; i < fileLength ; ++i) {
//        keywordArray[i] = calloc(5, sizeof(char));
        tmpArray[i] = calloc(5, sizeof(char));
//        tmpArray = calloc(tmpArray, i * sizeof(char*));
//        printf("test size : %i\n", sizeof(tmpArray));
    }

    printf("leuddee: %s", keywordArray[0]);
//    snprintf(tmpArray[0], 4, "%s", keywordArray[0]);

//    bool found = false;
//    for (int j = 0; j < fileLength; ++j) {
//        printf("testo nr: %i\n", j);
//
//        if(j >= memAllocated) {
//            tmpLocationArray = realloc(tmpLocationArray, (j * sizeof(int)));
//            keywordRecord    = realloc(keywordRecord, (j * sizeof(struct keywordRecord)));
//            printf("extra memory allocated\n");
//        }
//        found = false;
//        for (int i = 0; i < fileLength; ++i) {
//            printf("test: %s", keywordArray[j]);
//            printf("test2: %s", tmpArray[i]);
//            // check if string contains in tmpArray max 4 chars
//            if(strncmp(keywordArray[j], tmpArray[i], 4) == 0) {
//                if(i >= memAllocated) {
//                    tmpDuplicates = realloc(tmpDuplicates, (i * sizeof(int)));
//                    printf("teeeest\n");
//                }
//                printf("testo\n");
////
//                tmpDuplicates[i] = keywordLocation[j];
//                printf("duplicate : %d\n", tmpDuplicates[i]);
//                found = true;
//            } else {
//                printf("debuggg\n");
//            }
//        }
//        printf("testo end\n");
//
//        if(!found) {
//            snprintf(tmpArray[tmpCounter], 5, keywordArray[j]);
//            tmpLocationArray[tmpCounter] = keywordLocation[j];
//
//            // struct build
//            snprintf(keywordRecord[tmpCounter].name, 5, tmpArray[tmpCounter]);
//            keywordRecord[tmpCounter].row        = tmpLocationArray[tmpCounter];
//            tmpCounter++;
//            printf("tttt: %s", tmpArray[tmpCounter]);
//
//        } else {
//            int location = getValue(keywordArray[tmpCounter], fileLength, tmpArray);
//            keywordRecord[location].duplicates = tmpDuplicates;
//            printf("found true\n");
//        }
//    }

//    keywordArray    = tmpArray;
//    keywordLocation = tmpLocationArray;

    // free memory
//    free(tmpArray);
//    free(tmpLocationArray);

    // debug test
//    printf("---------------------------------\n");
//    for (int k = 0; k < tmpCounter; ++k) {
//        printf("struct name: %s\n", keywordRecord[k].name);
//        printf("struct row: %d\n", keywordRecord[k].row);
//        int duplicateSize = sizeof(keywordRecord[k].duplicates);
////        printf("duplicate size: %d\n", duplicateSize);
//        for (int i = 0; i < duplicateSize; ++i) {
//            if(keywordRecord[k].duplicates != NULL) {
//                printf("struct duplicate : %d\n", keywordRecord[k].duplicates[i]);
//            }
//        }
//    }

//    printf("Datei konnte nicht gelesen werden.");
    exit(0);
    // struct array in csv exportieren
}

int getValue(char *key, int size, char **array) {

//    int size = sizeof(array);
    int i;
    for (i = 0; i < size; i++) {
        if(strcmp(key, array[i]) == 0) {
            return i;
        }
    }
}
