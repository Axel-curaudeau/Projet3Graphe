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
 *                 Constructeur de recopie                 *
 ***********************************************************
 * Entrée: CGraphe & GRPGraph                               *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: L'objet en cours est initialisé avec une      *
 *           recopie de GRPGraph.                          *
 ********************************************************* */
CGraphe::CGraphe(const CGraphe & GRPGraph) {
    unsigned int uiBoucle;
    
    uiGRPNbSommet = GRPGraph.uiGRPNbSommet;

    // Allocation de la mémoire
    if (uiGRPNbSommet > 0) { // -=- Changer pour accesseur -=-
        pSOMGRPTabSommet = (CSommet *) malloc(uiGRPNbSommet * sizeof (CSommet));
        if (pSOMGRPTabSommet == NULL) {
            throw CException(MALLOC_ECHOUE, (char *) "Allocation de la mémoire a échoué !");
        }
    } else {
        pSOMGRPTabSommet = NULL;
    }

    // Copie des sommets
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        CSommet* pSOMSommetTemporaire = new CSommet((GRPGraph.pSOMGRPTabSommet[uiBoucle]));
        pSOMGRPTabSommet[uiBoucle].SOMInitialiser();
        pSOMGRPTabSommet[uiBoucle] = *pSOMSommetTemporaire; 
        delete pSOMSommetTemporaire;
    }
}

/* ********************************************************
*                       Destructeur                       *
***********************************************************
* Entrée: -                                               *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: L'objet en cours est supprimé.                *
********************************************************* */
CGraphe::~CGraphe() {
    // Déclaration des variables
    unsigned int uiBoucle;

    // Libération de la mémoire
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        pSOMGRPTabSommet[uiBoucle].~CSommet();
    }
    free(pSOMGRPTabSommet);
    pSOMGRPTabSommet = NULL;
    // Appel GRPSupprimerSommet ?
}

/* ********************************************************
*                 Lire le nombre de sommets               *
***********************************************************
* Entrée: -                                               *
* Nécessite: -                                            *
* Sortie: unsigned int uiNbSommet                         *
* Entraine: retourne le nombre de sommet contenus dans    *
*           l'objet en cours.                             *
********************************************************* */
unsigned int CGraphe::GRPLireNbSommet()
{
    return uiGRPNbSommet;
}

/* *********************************************************
*               Obtenir le sommet à l'index               *
***********************************************************
* Entrée: unsigned int uiIndex                            *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: retourne l'objet sommet à l'index uiIndex     *
*           dans la liste des sommets                     *
********************************************************* */
CSommet & CGraphe::GRPIndexSommet(unsigned int uiIndex)
{
    if (uiIndex >= uiGRPNbSommet) {
        throw CException(DEPASSEMEMENT_INDEX, (char*)"Index saisie hors de la zone memoire");
    }
    return pSOMGRPTabSommet[uiIndex];
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
    pSOMGRPTabSommet = (CSommet *) realloc(pSOMGRPTabSommet, uiGRPNbSommet * sizeof (CSommet));
    if (pSOMGRPTabSommet == NULL) {
        throw CException(MALLOC_ECHOUE, (char *) "Allocation de la mémoire a échoué !");
    }
    pSOMGRPTabSommet[uiGRPNbSommet - 1].SOMInitialiser();
    CSommet* pSOMSommetTemporaire = new CSommet(uiNumero);
    pSOMGRPTabSommet[uiGRPNbSommet - 1] = *pSOMSommetTemporaire;
    delete pSOMSommetTemporaire;
}

