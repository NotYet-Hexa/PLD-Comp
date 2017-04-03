/*************************************************************************
PLD Comp
Entier.h  -  Description
-------------------
début                : 27/03/2017
copyright            : (C)2017
*************************************************************************/

//---------- Interface de la classe Entier (fichier Entier.h) ------
#if ! defined ( ENTIER_H )
#define ENTIER_H


//--------------------------------------------------- Interfaces utilisées
# include "Expression.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Entier:
//

//------------------------------------------------------------------------

class Entier: public Expression{
public:
    virtual void print();
    Entier();
    ~Entier();
    Expression::TypeExpr WhatIsThisExprType();
private:

};

#endif // if ! defined ENTIER_H