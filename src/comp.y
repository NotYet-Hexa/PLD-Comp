%{
#include <iostream>
using namespace std;
void yyerror(int*, const char*);
int yylex(void);
%}

// description des symboles non terminaux
%union {
    int ival;
}

%token <ival> ENTIER
%token PLUS MOINS DIV MUL MODULO PARENTOUV PARENTFERM

%type <ival> expressionevalue

%left MOINS PLUS
%left MUL DIV MODULO

%parse-param { int* resultat }

%%
axiome :    expressionevalue { *resultat = $1; }
            ; 

expressionevalue    : expressionevalue PLUS expressionevalue { $$ = $1 + $3; }
                    | expressionevalue MOINS expressionevalue { $$ = $1 - $3; }
                    | expressionevalue DIV expressionevalue { $$ = $1 / $3; }
                    | expressionevalue MUL expressionevalue { $$ = $1 * $3; }
                    | expressionevalue MODULO expressionevalue { $$ = $1 % $3; }
                    | ENTIER { $$ = $1; }
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