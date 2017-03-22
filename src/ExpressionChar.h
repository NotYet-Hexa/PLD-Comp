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
        ExpressionChar(char car);
        ~ExpressionChar();

    private:
        char valeur;
};

#endif // if ! defined EXPRESSIONCHAR_H