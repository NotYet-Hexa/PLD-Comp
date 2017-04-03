/*************************************************************************
PLD Comp
ArgsDef.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe ArgsDef (fichier ArgsDef.h) ------
#if ! defined ( ARGSDEF_H )
#define ARGSDEF_H

#include <vector>
//--------------------------------------------------- Interfaces utilisées
#include "Declaration.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe ArgsDef:
//

//------------------------------------------------------------------------

class ArgsDef{
    public:
        ArgsDef();
        ~ArgsDef();
        void add(Declaration* declaration);
        void print();
        std::vector <Declaration*> get_args();

    private:
        std::vector <Declaration*> args;
};

#endif // if ! defined ARGSDEF_H