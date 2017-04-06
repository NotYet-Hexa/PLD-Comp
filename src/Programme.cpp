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
// #include "const.h"
#include "Programme.h" 

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Programme::print()
{
    cout << "Debut du programme" << endl;
    this->briques->print();
    cout << "Fin du programme" << endl;
}

void Programme::checkContexte()
{
   // a faire plus bas dans brique
   briques->checkContexte(this);
}

//----- Constructeur
Programme::Programme():Contexte("Programme")
{}// Bloc vide
//----- Fin constructeur

//----- Constructeur
Programme::Programme(Briques* briques):Contexte("Programme")
{
    this->briques = briques;
}
//----- Fin constructeur

//----- Destructeur
Programme::~Programme()
{
    //cout << "Destructeur de Programme" << endl;
     delete this->briques ;
}
//----- Fin destructeur




Briques* Programme::getBriques()
{
    return this->briques;
}
