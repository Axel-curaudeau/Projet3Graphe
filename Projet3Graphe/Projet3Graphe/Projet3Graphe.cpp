
#include <iostream>
#include "CArc.h"
#include "CParseur.h"
#include "CAnalyseur.h"
#include "CSommet.h"
#include "CGraphe.h"

using namespace std;

int main(int argc, char* argv[])
{
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
    graphe.GRPAjouterArc(1, 5);
    graphe.GRPAjouterArc(2, 6);
    graphe.GRPAjouterArc(3, 6);
    graphe.GRPAjouterArc(4, 6);
    graphe.GRPAjouterArc(3, 7);
    graphe.GRPAjouterArc(4, 7);
    graphe.GRPAjouterArc(5, 7);
    graphe.GRPAjouterArc(6, 8);
    graphe.GRPAjouterArc(7, 8);
    graphe.GRPGenererGraphviz();
    return 0;
}
