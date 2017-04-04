/*************************************************************************
PLD Comp
Affectation.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe Affectation (fichier Affectation.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel


#include "Affectation.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
string Affectation::get_symbole()
{
    return symbole;
}

Expression* Affectation::get_expression()
{
    return expression;
}

string Affectation::get_nom_variable()
{
    return nomVariable;
}

std::list<string> Affectation::listeNomLValue()
{
    list<string> list;
    list.push_back(nomVariable);
    list.merge(expression->listeNomLValue());
    return list;
}

void Affectation::print()
{
    cout << "Affectation :" << endl;
    cout << "nom :" << nomVariable << endl;
    cout << "symbole :" << symbole << endl;
    cout << "expression :" << endl;
    expression->print();
}

//----- Constructeur
Affectation::Affectation(string nomVar, string monSymbole, Expression* monExpression):nomVariable(nomVar), symbole(monSymbole), expression(monExpression)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Affectation::~Affectation()
{
	delete this->expression;
}
//----- Fin destructeur
