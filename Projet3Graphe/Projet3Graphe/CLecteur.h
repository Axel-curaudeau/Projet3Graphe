#ifndef CLECTEUR_H
#define CLECTEUR_H

#include <iostream>
#include <fstream>
#include "CException.h"
#include <cstring>

using namespace std;

#define TAILLE_MAX_LIGNE 1000

/* ===== ERROR CODES ===== */
#define FICHIER_INTROUVABLE 1
#define CLE_INTROUVABLE 2

/*
 * Classe CLecteur
 *
 * Cette class est utilisée pour lire un fichier texte sur le modèle clé associe valeur (exemple : NombreSommet = 1).
 */
class CLecteur {
private:
	ifstream IFSLECFichier;
public:
	/* *********************************************************
	 *            Constructeur par defaut SUPPRIMÉ             *
	 ********************************************************* */
	CLecteur() = delete;

	/* *********************************************************
	 *               Constructeur par paramètre                *
	 ***********************************************************
	 * Entrée: unsigned int uiNumero                           *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: L'objet en cours est initialisé en ouvrant    *
	 *           le fichier avec le chemin specifié			   *
	 *           Si le chemin est incorrect, une exception	   *
	 * 			 (FICHIER_INTROUVABLE) est levée.              *
	 ********************************************************* */
	CLecteur(char* pcChemin);

	CLecteur(CLecteur& LECLecteur) = delete;

	/* *********************************************************
	 *                       Destructeur                       *
	 ***********************************************************
	 * Entrée: -                                               *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Ferme le fichier ouvert par l'objet en cours  *
	 ********************************************************* */
	~CLecteur();

	/* *********************************************************
	 *               Modifier le fichier                       *
	 ***********************************************************
	 * Entrée: char* pcChemin                                  *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Ferme le fichier ouvert par l'objet en cours  *
	 *           et ouvre le nouveau fichier                   *
	 *           Si le chemin est incorrect, une exception	   *
	 * 			 (FICHIER_INTROUVABLE) est levée.              *
	 ********************************************************* */
	void LECModifierFichier(char* pcChemin);

	/* *********************************************************
	 *               Cherche une valeur                        *
	 ***********************************************************
	 * Entrée: char* pcCle                                     *
	 *         char pcValeur[TAILLE_MAX_LIGNE]                 *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Cherche la cle specifie dans le fichier       *
	 *           et la copie dans la variable pcValeur         *
	 *           Si la cle est introuvable, une exception      *
	 *           (CLE_INTROUVABLE) est levée.                  *
	 ********************************************************* */
	void LECChercherValeur(char* pcCle, char pcValeur[]);

	/* *********************************************************
	 *            Lire et separe la ligne suivante             *
	 ***********************************************************
	 * Entrée: char pcPrecedent[]                              *
	 *         char pcSuivant[]                                *
	 *         char cSeparator  							   *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit la ligne suivant, et la sépare en deux.   *
	 * 		 La première partie est copiée dans pcPrecedent    *
	 * 		 La seconde partie est copiée dans pcSuivant       *
	 * 		 Le caractère séparateur est spécifié dans         *
	 * 		 cSeparator.                                       *
	 ********************************************************* */
	void LECCoupeLigne(char pcLigne[], char pcPrecedent[], char pcSuivant[], char* cSeparator);

	/* *********************************************************
	 *            Lire et separe la ligne suivante             *
	 ***********************************************************
	 * Entrée: char pcPrecedent[]                              *
	 *         char pcSuivant[]                                *
	 *         char cSeparator  							   *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit la ligne suivant, et la sépare en deux.   *
	 * 		 La première partie est copiée dans pcPrecedent    *
	 * 		 La seconde partie est copiée dans pcSuivant       *
	 * 		 Le caractère séparateur est spécifié dans         *
	 * 		 cSeparator.                                       *
	 ********************************************************* */
	void LECCoupeLigneSuivante(char pcPrecedent[], char pcSuivant[], char* cSeparator);

	/* *********************************************************
	 *               Lire la valeur de la ligne                *
	 ***********************************************************
	 * Entrée: char* pcCle									   *
	 * 	       char pcValeur[]                                 *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Cherche la cle specifié dans la ligne 	       *
	 * suivante, et copie la valeur associe dans pcValeur      *
	 ********************************************************* */
	void LECLireValeur(char* pcLigne, char* pcCle, char pcValeur[]);

	/* *********************************************************
	 *               Lire la valeur suivante                   *
	 ***********************************************************
	 * Entrée: char* pcCle									   *
	 * 	       char pcValeur[]                                 *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Cherche la cle specifié dans la ligne 	       *
	 * suivante, et copie la valeur associe dans pcValeur      *
	 ********************************************************* */
	void LECLireValeurSuivante(char* pcCle, char pcValeur[]);

	/* *********************************************************
	 *                Lire la ligne suivante                   *
	 ***********************************************************
	 * Entrée: char* pcCle									   *
	 * 	       char pcValeur[]                                 *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: retourne la ligne suivant dans pcLigne	       *
	 ********************************************************* */
	char* LECLireLigne(char pcLigne[]);

	//fonction utilitaires :
	/* *********************************************************
	*                Supprimer un caractère                    *
	************************************************************
	* Entrée: char pcChaine[]                                  *
	*         const char cChar                                 *
	* Nécessite: -                                             *
	* Sortie: -                                                *
	* Entraine: (Modifie pcChaine pour enlever toute les       *
	*           occurences de cChar).                          *
	************************************************************/
	static void LECsuppChar(char pcChaine[], char cChar);

	static void LECenMinuscule(char pcChaine[]);
	static bool LECestEgal(const char pcChaine1[], const char pcChaine2[]);
	static bool LECestUnNombre(const char pcChaine[]);
};

#endif //CPARSEUR_H