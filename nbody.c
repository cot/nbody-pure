#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "proto.h"

/**
*\author François Rué
*\version 0.1
*\date
*\file nbody.c
*\brief Probleme a n-corps multidimensionnel pour le cas d'effet gravitationnel
*/

int main() {

int i,j;

for (i=0;i<npart;i++) {
	m[i] = 1e+5 * rand() ;
	for (j=0;j<dim;j++) {
		r[i][j] = 10 * rand() ;
	}
}

/*
printf(" UnCube(norme ( r[3] , r[4] )) = %g\n",UnCube(Norme(r[3],r[4])) );
printf(" PhiPrimeX(3,4)  = %g\n",PhiPrimeX(3,4) );
*/
printf(" From r[%i][] = (%g,%g,%g) \n",npart-1,r[npart-1][0],r[npart-1][1],r[npart-1][2]);
printf(" EvolutionX(3) = %g\n",EvolutionX(npart-1));
printf(" EvolutionY(3) = %g\n",EvolutionY(npart-1));
printf(" EvolutionZ(3) = %g\n",EvolutionZ(npart-1));

printf("everything's good \n");

return EXIT_SUCCESS;

}
