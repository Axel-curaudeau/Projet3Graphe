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
            CGraphe* graphe = new CGraphe();
            CAnalyseur analyse(argv[1]);
            analyse.ANLInitialiserGraphe(*graphe);
            graphe->GRPAfficher();

            cout << endl << "Ouvre le lien suivant dans votre navigateur pour visualiser le graphe :" << endl;
            graphe->GRPGenererGraphviz();

            cout << endl << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << "Inversion du graphe précédent :" << endl;
            COperationGraphe OPG;
            CGraphe* graphe2 =new CGraphe(OPG.OPEInverserGraphe(*graphe));
            //graphe2->GRPAfficher();

            cout << endl << "Ouvre le lien suivant dans votre navigateur pour visualiser le graphe :" << endl;
            graphe2->GRPGenererGraphviz();

            cout << "Orienté : " << graphe->GRPEstOriente() << endl;

            cout << "clique : " << OPG.OPEEstUneClique(*graphe, 1, 2, -1) << endl;

            delete graphe;
            delete graphe2;
        }
        catch (CException EXCE) {
            cout << EXCE.EXCLireMessage() << endl;
        }
    }
    
    return 0;
}
