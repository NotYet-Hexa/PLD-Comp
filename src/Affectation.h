/*************************************************************************
PLD Comp
Affectation.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe AffectationDeclaratino (fichier AffectationDeclaratino.h) ------
#if ! defined ( AFFECTATION_H )
#define AFFECTATION_H


//--------------------------------------------------- Interfaces utilisées


#include "Expression.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe AffectationDeclaratino:
//

//------------------------------------------------------------------------
class Affectation: public Expression {
    public:
        void print();
        Affectation(string nomVariable, string symbole, Expression* monExpression);
        ~Affectation();
        string get_nomVariable();
        string get_symbole();
        Expression* get_expression();
        Expression::TypeExpr WhatIsThisExprType();

    private:
    string nomVariable;
    string symbole;
    Expression* expression;

};

#endif // if ! defined AFFECTATION