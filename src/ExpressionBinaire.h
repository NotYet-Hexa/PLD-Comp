/*************************************************************************
PLD Comp
ExpressionBinaire.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe ExpressionBinaire (fichier ExpressionBinaire.h) ------
#if ! defined ( EXPRESSIONBINAIRE_H )
#define EXPRESSIONBINAIRE_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Expression.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe ExpressionBinaire:
//

//------------------------------------------------------------------------

class ExpressionBinaire : public Expression {
    public:
        void print();
        std::list<string> listeNomLValue();
        ExpressionBinaire(Expression* g, Expression* d, string symb);
        ~ExpressionBinaire();

    private:
        string symbole;
        Expression* gauche;
        Expression* droite;
        TypeExpression type_expression;
};

#endif // if ! defined EXPRESSIONBINAIRE_H
