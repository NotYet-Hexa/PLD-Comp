/*************************************************************************
PLD Comp
PutChar.h  -  Description
-------------------
début                : 27/03/2017
copyright            : (C)2017
*************************************************************************/

//---------- Interface de la classe PutChar (fichier PutChar.h) ------
#if ! defined ( PUTCHAR_H )
#define PUTCHAR_H


//--------------------------------------------------- Interfaces utilisées

#include "InstructionVraie.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe PutChar:
//

//------------------------------------------------------------------------

class PutChar : public InstructionVraie {
public:
    virtual void print();
    PutChar(char monChar);
    ~PutChar();

private:
    char theChar;

};

#endif // if ! defined PUTCHAR_H
