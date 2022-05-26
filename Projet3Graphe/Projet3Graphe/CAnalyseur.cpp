#include "CAnalyseur.h"

/* *********************************************************
*               Constructeur par paramètre                 *
************************************************************
* Entrée: CLecteur pLECParseur                             *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: L'objet en cours est initialisé avec un        *
* 			 parseur de fichier.                           *
************************************************************/
CAnalyseur::CAnalyseur(CLecteur* pLECParseur)
{
	pLECANLParseur = pLECParseur;
}

/* *********************************************************
*                  Modifier le Parseur                     *
************************************************************
* Entrée: CLecteur pLECParseur                             *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: Modifie le parseur de fichier de l'objet en    *
* 		     cours.                                        *
************************************************************/
void CAnalyseur::ANLModifierParseur(CLecteur* LECParseur)
{
	pLECANLParseur = LECParseur;
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
	pLECANLParseur->LECChercherValeur((char*)"NbSommets", pcValeur);
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
	pLECANLParseur->LECChercherValeur((char*)"NbArcs", pcValeur);
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
void CAnalyseur::ANLLireSommets(CGraphe & GRPGraphe)
{
	char pcResult[TAILLE_MAX_LIGNE];
	pLECANLParseur->LECChercherValeur((char*)"Sommets", pcResult);
	if (!pLECANLParseur->LECestEgal(pcResult, "[")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Crochet ouvrant manquant apres le mot cle \"sommets =\"");
	}

	do {
		try {
			pLECANLParseur->LECLireValeurSuivante((char*)"Numero", pcResult);
			GRPGraphe.GRPAjouterSommet(atoi(pcResult));
		}
		catch (CException EXCE) {
			if (EXCE.EXCLireCode() == CLE_INTROUVABLE) {
				if (!pLECANLParseur->LECestEgal(pcResult, "]")) {
					throw CException(ERREUR_SYNTAXE, (char*)"Erreur : crochet fermant \"]\" manquant");
				}
			}
		}
	} while (!pLECANLParseur->LECestEgal(pcResult, "]"));
}

void CAnalyseur::ANLLireArcs(CGraphe & GRPGraphe)
{
	char pcLigne[TAILLE_MAX_LIGNE];
	char pcResult[TAILLE_MAX_LIGNE];
	char pcPartieDroite[TAILLE_MAX_LIGNE];
	char pcPartieGauche[TAILLE_MAX_LIGNE];
	unsigned int origine, destination;

	pLECANLParseur->LECChercherValeur((char*)"Arcs", pcResult);
	if (!pLECANLParseur->LECestEgal(pcResult, "[")) {
		throw CException(ERREUR_SYNTAXE, (char*)"Crochet ouvrant manquant apres le mot cle \"sommets =\"");
	}

	pLECANLParseur->LECLireLigne(pcLigne);
	while (!pLECANLParseur->LECestEgal(pcLigne, "]") || pcLigne == nullptr) {
		try {
			pLECANLParseur->LECCoupeLigne(pcLigne, pcPartieGauche, pcPartieDroite, (char*)",");

			pLECANLParseur->LECLireValeur(pcPartieGauche, (char*)"Debut", pcResult);
			if (!pLECANLParseur->LECestUnNombre(pcResult)) {
				throw CException(ERREUR_SYNTAXE, (char*)"La valeur de Debut d'arc doit etre un nombre.");
			}
			cout << "Debut = " << atoi(pcResult) << endl;
			origine = atoi(pcResult);

			pLECANLParseur->LECLireValeur(pcPartieDroite, (char*)"Fin", pcResult);
			if (!pLECANLParseur->LECestUnNombre(pcResult)) {
				throw CException(ERREUR_SYNTAXE, (char*)"La valeur de Fin d'arc doit etre un nombre.");
			}
			cout << "Fin = " << atoi(pcResult) << endl;
			destination = atoi(pcResult);

			GRPGraphe.GRPAjouterArc(origine, destination);

			pLECANLParseur->LECLireLigne(pcLigne);
		}
		catch (CException EXCE) {
			cout << EXCE.EXCLireMessage();
			break;
		}
	}
}
