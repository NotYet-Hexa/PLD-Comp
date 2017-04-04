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
void AppelFonction::print()
{
	cout<<"Debut d'appel de Fonction"<<endl;
	cout<<"nom fonction : "<<nomFonction<<endl;
	argsAppel->print();
}

string AppelFonction::get_nomFonction(){return nomFonction;}

ArgsAppel* AppelFonction::get_argsAppel(){return argsAppel;}

Expression::TypeExpr AppelFonction::WhatIsThisExprType(){return Expression::TypeExpr::appelFonction;};

//----- Constructeur

AppelFonction::AppelFonction(string nf, ArgsAppel* ap):nomFonction(nf),argsAppel(ap)
{
}
//-----Bloc vide
//----- Fin constructeur

//----- Destructeur
AppelFonction::~AppelFonction()
{}// Bloc vide
//----- Fin destructeur
