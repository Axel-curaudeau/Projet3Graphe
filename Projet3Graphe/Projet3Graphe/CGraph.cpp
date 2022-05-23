#include "CGraph.h"

/* *********************************************************
 *                 Constructeur par defaut                 *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est initialisé,              *
 *           pSOMGRPTabSommet est initialisé à NULL.       *
 * ******************************************************* */
CGraph::CGraph() {
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
CGraph::CGraph(unsigned int uiNbSommet) {
    uiGRPNbSommet = uiNbSommet;
    pSOMGRPTabSommet = new CSommet[uiGRPNbSommet];
}

/* *********************************************************
 *                 Constructeur de recopie                 *
 ***********************************************************
 * Entrée: CGraph & GRPGraph                               *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est initialisé avec une      *
 *           recopie de GRPGraph.                          *
 ********************************************************* */
CGraph::CGraph(CGraph & GRPGraph) {
    unsigned int uiBoucle;
    uiGRPNbSommet = GRPGraph.uiGRPNbSommet;

    // Allocation de la mémoire
    pSOMGRPTabSommet = new CSommet[uiGRPNbSommet];

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
CGraph::~CGraph() {
    delete[] pSOMGRPTabSommet;
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
void CGraph::GRPAjouterSommet(unsigned int uiNumero) {
    unsigned int uiBoucle;

    // Vérification de l'existence du sommet (Je trouve pas ca tres beau)
    try {
        GRPObtenirSommet(uiNumero);
        
        throw NUMERO_SOMMMET_INDISPONIBLE;  // Le sommet existe déjà

    } catch (CException EXCException) {
        if (EXCException.EXCLireCode() != NUMERO_SOMMMET_INDISPONIBLE) {
            throw EXCException;
        }
        // Le sommet n'existe pas
    } 


    // "ReaNew" Realloc + New
    uiGRPNbSommet++;
    CSommet * pSOMGRPTabSommetTemp = new CSommet[uiGRPNbSommet];
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet - 1; uiBoucle++) {
        pSOMGRPTabSommetTemp[uiBoucle] = pSOMGRPTabSommet[uiBoucle];
    }
    pSOMGRPTabSommetTemp[uiGRPNbSommet - 1] = CSommet(uiNumero);
    delete[] pSOMGRPTabSommet;
    pSOMGRPTabSommet = pSOMGRPTabSommetTemp;
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
CSommet & CGraph::GRPObtenirSommet(unsigned int uiNumero) {
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