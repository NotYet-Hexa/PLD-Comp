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
#include "IR.h"
#include "Type.h"
#include "Outils.h"
#include "ExpressionBinaire.h"
#include "ExpressionChar.h"
#include "ExpressionEntier.h"
#include "ExpressionVariable.h"


#include "Affectation.h"
#include "AffectationUnaire.h"

#include <fstream>
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés
typedef Expression::TypeExpression EnumExpression;
typedef IRInstr::Operation Operation;
typedef Outils::TypeSymbole Symboles;

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
        for(vector<Expression*>::iterator it= listExp.begin() ; it != listExp.end() ; it++)
        {
            ins = (*it)->typeClass();
            switch(ins)
            {
                case InstructionVraieClass::expressionChar : analyseExpressionChar((ExpressionChar*)(*it));break;
            }
        }
    }
}

void PreIR::analyseExpressionChar(ExpressionChar* expressionChar)
{
    expressionChar->getChar();
    string tmpVar = current_cfg->create_new_tempvar(Type::ch);
    //IRInstr* irInstr = new IRInstr(current_bb, Operation op, Type t, std::vector<std::string> params);
}

// string PreIR::instructionToIR(Instruction* instruction)
// {

// }
/// Return soit a dans le cas a = b + 1 soit tn 
string PreIR::expressionToIR(Expression* expression)
{
    string result;
    string resultGauche;
    string resultDroite;
    vector<std::string> params;
    EnumExpression type = expression->getType();
    Outils outils ;

    switch(type)
    {
        case EnumExpression::Type_Unaire :
            break;
        case EnumExpression::Type_Binaire :
            {
                ExpressionBinaire* expressionBinaire = (ExpressionBinaire*)expression;
                resultGauche = expressionToIR(expressionBinaire->get_gauche());
                resultDroite = expressionToIR(expressionBinaire->get_droite());
                switch (outils.parse_symb(expressionBinaire->get_symbole()))
                {
                    case Symboles::plus:
                    {
                        params.push_back(resultGauche);
                        params.push_back(resultDroite);
                        IRInstr* ir = new IRInstr(current_bb, Operation::add, Type::int64, params);
                        current_bb->instrs.push_back(ir);
                        break;
                    }
                    default:
                    {
                        throw "toujours pas fait ";
                    }
                }
            }

            break;
        case EnumExpression::Type_Char :
            {
                ExpressionChar* expressionChar = (ExpressionChar*)expression;
                params.push_back(to_string(expressionChar->getChar()));
                IRInstr* ir = new IRInstr(current_bb, Operation::ldconst, Type::ch, params);
                current_bb->instrs.push_back(ir);
                break;
            }
        case EnumExpression::Type_Entier :
            {
                ExpressionEntier* expressionEntier = (ExpressionEntier*)expression;
                params.push_back(to_string(expressionEntier->get_valeur()));
                current_bb->add_IRInstr(Operation::ldconst,Type::int64, params);
                break;
            }
        case EnumExpression::Type_Variable :
            {
                ExpressionVariable* expressionVariable = (ExpressionVariable*)expression;
                params.push_back(expressionVariable->get_nomVariable());
                IRInstr* ir = new IRInstr(current_bb, Operation::ldconst, Type::ch, params);
                current_bb->instrs.push_back(ir);
                break;
            }
        case EnumExpression::Type_Affectation :
            {
                Affectation* affectation = (Affectation*)expression;
                result = expressionToIR(affectation->get_expression());

                // move result to nom_variable
                params.push_back(result);
                params.push_back(affectation->get_nom_variable());

                switch(outils.parse_symb(affectation->get_symbole()))
                {
                    case Symboles::egal:
                        {
                            IRInstr* ir = new IRInstr(current_bb, Operation::wmem, Type::int64, params);
                            current_bb->instrs.push_back(ir);
                            break;
                        }
                    case Symboles::plusegal:
                        {
                            break;
                        }
                    case Symboles::moinsegal:
                        {
                            break;
                        }
                    case Symboles::divegal:
                        {
                           break; 
                        }
                    case Symboles::mulegal:
                        {
                           break; 
                        }
                    default:
                        {
                            throw "Not Implemented Yet";
                        }
                }

                break;
            }
        case EnumExpression::Type_AffectationUnaire :
            break;
        case EnumExpression::Type_AppelFonction :
            break;
        case EnumExpression::Type_Assignation :
            break;
        case EnumExpression::Type_ExpressionVariable :
            break;
    }
    return result;
}