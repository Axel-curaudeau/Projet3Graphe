#ifndef CPARSEUR_H
#define CPARSEUR_H

#include <iostream>
#include <fstream>
#include "CException.h"

using namespace std;

/* ===== ERROR CODES ===== */
#define FICHIER_INTROUVABLE 1

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
		void PRSModifierFichier(char* pcChemin);
		char* PRSLireValeur(char* pcCle);
		char* PRSLigneSuivante(char pcPrecedent[], char pcSuivant[], char* cSeparator);

	protected :
		void PRSsuppChar(char pcChaine[], char cChar);
		void PRSenMinuscule(char pcChaine[]);
		bool PRSestEgal(const char pcChaine1[], const char pcChaine2[]);
		//void PRSanalyseLigne(ifstream & IFSFichier, char pcPrecedent[], char pcSuivant[]);
};

#endif //CPARSEUR_H