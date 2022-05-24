#include "CParseur.h"

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
CParseur::CParseur(char* pcChemin) {
    IFSPRSFichier.open(pcChemin);
    if (!IFSPRSFichier.is_open()) {
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
CParseur::~CParseur() {
    IFSPRSFichier.close();
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
void CParseur::PRSModifierFichier(char* pcChemin) {
    if (IFSPRSFichier.is_open()) {
        IFSPRSFichier.close();
    }
    IFSPRSFichier.open(pcChemin);
    if (!IFSPRSFichier.is_open()) {
        throw new CException(FICHIER_INTROUVABLE, (char*)"l'Ouverture du fichier à échoué");
    }
}

/* *********************************************************
*               Lire une valeur                            *
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
void CParseur::PRSChercherValeur(char* pcCle, char pcValeur[]) {
    char pcPrecedent[TAILLE_MAX_LIGNE];
    char pcSuivant[TAILLE_MAX_LIGNE];
    char pcCleCopie[TAILLE_MAX_LIGNE];
    strcpy(pcCleCopie, pcCle);

    PRSsuppChar(pcCleCopie, ' ');
    PRSsuppChar(pcCleCopie, '\t');
    PRSenMinuscule(pcCleCopie);

    while (!IFSPRSFichier.eof()) {
        PRSCoupeLigneSuivante(pcPrecedent, pcSuivant, (char*)"=");
        if (PRSestEgal(pcPrecedent, pcCleCopie)) {
            strcpy(pcValeur, pcSuivant);
            return;
        }
    }
    throw CException(CLE_INTROUVABLE, (char*)"La cle specifie n'a pas ete trouve dans le fichier");
}

void CParseur::PRSCoupeLigne(char pcLigne[], char pcPrecedent[], char pcSuivant[], char* cSeparator) {
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
void CParseur::PRSCoupeLigneSuivante(char pcPrecedent[], char pcSuivant[], char* cSeparator) {
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
void CParseur::PRSLireValeur(char* pcLigne, char* pcCle, char pcValeur[])
{
    char pcPrecedent[TAILLE_MAX_LIGNE];
    char pcSuivant[TAILLE_MAX_LIGNE];
    char pcCleCopie[TAILLE_MAX_LIGNE];
    strcpy(pcCleCopie, pcCle);

    PRSsuppChar(pcCleCopie, ' ');
    PRSsuppChar(pcCleCopie, '\t');
    PRSenMinuscule(pcCleCopie);

    PRSCoupeLigne(pcLigne, pcPrecedent, pcSuivant, (char*)"=");
    if (PRSestEgal(pcPrecedent, pcCleCopie)) {
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
void CParseur::PRSLireValeurSuivante(char* pcCle, char pcValeur[])
{
    char pcPrecedent[TAILLE_MAX_LIGNE];
    char pcSuivant[TAILLE_MAX_LIGNE];
    char pcCleCopie[TAILLE_MAX_LIGNE];
    strcpy(pcCleCopie, pcCle);

    PRSsuppChar(pcCleCopie, ' ');
    PRSsuppChar(pcCleCopie, '\t');
    PRSenMinuscule(pcCleCopie);

    PRSCoupeLigne(PRSLireLigne(), pcPrecedent, pcSuivant, (char*)"=");
    if (PRSestEgal(pcPrecedent, pcCleCopie)) {
        strcpy(pcValeur, pcSuivant);
    }
    else {
        strcpy(pcValeur, pcPrecedent);
        throw CException(CLE_INTROUVABLE, (char*)"La cle specifie n'a pas ete trouve dans le fichier");
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
char* CParseur::PRSLireLigne()
{
    char pcLigne[TAILLE_MAX_LIGNE];
    IFSPRSFichier.getline(pcLigne, TAILLE_MAX_LIGNE);
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
void CParseur::PRSsuppChar(char pcChaine[], char cChar) {
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

void CParseur::PRSenMinuscule(char pcChaine[]) {
    unsigned int uiBoucle = 0;
    while (pcChaine[uiBoucle] != '\0') {
        pcChaine[uiBoucle] = tolower(pcChaine[uiBoucle]);
        uiBoucle++;
    }
    return;
}

bool CParseur::PRSestEgal(const char pcChaine1[], const char pcChaine2[]) {
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

bool CParseur::PRSestUnNombre(const char pcChaine[])
{
    if (pcChaine[0] < 48 || pcChaine[0] > 57) {
        return false;
    }
    return true;
}