/* ********************************************************
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
void CGraphe::GRPModifierSommet(unsigned int uiAncienNumero, unsigned int uiNouveauNumero)
{
    if (GRPSommetExiste(uiNouveauNumero)) {
        throw CException(NUMERO_SOMMMET_INDISPONIBLE, (char*)"Le numero de sommet saisie est indisponible !");
    }
    GRPObtenirSommet(uiAncienNumero).SOMModifierNumero(uiNouveauNumero);
}

/* ********************************************************
*                      SupprimerSommet                    *
***********************************************************
* Entrée: unsigned int uiNumero                           *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: Un sommet est supprimé de la liste de sommets.*
*           Si le sommet n'existe pas, une exception      *
*           (NUMERO_SOMMMET_INEXISTANT) est levée.        *
********************************************************* */
void CGraphe::GRPSupprimerSommet(unsigned int uiNumero)
{
    if (!GRPSommetExiste(uiNumero)) {   //Verification de l'existance du sommet à supprimer.
        throw CException(NUMERO_SOMMMET_INEXISTANT, (char*)"Ce sommet n'existe pas !");
    }

    unsigned int uiBoucle, uiBoucle2;
    CSommet* pSOMNouveauTabSommet = (CSommet*)malloc((uiGRPNbSommet - 1) * sizeof(CSommet));    //Allocation du futur tableau de sommet.
    if (pSOMNouveauTabSommet == NULL) {
        throw CException(MALLOC_ECHOUE, (char*)"Allocation de la mémoire a échoué !");
    }

    CSommet SOMTemp = GRPObtenirSommet(uiNumero);
    for (uiBoucle = 0; uiBoucle < SOMTemp.SOMLireNbArcSortant(); uiBoucle++) {  //supression des arcs entrant dans les sommmets de destination.
        unsigned int uiDestination = SOMTemp.SOMLireArcSortant(uiBoucle).ARCLireDest();
        GRPObtenirSommet(uiDestination).SOMSupprimerArcEntrant(uiNumero);
    }

    for (uiBoucle = 0; uiBoucle < SOMTemp.SOMLireNbArcEntrant(); uiBoucle++) {
        unsigned int uiDestination = SOMTemp.SOMLireArcEntrant(uiBoucle).ARCLireDest();
        GRPObtenirSommet(uiDestination).SOMSupprimerArcSortant(uiNumero);
    }
    
    uiBoucle2 = 0;
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        if (pSOMGRPTabSommet[uiBoucle].SOMLireNumero() != uiNumero) {   //Ajout de tout les sommet dans le nouveau tableau sauf celui à supprimer.
            pSOMNouveauTabSommet[uiBoucle2].SOMInitialiser();
            pSOMNouveauTabSommet[uiBoucle2] = pSOMGRPTabSommet[uiBoucle];
            uiBoucle2++;
        }
        pSOMGRPTabSommet[uiBoucle].~CSommet();  //Supprission des sommets dans l'ancien tableau.
    }

    uiGRPNbSommet--;
    free(pSOMGRPTabSommet);
    pSOMGRPTabSommet = pSOMNouveauTabSommet;
}

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
    throw CException(NUMERO_SOMMMET_INEXISTANT,(char *) "Ce sommet n'existe pas ! (GRPObtenirSommet)");
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

/* ********************************************************
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
void CGraphe::GRPSupprimerArc(unsigned int uiOrigine, unsigned int uiDestination)
{
    if (!GRPArcExiste(uiOrigine, uiDestination)) {
        throw CException(ARC_INEXISTANT, (char*)"L'arc précisé n'existe pas !");
    }
    GRPObtenirSommet(uiOrigine).SOMSupprimerArcSortant(uiDestination);
    GRPObtenirSommet(uiDestination).SOMSupprimerArcEntrant(uiOrigine);
}

/* ********************************************************
*                        ArcExiste                        *
***********************************************************
* Entrée: unsigned int uiOrigine                          *
*         unsigned int uiDestination                      *
* Nécessite: -                                            *
* Sortie: bool                                            *
* Entraine: Retourne true si l'arc existe, false sinon.   *
* ******************************************************* */
bool CGraphe::GRPArcExiste(unsigned int uiOrigine, unsigned int uiDestination)
{
    unsigned int uiBoucle;
    try {
        CSommet SOMOrigine = GRPObtenirSommet(uiOrigine);
        for (uiBoucle = 0; uiBoucle < SOMOrigine.SOMLireNbArcSortant(); uiBoucle++) {
            if (SOMOrigine.SOMLireArcSortant(uiBoucle).ARCLireDest() == uiDestination) {
                return true;
            }
        }
    }
    catch (CException EXCE) {
        if (EXCE.EXCLireCode() == NUMERO_SOMMMET_INEXISTANT) {
            return false;
        }
    }
    return false;
}

