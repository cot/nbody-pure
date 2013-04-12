/**
 * \author François Rué
 * \version 0.1
 * \date 11 avril 2013
 * \file proto.h
 * \brief fichier d'entête pour les prototypes de fonctions contenant les variables globales utiles au problème
 * \param npart nombre de particules
 * \param niter nombre d'iterations
 * \param deltat pas de temps du probleme (pour l'evaluation de la vitesse puis du deplacement)
 * \param dim dimension spatiale du probleme
 * \param G constante gravitationnelle (m^3 * kg^-1 * s^-2)
 */

#ifdef SOLAIRE
   #define npart 9 
   #define niter 1 
   #define deltat 0.0001 
#else
   #define npart 3 
   #define niter 1000000000 
   #define deltat 0.0001 
#endif

#define dim 3 
#define G 6.6738480e-11 

double alpha = (double) G * (double)1000000000.0 * (double) deltat;

double m[npart] ;
double r[npart][dim];

double Carre(double v);
double Norme(double A[dim], double B[dim]); 
double UnCube(double v);
double Distance(double v, double w);
double PhiPrimeX(int indice, int k);
double PhiPrimeY(int indice, int k);
double PhiPrimeZ(int indice, int k);
double SommePhiX(int indice, int level);
double SommePhiY(int indice, int level);
double SommePhiZ(int indice, int level);
double EvalVitesseX(int indice);
double EvalVitesseY(int indice);
double EvalVitesseZ(int indice);
double SommeX(int indice, int iteration);
double SommeX(int indice, int iteration);
double SommeX(int indice, int iteration);
double EvolutionX(int indice);
double EvolutionY(int indice);
double EvolutionZ(int indice);

