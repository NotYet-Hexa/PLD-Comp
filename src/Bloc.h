/*************************************************************************
PLD Comp
Bloc.h  -  Description
-------------------
début                : 23/02/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/

//---------- Interface de la classe Bloc (fichier Bloc.h) ------
#if ! defined ( BLOC_H )
#define BLOC_H


//--------------------------------------------------- Interfaces utilisées
#include "ListInstruction.h"
#include "InstructionVraie.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Bloc:
//

//------------------------------------------------------------------------

class InstructionVraie;

class Bloc : public InstructionVraie{
    public:
        void print();
        Bloc(ListInstruction* maListInstruction);
        ~Bloc();
        ListInstruction* getListInstruction();

    private:
    ListInstruction* listInstruction;

};

#endif // if ! defined BLOC_H