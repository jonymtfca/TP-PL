typedef struct imagem {
		TXY dimensao;
		TCOR pixel[500][500];
             }  Imagem;

int abrirFicheiro(char* nome, Imagem* img);
int guardarFicheiro(char* , Imagem* );

