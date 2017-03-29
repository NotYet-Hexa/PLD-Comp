/*************************************************************************
PLD Comp
Briques.cpp  -  Description
-------------------
début                : 27/03/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/

//---------- Réalisation de la classe Briques (fichier Briques.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Briques.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//----- Constructeur
Briques::Briques()
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Briques::~Briques()
{}// Bloc vide
//----- Fin destructeur

void Briques::add(DefFonction* d)
{
	vectorDefinitionFonction.push_back(d);
}

void Briques::add(DeclarationFonction* d)
{
	vectorDeclarationFonction.push_back(d);
}

void Briques::add(Declaration* d)
{
	vectorDeclaration.push_back(d);
}

void Briques::print()
{
	cout << "Briques :" << endl;
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