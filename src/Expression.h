/*************************************************************************
PLD Comp
Expression.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe Expression (fichier Expression.h) ------
#if ! defined ( EXPRESSION_H )
#define EXPRESSION_H


//--------------------------------------------------- Interfaces utilisées
# include "InstructionVraie.h"
#include <list>
#include <string>
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Expression:
//

//------------------------------------------------------------------------

class Expression: public InstructionVraie{
    public:
        virtual void print();
        virtual std::list<string> listeNomLValue()=0;
        Expression();
        ~Expression();

    private:

};

#endif // if ! defined EXPRESSION_H