/*************************************************************************
PLD Comp
Briques.cpp  -  Description
-------------------
début                : 27/03/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/

//---------- Réalisation de la classe Briques (fichier Briques.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Briques.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques



Briques::Briques()
{
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Briques::~Briques()
{}// Bloc vide
//----- Fin destructeur

void Briques::add(DefFonction* d)
{
	// vectorDefinitionFonction.push_back(d);
    vectorBrique.push_back(d);
}

void Briques::add(DeclarationFonction* d)
{
	// vectorDeclarationFonction.push_back(d);
    vectorBrique.push_back(d);
}

void Briques::add(DeclarationGlobal* d)
{
	// vectorDeclarationGlobal.push_back(d); 
    vectorBrique.push_back(d);  
}

void Briques::print()
{
	cout << "Debut de briques" << endl;
    //  if( !vectorDefinitionFonction.empty() )
    // {
    //     for(std::vector<DefFonction*>::iterator it = vectorDefinitionFonction.begin() ; it != vectorDefinitionFonction.end() ; it++)
    //     {
    //        (*it)->print();
    //     }
    // }



    // if( !vectorDeclarationFonction.empty() )
    // {
    //     for(std::vector<DeclarationFonction*>::iterator it = vectorDeclarationFonction.begin() ; it != vectorDeclarationFonction.end() ; it++)
    //     {
    //         (*it)->print();
    //     }
    // }


    //  if( !vectorDeclarationGlobal.empty() )
    //     {
    //         for(std::vector<DeclarationGlobal*>::iterator it = vectorDeclarationGlobal.begin(); it != vectorDeclarationGlobal.end(); ++it)
    //         {
    //                 (*it)->print();
    //         }
    //     }

         if( !vectorBrique.empty() )
        {
            for(std::vector<Brique*>::iterator it = vectorBrique.begin(); it != vectorBrique.end(); ++it)
            {
                    (*it)->print();
            }
        }
    cout << "Fin de briques" << endl;
}