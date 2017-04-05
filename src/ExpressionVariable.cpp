/*************************************************************************
PLD Comp
ExpressionVariable.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe ExpressionVariable (fichier ExpressionVariable.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "ExpressionVariable.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


std::list<string> ExpressionVariable::listeNomLValue()
{
    list<string> list;
    list.push_back(nomVariable);
    return list;
}

string ExpressionVariable::get_nomVariable(){return nomVariable;}

void ExpressionVariable::print()
{
    // Ajouter la valeur après les :
    cout << "variable : " << nomVariable << endl;
}
//----- Constructeur
ExpressionVariable::ExpressionVariable(string nom) : nomVariable(nom)
{
    //this->type_expression = Expression::TypeExpression::Variable;
    this->type_expression = Expression::TypeExpression::Type_ExpressionVariable;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ExpressionVariable::~ExpressionVariable()
{}// Bloc vide
//----- Fin destructeur

InstructionVraieClass ExpressionVariable::typeClass()
{
    return InstructionVraieClass::expressionVariable;
}
