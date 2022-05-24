#include "CSommet.h"

using namespace std;

/* *********************************************************
 *                 Constructeur par defaut                 *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est initialisé avec le       *
 *           numéro -1 (valeur impossible).                *
 ********************************************************* */
CSommet::CSommet() {
    // Initialisation des attributs
    iSOMNumero = -1;
    uiSOMNbArcEntrant = 0;
    uiSOMNbArcSortant = 0;
    ppARCSOMEntrant = NULL;
    ppARCSOMSortant = NULL;
}

/* *********************************************************
 *               Constructeur par paramètre                *
 ***********************************************************
 * Entrée: unsigned int uiNumero                           *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est initialisé la valeur de  *
 *           uiNumero.                                     *
 ********************************************************* */
CSommet::CSommet(unsigned int uiNumero) {
    // Initialisation des attributs
    iSOMNumero = uiNumero;
    if (iSOMNumero < -1) { // Dépassement unsigned int (LEVER UNE EXCEPTION ?)
        iSOMNumero = -1;
    }
    uiSOMNbArcEntrant = 0;
    uiSOMNbArcSortant = 0;
    ppARCSOMEntrant = NULL;
    ppARCSOMSortant = NULL;
}

/* *********************************************************
 *                 Constructeur de recopie                 *
 ***********************************************************
 * Entrée: CSommet & SOMSommet                             *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est initialisé avec une      *
 *           recopie de SOMSommet.                         *
 ********************************************************* */
