/*************************************************************************
PLD Comp
DeclarationFonction.h  -  Description
-------------------
début                : 23/02/2017
copyright            : (C)2017 par H4414
*************************************************************************/

//---------- Interface de la classe Declaration (fichier Declaration.h) ------
#if ! defined ( DECLARATIONFONCTION_H )
#define DECLARATIONFONCTION_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include "Programme.h"
#include "ArgsDef.h"
#include "Brique.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe DeclarationFonction:
//

//------------------------------------------------------------------------

class DeclarationFonction : public Brique 
{
    public:
        void print();
        DeclarationFonction(string nom_fonction, string type_retour, ArgsDef* args);
        ~DeclarationFonction();
        string getNomFonction();

    private:
        string nomFonction;
        string typeRetour;
        ArgsDef* argsDef;
};

#endif // if ! defined DECLARATIONFONCTION_H