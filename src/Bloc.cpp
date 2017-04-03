/*************************************************************************
PLD Comp
Instruction.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/

//---------- Réalisation de la classe Bloc (fichier Bloc.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "Bloc.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Bloc::print()
{
    cout << "Bloc :" << endl;
    listInstruction->print();
    cout << "Fin de Bloc" << endl;
}

//----- Constructeur
Bloc::Bloc(ListInstruction* maListInstruction): listInstruction(maListInstruction)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Bloc::~Bloc()
{
    //delete instruction;
}// Bloc vide
//----- Fin destructeur

ListInstruction* Bloc::getListInstruction() { return listInstruction; }