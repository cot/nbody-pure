#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "proto.h"

/**
 *\author François Rué
 *\version 0.1
 *\date 11 avril 2013
 *\file nbody.c
 *\brief Probleme a n-corps multidimensionnel pour le cas d'effet gravitationnel
 */

/*! \fn int main()
 *  \brief Programme principal initialisant les champs (position, masse)
 *  \param void
 *  \return Les points d'evolution
 */

int main() {

	int i,j;
	int alea;

#ifdef SOLAIRE
	for (i=0;i<npart;i++) {
		m[i] = 1.8986e+27 * rand() + 1.314e+22 ; /* masse des planetes du systeme solaire: 1.314*1e22 < m < 1.8986*1e27 (en kg)*/
		for (j=0;j<dim;j++) {
			r[i][j] = (5914.65*1e6 * rand() + 57.9*1e6) * 1.0e+3 ; /* distance moyenne au soleil: 57.9 < d < 5914.65 (en millions de km) */
		}
	}

#else
	for (i=0;i<npart;i++) {
		m[i] = 1.8986e+27 * rand() + 1.314e+22 ; /* masse des planetes du systeme solaire: 1.314*1e22 < m < 1.8986*1e27 (en kg)*/
		for (j=0;j<dim;j++) {
			r[i][j] = (5914.65*1e6 * rand() + 57.9*1e6) * 1.0e+3 ; /* distance moyenne au soleil: 57.9 < d < 5914.65 (en millions de km) */
		}
	}
#endif

	printf("_________________________________________________________________________\n\n");

	srand((int)time(NULL));
	alea = rand() % npart;

	printf(" Nombre de particules : %i\n", npart);
	printf(" Pour la particule %i de coordonnées (%g,%g,%g) \n",alea,r[alea][0],r[alea][1],r[alea][2]);
	printf(" --> La vitesse estimée suivant x vaut: %g km.s^-1\n",EvalVitesseX(alea));
	printf(" --> La vitesse estimée suivant Y vaut: %g km.s^-1\n",EvalVitesseY(alea));
	printf(" --> La vitesse estimée suivant Z vaut: %g km.s^-1\n",EvalVitesseZ(alea));


	printf("_________________________________________________________________________\n\n");
	printf("everything's good \n");

	return EXIT_SUCCESS;

}
