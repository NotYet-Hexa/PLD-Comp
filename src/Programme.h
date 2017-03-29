/*************************************************************************
PLD COMP
Programme.h  -  Description
-------------------
début                : 20/03/2017
copyright            : (C)2017 par H4114
*************************************************************************/

//---------- Interface de la classe Programme (fichier Programme.h) ------
#if ! defined ( PROGRAMME_H )
#define PROGRAMME_H

//--------------------------------------------------- Interfaces utilisées

#include "Contexte.h"
#include <vector>
#include "Brique.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Programme:
//

//------------------------------------------------------------------------

class Programme: public Contexte{
    public:
        void print();
        Programme();
        Programme(vector <Contexte*> listeDeContexte, Brique* brique);
        ~Programme();
        vector <Contexte*> getListeDeContexte();
    private:
        vector <Contexte*> listeDeContexte;
        Brique* brique;
};

#endif // if ! defined PROGRAMME_H