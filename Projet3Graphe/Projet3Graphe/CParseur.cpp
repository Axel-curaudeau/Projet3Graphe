#include "CParseur.h"

#define MAX_LINE_SIZE 1000

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

char* PRSLireValeur(char* pcCle) {

}

void suppChar(char pcChaine[], char cChar){
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

void enMinuscule(char pcChaine[]){
	unsigned int uiBoucle = 0;
    while (pcChaine[uiBoucle] != '\0') {
        pcChaine[uiBoucle] = tolower(pcChaine[uiBoucle]);
        uiBoucle++;
    }
    return;
}

bool estEgal(const char pcChaine1[], const char pcChaine2[]){
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

void analyseLigne(ifstream & IFSPRSFichier, char pcPrecedent[], char pcSuivant[]){
    char pcLigne[MAX_LINE_SIZE];
    IFSPRSFichier.getline(pcLigne, MAX_LINE_SIZE);

    suppChar(pcLigne, ' ');
    suppChar(pcLigne, '\t');
    enMinuscule(pcLigne);
    
    strcpy(pcPrecedent, strtok(pcLigne, "="));
    strcpy(pcSuivant, strtok(nullptr, "="));
}