#include "CLecteur.h"

#pragma warning(disable : 4996)

using namespace std;

/* *********************************************************
*               Constructeur par paramètre                 *
************************************************************
* Entrée: unsigned int uiNumero                            *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: L'objet en cours est initialisé en ouvrant     *
*           le fichier avec le chemin specifié			   *
*           Si le chemin est incorrect, une exception	   *
* 			 (FICHIER_INTROUVABLE) est levée.              *
************************************************************/
CLecteur::CLecteur(char* pcChemin) {
    IFSLECFichier.open(pcChemin);
    if (!IFSLECFichier.is_open()) {
        throw CException(FICHIER_INTROUVABLE, (char*)"l'Ouverture du fichier a echoue");
    }
}


/* *********************************************************
*                       Destructeur                        *
************************************************************
* Entrée: -                                                *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: Ferme le fichier ouvert par l'objet en cours   *
************************************************************/
CLecteur::~CLecteur() {
    IFSLECFichier.close();
}

/* *********************************************************
*                  Modifier le fichier                     *
************************************************************
* Entrée: char* pcChemin                                   *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: Ferme le fichier ouvert par l'objet en cours   *
*           et ouvre le nouveau fichier                    *
*           Si le chemin est incorrect, une exception	   *
* 			 (FICHIER_INTROUVABLE) est levée.              *
************************************************************/
void CLecteur::LECModifierFichier(char* pcChemin) {
    if (IFSLECFichier.is_open()) {
        IFSLECFichier.close();
    }
    IFSLECFichier.open(pcChemin);
    if (!IFSLECFichier.is_open()) {
        throw new CException(FICHIER_INTROUVABLE, (char*)"l'Ouverture du fichier à échoué");
    }
}

/* *********************************************************
*               Chercher une valeur                        *
************************************************************
* Entrée: char* pcCle                                      *
*         char pcValeur[TAILLE_MAX_LIGNE]                  *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: Cherche la cle specifie dans le fichier        *
*           et la copie dans la variable pcValeur          *
*           Si la cle est introuvable, une exception       *
*           (CLE_INTROUVABLE) est levée.                   *
************************************************************/
void CLecteur::LECChercherValeur(char* pcCle, char pcValeur[]) {
    char pcPrecedent[TAILLE_MAX_LIGNE];
    char pcSuivant[TAILLE_MAX_LIGNE];
    char pcCleCopie[TAILLE_MAX_LIGNE];
    strcpy(pcCleCopie, pcCle);

    LECsuppChar(pcCleCopie, ' ');
    LECsuppChar(pcCleCopie, '\t');
    LECenMinuscule(pcCleCopie);

    IFSLECFichier.seekg(0, IFSLECFichier.beg);

    while (!IFSLECFichier.eof()) {
        LECCoupeLigneSuivante(pcPrecedent, pcSuivant, (char*)"=");
	if (LECestEgal(pcPrecedent, pcCleCopie)) {
            strcpy(pcValeur, pcSuivant);
	        LECsuppChar(pcValeur, '\r');
            LECsuppChar(pcValeur, ' ');
            LECsuppChar(pcValeur, '\t');
            return;
        }
    }
    throw CException(CLE_INTROUVABLE, (char*)"La cle specifie n'a pas ete trouve dans le fichier");
}

void CLecteur::LECCoupeLigne(char pcLigne[], char pcPrecedent[], char pcSuivant[], char* cSeparator) {
    LECsuppChar(pcLigne, ' ');
    LECsuppChar(pcLigne, '\t');
    LECenMinuscule(pcLigne);

    char* pcTemporaire = strtok(pcLigne, cSeparator);
    if (pcTemporaire != nullptr) {
        strcpy(pcPrecedent, pcTemporaire);
    }

    pcTemporaire = strtok(nullptr, cSeparator);
    if (pcTemporaire != nullptr) {
        strcpy(pcSuivant, pcTemporaire);
    }
}

/* *********************************************************
*            Lire et separe la ligne suivante              *
************************************************************
* Entrée: char pcPrecedent[]                               *
*         char pcSuivant[]                                 *
*         char cSeparator  							       *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: Lit la ligne suivant, et la sépare en deux.    *
* 		 La première partie est copiée dans pcPrecedent    *
* 		 La seconde partie est copiée dans pcSuivant       *
* 		 Le caractère séparateur est spécifié dans         *
* 		 cSeparator.                                       *
************************************************************/
void CLecteur::LECCoupeLigneSuivante(char pcPrecedent[], char pcSuivant[], char* cSeparator) {
    char pcLigne[TAILLE_MAX_LIGNE];
    IFSLECFichier.getline(pcLigne, TAILLE_MAX_LIGNE);

    LECsuppChar(pcLigne, ' ');
    LECsuppChar(pcLigne, '\t');
    LECenMinuscule(pcLigne);

    char* pcTemporaire = strtok(pcLigne, cSeparator);
    if (pcTemporaire != nullptr) {
        strcpy(pcPrecedent, pcTemporaire);
    }

    pcTemporaire = strtok(nullptr, cSeparator);
    if (pcTemporaire != nullptr) {
        strcpy(pcSuivant, pcTemporaire);
    }
}

