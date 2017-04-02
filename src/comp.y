%{

using namespace std;

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
#include "ExpressionBinaire.h"
#include "Instruction.h"

#include "Declaration.h"
#include "DeclarationGlobal.h"
#include "DeclarationFonction.h"
#include "DefFonction.h"

#include "Retour_Fonction.h"

#include "ArgsDef.h"

#include "ListInstruction.h"
#include "Bloc.h"
#include "Programme.h"

#include "Briques.h"
#include "Brique.h"

//AJOUT
#include "Contexte.h"



void yyerror(Programme**, const char*);
int yylex(void);

%}


// description des symboles non terminaux
%union {
    int ival;
    char charactere;
    Expression * expression;
    Instruction * instruction;
    char* chaine;

    Declaration* declaration;
    DeclarationGlobal * declarationGlobal;
    DeclarationFonction* declaration_fonction;
    DefFonction*  definition_fonction;

    Retour_Fonction* retour_fonction;

    Briques* briques;

    ArgsDef * args;

    ListInstruction* liste_instruction;
    Bloc * bloc;
    Programme* program;
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
%token POINTVIRGULE VIRGULE

%token EGALEGAL DIFF 
%token INFEG INF SUP SUPEG

%token VOID INT32 INT64 TYPECHAR FOR WHILE IF ELSE RETURN PUTCHAR GETCHAR

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

%type<chaine> type_retour_fonction
%type<chaine> nom_fonction
%type<args> args_def
%type<chaine> type

%type<declaration> parametre
%type<ival> loop_statement
%type<ival> cond 
%type<retour_fonction> retour_fonction
%type<chaine> nom_parametre
%type<chaine> nom_variable
%type<chaine> nom
%type<ival> aff
%type<ival> l_value
%type<ival> appel_fonction
%type<ival> args_appel_fonction
%type<ival> fin_cond
%type<ival> for_loop
%type<ival> while_loop
%type<ival> lecture_ecriture
%type<ival> suite_lecture
%type<ival> suite_ecriture



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

programme		    : liste         { $$ = new Programme(vector<Contexte*>(),$1); } 
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
                            | type nom CROCHETOUV ENTIER CROCHETFERM   { $$ = new DeclarationGlobal( $1 , $2, true, $4); cout<<"tab"<<endl; }
                            ;
                           	;

args_def                    : parametre                     { $$ = new ArgsDef(); $$->add($1); }
                            | args_def VIRGULE parametre    { $$ = $1 ; $$->add($3); }
                           	| VOID                          { $$ = new ArgsDef(); }
                            |                               { $$ = new ArgsDef(); }
                            ;


bloc                        :  ACCOLOUV liste_instruction  ACCOLFERM    { $$ = new Bloc($2); }
                            ;


liste_instruction	    : liste_instruction instruction 	    { $$ = $1; $$->addInstruction($2); }
		                | instruction           		        { $$ = new ListInstruction(); $$->addInstruction($1);cout <<" une instruction"<<endl; }
                        |                                       { $$ = new ListInstruction(); cout <<"pas d instruction"<<endl; }
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


nom_variable            : nom                               {  $$ = $1; }                                  // a modifer  
                        | nom CROCHETOUV ENTIER CROCHETFERM { $$ = $1; }   
                        | nom aff                           { cout<<"regle de nom "<<endl; $$ = $1; }
                        ;

aff 	                : EGALE expression 
                        |
                        ;


appel_fonction      : nom PARENTOUV args_appel_fonction PARENTFERM
        			;


nom                 : NOM               { $$ = $1; }
                    ;


args_appel_fonction 	: args_appel_fonction VIRGULE expression 
                    	| expression
                   		;



cond                	: IF PARENTOUV expression PARENTFERM instruction fin_cond
                		;

fin_cond           		: ELSE instruction 
              			|
                		;


loop_statement      	: while_loop 
            			| for_loop
            			;


while_loop          	: WHILE PARENTOUV expression PARENTFERM instruction
            			;


for_loop          		: FOR PARENTOUV expression POINTVIRGULE expression POINTVIRGULE expression PARENTFERM instruction
            			;



instruction         : expression POINTVIRGULE               { $$ = new Instruction($1); }
                    | bloc                                  { $$ = new Instruction($1); }
                    | loop_statement 
        			| cond 
          			| retour_fonction 
		            | declaration POINTVIRGULE              { $$ = new Instruction($1); }
                    | lecture_ecriture POINTVIRGULE
		            ;

retour_fonction     	: RETURN expression
                    	;


expression          : ENTIER                            { $$ = new ExpressionEntier($1); }
                    | NOM                               { $$ = new ExpressionVariable($1); }
                    | CHAR                              { $$ = new ExpressionChar($1); }
                    | appel_fonction                              
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
                    | l_value EGALE expression 
        			| l_value PLUSEGAL expression
          			| l_value MOINSEGAL expression
        			| l_value DIVEGAL expression
                    | l_value MULEGAL expression
                    | l_value MODULOEGAL expression
                    | l_value DECALGAUCHEEGAL expression
                    | l_value DECALDROITEGAL expression
                    | l_value ETEGAL expression
                    | l_value XOREGAL expression
                   	| l_value OUEGAL expression
                    | l_value PLUSPLUS
                    | l_value MOINSMOINS
                   	| PARENTOUV expression PARENTFERM
                    ;

l_value             : nom_variable CROCHETOUV ENTIER CROCHETFERM 
            		| nom_variable
                    			;
lecture_ecriture	: GETCHAR suite_lecture
			        | PUTCHAR suite_ecriture
			        ;



suite_ecriture		: PARENTOUV NOM PARENTFERM
			        | PARENTOUV CHAR PARENTFERM
				    ;

suite_lecture		: PARENTOUV NOM PARENTFERM
				    ;

nom_variable        : NOM               { $$ = $1; }
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
    return 0;
}

