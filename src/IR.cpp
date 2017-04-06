//
// Created by Nathan Haim on 29/03/2017.
//


#include "IR.h"

using namespace std;

IRInstr::IRInstr(BasicBlock *bb_, Operation op, Type t, vector <string> params)
{
    this->bb_ = bb_;
    this->op = op;
    this->t = t;
    this->params = params;
}

IRInstr::~IRInstr()
{
    
}

void IRInstr::gen_asm(ostream &o)
{
    string str;
    string operateur; 
    int paramNum =0;
    switch(this->op)
    {
        case Operation::ldconst :
                operateur = "movq";
                str= "\t"+operateur+ " $"+ params.at(1) + ", "+to_string(bb_->cfg->get_var_index(params.at(0)))+ "(%rbp)";
                o<< str << endl;
                break;
        case Operation::call :
                while((params.size() - paramNum) > 1 )
                {
                    string p = params.at(params.size()-paramNum-1);
                    operateur = "movq";
                    str = "\t"+operateur+" "+ to_string(bb_->cfg->get_var_index(p))+"(%rbp), " + chooseRegister(paramNum);
                    o<<str<<endl;
                    paramNum++;
                }
                o<< "\tcall " +params.at(0)<<endl;
                break;
        case Operation::copy :
                operateur = "movq";
                str = "\t"+operateur+" "+ to_string(bb_->cfg->get_var_index(params.at(0)))+"(%rbp), %rax";
                o<<str<<endl;
                str = "\t"+operateur+" %rax,"+ to_string(bb_->cfg->get_var_index(params.at(1)))+"(%rbp)";
                o<<str<<endl;
                break;
        case Operation::sub :
                str = "\tmovq "+ to_string(bb_->cfg->get_var_index(params.at(2))) + "(%rbp), %rax";
                o<<str<<endl;
                str = "\tsubq "+ to_string(bb_->cfg->get_var_index(params.at(1))) + "(%rbp), %rax";
                o<<str<<endl;
                str = "\tmovq %rax, "+ to_string(bb_->cfg->get_var_index(params.at(0))) + "(%rbp)";
                o<<str<<endl;
                break;
        case Operation::add :
                str = "\tmovq "+ to_string(bb_->cfg->get_var_index(params.at(2))) + "(%rbp), %rax";
                o<<str<<endl;
                str = "\taddq "+ to_string(bb_->cfg->get_var_index(params.at(1))) + "(%rbp), %rax";
                o<<str<<endl;
                str = "\tmovq %rax, "+ to_string(bb_->cfg->get_var_index(params.at(0))) + "(%rbp)";
                o<<str<<endl;
                break;
        case Operation::ret :
                str = "\tmovq " + to_string(bb_->cfg->get_var_index(params.at(0))) + "(%rbp), %rax";
                o<<str<<endl;
    }
    



}

void IRInstr::print()
{
    /*for(vector<string>::iterator it = params.begin() ; it != params.end() ; it++)
    {
    }*/
}

string IRInstr::chooseRegister(int num)
{
    switch(num)
    {
        case 0: return "%rdi"; break;
        case 1: return "%rsi"; break;
        case 2: return "%rdx"; break;
        case 3: return "%rcx"; break;
        case 4: return "%r8"; break;
        case 5: return "%r9"; break;
    }
}

BasicBlock::BasicBlock(CFG* cfg, string entry_label)
{
    this->cfg = cfg;
    this->label = entry_label;
}

void BasicBlock::add_IRInstr(IRInstr::Operation op, Type t, vector<string> params)
{
    this->instrs.push_back(new IRInstr(this,op,t,params));
}


CFG::CFG(DefFonction *ast)
{
    this-> ast = ast;
    current_bb = NULL;
    nextFreeSymbolIndex = -8;
    nextBBnumber = 1;
    nbVar = 0;
    nbTVar = 0;
}

CFG::~CFG()
{
    for(vector<BasicBlock*>::iterator it = bbs.begin(); it != bbs.end(); it++)
    {
        delete *it;
    }
    bbs.clear();
}

void CFG::add_bb(BasicBlock *bb)
{
    bbs.push_back(bb);
}

void CFG::add_to_symbol_table(string name, Type t)
{
    SymbolType.insert(std::pair<string,Type>(name,t));
    SymbolIndex.insert(std::pair<string,int>(name,nextFreeSymbolIndex));
    nextFreeSymbolIndex-=8;
    nbVar+=1;
}


int CFG::get_var_index(string name)
{
    return SymbolIndex[name];
}

Type CFG::get_var_type(string name)
{
    return SymbolType[name];
}

string CFG::new_BB_name()
{
    return "b"+to_string(nextBBnumber);
}

string CFG::create_new_tempvar(Type t)
{
    nbTVar++;
    add_to_symbol_table("t"+to_string(nbTVar),t);
    return "t"+to_string(nbTVar);
}

void CFG::gen_asm(ostream& o)
{
    gen_asm_prologue(o);
    gen_asm_body(o);
    gen_asm_epilogue(o);
}

void CFG::gen_asm_body(std::ostream& o)
{
    for(vector<BasicBlock*>::iterator it= bbs.begin() ; it != bbs.end() ; it++)
    {
        (*it)->gen_asm(o);
    }
}


void BasicBlock::gen_asm(std::ostream &o)
{
    for(vector<IRInstr*>::iterator it= instrs.begin() ; it != instrs.end() ; it++)
    {   

        (*it)->gen_asm(o);
    }
}

void CFG::gen_asm_prologue(std::ostream& o)
{
    o<<"main:"<<endl;
    o<<"\tpushq %rbp"<<endl;
    o<<"\tmovq %rsp, %rbp"<<endl;
    if(nbVar%2 == 0)    o<<"\tsubq $" + to_string(nbVar/2*16) + ", %rsp"<<endl;
    else o<<"\tsubq $" + to_string((nbVar/2+1)*16) + ", %rsp"<<endl;
};

void CFG::gen_asm_epilogue(std::ostream& o)
{
    o<<endl<<"\tleave"<<endl;
    o<<"\tret"<<endl;
}
