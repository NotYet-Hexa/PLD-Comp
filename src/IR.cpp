//
// Created by Nathan Haim on 29/03/2017.
//


#include "IR.h"

using namespace std;

IRInstr::IRInstr(BasicBlock *bb_, Operation op, Type t, vector <string> params)
{
    this->bb = bb;
    this->op = op;
    this->t = t;
    this->params = params;
}

void IRInstr::gen_asm(ostream &o) { }


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
    nextFreeSymbolIndex = 0;
    nextBBnumber = 1;
    nbVar = 0;
    nbTVar = 0;
}

void CFG::add_bb(BasicBlock *bb)
{
    bbs.push_back(bb);
}

void CFG::add_to_symbol_table(string name, Type t)
{
    SymbolType.insert(std::pair<string,Type>(name,t));
    SymbolIndex.insert(std::pair<string,int>(name,nextFreeSymbolIndex));
    nextFreeSymbolIndex+=8;
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
    add_to_symbol_table("t"+to_string(nbTVar),t);
    return "t"+to_string(nbTVar);
    nbTVar++;
}

void CFG::gen_asm(ostream& o)
{
    gen_asm_prologue(o);
    gen_asm_epilogue(o);
}


void CFG::gen_asm_prologue(std::ostream& o)
{
    o.write("pushq %rbp",50);
    o.write("movq %rsp, %rbp",50);
    string str = "";
    str = "subq" + to_string(nbVar) + "%rsp";
    o.write(str.c_str(),50);
};

void CFG::gen_asm_epilogue(std::ostream& o)
{
    o.write("leave",50);
    o.write("ret",50);
}