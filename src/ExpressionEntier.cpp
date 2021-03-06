/*************************************************************************
PLD Comp
ExpressionEntier.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe ExpressionEntier (fichier ExpressionEntier.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "ExpressionEntier.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
std::list<string> ExpressionEntier::listeNomLValue()
{
    std::list<string> list;
    return list;
}

int ExpressionEntier::get_valeur(){return valeur;}

void ExpressionEntier::print()
{
    cout << valeur << endl;
}

Expression::TypeExpression ExpressionEntier::getType()
{
	return Expression::TypeExpression::Type_Entier;
}

//----- Constructeur
ExpressionEntier::ExpressionEntier(int unint) : valeur(unint)
{
    this->type_expression = Expression::TypeExpression::Type_Entier;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ExpressionEntier::~ExpressionEntier()
{
    //cout << "Destructeur de ExtressionEntier " << endl;
}// Bloc vide
//----- Fin destructeur

InstructionVraieClass ExpressionEntier::typeClass()
{
    return InstructionVraieClass::expressionEntier;
}
