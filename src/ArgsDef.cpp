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
#include <vector>

using namespace std;

//------------------------------------------------------ Include personnel
#include "ArgsDef.h"
#include "Declaration.h"
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

list<string> ArgsDef::getListNomParam()
{
    list<string> listNomParam;
    for(vector<Declaration*>::iterator it = args.begin(); it != args.end(); it++)
        {
            listNomParam.push_back((*it)->getNom());
        }
    return listNomParam;
}


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
{
    //cout << "Constructeur de Affectation" << endl;
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
ArgsDef::~ArgsDef()
{
    //cout << "Destructeur de ArgsDef " << endl;
    if(!args.empty())
    {
        for (vector<Declaration*>::iterator it = args.begin(); it != args.end(); it++)
        {
            delete (*it);
        }
    }
	
	args.clear();
}// Bloc vide
//----- Fin destructeur