/*************************************************************************
PLD Comp
Instruction.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe Instruction (fichier Instruction.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "InstructionVraie.h"
#include "Instruction.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Instruction::print()
{
    cout << "Instruction :" << endl;
    instruction->print();
}

//----- Constructeur
Instruction::Instruction(InstructionVraie* monInstruction): instruction(monInstruction)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Instruction::~Instruction()
{
    //delete instruction;
}// Bloc vide
//----- Fin destructeur

InstructionVraie* Instruction::getInstructionVraie()
{
    return this->instruction;
}
