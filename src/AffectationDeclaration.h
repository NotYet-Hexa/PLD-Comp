/*************************************************************************
PLD Comp
AffectationDeclaration.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe AffectationDeclaratino (fichier AffectationDeclaratino.h) ------
#if ! defined ( AFFECTATIONDECLARATION )
#define AFFECTATIONDECLARATION


//--------------------------------------------------- Interfaces utilisées


#include "Expression.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe AffectationDeclaratino:
//

//------------------------------------------------------------------------

class AffectationDeclaration {
    public:
        void print();
        AffectationDeclaration(Expression* monExpression);
        ~AffectationDeclaration();

    private:
    Expression* expression;

};

#endif // if ! defined AFFECTATIONDECLARATION