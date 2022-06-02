#ifndef CGraphe_H
#define CGraphe_H

#include "CException.h"
#include "CSommet.h"

/* ===== ERROR CODES ===== */
#define NUMERO_SOMMMET_INDISPONIBLE 30
#define NUMERO_SOMMMET_INEXISTANT 31
#define DEPASSEMEMENT_INDEX 32

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
         *           ppSOMGRPTabSommet est initialisé à NULL.       *
         * ******************************************************* */
        CGraphe();

        /* *********************************************************
         *                 Constructeur de recopie                 *
         ***********************************************************
         * Entrée: CGraphe & GRPGraph                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé avec une      *
         *           recopie de GRPGraph.                          *
         ********************************************************* */
        CGraphe(const CGraphe & GRPGraph);

        /* *********************************************************
         *                       Destructeur                       *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est supprimé.                *
         ********************************************************* */
        ~CGraphe();

        /* *********************************************************
         *                 Lire le nombre de sommets               *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: unsigned int uiNbSommet                         *
         * Entraine: retourne le nombre de sommet contenus dans    *
         *           l'objet en cours.                             *
         ********************************************************* */
        unsigned int GRPLireNbSommet();

        /* *********************************************************
         *               Obtenir le sommet à l'index               *
         ***********************************************************
         * Entrée: unsigned int uiIndex                            *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: retourne l'objet sommet à l'index uiIndex     *
         *           dans la liste des sommets                     *
         ********************************************************* */
        CSommet & GRPIndexSommet(unsigned int uiIndex);

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
         *                      ObtenirSommet                      *
         ***********************************************************
         * Entrée: unsigned int uiNumero                           *
         * Nécessite: -                                            *
         * Sortie: CSommet                                         *
         * Entraine: Retourne le sommet dont le numéro est égal à  *
         *           uiNumero.                                     *
         *           Si le sommet n'existe pas, null est retourné. *
         ********************************************************* */
        CSommet& GRPObtenirSommet(unsigned int uiNumero);

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
         *                        ArcExiste                        *
         ***********************************************************
         * Entrée: unsigned int uiOrigine                          *
         *         unsigned int uiDestination                      *
         * Nécessite: -                                            *
         * Sortie: bool                                            *
         * Entraine: Retourne true si l'arc existe, false sinon.   *
         * ******************************************************* */
        bool GRPArcExiste(unsigned int uiOrigine, unsigned int uiDestination);

        /* *********************************************************
         *                     SommetExiste                        *
         ***********************************************************
         * Entrée: unsigned int uiNumero                           *
         * Nécessite: -                                            *
         * Sortie: bool                                            *
         * Entraine: Retourne true si le sommet existe,            *
         *            false sinon.                                 *
         * ******************************************************* */
        bool GRPSommetExiste(unsigned int uiNumero);

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
         * Entraine: affiche un lien permetant de visualiser le    *
         *           graphe.                                       *
         * ******************************************************* */
        void GRPGenererGraphviz();

        bool GRPEstOriente();
};

#endif // CGraphe_H