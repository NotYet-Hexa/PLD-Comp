/*************************************************************************
PLD Comp
ExpressionBinaire.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe ExpressionBinaire (fichier ExpressionBinaire.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "ExpressionBinaire.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void ExpressionBinaire::print()
{
    gauche->print();
    cout << symbole << endl;
    droite->print();
}
//----- Constructeur
ExpressionBinaire::ExpressionBinaire(Expression* g, Expression* d, string s) :
    gauche(g), droite(d), symbole(s)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ExpressionBinaire::~ExpressionBinaire()
{}// Bloc vide
//----- Fin destructeur