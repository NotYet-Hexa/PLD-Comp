/*************************************************************************
PLD Comp
Return.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe Return (fichier Return.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "Return.h"
#include "InstructionVraie.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Return::print()
{
    cout << "Return :" << endl;
    expression->print();
}

//----- Constructeur
Return::Return(Expression* monExpression): expression(monExpression)
{
    this->typeInstruction = InstructionVraie::TIretourFonction;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Return::~Return()
{

}
//----- Fin destructeur
