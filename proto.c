#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "proto.h"


/**
 *\author François Rué
 *\version 0.1
 *\date 11 avril 2013
 *\file proto.c
 *\brief Probleme a n-corps multidimensionnel pour le cas d'effet gravitationnel
 */

/*! \fn double Norme(double A[3], double B[3])
 *  \brief Permet d'evaluer la norme L2 de la différence de deux vecteurs A et B, représentés en coordonnées cartésiennes (x,y,z)
 *  \param[in] "A[3]" premier vecteur de type struct array
 *  \param[in] "B[3]" second vecteur de type struct array
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double Norme(double A[3], double B[3]) {
	return(sqrt( (A[0]-B[0])*(A[0]-B[0]) + (A[1]-B[1])*(A[1]-B[1]) + (A[2]-B[2])*(A[2]-B[2])  ));
}

/*! \fn double UnCube(double v)
 *  \brief Permet d'evaluer l'inverse d'une valeur élevée au cube
 *  \param[in] "v" valeur à évaluer au cube et à inverser (dans le cas n-body: la distance entre deux entitées)
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double UnCube(double v) {
	return(1.0/(v*v*v));
}

/*! \fn double Distance(double v, double w)
 *  \brief Permet d'evaluer la distance entre deux points: cette fonction permet d'évaluer chaque entitée dans chaque direction
 *  \param[in] "v" première valeur d'entrée
 *  \param[in] "w" seconde valeur d'entrée
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
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
	return(-1.0 * SommeX(indice,0));
}

double EvolutionY(int indice) {
	return(-1.0 * SommeY(indice,0));
}

double EvolutionZ(int indice) {
	return(-1.0 * SommeZ(indice,0));
}


