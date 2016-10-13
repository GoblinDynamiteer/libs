#include "replace_v1.h"

/*TESTVERSION 1
2016-10-05
fungerar initialt med de tester jag gjort
dock r�rig/of�rdig kod, jag f�rst�r knappt sj�lv hur det fungerar

Anv�nd: 
replace("Kalle �r ett namn!", "Kalle", "Anders");
funktionen kommer returnera: "Anders �r ett namn!"

replace("Hej Haj Hoj", "H", "K");
funktionen kommer returnera: "Kej Kaj Koj"

Detta g�r ej:
char VariabelNamn[300] = replace("String", "ing", "ock");

dock g�r:
char VariabelNamn[300];
strcpy(VariabelNamn, replace("String", "ing", "ock"));
eller 
char *test = replace("String", "ing", "ock");


tjuvkollade en del p� denna, mycket snyggare gjord, men ville prova att g�ra en egen:
http://stackoverflow.com/questions/779875/what-is-the-function-to-replace-string-in-c

*/

/*Funktion f�r att byta ut text i en str�ng fr�n->till, returnerar den bytta str�ngen*/
char *replace(char *orginal_text, char *fran, char *till){
	//variabler f�r textstr�ngarnas l�ngder:
	int orginal_text_langd = strlen(orginal_text);
	int fran_langd = strlen(fran);
	int till_langd = strlen(till);
	int antal_ord_att_byta = 0;
	//variabel f�r tempor�r h�llare av text, s�tts till orginaltextens l�ngd
	char temp[orginal_text_langd];
	strncpy(temp, orginal_text, orginal_text_langd+1);
	
	//printf("Funktionen har texten i temp: %s - den �r %d tecken l�ng \n", temp, strlen(temp));
	
	/*R�kna hur m�nga g�nger texten i 'fran' finns i 'orginal_text'
	For-loopen k�r s� l�nge strstr inte returnerar en substr�ng, f�r varje varv s�tts temp till retur-str�ngen
	fr�n strstr + l�ngden av fr�n-texten. Detta pga att strstr returnerar str�ngen man s�ker efter samt allt efter.
	omformulera...
	*/
 	for(antal_ord_att_byta=0; strstr(temp, fran) != NULL; ++antal_ord_att_byta){
			strcpy(temp, strstr(temp,fran)+fran_langd);
			if (antal_ord_att_byta > 5000){
				//n�got blev antagligen fel, bryt loop
				return "<<Fel!>>";
			}
	}

	char *return_text = malloc(300 * sizeof(char));
	//printf("Funktionen hittade %s %d antal g�nger i texten \n", fran, antal_ord_att_byta);
	
	int langd_fore_till = orginal_text_langd -  strlen(strstr(orginal_text,fran));
	//printf("Funktionen: langd_fore_till: %d\n", langd_fore_till);
	
	strncpy(return_text, orginal_text, langd_fore_till);
	return_text[langd_fore_till]='\0';
	strncat(return_text, till, till_langd); //temp har nu bytt f�rsta fr�n->till
	strcpy(temp, strstr(orginal_text, fran)+fran_langd);
	antal_ord_att_byta--;
	//printf("Funktionen: return_text: %s\n",return_text);
	//fixa returstr�ngen
	while(antal_ord_att_byta--){
		langd_fore_till = strlen(temp) - strlen(strstr(temp, fran));
		strncat(return_text, temp, langd_fore_till);
		strncat(return_text, till, till_langd);
/* 		printf("While-Loop(%d): strstr(temp, fran): %s\n",antal_ord_att_byta,strstr(temp, fran));
		printf("While-Loop(%d): temp: %s\n",antal_ord_att_byta,temp);
		printf("While-Loop(%d): langd_fore_till: %d\n",antal_ord_att_byta,langd_fore_till);
		printf("While-Loop(%d): return_text: %s\n",antal_ord_att_byta,return_text); */
		strcpy(temp, strstr(temp,fran)+fran_langd);
		//strcpy(temp, strstr(temp,fran)+fran_langd);
	}
	//printf("Efter While-loop: temp: %s\n",temp);
	strncat(return_text, temp, strlen(temp));
	/*Fixa snygg malloc och f�rklara hur den funkar - typ strlen(text) + strlen(till) etcetc
	fr�n annans replace-funktion:
	tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1); */
	
	
/* 	printf("Funktionen ser text: %s - den �r %d tecken l�ng \n", orginal_text, orginal_text_langd);
	printf("Funktionen ser fr�n: %s - den �r %d tecken l�ng \n", fran, fran_langd);
	printf("Funktionen ser till: %s - den �r %d tecken l�ng \n", till, till_langd); */
	
	//char *return_text;
	//strcpy(return_text, "Returtext");
	//return return_text;
	return return_text;
}
/* 
int main(){
	char text[200] = "ABC_123_abc_123_BytMig_���_BytMig_ABC_123_abc";
	char bytt_text[300];
	strcpy(bytt_text, replace(text, "BytMig", "Jag�rNy!"));
	printf("Innan funktion: \t%s\n", text);
	printf("Funktionen returnerade:\t%s\n", bytt_text);
	//printf("sizeof(char): %d\n", sizeof(char));
} */