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
    if (argc == 2) {
        try {
            CGraphe graphe;
            CLexeur fichier(argv[1]);
            CAnalyseur analyse(&fichier);
            analyse.ANLLireSommets(graphe);
            analyse.ANLLireArcs(graphe);
            graphe.GRPAfficher();

            graphe.GRPGenererGraphviz();

            COperationGraphe OPG;
            CGraphe graphe2 = OPG.OPEInverserGraphe(graphe);
            graphe2.GRPAfficher();
        }
        catch (CException EXCE) {
            cout << EXCE.EXCLireMessage() << endl;
        }
    }
    
    return 0;
}
