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
	m[i] = 100 * rand() % 57;
	for (j=0;j<dim;j++) {
		r[i][j] = 12422 * rand() % 1856;
	}
}

printf(" norme ( r[3] , r[4] ) = %g\n",Norme(r[3],r[4]) );
printf("everything's good \n");

return EXIT_SUCCESS;

}
