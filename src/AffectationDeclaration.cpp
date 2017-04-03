/*************************************************************************
PLD Comp
AffectationDeclaratino.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe AffectationDeclaratino (fichier AffectationDeclaratino.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel


#include "AffectationDeclaration.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void AffectationDeclaration::print()
{
    cout << "AffectationDeclaration :" << endl;
    expression->print();
}

//----- Constructeur
AffectationDeclaration::AffectationDeclaration( Expression* monExpression): expression(monExpression)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
AffectationDeclaration::~AffectationDeclaration()
{

}
//----- Fin destructeur
