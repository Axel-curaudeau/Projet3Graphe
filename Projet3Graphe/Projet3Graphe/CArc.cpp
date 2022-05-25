#include "CArc.h"

/* *********************************************************
 *               Constructeur par paramètre                *
 ***********************************************************
 * Entrée: unsigned int uiDestination                      *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est initialisé la valeur de  *
 *           uiDestination.                                *
 ********************************************************* */
CArc::CArc(unsigned int uiDestination) {
    uiARCDestination = uiDestination;
}

/* *********************************************************
 *          Accesseur uiARCDestination (lecture)           *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: unsigned int                                    *
 * Entraine: La valeur de uiARCDestination est initialisée *
 *           avec celle de uiDestination.                  *
 ********************************************************* */
unsigned int CArc::ARCLireDest() {
    return uiARCDestination;
}