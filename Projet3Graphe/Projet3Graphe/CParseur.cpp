#include "CParseur.h"

#define MAX_LINE_SIZE 100

#pragma warning(disable : 4996)

using namespace std;

CParseur::CParseur(){
	IFSFichier = nullptr;
}

CParseur::CParseur(char* pcChemin){
	IFSFichier.open(pcChemin);
	if (!ISFfichier.isopen()){
		throw new CException(FICHIER_INTROUVABLE, (char *)"l'Ouverture du fichier à échoué");
	}
}

CParseur::PRSModifierFichier(char* pcChemin){
	if (IFSFichier.isopen()){
		IFSFichier.close();
	}
	IFSFichier.open(pcChemin);
	if (!ISFfichier.isopen()){
		throw new CException(FICHIER_INTROUVABLE, (char *)"l'Ouverture du fichier à échoué");
	}
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

void analyseLigne(ifstream & IFSFichier, char pcPrecedent[], char pcSuivant[]){
    char pcLigne[MAX_LINE_SIZE];
    IFSFichier.getline(pcLigne, MAX_LINE_SIZE);

    suppChar(pcLigne, ' ');
    suppChar(pcLigne, '\t');
    enMinuscule(pcLigne);
    
    strcpy(pcPrecedent, strtok(pcLigne, "="));
    strcpy(pcSuivant, strtok(nullptr, "="));
}