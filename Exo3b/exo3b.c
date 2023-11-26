// This directive deactivates Warnings for unsecure functions that are deprecated by Microsoft.
// This is not a good practice but is used for pedagogic purposes,
// allowing usage of standard C functions as described in manuals.
// You should use only secured functions named with _s postfix
// e.g. printf_s() rather than printf()
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
/******************************************/
/*   TPC2022 no 3  exo 3-d-e-f-g-h        */
/*                                        */
/******************************************/


#define NBNOTESMAX 30

// impl�mentation avec un tableau

int main() {
	setlocale(LC_ALL, "fr-FR");

	float val = 0;
	int nbNotes = 0;    // notes valides
	int nbNotesSaisie = 0; // on compte aussi les absents
	float total = 0;		 // somme des notes valides
	bool arretSaisie = 0; // flag
	int nbAbsences = 0;
	float noteMax = 0;
	float noteMin = 20;
	double moyenne = 0;
	float note[NBNOTESMAX];
	char reponse;
	//3 - d

	for (int i = 0; i < NBNOTESMAX;i++) {
		note[i] = -2.0;
	}

	do {
		printf("\nEntrez la note no %d: ", nbNotesSaisie += 1);
		scanf_s("%f", &val); // saisie de la note
		if ((val > 20) || (val < 0)) {
			printf("El�ve absent ? ou voulez - vous arr�ter la saisie des notes ? A / O / N");
			reponse = _getch(); //on recupere la reponse
			if (reponse == 'O') {
				arretSaisie = true;
			}
			else if (reponse == 'N') {
				nbNotes -= 1;	// on retire une note des notes valide
				nbNotesSaisie -= 1; // on retire une note (déjà saisie)
			}
			else if (reponse == 'A') {
				note[nbNotes] = -1; // -1 pour les absents
				nbAbsences += 1; //on rajoute une absence
			}
		}
		else { // si la note est valide
			if (val > noteMax) {
				noteMax = val; // si la note est plus grande que la note max alors elle l'a remplace
			}
			if (val < noteMin) {
				noteMin = val; // si la note est plus petite que la note minimum alors elle l'a remplace
			}
			total += val; // on rajoute la valeur � l'additions des autres notes pour connaître la moyenne
			note[nbNotes] = val; // on ajoute la note au tableau de note
			nbNotes += 1;
		}

	} while ((nbNotes != NBNOTESMAX) && !arretSaisie);


	// 3-e
	
	// 

	if (nbNotes != 0) {
		moyenne = (float)total / (float)nbNotes;
		printf("\nLa moyenne de ces %d notes est : %.2f\n", nbNotes, moyenne);
		printf("\nIl y a %d absences.", nbAbsences);
		printf("\nLa plus petite note est %.2f, la plus grande est %.2f", noteMin, noteMax);

		// 3-f affichage de l'�cart-type 
		double ecartType = 0;
		double sommeEcart = 0;
		for (int i = 0; i < nbNotes; i++) {
			sommeEcart = sommeEcart + ((note[i] - moyenne) * (note[i] - moyenne)); //on fait la somme present dans l'écart type
		}
		ecartType = sqrt((1 / (float)nbNotes) * sommeEcart); // on applique la formule avec les sommes
		printf("\n L'�cart-type est: %.2f", ecartType); 

		// 3 - g : affichage du tableau de notes :

		printf("\n\tNo note\tValeur note");
		for (int i = 0; i < nbNotes; i++) { // boucle pour parcourir toutes les notes
			printf("\n \t%d \t%.2f", i + 1, note[i]); // affiche avec un espace horizontale
		}
		
		printf("\n");

		//3 -h - affichage du classement
		int index[NBNOTESMAX];
		float copyNotes[NBNOTESMAX];
		for (int i = 0;i < NBNOTESMAX;i++) { // copie du tableau note dans copyNotes
			copyNotes[i] = note[i];
			index[i] = i;
		}
		float temp;
		int temp_i;
		for (int i = 0;i < NBNOTESMAX;i++) {
			for (int j = 0;i < NBNOTESMAX - i - 1;i++) { // on traverse tous les éléments du tableau
				if (copyNotes[j] < copyNotes[j + 1]) { //on echange les éléments si l'élément est plus grand que le suivant
					temp = copyNotes[j];
					temp_i = index[j];
					copyNotes[j] = copyNotes[j + 1];
					temp_i = index[j + 1];
					copyNotes[j + 1] = temp;
					index[j + 1] = temp_i;
				}
			}
		}

		printf("\n\tRang: \tNo note \t Valeur note"); //on affiche alors ce classement
		for (int i = 0; i < nbNotes; i++) { //boucle pour parcourir toutes les notes
			printf("\n \t%d \t%d \t\t%.2f", i + 1,index[i]+1, copyNotes[i]); //affiche avec un espace horizontale
		}
	
		printf("\nBye !\n");

		return(EXIT_SUCCESS);
	}
}