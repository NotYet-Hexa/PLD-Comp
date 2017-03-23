/*************************************************************************
PLD COMP
Contexte.cpp  -  Description
-------------------
début                : 20/03/2017
copyright            : (C)2017 par H4114
*************************************************************************/

//---------- Réalisation de la classe Contexte (fichier Contexte.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream> //String

using namespace std;

//------------------------------------------------------ Include personnel
#include "Contexte.h"

//---------------------------------------------------- Variables de classe
typedef unordered_map<string,string>* tableDesVariables;
//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//----- Constructeur
Contexte::Contexte()
{}// Bloc Vide
Contexte::Contexte(string nomContexte)
{
    this->nomContexte = nomContexte;
    tableDesVariables table;
    //this->tableDesSymboles.insert(this,table);
}
//----- Fin constructeur

//----- Destructeur
Contexte::~Contexte()
{}// Bloc vide
//----- Fin destructeur

/*
int Contexte::ajouterVariable(Contexte* contexteCourant,string nomVariable,string typeVariable)
{
    if(chercherVariable(contexteCourant,nomVariable))
    {
        return -1; // Erreur
    }
    else
    {
        unordered_map<Contexte*,unordered_map<string,string> >::const_iterator iterateurContexte = this->tableDesSymboles.find(contexteCourant);
        unordered_map<string,string> tableVariable = iterateurContexte->second;
        //tableVariable.insert(nomVariable,typeVariable);
        return 0; // Succes
    }
    
}
*/

/*
bool Contexte::chercherVariable(Contexte* contexteCourant,string nomVariable)
{
    unordered_map<Contexte*,unordered_map<string,string> >::const_iterator iterateurContexte = this->tableDesSymboles.find(contexteCourant);
    if (iterateurContexte == this->tableDesSymboles.end())
        return false; // Le Contexte n'existe pas
    else
    {
        unordered_map<string,string> tableVariable = iterateurContexte->second;
        unordered_map<string,string> ::const_iterator iterateurVariable = tableVariable.find(nomVariable);
        if(iterateurVariable == tableVariable.end())
            return false; // La variable n'existe pas dans le contexte
        else
            return true;
    }
}
*/