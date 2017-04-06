%{

using namespace std;

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

#include "Contexte.h"

#include "Expression.h"
#include "ExpressionChar.h"
#include "ExpressionEntier.h"
#include "ExpressionVariable.h"
#include "ExpressionUnaire.h"

#include "LValue.h"
#include "ExpressionBinaire.h"
#include "AppelFonction.h"
#include "Instruction.h"
#include "Return.h"
#include "Affectation.h"
#include "AffectationUnaire.h"

#include "Declaration.h"
#include "DeclarationGlobal.h"
#include "DeclarationFonction.h"
#include "DefFonction.h"


#include "Cond.h"
#include "CondSuite.h"
#include "LoopStatement.h"

#include "ArgsDef.h"
#include "ArgsAppel.h"

#include "ListInstruction.h"
#include "Bloc.h"
#include "Programme.h"

#include "Briques.h"
#include "Brique.h"

//AJOUT
#include "Contexte.h"

#include "PreIR.h"

void yyerror(Programme**, const char*);
int yylex(void);

%}


// description des symboles non terminaux
%union {
    int ival;
    char charactere;
    Expression * expression;
    Instruction * instruction;
    Cond * cond;
    CondSuite * condSuite;
    LoopStatement * loop;

    char* chaine;

    Declaration* declaration;
    DeclarationGlobal * declarationGlobal;
    DeclarationFonction* declaration_fonction;
    DefFonction*  definition_fonction;

    LValue * lValue;
    Return* retour_fonction;

    Briques* briques;

    ArgsDef * args;
    ArgsAppel * argsAppel;

    ListInstruction* liste_instruction;
    Bloc * bloc;
    Programme* program;
}

%error-verbose

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
%token POINTVIRGULE VIRGULE

%token EGALEGAL DIFF 
%token INFEG INF SUP SUPEG

%token VOID INT32 INT64 TYPECHAR FOR WHILE IF ELSE RETURN PUTCHAR GETCHAR

%token UNKNOWN
%type <ival> UNKNOWN
// %type <ival> expressionevalue
%type <expression> expression
%type <chaine> ligne
%type <instruction> instruction
%type <liste_instruction> liste_instruction
%type <bloc> bloc



%type<program> programme

%type<briques> liste

%type<declaration> declaration
%type<declarationGlobal> declarationGlobal
%type<definition_fonction> definition_de_fonction
%type<declaration_fonction> declaration_de_fonction

%type<args> args_def
%type<chaine> type

%type<declaration> parametre
%type<loop> loop_statement
%type<cond> cond 
%type<retour_fonction> retour_fonction
%type<chaine> nom_variable
%type<chaine> nom
%type<lValue> l_value
%type<expression> appel_fonction
%type<argsAppel> args_appel_fonction
%type<condSuite> fin_cond


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


%parse-param { Programme** result}

%%
axiome              :programme      {  *result = $1;  }  
                    ;

programme		    : liste         { $$ = new Programme($1); } 
			        ;

liste			    : definition_de_fonction                        { $$ = new Briques(); $$->add($1); /*checked*/} 
                    | declaration_de_fonction POINTVIRGULE          { $$ = new Briques(); $$->add($1);  /*checked*/ } 
                    | declarationGlobal   POINTVIRGULE              { $$ = new Briques(); $$->add($1);  /*checked*/ }
			        | liste definition_de_fonction                  { $$ = $1; $$->add($2); /*checked*/ } 
			        | liste declaration_de_fonction POINTVIRGULE    { $$ = $1; $$->add($2); /*checked*/ } 
			        | liste declarationGlobal  POINTVIRGULE         { $$ = $1; $$->add($2); /*checked*/ } 
			        |                                               { $$ = new Briques(); }    
                    ;

declaration_de_fonction  	: type nom PARENTOUV args_def PARENTFERM 
                                        { $$ = new DeclarationFonction($2, $1, $4); }
                            ;

definition_de_fonction    	: type nom PARENTOUV args_def PARENTFERM bloc
                                        { $$ = new DefFonction( $1 , $6 , $4, $2 );}

