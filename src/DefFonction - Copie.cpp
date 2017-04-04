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
#include <string>

using namespace std;

//------------------------------------------------------ Include personnel
#include "DefFonction.h"


//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//----- Constructeur
DefFonction::DefFonction(string type, Bloc* bloc, ArgsDef* args, string nomFonction):
	Contexte("DefFonction"), nomFonction(nomFonction), type(type)
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
	args->print();
	bloc->print();
}

string DefFonction::getNomFonction() { return nomFonction; }

Bloc* DefFonction::getBloc(){ return bloc; }

ArgsDef* DefFonction::getArgs(){ return args; }

string DefFonction::get_type(){return type;}