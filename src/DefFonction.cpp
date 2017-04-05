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

void DefFonction::checkContexte()
{
	//Ajout des paramatre au variable associé au contexte
	list<string> listNomParam = args->getListNomParam();

	for(list<string>::iterator it = listNomParam.begin(); it != listNomParam.end(); ++it) 
	{
		this->ajouterVariable( (*it) , "int64_t" );
	}
	
	
	this->bloc->checkContexte(this);
}

//----- Constructeur
DefFonction::DefFonction(string type, Bloc* bloc, ArgsDef* args, string nomFonction):
	Contexte("DefFonction"), nomFonction(nomFonction), type(type)
{
	this->bloc = bloc;
	this->args = args;
	this->typeBrique = TBdefFonction;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
DefFonction::~DefFonction()
{
	//cout << "Destructeur de Def Fonction " << endl;
	delete this->bloc;
	delete this->args;
}// Bloc vide
//----- Fin destructeur

void DefFonction::print()
{
	cout << "DefFonction : nom ->" << nomFonction << endl;
	args->print();
	bloc->print();
}

string DefFonction::getNomFonction() { return this->nomFonction; }

Bloc* DefFonction::getBloc(){ return this->bloc; }

ArgsDef* DefFonction::getArgs(){ return this->args; }


typeClassBrique DefFonction::typeClass()
{
	return typeClassBrique::defFonction;
}