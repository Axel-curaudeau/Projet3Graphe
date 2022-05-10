#define CPARSEUR_H
#ifndef CPARSEUR_H

class CParseur {
	private :
		ifstream IFSPRSFichier;
		char* pcPRSLigne;
	public :
		CParseur();
		CParseur(ifstream IFSFile);
		ifstream PRSLireFichier();

};




#endif //CPARSEUR_H