/*************************************************************************
PLD Comp
Cond.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe Cond (fichier Cond.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "Cond.h"
#include "InstructionVraie.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

list<string> Cond::listeNomLValue()
{
    return this->expression->listeNomLValue();
}

void Cond::print()
{
    cout << "Cond :" << endl;
    this->expression->print();
    this->instruction->print();
    this->condSuite->print();
}

void Cond::checkContexte(Contexte* contexteCourant )
{
    list<string> listLValueUtilisees = this->expression->listeNomLValue();
    for(list<string>::iterator it = listLValueUtilisees.begin(); it != listLValueUtilisees.end(); ++it) 
    {
        if(!contexteCourant->chercherVariable( (*it)))
        {
            cout << "la variable  \" " << (*it) 
                << " \" est utiliser mais n'est pas déclarée " << endl;
        }
    }
    
    this->instruction->checkContexte(contexteCourant);
    this->condSuite->checkContexte(contexteCourant);
    
}

//----- Constructeur
Cond::Cond(Expression* monExpression,Instruction* monInstruction, CondSuite* maCondSuite): expression(monExpression), instruction(monInstruction), condSuite(maCondSuite)
{
    this->typeInstruction = InstructionVraie::TIcond;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Cond::~Cond()
{
    //cout << "Destructeur de Cond " << endl;
	delete this->expression;
	delete this->instruction;
	delete this->condSuite;
}
//----- Fin destructeur
