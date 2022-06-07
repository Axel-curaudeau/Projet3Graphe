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

            COperationGraphe OPG;
            if (OPG.OPEEstUneClique(*graphe)) {
                cout << "Le graphe saisie est une clique" << endl;
            }
            else {
                cout << "Le graphe saisie n'est pas une clique" << endl;
            }

            cout << "Sous graphe est une clique : " << OPG.OPEEstUneClique(*graphe, 1, 2, 3, -1);
            delete graphe;
        }
        catch (CException EXCE) {
            cout << EXCE.EXCLireMessage() << endl;
        }
    }
    
    return 0;
}
