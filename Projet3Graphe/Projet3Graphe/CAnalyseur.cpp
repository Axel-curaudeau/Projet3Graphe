#include "CAnalyseur.h"

/* ********************************************************
*               Constructeur par param?tre                *
***********************************************************
* Entr?e: char* pcChemin                                  *
* N?cessite: -                                            *
* Sortie: -                                               *
* Entraine: L'objet en cours est initialis? avec un       *
* 			 Lecteur du fichier donn? en param?tre.       *
********************************************************* */
CAnalyseur::CAnalyseur(char* pcChemin)
{
	pLEXANLLecteur = new CLexeur(pcChemin);
}

/* ********************************************************
*                      Destructeur                        *
***********************************************************
* Entr?e: -                                               *
* N?cessite: -                                            *
* Sortie: -                                               *
* Entraine: Detruit l'objet CLexeur.                      *
********************************************************* */
CAnalyseur::~CAnalyseur()
{
	delete pLEXANLLecteur;
}

/* ********************************************************
*                  Modifier le fichier                    *
***********************************************************
* Entr?e: char* pcFichier                                 *
* N?cessite: -                                            *
* Sortie: -                                               *
* Entraine: Modifie le Lecteur de fichier de l'objet en   *
* 		     cours.                                       *
********************************************************* */
void CAnalyseur::ANLModifierFichier(char* pcFichier)
{
	delete pLEXANLLecteur;
	pLEXANLLecteur = new CLexeur(pcFichier);
}

/* *********************************************************
*                Lire le nombre de sommets                 *
************************************************************
* Entr?e: -                                                *
* N?cessite: -                                             *
* Sortie: unsigned int uiNombreSommet                      *
* Entraine: Lit le nombre de sommets indiqu? dans le       *
* 		    fichier.                                      *
************************************************************/
unsigned int CAnalyseur::ANLLireNbSommets()
{
	char pcValeur[TAILLE_MAX_LIGNE];
	pLEXANLLecteur->LEXChercherValeur((char*)"NbSommets", pcValeur);
	return atoi(pcValeur);
}

/* *********************************************************
*                Lire le nombre d'arcs                     *
************************************************************
* Entr?e: -                                                *
* N?cessite: -                                             *
* Sortie: unsigned int uiNombreArc                         *
* Entraine: Lit le nombre d'arcs indiqu? dans le fichier.  *
************************************************************/
unsigned int CAnalyseur::ANLLireNbArcs()
{
	char pcValeur[TAILLE_MAX_LIGNE];
	pLEXANLLecteur->LEXChercherValeur((char*)"NbArcs", pcValeur);
	return atoi(pcValeur);
}

/* ********************************************************
*                  Lire les sommets                       *
***********************************************************
* Entr?e: CGraphe GRPGraphe                               *
* N?cessite: -                                            *
* Sortie: -                                               *
* Entraine: Lit les sommets indiqu?s dans le fichier,     *
*           et les alloue dans le Graphe donn? en         *
*           param?tre                                     *
********************************************************* */
void CAnalyseur::ANLLireSommets(CGraphe & GRPGraphe)
{
	unsigned int uiBoucle, uiNbSommets;
	char pcResult[TAILLE_MAX_LIGNE];

	//Lecture du nombre de sommets.
	uiNbSommets = ANLLireNbSommets();

	//Recherche de la ligne du d?but de la d?finition des sommets.
	pLEXANLLecteur->LEXChercherValeur((char*)"Sommets", pcResult);	
	if (!pLEXANLLecteur->LEXestEgal(pcResult, "[")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Crochet ouvrant manquant apres le mot cle \"sommets =\"");
	}
	
	//Lecture et allocation des sommets.
	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++) {
		try {
			pLEXANLLecteur->LEXLireValeurSuivante((char*)"Numero", pcResult);
			GRPGraphe.GRPAjouterSommet(atoi(pcResult));
		}
		catch (CException EXCE) {
			if (EXCE.EXCLireCode() == CLE_INTROUVABLE) {
				throw CException(CLE_INTROUVABLE, (char*)"Nombre de sommets declare inferieur a la valeur de NbSommet.");
			}
		}
	}

	//Lecture du crochet fermant.
	pLEXANLLecteur->LEXLireLigne(pcResult);
	if (!pLEXANLLecteur->LEXestEgal(pcResult, "]")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Erreur : crochet fermant \"]\" manquant ou nombre de sommets declare superieur a NbSommets.");
	}
}

