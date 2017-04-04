/*************************************************************************
PLD Comp
ExpressionUnaire.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe ExpressionUnaire (fichier ExpressionUnaire.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Expression.h"
#include "ExpressionUnaire.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

std::list<string> ExpressionUnaire::listeNomLValue()
{
    std::list<string> list = expression->listeNomLValue();
    return list;
}

void ExpressionUnaire::print()
{
    expression->print();
    cout << symbole << endl;
}
//----- Constructeur
ExpressionUnaire::ExpressionUnaire(Expression* exp, string s) : expression(exp), symbole(s)
{
    this->type_expression = Expression::TypeExpression::Type_Unaire;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ExpressionUnaire::~ExpressionUnaire()
{}// Bloc vide
//----- Fin destructeur