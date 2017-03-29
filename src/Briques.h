/*************************************************************************
PLD Comp
Briques.h  -  Description
-------------------
début                : 29/03/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/

//---------- Interface de la classe Briques (fichier Briques.h) ------
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
// Role de la classe Briques:
//

//------------------------------------------------------------------------
class DeclarationFonction;

class Briques{
    public:
    	void print();
        Briques();
        ~Briques();
        void add(DefFonction* d);
        void add(DeclarationFonction* d);
        void add(Declaration* d);

    private:
    	std::vector<DefFonction*> vectorDefinitionFonction;
    	std::vector<DeclarationFonction*> vectorDeclarationFonction;
    	std::vector<Declaration*> vectorDeclaration;


};

#endif // if ! defined BRIQUE_H