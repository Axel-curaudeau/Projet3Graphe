#ifndef CEXCEPTION_H
#define CEXCEPTION_H

/* ===== ERROR CODES ===== */
#define EXCEPTION_INCONNUE 0
#define MALLOC_ECHOUE 1

/*
 * Classe CException
 * 
 * Cette class est utilisée pour gérer les exceptions
 */
class CException
{
    private :
        unsigned int uiEXCCode;
        char* pcEXCMessage;
  
    public:

        /* *********************************************************
         *                 Constructeur par defaut                 *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé avec l'erreur *
         *           EXCEPTION_INCONNUE (0) et le message :        *
         *           "Erreur initialisée par defaut".              *
         ********************************************************* */
        CException()
        {
            uiEXCCode = EXCEPTION_INCONNUE;
            pcEXCMessage = (char*) "Erreur non definie";
        }

        /* *********************************************************
         *               Constructeur par parametre                *
         ***********************************************************
         * Entrée: unsigned int uiCode                             *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé avec l'erreur *
         *           uiCode et le message :                        *
         *           "*Message d'erreur manquant*".                *
         ********************************************************* */
        CException(unsigned int uiCode)
        {
            uiEXCCode = uiCode;
            pcEXCMessage = (char*) "*Message d'erreur manquant*";
        }

        /* *********************************************************
         *               Constructeur par parametre                *
         ***********************************************************
         * Entrée: unsigned int uiCode                             *
         *         char* pcMessage                                 * 
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: L'objet en cours est initialisé avec l'erreur *
         *           uiCode et le message sMessage.                *
         ********************************************************* */
        CException(unsigned int uiCode, char* pcMessage)
        {
            uiEXCCode = uiCode;
            pcEXCMessage = pcMessage;
        }

        /* *********************************************************
         *              Accesseur uiEXCCode (lecture)              *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: unsigned int                                    *
         * Entraine: Retourne l'erreur de l'objet en cours.        *
         ********************************************************* */
        unsigned int EXCLireCode()
        {
            return uiEXCCode;
        }

        /* *********************************************************
         *              Accesseur uiEXCCode (écriture)             *
         ***********************************************************
         * Entrée: unsigned int uiCode                             *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Modifie l'erreur de l'objet en cours          *
         ********************************************************* */
        void EXCModifierCode(unsigned int uiCode)
        {
            uiEXCCode = uiCode;
        }

        /* *********************************************************
         *            Accesseur pcEXCMessage (lecture)             *
         ***********************************************************
         * Entrée: -                                               *
         * Nécessite: -                                            *
         * Sortie: char*                                           *
         * Entraine: Retourne le message de l'objet en cours       *
         ********************************************************* */
        char* EXCLireMessage()
        {
            return pcEXCMessage;
        }

        /* *********************************************************
         *            Accesseur pcEXCMessage (écriture)            *
         ***********************************************************
         * Entrée: char* pcMessage                                 *
         * Nécessite: -                                            *
         * Sortie: -                                               *
         * Entraine: Modifie le message de l'objet en cours        *
         ********************************************************* */
        void EXCModifierMessage(char* pcMessage)
        {
            pcEXCMessage = pcMessage;
        }
};

#endif // CEXCEPTION_H