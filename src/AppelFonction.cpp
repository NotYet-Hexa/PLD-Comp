/*************************************************************************
PLD Comp
AppelFonction.cpp  -  Description
-------------------
début                : 23/02/2017
copyright            : (C)2015 par H4414
*************************************************************************/

//---------- Réalisation de la classe Declaration (fichier AppelFonction.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "AppelFonction.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

list<string> AppelFonction::listeNomLValue()
{
	list<string> list;
	return list;
}

void AppelFonction::print()
{
	cout<<"Debut d'appel de Fonction"<<endl;
	cout<<"nom fonction : "<<nomFonction<<endl;
	argsAppel->print();
}




string AppelFonction::getNomFonction()
{
	return nomFonction;
}//----- Constructeur

AppelFonction::AppelFonction(string nf, ArgsAppel* ap):nomFonction(nf),argsAppel(ap)
{
	this->type_expression = Expression::TypeExpression::Type_AppelFonction;
}
//-----Bloc vide
//----- Fin constructeur

//----- Destructeur
AppelFonction::~AppelFonction()
{
	//delete this->argsAppel;
}// Bloc vide
//----- Fin destructeur

InstructionVraieClass AppelFonction::typeClass()
{
    return InstructionVraieClass::appelFonction;
}
