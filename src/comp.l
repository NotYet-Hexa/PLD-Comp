%{
#include <stdio.h>
#include <stdlib.h>
// #include <list>
using namespace std;
#include "comp.tab.h"
%}

%option noyywrap

entier [0-9]+
nom_variable \w+


%%

[ \n\t]     { /* ignore */ }
{entier}    { yylval.ival = atoi(yytext); return ENTIER; }
"+"         { return PLUS; }
"-"         { return MOINS; }
"/"         { return DIV; }
"*"         { return MUL; }
"%"         { return MODULO; }