CSommet::CSommet(CSommet & SOMSommet) {
    // Déclaration des variables
    unsigned int uiBoucle;

    // Initialisation des attributs
    iSOMNumero = SOMSommet.iSOMNumero;
    uiSOMNbArcEntrant = SOMSommet.uiSOMNbArcEntrant;
    uiSOMNbArcSortant = SOMSommet.uiSOMNbArcSortant;

    // Allocation de la mémoire
    ppARCSOMEntrant = (CArc**) malloc(uiSOMNbArcEntrant * sizeof (CArc*));
    ppARCSOMSortant = (CArc**) malloc(uiSOMNbArcSortant * sizeof (CArc*));

    // Recopie des arcs
    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-= A VERIFIER =-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    if (uiSOMNbArcEntrant == 0) {
        ppARCSOMEntrant = NULL;
    }
    for (uiBoucle = 0; uiBoucle < uiSOMNbArcEntrant; uiBoucle++) {
        ppARCSOMEntrant[uiBoucle] = new CArc(*SOMSommet.ppARCSOMEntrant[uiBoucle]);
    }
    if (uiSOMNbArcSortant == 0) {
        ppARCSOMSortant = NULL;
    }
    for (uiBoucle = 0; uiBoucle < uiSOMNbArcSortant; uiBoucle++) {
        ppARCSOMSortant[uiBoucle] = new CArc(*SOMSommet.ppARCSOMSortant[uiBoucle]);
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
CSommet::~CSommet() {
    // Déclaration des variables
    unsigned int uiBoucle;

    // Libération de la mémoire
    // =-=-=-=-=-=-=-=-=-=-=-=-=-=-= A VERIFIER =-=-=-=-=-=-=-=-=-=-=-=-=-=-=
    for (uiBoucle = 0; uiBoucle < uiSOMNbArcEntrant; uiBoucle++) {
        delete ppARCSOMEntrant[uiBoucle];
    }
    for (uiBoucle = 0; uiBoucle < uiSOMNbArcSortant; uiBoucle++) {
        delete ppARCSOMSortant[uiBoucle];
    }
    free(ppARCSOMEntrant);
    free(ppARCSOMSortant);
}

/* *********************************************************
 *             Accesseur iSOMNumero (lecture)             *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: unsigned int iSOMNumero                        *
 * Entraine: La valeur de iSOMNumero est retournée.       *
 ********************************************************* */
unsigned int CSommet::SOMLireNumero() {
    return iSOMNumero;
}

/* *********************************************************
 *            Accesseur iSOMNumero (ecriture)             *
 ***********************************************************
 * Entrée: unsigned int iNumero                           *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: La valeur de iSOMNumero est modifiée.        *
 ********************************************************* */
void CSommet::SOMModifierNumero(unsigned int uiNumero) {
    iSOMNumero = uiNumero;
}

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
unsigned int CSommet::SOMLireNbArcEntrant() {
    return uiSOMNbArcEntrant;
}

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
unsigned int CSommet::SOMLireNbArcSortant() {
    return uiSOMNbArcSortant;
}

/* *********************************************************
 *                    AjouterArcEntrant                    *
 ***********************************************************
 * Entrée: CArc & ARCArcEntrant                            *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: Ajoute un arc entrant à l'objet en cours.     *
 ********************************************************* */
void CSommet::SOMAjouterArcEntrant(CArc ARCArcEntrant) {
    uiSOMNbArcEntrant++;
    ppARCSOMEntrant = (CArc **) realloc(ppARCSOMEntrant, uiSOMNbArcEntrant * sizeof(CArc*));
    ppARCSOMEntrant[uiSOMNbArcEntrant - 1] = new CArc(ARCArcEntrant);
}

/* *********************************************************
 *                    AjouterArcSortant                    *
 ***********************************************************
 * Entrée: CArc & ARCArcSortant                            *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: Ajoute un arc sortant à l'objet en cours.     *
 ********************************************************* */
void CSommet::SOMAjouterArcSortant(CArc ARCArcSortant) {
    uiSOMNbArcSortant++;
    ppARCSOMSortant = (CArc **) realloc(ppARCSOMSortant, uiSOMNbArcSortant * sizeof(CArc*));
    ppARCSOMSortant[uiSOMNbArcSortant - 1] = new CArc(ARCArcSortant);
}

/* *********************************************************
 *                        Affichage                        *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: Affiche les informations de l'objet en cours. *
 ********************************************************* */
void CSommet::SOMAfficher() {
    unsigned int uiBoucle;

    cout << "Sommet " << iSOMNumero << " : " << endl;

    cout << "   Nombre d'arcs entrants : " << uiSOMNbArcEntrant << endl;
    cout << "   Liste des arcs entrants (destination) : [";
    if (uiSOMNbArcEntrant > 0) {
        for (uiBoucle = 0; uiBoucle < uiSOMNbArcEntrant - 1; uiBoucle++) {
            cout << ppARCSOMEntrant[uiBoucle]->ARCLireDest() << ", ";
        }
        cout << ppARCSOMEntrant[uiBoucle]->ARCLireDest() << "]" << endl;
    } else {
        cout << "]" << endl;
    }

    cout << "   Nombre d'arcs sortants : " << uiSOMNbArcSortant << endl;
    cout << "   Liste des arcs sortants (destination) : [";
    if (uiSOMNbArcSortant > 0) {
        for (uiBoucle = 0; uiBoucle < uiSOMNbArcSortant - 1; uiBoucle++) {
            cout << ppARCSOMSortant[uiBoucle]->ARCLireDest() << ", ";
        }
        cout << ppARCSOMSortant[uiBoucle]->ARCLireDest() << "]" << endl;
    } else {
        cout << "]" << endl;
    }
}

/* *********************************************************
 *                 Accesseur ppARCSOMEntrant               *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: CArc** ppARCSOMEntrant                          *
 * Entraine: La liste des arcs entrant de l'objet en cours *
 *           est retournée.                                *
 ********************************************************* */
const CArc* const* CSommet::SOMLireListeArcEntrant() {
    return ppARCSOMEntrant;
}

/* *********************************************************
 *                 Accesseur ppARCSOMSortant               *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: CArc** ppARCSOMSortant                          *
 * Entraine: La liste des arcs sortant de l'objet en cours *
 *           est retournée.                                *
 ********************************************************* */
const CArc* const* CSommet::SOMLireListeArcSortant() {
    return ppARCSOMSortant;
}

/***********************************************************/
bool CSommet::SOMArcEntrantExiste(unsigned int uiDestination) {
    unsigned int uiBoucle;

    for (uiBoucle = 0; uiBoucle < uiSOMNbArcEntrant; uiBoucle++) {
        if (ppARCSOMEntrant[uiBoucle]->ARCLireDest() == uiDestination) {
            return true;
        }
    }
    return false;
}

bool CSommet::SOMArcSortantExiste(unsigned int uiDestination) {
    unsigned int uiBoucle;

    for (uiBoucle = 0; uiBoucle < uiSOMNbArcSortant; uiBoucle++) {
        if (ppARCSOMSortant[uiBoucle]->ARCLireDest() == uiDestination) {
            return true;
        }
    }
    return false;
}

CArc CSommet::SOMLireArcEntrant(unsigned int uiIndex) {
    return *ppARCSOMEntrant[uiIndex];
}

CArc CSommet::SOMLireArcSortant(unsigned int uiIndex) {
    return *ppARCSOMSortant[uiIndex];
}

CSommet& CSommet::operator=(CSommet SOMSommet) {
    if (this != &SOMSommet) {
        //Déclaration des variables
        unsigned int uiBoucle;

        // Recopie des attributs
        iSOMNumero = SOMSommet.iSOMNumero;
        uiSOMNbArcEntrant = SOMSommet.uiSOMNbArcEntrant;
        uiSOMNbArcSortant = SOMSommet.uiSOMNbArcSortant;
        
        // Libération de la mémoire
        if (uiSOMNbArcEntrant == 0) {
            ppARCSOMEntrant = NULL;
        }
        for (uiBoucle = 0; uiBoucle < uiSOMNbArcEntrant; uiBoucle++) {
            delete ppARCSOMEntrant[uiBoucle];
        }
        if (uiSOMNbArcSortant == 0) {
            ppARCSOMSortant = NULL;
        }
        for (uiBoucle = 0; uiBoucle < uiSOMNbArcSortant; uiBoucle++) {
            delete ppARCSOMSortant[uiBoucle];
        }

        // Reallocation de la mémoire
        if (ppARCSOMEntrant != NULL) {
            free(ppARCSOMEntrant);
        }
        if (ppARCSOMSortant != NULL) {
            free(ppARCSOMSortant);
        }
        ppARCSOMEntrant = (CArc **) malloc(uiSOMNbArcEntrant * sizeof(CArc*));
        ppARCSOMSortant = (CArc **) malloc(uiSOMNbArcSortant * sizeof(CArc*));

        // Recopie des arcs
        // =-=-=-=-=-=-=-=-=-=-=-=-=-=-= A VERIFIER =-=-=-=-=-=-=-=-=-=-=-=-=-=-=
        for (uiBoucle = 0; uiBoucle < uiSOMNbArcEntrant; uiBoucle++) {
            ppARCSOMEntrant[uiBoucle] = new CArc(*SOMSommet.ppARCSOMEntrant[uiBoucle]);
        }
        for (uiBoucle = 0; uiBoucle < uiSOMNbArcSortant; uiBoucle++) {
            ppARCSOMSortant[uiBoucle] = new CArc(*SOMSommet.ppARCSOMSortant[uiBoucle]);
        }
    }
    return *this;
}