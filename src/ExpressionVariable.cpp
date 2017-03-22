/*************************************************************************
PLD Comp
ExpressionVariable.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe ExpressionVariable (fichier ExpressionVariable.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "ExpressionVariable.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void ExpressionVariable::print()
{
    // Ajouter la valeur après les :
    cout << "variable : " << nomVariable << endl;
}
//----- Constructeur
ExpressionVariable::ExpressionVariable(string nom) : nomVariable(nom)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ExpressionVariable::~ExpressionVariable()
{}// Bloc vide
//----- Fin destructeur