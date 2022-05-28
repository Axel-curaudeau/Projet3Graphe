#ifndef CANALYSEUR_H
#define CANALYSEUR_H

#include "CLexeur.h"
#include "CGraphe.h"
#include <cstring>

#pragma warning(disable : 4996)

/* ===== ERROR CODES ===== */
#define ERREUR_SYNTAXE 10

/*
 * Classe CAnalyseur
 *
 * Cette class est utilis�e pour analyser les lignes lu par le CLexeur.
 */

class CAnalyseur
{
private:
	CLexeur* pLEXANLLecteur;
public:
	/* *********************************************************
	 *            Constructeur par defaut SUPPRIM�             *
	 ********************************************************* */
	CAnalyseur() = delete;

	/* *********************************************************
	 *               Constructeur par param�tre                *
	 ***********************************************************
	 * Entr�e: char* pcChemin                                  *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: L'objet en cours est initialis� avec un       *
	 * 			 Lecteur du fichier donn� en param�tre.        *
	 ********************************************************* */
	CAnalyseur(char* pcChemin);

	/* *********************************************************
	 *                      Destructeur                        *
	 ***********************************************************
	 * Entr�e: -                                               *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Detruit l'objet CLexeur.                      *
	 ********************************************************* */
	~CAnalyseur();

	/* *********************************************************
	 *                  Modifier le fichier                    *
	 ***********************************************************
	 * Entr�e: char* pcFichier                                 *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Modifie le Lecteur de fichier de l'objet en   *
	 * 		     cours.                                        *
	 ********************************************************* */
	void ANLModifierFichier(char* pcFichier);

	/* *********************************************************
	 *                Lire le nombre de sommets                *
	 ***********************************************************
	 * Entr�e: -                                               *
	 * N�cessite: -                                            *
	 * Sortie: unsigned int uiNombreSommet                     *
	 * Entraine: Lit le nombre de sommets indiqu� dans le      *
	 * 		     fichier.                                      *
	 ********************************************************* */
	unsigned int ANLLireNbSommets();

	/* *********************************************************
	 *                Lire le nombre d'arcs                    *
	 ***********************************************************
	 * Entr�e: -                                               *
	 * N�cessite: -                                            *
	 * Sortie: unsigned int uiNombreArc                        *
	 * Entraine: Lit le nombre d'arcs indiqu� dans le fichier. *
	 ********************************************************* */
	unsigned int ANLLireNbArcs();

	/* *********************************************************
	 *                  Lire les sommets                       *
	 ***********************************************************
	 * Entr�e: CGraphe GRPGraphe                               *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les sommets indiqu�s dans le fichier,     *
	 *           et les alloue dans le Graphe donn� en         *
	 *           param�tre                                     *
	 ********************************************************* */
	void ANLLireSommets(CGraphe & GRPGraphe);

	/* *********************************************************
	 *                     Lire les arcs                       *
	 ***********************************************************
	 * Entr�e: CGraphe GRPGraphe                               *
	 * N�cessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les arcs indiqu�s dans le fichier,        *
	 *           et les alloue dans le Graphe donn� en         *
	 *           param�tre                                     *
	 ********************************************************* */
	void ANLLireArcs(CGraphe & GRPGraph);

	/* ********************************************************
	*                  Initialise le Graphe                   *
	***********************************************************
	* Entr�e: CGraphe GRPGraphe                               *
	* N�cessite: -                                            *
	* Sortie: -                                               *
	* Entraine: Initialise le Graphe donn� en param�tre �     *
	*           partir du fichier. Allocution des sommets et  *
	*           des arcs.                                     *
	********************************************************* */
	void ANLInitialiserGraphe(CGraphe& GRPGraphe);
};

#endif //CANALYSEUR_h