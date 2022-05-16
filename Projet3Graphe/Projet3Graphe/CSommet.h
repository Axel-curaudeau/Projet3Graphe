#ifndef CSOMMET_H
#define CSOMMET_H

#include <iostream>
#include <stdlib.h>
#include "CArc.h"

using namespace std;

/* ===== ERROR CODES ===== */

/* 
 * Classe CSommet
 *
 * Cette class est utilisée pour gérer les sommets.
 */
class CSommet
{
    private :
        unsigned int uiSOMNumero;
        unsigned int uiSOMNbArcEntrant;
        unsigned int uiSOMNbArcSortant;
        CArc** ppARCSOMEntrant;
        CArc** ppARCSOMSortant;

    public :
        /* *********************************************************
         *            Constructeur par defaut SUPPRIMÉ             *
         ********************************************************* */
        CSommet() = delete;

        /* *********************************************************
         *               Constructeur par paramètre                *
         ***********************************************************
         * Entrée: unsigned int uiNumero                           *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé la valeur de  *
         *           uiNumero.                                     *
         ********************************************************* */
        CSommet(unsigned int uiNumero);

        /* *********************************************************
         *                 Constructeur de recopie                 *
         ***********************************************************
         * Entrée: CSommet & SOMSommet                             *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé avec une      *
         *           recopie de SOMSommet.                         *
         ********************************************************* */
        CSommet(CSommet & SOMSommet);

        /* *********************************************************
         *                       Destructeur                       *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours supprimé.                    *
         ********************************************************* */
        ~CSommet();

        /* *********************************************************
         *             Accesseur uiSOMNumero (lecture)             *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: unsigned int uiSOMNumero                        *
         * Entraine: La valeur de uiSOMNumero est retournée.       *
         ********************************************************* */
        unsigned int SOMLireNumero();
        
        /* *********************************************************
         *            Accesseur uiSOMNumero (ecriture)             *
         ***********************************************************
         * Entrée: unsigned int uiNumero                           *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: La valeur de uiSOMNumero est modifiée.        *
         ********************************************************* */
        void SOMModifierNumero(unsigned int uiNumero);

        /* *********************************************************
         *          Accesseur uiSOMNbArcEntrant (lecture)          *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: unsigned int uiSOMNbArcEntrant                  *
         * Entraine: La valeur de uiSOMNbArcEntrant est retournée. *
         *           Si uiSOMNbArcEntrant est égal à 0, la liste   *
         *           est vide.                                     *
         ********************************************************* */
        unsigned int SOMLireNbArcEntrant();

        /* *********************************************************
         *          Accesseur uiSOMNbArcSortant (lecture)          *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: unsigned int uiSOMNbArcSortant                  *
         * Entraine: La valeur de uiSOMNbArcSortant est retournée. *
         *          Si uiSOMNbArcSortant est égal à 0, la liste    *
         *         est vide.                                       *
         ********************************************************* */
        unsigned int SOMLireNbArcSortant();

        /* *********************************************************
         *                    AjouterArcEntrant                    *
         ***********************************************************
         * Entrée: CArc* pARCArcEntrant                            *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Ajoute un arc entrant à l'objet en cours.     *
         ********************************************************* */
        void SOMAjouterArcEntrant(CArc* pARCArc);

        /* *********************************************************
         *                    AjouterArcSortant                    *
         ***********************************************************
         * Entrée: CArc* pARCArcSortant                            *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Ajoute un arc sortant à l'objet en cours.     *
         ********************************************************* */
        void SOMAjouterArcSortant(CArc* pARCArc);

        /* *********************************************************
         *                        Affichage                        *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Affiche les informations de l'objet en cours. *
         ********************************************************* */
        void SOMAfficher();
    
};

#endif // CSOMMET_H