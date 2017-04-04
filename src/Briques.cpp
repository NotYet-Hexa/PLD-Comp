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
#include <vector>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Briques.h"
#include "DefFonction.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Briques::checkContexte(Contexte* programme)
{
    for(std::vector<Brique*>::iterator it = vectorBrique.begin(); it != vectorBrique.end(); ++it)
    {
        if((*it)->getTypeBrique() == TBdefFonction)
        {

            ((DefFonction * )(*it))->ajouterParent(programme);
            ((DefFonction * )(*it))->checkContexte();
        }
        if((*it)->getTypeBrique() == TBdec)
        {
           programme->ajouterVariable( ((DeclarationGlobal * )(*it))->getNom() , "int64_t" );

           
        }
    }
}

Briques::Briques()
{
}// Bloc vide
//----- Fin constructeur

//----- Destructeur
Briques::~Briques()
{
	for (vector<Brique*>::iterator it = vectorBrique.begin(); it != vectorBrique.end(); it++)
	{
		delete *it;
	}
	vectorBrique.clear();
}// Bloc vide
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

vector<Brique*> Briques::getListBrique()
{
    return this->vectorBrique;
}


void Briques::print()
{
	cout << "Debut de briques" << endl;
  

         if( !vectorBrique.empty() )
        {
            for(std::vector<Brique*>::iterator it = vectorBrique.begin(); it != vectorBrique.end(); ++it)
            {
                    (*it)->print();
            }
        }
    cout << "Fin de briques" << endl;
}