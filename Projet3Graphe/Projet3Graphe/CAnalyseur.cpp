#include "CAnalyseur.h"

/* *********************************************************
*               Constructeur par param�tre                 *
************************************************************
* Entr�e: CParseur pPRSParseur                             *
* N�cessite: -                                             *
* Sortie: -                                                *
* Entraine: L'objet en cours est initialis� avec un        *
* 			 parseur de fichier.                           *
************************************************************/
CAnalyseur::CAnalyseur(CParseur* pPRSParseur)
{
	pPRSANLParseur = pPRSParseur;
}

/* *********************************************************
*                  Modifier le Parseur                     *
************************************************************
* Entr�e: CParseur pPRSParseur                             *
* N�cessite: -                                             *
* Sortie: -                                                *
* Entraine: Modifie le parseur de fichier de l'objet en    *
* 		     cours.                                        *
************************************************************/
void CAnalyseur::ANLModifierParseur(CParseur* PRSParseur)
{
	pPRSANLParseur = PRSParseur;
}

/* *********************************************************
*                Lire le nombre de sommets                 *
************************************************************
* Entr�e: -                                                *
* N�cessite: -                                             *
* Sortie: unsigned int uiNombreSommet                      *
* Entraine: Lit le nombre de sommets indiqu� dans le       *
* 		     fichier du parseur.                           *
************************************************************/
unsigned int CAnalyseur::ANLLireNbSommet()
{
	char pcValeur[TAILLE_MAX_LIGNE];
	pPRSANLParseur->PRSChercherValeur((char*)"NbSommets", pcValeur);
	return atoi(pcValeur);
}

/* *********************************************************
*                Lire le nombre d'arcs                     *
************************************************************
* Entr�e: -                                                *
* N�cessite: -                                             *
* Sortie: unsigned int uiNombreArc                         *
* Entraine: Lit le nombre d'arcs indiqu� dans le fichier   *
* 		     du parseur.                                   *
************************************************************/
unsigned int CAnalyseur::ANLLireNbArc()
{
	char pcValeur[TAILLE_MAX_LIGNE];
	pPRSANLParseur->PRSChercherValeur((char*)"NbArcs", pcValeur);
	return atoi(pcValeur);
}

/* *********************************************************
*                Lire le nombre de sommets                 *
************************************************************
* Entr�e: -                                                *
* N�cessite: -                                             *
* Sortie: unsigned int uiNombreSommet                      *
* Entraine: Lit le nombre de sommets indiqu� dans le       *
* 		     fichier du parseur.                           *
************************************************************/
void CAnalyseur::ANLLireSommets(CGraphe & GRPGraphe)
{
	char pcResult[TAILLE_MAX_LIGNE];
	pPRSANLParseur->PRSChercherValeur((char*)"Sommets", pcResult);
	if (!pPRSANLParseur->PRSestEgal(pcResult, "[")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Crochet ouvrant manquant apres le mot cle \"sommets =\"");
	}

	do {
		try {
			pPRSANLParseur->PRSLireValeurSuivante((char*)"Numero", pcResult);
			GRPGraphe.GRPAjouterSommet(atoi(pcResult));
		}
		catch (CException EXCE) {
			if (EXCE.EXCLireCode() == CLE_INTROUVABLE) {
				if (!pPRSANLParseur->PRSestEgal(pcResult, "]")) {
					throw CException(ERREUR_SYNTAXE, (char*)"Erreur : crochet fermant \"]\" manquant");
				}
			}
		}
	} while (!pPRSANLParseur->PRSestEgal(pcResult, "]"));
}

void CAnalyseur::ANLLireArcs(CGraphe GRPGraphe)
{
	char pcLigne[TAILLE_MAX_LIGNE];
	char pcResult[TAILLE_MAX_LIGNE];
	char pcPartieDroite[TAILLE_MAX_LIGNE];
	char pcPartieGauche[TAILLE_MAX_LIGNE];
	unsigned int origine, destination;

	pPRSANLParseur->PRSChercherValeur((char*)"Arcs", pcResult);
	if (!pPRSANLParseur->PRSestEgal(pcResult, "[")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Crochet ouvrant manquant apres le mot cle \"sommets =\"");
	}

	strcpy(pcLigne, pPRSANLParseur->PRSLireLigne());
	while (!pPRSANLParseur->PRSestEgal(pcLigne, "]") || pcLigne == nullptr) {
		try {
			pPRSANLParseur->PRSCoupeLigne(pcLigne, pcPartieGauche, pcPartieDroite, (char*)",");

			pPRSANLParseur->PRSLireValeur(pcPartieGauche, (char*)"Debut", pcResult);
			if (!pPRSANLParseur->PRSestUnNombre(pcResult)) {
				throw CException(ERREUR_SYNTAXE, (char*)"La valeur de Debut d'arc doit etre un nombre.");
			}
			cout << "Debut = " << atoi(pcResult) << endl;
			origine = atoi(pcResult);

			pPRSANLParseur->PRSLireValeur(pcPartieDroite, (char*)"Fin", pcResult);
			if (!pPRSANLParseur->PRSestUnNombre(pcResult)) {
				throw CException(ERREUR_SYNTAXE, (char*)"La valeur de Fin d'arc doit etre un nombre.");
			}
			cout << "Fin = " << atoi(pcResult) << endl;
			destination = atoi(pcResult);

			GRPGraphe.GRPAjouterArc(origine, destination);

			strcpy(pcLigne, pPRSANLParseur->PRSLireLigne());
		}
		catch (CException EXCE) {
			cout << EXCE.EXCLireMessage();
			break;
		}
	}
}
