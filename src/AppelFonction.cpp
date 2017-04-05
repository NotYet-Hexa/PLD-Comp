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

Expression::TypeExpression AppelFonction::getType()
{
	return Expression::TypeExpression::Type_AppelFonction;
}


string AppelFonction::getNomFonction()
{
	return nomFonction;
}//----- Constructeur

AppelFonction::AppelFonction(string nf, ArgsAppel* ap):nomFonction(nf),argsAppel(ap)
{
	//cout << "Constructeur de AppelFonction" << endl;
}
//-----Bloc vide
//----- Fin constructeur

//----- Destructeur
AppelFonction::~AppelFonction()
{
	//cout << "Destructeur de AppelFonction " << endl;
	delete this->argsAppel;
}
//----- Fin destructeur

InstructionVraieClass AppelFonction::typeClass()
{
    return InstructionVraieClass::appelFonction;
}