declarationGlobal           : type nom                                  { $$ = new DeclarationGlobal( $1 , $2, false, 0); cout<<"non tab"<<endl; }      // ajouter les crochet 
                            | type nom CROCHETOUV ENTIER CROCHETFERM    { $$ = new DeclarationGlobal( $1 , $2, true, $4); cout<<"tab"<<endl; }
                            ;
                           	;

args_def                    : parametre                     { $$ = new ArgsDef(); $$->add($1); }
                            | args_def VIRGULE parametre    { $$ = $1 ; $$->add($3); }
                           	| VOID                          { $$ = new ArgsDef(); }
                            |                               { $$ = new ArgsDef(); cout <<"args ok " << endl;}
                            ;


bloc                        :  ACCOLOUV liste_instruction  ACCOLFERM    { $$ = new Bloc($2); }
                            ;


liste_instruction	    : liste_instruction instruction 	    { $$ = $1; $$->addInstruction($2); }
		                | instruction           		        { $$ = new ListInstruction(); $$->addInstruction($1); }
                        |                                       { $$ = new ListInstruction(); }
                        ;

parametre               : declaration   { $$ = $1; }
                        ;


declaration             : type nom                          { $$ = new Declaration( $1 , $2, false, 0); cout<<"non tab"<<endl; }      // ajouter les crochet 
                        | type nom CROCHETOUV CROCHETFERM   { $$ = new Declaration( $1 , $2, true, 0); cout<<"tab"<<endl; }
                        | type nom CROCHETOUV ENTIER CROCHETFERM   { $$ = new Declaration( $1 , $2, true, $4 ); cout<<"tab"<<endl; }
                        ;


type 	                : INT32	    		{ $$ = strdup("int32"); }
                        | INT64				{ $$ = strdup("int64"); }
                        | TYPECHAR			{ $$ = strdup("char"); }
                        | VOID	            { $$ = strdup("void"); }
                  		;







nom                 : NOM               { $$ = $1; }
                    ;






cond                	: IF PARENTOUV expression PARENTFERM instruction fin_cond       { $$ = new Cond($3, $5, $6); }
                		;

fin_cond           		: ELSE instruction                                              { $$ = new CondSuite(false, $2); }
              			|                                                               { Instruction * Ipt ; $$ = new CondSuite(true, Ipt ); }
                		;                                                               


loop_statement      	: WHILE PARENTOUV expression PARENTFERM instruction                { $$ = new LoopStatement($3, $5); }
            			| FOR PARENTOUV expression POINTVIRGULE expression POINTVIRGULE expression PARENTFERM instruction
                                                                                        { $$ = new LoopStatement($3, $5, $7, $9); }
            			;




instruction         : expression POINTVIRGULE               { $$ = new Instruction($1); }
                    | bloc                                  { $$ = new Instruction($1); }
                    | loop_statement                        { $$ = new Instruction($1); }
        			| cond                                  { $$ = new Instruction($1); }
          			| retour_fonction POINTVIRGULE          { $$ = new Instruction($1); }
		            | declaration POINTVIRGULE              { $$ = new Instruction($1); }
                    ;



retour_fonction     	: RETURN expression             { $$ = new Return($2); }
                    	;


