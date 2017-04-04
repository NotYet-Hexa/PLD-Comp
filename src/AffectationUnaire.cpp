/*************************************************************************
PLD Comp
AffectationUnaireUnaire.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe AffectationUnaire (fichier AffectationUnaire.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel


#include "AffectationUnaire.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

std::list<string> AffectationUnaire::listeNomLValue()
{
    list<string> list;
    list.push_back(nomVariable);
    return list;
}

string AffectationUnaire::get_nom_variable(){return nomVariable;}

string AffectationUnaire::get_symbole(){return symbole;}

void AffectationUnaire::print()
{
    cout << "Affectation Unaire:" << endl;
    cout << "nom :" << nomVariable << endl;
    cout << "symbole :" << symbole << endl;

}

//----- Constructeur
AffectationUnaire::AffectationUnaire(string nomVar, string monSymbole):nomVariable(nomVar), symbole(monSymbole)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
AffectationUnaire::~AffectationUnaire()
{

}
//----- Fin destructeur
