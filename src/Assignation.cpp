/*************************************************************************
PLD Comp
Assignation.cpp  -  Description
-------------------
début                : 27/03/2017
copyright            : (C)2017
*************************************************************************/

//---------- Réalisation de la classe Assignation (fichier Assignation.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Assignation.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publique
void Assignation::print()
{
    
}
//----- Constructeur
Assignation::Assignation()
{
    this->type_expression = Expression::TypeExpression::Type_Assignation;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Assignation::~Assignation()
{}// Bloc vide
//----- Fin destructeur