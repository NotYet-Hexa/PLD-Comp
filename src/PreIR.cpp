/*************************************************************************
PLD Comp
PreIR.cpp  -  Description
-------------------
début                : 03/04/2017
copyright            : (C)2015 par Haim Nathan
*************************************************************************/


#include <iostream>
#include <vector>

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
#include "InstructionVraie.h"
#include "ListInstruction.h"
#include "Return.h"
#include "Instruction.h"

#include "Affectation.h"
#include "AffectationUnaire.h"

#include <fstream>
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés
typedef Expression::TypeExpression EnumExpression;
typedef IRInstr::Operation Operation;
typedef Outils::TypeSymbole Symboles;
typedef InstructionVraie::TypeInstruction TypeInstruction;

//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
PreIR::PreIR()
{

}

PreIR::~PreIR()
{
	for (vector<CFG*>::iterator it = listCFG.begin(); it != listCFG.end(); it++)
	{
		delete *it;
	}
	listCFG.clear();
	delete this->current_cfg;
	delete this->current_bb;
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
            case InstructionVraieClass::affectation : analyseAffectation((Affectation*)(*it)->getInstructionVraie()) ; break;
        }
    }
}

void PreIR::analyseAffectation(Affectation* aff)
{
    string nomVar = aff->get_nom_variable();
    string symbole = aff->get_symbole();
    //TODO mettre un switch pour tester les differents symboles

    string tmpVar;
    vector<string> params;
    Expression* expr = aff->get_expression();
    switch(expr->typeClass())
    {
        case InstructionVraieClass::expressionEntier :
                tmpVar = analyseExpressionEntier((ExpressionEntier*)expr); 
                params.push_back(tmpVar);
                params.push_back(nomVar);
                current_bb->add_IRInstr(IRInstr::Operation::copy,Type::int64, params);
                break;
        case InstructionVraieClass::expressionChar :
                tmpVar = analyseExpressionChar((ExpressionChar*)expr); 
                params.push_back(tmpVar);
                params.push_back(nomVar);
                current_bb->add_IRInstr(IRInstr::Operation::copy,Type::ch, params);
                break;
    }

    

}

void PreIR::analyseDeclaration(Declaration* dec)
{  
    string s = dec->getType();
        cout << "type EEEEE : " << s << endl;
    if(s == "int64")
    {
        current_cfg->add_to_symbol_table(dec->getNom(),Type::int64);
    }
    else if(s == "int32")
    {
        current_cfg->add_to_symbol_table(dec->getNom(),Type::int32); 
    }
    else if(s == "char")
    {
        current_cfg->add_to_symbol_table(dec->getNom(),Type::ch);
    }
}


void PreIR::launchASM()
{   
    ofstream outfile ("main.s",ofstream::binary);
    outfile<<".text"<<endl;
    outfile<<".global main"<<endl;
    outfile<<"main:"<<endl;
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
            ins = InstructionVraieClass::expressionChar;
            switch(ins)
            {
                case InstructionVraieClass::expressionChar :
                            string varStr = analyseExpressionChar((ExpressionChar*)(*it));
                            listParam.push_back(varStr);
                            break;
                case InstructionVraieClass::expressionVariable :
                            string varStr = analyseExpressionVariable((ExpressionVariable*)(*it));
                            listParam.push_back(varStr);
                            break;
            }
        }
        current_bb->add_IRInstr(IRInstr::Operation::call,Type::ch, listParam);
    //IRInstr* irInstr = new IRInstr(current_bb,IRInstr::Operation::call,Type::ch, listParam);    
    }
}


string PreIR::analyseExpressionChar(ExpressionChar* expressionChar)
{
    string tmpVar = current_cfg->create_new_tempvar(Type::ch);
    vector<string> params;
    params.push_back(tmpVar);
    params.push_back(to_string(expressionChar->getChar()));
    cout << "le char est : " << to_string(expressionChar->getChar()) << endl;
    current_bb->add_IRInstr(IRInstr::Operation::ldconst,Type::ch, params);
    return tmpVar;
    //IRInstr* irInstr = new IRInstr(current_bb, Operation op, Type t, std::vector<std::string> params);
}


string PreIR::analyseExpressionVariable(ExpressionVariable* expressionVariable)
{
    string var = expressionVariable->get_nomVariable();
    return var;
    //IRInstr* irInstr = new IRInstr(current_bb, Operation op, Type t, std::vector<std::string> params);
}


string PreIR::analyseExpressionEntier(ExpressionEntier* expressionEntier)
{
    string tmpVar = current_cfg->create_new_tempvar(Type::int64);
    vector<string> params;
    params.push_back(tmpVar);
    params.push_back(to_string(expressionEntier->get_valeur()));
    current_bb->add_IRInstr(IRInstr::Operation::ldconst,Type::ch, params);
    return tmpVar;
    //IRInstr* irInstr = new IRInstr(current_bb, Operation op, Type t, std::vector<std::string> params);
}



// string PreIR::instructionToIR(Instruction* instruction)
// {

// }
/// Return soit a dans le cas a = b + 1 soit tn 
void PreIR::instructionToIR(Instruction* instruction)
{
    InstructionVraie* instructionVraie=instruction->getInstructionVraie();
    TypeInstruction type = instructionVraie->getTypeInstruction();
    switch(type)
    {
        case(TypeInstruction::TIexpression):
        {
            Expression* expression = (Expression*)instructionVraie;
            PreIR::expressionToIR(expression);
            break;
        }

        case(TypeInstruction::TIbloc):
        {
            Bloc* bloc = (Bloc*)instructionVraie;
            ListInstruction* listInstruction = bloc->getListInstruction();
            std::vector<Instruction*> instructions = listInstruction-> getInstructions();
            for(std::vector<Instruction*>::iterator i =instructions.begin();i!=instructions.end();++i)
            {
                PreIR::instructionToIR(*i);
            }
            break;

        }
        
        case(TypeInstruction::TIretourFonction):
        {
            Return* retour = (Return*)instructionVraie;
            PreIR::expressionToIR(retour->get_expression());
            break;
        }
        
    }
}
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
                        current_bb->add_IRInstr(Operation::add,Type::int64, params);
                        break;
                    }
                    case Symboles::moins:
                    {
                        params.push_back(resultGauche);
                        params.push_back(resultDroite);
                        current_bb->add_IRInstr(Operation::sub,Type::int64, params);
                        break;
                    }
                    case Symboles::multi:
                    {
                        params.push_back(resultGauche);
                        params.push_back(resultDroite);
                        current_bb->add_IRInstr(Operation::mul,Type::int64, params);
                        break;
                    }
                    default:
                    {
                        throw "toujours pas fait ";
                    }
                break;

            }
        }

        case EnumExpression::Type_Char :
            {
                ExpressionChar* expressionChar = (ExpressionChar*)expression;
                params.push_back(to_string(expressionChar->getChar()));
                current_bb->add_IRInstr(Operation::ldconst,Type::ch, params);
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
                current_bb->add_IRInstr(Operation::ldconst,Type::ch, params);
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
                            current_bb->add_IRInstr(Operation::ldconst,Type::int64, params);
                            break;
                        }
                    case Symboles::plusegal:
                        {
                            current_bb->add_IRInstr(Operation::add,Type::int64,params);
                            current_bb->add_IRInstr(Operation::ldconst,Type::int64,params);
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
