/*************************************************************************
PLD Comp
Return.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe Return (fichier Return.h) ------
#if ! defined ( RETURN_H )
#define RETURN_H


//--------------------------------------------------- Interfaces utilisées

#include "InstructionVraie.h"
#include "Expression.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Return:
//

//------------------------------------------------------------------------

class Return : public InstructionVraie {
    public:
        void print();
        std::list<std::string> listeNomLValue();
        Return(Expression* monExpression);
        ~Return();
        Expression* get_expression();
        virtual InstructionVraieClass typeClass();
    private:
    Expression* expression;

};

#endif // if ! defined RETURN_H