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
Declaration::Declaration(string t, string n, bool isT, int s):type(t),nom(n),isTab(isT), size(s)
{
	this->typeInstruction = InstructionVraie::TIdeclaration;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Declaration::~Declaration()
{}// Bloc vide
//----- Fin destructeur

void Declaration::print()
{
	cout << "Declaration : type ->" << type << "  |  nom -> " << nom;
	if(isTab)
	{
		cout<<"[";
		if(size>0)
		{
			cout<<size;
		}
		cout<<"]";
	}
	cout<<endl;
}

InstructionVraieClass Declaration::typeClass()
{
    return InstructionVraieClass::declaration;
}

