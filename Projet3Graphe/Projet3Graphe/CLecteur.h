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
	 * Entrée: char* pcChemin                                  *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: L'objet en cours est initialisé en ouvrant    *
	 *           le fichier avec le chemin specifié			   *
	 *           Si le chemin est incorrect, une exception	   *
	 * 			 (FICHIER_INTROUVABLE) est levée.              *
	 ********************************************************* */
	CLecteur(char* pcChemin);

	/* *********************************************************
	 *            Constructeur de recopie SUPPRIMÉ             *
	 ********************************************************* */
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
	 *           et ouvre un nouveau fichier                   *
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
	 *           separe la ligne donné en paramètre            *
	 ***********************************************************
	 * Entrée: char pcLigne[]                                  *
	 *         char pcPrecedent[]                              *
	 *         char pcSuivant[]                                *
	 *         char* pcSeparator  							   *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit la ligne suivant, et la sépare en deux.   *
	 * 		 La première partie est copiée dans pcPrecedent    *
	 * 		 La seconde partie est copiée dans pcSuivant       *
	 * 		 Le caractère séparateur est spécifié dans         *
	 * 		 cSeparator.                                       *
	 ********************************************************* */
	void LECCoupeLigne(char* pcLigne, char pcPrecedent[], char pcSuivant[], char* pcSeparator);

	/* *********************************************************
	 *             Lit et separe la ligne suivante             *
	 ***********************************************************
	 * Entrée: char pcPrecedent[]                              *
	 *         char pcSuivant[]                                *
	 *         char pcSeparator  							   *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Lit la ligne suivant, et la sépare en deux.   *
	 * 		 La première partie est copiée dans pcPrecedent    *
	 * 		 La seconde partie est copiée dans pcSuivant       *
	 * 		 Le caractère séparateur est spécifié dans         *
	 * 		 cSeparator.                                       *
	 ********************************************************* */
	void LECCoupeLigneSuivante(char pcPrecedent[], char pcSuivant[], char* pcSeparator);

	/* *********************************************************
	 *      Lit la valeur de la ligne donné en paramètre       *
	 ***********************************************************
	 * Entrée: char
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
	 * Entrée: char pcLigne									   *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: retourne la ligne suivante dans pcLigne       *
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
	* Entraine: Enlève toutes les occurence de cChar dans      *
	*           pcChaine                                       *
	************************************************************/
	static void LECsuppChar(char pcChaine[], char cChar);

	/* *********************************************************
	 *          Transforme les majuscules en minuscule         *
	 ***********************************************************
	 * Entrée: char pcChaine[]                                 *
	 * Nécessite: -                                            *
	 * Sortie: -                                               *
	 * Entraine: Passe toutes les majuscules de pcChaine en    *
	 *           minuscule                                     *
	 ********************************************************* */
	static void LECenMinuscule(char pcChaine[]);

	/* *********************************************************
	 *         Verifie si les deux chaines sont égales         *
	 ***********************************************************
	 * Entrée: const char pcChaine1[]                          *
	 *         const char pcChaine2[]                          *
	 * Nécessite: -                                            *
	 * Sortie: bool                                            *
	 * Entraine: Retourne vrai si les 2 chaines sont           *
	 *            identiques                                   *
	 ********************************************************* */
	static bool LECestEgal(const char pcChaine1[], const char pcChaine2[]);

	/* *********************************************************
	 *           Verifie si la chaine est un nombre            *
	 ***********************************************************
	 * Entrée: const char pcChaine[]                           *
	 * Nécessite: -                                            *
	 * Sortie: bool                                            *
	 * Entraine: Retourne vrai si la chaines est un nombre     *
	 ********************************************************* */
	static bool LECestUnNombre(const char pcChaine[]);
};

#endif //CPARSEUR_H