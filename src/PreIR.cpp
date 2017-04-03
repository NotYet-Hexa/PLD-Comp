/*************************************************************************
PLD Comp
PreIR.cpp  -  Description
-------------------
début                : 03/04/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/


#include <iostream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "Programme.h"
#include "IR.h"
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques



void launchPreIR(Programme* prog)
{
    vector<CFG*> listCFG;
    vector<Contexte*> listContext = prog->getListeDeContexte();
    string tp = "";
    for(vector<Contexte*>::iterator it= listContext.begin() ; it != listContext.end() ; it++)
    {
        tp = (*it)->typeClass();
        switch(tp)
        {
            case "DefFonction": analyseDefFonction(*it);break;
        }
    }
    launchASM(vector<CFG*> listCFG);
}

void analyseDefFonction(DefFonction* defFonction)
{
    CFG* cfg = new CFG(defFonction);
    BasicBlock* bb = new BasicBlock(cfg.new_BB_name);
    ListInstruction* listInstruct = defFonction->getBloc()->getListInstruction();


}

void analyseBloc(){}


void launchASM(vector<CFG*> listCFG)
{   
    ofstream outfile ("new.txt",ofstream::binary);
    for(vector<CFG*>::iterator it= listCFG.begin() ; it != listCFG.end() ; it++)
    {
        (*it)->gen_asm(outfile);
    }
}