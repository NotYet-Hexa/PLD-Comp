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
enum TypeExpr{argsAppel=9};
class ArgsAppel{
    public:
        ArgsAppel();
        ~ArgsAppel();
        void add(Expression* expression);
        void print();
        std::vector <Expression*> get_args();
        Expression::TypeExpr WhatIsThisExprType();

    private:
        std::vector <Expression*> args;
};

#endif // if ! defined ARGSAPPEL_H