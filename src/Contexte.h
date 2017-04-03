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
        Contexte(string Nom);
        ~Contexte();
        virtual void print();
        int ajouterVariable(string nomVariable,string typeVariable);
        bool chercherVariable(string nomVariable);
        void ajouterParent(Contexte*);
        string getNomContexte();
        static void test_AfficherTableDesSymboles();
        string get_nomContexte();
        Contexte* get_contexte();

    private:
        string nomContexte;
        Contexte* parent;
        
    protected:
        static unordered_map<Contexte*,unordered_map<string,string>* > tableDesSymboles;

};

#endif // if ! defined CONTEXTE_H
