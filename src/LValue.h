/*************************************************************************
PLD Comp
LValue.h  -  Description
-------------------
début                : 23/02/2017
copyright            : (C)2017 par Haim Nathan
*************************************************************************/

//---------- Interface de la classe LValue (fichier LValue.h) ------
#if ! defined ( LVALUE_H )
#define LVALUE_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Expression.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe LValue:
//

//------------------------------------------------------------------------

class LValue : public Expression {
    public:
        list<string> listeNomLValue();
        void print();
        LValue(string nom, bool isTab, int num);
        ~LValue();
        bool getIsTab(){return isTab;}
        virtual InstructionVraieClass typeClass();
        string getNom(){return nom;}
        TypeExpression getType()
    private:
        string nom;
        bool isTab;
        int num;
        TypeExpression type_expression;
};

#endif // if ! defined LVALUE_H
