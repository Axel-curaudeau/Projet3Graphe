#include "CSommet.h"

using namespace std;

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
    uiSOMNumero = uiNumero;
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
    SOMModifierNumero(SOMSommet.SOMLireNumero());
    uiSOMNbArcEntrant = SOMSommet.SOMLireNbArcEntrant();
    uiSOMNbArcSortant = SOMSommet.SOMLireNbArcSortant();

    // Allocation de la mémoire
    if (SOMLireNbArcEntrant() > 0) {
        ppARCSOMEntrant = (CArc**) malloc(uiSOMNbArcEntrant * sizeof (CArc*));
    } else {
        ppARCSOMEntrant = NULL;
    }

    if (SOMLireNbArcSortant() > 0) {
        ppARCSOMSortant = (CArc**) malloc(uiSOMNbArcSortant * sizeof (CArc*));
    } else {
        ppARCSOMSortant = NULL;
    }

    // Recopie des arcs
    for (uiBoucle = 0; uiBoucle < uiSOMNbArcEntrant; uiBoucle++) {
        ppARCSOMEntrant[uiBoucle] = new CArc(SOMSommet.SOMLireArcEntrant(uiBoucle));
    }

    for (uiBoucle = 0; uiBoucle < uiSOMNbArcSortant; uiBoucle++) {
        ppARCSOMSortant[uiBoucle] = new CArc(SOMSommet.SOMLireArcSortant(uiBoucle));
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
    for (uiBoucle = 0; uiBoucle < SOMLireNbArcEntrant() ; uiBoucle++) {
        delete ppARCSOMEntrant[uiBoucle];
        ppARCSOMEntrant[uiBoucle] = NULL;
    }
    for (uiBoucle = 0; uiBoucle < SOMLireNbArcSortant() ; uiBoucle++) {
        delete ppARCSOMSortant[uiBoucle];
        ppARCSOMSortant[uiBoucle] = NULL;
    }
    free(ppARCSOMEntrant);
    ppARCSOMEntrant = NULL;
    free(ppARCSOMSortant);
    ppARCSOMSortant = NULL;
}

/* *********************************************************
 *             Accesseur uiSOMNumero (lecture)             *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: unsigned int uiSOMNumero                        *
 * Entraine: La valeur de uiSOMNumero est retournée.       *
 ********************************************************* */
unsigned int CSommet::SOMLireNumero() {
    return uiSOMNumero;
}

/* *********************************************************
 *            Accesseur uiSOMNumero (ecriture)             *
 ***********************************************************
 * Entrée: unsigned int iNumero                            *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: La valeur de uiSOMNumero est modifiée.        *
 ********************************************************* */
void CSommet::SOMModifierNumero(unsigned int uiNumero) {
    uiSOMNumero = uiNumero;
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

    cout << "Sommet " << uiSOMNumero << " : " << endl;

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

        // Libération de la mémoire
        for (uiBoucle = 0; uiBoucle < SOMLireNbArcEntrant() ; uiBoucle++) {
            delete ppARCSOMEntrant[uiBoucle];
            ppARCSOMEntrant[uiBoucle] = NULL;
        }
        for (uiBoucle = 0; uiBoucle < SOMLireNbArcSortant() ; uiBoucle++) {
            delete ppARCSOMSortant[uiBoucle];
            ppARCSOMSortant[uiBoucle] = NULL;
        }
        free(ppARCSOMEntrant);
        ppARCSOMEntrant = NULL;
        free(ppARCSOMSortant);
        ppARCSOMSortant = NULL;

        // Recopie des attributs
        SOMModifierNumero(SOMSommet.SOMLireNumero());
        uiSOMNbArcEntrant = SOMSommet.SOMLireNbArcEntrant();
        uiSOMNbArcSortant = SOMSommet.SOMLireNbArcSortant();

        // Allocation de la mémoire
        if (SOMLireNbArcEntrant() > 0) {
            ppARCSOMEntrant = (CArc**) malloc(SOMLireNbArcEntrant() * sizeof (CArc*));
        }

        if (SOMLireNbArcSortant() > 0) {
            ppARCSOMSortant = (CArc**) malloc(SOMLireNbArcSortant() * sizeof (CArc*));
        }

        // Recopie des arcs
        for (uiBoucle = 0; uiBoucle < SOMLireNbArcEntrant() ; uiBoucle++) {
            ppARCSOMEntrant[uiBoucle] = new CArc(SOMSommet.SOMLireArcEntrant(uiBoucle));
        }

        for (uiBoucle = 0; uiBoucle < SOMLireNbArcSortant() ; uiBoucle++) {
            ppARCSOMSortant[uiBoucle] = new CArc(SOMSommet.SOMLireArcSortant(uiBoucle));
        }
    }
    return *this;
}