#include "CGraphe.h"

/* *********************************************************
 *                 Constructeur par defaut                 *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est initialisé,              *
 *           ppSOMGRPTabSommet est initialisé à NULL.       *
 * ******************************************************* */
CGraphe::CGraphe() {
    uiGRPNbSommet = 0;
    ppSOMGRPTabSommet = NULL;
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
    
    uiGRPNbSommet = GRPGraph.uiGRPNbSommet; // -=- Changer pour accesseur -=-

    // Allocation de la mémoire
    if (uiGRPNbSommet > 0) { // -=- Changer pour accesseur -=-
        ppSOMGRPTabSommet = (CSommet **) malloc(uiGRPNbSommet * sizeof (CSommet*));
        if (ppSOMGRPTabSommet == NULL) {
            throw CException(MALLOC_ECHOUE, (char *) "Allocation de la mémoire a échoué !");
        }
    } else {
        ppSOMGRPTabSommet = NULL;
    }

    // Copie des sommets
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        ppSOMGRPTabSommet[uiBoucle] = new CSommet(*(GRPGraph.ppSOMGRPTabSommet[uiBoucle])); // -=- Changer pour accesseur -=-
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
    // Déclaration des variables
    unsigned int uiBoucle;

    // Libération de la mémoire
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        delete ppSOMGRPTabSommet[uiBoucle];
        ppSOMGRPTabSommet[uiBoucle] = NULL;
    }
    free(ppSOMGRPTabSommet);
    ppSOMGRPTabSommet = NULL;
    // Appel GRPSupprimerSommet ?
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

    // Si le sommet existe déjà, on lève une exception
    if (GRPSommetExiste(uiNumero)) {
        throw NUMERO_SOMMMET_INDISPONIBLE;
    }

    // Sinon, on l'ajoute
    uiGRPNbSommet++;
    ppSOMGRPTabSommet = (CSommet **) realloc(ppSOMGRPTabSommet, uiGRPNbSommet * sizeof (CSommet*));
    if (ppSOMGRPTabSommet == NULL) {
        throw CException(MALLOC_ECHOUE, (char *) "Allocation de la mémoire a échoué !");
    }
    ppSOMGRPTabSommet[uiGRPNbSommet - 1] = new CSommet(uiNumero);
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
        if (ppSOMGRPTabSommet[uiBoucle]->SOMLireNumero() == uiNumero) {
            return *ppSOMGRPTabSommet[uiBoucle];
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
        if (ppSOMGRPTabSommet[uiBoucle]->SOMLireNumero() == uiNumero) {
            return true;
        }
    }

    return false;
}

/* *********************************************************
 *                      Generer graphviz                   *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est généré en .dot           *
 * ******************************************************* */
void CGraphe::GRPGenererGraphviz() {
    unsigned int uiBoucle;
    unsigned int uiBoucle1;

    cout << "https://dreampuf.github.io/GraphvizOnline/#digraph{";
    // Parcours de la liste de sommets
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        // Recopie du sommet
        CSommet SOMCourant = *ppSOMGRPTabSommet[uiBoucle];
        cout << SOMCourant.SOMLireNumero() << ";";
        // Parcours des arcs sortants
        for (uiBoucle1 = 0; uiBoucle1 < SOMCourant.SOMLireNbArcSortant(); uiBoucle1++) {
            cout << SOMCourant.SOMLireNumero() << "->" << SOMCourant.SOMLireArcSortant(uiBoucle1).ARCLireDest() << ";";
        }
    }
    cout << "}";
}