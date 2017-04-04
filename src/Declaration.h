/*************************************************************************
PLD Comp
Declaration.h  -  Description
-------------------
début                : 23/02/2017
copyright            : (C)2017 par Haim Nathan
*************************************************************************/

//---------- Interface de la classe Declaration (fichier Declaration.h) ------
#if ! defined ( DECLARATION_H )
#define DECLARATION_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "InstructionVraie.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Declaration:
//

//------------------------------------------------------------------------

class Declaration : public InstructionVraie {
    public:
        void print();
        Declaration(string type, string nom, bool isTab, int size);
        ~Declaration();
        InstructionVraieClass typeClass();
    string getType(){return type;}
    string getNom(){return nom;}
    private:
        string type;
        string nom;
        bool isTab;
        int size;
};

#endif // if ! defined DECLARATION_H
