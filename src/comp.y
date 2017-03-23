%{

using namespace std;

#include <iostream>
#include <string>

#include "Expression.h"
#include "ExpressionChar.h"
#include "ExpressionEntier.h"
#include "ExpressionVariable.h"
#include "ExpressionBinaire.h"
#include "InstructionVraie.h"

struct resultat {
    int integer;
    string character;
    Expression * expression;
    InstructionVraie * instructionVraie
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
    InstructionVraie * instructionVraie
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
%type <instructionVraie> instructionVraie

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


// #ifdef CHAINE
// %parse-param { char* resultat }
// #endif

// expressionevalue    : MOINS expressionevalue %prec NEG              { $$ = -$2; }
//                     | expressionevalue PLUS expressionevalue        { $$ = $1 + $3; }
//                     | expressionevalue MOINS expressionevalue       { $$ = $1 - $3; }
//                     | expressionevalue DIV expressionevalue         { $$ = $1 / $3; }
//                     | expressionevalue MUL expressionevalue         { $$ = $1 * $3; }
//                     | expressionevalue MODULO expressionevalue      { $$ = $1 % $3; }
//                     | PARENTOUV expressionevalue PARENTFERM         { $$ = $2; }
//                     | expressionevalue PLUSPLUS                     { $$ = $1++; }
//                     | expressionevalue MOINSMOINS                   { $$ = $1--; }
//                     | expressionevalue DECALGAUCHE expressionevalue { $$ = $1 << $3; }
//                     | expressionevalue DECALDROIT expressionevalue  { $$ = $1 >> $3; }
//                     | expressionevalue XORBINAIRE expressionevalue  { $$ = $1 ^ $3; }
//                     | expressionevalue OUBINAIRE expressionevalue   { $$ = $1 | $3; }
//                     | expressionevalue ETBINAIRE expressionevalue   { $$ = $1 & $3; }
//                     | ENTIER                                        { $$ = $1; }


                    // | expressionevalue                  { result->integer = $1; }
//                     ;

%parse-param { resultat* result}

%%

axiome              : ligne                             { result->character = $1; }
                    | InstructionVraie                  { resultat -> instructionVraie = $1; }
                    | expression                        { result->expression = $1; }
                    ; 


InstructionVraie    : expression POINTVIRGULE           {$$ = new }

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
    result.expression->print();
// #ifdef CHAINE
//     cout << result.character << endl;
// #endif
//     cout << result.integer << endl;
    return 0;
}