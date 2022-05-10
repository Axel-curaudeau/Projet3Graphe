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
         *                 Constructeur par defaut                 *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé               *
         ********************************************************* */
        CArc();

        CArc(unsigned int uiDestination);


    /* =-=-=-=-=-= La suite dans le prochain épisode =-=-=-=-=-= */
};

#endif // CARC_H