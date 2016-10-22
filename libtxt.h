#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Definitioner för textformatering, skriv ut i printf-satser
Kräver system("cls") initialt i koden, för Windows

ANSI-escape-koder: Används för t.ex formatering av text
ESC + [ + kod används för att mata in ANSI-escape-koder
\033 (oktalt) är escape-koden för tecknet Escape, det går också att använda \x1b för det hexadecimala värdet

ANSI-escape + n m 
där n är 31 - 37: Sätter olika färger på texten
där n är 91 - 97: Sätter olika färger på texten, högintensivt
där n är 40 - 47: Sätter olika färger på textens bakgrund
där n är 0: Återställer
m används för att indikera slut på formateringskoder

Exempel: \033[91;43m TEXT ger intensiv röd teckenfärg med gul bakgrund

Källa:
https://en.wikipedia.org/wiki/Escape_character 
https://en.wikipedia.org/wiki/ANSI_escape_code*/

#define FORM_RED "\033[91m" 		//Röd textformatering (31 är mörk)
#define FORM_GREEN "\033[32m" 	//Grön textformatering
#define FORM_YELLOW "\033[33m" 	//Gul textformatering
#define FORM_BLUE "\033[94m" 		//Blå textformatering (34 är väldigt mörk)
#define FORM_CYAN "\033[36m" 		//Cyan (Ungefär ljusblå) textformatering
#define FORM_UNDER "\033[4m" 		//Understruken textformatering
#define FORM_END "\033[0m" 			//Återställer textformatering

//För utskrift av linjer med printf
#define ADD_LINE "\n-----------------------------------------------------------------\n"


//Funktionsdeklarationer för funktioner i libtxt.c
_Bool removeNewLine(char[]);
void clearBuffer(void);
void clearBufferFil(FILE *f);
_Bool radInput(char[], int);
_Bool textfilTillString(char[], int, FILE *f);
_Bool TTS(char *a, int n, FILE *f);