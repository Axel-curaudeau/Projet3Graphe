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
    uiSOMNumero = uiNumero;
    uiSOMNbArcEntrant = 0;
    uiSOMNbArcSortant = 0;
    ppARCSOMEntrant = (CArc **) malloc(sizeof(CArc*));
    ppARCSOMSortant = (CArc **) malloc(sizeof(CArc*));
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
    // TODO
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
    // TODO
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
 * Entrée: unsigned int uiNumero                           *
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
 * Entrée: CArc* pARCArcEntrant                            *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: Ajoute un arc entrant à l'objet en cours.     *
 ********************************************************* */
void CSommet::SOMAjouterArcEntrant(CArc* pARCArcEntrant) {
    uiSOMNbArcEntrant++;
    ppARCSOMEntrant = (CArc **) realloc(ppARCSOMEntrant, uiSOMNbArcEntrant * sizeof(CArc*));
    ppARCSOMEntrant[uiSOMNbArcEntrant - 1] = pARCArcEntrant;
}

/* *********************************************************
 *                    AjouterArcSortant                    *
 ***********************************************************
 * Entrée: CArc* pARCArcSortant                            *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: Ajoute un arc sortant à l'objet en cours.     *
 ********************************************************* */
void CSommet::SOMAjouterArcSortant(CArc* pARCArcEntrant) {
    uiSOMNbArcSortant++;
    ppARCSOMSortant = (CArc **) realloc(ppARCSOMSortant, uiSOMNbArcSortant * sizeof(CArc*));
    ppARCSOMSortant[uiSOMNbArcSortant - 1] = pARCArcEntrant;
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