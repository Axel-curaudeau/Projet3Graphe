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

bool COperationGraphe::OPEEstUneClique(CGraphe & GRPGraphe)
{
	if (GRPGraphe.GRPEstOriente()) {
		throw CException(NON_ORIENTE, (char*)"Le graphe saisie ne doit pas etre oriente");
	}
	unsigned int uiNbSommet = GRPGraphe.GRPLireNbSommet();
	unsigned int uiBoucle;
	unsigned int uiBoucle2;


	for (uiBoucle = 0; uiBoucle < uiNbSommet; uiBoucle++) {
		for (uiBoucle2 = 0; uiBoucle2 < uiNbSommet; uiBoucle2++) {
			if (GRPGraphe.GRPIndexSommet(uiBoucle).SOMLireNumero() != GRPGraphe.GRPIndexSommet(uiBoucle2).SOMLireNumero()) {
				if (!GRPGraphe.GRPIndexSommet(uiBoucle).SOMArcEntrantExiste(GRPGraphe.GRPIndexSommet(uiBoucle2).SOMLireNumero())) {
					return false;
				}
			}
		}

	}
	return true;
}

bool COperationGraphe::OPEEstUneClique(CGraphe & GRPGraphe, int iSommet, ...)
{
	//initialisation des variables locales
	CGraphe* GRPSousGraphe = new CGraphe(GRPGraphe);
	int* piTabNumSommet = (int*) malloc((GRPGraphe.GRPLireNbSommet() + 1) * sizeof(int));
	if (piTabNumSommet == nullptr) {
		throw CException(MALLOC_ECHOUE, (char*)"L'allocation à écoué !");
	}
	piTabNumSommet[0] = -1;
	bool bResult;
	unsigned int uiNbSommet = 0;

	va_list vl;
	va_start(vl, iSommet);
	int iBoucleSommet = iSommet;
	
	while(iBoucleSommet != -1) {

		//Verification existance du sommet.
		if (!GRPGraphe.GRPSommetExiste(iBoucleSommet)) {
			throw CException(NUMERO_SOMMMET_INEXISTANT, (char*)"Le sommets saisie est inexistant : ");
		}

		piTabNumSommet[uiNbSommet] = iBoucleSommet;
		piTabNumSommet[uiNbSommet + 1] = -1;
		uiNbSommet++;

		iBoucleSommet = va_arg(vl, int);
	}
	va_end(vl);

	OPESousGraphe(GRPGraphe, *GRPSousGraphe, uiNbSommet, piTabNumSommet);
	bResult = OPEEstUneClique(*GRPSousGraphe);

	free(piTabNumSommet);
	delete GRPSousGraphe;
	return bResult;
}

void COperationGraphe::OPESousGraphe(CGraphe & GRPGraphe, CGraphe & GRPSousGraphe, unsigned int uiNbSommet, int* piTabNumSommet)
{
	unsigned int uiBoucle, uiBoucle2;
	bool bSupprimer;
	GRPSousGraphe = GRPGraphe;
	for (uiBoucle = 0; uiBoucle < GRPGraphe.GRPLireNbSommet(); uiBoucle++) {
		bSupprimer = true;
		for (uiBoucle2 = 0; uiBoucle2 < uiNbSommet; uiBoucle2++) {
			if (GRPGraphe.GRPIndexSommet(uiBoucle).SOMLireNumero() == piTabNumSommet[uiBoucle2]) {
				bSupprimer = false;
			}
		}
		if (bSupprimer) {
			GRPSousGraphe.GRPSupprimerSommet(GRPGraphe.GRPIndexSommet(uiBoucle).SOMLireNumero());
		}
	}
}

bool COperationGraphe::OPEEstUneClique(CGraphe GRPGraphe, unsigned int uiNbSommet, int* piTabSommet)
{
	bool bResult;
	CGraphe* GRPSousGraphe = new CGraphe();
	
	OPESousGraphe(GRPGraphe, *GRPSousGraphe, uiNbSommet, piTabSommet);
	
	bResult = OPEEstUneClique(*GRPSousGraphe);
	delete GRPSousGraphe;
	return bResult;
}
