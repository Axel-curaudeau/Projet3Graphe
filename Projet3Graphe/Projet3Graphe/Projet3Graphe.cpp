#include <iostream>
#include "CArc.h"
#include "CLecteur.h"
#include "CAnalyseur.h"
#include "CSommet.h"
#include "CGraphe.h"
#include <cstring>

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

    graphe.GRPGenererGraphviz();

    CGraphe graphe2;
    CLecteur fichier((char*)"graphes/graphetest.txt");
    CAnalyseur analyse(&fichier);
    analyse.ANLLireSommets(graphe2);
    analyse.ANLLireArcs(graphe2);
    graphe2.GRPGenererGraphviz();
    return 0;
}
