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
#include <unordered_map> //unordered_map
using namespace std;

//------------------------------------------------------ Include personnel
#include "Contexte.h"

//---------------------------------------------------- Variables de classe
typedef unordered_map<Contexte*,unordered_map<string,string>* > MapContexte;
typedef unordered_map<string,string> MapVariable;
MapContexte Contexte::tableDesSymboles;

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Contexte::print()
{
    cout << "Probleme implémenter print pour ce context" << endl;
}


//----- Constructeur
Contexte::Contexte()
{}// Bloc Vide

Contexte::Contexte(string nomContexte)
{
    this->nomContexte = nomContexte;
    this->parent = nullptr;
    MapVariable* tableDesVariables = new unordered_map<string,string>();
    this->tableDesSymboles.insert(std::make_pair(this,tableDesVariables));
}
//----- Fin constructeur

//----- Destructeur
Contexte::~Contexte()
{
    MapContexte::const_iterator iterateurContexte = this->tableDesSymboles.find(this);
    MapVariable* tableVariables = iterateurContexte->second;

    //Nettoyage des donnees
    //tableVariables->clear(); 
    //delete(tableVariables);
    //this->tableDesSymboles.erase(this); 
}// Bloc vide
//----- Fin destructeur

string Contexte::getNomContexte()
{
    return this->nomContexte;
}


int Contexte::ajouterVariable(string nomVariable,string typeVariable)
{
    if(chercherVariable(nomVariable))
    {
        return -1; // Erreur
    }
    else
    {
        MapContexte::const_iterator iterateurContexte = this->tableDesSymboles.find(this);
        MapVariable* tableVariables = iterateurContexte->second;
        pair<string,string> variable (nomVariable,typeVariable);
        tableVariables->insert(variable);
        return 0; // Succes
    }
    
}
bool Contexte::chercherVariable(string nomVariable)
{
    MapContexte::const_iterator iterateurContexte = this->tableDesSymboles.find(this);
    if (iterateurContexte == this->tableDesSymboles.end())
        return false; // Le Contexte n'existe pas
    else
    {
        MapVariable* tableVariable = iterateurContexte->second;
        MapVariable::const_iterator iterateurVariable = tableVariable->find(nomVariable);
        if(iterateurVariable == tableVariable->end())
            return false; // La variable n'existe pas dans le contexte
        else
            return true;
    }
}

void Contexte::ajouterParent(Contexte* contexte)
{
    this->parent = contexte;
}

// ---------------------------------------------------------------------------------------- //
// ----------------------------------- FONCTION DE TEST ----------------------------------- //
// ---------------------------------------------------------------------------------------- //

void Contexte::test_AfficherTableDesSymboles()
{
    if(tableDesSymboles.empty())
        cout << "Aucun Contexte Instancie";
    else
    {
        for (MapContexte::iterator itContexte= tableDesSymboles.begin(); itContexte!= tableDesSymboles.end(); ++itContexte)
        {
            cout << itContexte->first->getNomContexte() << endl;
            cout << "=========================" << endl;
            MapVariable mapdd = *itContexte->second;
            for (MapVariable::iterator itVariable= itContexte->second->begin(); itVariable!= itContexte->second->end(); ++itVariable)
            {
                cout << itVariable->first << "|" << itVariable->second << endl;
            }
            cout << endl;
        }
    }
        
}