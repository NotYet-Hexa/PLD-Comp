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
#include <list>
#include <string>
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Expression:
//

//------------------------------------------------------------------------

class Expression: public InstructionVraie{
    public:

        enum TypeExpression{
            Unaire=1,
            Binaire=2,
            Char=3,
            Entier=4,
            Variable=5,
            Affectation=6,
            AffectationUnaire=7,
            AppelFonction=8,
            ArgsAppel=9,
            Assignation=10,
            ExpressionVariable=11
        };

        Expression::TypeExpression getType();
        virtual void print();
        virtual std::list<string> listeNomLValue()=0;

        Expression();
        ~Expression();

    protected:
        TypeExpression type_expression;
};

#endif // if ! defined EXPRESSION_H