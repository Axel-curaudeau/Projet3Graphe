#include "CGraphe.h"

/* *********************************************************
 *                 Constructeur par defaut                 *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est initialisé,              *
 *           pSOMGRPTabSommet est initialisé à NULL.       *
 * ******************************************************* */
CGraphe::CGraphe() {
    uiGRPNbSommet = 0;
    pSOMGRPTabSommet = NULL;
}

/* *********************************************************
 *               Constructeur par paramètre                *
 ***********************************************************
 * Entrée: unsigned int uiNbSommet                         *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est initialisé avec un       *
 *           nombre de sommets égal à uiNbSommet.          *
 ********************************************************* */
CGraphe::CGraphe(unsigned int uiNbSommet) {
    uiGRPNbSommet = uiNbSommet;
    pSOMGRPTabSommet = (CSommet *) malloc(uiNbSommet * sizeof (CSommet));
}

/* *********************************************************
 *                 Constructeur de recopie                 *
 ***********************************************************
 * Entrée: CGraphe & GRPGraph                               *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est initialisé avec une      *
 *           recopie de GRPGraph.                          *
 ********************************************************* */
CGraphe::CGraphe(CGraphe & GRPGraph) {
    unsigned int uiBoucle;
    uiGRPNbSommet = GRPGraph.uiGRPNbSommet;

    // Allocation de la mémoire
    pSOMGRPTabSommet = (CSommet *) malloc(uiGRPNbSommet * sizeof (CSommet));

    // Copie des sommets
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        pSOMGRPTabSommet[uiBoucle] = GRPGraph.pSOMGRPTabSommet[uiBoucle];
    }
}

/* *********************************************************
 *                       Destructeur                       *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours supprimé.                    *
 ********************************************************* */
CGraphe::~CGraphe() {
    free(pSOMGRPTabSommet);
}

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
void CGraphe::GRPAjouterSommet(unsigned int uiNumero) {
    unsigned int uiBoucle;

    if (GRPSommetExiste(uiNumero)) { // Si le sommet existe déjà
        throw NUMERO_SOMMMET_INDISPONIBLE;
    }

    // Ajout du sommet
    uiGRPNbSommet++;
    pSOMGRPTabSommet = (CSommet *) realloc(pSOMGRPTabSommet, uiGRPNbSommet * sizeof (CSommet));
    pSOMGRPTabSommet[uiGRPNbSommet - 1] = CSommet(uiNumero);
}

/* *********************************************************
 *                      ObtenirSommet                      *
 ***********************************************************
 * Entrée: unsigned int uiNumero                           *
 * Nécessite: -                                            *
 * Sortie: CSommet                                         *
 * Entraine: Retourne le sommet dont le numéro est égal à  *
 *           uiNumero.
 *           Si le sommet n'existe pas, null est retourné. *
 ********************************************************* */
CSommet & CGraphe::GRPObtenirSommet(unsigned int uiNumero) {
    unsigned int uiBoucle;

    // Parcours de la liste de sommets
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        // Si le sommet est trouvé
        if (pSOMGRPTabSommet[uiBoucle].SOMLireNumero() == uiNumero) {
            return pSOMGRPTabSommet[uiBoucle];
        }
    }

    // Si le sommet n'existe pas
    throw CException(NUMERO_SOMMMET_INDISPONIBLE,(char *) "Ce sommet n'existe pas");
}

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
void CGraphe::GRPAjouterArc(unsigned int uiOrigine, unsigned int uiDestination) {
    unsigned int uiBoucle;

    // Si un des 2 sommets n'existe pas
    if (!GRPSommetExiste(uiOrigine)) {
        throw CException(NUMERO_SOMMMET_INEXISTANT,(char *) "Le somment d'origine n'existe pas");
    } else if (!GRPSommetExiste(uiDestination)) {
        throw CException(NUMERO_SOMMMET_INEXISTANT,(char *) "Le somment de destination n'existe pas");
    }

    // Si l'arc existe déjà
    if (GRPObtenirSommet(uiOrigine).SOMArcSortantExiste(uiDestination)) {
        throw CException(ARC_DEJA_EXISTANT,(char *) "Cet arc existe déjà");
    }

    // Ajout de l'arc
    GRPObtenirSommet(uiOrigine).SOMAjouterArcSortant(uiDestination);
    GRPObtenirSommet(uiDestination).SOMAjouterArcEntrant(uiOrigine);
}

/***********************************************************/
bool CGraphe::GRPSommetExiste(unsigned int uiNumero) {
    unsigned int uiBoucle;

    // Parcours de la liste de sommets
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        // Si le sommet est trouvé
        if (pSOMGRPTabSommet[uiBoucle].SOMLireNumero() == uiNumero) {
            return true;
        }
    }

    return false;
}