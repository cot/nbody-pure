#ifdef SOLAIRE
   #define npart 9 /* nombre de particules  */
   #define niter 1000000 /* nombre d'iteration d'un truc qu'on comprend finalement assez peu  */
   #define deltat 0.0001 /* pas de temps du problème */
#else
   #define npart 3 /* nombre de particules  */
   #define niter 1000000000 /* nombre d'iteration d'un truc qu'on comprend finalement assez peu  */
   #define deltat 0.0001 /* pas de temps du problème */
#endif

#define dim 3 /* dimension spatiale du probleme */
#define G 6.6738480e-11 /* Constante Gravitationnelle ( m^3 * kg^-1 * s^-2 ) */

double alpha = (double) G * (1.0e+3)*(1.0e+3)*(1.0e+3) * (double) deltat;

double m[npart] ;
double r[npart][dim];

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

