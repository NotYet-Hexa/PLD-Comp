/*************************************************************************
PLD Comp
Instruction.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe Instruction (fichier Instruction.h) ------
#if ! defined ( LISTINSTRUCTION_H )
#define LISTINSTRUCTION_H


//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include "Instruction.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Instruction:
//

//------------------------------------------------------------------------

class ListInstruction{
    public:
        void print();
        void addInstruction(Instruction* instruction);
        ListInstruction();
        ~ListInstruction();
        std::vector<Instruction*> getInstructions();

    private:
    std::vector<Instruction*> listInstruction;

};

#endif // if ! defined LISTINSTRUCTIONVRAIE_H
