/*************************************************************************
PLD Comp
ArgsAppel.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe ArgsAppel (fichier ArgsAppel.h) ------
#if ! defined ( ARGSAPPEL_H )
#define ARGSAPPEL_H

#include <vector>
//--------------------------------------------------- Interfaces utilisées
#include "Expression.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe ArgsAppel:
//

//------------------------------------------------------------------------

class ArgsAppel{
    public:
        ArgsAppel();
        ~ArgsAppel();
        void add(Expression* expression);
        void print();

    private:
        std::vector <Expression*> args;
};

#endif // if ! defined ARGSAPPEL_H