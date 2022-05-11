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
 *                 Getter uiARCDestination                 *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: unsigned int uiARCDestination                   *
 * Entraine: La valeur de uiARCDestination est initialisée *
 *           avec celle de uiDestination.                  *
 ********************************************************* */
unsigned int CArc::ARCGetDest() {
    return uiARCDestination;
}