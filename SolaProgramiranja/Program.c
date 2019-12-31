#include <stdio.h>
#include <string.h>

int sestej(int , int );

int main2(void){
	
	int a = 5, b =6, c;
	c =  a + b;
	
	char vneseniNiz[20];
    printf("Vnesi Nulto poved\n");
	gets(vneseniNiz);
	printf("Nulta poved je %s.\n", vneseniNiz);
	
	char niz[] = {'a', 'b', '\0'};
	char *stavek = (char *)"1234512345";
	
	printf("Prva Poved je %s.\n", stavek);
	printf("Dolga je %d znakov. \n", strlen(stavek));
	printf("V spominu zaseda %d.\n", sizeof(stavek));
	
	printf("Druga Poved je %s.\n", niz);
	printf("Dolga je %d znakov.\n", strlen(niz));
	printf("V spominu zaseda %d.\n", sizeof(niz));
	
	char tretja[20] = "Program";
	printf("Tretja poved je %s.\n", tretja);
	
	
	return 0;
}

int sestej(int a, int b){
   return a+b;
}
