%{

using namespace std;

#include <iostream>
#include <string>

#include "Expression.h"
#include "ExpressionChar.h"
#include "ExpressionEntier.h"
#include "ExpressionVariable.h"
#include "ExpressionBinaire.h"
#include "Instruction.h"

struct resultat {
    int integer;
    string character;
    Expression * expression;
    Instruction * instruction;
};

void yyerror(resultat*, const char*);
int yylex(void);

%}

%code requires {

}

// description des symboles non terminaux
%union {
    int ival;
    char charactere;
    Expression * expression;
    Instruction * instruction;
    char* chaine;
}

%token <ival> ENTIER
%token <charactere> CHAR
%token <chaine> CHAINE
%token <chaine> NOM

%token PLUS MOINS DIV MUL MODULO
%token EGALE
%token PARENTOUV PARENTFERM ACCOLOUV ACCOLFERM CROCHETOUV CROCHETFERM
%token PLUSPLUS MOINSMOINS
%token PLUSEGAL MOINSEGAL DIVEGAL MULEGAL MODULOEGAL
%token DECALGAUCHEEGAL DECALDROITEGAL
%token ETEGAL OUEGAL XOREGAL
%token ETLOGIQUE OULOGIQUE
%token DECALGAUCHE DECALDROIT
%token ETBINAIRE OUBINAIRE
%token XOR INV
%token POINTVIRGULE

%token EGALEGAL DIFF 
%token INFEG INF SUP SUPEG

%token VOID INT32 INT64 TYPECHAR FOR WHILE IF ELSE RETURN

// %type <ival> expressionevalue
%type <expression> expression
%type <chaine> ligne
%type <instruction> instruction

%left PLUSEGAL EGALE MOINSEGAL DIVEGAL MULEGAL MODULOEGAL DECALGAUCHEEGAL DECALDROITEGAL ETEGAL OUEGAL XOREGAL
//OPTERNAIRE
%left OULOGIQUE
%left ETLOGIQUE
%left OUBINAIRE
%left XORBINAIRE
%left ETBINAIRE
// EGALEGAL DIFFERENT 
// INFEG INF SUPEG SUPEG
%left DECALGAUCHE DECALDROIT
%left PLUS MOINS
%left DIV MUL MODULO
%left NEG
%left PLUSPLUS MOINSMOINS


                    ;

%parse-param { resultat* result}

%%

axiome              : ligne                             { result->character = $1; }
                    | instruction                       { result->instruction = $1; }
                    | expression                        { result->expression = $1; }
                    ; 


instruction         : expression POINTVIRGULE           { $$ = new Instruction($1); }

expression          : ENTIER                            { $$ = new ExpressionEntier($1); }
                    | NOM                               { $$ = new ExpressionVariable($1); }
                    | CHAR                              { $$ = new ExpressionChar($1); }
                    |expression ETLOGIQUE expression    { $$ = new ExpressionBinaire($1, $3, "&&"); }
                    |expression OULOGIQUE expression    { $$ = new ExpressionBinaire($1, $3, "||"); }
                    |expression PLUS expression         { $$ = new ExpressionBinaire($1, $3, "+"); }
                    |expression MUL expression          { $$ = new ExpressionBinaire($1, $3, "*"); }
                    |expression DIV expression          { $$ = new ExpressionBinaire($1, $3, "/"); }
                    |expression MOINS expression        { $$ = new ExpressionBinaire($1, $3, "-"); }
                    |expression MODULO expression       { $$ = new ExpressionBinaire($1, $3, "%"); }
                    |expression DECALGAUCHE expression  { $$ = new ExpressionBinaire($1, $3, "<<"); }
                    |expression DECALDROIT expression   { $$ = new ExpressionBinaire($1, $3, ">>"); }
                    |expression XORBINAIRE expression   { $$ = new ExpressionBinaire($1, $3, "^"); }
                    |expression ETBINAIRE expression    { $$ = new ExpressionBinaire($1, $3, "&"); }
                    |expression OUBINAIRE expression    { $$ = new ExpressionBinaire($1, $3, "|"); }
                    |expression INF expression          { $$ = new ExpressionBinaire($1, $3, "<"); }
                    |expression SUP expression          { $$ = new ExpressionBinaire($1, $3, ">"); }
                    |expression INFEG expression        { $$ = new ExpressionBinaire($1, $3, "<="); }
                    |expression SUPEG expression        { $$ = new ExpressionBinaire($1, $3, ">="); }
                    |expression DIFF expression         { $$ = new ExpressionBinaire($1, $3, "!="); }
                    |expression EGALEGAL expression     { $$ = new ExpressionBinaire($1, $3, "=="); }
                    ;

ligne               : CHAINE { $$ = $1; }
                    ;
%%

void yyerror(resultat* ligne, const char * msg) {
   cout << "Syntax error : " << msg << endl;
}

int main(void) {
    resultat result;
    yyparse(&result);
    result.instruction->print();
// #ifdef CHAINE
//     cout << result.character << endl;
// #endif
//     cout << result.integer << endl;
    return 0;
}

