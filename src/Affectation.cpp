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
    return variable->getNom();
}

std::list<string> Affectation::listeNomLValue()
{
    list<string> list;
    list.push_back(variable->getNom());
    list.merge(expression->listeNomLValue());
    return list;
}

void Affectation::print()
{
    cout << "Affectation :" << endl;
    cout << "variable :";
    variable->print();
    cout << "symbole :" << symbole << endl;
    cout << "expression :" << endl;
    expression->print();
}

InstructionVraieClass Affectation::typeClass()
{
    return InstructionVraieClass::affectation;
}

//----- Constructeur
Affectation::Affectation(LValue* var, string monSymbole, Expression* monExpression):variable(var), symbole(monSymbole), expression(monExpression)
{
    //cout << "Constructeur de Affectation" << endl;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Affectation::~Affectation()
{
    //cout << "Destructeur de Affectation " << endl;
    delete this->variable;
	delete this->expression;
}
//----- Fin destructeur
