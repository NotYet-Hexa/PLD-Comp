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
#include "Declaration.h"
#include "ListInstruction.h"
#include "Bloc.h"

//AJOUT
#include "Contexte.h"

struct resultat {
    int integer;
    string character;
    Expression * expression;
    Instruction * instruction;
    ListInstruction * liste_instruction;
    Bloc * bloc;
};

void yyerror(resultat*, const char*);
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
    ListInstruction* liste_instruction;
    Bloc * bloc;
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

%token VOID INT32 INT64 TYPECHAR FOR WHILE IF ELSE RETURN

// %type <ival> expressionevalue
%type <expression> expression
%type <chaine> ligne
%type <instruction> instruction
%type <declaration> declaration
%type <liste_instruction> liste_instruction
%type <bloc> bloc

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
                    | liste_instruction                 { result->liste_instruction = $1; }
                    | bloc                              { result->bloc = $1; }
                    | expression                        { result->expression = $1; }
                    ; 

bloc                :  ACCOLOUV liste_instruction  ACCOLFERM    { $$ = new Bloc($2); }
                    ;

liste_instruction	    : liste_instruction instruction 	{ $$ = $1; $$->addInstruction($2); }
		    | instruction			{ $$ = new ListInstruction(); $$->addInstruction($1);}
		    ;

instruction         : expression POINTVIRGULE           { $$ = new Instruction($1); }
		            | declaration POINTVIRGULE          { $$ = new Instruction($1); } 
		            ;


declaration  	    : VOID NOM 				{ $$ = new Declaration("void", $2);} 
                    | INT32  NOM			{ $$ = new Declaration("int32", $2);}
                    | INT64 NOM				{ $$ = new Declaration("int64", $2);}
                    | TYPECHAR NOM			{ $$ = new Declaration("char", $2);}
                    ;

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
    //resultat result;
    //yyparse(&result);
    //result.bloc->print();
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
    delete(contexte1);
    delete(contexte2);
    cout << "Contexte Suprime" << endl;

    */
// #ifdef CHAINE
//     cout << result.character << endl;
// #endif
//     cout << result.integer << endl;
    return 0;
}

