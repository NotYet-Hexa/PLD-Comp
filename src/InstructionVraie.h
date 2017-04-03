/*************************************************************************
PLD Comp
InstructionVraie.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe InstructionVraie (fichier InstructionVraie.h) ------
#if ! defined ( INSTRUCTIONVRAIE_H )
#define INSTRUCTIONVRAIE_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe InstructionVraie:
//

//------------------------------------------------------------------------

enum TypeInstruction
{
    TIexpression,
    TIbloc,
    TIretourFonction,
    TIdeclaration
};


class InstructionVraie{
    public:
        TypeInstruction getTypeInstruction();
        virtual void print() = 0;
        InstructionVraie();
        ~InstructionVraie();

    protected:
        TypeInstruction typeInstruction;
};

#endif // if ! defined INSTRUCTIONVRAIE_H