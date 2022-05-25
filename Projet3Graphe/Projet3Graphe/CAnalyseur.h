#ifndef CANALYSEUR_H
#define CANALYSEUR_H

#include "CParseur.h"
#include "CGraphe.h"
#include <cstring>

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
	 *            Constructeur par defaut SUPPRIM�             *
	 ********************************************************* */
	CAnalyseur() = delete;

	/* *********************************************************
	 *               Constructeur par param�tre                *
	 ***********************************************************
	 * Entr�e: CParseur pPRSParseur                            *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: L'objet en cours est initialis� avec un       *
	 * 			 parseur de fichier.                           *
	 ********************************************************* */
	CAnalyseur(CParseur* pPRSParseur);

	/* *********************************************************
	 *                  Modifier le Parseur                    *
	 ***********************************************************
	 * Entr�e: CParseur pPRSParseur                            *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Modifie le parseur de fichier de l'objet en   *
	 * 		     cours.                                        *
	 ********************************************************* */
	void ANLModifierParseur(CParseur* PRSParseur);

	/* *********************************************************
	 *                Lire le nombre de sommets                *
	 ***********************************************************
	 * Entr�e: -                                               *
	 * N�cessite: -                                            *
	 * Sortie: unsigned int uiNombreSommet                     *
	 * Entraine: Lit le nombre de sommets indiqu� dans le      *
	 * 		     fichier du parseur.                           *
	 ********************************************************* */
	unsigned int ANLLireNbSommet();

	/* *********************************************************
	 *                Lire le nombre d'arcs                    *
	 ***********************************************************
	 * Entr�e: -                                               *
	 * N�cessite: -                                            *
	 * Sortie: unsigned int uiNombreArc                        *
	 * Entraine: Lit le nombre d'arcs indiqu� dans le fichier  *
	 * 		     du parseur.                                   *
	 ********************************************************* */
	unsigned int ANLLireNbArc();

	/* *********************************************************
	 *                  Lire les sommets                       *
	 ***********************************************************
	 * Entr�e: -                                               *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les sommets indiqu�s dans le fichier du   *
	 * 		     parseur, et les alloue.                       *
	 ********************************************************* */
	void ANLLireSommets(CGraphe & GRPGraphe);

	/* *********************************************************
	 *                  Lire les arcs                         *
	 ***********************************************************
	 * Entr�e: -                                               *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les arcs indiqu�s dans le fichier du      *
	 * 		     parseur, et les alloue.                       *
	 ********************************************************* */
	void ANLLireArcs(CGraphe & GRPGraph);
};

#endif