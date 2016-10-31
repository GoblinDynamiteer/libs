#include "libinput.h"

/* 
VERSION 1

2016-10-31
Första utgåvan
Flyttad funktioner inputInt(a) & inputDouble(a) från bibliotek: libtxt
Ny funktion: convertDecimalInput(char a)
	- Byter ut kommatecken till punkt i textsträng, konverterar till float, som returneras

Information:
Filen innehåller funktioner för användarinmatning till variabler.
*/



/* 
convertDecimalInput 
Letar upp evnetuellt decimaltecken i teckensträng , om det hittas byts det ut till en punkt.
Strängen konverteras till double med standardfunktionen strtod, vars retur returneras
*/
double convertDecimalInput(char *s){
	char *ptr;
	int n = 0;
	while(*s && *s != ','){
		s++;
		n++;
	}
	*s = '.';
	return strtod(s-n, &ptr);
}


/* inputInt
Skriver ut texten i char-variabel a, och tar en användarinläsning till int-variabel som returneras

Exempel användning:
int variabel = inputInt("Skriv in ett heltal: ");
 */
int inputInt(const char a[]){
	int temp;
	printf("%s", a);
	scanf("%d", &temp);
	return temp;
}

/* inputDouble
Skriver ut texten i char-variabel a, och tar en användarinläsning till double-variabel som returneras

Exempel användning:
double variabel = inputDouble("Skriv in ett decimaltal: ");
 */
double inputDouble(const char a[]){
	char temp[30];
	printf("%s", a);
	scanf("%s", temp);
	return convertDecimalInput(temp);
}

