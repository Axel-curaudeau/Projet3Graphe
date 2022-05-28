#include "COperationGraphe.h"

COperationGraphe::COperationGraphe() {}

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