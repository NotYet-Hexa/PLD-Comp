/*************************************************************************
PLD Comp
Outils.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe Outils (fichier Outils.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel


#include "Outils.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

Outils::TypeSymbole Outils::parse_symb(string symbole)
{
	if (symbole == "+")
	{
		return Outils::TypeSymbole::plus;
	}
	else if (symbole == "-")
	{
		return Outils::TypeSymbole::moins;
	}
	else if (symbole == "*")
	{
		return Outils::TypeSymbole::multi;
	}
	else if (symbole == "/")
	{
		return Outils::TypeSymbole::divis;
	}
	else if (symbole == "=")
	{
		return Outils::TypeSymbole::egal;
	}
	else if (symbole == "(")
	{
		return Outils::TypeSymbole::parentouv;
	}
	else if (symbole == ")")
	{
		return Outils::TypeSymbole::parentFerm;
	}
	else if (symbole == "{")
	{
		return Outils::TypeSymbole::accolouv;
	}
	else if (symbole == "}")
	{
		return Outils::TypeSymbole::accoferm;
	}
	else if (symbole == "[")
	{
		return Outils::TypeSymbole::crochetouv;
	}
	else if (symbole =="]")
	{
		return Outils::TypeSymbole::crochetferm;
	}
	else if (symbole == "++")
	{
		return Outils::TypeSymbole::plusplus;
	}
	else if (symbole == "--")
	{
		return Outils::TypeSymbole::moinsmoins;
	}
	else if (symbole == "+=")
	{
		return Outils::TypeSymbole::plusegal;
	}
	else if (symbole == "-=")
	{
		return Outils::TypeSymbole::moinsegal;
	}
	else if (symbole == "/=")
	{
		return Outils::TypeSymbole::divegal;
	}
	else if (symbole == "*=")
	{
		return Outils::TypeSymbole::mulegal;
	}
	else if (symbole == "%=")
	{
		return Outils::TypeSymbole::moduloegal;
	}
	else if (symbole == "<<=")
	{
		return Outils::TypeSymbole::decalgaucheegal;
	}
	else if (symbole == ">>=")
	{
		return Outils::TypeSymbole::decaldroiteegal;
	}
	else if (symbole == "^")
	{
		return Outils::TypeSymbole::xorbinaire;
	}
	else if (symbole == "<<")
	{
		return Outils::TypeSymbole::decalgauche;
	}
	else if (symbole == ">>")
	{
		return Outils::TypeSymbole::decaldroite;
	}
}




//----- Constructeur
Outils::Outils()
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Outils::~Outils()
{

}
//----- Fin destructeur
