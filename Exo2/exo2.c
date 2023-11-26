// This directive deactivates Warnings for unsecure functions that are deprecated by Microsoft.
// This is not a good practice but is used for pedagogic purposes,
// allowing usage of standard C functions as described in manuals.
// You should use only secured functions named with _s postfix
// e.g. printf_s() rather than printf()
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/******************************************/
/*   TPC2022 no 3  exo 2                  */
/*                                        */
/******************************************/


int main() {
	setlocale(LC_ALL, "fr-FR");

	unsigned int val = 0xAAFF0000;

	printf("\nLe nombre d'octets utilisés est %u", sizeof(val));
	printf("\nLe nombre de bits utilisés est %u", sizeof(val)*8);

	for (int i = 1; i < sizeof(val) * 8 + 1; i++){
		if ((val & 1) == 1) { //on additionne la valeur en binaire avec le binaire de 1 et on regarde si cela nous donne un 1 ou un 2
			printf("\nbit %d: ON",i );
			val >>= 1; //on decale d'un bit
		}
		else {
			printf("\nbit %d: OFF", i);
			val >>= 1;
		}
	}
	
	printf("\nBye !\n");
	return(EXIT_SUCCESS);
}