/*************************************************************************
PLD Comp
Declaration.h  -  Description
-------------------
début                : 23/02/2017
copyright            : (C)2017 par Haim Nathan
*************************************************************************/

//---------- Interface de la classe Declaration (fichier Declaration.h) ------
#if ! defined ( DECLARATION_H )
#define DECLARATION_H

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

class ExpressionBinaire : public Instruction {
    public:
        void print();
        ExpressionBinaire(Expression* g, Expression* d, string symb);
        ~ExpressionBinaire();

    private:
        string symbole;
        Expression* gauche;
        Expression* droite;
};

#endif // if ! defined DECLARATION_H