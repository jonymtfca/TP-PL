%{
  #include <stdio.h>
  #include "mydefs.h"

  Imagem img;
%}

%union {
     int valor; 
     int inteiro; 
     char *texto;
}

%type <tcor>		cor
%type <texto>		FICHEIRO
%token <inteiro>	INTEIRO

%token NOVA ABRIR GUARDAR COR PONTO LINHA RETANGULO RETFILL CIRCUNF LINHAS FIM  

%start s
%% 
s: comandos FIM	
 ;
comandos	:comandos comando ';'
		|comando ';'
		;
comando		:nova
		|abrir
		|guardar
		|cor
		|ponto
		|linha
		|retangulo
		|retfill
		|circunf
		|linhas
		;
nova		:NOVA coordenada cor { } 
abrir		:ABRIR FICHEIRO { abrirFicheiro($2,&img); }
guardar		:GUARDAR FICHEIRO { guardarFicheiro($2,&img); }

%%

int yyerror(char const *s) {
	fprintf(stderr,"Upps occoreu um erro: %s\n",s);	
	return 0;
}

int main() {
	yyparse(); 
	return 0;
}

