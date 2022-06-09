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
    * Entraine: retourne un nouveau graphe inversé.           *
    * ******************************************************* */
    CGraphe OPEInverserGraphe(CGraphe & GRPGraphe);

    /* ********************************************************
    *                      Sous Graphe                        *
    ***********************************************************
    * Entrée: CGraphe GRPGraphe                               *
    *         CGraphe GRPSousGraphe                           *
    *         unsigned int uiNbSommet                         *
    *         int* piTabSommet                                *
    * Nécessite: -                                            *
    * Sortie: CGraphe                                         *
    * Entraine: Un sous graphe de GRPGraphe est alloué dans   *
    *           GRPSousGraphe, avec uiNbSommet le nombre de   *
    *           sommets à conserver, et piTabSommet le        *
    *           tableau des numéro des sommets à conserver.   *
    * ******************************************************* */
    void OPESousGraphe(CGraphe& GRPGraphe, CGraphe& GRPSousGraphe, unsigned int iNbSommet, int* piTabSommet);

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
    * Entraine: retourne vrai si le sou graphe donné en entré *
    *           est une clique, faux sinon.                   *
    *           Chaque paramètre en plus après GRPGraphe      *
    *           est un numéro d'un sommet a conservé          *
    *           Le dernier numero doit être -1 pour indiquer  *
    *           la fin.                                       *
    *      (exemple : OPEEstUneClique(GRPGraphe, 1, 2, 3, -1) *
    *           indiquera de garder les sommet 1, 2 et 3 de   *
    *           GRPGraphe.                                    *
    * ******************************************************* */
    bool OPEEstUneClique(CGraphe & GRPGraphe, int iSommet , ...);

    /* ********************************************************
    *          Est une clique ? (version Sous Graphe)         *
    ***********************************************************
    * Entrée: CGraphe GRPGraphe                               *
    *         unsigned int uiNbSommet                         *
    *         int* piTabSommet                                *
    * Nécessite: -                                            *
    * Sortie: bool                                            *
    * Entraine: retourne vrai si le sou graphe donné en entré *
    *           est une clique, faux sinon.                   *
    *           uiNbSommet est le nombre de sommet conservé   *
    *           et piTabSommet contient les numéro des        *
    *           sommets à conserver.                          *
    * ******************************************************* */
    bool OPEEstUneClique(CGraphe GRPGraphe, unsigned int uiNbSommet, int* piTabSommet);
};

#endif