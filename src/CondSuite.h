/*************************************************************************
PLD Comp
CondSuite.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe CondSuite (fichier CondSuite.h) ------
#if ! defined ( CONDSUITE_H )
#define CONDSUITE_H


//--------------------------------------------------- Interfaces utilisées

#include "InstructionVraie.h"
#include "Instruction.h"
#include "Expression.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe CondSuite:
//

//------------------------------------------------------------------------

class CondSuite  {
    public:
        void print();
        void checkContexte(Contexte* contexteCourant );
        CondSuite(bool vide, Instruction* instruction);
        ~CondSuite();

    private:
    bool vide;
    Instruction* instruction;

};

#endif // if ! defined CONDSUITE_H