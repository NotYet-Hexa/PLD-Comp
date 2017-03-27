/*************************************************************************
PLD COMP
Programme.cpp  -  Description
-------------------
début                : 20/03/2017
copyright            : (C)2017 par H4114
*************************************************************************/

//---------- Réalisation de la classe Programme (fichier Programme.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Programme.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//----- Constructeur
Programme::Programme():Contexte("Programme")
{}// Bloc vide
//----- Fin constructeur

//----- Constructeur
Programme::Programme(vector <Contexte*> listeDeContexte):Contexte("Programme")
{
    this->listeDeContexte = listeDeContexte;
    
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Programme::~Programme()
{}// Bloc vide
//----- Fin destructeur


vector <Contexte*> Programme::getListeDeContexte()
{
    return this->listeDeContexte;
}