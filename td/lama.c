#include "graphics.h"
#include <stdio.h>

#define largeur 25
#define hauteur 25
#define cote 25





/*

Terre : Marron
Terre hydratée : marron foncé
Arbre : Vert
Pousse d'arbre : vert clair
Eau : Bleu
Feu intense : Rouge
Feu peu intense : orange
Cendres tièdes : Gris
Cendres éteintes : Noir

*/

int main()
{
	int etat[largeur+2][hauteur+2];
	init_graphics(largeur*cote,hauteur*cote);
	
	
	
	
	
	write_int(5);
	
	
	wait_escape();
	return 0;
}

