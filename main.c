#include <stdio.h>
#include <stdlib.h>
#include "util_keyword.h"
#include "util_datatype.h"

int main(int argc, char *argv[]) {
    if(argc <= 1) {
        printf("Kein Argument wurde uebermittelt.");
        return 0;
    }


    char *fileName = argv[1];
    int * keywordLocation;
    char ** keywordArray;

    // Read and check file
    if(readFile(fileName, keywordLocation, keywordArray) > 0 ) {
        dummy();

        return 0;
    }
    printf("Datei konnte nicht gelesen werden.");
    exit(0);
}
