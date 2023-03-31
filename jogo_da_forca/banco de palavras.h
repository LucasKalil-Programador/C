#include <stdio.h>
#include <stdlib.h>

void imprimirPalavras()
{
	// inicializa as variaveis ultilizadas
	FILE *fileTexto;
	
	switch(selecionarTema())
	{
	case 1:
		fileTexto = fopen("nomes.txt", "r");
		break;
	case 2:
		fileTexto = fopen("nomes.txt", "r");
		break;
	case 3:
		fileTexto = fopen("nomes.txt", "r");
		break;
	default:
		fileTexto = fopen("nomes.txt", "r");
		break;
	}
	
	char texto[25];
	int size = sizeof(texto) / sizeof(char);

	// verifica se o arquivo existe
	if(fileTexto == NULL)
	{
		printf("\nerro ao abrir paises.txt\n");
		exit(0);
	}
	else
	{
		// le todas as palavras do .txt
		int i = 0;
		while(fgets(texto, size, fileTexto) != NULL)
		{
			i++;
			printf("%s", texto);
			if(i >= 100) break;
		}
	}
	system("pause");
}