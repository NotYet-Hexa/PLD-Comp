%{

using namespace std;

#include <iostream>
#include <string>
#include <vector>

#include "Contexte.h"

#include "Expression.h"
#include "ExpressionChar.h"
#include "ExpressionEntier.h"
#include "ExpressionVariable.h"
#include "ExpressionBinaire.h"
#include "Instruction.h"

#include "Declaration.h"
#include "DeclarationFonction.h"
#include "DefFonction.h"

#include "Retour_Fonction.h"

#include "ArgsDef.h"

#include "ListInstruction.h"
#include "Bloc.h"
#include "Programme.h"

//AJOUT
#include "Contexte.h"

// struct resultat {
//     int integer;
//     string character;
//     Expression * expression;
//     Instruction * instruction;
//     ListInstruction * liste_instruction;
//     Bloc * bloc;
// };

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
%type<ival> liste_nom
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

programme		    : liste         {  $$ = new Programme(vector<Contexte*>(),$1); } 
			        ;

liste			    : definition_de_fonction            { $$ = new Briques(); $$->add($1); } 
                    | declaration_de_fonction           { $$ = new Briques(); $$->add($1); } 
                    | declaration                       { $$ = new Briques(); $$->add($1);  /*checked*/ }
			        | liste definition_de_fonction      { $$ = $1; $$->add($2); } 
			        | liste declaration_de_fonction     { $$ = $1; $$->add($2); } 
			        | liste declaration                 { $$ = $1; $$->add($2); /*checked*/ } 
			        |                                   { $$ = new Briques(); }    
                    ;

declaration_de_fonction  	: type_retour_fonction nom_fonction PARENTOUV args_def PARENTFERM POINTVIRGULE 
                            { DeclarationFonction($2, $1, $4); }
                            ;

definition_de_fonction    	: type_retour_fonction nom_fonction PARENTOUV args_def PARENTFERM bloc
                           	;


type_retour_fonction        : type          { $$ = $1; }
                            | VOID	        { $$ = "void"; }
                            ;

args_def                    : parametre         { $$ = new ArgsDef(); $$->add($1); }
                            | args_def VIRGULE parametre { $$ = $1 ; $$->add($3); }
                           	| VOID              { $$ = new ArgsDef(); }
                            |                   { $$ = new ArgsDef(); }
                            ;


bloc                        :  ACCOLOUV liste_instruction  ACCOLFERM    { $$ = new Bloc($2); }
                            ;


liste_instruction	    : liste_instruction instruction 	{ $$ = $1; $$->addInstruction($2); }
		                | instruction			            { $$ = new ListInstruction(); $$->addInstruction($1);}
                        |
                        ;

parametre               : declaration   { $$ = $1; }
                        ;


nom_parametre           : nom_variable                              
                        | nom_variable CROCHETOUV CROCHETFERM       
                        ;

declaration             : type nom POINTVIRGULE     {  $$ = new Declaration( $1 , $2); }
                        ;


type 	                : INT32	    		{ $$ = "int32"; }
                        | INT64				{ $$ = "int64"; }
                        | TYPECHAR			{ $$ = "char"; }
                  		;



liste_nom               : nom       
                        ;

nom                     : NOM aff           
                        | NOM CROCHETOUV ENTIER CROCHETFERM 
                        ;

aff 	                : EGALE expression 
                        |
                        ;


appel_fonction      : nom_fonction PARENTOUV args_appel_fonction PARENTFERM
        			;


nom_fonction        : NOM               { $$ = $1; }
                    ;


args_appel_fonction 	: args_appel_fonction VIRGULE expression 
                    	| expression
                   		;

retour_fonction     	: RETURN expression
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



instruction         : expression POINTVIRGULE           { $$ = new Instruction($1); }
                    | bloc
                    | loop_statement 
        			| cond 
          			| retour_fonction 
		            | declaration                       { $$ = new Instruction($1); }
                    | lecture_ecriture POINTVIRGULE
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
   cout << "Syntax error : " << msg << endl;
}

int main(void) {
    Programme** result = new Programme* ;
    yyparse(result);
    (*result)->print();
    //result.liste_instruction->print();
    //result.instruction->print();

    /* VALGRIND A VOIR

    Contexte* contexte1 = new Contexte("Programme");
    Contexte* contexte2 = new Contexte("Bloc");
    contexte1->ajouterVariable("a","int");
    contexte1->ajouterVariable("b","char");
    cout << "Variable Ajoutee" << endl;

    if(contexte1->chercherVariable("a"))
        cout << "Variable Trouvee" << endl;
    else
        cout << "Variable Non Trouvee" << endl;

    if(contexte2->chercherVariable("a"))
        cout << "Variable Trouvee" << endl;
    else
        cout << "Variable Non Trouvee" << endl;
    contexte2->ajouterVariable("a","int");
    contexte2->ajouterVariable("b","int");
    contexte2->ajouterVariable("c","int");
    if(contexte1->chercherVariable("a"))
        cout << "Variable Trouvee" << endl;
    else
        cout << "Variable Non Trouvee" << endl;
    Contexte::test_AfficherTableDesSymboles();   
     (contexte1);
    delete(contexte2);
    cout << "Contexte Suprime" << endl;

    */
// #ifdef CHAINE
//     cout << result.character << endl;
// #endif
//     cout << result.integer << endl;
    return 0;
}

