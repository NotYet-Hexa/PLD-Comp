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
    list.push_back(variable->getNom());
    return list;
}

string AffectationUnaire::get_nom_variable(){return variable->getNom();}

string AffectationUnaire::get_symbole(){return symbole;}

void AffectationUnaire::print()
{
    cout << "Affectation Unaire:" << endl;
    cout << "variable :";
    variable->print();
    cout << "symbole :" << symbole << endl;

}

//----- Constructeur
AffectationUnaire::AffectationUnaire(LValue* var, string monSymbole):variable(var), symbole(monSymbole)
{
    //cout << "Constructeur de AffectationUnaire" << endl;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
AffectationUnaire::~AffectationUnaire()
{
    //cout << "Destructeur de AffectationUnaire" << endl;
    delete variable;
}
//----- Fin destructeur
