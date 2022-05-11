#ifndef CARC_H
#define CARC_H

/* ===== ERROR CODES ===== */

/*
 * Classe CArc
 *
 * Cette class est utilisée pour gérer les arcs.
 */
class CArc
{
    private :
        unsigned int uiARCDestination;

    public :

        /* *********************************************************
         *            Constructeur par defaut SUPPRIMÉ             *
         ********************************************************* */
        CArc() = delete;

        /* *********************************************************
         *               Constructeur par paramètre                *
         ***********************************************************
         * Entrée: unsigned int uiDestination                      *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé la valeur de  *
         *           uiDestination.                                *
         ********************************************************* */
        CArc(unsigned int uiDestination);

        /* *********************************************************
         *                 Getter uiARCDestination                 *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: unsigned int uiARCDestination                   *
         * Entraine: La valeur de uiARCDestination est initialisée *
         *           avec celle de uiDestination.                  *
         ********************************************************* */
        unsigned int ARCGetDest();
};

#endif // CARC_H