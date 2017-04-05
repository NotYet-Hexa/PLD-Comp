/*************************************************************************
PLD Comp
Declaration.h  -  Description
-------------------
début                : 23/02/2017
copyright            : (C)2017 par Haim Nathan
*************************************************************************/

//---------- Interface de la classe Declaration (fichier DeclarationGlobal.h) ------
#if ! defined ( DECLARATIONGLOBAL_H )
#define DECLARATIONGLOBAL_H

using namespace std;

//--------------------------------------------------- Interfaces utilisées
#include <string>

#include "Brique.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Declaration:
//

//------------------------------------------------------------------------

class DeclarationGlobal : public Brique  {
    public:
        void print();
        std::string getNom(); 
        DeclarationGlobal(string type, string nom, bool isTab, int size);
        ~DeclarationGlobal();
        string get_type();
        string get_nom();
        bool get_isTab();
        int get_size();
    private:
        string type;
        string nom;
        bool isTab;
        int size;
};

#endif // if ! defined DECLARATION_H