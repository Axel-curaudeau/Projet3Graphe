#ifndef CSOMMET_H
#define CSOMMET_H

#include <iostream>
#include <stdlib.h>
#include "CArc.h"

using namespace std;

/* ===== ERROR CODES ===== */
#define ARC_DEJA_EXISTANT 10
#define ARC_INEXISTANT 11

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
         *           uiNumero, les pointeurs sont à NULL.          *
         ********************************************************* */
        CSommet(unsigned int uiNumero);

        /* *********************************************************
         *                 Constructeur de recopie                 *
         ***********************************************************
         * Entrée: CSommet & SOMSommet                             *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé avec une      *
         *           copie de SOMSommet.                           *
         ********************************************************* */
        CSommet(CSommet & SOMSommet);

        /* *********************************************************
         *                       Destructeur                       *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est supprimé.                *
         ********************************************************* */
        ~CSommet();

        /* *********************************************************
         *             Accesseur uiSOMNumero (lecture)             *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: unsigned int                                    *
         * Entraine: La numero du sommet est retourné.             *
         ********************************************************* */
        unsigned int SOMLireNumero();
        
        /* *********************************************************
         *            Accesseur uiSOMNumero (ecriture)             *
         ***********************************************************
         * Entrée: unsigned int uiNumero                           *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Le numero du sommet est modifié.              *
         ********************************************************* */
        void SOMModifierNumero(unsigned int uiNumero);

        /* *********************************************************
         *          Accesseur uiSOMNbArcEntrant (lecture)          *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: unsigned int                                    *
         * Entraine: Retourne le nombre d'arcs entrant du sommet.  *
         ********************************************************* */
        unsigned int SOMLireNbArcEntrant();

        /* *********************************************************
         *          Accesseur uiSOMNbArcSortant (lecture)          *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: unsigned int                                    *
         * Entraine: Retourne le nombre d'arcs sortant du sommet.  *
         ********************************************************* */
        unsigned int SOMLireNbArcSortant();

        /* *********************************************************
         *                    AjouterArcEntrant                    *
         ***********************************************************
         * Entrée: CArc & ARCArcEntrant                            *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Ajoute un arc entrant à l'objet en cours.     *
         *           Une copie de ARCArcEntrant est allouée.       *
         ********************************************************* */
        void SOMAjouterArcEntrant(CArc ARCArcEntrant);

        /* *********************************************************
         *                    AjouterArcSortant                    *
         ***********************************************************
         * Entrée: CArc* pARCArcSortant                            *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Ajoute un arc sortant à l'objet en cours.     *
         *           Une copie de pARCArcSortant est allouée.      *
         ********************************************************* */
        void SOMAjouterArcSortant(CArc ARCArcSortant);

        /* *********************************************************
         *                   SupprimerArcEntrant                   *
         ***********************************************************
         * Entrée: unsigned int uiNumero                           *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Supprime un arc entrant à l'objet en cours.   *
         ********************************************************* */
        void SOMSupprimerArcEntrant(unsigned int uiDestination);

        /* *********************************************************
         *                   SupprimerArcSortant                   *
         ***********************************************************
         * Entrée: unsigned int uiNumero                           *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Supprime un arc sortant à l'objet en cours.   *
         ********************************************************* */
        void SOMSupprimerArcSortant(unsigned int uiDestination);

        /* *********************************************************
         *                     LireArcEntrant                      *
         ***********************************************************
         * Entrée: unsigned int uiIndex                            *
         * Nécessite: -                                            *
         * Sortie: CArc                                            *
         * Entraine: L'arc d'index uiIndex dans la liste des arcs  *
         *           entrants est retourné.                        *
         ********************************************************* */
        CArc SOMLireArcEntrant(unsigned int uiIndex);

        /* *********************************************************
         *                     LireArcSortant                      *
         ***********************************************************
         * Entrée: unsigned int uiIndex                            *
         * Nécessite: -                                            *
         * Sortie: CArc                                            *
         * Entraine: L'arc d'index uiIndex dans la liste des arcs  *
         *           sortants est retourné.                        *
         ********************************************************* */
        CArc SOMLireArcSortant(unsigned int uiIndex);

        /* *********************************************************
         *                    ArcEntrantExiste                     *
         ***********************************************************
         * Entrée: unsigned int uiDestination                      *
         * Nécessite: -                                            *
         * Sortie: bool                                            *
         * Entraine: Retourne vrai si un arc entrant de            *
         *           destination uiDestination existe dans l'objet *
         *           en cours, faux sinon.                         *
         ********************************************************* */
        bool SOMArcEntrantExiste(unsigned int uiDestination);

        /* *********************************************************
         *                    ArcSortantExiste                     *
         ***********************************************************
         * Entrée: unsigned int uiDestination                      *
         * Nécessite: -                                            *
         * Sortie: bool                                            *
         * Entraine: Retourne vrai si un arc sortant de            *
         *           destination uiDestination existe dans l'objet *
         *           en cours, faux sinon.                         *
         ********************************************************* */
        bool SOMArcSortantExiste(unsigned int uiDestination);

        /* *********************************************************
         *                        Affichage                        *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Affiche les informations de l'objet en cours. *
         ********************************************************* */
        void SOMAfficher();

        /* *********************************************************
         *                  Surcharge opérateur =                  *
         ***********************************************************
         * Entrée: CSommet SOMSommet                               *
         * Nécessite: -                                            *
         * Sortie: CSommet                                         *
         * Entraine: L'objet en cours est initialisé avec une      *
         *           copie de SOMSommet.                           *
         ********************************************************* */
        CSommet& operator=(CSommet SOMSommet);

        void SOMInitialiser();

        void SOMInverserArcs();
};

#endif // CSOMMET_H