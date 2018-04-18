#include <stdio.h>
#include <stdlib.h>
#include "util_keyword.h"
#include "util_datatype.h"

void main()
{
  //Dateiname:
  char fileName[256];
  int * keywordLocation;
  char ** keywordArray;

  int err = 0;

  err = readFile(fileName, keywordLocation, keywordArray);
  
  if (err < 0)
  {
    printf("Someting is wrong!!! ");
    exit(0);
  }
  
  dummy();

}

