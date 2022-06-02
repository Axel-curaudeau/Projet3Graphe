#ifndef COPERATIONGRAPHE_H
#define COPERATIONGRAPHE_H

#include "CGraphe.h"
#include <stdarg.h>

/* ===== ERROR CODES ===== */


/*
 * Classe COperationGraphes
 *
 * Cette class est utilis�e pour faire des op�ration sur des graphes.
 */
class COperationGraphe
{
public:
	/* *********************************************************
	 *                 Constructeur par d�faut                 *
	 ***********************************************************
	 * Entr�e: -                                               *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: construit l'objet                             *
	 ********************************************************* */
    COperationGraphe();

    /* ********************************************************
    *                      Inverser                           *
    ***********************************************************
    * Entr�e: CGraphe GRPGraphe                               *
    * N�cessite: -                                            *
    * Sortie: CGraphe                                         *
    * Entraine: retourne un nouveau graphe invers�            *
    * ******************************************************* */
    CGraphe OPEInverserGraphe(CGraphe & GRPGraphe);

    bool OPEEstUneClique(CGraphe GRPGraphe, int Sommet , ...);
};

#endif