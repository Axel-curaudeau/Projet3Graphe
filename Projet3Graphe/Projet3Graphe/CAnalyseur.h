#ifndef CANALYSEUR_H
#define CANALYSEUR_H

#include "CParseur.h"
#include "CGraphe.h"

#pragma warning(disable : 4996)

//Codes d'erreur
#define ERREUR_SYNTAXE 10
class CAnalyseur
{
private:
	CParseur* pPRSANLParseur;
	//CGraph GRFANLGraphe; 
public:
	/* *********************************************************
	 *            Constructeur par defaut SUPPRIMÉ             *
	 ********************************************************* */
	CAnalyseur() = delete;

	/* *********************************************************
	 *               Constructeur par paramètre                *
	 ***********************************************************
	 * Entrée: CParseur pPRSParseur                            *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: L'objet en cours est initialisé avec un       *
	 * 			 parseur de fichier.                           *
	 ********************************************************* */
	CAnalyseur(CParseur* pPRSParseur);

	/* *********************************************************
	 *                  Modifier le Parseur                    *
	 ***********************************************************
	 * Entrée: CParseur pPRSParseur                            *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Modifie le parseur de fichier de l'objet en   *
	 * 		     cours.                                        *
	 ********************************************************* */
	void ANLModifierParseur(CParseur* PRSParseur);

	/* *********************************************************
	 *                Lire le nombre de sommets                *
	 ***********************************************************
	 * Entrée: -                                               *
	 * Nécessite: -                                            *
	 * Sortie: unsigned int uiNombreSommet                     *
	 * Entraine: Lit le nombre de sommets indiqué dans le      *
	 * 		     fichier du parseur.                           *
	 ********************************************************* */
	unsigned int ANLLireNbSommet();

	/* *********************************************************
	 *                Lire le nombre d'arcs                    *
	 ***********************************************************
	 * Entrée: -                                               *
	 * Nécessite: -                                            *
	 * Sortie: unsigned int uiNombreArc                        *
	 * Entraine: Lit le nombre d'arcs indiqué dans le fichier  *
	 * 		     du parseur.                                   *
	 ********************************************************* */
	unsigned int ANLLireNbArc();

	/* *********************************************************
	 *                  Lire les sommets                       *
	 ***********************************************************
	 * Entrée: -                                               *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les sommets indiqués dans le fichier du   *
	 * 		     parseur, et les alloue.                       *
	 ********************************************************* */
	void ANLLireSommets(CGraphe & GRPGraphe);

	/* *********************************************************
	 *                  Lire les arcs                         *
	 ***********************************************************
	 * Entrée: -                                               *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les arcs indiqués dans le fichier du      *
	 * 		     parseur, et les alloue.                       *
	 ********************************************************* */
	void ANLLireArcs(CGraphe GRPGraph);
};

#endif