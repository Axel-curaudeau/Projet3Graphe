#include "CAnalyseur.h"

CAnalyseur::CAnalyseur(CParseur* pPRSParseur)
{
	pPRSANLParseur = pPRSParseur;
}

unsigned int CAnalyseur::ANLLireNbSommet()
{
	char pcValeur[TAILLE_MAX_LIGNE];
	pPRSANLParseur->PRSLireValeur((char*)"NbSommets", pcValeur);
	return atoi(pcValeur);
}

unsigned int CAnalyseur::ANLLireNbArc()
{
	char pcValeur[TAILLE_MAX_LIGNE];
	pPRSANLParseur->PRSLireValeur((char*)"NbArcs", pcValeur);
	return atoi(pcValeur);
}

void CAnalyseur::ANLLireSommets()
{
	char pcResult[TAILLE_MAX_LIGNE];
	pPRSANLParseur->PRSLireValeur((char*)"Sommets", pcResult);
	if (!pPRSANLParseur->PRSestEgal(pcResult, "[")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Crochet ouvrant manquant apres le mot cle \"sommets =\"");
	}
	do {
		try {
			pPRSANLParseur->PRSLireValeurSuivant((char*)"Numero", pcResult);
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
