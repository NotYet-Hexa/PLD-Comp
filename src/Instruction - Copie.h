/*************************************************************************
PLD Comp
Instruction.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe Instruction (fichier Instruction.h) ------
#if ! defined ( INSTRUCTION_H )
#define INSTRUCTION_H


//--------------------------------------------------- Interfaces utilisées

#include "InstructionVraie.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Instruction:
//

//------------------------------------------------------------------------

class Instruction{
    public:
        void print();
        Instruction(InstructionVraie* monInstruction);
        ~Instruction();
        InstructionVraie get_instru();

    private:
    InstructionVraie* instruction;

};

#endif // if ! defined INSTRUCTIONVRAIE_H