/*************************************************************************
PLD Comp
ExpressionVariable.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe ExpressionVariable (fichier ExpressionVariable.h) ------
#if ! defined ( EXPRESSIONVARIABLE_H )
#define EXPRESSIONVARIABLE_H


//--------------------------------------------------- Interfaces utilisées
#include <string>

#include "Expression.h"
//------------------------------------------------------------------------

using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe ExpressionVariable:
//

//------------------------------------------------------------------------

class ExpressionVariable : public Expression{
    public:
        void print();
        std::list<string> listeNomLValue();
        ExpressionVariable(string nom);
        ~ExpressionVariable();
        virtual InstructionVraieClass typeClass();
        string get_nomVariable();
        TypeExpression getType();
    private:
        string nomVariable;
        TypeExpression type_expression;
};

#endif // if ! defined EXPRESSIONVARIABLE_H
