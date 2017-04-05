/*************************************************************************
PLD Comp
LoopStatement.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe LoopStatement (fichier LoopStatement.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel

#include "LoopStatement.h"
#include "InstructionVraie.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


void LoopStatement::print()
{
    // gerrer while ou for
    if(this->typeLoop == LoopStatement::TLwhile)
    {
        cout << "while :" << endl;
        this->expression1->print();
        this->instruction->print();
    }
    if(this->typeLoop == LoopStatement::TLfor)
    {
        cout << "for :" << endl << "e1: ";
        this->expression1->print();
        cout << "e2: ";
        this->expression2->print();
        cout << "e3: ";
        this->expression3->print();
        this->instruction->print();
    }
}

void LoopStatement::checkContexte(Contexte* contexteCourant )
{
    if(this->typeLoop == LoopStatement::TLwhile)
    {
        list<string> listLValueUtilisees = this->expression1->listeNomLValue();
        for(list<string>::iterator it = listLValueUtilisees.begin(); it != listLValueUtilisees.end(); ++it) 
        {
            if(!contexteCourant->chercherVariable( (*it)))
            {
                cout << "la variable  \" " << (*it) 
                    << " \" est utiliser mais n'est pas déclarée " << endl;
            }
        }
    }

    if(this->typeLoop == LoopStatement::TLfor)
    {
        list<string> listLValueUtilisees = this->expression1->listeNomLValue();
        for(list<string>::iterator it = listLValueUtilisees.begin(); it != listLValueUtilisees.end(); ++it) 
        {
            if(!contexteCourant->chercherVariable( (*it)))
            {
                cout << "la variable  \" " << (*it) 
                    << " \" est utiliser mais n'est pas déclarée " << endl;
            }
        }


        listLValueUtilisees = this->expression2->listeNomLValue();
        for(list<string>::iterator it = listLValueUtilisees.begin(); it != listLValueUtilisees.end(); ++it) 
        {
            if(!contexteCourant->chercherVariable( (*it)))
            {
                cout << "la variable  \" " << (*it) 
                    << " \" est utiliser mais n'est pas déclarée " << endl;
            }
        }

        listLValueUtilisees = this->expression3->listeNomLValue();
        for(list<string>::iterator it = listLValueUtilisees.begin(); it != listLValueUtilisees.end(); ++it) 
        {
            if(!contexteCourant->chercherVariable( (*it)))
            {
                cout << "la variable  \" " << (*it) 
                    << " \" est utiliser mais n'est pas déclarée " << endl;
            }
        }
    }

    // Il faudra faire cela dans tous les cas    
    this->instruction->checkContexte(contexteCourant);

    
}

//----- Constructeur
LoopStatement::LoopStatement(Expression* monExpression,Instruction* monInstruction): 
    expression1(monExpression), instruction(monInstruction)
{
    this->typeInstruction = InstructionVraie::TIloop;
    this->typeLoop = LoopStatement::TLwhile;
}

LoopStatement::LoopStatement(Expression* monExpression1, Expression* monExpression2,
     Expression* monExpression3, Instruction* monInstruction):expression1(monExpression1),
     expression2(monExpression2),expression3(monExpression3),instruction(monInstruction)
{
    this->typeInstruction = InstructionVraie::TIloop;
    this->typeLoop = LoopStatement::TLfor;
}
        
//----- Fin constructeur

//----- Destructeur
LoopStatement::~LoopStatement()
{
    //cout << "Destructeur de LoopStatement " << endl;
    // for et while 
    if(this->typeLoop == LoopStatement::TLwhile)
    {
        delete this->expression1;
        delete this->instruction;
    }
    else
    {
        delete this->expression1;
        delete this->expression2;
        delete this->expression3;
        delete this->instruction;
    }
}
//----- Fin destructeur
