/*************************************************************************
/*************************************************************************
PLD Comp
ArgsAppel.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe ArgsAppel (fichier ArgsAppel.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "ArgsAppel.h"
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void ArgsAppel::print()
{
    cout << "ArgumentAppel : "<<endl;
    if(!args.empty())
    {
        for(vector<Expression*>::iterator it = args.begin(); it != args.end(); it++)
        {
            (*it)->print();
        }
    }
    else 
    {
        cout<<"empty"<<endl;
    }
}

void ArgsAppel::add(Expression* expression)
{
    args.push_back(expression);
}

//----- Constructeur
ArgsAppel::ArgsAppel()
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ArgsAppel::~ArgsAppel()
{}// Bloc vide
//----- Fin destructeur