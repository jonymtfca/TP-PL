%{
  #include <stdio.h>
  #include "mydefs.h"

//aaa  
%}

%union {
     int valor; 
     int inteiro; 
     char *texto;
}

%type <tcor>		cor
%type <texto>		FICHEIRO
%token <inteiro>	INTEIRO

%token NOVA FIM PONTO LINHA LINHAS CORDEFEITO DEBUG FICHEIRO GUARDAR CIRCUNF RETFILL RETANGULO ABRIR

%start s
%% 
s: comandos FIM	

 
