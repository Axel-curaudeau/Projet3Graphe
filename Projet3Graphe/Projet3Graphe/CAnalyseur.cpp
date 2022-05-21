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
	pPRSANLParseur->PRSLireValeur((char*)"NbSommets", pcValeur);
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
	pPRSANLParseur->PRSLireValeur((char*)"NbArcs", pcValeur);
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
