/*************************************************************************
PLD Comp
DeclarationGlobal.cpp  -  Description
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
#include "DeclarationGlobal.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
string DeclarationGlobal::get_type(){return Declaration::type;}
string DeclarationGlobal::get_nom(){return Declaration::nom;}
bool DeclarationGlobal::get_tab(){return Declaration::isTab;}
int DeclarationGlobal::get_size(){return Declaration::size;}
//----- Constructeur
DeclarationGlobal::DeclarationGlobal(string t, string n, bool isT, int s):type(t),nom(n),isTab(isT), size(s)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
DeclarationGlobal::~DeclarationGlobal()
{}// Bloc vide
//----- Fin destructeur

void DeclarationGlobal::print()
{
	cout << "DeclarationGlobal : type ->" << type << "  |  nom -> " << nom ;
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

