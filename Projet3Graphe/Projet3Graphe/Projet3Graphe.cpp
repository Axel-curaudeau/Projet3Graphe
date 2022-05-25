
#include <iostream>
#include "CArc.h"
#include "CParseur.h"
#include "CAnalyseur.h"
#include "CSommet.h"
#include "CGraphe.h"
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    CSommet som(1);
    som.SOMAjouterArcSortant(2);
    som.SOMAjouterArcSortant(3);
    som.SOMAjouterArcSortant(4);
    som.SOMSupprimerArcSortant(3);
    som.SOMAfficher();
    /*
    CGraphe graphe;
    graphe.GRPAjouterSommet(1);
    graphe.GRPAjouterSommet(2);
    graphe.GRPAjouterSommet(3);
    graphe.GRPAjouterSommet(4);
    graphe.GRPAjouterSommet(5);
    graphe.GRPAjouterSommet(6);
    graphe.GRPAjouterSommet(7);
    graphe.GRPAjouterSommet(8);
    graphe.GRPAjouterArc(1, 2);
    graphe.GRPAjouterArc(1, 3);
    graphe.GRPAjouterArc(1, 4);
    graphe.GRPAjouterArc(2, 5);
    graphe.GRPAjouterArc(2, 6);
    graphe.GRPAjouterArc(3, 7);
    graphe.GRPAjouterArc(3, 8);
    graphe.GRPAjouterArc(4, 8);
    graphe.GRPAjouterArc(5, 8);
    graphe.GRPAjouterArc(6, 8);
    graphe.GRPAjouterSommet(9);
    graphe.GRPAjouterSommet(10);
    graphe.GRPAjouterSommet(11);
    graphe.GRPAjouterArc(10, 11);

    graphe.GRPGenererGraphviz();*/
    return 0;
}
