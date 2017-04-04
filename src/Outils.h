/*************************************************************************
PLD Comp
Outils.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe Outils (fichier Outils.h) ------
#if ! defined ( Outils_H )
#define Outils_H


//--------------------------------------------------- Interfaces utilisées

#include "Expression.h"

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe OutilsDeclaratino:
//

//------------------------------------------------------------------------

class Outils  {
    public:
    	enum TypeSymbole{
    		plus,
    		moins,
    		multi,
    		divis,
    		egal,
    		parentouv,
    		parentFerm,
    		accolouv,
    		accoferm,
    		crochetouv,
    		crochetferm,
    		plusplus,
    		moinsmoins,
    		plusegal,
    		moinsegal,
    		divegal,
    		mulegal,
    		moduloegal,
    		decalgaucheegal,
    		decaldroiteegal,
    		xorbinaire,
    		oubinaire,
    		etbinaire,
    		inv,
    		pointvirgule,
    		virgule,
    		inf,
    		sup,
    		infeg,
    		supeg,
    		diff,
    		egaleegal,
    		etegal,
    		ouegal,
    		xoregal,
    		etlogique,
    		oulogique,
    		decaldroite,
    		decalgauche
    	};

    	Outils::TypeSymbole parse_symb(string symbole);
        Outils();
        ~Outils();

    private:

};

#endif // if ! defined Outils