%{
using namespace std;

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "Contexte.h"

#include "Expression.h"
#include "ExpressionChar.h"
#include "ExpressionEntier.h"
#include "ExpressionVariable.h"
#include "ExpressionBinaire.h"
#include "AppelFonction.h"
#include "Instruction.h"
#include "Return.h"
#include "Affectation.h"
#include "AffectationUnaire.h"




#include "Declaration.h"
#include "DeclarationFonction.h"
#include "DefFonction.h"
#include "DeclarationGlobal.h"


#include "ArgsDef.h"

#include "ListInstruction.h"
#include "Bloc.h"
#include "Programme.h"

#include "Briques.h"
#include "Brique.h"

//AJOUT
#include "Contexte.h"

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

"void"                { return VOID; }
"int32_t"             { return INT32; }
"int64_t"             { return INT64; }
"char"                { return TYPECHAR; }
"for"                 { return FOR; }
"while"               { return WHILE; }
"if"                  { return IF; }
"else"                { return ELSE; }
"return"              { return RETURN; }

{charactere}        { yylval.charactere = yytext[1]; return CHAR; }
{chaine}            { yylval.chaine = strdup(yytext); return CHAINE; }
{nom}               { yylval.chaine = strdup(yytext); return NOM; }

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
","                 { return VIRGULE; }
"<"                 { return INF; }
">"                 { return SUP; }
"<="                { return INFEG; }
">="                { return SUPEG; }
"!="                { return DIFF; }
"=="                { return EGALEGAL; }


