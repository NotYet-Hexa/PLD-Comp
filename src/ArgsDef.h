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
#include <list>
#include <string>
#include <iterator>

using namespace std;
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
        std::list<string> getListNomParam();
        void add(Declaration* declaration);
        void print();

    private:
        std::vector <Declaration*> args;
};

#endif // if ! defined ARGSDEF_H