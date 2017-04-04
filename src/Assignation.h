/*************************************************************************
PLD Comp
Assignation.h  -  Description
-------------------
début                : 27/03/2017
copyright            : (C)2017
*************************************************************************/

//---------- Interface de la classe Assignation (fichier Assignation.h) ------
#if ! defined ( ASSIGNATION_H )
#define ASSIGNATION_H


//--------------------------------------------------- Interfaces utilisées
# include "Expression.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Assignation:
//

//------------------------------------------------------------------------

class Assignation: public Expression{
    public:
        virtual void print();
        Assignation();
        ~Assignation();
 
    private:
        TypeExpression type_expression;

};

#endif // if ! defined ASSIGNATION_H
