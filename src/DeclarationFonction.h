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
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe DeclarationFonction:
//

//------------------------------------------------------------------------

class Declaration : public Programme {
    public:
        DeclarationFonction(string nf, string tr, ArgsDef ad);
        ~DeclarationFonction();
        getNomFonction();

    private:
        string nomFonction;
        string typeRetour;
        ArgsDef argsDef;
};

#endif // if ! defined DECLARATIONFONCTION_H