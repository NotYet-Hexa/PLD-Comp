/*************************************************************************
PLD Comp
Expression.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe Expression (fichier Expression.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Expression.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Expression::print()
{
    cout << "salut" << endl;
}
//----- Constructeur
Expression::Expression()
{
    this->typeInstruction = TIexpression;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Expression::~Expression()
{}// Bloc vide
//----- Fin destructeur