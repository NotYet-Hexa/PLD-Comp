/*************************************************************************
PLD Comp
DefFonction.h  -  Description
-------------------
début                : 27/03/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/

//---------- Interface de la classe DefFonction (fichier DefFonction.h) ------
#if ! defined ( DEFFONCTION_H )
#define DEFFONCTION_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include "Contexte.h"
#include "Bloc.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe DefFonction:
//

//------------------------------------------------------------------------

class DefFonction : public Contexte {
    public:
        void print();
        DefFonction(Bloc* bloc, ArgsDef* args, string nomFonction);
        ~DefFonction();

    private:
    	string type;
        string nomFonction;
        Bloc* bloc;
        ArgsDef* args;
};

#endif // if ! defined DEFFONCTION_H