/*************************************************************************
PLD Comp
ExpressionUnaire.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//Réalisation de la classe ExpressionUnaire (fichier ExpressionUnaire.cpp)

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "ExpressionUnaire.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

list<string> ExpressionUnaire::listeNomLValue()
{
    std::list<string> list = this->expression->listeNomLValue();
    return list;
}

string ExpressionUnaire::get_symbole()
{ 
    return symbole;
}

Expression* ExpressionUnaire::get_expression()
{
    return expression;
}


void ExpressionUnaire::print()
{
    cout << "Expression Unaire :" << symbole << endl;
    expression->print();
}
//----- Constructeur
ExpressionUnaire::ExpressionUnaire(Expression* e, string s) : expression(e), symbole(s)
{
    //this->type_expression = Expression::TypeExpression::Type_Unaire;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ExpressionUnaire::~ExpressionUnaire()
{
    //cout << "Destructeur de ExpressionUnaire " << endl;
	delete this->expression;
}// Bloc vide
//----- Fin destructeur
