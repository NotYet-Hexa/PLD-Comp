/*************************************************************************
PLD Comp
Brique.h  -  Description
-------------------
début                : 29/03/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/

//---------- Interface de la classe Brique (fichier Brique.h) ------
#if ! defined ( BRIQUE_H )
#define BRIQUE_H

#include "DefFonction.h"
#include "DeclarationFonction.h"
#include "Declaration.h"

using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Brique:
//

//------------------------------------------------------------------------

class Brique{
    public:
    	void print();
        Brique();
        ~Brique();
        void addDefFonction(DefFonction* d);
        void addDecFonction(DeclarationFonction* d);
        void addDeclaration(Declaration* d);

    private:
    	std::vector<DefFonction*> vectorDefinitionFonction;
    	std::vector<DeclarationFonction*> vectorDeclarationFonction;
    	std::vector<Declaration*> vectorDeclaration;


};

#endif // if ! defined BRIQUE_H