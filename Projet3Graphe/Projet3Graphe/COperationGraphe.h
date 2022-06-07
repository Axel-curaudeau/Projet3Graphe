#ifndef COPERATIONGRAPHE_H
#define COPERATIONGRAPHE_H

#include "CGraphe.h"
#include <stdarg.h>

/* ===== ERROR CODES ===== */
#define NON_ORIENTE 60

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

    /* ********************************************************
    *                    Est une clique ?                     *
    ***********************************************************
    * Entrée: CGraphe GRPGraphe                               *
    * Nécessite: -                                            *
    * Sortie: bool                                            *
    * Entraine: retourne vrai si le graphe donné en entré     *
    *           est une clique, faux sinon.                   *
    * ******************************************************* */
    bool OPEEstUneClique(CGraphe & GRPGraphe);

    /* ********************************************************
    *          Est une clique ? (version Sous Graphe)         *
    ***********************************************************
    * Entrée: CGraphe GRPGraphe                               *
    *         int iSommet                                     *
    *         ...                                             *
    * Nécessite: les paramètres iSommets sont les numéros des *
    *            sommets a conserver                          *
    * Sortie: bool                                            *
    * Entraine: retourne vrai si le graphe donné en entré     *
    *           est une clique, faux sinon.                   *
    * ******************************************************* */
    bool OPEEstUneClique(CGraphe & GRPGraphe, int iSommet , ...);

    void OPESousGraphe(CGraphe & GRPGraphe, CGraphe & GRPSousGraphe, unsigned int iNbSommet, int* piTabSommet);

    bool OPEEstUneClique(CGraphe GRPGraphe, unsigned int uiNbSommet, int* piTabSommet);
};

#endif