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
#include "ListInstruction.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void ListInstruction::checkContexte(Contexte* contexteCourant )
{
    for(std::vector<Instruction*>::iterator it = listInstruction.begin() ; it != listInstruction.end() ; it++)
    {
    	(*it)->checkContexte(contexteCourant);
    }
}

void ListInstruction::print()
{
    cout << "ListInstruction :" << endl;
    for(std::vector<Instruction*>::iterator it = listInstruction.begin() ; it != listInstruction.end() ; it++)
    {
    	(*it)->print();
    }
}

//----- Constructeur
ListInstruction::ListInstruction()
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ListInstruction::~ListInstruction()
{
    //delete instruction;
}// Bloc vide
//----- Fin destructeur

std::vector<Instruction*> ListInstruction::getInstructions()
{
    return this->listInstruction;
}


void ListInstruction::addInstruction(Instruction* instruction)
{
	listInstruction.push_back(instruction);
}
