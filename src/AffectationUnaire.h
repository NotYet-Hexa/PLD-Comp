/*************************************************************************
PLD Comp
AffectationUnaire.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe AffectationUnaire (fichier AffectationUnaire.h) ------
#if ! defined ( AFFECTATIONUNAIRE_H )
#define AFFECTATIONUNAIRE_H


//--------------------------------------------------- Interfaces utilisées


#include "Expression.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe AffectationUnaire:
//

//------------------------------------------------------------------------

class AffectationUnaire: public Expression {
    public:
        void print();
        std::list<string> listeNomLValue();
        AffectationUnaire(string nomVariable, string symbole);
        ~AffectationUnaire();

    private:
        string nomVariable;
        string symbole;

};

#endif // if ! defined AFFECTATIONUNAIRE_H