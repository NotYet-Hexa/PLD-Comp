/*************************************************************************
PLD Comp
ArgsDef.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe ArgsDef (fichier ArgsDef.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "ArgsDef.h"
#include "Declaration.h"
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void ArgsDef::print()
{
    cout << "ArgumentDef : "<<endl;
    if(!args.empty())
    {
        for(vector<Declaration*>::iterator it = args.begin(); it != args.end(); it++)
        {
            (*it)->print();
        }
    }
    else 
    {
        cout<<"empty"<<endl;
    }
}

void ArgsDef::add(Declaration* declaration)
{
    args.push_back(declaration);
}

//----- Constructeur
ArgsDef::ArgsDef()
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ArgsDef::~ArgsDef()
{}// Bloc vide
//----- Fin destructeur