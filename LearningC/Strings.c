#include <stdio.h>

int sestej(int a, int b);

int main(void){
	int a, b;
	a = 1;
	b = 2;
	printf("Rezultat je: %d\n", sestej(a, b));}

int sestej(int a, int b){
   return a+b;
}
