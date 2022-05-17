#ifndef CPARSEUR_H
#define CPARSEUR_H

#include <iostream>
#include <fstream>
#include "CException.h"

using namespace std;

#define TAILLE_MAX_LIGNE 1000

/* ===== ERROR CODES ===== */
#define FICHIER_INTROUVABLE 1
#define CLE_INTROUVABLE 2

/*
 * Classe CParseur
 *
 * Cette class est utilisée pour gérer les parseurs.
 */
class CParseur {
	private :
		ifstream IFSPRSFichier;
	public :
		CParseur();
		CParseur(char* pcChemin);
		~CParseur();
		void PRSModifierFichier(char* pcChemin);
		void PRSLireValeur(char* pcCle, char pcValeur[]);
		void PRSLigneSuivante(char pcPrecedent[], char pcSuivant[], char* cSeparator);
		void PRSLireValeurSuivant(char* pcCle, char pcValeur[]);
		void PRSLireLigne(char pcLigne[]);

		//fonction utilitaires :
		static void PRSsuppChar(char pcChaine[], char cChar);
		static void PRSenMinuscule(char pcChaine[]);
		static bool PRSestEgal(const char pcChaine1[], const char pcChaine2[]);
};

#endif //CPARSEUR_H