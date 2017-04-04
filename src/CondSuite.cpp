/*************************************************************************
PLD Comp
CondSuite.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe CondSuite (fichier CondSuite.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "CondSuite.h"
#include "InstructionVraie.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void CondSuite::print()
{
    if(!vide)
    {
        cout << "CondSuite :" << endl;
        this->instruction->print();
    }
}

void CondSuite::checkContexte(Contexte* contexteCourant )
{
    if(!vide)
    {
        this->instruction->checkContexte(contexteCourant);
    }
}

//----- Constructeur
CondSuite::CondSuite(bool monVide, Instruction* monInstruction): instruction(monInstruction), vide(monVide)
{
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
CondSuite::~CondSuite()
{
	delete this->instruction;
}
//----- Fin destructeur