expression          : ENTIER                             { $$ = new ExpressionEntier($1); cout  << "expresoin : entier " << endl;}
                    | l_value                            { $$ = $1; } 
                    | CHAR                               { $$ = new ExpressionChar($1); cout << "expression : char " << endl; }
                    | appel_fonction                     { $$ = $1; }        
                    | expression ETLOGIQUE expression    { $$ = new ExpressionBinaire($1, $3, "&&"); }
                    | expression OULOGIQUE expression    { $$ = new ExpressionBinaire($1, $3, "||"); }
                    | expression PLUS expression         { $$ = new ExpressionBinaire($1, $3, "+"); }
                    | expression MUL expression          { $$ = new ExpressionBinaire($1, $3, "*"); }
                    | expression DIV expression          { $$ = new ExpressionBinaire($1, $3, "/"); }
                    | expression MOINS expression        { $$ = new ExpressionBinaire($1, $3, "-"); }
                    | expression MODULO expression       { $$ = new ExpressionBinaire($1, $3, "%"); }
                    | expression DECALGAUCHE expression  { $$ = new ExpressionBinaire($1, $3, "<<"); }
                    | expression DECALDROIT expression   { $$ = new ExpressionBinaire($1, $3, ">>"); }
                    | expression XORBINAIRE expression   { $$ = new ExpressionBinaire($1, $3, "^"); }
                    | expression ETBINAIRE expression    { $$ = new ExpressionBinaire($1, $3, "&"); }
                    | expression OUBINAIRE expression    { $$ = new ExpressionBinaire($1, $3, "|"); }
                    | expression INF expression          { $$ = new ExpressionBinaire($1, $3, "<"); }
                    | expression SUP expression          { $$ = new ExpressionBinaire($1, $3, ">"); }
                    | expression INFEG expression        { $$ = new ExpressionBinaire($1, $3, "<="); }
                    | expression SUPEG expression        { $$ = new ExpressionBinaire($1, $3, ">="); }
                    | expression DIFF expression         { $$ = new ExpressionBinaire($1, $3, "!="); }
                    | expression EGALEGAL expression     { $$ = new ExpressionBinaire($1, $3, "=="); }
                    | MOINS expression %prec NEG         { $$ = new ExpressionUnaire($2, "-"); }
                    | INV expression                     { $$ = new ExpressionUnaire($2, "~"); }
                    | l_value EGALE expression           { $$ = new Affectation($1, "=", $3); cout <<"lvalue = expression" << endl; }
        			| l_value PLUSEGAL expression        { $$ = new Affectation($1, "+=", $3); }
          			| l_value MOINSEGAL expression       { $$ = new Affectation($1, "-=", $3); }
        			| l_value DIVEGAL expression         { $$ = new Affectation($1, "/=", $3); }
                    | l_value MULEGAL expression         { $$ = new Affectation($1, "*=", $3); }  
                    | l_value MODULOEGAL expression      { $$ = new Affectation($1, "%=", $3); }
                    | l_value DECALGAUCHEEGAL expression { $$ = new Affectation($1, "<<=", $3); }
                    | l_value DECALDROITEGAL expression  { $$ = new Affectation($1, ">>=", $3); }
                    | l_value ETEGAL expression          { $$ = new Affectation($1, "&=", $3); }
                    | l_value XOREGAL expression         { $$ = new Affectation($1, "^=", $3); }
                   	| l_value OUEGAL expression          { $$ = new Affectation($1, "|=", $3); }
                    | l_value PLUSPLUS                   { $$ = new AffectationUnaire($1, "++"); }
                    | l_value MOINSMOINS                 { $$ = new AffectationUnaire($1, "--"); }
                   	| PARENTOUV expression PARENTFERM    { $$ = $2; } 
                    ;


appel_fonction      : nom PARENTOUV args_appel_fonction PARENTFERM { $$ = new AppelFonction( $1, $3); }
                    ;


args_appel_fonction : args_appel_fonction VIRGULE expression        { $$ = $1 ; $$->add($3); }
                    | expression                                    { $$ = new ArgsAppel(); $$->add($1); }
                    |                                               { $$ = new ArgsAppel(); } 
                    ;

l_value             : NOM                                           { $$ = new LValue($1,false, -1); }
                    | NOM CROCHETOUV ENTIER CROCHETFERM             { $$ = new LValue($1,true, $3); }
                    ;




nom_variable        : NOM               { $$ = $1; }  // gérer les tableau
        			;


ligne               : CHAINE { $$ = $1; }
                    ;

%%

void yyerror(Programme** pgm, const char * msg) {
   cerr << "Syntax error : " << msg << endl;
}

int main(void) {
    Programme** result = new Programme* ;
#ifndef DEBUG
    string filename = "log.txt";
    std::ofstream output(filename.c_str());
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(output.rdbuf()); //redirect std::cout to log.txt!
#endif
    // les cout de yyparse sont jeté à la corbeille
    yyparse(result);
    
#ifndef DEBUG
    std::cout.rdbuf(coutbuf); //reset to standard output again
#endif
    (*result)->print();
    cout << "Verification de variable " << endl; 
    (*result)->checkContexte();

    PreIR preIR;
    preIR.launchPreIR(*result);

    delete *result;
    delete result;
    return 0;
}

