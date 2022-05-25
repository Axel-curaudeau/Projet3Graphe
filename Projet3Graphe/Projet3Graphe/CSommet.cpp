#include "CSommet.h"
#include "CException.h"

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
        if (ppARCSOMEntrant == NULL) {
            throw CException(MALLOC_ECHOUE, "Allocation de la mémoire a échoué !");
        }
    } else {
        ppARCSOMEntrant = NULL;
    }

    if (SOMLireNbArcSortant() > 0) {
        ppARCSOMSortant = (CArc**) malloc(uiSOMNbArcSortant * sizeof (CArc*));
        if (ppARCSOMSortant == NULL) {
            throw CException(MALLOC_ECHOUE, "Allocation de la mémoire a échoué !");
        }
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
 * Sortie: unsigned int                                    *
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
 * Sortie: unsigned int                                    *
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
 * Sortie: unsigned int                                    *
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

    // Si l'arc existe déjà, on lève une exception
    if (SOMArcEntrantExiste(ARCArcEntrant.ARCLireDest())) {
        throw CException(ARC_DEJA_EXISTANT, "Cet arc existe déjà");
    }

    // Sinon, on l'ajoute
    uiSOMNbArcEntrant++;
    ppARCSOMEntrant = (CArc **) realloc(ppARCSOMEntrant, uiSOMNbArcEntrant * sizeof(CArc*));
    if (ppARCSOMEntrant == NULL) {
        throw CException(MALLOC_ECHOUE, "Allocation de la mémoire a échoué !");
    }
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

    // Si l'arc existe déjà, on lève une exception
    if (SOMArcSortantExiste(ARCArcSortant.ARCLireDest())) {
        throw CException(ARC_DEJA_EXISTANT, "Cet arc existe déjà");
    }

    //Sinon, on l'ajoute
    uiSOMNbArcSortant++;
    ppARCSOMSortant = (CArc **) realloc(ppARCSOMSortant, uiSOMNbArcSortant * sizeof(CArc*));
    if (ppARCSOMSortant == NULL) {
        throw CException(MALLOC_ECHOUE, "Allocation de la mémoire a échoué !");
    }
    ppARCSOMSortant[uiSOMNbArcSortant - 1] = new CArc(ARCArcSortant);
}

/* *********************************************************
 *                     LireArcEntrant                      *
 ***********************************************************
 * Entrée: unsigned int uiIndex                            *
 * Nécessite: -                                            *
 * Sortie: CArc                                            *
 * Entraine: L'arc d'index uiIndex dans la liste des arcs  *
 *           entrants est retourné.                        *
 ********************************************************* */
CArc CSommet::SOMLireArcEntrant(unsigned int uiIndex) {
    return *ppARCSOMEntrant[uiIndex];
}

/* *********************************************************
 *                     LireArcSortant                      *
 ***********************************************************
 * Entrée: unsigned int uiIndex                            *
 * Nécessite: -                                            *
 * Sortie: CArc                                            *
 * Entraine: L'arc d'index uiIndex dans la liste des arcs  *
 *           sortants est retourné.                        *
 ********************************************************* */
CArc CSommet::SOMLireArcSortant(unsigned int uiIndex) {
    return *ppARCSOMSortant[uiIndex];
}

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
bool CSommet::SOMArcEntrantExiste(unsigned int uiDestination) {
    unsigned int uiBoucle;

    for (uiBoucle = 0; uiBoucle < uiSOMNbArcEntrant; uiBoucle++) {
        if (ppARCSOMEntrant[uiBoucle]->ARCLireDest() == uiDestination) {
            return true;
        }
    }
    return false;
}

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
bool CSommet::SOMArcSortantExiste(unsigned int uiDestination) {
    unsigned int uiBoucle;

    for (uiBoucle = 0; uiBoucle < uiSOMNbArcSortant; uiBoucle++) {
        if (ppARCSOMSortant[uiBoucle]->ARCLireDest() == uiDestination) {
            return true;
        }
    }
    return false;
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

/* *********************************************************
 *                  Surcharge opérateur =                  *
 ***********************************************************
 * Entrée: CSommet SOMSommet                               *
 * Nécessite: -                                            *
 * Sortie: CSommet                                         *
 * Entraine: L'objet en cours est initialisé avec une      *
 *           copie de SOMSommet.                           *
 ********************************************************* */
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
            if (ppARCSOMEntrant == NULL) {
                throw CException(MALLOC_ECHOUE, "Allocation de la mémoire a échoué !");
            }
        }

        if (SOMLireNbArcSortant() > 0) {
            ppARCSOMSortant = (CArc**) malloc(SOMLireNbArcSortant() * sizeof (CArc*));
            if (ppARCSOMSortant == NULL) {
                throw CException(MALLOC_ECHOUE, "Allocation de la mémoire a échoué !");
            }
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