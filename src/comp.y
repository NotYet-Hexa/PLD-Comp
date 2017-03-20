%{
#include <iostream>
using namespace std;
void yyerror(int*, const char*);
int yylex(void);
%}

// description des symboles non terminaux
%union {
    int ival;
    char charactere;
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

%type <ival> expressionevalue

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

%parse-param { int* resultat }

%%

axiome              : expressionevalue                              { *resultat = $1; }
                    ; 

expressionevalue    : MOINS expressionevalue %prec NEG              { $$ = -$2; }
                    | expressionevalue PLUS expressionevalue        { $$ = $1 + $3; }
                    | expressionevalue MOINS expressionevalue       { $$ = $1 - $3; }
                    | expressionevalue DIV expressionevalue         { $$ = $1 / $3; }
                    | expressionevalue MUL expressionevalue         { $$ = $1 * $3; }
                    | expressionevalue MODULO expressionevalue      { $$ = $1 % $3; }
                    | PARENTOUV expressionevalue PARENTFERM         { $$ = $2; }
                    | expressionevalue PLUSPLUS                     { $$ = $1++; }
                    | expressionevalue MOINSMOINS                   { $$ = $1--; }
                    | expressionevalue DECALGAUCHE expressionevalue { $$ = $1 << $3; }
                    | expressionevalue DECALDROIT expressionevalue  { $$ = $1 >> $3; }
                    | expressionevalue XORBINAIRE expressionevalue  { $$ = $1 ^ $3; }
                    | expressionevalue OUBINAIRE expressionevalue   { $$ = $1 | $3; }
                    | expressionevalue ETBINAIRE expressionevalue   { $$ = $1 & $3; }
                    | ENTIER                                        { $$ = $1; }
                    ;
%%

void yyerror(int* exp, const char * msg) {
   cout << "Syntax error : " << msg << endl;
}

int main(void) {
   int result; // allocation de prgm
   yyparse(&result);
   cout << result << endl;
   return 0;
}