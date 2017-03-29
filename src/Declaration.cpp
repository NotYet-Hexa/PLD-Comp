/*************************************************************************
PLD Comp
Declaration.cpp  -  Description
-------------------
début                : 23/02/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/

//---------- Réalisation de la classe Declaration (fichier Declaration.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Declaration.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//----- Constructeur
Declaration::Declaration(string t, string n):type(t),nom(n)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Declaration::~Declaration()
{}// Bloc vide
//----- Fin destructeur

void Declaration::print()
{
	cout << "Declaration : type ->" << type << "  |  nom -> " << nom << endl;
}