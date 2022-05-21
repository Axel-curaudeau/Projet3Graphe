#include "CAnalyseur.h"

/* *********************************************************
*               Constructeur par paramètre                 *
************************************************************
* Entrée: CParseur pPRSParseur                             *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: L'objet en cours est initialisé avec un        *
* 			 parseur de fichier.                           *
************************************************************/
CAnalyseur::CAnalyseur(CParseur* pPRSParseur)
{
	pPRSANLParseur = pPRSParseur;
}

/* *********************************************************
*                  Modifier le Parseur                     *
************************************************************
* Entrée: CParseur pPRSParseur                             *
* Nécessite: -                                             *
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
* Entrée: -                                                *
* Nécessite: -                                             *
* Sortie: unsigned int uiNombreSommet                      *
* Entraine: Lit le nombre de sommets indiqué dans le       *
* 		     fichier du parseur.                           *
************************************************************/
unsigned int CAnalyseur::ANLLireNbSommet()
{
	char pcValeur[TAILLE_MAX_LIGNE];
	pPRSANLParseur->PRSLireValeur((char*)"NbSommets", pcValeur);
	return atoi(pcValeur);
}

/* *********************************************************
*                Lire le nombre d'arcs                     *
************************************************************
* Entrée: -                                                *
* Nécessite: -                                             *
* Sortie: unsigned int uiNombreArc                         *
* Entraine: Lit le nombre d'arcs indiqué dans le fichier   *
* 		     du parseur.                                   *
************************************************************/
unsigned int CAnalyseur::ANLLireNbArc()
{
	char pcValeur[TAILLE_MAX_LIGNE];
	pPRSANLParseur->PRSLireValeur((char*)"NbArcs", pcValeur);
	return atoi(pcValeur);
}

/* *********************************************************
*                Lire le nombre de sommets                 *
************************************************************
* Entrée: -                                                *
* Nécessite: -                                             *
* Sortie: unsigned int uiNombreSommet                      *
* Entraine: Lit le nombre de sommets indiqué dans le       *
* 		     fichier du parseur.                           *
************************************************************/
void CAnalyseur::ANLLireSommets()
{
	char pcResult[TAILLE_MAX_LIGNE];
	pPRSANLParseur->PRSLireValeur((char*)"Sommets", pcResult);
	if (!pPRSANLParseur->PRSestEgal(pcResult, "[")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Crochet ouvrant manquant apres le mot cle \"sommets =\"");
	}
	do {
		try {
			pPRSANLParseur->PRSLireValeurSuivante((char*)"Numero", pcResult);
			cout << pcResult << endl;
		}
		catch (CException EXCE) {
			if (EXCE.EXCLireCode() == CLE_INTROUVABLE) {
				cout << pcResult << endl;
				if (!pPRSANLParseur->PRSestEgal(pcResult, "]")) {
					throw CException(ERREUR_SYNTAXE, (char*)"Erreur : crochet fermant \"]\" manquant");
				}
			}
		}
	} while (!pPRSANLParseur->PRSestEgal(pcResult, "]"));
}
