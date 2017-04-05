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
        string get_nom_variable();
        string get_symbole();
        TypeExpression getType();
    private:
        string nomVariable;
        string symbole;
        TypeExpression type_expression;

};

#endif // if ! defined AFFECTATIONUNAIRE_H