/* ********************************************************
*                     SommetExiste                        *
***********************************************************
* Entrée: unsigned int uiNumero                           *
* Nécessite: -                                            *
* Sortie: bool                                            *
* Entraine: Retourne true si le sommet existe,            *
*            false sinon.                                 *
* ******************************************************* */
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

/* ********************************************************
*                      Affichage                          *
***********************************************************
* Entrée: -                                               *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: L'objet en cours est affiché.                 *
* ******************************************************* */
void CGraphe::GRPAfficher()
{
    unsigned int uiBoucle;
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        pSOMGRPTabSommet[uiBoucle].SOMAfficher();
    }
}

/* *********************************************************
 *                      Generer graphviz                   *
 ***********************************************************
 * Entrée: -                                               *
 * Nécessite: -                                            *
 * Sortie: -                                               *
 * Entraine: affiche un lien permetant de visualiser le    *
 *           graphe.                                       *
 * ******************************************************* */
void CGraphe::GRPGenererGraphviz() {
    unsigned int uiBoucle;
    unsigned int uiBoucle1;

    cout << "https://dreampuf.github.io/GraphvizOnline/#digraph{";
    // Parcours de la liste de sommets
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        // Recopie du sommet
        CSommet SOMCourant = pSOMGRPTabSommet[uiBoucle];
        cout << SOMCourant.SOMLireNumero() << ";";
        // Parcours des arcs sortants
        for (uiBoucle1 = 0; uiBoucle1 < SOMCourant.SOMLireNbArcSortant(); uiBoucle1++) {
            cout << SOMCourant.SOMLireNumero() << "->" << SOMCourant.SOMLireArcSortant(uiBoucle1).ARCLireDest() << ";";
        }
    }
    cout << "}" << endl;
}

/* ********************************************************
*                       Est Orienté ?                     *
***********************************************************
* Entrée: -                                               *
* Nécessite: -                                            *
* Sortie: bool                                            *
* Entraine: retourne vrai si le graphe est orienté, faux  *
*           sinon.                                        *
* ******************************************************* */
bool CGraphe::GRPEstOriente()
{
    unsigned int uiBoucle;
    unsigned int uiBoucleArc;
    unsigned int uiDestination;
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        for (uiBoucleArc = 0; uiBoucleArc < pSOMGRPTabSommet[uiBoucle].SOMLireNbArcEntrant(); uiBoucleArc++) {
            uiDestination = pSOMGRPTabSommet[uiBoucle].SOMLireArcEntrant(uiBoucleArc).ARCLireDest();
            if (!pSOMGRPTabSommet[uiBoucle].SOMArcSortantExiste(uiDestination)) {
                return true;
            }
        }
    }
    return false;
}

/* ********************************************************
*                       Opérateur =                       *
***********************************************************
* Entrée: CGraphe GRPGraphe                               *
* Nécessite: -                                            *
* Sortie: -                                               *
* Entraine: Recopie l'objet CGraphe dans l'objet en       *
*           cours.                                        *
* ******************************************************* */
void CGraphe::operator=(CGraphe GRPGraphe)
{
    unsigned int uiBoucle;

    uiGRPNbSommet = GRPGraphe.uiGRPNbSommet;

    // Allocation de la mémoire
    if (uiGRPNbSommet > 0) { // -=- Changer pour accesseur -=-
        pSOMGRPTabSommet = (CSommet*)malloc(uiGRPNbSommet * sizeof(CSommet));
        if (pSOMGRPTabSommet == NULL) {
            throw CException(MALLOC_ECHOUE, (char*)"Allocation de la mémoire a échoué !");
        }
    }
    else {
        pSOMGRPTabSommet = NULL;
    }

    // Copie des sommets
    for (uiBoucle = 0; uiBoucle < uiGRPNbSommet; uiBoucle++) {
        CSommet* pSOMSommetTemporaire = new CSommet((GRPGraphe.pSOMGRPTabSommet[uiBoucle]));
        pSOMGRPTabSommet[uiBoucle].SOMInitialiser();
        pSOMGRPTabSommet[uiBoucle] = *pSOMSommetTemporaire;
        delete pSOMSommetTemporaire;
    }
}