/* *********************************************************
*               Lire la valeur de la ligne                 *
************************************************************
* Entrée: char* pcCle									   *
* 	       char pcValeur[]                                 *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: Cherche la cle specifié dans la ligne 	       *
* suivante, et copie la valeur associe dans pcValeur       *
************************************************************/
void CLecteur::LECLireValeur(char* pcLigne, char* pcCle, char pcValeur[])
{
    char pcPrecedent[TAILLE_MAX_LIGNE];
    char pcSuivant[TAILLE_MAX_LIGNE];
    char pcCleCopie[TAILLE_MAX_LIGNE];
    strcpy(pcCleCopie, pcCle);

    LECsuppChar(pcCleCopie, ' ');
    LECsuppChar(pcCleCopie, '\t');
    LECenMinuscule(pcCleCopie);

    LECCoupeLigne(pcLigne, pcPrecedent, pcSuivant, (char*)"=");
    if (LECestEgal(pcPrecedent, pcCleCopie)) {
        strcpy(pcValeur, pcSuivant);
    }
    else {
        strcpy(pcValeur, pcPrecedent);
        throw CException(CLE_INTROUVABLE, (char*)"La cle specifie n'a pas ete trouve dans le fichier");
    }

}

/* *********************************************************
*               Lire la valeur suivante                    *
************************************************************
* Entrée: char* pcCle									   *
* 	       char pcValeur[]                                 *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: Cherche la cle specifié dans la ligne 	       *
* suivante, et copie la valeur associe dans pcValeur       *
************************************************************/
void CLecteur::LECLireValeurSuivante(char* pcCle, char pcValeur[])
{
    char pcLigne[TAILLE_MAX_LIGNE];
    char pcPrecedent[TAILLE_MAX_LIGNE];
    char pcSuivant[TAILLE_MAX_LIGNE];
    char pcCleCopie[TAILLE_MAX_LIGNE];
    strcpy(pcCleCopie, pcCle);

    LECsuppChar(pcCleCopie, ' ');
    LECsuppChar(pcCleCopie, '\t');
    LECenMinuscule(pcCleCopie);

    LECLireLigne(pcLigne);
    LECCoupeLigne(pcLigne, pcPrecedent, pcSuivant, (char*)"=");
    if (LECestEgal(pcPrecedent, pcCleCopie)) {
        strcpy(pcValeur, pcSuivant);
    }
    else {
        strcpy(pcValeur, pcPrecedent);
        char pcMessage[TAILLE_MAX_LIGNE] = "La cle specifie n'a pas ete trouve dans le fichier : ";
        throw CException(CLE_INTROUVABLE, strcat(pcMessage, pcCle));
    }

}

/* *********************************************************
*                Lire la ligne suivante                    *
************************************************************
* Entrée: char* pcCle									   *
* 	       char pcValeur[]                                 *
* Nécessite: -                                             *
* Sortie: -                                                *
* Entraine: retourne la ligne suivant dans pcLigne	       *
************************************************************/
char* CLecteur::LECLireLigne(char pcLigne[])
{
    IFSLECFichier.getline(pcLigne, TAILLE_MAX_LIGNE);
    LECsuppChar(pcLigne, '\r');
    return pcLigne;
}

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
void CLecteur::LECsuppChar(char pcChaine[], char cChar) {
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

void CLecteur::LECenMinuscule(char pcChaine[]) {
    unsigned int uiBoucle = 0;
    while (pcChaine[uiBoucle] != '\0') {
        pcChaine[uiBoucle] = tolower(pcChaine[uiBoucle]);
        uiBoucle++;
    }
    return;
}

bool CLecteur::LECestEgal(const char pcChaine1[], const char pcChaine2[]) {
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
    if (pcChaine1[uiBoucle] != '\0' || pcChaine2[uiBoucle] != '\0') {
        return false;
    }
    return true;
}

bool CLecteur::LECestUnNombre(const char pcChaine[])
{
    if (pcChaine[0] < 48 || pcChaine[0] > 57) {
        return false;
    }
    return true;
}
