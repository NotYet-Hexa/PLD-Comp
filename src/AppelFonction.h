/*************************************************************************
PLD Comp
AppelFonction.h  -  Description
-------------------
début                : 23/02/2017
copyright            : (C)2017 par H4414
*************************************************************************/

//---------- Interface de la classe Declaration (fichier Declaration.h) ------
#if ! defined ( APPELFONCTION_H )
#define APPELFONCTION_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Programme.h"
#include "ArgsAppel.h"
#include "Expression.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe AppelFonction:
//

//------------------------------------------------------------------------

class AppelFonction : public Expression 
{
    public:
        void print();
        std::list<string> listeNomLValue();
        AppelFonction(string nom_fonction, ArgsAppel* args);
        ~AppelFonction();
        string getNomFonction();

    private:
        string nomFonction;
        ArgsAppel* argsAppel;
};

#endif // if ! defined APPELFONCTION_H