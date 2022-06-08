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

            cout << "indiquez quels sommet vous souhaitez garder pour le sous-graphe separe par un espace (exemple : \"1 2 3 4\") :" << endl;

            char pcInput[TAILLE_MAX_LIGNE];
            char* pcSommet = nullptr;
            int piTabSommet[TAILLE_MAX_LIGNE];
            unsigned int uiNbSommet = 0;
            
            cin.getline(pcInput, TAILLE_MAX_LIGNE);
            pcSommet = strtok(pcInput, " ");
            while (pcSommet != nullptr) {
                piTabSommet[uiNbSommet] = atoi(pcSommet);
                uiNbSommet++;
                pcSommet = strtok(nullptr, " ");
            }

            cout << "Le sous graphe saisie est une clique : " << OPG.OPEEstUneClique(*graphe, uiNbSommet, piTabSommet) << endl;

            delete graphe;
        }
        catch (CException EXCE) {
            cout << EXCE.EXCLireMessage() << endl;
        }
    }
    
    return 0;
}
