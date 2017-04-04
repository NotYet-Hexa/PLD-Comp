/*************************************************************************
PLD Comp
Cond.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe Cond (fichier Cond.h) ------
#if ! defined ( COND_H )
#define COND_H


//--------------------------------------------------- Interfaces utilisées

#include "InstructionVraie.h"
#include "Instruction.h"
#include "Expression.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Cond:
//

//------------------------------------------------------------------------

class Cond : public InstructionVraie {
    public:
        void print();
        std::list<string> listeNomLValue();
        void checkContexte(Contexte* contexteCourant );
        Cond(Expression* monExpression, Instruction* instruction);
        ~Cond();

    private:
    Expression * expression;
    Instruction* instruction;

};

#endif // if ! defined COND_H