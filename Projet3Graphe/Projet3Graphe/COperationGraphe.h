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
    * Entrée: CGraphe GRPGraphe                               *
    * Nécessite: -                                            *
    * Sortie: CGraphe                                         *
    * Entraine: retourne un nouveau graphe inversé            *
    * ******************************************************* */
    CGraphe OPEInverserGraphe(CGraphe & GRPGraphe);
};

#endif