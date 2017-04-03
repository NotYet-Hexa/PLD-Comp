/*************************************************************************
PLD Comp
Expression.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe Expression (fichier Expression.h) ------
#if ! defined ( EXPRESSION_H )
#define EXPRESSION_H


//--------------------------------------------------- Interfaces utilisées
# include "InstructionVraie.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Expression:
//

//------------------------------------------------------------------------
enum TypeClass { expression = 3 };
class Expression: public InstructionVraie{
    public:
		TypeClass WhatIsThisType();
        virtual void print();
        Expression();
        ~Expression();

    private:

};

#endif // if ! defined EXPRESSION_H
