#include "COperationGraphe.h"

/* ********************************************************
*                 Constructeur par défaut                 *
***********************************************************
* Entrée: -                                               *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: construit l'objet                             *
********************************************************* */
COperationGraphe::COperationGraphe() {}

/* ********************************************************
*                      Inverser                           *
***********************************************************
* Entrée: CGraphe GRPGraphe                               *
* Nécessite: -                                            *
* Sortie: CGraphe                                         *
* Entraine: retourne un nouveau graphe inversé            *
* ******************************************************* */
CGraphe COperationGraphe::OPEInverserGraphe(CGraphe & GRPGraphe)
{
	unsigned int uiBoucle, uiNbSommet;

	CGraphe GRPResultat(GRPGraphe);

	uiNbSommet = GRPResultat.GRPLireNbSommet();
	for (uiBoucle = 0; uiBoucle < uiNbSommet; uiBoucle++) {
		GRPResultat.GRPIndexSommet(uiBoucle).SOMInverserArcs();
	}

	return GRPResultat;
}