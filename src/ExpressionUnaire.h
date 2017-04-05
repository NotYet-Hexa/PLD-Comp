/*************************************************************************
PLD Comp
ExpressionUnaire.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe ExpressionUnaire (fichier ExpressionUnaire.h) ------
#if ! defined ( EXPRESSIONUNAIRE_H )
#define EXPRESSIONUNAIRE_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Expression.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe ExpressionUnaire:
//

//------------------------------------------------------------------------

class ExpressionUnaire : public Expression {
    public:
        void print();
        std::list<string> listeNomLValue();
        ExpressionUnaire( Expression* exp ,string symb);
        ~ExpressionUnaire();
        string get_symbole();
        Expression* get_expression();
        
    private:
        string symbole;
        Expression* expression;
        TypeExpression type_expression;
};

#endif // if ! defined EXPRESSIONUNAIRE_H
