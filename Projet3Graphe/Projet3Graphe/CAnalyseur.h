#ifndef CANALYSEUR_H
#define CANALYSEUR_H

#include "CLexeur.h"
#include "CGraphe.h"
#include <cstring>

#pragma warning(disable : 4996)

//Codes d'erreur
#define ERREUR_SYNTAXE 10
class CAnalyseur
{
private:
	CLexeur* pLEXANLLecteur;
	//CGraph GRFANLGraphe; 
public:
	/* *********************************************************
	 *            Constructeur par defaut SUPPRIM�             *
	 ********************************************************* */
	CAnalyseur() = delete;

	/* *********************************************************
	 *               Constructeur par param�tre                *
	 ***********************************************************
	 * Entr�e: CLexeur pLECLexeur                            *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: L'objet en cours est initialis� avec un       *
	 * 			 Lecteur de fichier.                           *
	 ********************************************************* */
	CAnalyseur(CLexeur* pLECLexeur);

	/* *********************************************************
	 *                  Modifier le Lecteur                    *
	 ***********************************************************
	 * Entr�e: CLexeur pLECLexeur                            *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Modifie le Lecteur de fichier de l'objet en   *
	 * 		     cours.                                        *
	 ********************************************************* */
	void ANLModifierLecteur(CLexeur* pLECLexeur);

	/* *********************************************************
	 *                Lire le nombre de sommets                *
	 ***********************************************************
	 * Entr�e: -                                               *
	 * N�cessite: -                                            *
	 * Sortie: unsigned int uiNombreSommet                     *
	 * Entraine: Lit le nombre de sommets indiqu� dans le      *
	 * 		     fichier du Lecteur.                           *
	 ********************************************************* */
	unsigned int ANLLireNbSommets();

	/* *********************************************************
	 *                Lire le nombre d'arcs                    *
	 ***********************************************************
	 * Entr�e: -                                               *
	 * N�cessite: -                                            *
	 * Sortie: unsigned int uiNombreArc                        *
	 * Entraine: Lit le nombre d'arcs indiqu� dans le fichier  *
	 * 		     du Lecteur.                                   *
	 ********************************************************* */
	unsigned int ANLLireNbArcs();

	/* *********************************************************
	 *                  Lire les sommets                       *
	 ***********************************************************
	 * Entr�e: CGraphe GRPGraphe                               *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les sommets indiqu�s dans le fichier du   *
	 * 		     Lecteur, et les alloue.                       *
	 ********************************************************* */
	void ANLLireSommets(CGraphe & GRPGraphe);

	/* *********************************************************
	 *                  Lire les arcs                         *
	 ***********************************************************
	 * Entr�e: CGraphe GRPGraphe                               *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les arcs indiqu�s dans le fichier du      *
	 * 		     Lecteur, et les alloue.                       *
	 ********************************************************* */
	void ANLLireArcs(CGraphe & GRPGraph);
};

#endif