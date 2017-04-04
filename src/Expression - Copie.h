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

class Expression: public InstructionVraie{
    public:
        enum TypeExpr{
            Unaire=1,
            Binaire=2,
            Char=3,
            entier=4,
            variable=5,
            affectation=6,
            affectationUnaire=7,
            appelFonction=8,
            argsAppel=9,
            assignation=10,
			expressionVariable=11
        };
		InstructionVraie::TypeClass WhatIsThisType();
        virtual void print();
        Expression();
        ~Expression();
        virtual Expression::TypeExpr WhatIsThisExprType();


    private:

};

#endif // if ! defined EXPRESSION_H
