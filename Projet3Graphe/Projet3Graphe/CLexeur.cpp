#include "CLexeur.h"

#pragma warning(disable : 4996)

using namespace std;

/* ********************************************************
*               Constructeur par paramètre                *
***********************************************************
* Entrée: char* pcChemin                                  *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: L'objet en cours est initialisé en ouvrant    *
*           le fichier avec le chemin specifié.			  *
*           Si le chemin est incorrect, une exception	  *
* 			 (FICHIER_INTROUVABLE) est levée.             *
***********************************************************/
CLexeur::CLexeur(char* pcChemin) {
    IFSLEXFichier.open(pcChemin);
    if (!IFSLEXFichier.is_open()) {
        throw CException(FICHIER_INTROUVABLE, (char*)"l'Ouverture du fichier a echoue, fichier introuvable !");
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
CLexeur::~CLexeur() {
    IFSLEXFichier.close();
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
void CLexeur::LEXModifierFichier(char* pcChemin) {
    if (IFSLEXFichier.is_open()) {
        IFSLEXFichier.close();
    }
    IFSLEXFichier.open(pcChemin);
    if (!IFSLEXFichier.is_open()) {
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
void CLexeur::LEXChercherValeur(char* pcCle, char pcValeur[]) {
    char pcPrecedent[TAILLE_MAX_LIGNE];
    char pcSuivant[TAILLE_MAX_LIGNE];
    char pcCLEXopie[TAILLE_MAX_LIGNE];
    strcpy(pcCLEXopie, pcCle);

    LEXsuppChar(pcCLEXopie, ' ');
    LEXsuppChar(pcCLEXopie, '\t');
    LEXenMinuscule(pcCLEXopie);

    IFSLEXFichier.seekg(0, IFSLEXFichier.beg);

    while (!IFSLEXFichier.eof()) {
        LEXCoupeLigneSuivante(pcPrecedent, pcSuivant, (char*)"=");
	if (LEXestEgal(pcPrecedent, pcCLEXopie)) {
            strcpy(pcValeur, pcSuivant);
	        LEXsuppChar(pcValeur, '\r');
            LEXsuppChar(pcValeur, ' ');
            LEXsuppChar(pcValeur, '\t');
            return;
        }
    }
    throw CException(CLE_INTROUVABLE, (char*)"La cle specifie n'a pas ete trouve dans le fichier");
}

/* ********************************************************
*           separe la ligne donné en paramètre            *
***********************************************************
* Entrée: char pcLigne[]                                  *
*         char pcPrecedent[]                              *
*         char pcSuivant[]                                *
*         char* pcSeparator  							  *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: sépare en deux la ligne donné dans pcLigne.   *
* 		 La première partie est copiée dans pcPrecedent   *
* 		 La seconde partie est copiée dans pcSuivant      *
* 		 Le caractère séparateur est spécifié dans        *
* 		 cSeparator.                                      *
********************************************************* */
void CLexeur::LEXCoupeLigne(char* pcLigne, char pcPrecedent[], char pcSuivant[], char* cSeparator) {
    LEXsuppChar(pcLigne, ' ');
    LEXsuppChar(pcLigne, '\t');
    LEXenMinuscule(pcLigne);

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
void CLexeur::LEXCoupeLigneSuivante(char pcPrecedent[], char pcSuivant[], char* cSeparator) {
    char pcLigne[TAILLE_MAX_LIGNE];
    IFSLEXFichier.getline(pcLigne, TAILLE_MAX_LIGNE);

    LEXsuppChar(pcLigne, ' ');
    LEXsuppChar(pcLigne, '\t');
    LEXenMinuscule(pcLigne);

    char* pcTemporaire = strtok(pcLigne, cSeparator);
    if (pcTemporaire != nullptr) {
        strcpy(pcPrecedent, pcTemporaire);
    }

    pcTemporaire = strtok(nullptr, cSeparator);
    if (pcTemporaire != nullptr) {
        strcpy(pcSuivant, pcTemporaire);
    }
}

/* ********************************************************
*      Lit la valeur de la ligne donné en paramètre       *
***********************************************************
* Entrée: char* pcLigne                                   *
* Entrée: char* pcCle									  *
* 	       char pcValeur[]                                *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: Cherche la cle specifié dans la chaine        *
*           pcLigne, et copie la valeur associe dans      *
*           pcValeur                                      *
********************************************************* */
void CLexeur::LEXLireValeur(char* pcLigne, char* pcCle, char pcValeur[])
{
    char pcPrecedent[TAILLE_MAX_LIGNE];
    char pcSuivant[TAILLE_MAX_LIGNE];
    char pcCLEXopie[TAILLE_MAX_LIGNE];
    strcpy(pcCLEXopie, pcCle);

    LEXsuppChar(pcCLEXopie, ' ');
    LEXsuppChar(pcCLEXopie, '\t');
    LEXenMinuscule(pcCLEXopie);

    LEXCoupeLigne(pcLigne, pcPrecedent, pcSuivant, (char*)"=");
    if (LEXestEgal(pcPrecedent, pcCLEXopie)) {
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
void CLexeur::LEXLireValeurSuivante(char* pcCle, char pcValeur[])
{
    char pcLigne[TAILLE_MAX_LIGNE];
    char pcPrecedent[TAILLE_MAX_LIGNE];
    char pcSuivant[TAILLE_MAX_LIGNE];
    char pcCLEXopie[TAILLE_MAX_LIGNE];
    strcpy(pcCLEXopie, pcCle);

    LEXsuppChar(pcCLEXopie, ' ');
    LEXsuppChar(pcCLEXopie, '\t');
    LEXenMinuscule(pcCLEXopie);

    LEXLireLigne(pcLigne);
    LEXCoupeLigne(pcLigne, pcPrecedent, pcSuivant, (char*)"=");
    if (LEXestEgal(pcPrecedent, pcCLEXopie)) {
        strcpy(pcValeur, pcSuivant);
    }
    else {
        strcpy(pcValeur, pcPrecedent);
        char pcMessage[TAILLE_MAX_LIGNE] = "La cle specifie n'a pas ete trouve dans le fichier : ";
        throw CException(CLE_INTROUVABLE, strcat(pcMessage, pcCle));
    }

}

/* ********************************************************
*                Lire la ligne suivante                   *
***********************************************************
* Entrée: char pcLigne									  *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: retourne la ligne suivante dans pcLigne       *
********************************************************* */
char* CLexeur::LEXLireLigne(char pcLigne[])
{
    IFSLEXFichier.getline(pcLigne, TAILLE_MAX_LIGNE);
    LEXsuppChar(pcLigne, '\r');
    return pcLigne;
}

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
void CLexeur::LEXsuppChar(char pcChaine[], char cChar) {
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

/* ********************************************************
*          Transforme les majuscules en minuscule         *
***********************************************************
* Entrée: char pcChaine[]                                 *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: Passe toutes les majuscules de pcChaine en    *
*           minuscule                                     *
********************************************************* */
void CLexeur::LEXenMinuscule(char pcChaine[]) {
    unsigned int uiBoucle = 0;
    while (pcChaine[uiBoucle] != '\0') {
        pcChaine[uiBoucle] = tolower(pcChaine[uiBoucle]);
        uiBoucle++;
    }
    return;
}

/* ********************************************************
*         Verifie si les deux chaines sont égales         *
***********************************************************
* Entrée: const char pcChaine1[]                          *
*         const char pcChaine2[]                          *
* Nécessite: -                                            *
* Sortie: bool                                            *
* Entraine: Retourne vrai si les 2 chaines sont           *
*            identiques                                   *
********************************************************* */
bool CLexeur::LEXestEgal(const char pcChaine1[], const char pcChaine2[]) {
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

/* ********************************************************
*           Verifie si la chaine est un nombre            *
***********************************************************
* Entrée: const char pcChaine[]                           *
* Nécessite: -                                            *
* Sortie: bool                                            *
* Entraine: Retourne vrai si la chaines est un nombre     *
********************************************************* */
bool CLexeur::LEXestUnNombre(const char pcChaine[])
{
    if (pcChaine[0] < 48 || pcChaine[0] > 57) {
        return false;
    }
    return true;
}
