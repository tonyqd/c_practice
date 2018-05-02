#include <stdlib.h>
#include <stdio.h>
#include "util_datatype.h"

int readFile(char * fileName, int * keywordLocation, char ** keywordArray)
{
  int returnValue = -1;
  int counter = 0;
  int arlength;
  int strstrausgabe;
  int strstrausgabe2;
  char **arrayinput;
  char **backupKeywordArray;
  int  *backupLocationArray;
  char buff[500];
  FILE *file;

//Liest die Datei ein und zählt die Anzahl der Zeilen
    file = fopen(fileName, "r");
    while(fgets (buff, 200,file)){
       counter ++;
    }
    rewind(file);
    printf("Diese Datei hat %d Zeilen", counter);

//Erstellt ein Array für die ganze Datei
   arlength  = counter;
   arrayinput =  calloc(arlength, sizeof(char*));

	for(int i = 0; i < arlength; i++){
	   arrayinput[i] = calloc(200,sizeof(char));
	}
        counter = 0;
     
        while(fgets(buff,255,file)){
	snprintf(arrayinput[counter],255, "%s", buff);
	counter++;
      }

//BackupArray für die Keywords wird erstellt
    backupKeywordArray = calloc(arlength, sizeof(char*));
	for(int i = 0;i < arlength;i++){
	   backupKeywordArray[i] = calloc(5, sizeof(char));
	}

    backupLocationArray = calloc(arlength, sizeof(int*));
	for(int i = 0;i<=arlength;i++){
	   backupLocationArray[i] = calloc(2,sizeof(int));
	}
//Die Datei wird nach Keywords durchsucht und in ein Backuparray kopiert
    for(int i = 0;i<=arlength;i++){
	strstrausgabe = 0;
	strstrausgabe = strstr(arrayinput[i],"#"); 
	strstrausgabe2 = 0;
	strstrausgabe2 = strstr(arrayinput[i],"$"); 
	if(strstrausgabe > 0){
	  snprintf(backupKeywordArray[i],5, "%4s", &(arrayinput[i][strstrausgabe]));
	  snprintf(backupLocationArray[i],2, "%d", strstrausgabe);
	}else if(strstrausgabe2 > 0){
	  snprintf(backupKeywordArray[i],5, "%4s", &(arrayinput[i][strstrausgabe2]));
	  snprintf(backupLocationArray[i],2, "%d" , strstrausgabe2);
	
	}
      }	
//Die Datei wird auf das Array zum durchchecken kopiert
	keywordArray = calloc(arlength, sizeof(char*));
	for(int i = 0; i<= arlength; i++){
	   keywordArray[i] = calloc(5, sizeof(char));
	}
	keywordLocation = calloc(arlength, sizeof(int*));
	for(int i = 0; i<= arlength; i++){
	   keywordLocation[i] = calloc(5, sizeof(int));
	}
	for(int i = 0; i<=arlength; i++){
	snprintf(keywordArray[i], 5, "s", &(arrayinput[i]));
	}






  return returnValue;
}
