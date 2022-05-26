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
	 *            Constructeur par defaut SUPPRIMÉ             *
	 ********************************************************* */
	CAnalyseur() = delete;

	/* *********************************************************
	 *               Constructeur par paramètre                *
	 ***********************************************************
	 * Entrée: CLexeur pLECLexeur                            *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: L'objet en cours est initialisé avec un       *
	 * 			 Lecteur de fichier.                           *
	 ********************************************************* */
	CAnalyseur(CLexeur* pLECLexeur);

	/* *********************************************************
	 *                  Modifier le Lecteur                    *
	 ***********************************************************
	 * Entrée: CLexeur pLECLexeur                            *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Modifie le Lecteur de fichier de l'objet en   *
	 * 		     cours.                                        *
	 ********************************************************* */
	void ANLModifierLecteur(CLexeur* pLECLexeur);

	/* *********************************************************
	 *                Lire le nombre de sommets                *
	 ***********************************************************
	 * Entrée: -                                               *
	 * Nécessite: -                                            *
	 * Sortie: unsigned int uiNombreSommet                     *
	 * Entraine: Lit le nombre de sommets indiqué dans le      *
	 * 		     fichier du Lecteur.                           *
	 ********************************************************* */
	unsigned int ANLLireNbSommets();

	/* *********************************************************
	 *                Lire le nombre d'arcs                    *
	 ***********************************************************
	 * Entrée: -                                               *
	 * Nécessite: -                                            *
	 * Sortie: unsigned int uiNombreArc                        *
	 * Entraine: Lit le nombre d'arcs indiqué dans le fichier  *
	 * 		     du Lecteur.                                   *
	 ********************************************************* */
	unsigned int ANLLireNbArcs();

	/* *********************************************************
	 *                  Lire les sommets                       *
	 ***********************************************************
	 * Entrée: CGraphe GRPGraphe                               *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les sommets indiqués dans le fichier du   *
	 * 		     Lecteur, et les alloue.                       *
	 ********************************************************* */
	void ANLLireSommets(CGraphe & GRPGraphe);

	/* *********************************************************
	 *                  Lire les arcs                         *
	 ***********************************************************
	 * Entrée: CGraphe GRPGraphe                               *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit les arcs indiqués dans le fichier du      *
	 * 		     Lecteur, et les alloue.                       *
	 ********************************************************* */
	void ANLLireArcs(CGraphe & GRPGraph);
};

#endif