/*************************************************************************
PLD Comp
Briques.h  -  Description
-------------------
début                : 29/03/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/

//---------- Interface de la classe Briques (fichier Briques.h) ------
#if ! defined ( BRIQUES_H )
#define BRIQUES_H

#include "DefFonction.h"
#include "DeclarationFonction.h"
#include "DeclarationGlobal.h"
#include "Brique.h"
#include <vector>
#include <iterator>

using namespace std;
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Briques:
//

//------------------------------------------------------------------------
class DeclarationFonction; //Vraiment utile ?
class DeclarationGlobal;

class Briques{
    public:
    	void print();

        void checkContexte(Contexte * programme); 

        Briques();
        ~Briques();
        void add(DefFonction* d);
        void add(DeclarationFonction* d);
        void add(DeclarationGlobal* d);
        std::vector<Brique*> getListBrique();
    private:
    	// std::vector<DefFonction*> vectorDefinitionFonction;
    	// std::vector<DeclarationFonction*> vectorDeclarationFonction;
        // std::vector<DeclarationGlobal*> vectorDeclarationGlobal;
        std::vector<Brique*> vectorBrique;





};

#endif // if ! defined BRIQUES_H