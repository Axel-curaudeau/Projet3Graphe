#include "CAnalyseur.h"

/* *********************************************************
*               Constructeur par paramètre                 *
************************************************************
* Entrée: CLecteur pLECLecteur                             *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: L'objet en cours est initialisé avec un        *
* 			 Lecteur de fichier.                           *
************************************************************/
CAnalyseur::CAnalyseur(CLecteur* pLECLecteur)
{
	pLECANLLecteur = pLECLecteur;
}

/* *********************************************************
*                  Modifier le Lecteur                     *
************************************************************
* Entrée: CLecteur pLECLecteur                             *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: Modifie le Lecteur de fichier de l'objet en    *
* 		     cours.                                        *
************************************************************/
void CAnalyseur::ANLModifierLecteur(CLecteur* LECLecteur)
{
	pLECANLLecteur = LECLecteur;
}

/* *********************************************************
*                Lire le nombre de sommets                 *
************************************************************
* Entrée: -                                                *
* Nécessite: -                                             *
* Sortie: unsigned int uiNombreSommet                      *
* Entraine: Lit le nombre de sommets indiqué dans le       *
* 		     fichier du Lecteur.                           *
************************************************************/
unsigned int CAnalyseur::ANLLireNbSommets()
{
	char pcValeur[TAILLE_MAX_LIGNE];
	pLECANLLecteur->LECChercherValeur((char*)"NbSommets", pcValeur);
	return atoi(pcValeur);
}

/* *********************************************************
*                Lire le nombre d'arcs                     *
************************************************************
* Entrée: -                                                *
* Nécessite: -                                             *
* Sortie: unsigned int uiNombreArc                         *
* Entraine: Lit le nombre d'arcs indiqué dans le fichier   *
* 		     du Lecteur.                                   *
************************************************************/
unsigned int CAnalyseur::ANLLireNbArcs()
{
	char pcValeur[TAILLE_MAX_LIGNE];
	pLECANLLecteur->LECChercherValeur((char*)"NbArcs", pcValeur);
	return atoi(pcValeur);
}

/* *********************************************************
*                Lire le nombre de sommets                 *
************************************************************
* Entrée: CGraphe GRPGraphe                                *
* Nécessite: -                                             *
* Sortie: unsigned int uiNombreSommet                      *
* Entraine: Lit le nombre de sommets indiqué dans le       *
* 		     fichier du Lecteur.                           *
************************************************************/
void CAnalyseur::ANLLireSommets(CGraphe & GRPGraphe)
{
	unsigned int uiBoucle, uiNbSommets;
	char pcResult[TAILLE_MAX_LIGNE];

	//Lecture du nombre de sommets.
	uiNbSommets = ANLLireNbSommets();

	//Recherche de la ligne du début de la définition des sommets.
	pLECANLLecteur->LECChercherValeur((char*)"Sommets", pcResult);	
	if (!pLECANLLecteur->LECestEgal(pcResult, "[")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Crochet ouvrant manquant apres le mot cle \"sommets =\"");
	}
	
	//Lecture et allocation des sommets.
	for (uiBoucle = 0; uiBoucle < uiNbSommets; uiBoucle++) {
		try {
			pLECANLLecteur->LECLireValeurSuivante((char*)"Numero", pcResult);
			GRPGraphe.GRPAjouterSommet(atoi(pcResult));
		}
		catch (CException EXCE) {
			if (EXCE.EXCLireCode() == CLE_INTROUVABLE) {
				throw CException(CLE_INTROUVABLE, (char*)"Nombre de sommets declare inferieur a la valeur de NbSommet.");
			}
		}
	}

	//Lecture du crochet fermant.
	pLECANLLecteur->LECLireLigne(pcResult);
	if (!pLECANLLecteur->LECestEgal(pcResult, "]")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Erreur : crochet fermant \"]\" manquant ou nombre de sommets declare superieur a NbSommets.");
	}
}

/* ********************************************************
*                  Lire les arcs                          *
***********************************************************
* Entrée: CGraphe GRPGraphe                               *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: Lit les arcs indiqués dans le fichier du      *
* 		     Lecteur, et les alloue.                      *
********************************************************* */
void CAnalyseur::ANLLireArcs(CGraphe & GRPGraphe)
{
	char pcLigne[TAILLE_MAX_LIGNE];
	char pcResult[TAILLE_MAX_LIGNE];
	char pcPartieDroite[TAILLE_MAX_LIGNE];
	char pcPartieGauche[TAILLE_MAX_LIGNE];
	unsigned int uiOrigine, uiDestination, uiNbArcs, uiBoucle;

	uiNbArcs = ANLLireNbArcs();

	pLECANLLecteur->LECChercherValeur((char*)"Arcs", pcResult);
	if (!pLECANLLecteur->LECestEgal(pcResult, "[")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Crochet ouvrant manquant apres le mot cle \"sommets =\"");
	}

	for (uiBoucle = 0; uiBoucle < uiNbArcs; uiBoucle++) {
		try {
			pLECANLLecteur->LECCoupeLigneSuivante(pcPartieGauche, pcPartieDroite, (char*)",");
			pLECANLLecteur->LECLireValeur(pcPartieGauche, (char*)"Debut", pcResult);
			if (!pLECANLLecteur->LECestUnNombre(pcResult)) {
				throw CException(ERREUR_SYNTAXE, (char*)"La valeur de Debut d'arc doit etre un nombre.");
			}
			uiOrigine = atoi(pcResult);

			pLECANLLecteur->LECLireValeur(pcPartieDroite, (char*)"Fin", pcResult);
			if (!pLECANLLecteur->LECestUnNombre(pcResult)) {
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
	pLECANLLecteur->LECLireLigne(pcResult);
	if (!pLECANLLecteur->LECestEgal(pcResult, "]")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Erreur : crochet fermant \"]\" manquant ou nombre d'arcs declare superieur a NbArcs.");
	}
}
