#ifndef CANALYSEUR_H
#define CANALYSEUR_H

#include "CParseur.h"

//Codes d'erreur
#define ERREUR_SYNTAXE 10
class CAnalyseur
{
private :
	CParseur* pPRSANLParseur;
	//CGraph GRFANLGraphe; 
public :
	CAnalyseur(CParseur* pPRSParseur);
	void ANLModifierParseur(CParseur PRSParseur);
	unsigned int ANLLireNbSommet();
	unsigned int ANLLireNbArc();
	void ANLLireSommets();
	void ANLLireArcs();
};

#endif