/*************************************************************************
PLD Comp
Declaration.h  -  Description
-------------------
début                : 23/02/2017
copyright            : (C)2017 par Haim Nathan
*************************************************************************/

//---------- Interface de la classe Declaration (fichier Declaration.h) ------
#if ! defined ( DECLARATION_H )
#define DECLARATION_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "ExpressionVrai.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Declaration:
//

//------------------------------------------------------------------------

class Declaration : public InstructionVrai {
    public:
        void print();
        Declaration(string type, string nom);
        ~Declaration();

    private:
        string type;
        string nom;
};

#endif // if ! defined DECLARATION_H