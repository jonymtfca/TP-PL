%{
  #include <stdio.h>
  #include "mydefs.h"
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
nova		:NOVA coordenada cor 
