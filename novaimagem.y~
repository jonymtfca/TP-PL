%{
  #include <stdio.h>
  #include "mydefs.h"

  /*Imagem globalImage;
  TCOR 	 corDefeito;*/
  
%}

%union {
     int valor; 
     int inteiro; 
     TCOR tcor;
     TXY txy;
     char *texto;
}

%type <tcor>		cor
%type <txy>		coordenada
%type <txy>		dimensao
%type <texto>		FICHEIRO
%token <inteiro>	INTEIRO

%token NOVA FIM PONTO LINHA LINHAS CORDEFEITO DEBUG FICHEIRO GUARDAR CIRCUNF RETFILL RETANGULO ABRIR

%start s
%% 
s: comandos FIM	

 
