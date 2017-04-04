/*************************************************************************
PLD COMP
Programme.h  -  Description
-------------------
début                : 20/03/2017
copyright            : (C)2017 par Haim Nathan
*************************************************************************/

//---------- Interface de la classe Programme (fichier Programme.h) ------
#if ! defined ( PREIR_H )
#define PREIR_H

//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <vector>
#include "IR.h"
#include "Bloc.h"
#include "AppelFonction.h"
#include "ExpressionChar.h"
#include "Expression.h"
//------------------------------------------------------------------------

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------------
// Role de la classe Programme:
//
//------------------------------------------------------------------------
class PreIR{
private:
    std::vector<CFG*> listCFG;
    CFG* current_cfg;
    BasicBlock* current_bb;
public:
    PreIR();
    ~PreIR();
    void analyseDefFonction(DefFonction* defFonction);
    void launchPreIR(Programme* prog);
    void analyseBloc(Bloc* b);
    void analyseDeclaration(Declaration* dec);
    void analyseAppelFonction(AppelFonction* appelFonction);
    string analyseExpressionChar(ExpressionChar* expressionChar);
    void launchASM();

    string expressionToIR(Expression* expression);
    void instructionToIR(Instruction* instruction);

};



#endif // if ! defined PREIR_H