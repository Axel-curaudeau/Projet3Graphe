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

bool COperationGraphe::OPEEstUneClique(CGraphe GRPGraphe, int iSommet, ...)
{
	CSommet** ppSOMTabSommet = (CSommet**)malloc(1);
	CSommet** ppSOMTabSommetTemp = nullptr;
	unsigned int uiNbSommet = 0;
	unsigned int uiBoucle;
	unsigned int uiBoucle2;
	unsigned int uiBoucleArc;

	va_list vl;
	va_start(vl, iSommet);
	int iBoucleSommet = iSommet;
	
	while(iBoucleSommet != -1) {
		cout << iBoucleSommet << endl;

		//Verification existance du sommet.
		if (!GRPGraphe.GRPSommetExiste(iBoucleSommet)) {
			throw CException(NUMERO_SOMMMET_INEXISTANT, (char*)"Le sommets saisie est inexistant !");
		}

		//allocation m�moire.
		ppSOMTabSommetTemp = (CSommet**) realloc(ppSOMTabSommet, (uiNbSommet + 1) * sizeof(CSommet*));
		if (ppSOMTabSommetTemp == nullptr) {
			throw CException(MALLOC_ECHOUE, (char*)"L'allocation � �cou� !");
		}
		ppSOMTabSommet = ppSOMTabSommetTemp;
		ppSOMTabSommet[uiNbSommet] = (CSommet*) malloc(sizeof(CSommet));
		ppSOMTabSommet[uiNbSommet]->SOMInitialiser();
		*ppSOMTabSommet[uiNbSommet] = GRPGraphe.GRPObtenirSommet(iBoucleSommet);
		uiNbSommet++;

		iBoucleSommet = va_arg(vl, int);
	}

	va_end(vl); 

	for (uiBoucle = 0; uiBoucle < uiNbSommet; uiBoucle++) {
		ppSOMTabSommet[uiBoucle]->SOMAfficher();
		for (uiBoucle2 = 0; uiBoucle2 < uiNbSommet; uiBoucle2++) {

		}

	}
	return false;
}

