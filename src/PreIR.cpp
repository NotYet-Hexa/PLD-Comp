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
#include "Expression.h"
#include "Brique.h"
#include "PreIR.h"
#include "Type.h"

#include <fstream>
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés
typedef Expression::TypeExpression EnumExpression;

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
PreIR::PreIR()
{

}

PreIR::~PreIR()
{

}


void PreIR::analyseDefFonction(DefFonction* defFonction)
{
    CFG* cfg = new CFG(defFonction);
    listCFG.push_back(cfg);
    current_cfg = cfg;
    BasicBlock* bb = new BasicBlock(current_cfg, current_cfg->new_BB_name());
    current_bb = bb;
    cfg->add_bb(bb);

    analyseBloc(defFonction->getBloc());
}

void PreIR::launchPreIR(Programme* prog)
{
    vector<Brique*> listBrique = prog->getBriques()->getListBrique();
    typeClassBrique tp;

    for(vector<Brique*>::iterator it= listBrique.begin() ; it != listBrique.end() ; it++)
    {
        tp = (*it)->typeClass();
        switch(tp)
        {
            case typeClassBrique::defFonction : analyseDefFonction((DefFonction*)*it);break;
        }
    }
    launchASM();
}


void PreIR::analyseBloc(Bloc* b)
{
    ListInstruction* listInstr = b->getListInstruction();
    vector<Instruction*> instructions = listInstr->getInstructions();
    InstructionVraieClass ins;
    for(vector<Instruction*>::iterator it= instructions.begin() ; it != instructions.end() ; it++)
    {
        ins = (*it)->getInstructionVraie()->typeClass();
        switch(ins)
        {
            case InstructionVraieClass::declaration : analyseDeclaration((Declaration*)(*it)->getInstructionVraie());break;
            case InstructionVraieClass::appelFonction : analyseAppelFonction((AppelFonction*)(*it)->getInstructionVraie()) ; break;
        }
    }
}

void PreIR::analyseDeclaration(Declaration* dec)
{  
    string s = dec->getType();
    if(s == "int64")
    {
        current_cfg->add_to_symbol_table(dec->getNom(),Type::int64);
    }
}


void PreIR::launchASM()
{   
    ofstream outfile ("main.s",ofstream::binary);
    outfile<<".text"<<endl;
    outfile<<".global _main"<<endl;
    outfile<<"_main:"<<endl;
    for(vector<CFG*>::iterator it= listCFG.begin() ; it != listCFG.end() ; it++)
    {
        (*it)->gen_asm(outfile);
    }
    outfile.close();
}

void PreIR::analyseAppelFonction(AppelFonction* appelFonction)
{
    ArgsAppel* argsAppel = appelFonction->getArgsAppel();
    if(argsAppel)
    {
        std::vector<Expression*>listExp = argsAppel->getArgs();
        InstructionVraieClass ins;
        vector<string> listParam;
        listParam.push_back(appelFonction->getNomFonction());
        for(vector<Expression*>::iterator it= listExp.begin() ; it != listExp.end() ; it++)
        {
            ins = (*it)->typeClass();
            switch(ins)
            {
                case InstructionVraieClass::expressionChar :
                            string varStr = analyseExpressionChar((ExpressionChar*)(*it));
                            listParam.push_back(varStr);
                            break;
            }
        }
    IRInstr* irInstr = new IRInstr(current_bb,IRInstr::Operation::call,Type::ch, listParam);    
    }
}


string PreIR::analyseExpressionChar(ExpressionChar* expressionChar)
{
    string tmpVar = current_cfg->create_new_tempvar(Type::ch);
    vector<string> params;
    params.push_back(tmpVar);
    params.push_back(to_string(expressionChar->getChar()));
    current_bb->add_IRInstr(IRInstr::Operation::ldconst,Type::ch, params);
    return tmpVar;
    //IRInstr* irInstr = new IRInstr(current_bb, Operation op, Type t, std::vector<std::string> params);
}

// string PreIR::instructionToIR(Instruction* instruction)
// {

// }

/// Return soit a dans le cas a = b + 1 soit tn 
string PreIR::expressionToIR(Expression* expression)
{
    EnumExpression type = expression->getType();
    switch(type)
    {
        case EnumExpression::Type_Unaire:
            break;
        case EnumExpression::Type_Binaire :
            break;
        case EnumExpression::Type_Char :
            break;
        case EnumExpression::Type_Entier :
            break;
        case EnumExpression::Type_Variable :
            break;
        case EnumExpression::Type_Affectation :
            // string tmp = expressionToIR(expression->get_expresion());
            // IRInstr* ir = new IRInstr(current_bb, Operation::mov, "b", "a" )
            // current_bb.instrs.push_back(ir);
            // return tmp;
            break;
        case EnumExpression::Type_AffectationUnaire :
            break;
        case EnumExpression::Type_AppelFonction :
            break;
        case EnumExpression::Type_Assignation :
            break;
        case EnumExpression::Type_ExpressionVariable :
            break;
    }
}