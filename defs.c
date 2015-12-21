// cria e guarda o ficheiro da imagem com extenção .pnm
int guardarFicheiro(char* nome, Imagem* img)
{
	FILE *f = fopen(nome, "w");

	if (f == NULL) {
  		printf( "Não é possivel gravar o ficheiro %s!\n", nome);
		return 0;
	}

	fprintf(f,"P3\n");
	
	fprintf(f,"%d %d\n", img->dimensao.x, img->dimensao.y);
	fprintf(f,"255\n");
	int i,j;
	for(j=0; j < img->dimensao.x; j++)
	{
		for (i=0; i < img->dimensao.y; i++)
		{ 
			fprintf(f, "%d %d %d\t",  img->pixel[i][j].r, 
						  img->pixel[i][j].g, 
						  img->pixel[i][j].b);		
		}
		fprintf(f,"\n");	
	}
	fclose(f);
	return 1;
}


//Funcao para abrir imagem
int abrirFicheiro(char* nome, Imagem* img)
{
	FILE *f = fopen(nome, "r");
	int count = 1;
	TCOR corLida;
	
	f = fopen( nome , "r");
	if (f == NULL) {
  		printf( "Não é possivel abrir o ficheiro %s!\n", nome);
		return 0;
	}
	char line [ 128 ]; 

      	while ( fgets ( line, sizeof line, f ) != NULL ) /* ler linha a linha */
      	{

		if (count == 2)
		{
			int x, y;
			sscanf(line, "%d %d", &x, &y);
			img->dimensao.x = x;
			img->dimensao.y = y;
		}
		else if (count >2)
		{
			// vai intepretar as cores dos pixeis
			char *token;		
			
			int r, g, b;
			
			int i;
			for (i = 0; i < img->dimensao.x; i++)
			{
				token = strtok(line, "\t");
				
				sscanf(token, "%d %d %d", &r, &g, &b);
				printf("token  [%s]  r:%d g:%d b:%d\n" , token, r, g, b);
				corLida.r = r;
				corLida.g = g;
				corLida.b = b;
				img->pixel[count-3][i] = corLida;
				
			}
		
		}
		count++;
		
	}
		
	
	fclose(f);
	
	return 1;
}
