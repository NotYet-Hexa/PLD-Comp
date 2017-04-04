/*************************************************************************
PLD Comp
ExpressionEntier.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe ExpressionEntier (fichier ExpressionEntier.h) ------
#if ! defined ( EXPRESSIONENTIER_H )
#define EXPRESSIONENTIER_H


//--------------------------------------------------- Interfaces utilisées
#include "Expression.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe ExpressionEntier:
//

//------------------------------------------------------------------------

class ExpressionEntier : public Expression{
    public:
        void print();
        std::list<string> listeNomLValue();
        ExpressionEntier(int);
        ~ExpressionEntier();
        int get_valeur();

    private:
        int valeur;
};

#endif // if ! defined EXPRESSIONENTIER_H