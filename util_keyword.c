#include <stdlib.h>
#include <stdio.h>
#include "util_datatype.h"

int readFile(char * fileName, int * keywordLocation, char ** keywordArray)
{
  int returnValue = -1;
  int counter = 0;
  int arlength;
  char **arrayinput;

//Liest die Datei ein und zählt die Anzahl der Zeilen
   file = fopen(fileName, "r");

    while(fgets (buff, 200,file)){
	counter ++;
    }
   rewind(finle);
   printf("Diese Datei hat %d Zeilen", counter);

//Erstellt ein Array für die ganze Datei
   arlength  = counter;
   arrayinput =  calloc(arlength, sizeof(char*));

	for(int i = 0; i<=arlength; i++){
	   arrayinput[i] = calloc(200,sizeof(char));
	}
        counter = 0;
     
      while(fgets(buff,255,file)){
	snprintf(array[counter],255, "%s", buff);
	counter++;
      }

//Array für die Keywords wird erstellt
    keywordarray# = calloc(arlength, sizeof(char*));

	for(int i = 0;i<=arlength;i++){
	   keywordarray#[i] = calloc(5, sizeof(char));
	}

    keywordarray$ = calloc(arlength, sizeof(char*));

	for(int i = 0;i<=arlength;i++){
	   keywordarray$[i] = calloc(5,sizeof(char));
	}
//Die _Datei wird nach Keywords durchsucht
    for(int i = 0;i<=arlength;i++){
	int strstrausgabe = strstr(arrayinput[i],#); 
	if(strstr(arrayinput[i], #) > 0){
	  snprintf(keywordarray#[i][strstrausgabe],5, "%s", arrayinput[i]);
	}
	if(strstr(arrayinput[i],$) > 0){
	  snprintf(keywordarray$[i][strstrausgabe],5, "%s", arrayinput[i]);
	}


  
  return returnValue;
}
