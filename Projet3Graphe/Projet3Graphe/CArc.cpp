#include "CArc.h"

/* ********************************************************
*               Constructeur par paramètre                *
***********************************************************
* Entrée: unsigned int uiDestination                      *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: L'objet en cours est initialisé avec la       *
*           valeur de  uiDestination.                     *
********************************************************* */
CArc::CArc(unsigned int uiDestination) {
    uiARCDestination = uiDestination;
}

/* ********************************************************
*                   Lire la destination                   *
***********************************************************
* Entrée: -                                               *
* Nécessite: -                                            *
* Sortie: unsigned int                                    *
* Entraine: Retourne la valeur de destination de l'arc    *
********************************************************* */
unsigned int CArc::ARCLireDest() {
    return uiARCDestination;
}