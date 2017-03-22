/*************************************************************************
PLD Comp
ExpressionChar.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe ExpressionChar (fichier ExpressionChar.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "ExpressionChar.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void ExpressionChar::print()
{
    cout << valeur << endl;
}
//----- Constructeur
ExpressionChar::ExpressionChar(char car) : valeur(car)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ExpressionChar::~ExpressionChar()
{}// Bloc vide
//----- Fin destructeur