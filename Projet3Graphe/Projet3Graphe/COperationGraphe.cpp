#include "COperationGraphe.h"

/* ********************************************************
*                 Constructeur par d�faut                 *
***********************************************************
* Entr�e: -                                               *
* N�cessite: -                                            *
* Sortie: -                                               *
* Entraine: construit l'objet                             *
********************************************************* */
COperationGraphe::COperationGraphe() {}

/* ********************************************************
*                      Inverser                           *
***********************************************************
* Entr�e: CGraphe GRPGraphe                               *
* N�cessite: -                                            *
* Sortie: CGraphe                                         *
* Entraine: retourne un nouveau graphe invers�            *
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