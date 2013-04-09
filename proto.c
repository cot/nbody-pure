#include <math.h>

double deltat = 0.001;
double G = 6.6738480e-11;
double alpha = 6.6738480e-11 * 0.001;
int dim = 1000; /* nombre d'objets observes */
int niter = 10; /* nombre d'iteration d'un truc qu'on comprend finalement assez peu */

double m[1000];
double r[1000][3];

double Norme(double A[3], double B[3]) {
	return(sqrt( (A[0]-B[0])*(A[0]-B[0]) + (A[1]-B[1])*(A[1]-B[1]) + (A[2]-B[2])*(A[2]-B[2])  ));
}

double UnCube(double v) {
	return(1.0/(v*v*v));
}

double Distance(double v, double w) {
	return(v-w);
}

double PhiPrimeX(int indice, int k) {
	if(k!=indice)
		return(alpha * m[k] * UnCube(Norme(r[indice],r[k])) * Distance(r[indice][0],r[k][0]) );
	else
		return 0;
}

