// This directive deactivates Warnings for unsecure functions that are deprecated by Microsoft.
// This is not a good practice but is used for pedagogic purposes,
// allowing usage of standard C functions as described in manuals.
// You should use only secured functions named with _s postfix
// e.g. printf_s() rather than printf()
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <assert.h>

/******************************************/
/*   TPC2021 no 3  exo 4                  */
/*                                        */
/******************************************/


/// <summary>
/// Lecture de la valeur du bit en position pos dans l�entier n en partant de 0 pour le bit de poids fort.
/// renvoie vrai si 1, ou false si 0
/// </summary>
/// <param name="n">entier � �valuer</param>
/// <param name="pos">bit � tester</param>
/// <returns></returns>
bool readBit(int* n, int pos) {
	bool state = false;
	int decal;
	int indice;
	indice = 32 - pos;
	decal = (*n) >> indice;
	int valBit = decal % 2;
	if (valBit == 1) {
		state = true;
	}if (valBit == 0) {
		state = false;
	}
	return state;
}
/// <summary>
/// Modifie la valeur de l�entier n en positionnant � 1 le bit en position pos en partant de 0 pour le bit de poids fort.
/// </summary>
/// <param name="n">: entier � modifier</param>
/// <param name="pos">: bit � positionner � 1</param>
/// <returns></returns>
int writeBit(int* n, int pos) {
	int n2;
	n2 = 1 << ((sizeof(*n) * 8 - 1) - pos);
	int decal;
	decal = (*n) & n2;
	if (decal == false) {
		*n += n2;
	}
	else {
		(*n) = (*n);
	}
	return *n;
}

/// <summary>
/// Rotation d'une bitmap 32x32 dans le sens des aiguilles d'une montre
/// </summary>
/// <param name="tab">: un tableau de 32 entiers qui contient la bitmap</param>
void rotateClockWise90Static(int tab[32]) {

	// la taille du cot� est toujours �gale � 32 bits
	// Lors de la rotation d�un quart de tour, on sait qu�un point qui se trouve maintenant en position
	// (x, y) se trouvait en position(y, c - 1 - x) dans le bitmap original.
	//	La valeur c �tant la taille du c�t� de la bitmap, soit 32.

	// creation d'une bitmap temporaire de 32x32 bits
	int tmpBitMap[32] = { 0 };
	

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 32; x++) {
			tab[y] = tmpBitMap[x];
			writeBit(&tab[y], x);
		}
	}
	for (int y = 4; y < 8; y++) {
		for (int x = 0; x < 32; x++) {
			writeBit(&tab[y], x);
		}
	}
	for (int y = 8; y < 12; y++) {
		for (int x = 0; x < 32; x++) {
			tab[y] = tmpBitMap[x];
			writeBit(&tab[y], x);
		}
	}
	for (int y = 12; y < 16; y++) {
		for (int x = 0; x < 32; x++) {
			writeBit(&tab[y], x);
		}
	}
	for (int y = 16; y < 20; y++) {
		for (int x = 0; x < 32; x++) {
			tab[y] = tmpBitMap[x];
			writeBit(&tab[y], x);
		}
	}
	for (int y = 20; y < 24; y++) {
		for (int x = 0; x < 32; x++) {
			writeBit(&tab[y], x);
		}
	}
	for (int y = 24; y < 28; y++) {
		for (int x = 0; x < 32; x++) {
			tab[y] = tmpBitMap[x];
			writeBit(&tab[y], x);
		}
	}
	for (int y = 28; y < 32; y++) {
		for (int x = 0; x < 32; x++) {
			writeBit(&tab[y], x);
		}
	}
	return;
}

void displayBitmap32(int tab[32]) {
	printf("\n");
	for (int y = 0; y < 32; y++)
	{
		for (int x = 0; x < 32; x++) {
			int test;
			test = readBit(&tab[y], x);
			if (test == 0) {
				printf("*");
			}
			if (test == 1) {
				printf("\t");
			}
		}
		printf("\n");
	}
}

int main() {
	setlocale(LC_ALL, "fr-FR");

	int tab[32] = {
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111,
	0b00001111000011110000111100001111

	};
	int n = 0x00000A0A;
	int ret = writeBit(&n, 0);
	
	// test le bon fonctionnement de writeBit()
	assert(n == 0x80000A0A); // VS m'indique qu'il y a une erreur

	// affiche le bitmap avant
	displayBitmap32(tab);
	// rotation 90 degr�s
	rotateClockWise90Static(tab);
	// affiche le bitmap apr�s
	displayBitmap32(tab);
	

	return(EXIT_SUCCESS);
}