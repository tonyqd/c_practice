#include <stdlib.h>
#include <stdio.h>
#include "util_datatype.h"
#include <string.h>


int strstrAufloesung(char *input, char *Keyword){
  char *result = NULL;
  int ret = 0;

      result = strstr(input, Keyword);
	if(result == NULL){
	  ret = -1;
	}else{
	  ret = result - input + 1;  //das gibt die Differenz zwischen der Stelle des Results(Keywords) und des Anfangs der Zeile => Somit kommt eine Zahl raus
	}
  return ret;                        //Ret wird dann zur  strstrausgabe

}

int readFile(char * fileName, int * keywordLocation, char ** keywordArray)
{
  int returnValue = -1;
  int counter = 0;
  int fileLength = 0; 
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
    printf("filename: %s", fileName);

    while(fgets (buff, 200,file)){
       counter ++;
    }
    rewind(file);
    fileLength = counter;
    printf("\niese Datei hat %d Zeilen\n", fileLength);

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

//Die Datei wird nach Keywords durchsucht und in ein Backuparray kopiert
counter = 0; // Man verwendet einen Counter und nicht i für das Array, sodass alle Zeilen, wo kein Keyword steht nicht nutzlos verwendet werden.
printf("\narlength: %i\n", arlength);
    for(int i = 0;i<arlength;i++){
	strstrausgabe = 0;
	strstrausgabe = strstrAufloesung(arrayinput[i], "#");
	strstrausgabe2 = 0;
	strstrausgabe2 = strstrAufloesung(arrayinput[i], "$");
	if(strstrausgabe > 0){
	  snprintf(backupKeywordArray[counter], 5 , "%4s", &(arrayinput[i][strstrausgabe-1]));  //-1 für den Ausgleich der +1 für die Funktion oben damit die Position des Keywords gleich bleibt
	  backupLocationArray[counter] = strstrausgabe;
          printf("Zeile: %i Keyword: %s Location: %i \n",i,  backupKeywordArray[counter], backupLocationArray[counter]);
	  counter++;
	}else if(strstrausgabe2 > 0){
	  snprintf(backupKeywordArray[counter], 5 , "%4s", &(arrayinput[i][strstrausgabe2-1]));
	  backupLocationArray[counter] = strstrausgabe2;
          printf("Zeile: %i Keyword: %s Location: %i \n",i,  backupKeywordArray[counter], backupLocationArray[counter]);
	  counter++;
	}
     }

//backup falls doch nicht funktioniert!
/*
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
*/      


//Die Keywords werden auf das finale Array kopiert

	keywordArray = calloc(counter, sizeof(char*));
	for(int i = 0; i< counter; i++){
	   keywordArray[i] = calloc(5, sizeof(char));
	}
        for(int i = 0; i<counter; i++){
	snprintf(keywordArray[i], 5, "%s", backupKeywordArray[i]);
	}
//Die Locations der Keywords werden auf das finale Array kopiert
	keywordLocation = calloc(counter, sizeof(int));
	for(int i = 0; i< counter; i++){
	   keywordLocation[i] = backupLocationArray[i];
	}

returnValue = counter;
printf("returnValue: %i", returnValue);

  
for(int i = 0; i < arlength; i++){
   free(backupKeywordArray[i]);
}
free(backupKeywordArray);
free(backupLocationArray);




  return returnValue;
}
