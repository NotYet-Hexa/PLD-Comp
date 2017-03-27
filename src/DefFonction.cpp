/*************************************************************************
PLD Comp
DefFonction.cpp  -  Description
-------------------
début                : 27/03/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/

//---------- Réalisation de la classe DefFonction (fichier DefFonction.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "DefFonction.h"


//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//----- Constructeur
DefFonction::DefFonction(Bloc* bloc, ArgsDef* args, string nomFonction):Contexte("DefFonction"),nomFonction(nom)
{
	this->bloc = bloc;
	this->args = args;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
DefFonction::~DefFonction()
{}// Bloc vide
//----- Fin destructeur

void DefFonction::print()
{
	cout << "DefFonction : nom ->" << nomFonction << endl;
}

string DefFonction::getNomFonction() { return this->nomFonction; }

Bloc* DefFonction::getBloc(){ return this->bloc; }

ArgsDef* DefFonction::getArgs(){ return this->args; }