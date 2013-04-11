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
		for (j=0;j<dim;j++) {
			r[i][j] = 0.0;
		}
	}
	m[0] = 1.9891*1e30;	
	m[1] = 0.33*1e24;	r[1][1] = 57.8*1.0e+6;
	m[2] = 4.87*1e24;					r[2][2] = 108.2*1.0e+6;
	m[3] = 5.9736*1e24;	r[3][1] = -149.6*1.0e+6;	r[3][2] = 149.6*1.0e+6;
	m[4] = 0.642*1e24;					r[4][2] = 227.9*1.0e+6;	
	m[5] = 1899*1e24;	r[5][1] = -778.6*1.0e+6;	r[5][2] = 778.6*1.0e+6;
	m[6] = 568*1e24;	r[6][1] = 1433.5*1.0e+6;	r[6][2] = -1433.5*1.0e+6;
	m[7] = 86.8*1e24;					r[7][2] = 2872.5*1.0e+6;
	m[8] = 102*1e24;	r[8][1] = 4495.1*1.0e+6;	r[8][2] = 4495.1*1.0e+6;
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
	printf(" la nouvelle position est alors: (%g,%g,%g) \n",EvolutionX(alea),EvolutionY(alea),EvolutionZ(alea));

	printf("_________________________________________________________________________\n\n");
	printf("everything's good \n");

	return EXIT_SUCCESS;

}
