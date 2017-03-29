/*************************************************************************
PLD Comp
Brique.cpp  -  Description
-------------------
début                : 27/03/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/

//---------- Réalisation de la classe Brique (fichier Brique.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Brique.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//----- Constructeur
Brique::Brique()
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Brique::~Brique()
{}// Bloc vide
//----- Fin destructeur

Brique::add(DefFonction* d)
{
	vectorDefinitionFonction.push_back(d);
}

Brique::add(DefFonction* d)
{
	vectorDeclarationFonction.push_back(d);
}

Brique::add(DefFonction* d)
{
	vectorDeclaration.push_back(d);
}

Brique::print()
{
	cout << "Brique :" << endl;
    for(std::vector<DefFonction*>::iterator it = vectorDefinitionFonction.begin() ; it != vectorDefinitionFonction.end() ; it++)
    {
    	(*it)->print();
    }
    for(std::vector<DeclarationFonction*>::iterator it = vectorDeclarationFonction.begin() ; it != vectorDeclarationFonction.end() ; it++)
    {
    	(*it)->print();
    }
    for(std::vector<Declaration*>::iterator it = vectorDeclaration.begin() ; it != vectorDeclaration.end() ; it++)
    {
    	(*it)->print();
    }

}