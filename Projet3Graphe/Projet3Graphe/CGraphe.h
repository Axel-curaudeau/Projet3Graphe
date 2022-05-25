#ifndef CGraphe_H
#define CGraphe_H

#include "CException.h"
#include "CSommet.h"

/* ===== ERROR CODES ===== */
#define NUMERO_SOMMMET_INDISPONIBLE 1
#define NUMERO_SOMMMET_INEXISTANT 2

/*
 * Classe CGraphe
 *
 * Cette class est utilisée pour gérer les graphes.
 */
class CGraphe
{
    private :
        unsigned int uiGRPNbSommet;
        CSommet* pSOMGRPTabSommet;

    public :
        /* *********************************************************
         *                 Constructeur par defaut                 *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé,              *
         *           pSOMGRPTabSommet est initialisé à NULL.       *
         * ******************************************************* */
        CGraphe();

        /* *********************************************************
         *               Constructeur par paramètre                *
         ***********************************************************
         * Entrée: unsigned int uiNbSommet                         *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé avec un       *
         *           nombre de sommets égal à uiNbSommet.          *
         ********************************************************* */
        CGraphe(unsigned int uiNbSommet);

        /* *********************************************************
         *                 Constructeur de recopie                 *
         ***********************************************************
         * Entrée: CGraphe & GRPGraph                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé avec une      *
         *           recopie de GRPGraph.                          *
         ********************************************************* */
        CGraphe(CGraphe & GRPGraph);

        /* *********************************************************
         *                       Destructeur                       *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours supprimé.                    *
         ********************************************************* */
        ~CGraphe();

        /* *********************************************************
         *                      AjouterSommet                      *
         ***********************************************************
         * Entrée: unsigned int uiNumero                           *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Un sommet est ajouté à la fin de la liste de  *
         *           sommets.                                      *
         *           Si le sommet existe déjà, une exception       *
         *           (NUMERO_SOMMMET_INDISPONIBLE) est levée.      *
         ********************************************************* */
        void GRPAjouterSommet(unsigned int uiNumero);

        /* *********************************************************
         *                     ModifierSommet                      *
         ***********************************************************
         * Entrée: unsigned int uiAncienNumero                     *
         *         unsigned int uiNouveauNumero                    *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Le sommet avec le numéro uiAncienNumero est   *
         *           modifié avec le numéro uiNouveauNumero.       *
         *           Si "l'ancien" sommet n'existe pas, une        *
         *           exception (NUMERO_SOMMMET_INEXISTANT) est     *
         *           levée.                                        *
         *           Si le "nouveau" sommet existe déjà, une       *
         *           exception (NUMERO_SOMMMET_INDISPONIBLE) est   *
         *           levée.                                        *
         * ******************************************************* */
        void GRPModifierSommet(unsigned int uiAncienNumero, unsigned int uiNouveauNumero);

        /* *********************************************************
         *                      SupprimerSommet                    *
         ***********************************************************
         * Entrée: unsigned int uiNumero                           *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Un sommet est supprimé de la liste de sommets.*
         *           Si le sommet n'existe pas, une exception      *
         *           (NUMERO_SOMMMET_INEXISTANT) est levée.        *
         ********************************************************* */
        void GRPSupprimerSommet(unsigned int uiNumero);

        /* *********************************************************
         *                      AjouterArc                         *
         ***********************************************************
         * Entrée: unsigned int uiOrigine                          *
         *         unsigned int uiDestination                      *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Un arc est ajouté du sommet uiOrigine à       *
         *           uiDestination                                 *
         *           Si un des 2 sommet n'existe pas, une          *
         *           exception (NUMERO_SOMMMET_INEXISTANT) est     *
         *           levée.                                        *
         *           Si l'arc existe déjà, une exception           *
         *           (ARC_DEJA_EXISTANT) est levée.                *
         ********************************************************* */
        void GRPAjouterArc(unsigned int uiOrigine, unsigned int uiDestination);

        /* *********************************************************
         *                      SupprimerArc                       *
         ***********************************************************
         * Entrée: unsigned int uiOrigine                          *
         *         unsigned int uiDestination                      *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Un arc est supprimé du sommet uiOrigine à     *
         *           uiDestination.                                *
         *           Si un des 2 sommets n'existe pas, une         *
         *           exception (NUMERO_SOMMMET_INEXISTANT) est     *
         *           levée.                                        *
         *           Si l'arc n'existe pas, une exception          *
         *           (ARC_INEXISTANT) est levée.                   *
         ********************************************************* */
        void GRPSupprimerArc(unsigned int uiOrigine, unsigned int uiDestination);

        /* *********************************************************
         *                      SommetExiste                       *
         ***********************************************************
         * Entrée: unsigned int uiNumero                           *
         * Nécessite: -                                            *
         * Sortie: bool                                            *
         * Entraine: Retourne true si le sommet avec le numéro     *
         *           uiNumero existe, false sinon.                 *
         * ******************************************************* */
        CSommet & GRPObtenirSommet(unsigned int uiNumero); // Mettre privé

        /* *********************************************************
         *                        ArcExiste                        *
         ***********************************************************
         * Entrée: unsigned int uiOrigine                          *
         *         unsigned int uiDestination                      *
         * Nécessite: -                                            *
         * Sortie: bool                                            *
         * Entraine: Retourne true si l'arc existe, false sinon.    *
         * ******************************************************* */
        bool GRPArcExiste(unsigned int uiOrigine, unsigned int uiDestination);

        /* *********************************************************
         *                      Affichage                          *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est affiché.                 *
         * ******************************************************* */
        void GRPAfficher();

        /* *********************************************************
         *                      Generer graphviz                   *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est généré en .dot           *
         * ******************************************************* */
        void GRPGenererGraphviz();

        /* *********************************************************
         *                      Inverser                           *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Les arcs sont inversés.                       *
         * ******************************************************* */
        void GRPInverser();

        bool GRPSommetExiste(unsigned int uiNumero);
};

#endif // CGraphe_H