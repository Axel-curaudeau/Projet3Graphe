#ifndef COPERATIONGRAPHE_H
#define COPERATIONGRAPHE_H

#include "CGraphe.h"
class COperationGraphe
{
public:
    COperationGraphe();

    /* ********************************************************
    *                      Inverser                           *
    ***********************************************************
    * Entr�e: CGraphe GRPGraphe                               *
    * N�cessite: -                                            *
    * Sortie: CGraphe                                         *
    * Entraine: retourne un nouveau graphe invers�            *
    * ******************************************************* */
    CGraphe OPEInverserGraphe(CGraphe & GRPGraphe);
};

#endif