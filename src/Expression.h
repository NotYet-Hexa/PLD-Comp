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
            Enum_Unaire=1,
            Enum_Binaire=2,
            Enum_Char=3,
            Enum_Entier=4,
            Enum_Variable=5,
            Enum_Affectation=6,
            Enum_AffectationUnaire=7,
            Enum_AppelFonction=8,
            Enum_ArgsAppel=9,
            Enum_Assignation=10,
            Enum_ExpressionVariable=11
        };

        Expression::TypeExpression getType();
        virtual void print();
        virtual std::list<string> listeNomLValue()=0;

        Expression();
        ~Expression();
        virtual InstructionVraieClass typeClass();

    protected:
        TypeExpression type_expression;
};

#endif // if ! defined EXPRESSION_H
