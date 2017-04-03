/*************************************************************************
PLD Comp
Variable.h  -  Description
-------------------
début                : 27/03/2017
copyright            : (C)2017
*************************************************************************/

//---------- Interface de la classe Variable(fichier Variable.h) ------
#if ! defined ( VARIABLE_H )
#define VARIABLE_H


//--------------------------------------------------- Interfaces utilisées
# include "Expression.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Variable:
//

//------------------------------------------------------------------------

class Variable: public Expression{
public:
    virtual void print();
    Variable();
    ~Variable();
    Expression::TypeExpr WhatIsThisExprType();
private:

};

#endif // if ! defined VARIABLE_H