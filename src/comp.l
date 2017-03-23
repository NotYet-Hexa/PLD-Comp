%{
#include <stdio.h>
#include <stdlib.h>
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
};
// #include <list>
using namespace std;
#include "comp.tab.h"
%}

%option noyywrap

entier [0-9]+
charactere \"(\\.|[^\\"])\"
chaine \"(\\.|[^\\"])*\"
nom [a-zA-Z_]+


%%

[ \n\t]             { /* ignore */ }
"/*"(.|\n|\r)*"*/"  { /* ignore */ }
"//".*$ 	        { /* ignore */ }

{entier}            { yylval.ival = atoi(yytext); return ENTIER; }

void                { return VOID; }
int32_t             { return INT32; }
int64_t             { return INT64; }
char                { return TYPECHAR; }
for                 { return FOR; }
while               { return WHILE; }
if                  { return IF; }
else                { return ELSE; }
return              { return RETURN; }

{charactere}        { yylval.charactere = yytext[1]; return CHAR; }
{chaine}            { yylval.chaine = yytext; return CHAINE; }
{nom}               { yylval.chaine = yytext; return NOM; }

"+"                 { return PLUS; }
"-"                 { return MOINS; }
"/"                 { return DIV; }
"*"                 { return MUL; }
"%"                 { return MODULO; }
"="                 { return EGALE; }
"("                 { return PARENTOUV; }
")"                 { return PARENTFERM; }
"{"                 { return ACCOLOUV; }
"}"                 { return ACCOLFERM; }
"["                 { return CROCHETOUV; }
"]"                 { return CROCHETFERM; }
"++"                { return PLUSPLUS; }
"--"                { return MOINSMOINS; }
"+="                { return PLUSEGAL; }
"-="                { return MOINSEGAL; }
"/="                { return DIVEGAL; }
"*="                { return MULEGAL; }
"%="                { return MODULOEGAL; }
"<<="               { return DECALGAUCHEEGAL; }
">>="               { return DECALDROITEGAL; }
"&="                { return ETEGAL; }
"|="                { return OUEGAL; }
"^="                { return XOREGAL; }
"&&"                { return ETLOGIQUE; }
"||"                { return OULOGIQUE; }
"<<"                { return DECALGAUCHE; }
">>"                { return DECALDROIT; }
"^"                 { return XORBINAIRE; }
"|"                 { return OUBINAIRE; }
"&"                 { return ETBINAIRE; }
"~"                 { return INV; }
";"                 { return POINTVIRGULE; }
"<"                 { return INF; }
">"                 { return SUP; }
"<="                { return INFEG; }
">="                { return SUPEG; }
"!="                { return DIFF; }
"=="                { return EGALEGAL; }


