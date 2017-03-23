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
unordered_map<Contexte*,unordered_map<string,string>* > Contexte::tableDesSymboles;

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

//----- Constructeur
Contexte::Contexte()
{}// Bloc Vide

Contexte::Contexte(string nomContexte)
{
    cout << "Constructeur" << endl;
    this->nomContexte = nomContexte;
    unordered_map<string,string >* tableDesVariables = new unordered_map<string,string>();
    this->tableDesSymboles.insert(std::make_pair(this,tableDesVariables));
}
//----- Fin constructeur

//----- Destructeur
Contexte::~Contexte()
{
    unordered_map<Contexte*,unordered_map<string,string>* >::const_iterator iterateurContexte = this->tableDesSymboles.find(this);
    unordered_map<string,string>* tableVariables = iterateurContexte->second;

    //Nettoyage des donnees
    tableVariables->clear(); 
    delete(tableVariables);
    this->tableDesSymboles.erase(this); 

    cout << "Destructeur" << endl;
}// Bloc vide
//----- Fin destructeur


int Contexte::ajouterVariable(string nomVariable,string typeVariable)
{
    if(chercherVariable(nomVariable))
    {
        return -1; // Erreur
    }
    else
    {
        unordered_map<Contexte*,unordered_map<string,string>* >::const_iterator iterateurContexte = this->tableDesSymboles.find(this);
        unordered_map<string,string>* tableVariables = iterateurContexte->second;
        pair<string,string> variable (nomVariable,typeVariable);
        tableVariables->insert(variable);
        return 0; // Succes
    }
    
}
bool Contexte::chercherVariable(string nomVariable)
{
    unordered_map<Contexte*,unordered_map<string,string>* >::const_iterator iterateurContexte = this->tableDesSymboles.find(this);
    if (iterateurContexte == this->tableDesSymboles.end())
        return false; // Le Contexte n'existe pas
    else
    {
        unordered_map<string,string>* tableVariable = iterateurContexte->second;
        unordered_map<string,string> ::const_iterator iterateurVariable = tableVariable->find(nomVariable);
        if(iterateurVariable == tableVariable->end())
            return false; // La variable n'existe pas dans le contexte
        else
            return true;
    }
}
string Contexte::getNomContexte()
{
    return this->nomContexte;
}

void Contexte::test_AfficherTableDesSymboles()
{
    if(tableDesSymboles.empty())
        cout << "Aucun Contexte Instancie";
    else
    {
        for (unordered_map<Contexte*,unordered_map<string,string>* >::iterator itContexte= tableDesSymboles.begin(); itContexte!= tableDesSymboles.end(); ++itContexte)
        {
            cout << itContexte->first->getNomContexte() << endl;
            cout << "=========================" << endl;
            unordered_map<string,string> mapdd = *itContexte->second;
            for (unordered_map<string,string>::iterator itVariable= itContexte->second->begin(); itVariable!= itContexte->second->end(); ++itVariable)
            {
                cout << itVariable->first << "|" << itVariable->second << endl;
            }
            cout << endl;
        }
    }
        
}