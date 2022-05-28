#ifndef COPERATIONGRAPHE_H
#define COPERATIONGRAPHE_H

#include "CGraphe.h"

/* ===== ERROR CODES ===== */


/*
 * Classe COperationGraphes
 *
 * Cette class est utilisée pour faire des opération sur des graphes.
 */
class COperationGraphe
{
public:
	/* *********************************************************
	 *                 Constructeur par défaut                 *
	 ***********************************************************
	 * Entrée: -                                               *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: construit l'objet                             *
	 ********************************************************* */
    COperationGraphe();

    /* ********************************************************
    *                      Inverser                           *
    ***********************************************************
    * Entrée: CGraphe GRPGraphe                               *
    * Nécessite: -                                            *
    * Sortie: CGraphe                                         *
    * Entraine: retourne un nouveau graphe inversé            *
    * ******************************************************* */
    CGraphe OPEInverserGraphe(CGraphe & GRPGraphe);
};

#endif