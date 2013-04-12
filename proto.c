/**
 *\author François Rué
 *\version 0.1
 *\date 11 avril 2013
 *\file proto.c
 *\brief Probleme a n-corps multidimensionnel pour le cas d'effet gravitationnel
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "proto.h"

/*! \fn double Distance(double v, double w)
 *  \brief Permet d'evaluer la distance entre deux points: cette fonction permet d'évaluer chaque entitée dans chaque direction
 *  \param[in] "v" première valeur d'entrée
 *  \param[in] "w" seconde valeur d'entrée
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double Distance(double v, double w) {
	return(v-w);
}

/*! \fn double Carre(double v)
 *  \brief Permet d'evaluer le carre d'un nombre
 *  \param[in] "v" première valeur d'entrée
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double Carre(double v) {
	return(v*v);
}

/*! \fn double Norme(double A[3], double B[3])
 *  \brief Permet d'evaluer la norme L2 de la différence de deux vecteurs A et B, représentés en coordonnées cartésiennes (x,y,z)
 *  \param[in] "A[3]" premier vecteur de type struct array
 *  \param[in] "B[3]" second vecteur de type struct array
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double Norme(double A[3], double B[3]) {
	return(sqrt( Carre(Distance(A[0],B[0])) + Carre(Distance(A[1],B[1])) + Carre(Distance(A[2],B[2])) ) ) ;
}

/*! \fn double UnCube(double v)
 *  \brief Permet d'evaluer l'inverse d'une valeur élevée au cube
 *  \param[in] "v" valeur à évaluer au cube et à inverser (dans le cas n-body: la distance entre deux entitées)
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double UnCube(double v) {
	return(1.0/(v*v*v));
}

/*! \fn double PhiX(int indice, int k)
 *  \brief Permet d'evaluer chacune des influences des autres astres sur l'astre évalué: PhiX évalue l'influence dans la direction x.
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \param[in] "k" l'indice de l'astre dont on évalue l'influence
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double PhiX(int indice, int k) {
	if(k!=indice)
		return( m[k] * UnCube(Norme(r[indice],r[k])) * Distance(r[indice][0],r[k][0]) );
	else
		return 0;
}

/*! \fn double PhiY(int indice, int k)
 *  \brief Permet d'evaluer chacune des influences des autres astres sur l'astre évalué: PhiY évalue l'influence dans la direction y.
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \param[in] "k" l'indice de l'astre dont on évalue l'influence
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double PhiY(int indice, int k) {
	if(k!=indice)
		return( m[k] * UnCube(Norme(r[indice],r[k])) * Distance(r[indice][1],r[k][1]) );
	else
		return 0;
}

/*! \fn double PhiZ(int indice, int k)
 *  \brief Permet d'evaluer chacune des influences des autres astres sur l'astre évalué: PhiZ évalue l'influence dans la direction z.
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \param[in] "k" l'indice de l'astre dont on évalue l'influence
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double PhiZ(int indice, int k) {
	if(k!=indice)
		return( m[k] * UnCube(Norme(r[indice],r[k])) * Distance(r[indice][2],r[k][2]) );
	else
		return 0;
}

/*! \fn double SommePhiX(int indice, int level)
 *  \brief Permet de sommer les influences de chacun des astres agissant sur l'astre étudié: SommePhiX évalue l'influence globale dans la direction x.
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \param[in] "level" le niveau d'évaluation où l'on se trouve; c'est le paramètre recursif
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double SommePhiX(int indice, int level) {
	switch(level) {
		case 0:  return 0;
		default: return ( PhiX(indice,level-1) + SommePhiX(indice,level-1));
	}
}

/*! \fn double SommePhiY(int indice, int level)
 *  \brief Permet de sommer les influences de chacun des astres agissant sur l'astre étudié: SommePhiY évalue l'influence globale dans la direction y.
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \param[in] "level" le niveau d'évaluation où l'on se trouve; c'est le paramètre recursif
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double SommePhiY(int indice, int level) {
	switch(level) {
		case 0:  return 0;
		default: return ( PhiY(indice,level-1) + SommePhiY(indice,level-1));
	}
}

/*! \fn double SommePhiZ(int indice, int level)
 *  \brief Permet de sommer les influences de chacun des astres agissant sur l'astre étudié: SommePhiZ évalue l'influence globale dans la direction z.
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \param[in] "level" le niveau d'évaluation où l'on se trouve; c'est le paramètre recursif
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double SommePhiZ(int indice, int level) {
	switch(level) {
		case 0:  return 0;
		default: return ( PhiZ(indice,level-1) + SommePhiZ(indice,level-1));
	}
}

/*! \fn double EvalVitesseX(int indice)
 *  \brief Permet d'évaluer la vitesse au regard de l'accéleration (somme des influences de chaque astre sur l'astre observé)
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double EvalVitesseX(int indice) {
	return(alpha * SommePhiX(indice, npart));
}

/*! \fn double EvalVitesseY(int indice)
 *  \brief Permet d'évaluer la vitesse au regard de l'accéleration (somme des influences de chaque astre sur l'astre observé)
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double EvalVitesseY(int indice) {
	return(alpha * SommePhiY(indice, npart));
}

/*! \fn double EvalVitesseZ(int indice)
 *  \brief Permet d'évaluer la vitesse au regard de l'accéleration (somme des influences de chaque astre sur l'astre observé)
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double EvalVitesseZ(int indice) {
	return(alpha * SommePhiZ(indice, npart));
}

/*! \fn double SommeX(int indice, int iteration)
 *  \brief Permet d'évaluer la vitesse au pas de temps d'iteration désiré dans la direction X
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \param[in] "iteration" l'indice de l'iteration terminale
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double SommeX(int indice, int iteration) {
	switch(iteration)
	{
		case niter:  return 0;
		default :    return(EvalVitesseX(indice) + SommeX(indice,iteration+1));
	}
}

/*! \fn double SommeY(int indice, int iteration)
 *  \brief Permet d'évaluer la vitesse au pas de temps d'iteration désiré dans la direction Y
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \param[in] "iteration" l'indice de l'iteration terminale
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double SommeY(int indice, int iteration) {
	switch(iteration)
	{
		case niter:  return 0;
		default :    return(EvalVitesseY(indice) + SommeY(indice,iteration+1));
	}
}

/*! \fn double SommeZ(int indice, int iteration)
 *  \brief Permet d'évaluer la vitesse au pas de temps d'iteration désiré dans la direction Z
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \param[in] "iteration" l'indice de l'iteration terminale
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double SommeZ(int indice, int iteration) {
	switch(iteration)
	{
		case niter:  return 0;
		default :    return(EvalVitesseZ(indice) + SommeZ(indice,iteration+1));
	}
}

/*! \fn double EvolutionX(int indice)
 *  \brief Permet d'évaluer le deplacement au pas de temps d'iteration désiré dans la direction X
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double EvolutionX(int indice) {
	return( SommeX(indice,0) );
}

/*! \fn double EvolutionY(int indice)
 *  \brief Permet d'évaluer le deplacement au pas de temps d'iteration désiré dans la direction Y
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double EvolutionY(int indice) {
	return( SommeY(indice,0) );
}

/*! \fn double EvolutionZ(int indice)
 *  \brief Permet d'évaluer le deplacement au pas de temps d'iteration désiré dans la direction Z
 *  \param[in] "indice" l'indice de l'astre qu'on observe
 *  \return toutes les fonctions de proto.c sont créées pour n'effectuer que des retours de type double
 */
double EvolutionZ(int indice) {
	return( SommeZ(indice,0) );
}


