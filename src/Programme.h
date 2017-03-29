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
#include "Briques.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Programme:
//
class Briques;
//------------------------------------------------------------------------

class Programme : public Contexte {
    public:
        void print();
        Programme();
        Programme(std::vector <Contexte*> listeDeContexte, Briques* briques);
        ~Programme();
        std::vector <Contexte*> getListeDeContexte();
    private:
        std::vector <Contexte*> listeDeContexte;
        Briques* brique;
};

#endif // if ! defined PROGRAMME_H