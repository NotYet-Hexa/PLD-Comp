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

class InstructionVraie{
    public:
        virtual void print();
        InstructionVraie();
        ~InstructionVraie();

    private:

};

#endif // if ! defined INSTRUCTIONVRAIE_H