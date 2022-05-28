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
 * Cette class est utilisée pour analyser les lignes lu par le CLexeur.
 */

class CAnalyseur
{
private:
	CLexeur* pLEXANLLecteur;
public:
	/* *********************************************************
	 *            Constructeur par defaut SUPPRIMÉ             *
	 ********************************************************* */
	CAnalyseur() = delete;

	/* *********************************************************
	 *               Constructeur par paramètre                *
	 ***********************************************************
	 * Entrée: char* pcChemin                                  *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: L'objet en cours est initialisé avec un       *
	 * 			 Lecteur du fichier donné en paramètre.        *
	 ********************************************************* */
	CAnalyseur(char* pcChemin);

	/* *********************************************************
	 *                      Destructeur                        *
	 ***********************************************************
	 * Entrée: -                                               *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Detruit l'objet CLexeur.                      *
	 ********************************************************* */
	~CAnalyseur();

	/* *********************************************************
	 *                  Modifier le fichier                    *
	 ***********************************************************
	 * Entrée: char* pcFichier                                 *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Modifie le Lecteur de fichier de l'objet en   *
	 * 		     cours.                                        *
	 ********************************************************* */
	void ANLModifierFichier(char* pcFichier);

	/* *********************************************************
	 *                Lire le nombre de sommets                *
	 ***********************************************************
	 * Entrée: -                                               *
	 * Nécessite: -                                            *
	 * Sortie: unsigned int uiNombreSommet                     *
	 * Entraine: Lit le nombre de sommets indiqué dans le      *
	 * 		     fichier.                                      *
	 ********************************************************* */
	unsigned int ANLLireNbSommets();

	/* *********************************************************
	 *                Lire le nombre d'arcs                    *
	 ***********************************************************
	 * Entrée: -                                               *
	 * Nécessite: -                                            *
	 * Sortie: unsigned int uiNombreArc                        *
	 * Entraine: Lit le nombre d'arcs indiqué dans le fichier. *
	 ********************************************************* */
	unsigned int ANLLireNbArcs();

	/* *********************************************************
	 *                  Lire les sommets                       *
	 ***********************************************************
	 * Entrée: CGraphe GRPGraphe                               *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les sommets indiqués dans le fichier,     *
	 *           et les alloue dans le Graphe donné en         *
	 *           paramètre                                     *
	 ********************************************************* */
	void ANLLireSommets(CGraphe & GRPGraphe);

	/* *********************************************************
	 *                     Lire les arcs                       *
	 ***********************************************************
	 * Entrée: CGraphe GRPGraphe                               *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les arcs indiqués dans le fichier,        *
	 *           et les alloue dans le Graphe donné en         *
	 *           paramètre                                     *
	 ********************************************************* */
	void ANLLireArcs(CGraphe & GRPGraph);

	/* ********************************************************
	*                  Initialise le Graphe                   *
	***********************************************************
	* Entrée: CGraphe GRPGraphe                               *
	* Nécessite: -                                            *
	* Sortie: -                                               *
	* Entraine: Initialise le Graphe donné en paramètre à     *
	*           partir du fichier. Allocution des sommets et  *
	*           des arcs.                                     *
	********************************************************* */
	void ANLInitialiserGraphe(CGraphe& GRPGraphe);
};

#endif //CANALYSEUR_h