#ifndef COPERATIONGRAPHE_H
#define COPERATIONGRAPHE_H

#include "CGraphe.h"
#include <stdarg.h>

/* ===== ERROR CODES ===== */
#define NON_ORIENTE 60

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

    /* ********************************************************
    *                    Est une clique ?                     *
    ***********************************************************
    * Entr�e: CGraphe GRPGraphe                               *
    * N�cessite: -                                            *
    * Sortie: bool                                            *
    * Entraine: retourne vrai si le graphe donn� en entr�     *
    *           est une clique, faux sinon.                   *
    * ******************************************************* */
    bool OPEEstUneClique(CGraphe & GRPGraphe);

    /* ********************************************************
    *          Est une clique ? (version Sous Graphe)         *
    ***********************************************************
    * Entr�e: CGraphe GRPGraphe                               *
    *         int iSommet                                     *
    *         ...                                             *
    * N�cessite: les param�tres iSommets sont les num�ros des *
    *            sommets a conserver                          *
    * Sortie: bool                                            *
    * Entraine: retourne vrai si le graphe donn� en entr�     *
    *           est une clique, faux sinon.                   *
    * ******************************************************* */
    bool OPEEstUneClique(CGraphe & GRPGraphe, int iSommet , ...);

    void OPESousGraphe(CGraphe & GRPGraphe, CGraphe & GRPSousGraphe, unsigned int iNbSommet, int* piTabSommet);

    bool OPEEstUneClique(CGraphe GRPGraphe, unsigned int uiNbSommet, int* piTabSommet);
};

#endif