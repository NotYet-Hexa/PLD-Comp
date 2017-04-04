/*************************************************************************
PLD Comp
Brique.cpp  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Réalisation de la classe Brique (fichier Brique.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Brique.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques




TypeBrique Brique::getTypeBrique()
{
    return typeBrique;
}


//----- Constructeur
Brique::Brique()
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Brique::~Brique()
{
    cout << "destructeur de Brique" << endl;
}// Bloc vide
//----- Fin destructeur
