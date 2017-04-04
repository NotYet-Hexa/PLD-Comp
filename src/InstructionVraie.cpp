/*************************************************************************
PLD Comp
InstructionVraie.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe InstructionVraie (fichier InstructionVraie.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "InstructionVraie.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

InstructionVraie::TypeInstruction InstructionVraie::getTypeInstruction()
{
    return typeInstruction;
}

//----- Constructeur
InstructionVraie::InstructionVraie()
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
InstructionVraie::~InstructionVraie()
{}// Bloc vide
//----- Fin destructeur

InstructionVraieClass InstructionVraie::typeClass()
{
    return InstructionVraieClass::instructionVraie;
}
