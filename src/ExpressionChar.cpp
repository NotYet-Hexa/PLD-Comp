/*************************************************************************
PLD Comp
ExpressionChar.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe ExpressionChar (fichier ExpressionChar.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Expression.h"
#include "ExpressionChar.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

std::list<string> ExpressionChar::listeNomLValue()
{
    std::list<string> list;
    return list;
}

void ExpressionChar::print()
{
    cout << "char : ";  
    cout << valeur << endl;
}

Expression::TypeExpression ExpressionChar::getType()
{
	return Expression::TypeExpression::Type_Char;
}

//----- Constructeur
ExpressionChar::ExpressionChar(char car) : valeur(car)
{
    this->type_expression = Expression::TypeExpression::Type_Char;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ExpressionChar::~ExpressionChar()
{
    //cout << "Destructeur de ExpressionChar " << endl;
}// Bloc vide
//----- Fin destructeur

InstructionVraieClass ExpressionChar::typeClass()
{
    return InstructionVraieClass::expressionChar;
}
