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
* Entraine: retourne un nouveau graphe inversé.           *
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
void COperationGraphe::OPESousGraphe(CGraphe& GRPGraphe, CGraphe& GRPSousGraphe, unsigned int uiNbSommet, int* piTabNumSommet)
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

/* ********************************************************
*                    Est une clique ?                     *
***********************************************************
* Entrée: CGraphe GRPGraphe                               *
* Nécessite: -                                            *
* Sortie: bool                                            *
* Entraine: retourne vrai si le graphe donné en entré     *
*           est une clique, faux sinon.                   *
* ******************************************************* */
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
bool COperationGraphe::OPEEstUneClique(CGraphe & GRPGraphe, int iSommet, ...)
{
	//initialisation des variables locales
	CGraphe* GRPSousGraphe = new CGraphe();
	int* piTabNumSommet = (int*) malloc(GRPGraphe.GRPLireNbSommet() * sizeof(int));
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
		if (uiNbSommet > GRPGraphe.GRPLireNbSommet()) {
			throw CException(NUMERO_SOMMMET_INEXISTANT, (char*)"Un sommet saisie n'esxiste pas dans le graphe !");
		}
		else {
			piTabNumSommet[uiNbSommet] = iBoucleSommet;
			uiNbSommet++;
		}
		

		iBoucleSommet = va_arg(vl, int);
	}
	va_end(vl);

	OPESousGraphe(GRPGraphe, *GRPSousGraphe, uiNbSommet, piTabNumSommet);
	bResult = OPEEstUneClique(*GRPSousGraphe);

	free(piTabNumSommet);
	delete GRPSousGraphe;
	return bResult;
}

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
bool COperationGraphe::OPEEstUneClique(CGraphe GRPGraphe, unsigned int uiNbSommet, int* piTabSommet)
{
	bool bResult;
	CGraphe* GRPSousGraphe = new CGraphe();
	
	OPESousGraphe(GRPGraphe, *GRPSousGraphe, uiNbSommet, piTabSommet);
	
	bResult = OPEEstUneClique(*GRPSousGraphe);
	delete GRPSousGraphe;
	return bResult;
}
