%{
 #include "gram.h"
%}

num 	   [0-9]+
texto      [A-Z_a-z\[\]0-9]+\.pnm
%%
"NOVA"          { return NOVA; }
"ABRIR"         { return ABRIR; }
"GUARDAR"       { return GUARDAR; }
"COR"           { return COR; }
"PONTO"         { return PONTO; }
"LINHA"         { return LINHA; }
"RETANGULO"     { return RETANGULO; }
"RETFILL"       { return RETFILL; }
"CIRCUNF"       { return CIRCUNF; }
"LINHAS"        { return LINHAS; }
"FIM"           { return FIM; }
"x" | ":" |
","		 { return yytext[0];   }
{num}	 	 { yylval.valor = atoi(yytext); 
		   return INT;}
{texto}         { yylval.str = strdup(yytext);
		  return TEXTO;} 

[ \n\t]	 { /* ignorar os espaços, mudanças de linha e tabs */ }
.		 { return yytext[0]; }
%%


int yywrap(){ return 1; }
