#include "CParseur.h"

#pragma warning(disable : 4996)

using namespace std;

CParseur::CParseur(){}

CParseur::CParseur(char* pcChemin){
	IFSPRSFichier.open(pcChemin);
	if (!IFSPRSFichier.is_open()){
		throw CException(FICHIER_INTROUVABLE, (char *)"l'Ouverture du fichier a echoue");
	}
}

CParseur::~CParseur() {
    IFSPRSFichier.close();
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

void CParseur::PRSLireValeur(char* pcCle, char pcValeur[]) {
    char pcPrecedent[TAILLE_MAX_LIGNE];
    char pcSuivant[TAILLE_MAX_LIGNE];
    char pcCleCopie[TAILLE_MAX_LIGNE];
    strcpy(pcCleCopie, pcCle);

    PRSsuppChar(pcCleCopie, ' ');
    PRSsuppChar(pcCleCopie, '\t');
    PRSenMinuscule(pcCleCopie);

    while (!IFSPRSFichier.eof()) {
        PRSLigneSuivante(pcPrecedent, pcSuivant, (char*)"=");
        if (PRSestEgal(pcPrecedent, pcCleCopie)) {
            strcpy(pcValeur, pcSuivant);
            return;
        }
    }
    throw CException(CLE_INTROUVABLE, (char*)"La cle specifie n'a pas ete trouve dans le fichier");
}

void CParseur::PRSLigneSuivante(char pcPrecedent[], char pcSuivant[], char* cSeparator) {
    char pcLigne[TAILLE_MAX_LIGNE];
    IFSPRSFichier.getline(pcLigne, TAILLE_MAX_LIGNE);

    PRSsuppChar(pcLigne, ' ');
    PRSsuppChar(pcLigne, '\t');
    PRSenMinuscule(pcLigne);

    char* pcTemporaire = strtok(pcLigne, cSeparator);
    if (pcTemporaire != nullptr) {
        strcpy(pcPrecedent, pcTemporaire);
    }

    pcTemporaire = strtok(nullptr, cSeparator);
    if (pcTemporaire != nullptr) {
        strcpy(pcSuivant, pcTemporaire);
    }
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