/*************************************************************************
PLD Comp
Brique.h  -  Description
-------------------
début                : 15/02/2017
copyright            : (C)2015 par FOLLEAS Jacques et SCHROTER Quentin
*************************************************************************/

//---------- Interface de la classe Brique (fichier Brique.h) ------
#if ! defined ( BRIQUE_H )
#define BRIQUE_H


//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Brique:
//

//------------------------------------------------------------------------

class Brique{
    public:
        virtual void print() = 0;
        bool getIsContexte();
        Brique();
        ~Brique();

    protected:
        bool isContexte;

};

#endif // if ! defined BRIQUE_H