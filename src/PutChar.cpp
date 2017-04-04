/*************************************************************************
PLD Comp
PutChar.cpp  -  Description
-------------------
début                : 27/03/2017
copyright            : (C)2017
*************************************************************************/

//---------- Réalisation de la classe PutChar (fichier PutChar.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "PutChar.h"

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void PutChar::print()
{
    cout << "PutChar : " << theChar << endl; 
}
//----- Constructeur
PutChar::PutChar(char monChar) : theChar(monChar)
{}// Bloc vide
//----- Fin constructeur

//----- Destructeur
PutChar::~PutChar()
{}// Bloc vide
//----- Fin destructeur


/*
lecture_ecriture	: GETCHAR PARENTOUV nom_variable PARENTFERM     
			        | PUTCHAR PARENTOUV CHAR PARENTFERM             { $$ = new PutChar($3); }
			        ;


%type<instructionVraie> lecture_ecriture


    InstructionVraie * instructionVraie;


#include "PutChar.h"


"putchar"             { return PUTCHAR; }
"getchar"             { return GETCHAR; }

*/