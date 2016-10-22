#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//För textformattering -- kräver system("cls") initialt i koden, för Windows
#define FORM_RED "\033[91m" 	//Röd textformatering (31 är mörk)
#define FORM_GREEN "\033[32m" 	//Grön textformatering
#define FORM_YELLOW "\033[33m" 	//Gul textformatering
#define FORM_BLUE "\033[94m" 	//Blå textformatering (34 är väldigt mörk)
#define FORM_CYAN "\033[36m" 	//Cyan (Ungefär ljusblå) textformatering
#define FORM_UNDER "\033[4m" 		//Understruken textformatering
#define FORM_END "\033[0m" 		//Återställer textformatering

 //För utskrift av linjer med printf
#define ADD_LINE "\n-----------------------------------------------------------------\n"

//Funktionsdeklarationer
_Bool removeNewLine(char[]);
void clearBuffer(void);
void clearBufferFil(FILE *f);
_Bool radInput(char[], int);
_Bool textfilTillString(char[], int, FILE *f);
_Bool TTS(char *a, int n, FILE *f);