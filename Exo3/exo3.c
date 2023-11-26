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
#include <stdbool.h>


/******************************************/
/*   TPC2022 no 3  exo 3-abc              */
/*                                        */
/******************************************/

#define NBNOTESMAX 30


int main() {
	setlocale(LC_ALL, "fr-FR");

	float val = 0;		// note lue au clavier
	int nbNotes = 0;    // nombre de notes valides
	int nbNotesSaisie=0; // nombre de notes saisies, on compte aussi les absents
	float total = 0;		 // somme des notes valides
	bool arretSaisie = false; // flag
	char reponse;
	float note[NBNOTESMAX];
	int nbAbsences = 0;
	float noteMax = 0;
	float noteMin = 20;
	int somme = 0; //somme pour l'écart type
	float moyenne_temp;
	float somme_temp;
	// 3-a-b-c
	// version sans tableau
	for (int i = 0; i < NBNOTESMAX;i++) {
		note[i] = -2;
	}
	do {
		printf("\nEntrez la note no %d: ", nbNotesSaisie + 1);
		scanf("%f", &val);

		if ((val > 20) || (val < 0)) {
			printf("Elève absent ? ou voulez-vous arrêter la saisie des notes ? A/O/N");
			reponse = getch();

			if (nbNotesSaisie > 30) {
				if (reponse == "O" || reponse="o") {
					arretSaisie = true;
				}
				else if (reponse == 'N' || reponse == 'n') {
				nbNotes -= 1;
				nbNotesSaisie -= 1;
				}
				else if (reponse == 'A' || reponse == 'a' ) {
					note[nbNotes] = -1; //on met un -1 pour les absents
					nbAbsences += 1; //on rajoute une absence
				}
			
		}
				else {
			if (val > noteMax) {
				noteMax = val; //si la note est plus grande que la note max alors elle l'a remplace
			}
			if (val < noteMin) {
				noteMin = val; //si la note est plus petite que la note minimum alors elle l'a remplace
			}
			total += val; //on rajoute la valeur à l'addition des autres notes pour envisager la moyenne
			nbNotes += 1; //on rajoute 1 à nombre de note car il y en a une en plus 
			note[nbNotes] = val; //on ajoute la note au tableau de note

		}
//

	} while ((nbNotes != NBNOTESMAX) && !arretSaisie );

	for (int a = 0; a < NBNOTESMAX;a++) {
	somme_temp += note[a];
	moyenne_temp = somme_temp / a; // on fait la moyenne des notes actuelles
	somme += pow((note[a] - moyenne_temp),2);
	}
	

	if (nbNotes != 0) {
		printf("\nLa moyenne de ces %d notes est : %.2f\n", nbNotes, (float)total / (float)nbNotes);
		printf("\nIl y a %d absences.", nbAbsences);
		printf("\nLa plus petite note est %.2f, la plus grande est %.2f", noteMin, noteMax);
	}
	else printf("\nVous n'avez pas saisi de note\n");


	printf("\nBye !\n");
	return(EXIT_SUCCESS);
}