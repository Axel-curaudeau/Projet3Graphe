#include <iostream>
#include "CArc.h"
#include "CLexeur.h"
#include "CAnalyseur.h"
#include "CSommet.h"
#include "CGraphe.h"
#include "COperationGraphe.h"
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{
    try{
        CGraphe* graphe = new CGraphe();
        graphe->GRPAjouterSommet(1);
        graphe->GRPAjouterSommet(2);
        graphe->GRPAjouterSommet(3);
        graphe->GRPAjouterSommet(4);
        graphe->GRPAjouterSommet(5);
        graphe->GRPAjouterSommet(6);
        graphe->GRPAjouterSommet(7);
        graphe->GRPAjouterSommet(8);
        graphe->GRPModifierSommet(7, 12);
        graphe->GRPAjouterArc(1, 2);
        graphe->GRPAjouterArc(1, 3);
        graphe->GRPAjouterArc(1, 4);
        graphe->GRPAjouterArc(2, 5);
        graphe->GRPAjouterArc(2, 6);
        graphe->GRPAjouterArc(3, 12);
        graphe->GRPAjouterArc(3, 8);
        graphe->GRPAjouterArc(4, 8);
        graphe->GRPAjouterArc(5, 8);
        graphe->GRPAjouterArc(6, 8);
        graphe->GRPAjouterSommet(9);
        graphe->GRPAjouterSommet(10);
        graphe->GRPAjouterSommet(11);
        graphe->GRPAjouterArc(10, 11);

        graphe->GRPAfficher();
        graphe->GRPGenererGraphviz();

        COperationGraphe OPE1;
        CGraphe grapheinverse = OPE1.OPEInverserGraphe(*graphe);
        grapheinverse.GRPGenererGraphviz();
        

        delete graphe;

        CGraphe graphe2;
        CLexeur fichier((char*)"graphes/graphetest.txt");
        CAnalyseur analyse(&fichier);
        cout << analyse.ANLLireNbArcs() << "|" << analyse.ANLLireNbSommets() << endl;
        analyse.ANLLireSommets(graphe2);
        analyse.ANLLireArcs(graphe2);
        graphe2.GRPGenererGraphviz();
    }
    catch (CException EXCE) {
        cout << EXCE.EXCLireMessage() << endl;
    }
    return 0;
}
