#ifndef CSOMMET_H
#define CSOMMET_H

#include "CArc.h"

/* ===== ERROR CODES ===== */

/* 
 * Classe CSommet
 *
 * Cette class est utilisée pour gérer les sommets.
 */
class CSommet
{
    private :
        unsigned int uiSOMNumero;
        CArc** ppARCSOMEntrant;
        CArc** ppARCSOMSortant;

    public :
        CSommet() = delete;
        CSommet(unsigned int uiSOMNumero);
        CSommet(CSommet & SOMSommet);
        ~CSommet();
        
};

#endif // CSOMMET_H