/* ********************************************************
*                     Lire les arcs                       *
***********************************************************
* Entr?e: CGraphe GRPGraphe                               *
* N?cessite: -                                            *
* Sortie: -                                               *
* Entraine: Lit les arcs indiqu?s dans le fichier,        *
*           et les alloue dans le Graphe donn? en         *
*           param?tre                                     *
********************************************************* */
void CAnalyseur::ANLLireArcs(CGraphe & GRPGraphe)
{
	char pcLigne[TAILLE_MAX_LIGNE];
	char pcResult[TAILLE_MAX_LIGNE];
	char pcPartieDroite[TAILLE_MAX_LIGNE];
	char pcPartieGauche[TAILLE_MAX_LIGNE];
	unsigned int uiOrigine, uiDestination, uiNbArcs, uiBoucle;

	uiNbArcs = ANLLireNbArcs();

	pLEXANLLecteur->LEXChercherValeur((char*)"Arcs", pcResult);
	if (!pLEXANLLecteur->LEXestEgal(pcResult, "[")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Crochet ouvrant manquant apres le mot cle \"sommets =\"");
	}

	for (uiBoucle = 0; uiBoucle < uiNbArcs; uiBoucle++) {
		try {
			pLEXANLLecteur->LEXCoupeLigneSuivante(pcPartieGauche, pcPartieDroite, (char*)",");
			pLEXANLLecteur->LEXLireValeur(pcPartieGauche, (char*)"Debut", pcResult);
			if (!pLEXANLLecteur->LEXestUnNombre(pcResult)) {
				throw CException(ERREUR_SYNTAXE, (char*)"La valeur de Debut d'arc doit etre un nombre.");
			}
			uiOrigine = atoi(pcResult);

			pLEXANLLecteur->LEXLireValeur(pcPartieDroite, (char*)"Fin", pcResult);
			if (!pLEXANLLecteur->LEXestUnNombre(pcResult)) {
				throw CException(ERREUR_SYNTAXE, (char*)"La valeur de Fin d'arc doit etre un nombre.");
			}
			uiDestination = atoi(pcResult);

			GRPGraphe.GRPAjouterArc(uiOrigine, uiDestination);
		}
		catch (CException EXCE) {
			if (EXCE.EXCLireCode() == CLE_INTROUVABLE) {
				throw CException(CLE_INTROUVABLE, (char*)"Nombre d'arcs declare inferieur a la valeur de NbArcs.");
			}
		}
	}

	//Lecture du crochet fermant.
	pLEXANLLecteur->LEXLireLigne(pcResult);
	if (!pLEXANLLecteur->LEXestEgal(pcResult, "]")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Erreur : crochet fermant \"]\" manquant ou nombre d'arcs declare superieur a NbArcs.");
	}
}

/* ********************************************************
*                  Initialise le Graphe                   *
***********************************************************
* Entr?e: CGraphe GRPGraphe                               *
* N?cessite: -                                            *
* Sortie: -                                               *
* Entraine: Initialise le Graphe donn? en param?tre ?     *
*           partir du fichier. Allocution des sommets et  *
*           des arcs.                                     *
********************************************************* */
void CAnalyseur::ANLInitialiserGraphe(CGraphe& GRPGraphe)
{
	ANLLireSommets(GRPGraphe);
	ANLLireArcs(GRPGraphe);
}
