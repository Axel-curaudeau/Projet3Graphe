
#include <iostream>
#include "CParseur.h"
#include "CArc.h"
#include "CParseur.h"
#include "CAnalyseur.h"

using namespace std;

int main(int argc, char* argv[])
{
    try {
        CParseur* fichier = new CParseur((char*)"graphes/graphetest.txt");
        /*char pcPrecedent[TAILLE_MAX_LIGNE];
        char pcSuivant[TAILLE_MAX_LIGNE];
        fichier.PRSLigneSuivante(pcPrecedent, pcSuivant, (char*)"=");
        cout << pcPrecedent << "| |" << pcSuivant << endl;*/
        char result[TAILLE_MAX_LIGNE];
        CAnalyseur analyse = CAnalyseur(fichier);
        analyse.ANLLireSommets();

        //cout << result << endl;
    } catch (CException e) {
        cout << e.EXCLireMessage() << endl;
    }
    
    return 0;
}
