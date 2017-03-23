/*************************************************************************
PLD COMP
Contexte.h  -  Description
-------------------
début                : 20/03/2017
copyright            : (C)2017 par H4114
*************************************************************************/

//---------- Interface de la classe Contexte (fichier Contexte.h) ------
#if ! defined ( CONTEXTE_H )
#define CONTEXTE_H


//--------------------------------------------------- Interfaces utilisées
#include <unordered_map> //unordered_map
#include <iostream> // String
using namespace std;
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Contexte:
//

//------------------------------------------------------------------------

class Contexte{
    public:
        Contexte();
        Contexte(string Name);
        ~Contexte();
        

    private:
        string nomContexte;
        
    protected:
        static unordered_map<Contexte*,unordered_map<string,string>* > tableDesSymboles;
        //typedef unordered_map<Contexte*,unordered_map<string,string> > tableDesSymboles;

        //int ajouterVariable(Contexte*,string nomVariable,string typeVariable);
        //bool chercherVariable(Contexte*,string nomVariable); 
        

};

#endif // if ! defined CONTEXTE_H
