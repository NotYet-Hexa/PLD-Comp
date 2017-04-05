/*************************************************************************
PLD Comp
LoopStatement.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe LoopStatement (fichier LoopStatement.h) ------
#if ! defined ( LOOPSTATEMENT_H )
#define LOOPSTATEMENT_H


//--------------------------------------------------- Interfaces utilisées

#include "InstructionVraie.h"
#include "Instruction.h"
#include "Expression.h"


//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe LoopStatement:
//

//------------------------------------------------------------------------

class LoopStatement : public InstructionVraie {

      enum TypeLoop
        {
            TLfor,
            TLwhile
        };

    public:
        void print();
        void checkContexte(Contexte* contexteCourant );
        LoopStatement(Expression* monExpression, Instruction* instruction);//  pour while 
        LoopStatement(Expression* monExpression1, Expression* monExpression2, Expression* monExpression3, Instruction* instruction);
        ~LoopStatement(); // faire une switch si while ou for /!\ segment fault

    private:
    Expression * expression1;
    Expression * expression2;
    Expression * expression3;
    Instruction* instruction;
    TypeLoop typeLoop;


};

#endif // if ! defined LOOPSTATEMENT_H