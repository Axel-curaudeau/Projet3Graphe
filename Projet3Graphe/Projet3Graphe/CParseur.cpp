#include "CParseur.h"

#define TAILLE_MAX_LIGNE 100

#pragma warning(disable : 4996)

using namespace std;

CParseur::CParseur(){}

CParseur::CParseur(char* pcChemin){
	IFSPRSFichier.open(pcChemin);
	if (!IFSPRSFichier.is_open()){
		throw new CException(FICHIER_INTROUVABLE, (char *)"l'Ouverture du fichier à échoué");
	}
}

void CParseur::PRSModifierFichier(char* pcChemin){
	if (IFSPRSFichier.is_open()){
		IFSPRSFichier.close();
	}
	IFSPRSFichier.open(pcChemin);
	if (!IFSPRSFichier.is_open()){
		throw new CException(FICHIER_INTROUVABLE, (char *)"l'Ouverture du fichier à échoué");
	}
}

char* CParseur::PRSLireValeur(char* pcCle) {
    char pcPrecedent[TAILLE_MAX_LIGNE], pcSuivant[TAILLE_MAX_LIGNE];
    while (!IFSPRSFichier.eof()) {
        PRSLigneSuivante(pcPrecedent, pcSuivant, (char*)"=");
        if (PRSestEgal(pcPrecedent, pcCle)) {
            return pcSuivant;
        }
    }
}

char* CParseur::PRSLigneSuivante(char pcPrecedent[], char pcSuivant[], char* cSeparator) {
    char pcLigne[TAILLE_MAX_LIGNE];
    IFSPRSFichier.getline(pcLigne, TAILLE_MAX_LIGNE);

    PRSsuppChar(pcLigne, ' ');
    PRSsuppChar(pcLigne, '\t');
    PRSenMinuscule(pcLigne);

    strcpy(pcPrecedent, strtok(pcLigne, cSeparator));
    strcpy(pcSuivant, strtok(nullptr, cSeparator));
}

void CParseur::PRSsuppChar(char pcChaine[], char cChar){
	unsigned int uiBoucle = 0;
    unsigned int uiBoucle2 = 0;
    if (pcChaine == nullptr) {
        return;
    }
    while (pcChaine[uiBoucle] != '\0') {
        if (pcChaine[uiBoucle] != cChar) {
            pcChaine[uiBoucle2] = pcChaine[uiBoucle];
            uiBoucle2++;
        }
        uiBoucle++;
    }
    pcChaine[uiBoucle2] = '\0';
}

void CParseur::PRSenMinuscule(char pcChaine[]){
	unsigned int uiBoucle = 0;
    while (pcChaine[uiBoucle] != '\0') {
        pcChaine[uiBoucle] = tolower(pcChaine[uiBoucle]);
        uiBoucle++;
    }
    return;
}

bool CParseur::PRSestEgal(const char pcChaine1[], const char pcChaine2[]){
    unsigned int uiBoucle = 0;

    // Si les 2 pointeurs sont null, alors ils sont égaux
    if (pcChaine1 == nullptr && pcChaine2 == nullptr) {
        return true;
    }
    if (pcChaine1 == nullptr || pcChaine2 == nullptr) {
		return false;
	}
    while (pcChaine1[uiBoucle] != '\0' && pcChaine2[uiBoucle] != '\0') {
        if (pcChaine1[uiBoucle] != pcChaine2[uiBoucle])
            return false;
        uiBoucle++;
    }
    if (pcChaine1[uiBoucle] != '\0' || pcChaine2[uiBoucle] != '\0')
        return false;
    return true;
}

/*void CParseur::PRSanalyseLigne(ifstream& IFSPRSFichier, char pcPrecedent[], char pcSuivant[]) {
    char pcLigne[TAILLE_MAX_LIGNE];
    IFSPRSFichier.getline(pcLigne, TAILLE_MAX_LIGNE);

    PRSsuppChar(pcLigne, ' ');
    PRSsuppChar(pcLigne, '\t');
    PRSenMinuscule(pcLigne);
    
    strcpy(pcPrecedent, strtok(pcLigne, "="));
    strcpy(pcSuivant, strtok(nullptr, "="));
}*/