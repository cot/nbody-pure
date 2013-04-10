#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "proto.h"

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

double PhiPrimeY(int indice, int k) {
	if(k!=indice)
		return(alpha * m[k] * UnCube(Norme(r[indice],r[k])) * Distance(r[indice][1],r[k][1]) );
	else
		return 0;
}

double PhiPrimeZ(int indice, int k) {
	if(k!=indice)
		return(alpha * m[k] * UnCube(Norme(r[indice],r[k])) * Distance(r[indice][2],r[k][2]) );
	else
		return 0;
}

double SommePhiX(int indice, int level) {
	switch(level) {
		case 0:  return 0;
		default: return ( PhiPrimeX(indice,level-1) + SommePhiX(indice,level-1));
	}
}

double SommePhiY(int indice, int level) {
        switch(level) {
                case 0:  return 0;
                default: return ( PhiPrimeY(indice,level-1) + SommePhiY(indice,level-1));
        }
}

double SommePhiZ(int indice, int level) {
        switch(level) {
                case 0:  return 0;
                default: return ( PhiPrimeZ(indice,level-1) + SommePhiZ(indice,level-1));
        }
}

double EvalVitesseX(int indice) {
	return(SommePhiX(indice, npart));
}

double EvalVitesseY(int indice) {
	return(SommePhiY(indice, npart));
}

double EvalVitesseZ(int indice) {
	return(SommePhiZ(indice, npart));
}

double SommeX(int indice, int iteration) {
	switch(iteration)
	{
		case niter:  return 0;
		default :    return(EvalVitesseX(indice) + SommeX(indice,iteration+1));
	}
}

double SommeY(int indice, int iteration) {
	switch(iteration)
	{
		case niter:  return 0;
		default :    return(EvalVitesseY(indice) + SommeY(indice,iteration+1));
	}
}

double SommeZ(int indice, int iteration) {
	switch(iteration)
	{
		case niter:  return 0;
		default :    return(EvalVitesseZ(indice) + SommeZ(indice,iteration+1));
	}
}

double EvolutionX(int indice) {
	return(SommeX(indice,0));
}

double EvolutionY(int indice) {
	return(SommeY(indice,0));
}

double EvolutionZ(int indice) {
	return(SommeZ(indice,0));
}


