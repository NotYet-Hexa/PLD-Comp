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
            Type_Unaire,
            Type_Binaire,
            Type_Char,
            Type_Entier,
            Type_Variable,
            Type_Affectation,
            Type_AffectationUnaire,
            Type_AppelFonction,
            Type_Assignation,
            Type_ExpressionVariable
        };

        Expression::TypeExpression getType();
        virtual void print();
        virtual std::list<string> listeNomLValue()=0;


        Expression();
        virtual ~Expression();
        virtual InstructionVraieClass typeClass();

    protected:
        TypeExpression type_expression;
};

#endif // if ! defined EXPRESSION_H
