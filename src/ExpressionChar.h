/*************************************************************************
PLD Comp
ExpressionChar.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe ExpressionChar (fichier ExpressionChar.h) ------
#if ! defined ( EXPRESSIONCHAR_H )
#define EXPRESSIONCHAR_H


//--------------------------------------------------- Interfaces utilisées
#include "Expression.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe ExpressionChar:
//

//------------------------------------------------------------------------

class ExpressionChar : public Expression{
    public:
        void print();
        std::list<string> listeNomLValue();
        ExpressionChar(char car);
        ~ExpressionChar();
        virtual InstructionVraieClass typeClass();
        char getChar(){return valeur;}
        TypeExpression getType();

    private:
        char valeur;
        TypeExpression type_expression;
};

#endif // if ! defined EXPRESSIONCHAR_H
