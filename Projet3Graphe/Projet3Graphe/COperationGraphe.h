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
    * Entraine: retourne un nouveau graphe invers�.           *
    * ******************************************************* */
    CGraphe OPEInverserGraphe(CGraphe & GRPGraphe);

    /* ********************************************************
    *                      Sous Graphe                        *
    ***********************************************************
    * Entr�e: CGraphe GRPGraphe                               *
    *         CGraphe GRPSousGraphe                           *
    *         unsigned int uiNbSommet                         *
    *         int* piTabSommet                                *
    * N�cessite: -                                            *
    * Sortie: CGraphe                                         *
    * Entraine: Un sous graphe de GRPGraphe est allou� dans   *
    *           GRPSousGraphe, avec uiNbSommet le nombre de   *
    *           sommets � conserver, et piTabSommet le        *
    *           tableau des num�ro des sommets � conserver.   *
    * ******************************************************* */
    void OPESousGraphe(CGraphe& GRPGraphe, CGraphe& GRPSousGraphe, unsigned int iNbSommet, int* piTabSommet);

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
    * Entraine: retourne vrai si le sou graphe donn� en entr� *
    *           est une clique, faux sinon.                   *
    *           Chaque param�tre en plus apr�s GRPGraphe      *
    *           est un num�ro d'un sommet a conserv�          *
    *           Le dernier numero doit �tre -1 pour indiquer  *
    *           la fin.                                       *
    *      (exemple : OPEEstUneClique(GRPGraphe, 1, 2, 3, -1) *
    *           indiquera de garder les sommet 1, 2 et 3 de   *
    *           GRPGraphe.                                    *
    * ******************************************************* */
    bool OPEEstUneClique(CGraphe & GRPGraphe, int iSommet , ...);

    /* ********************************************************
    *          Est une clique ? (version Sous Graphe)         *
    ***********************************************************
    * Entr�e: CGraphe GRPGraphe                               *
    *         unsigned int uiNbSommet                         *
    *         int* piTabSommet                                *
    * N�cessite: -                                            *
    * Sortie: bool                                            *
    * Entraine: retourne vrai si le sou graphe donn� en entr� *
    *           est une clique, faux sinon.                   *
    *           uiNbSommet est le nombre de sommet conserv�   *
    *           et piTabSommet contient les num�ro des        *
    *           sommets � conserver.                          *
    * ******************************************************* */
    bool OPEEstUneClique(CGraphe GRPGraphe, unsigned int uiNbSommet, int* piTabSommet);
};

#endif