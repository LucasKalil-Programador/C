#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// retorna um numero aleatorio
int randomNumber(int Max, int Min)
{
	int Number;
	// gera e verifica o numero aleatorio
	do
	{
		srand(time(NULL));
		Number = rand() % Max + Min;
	}
	while(Number > Max || Number < Min);

	return Number;
}

// pede uma das opçoes de tema
int selecionarTema()
{
	printf("\n                       Qual modo de jogo voce deseja?");
	printf("\n                       1 para nomes");
	printf("\n                       2 para paises");
	printf("\n                       3 para frutas");
	printf("\n\n                       Digite uma opcao:");
	int i;
	// pede para o usuario um opcao caso ela nao seja uma opcao valida pede novamente
	do
	{
		scanf("%i", &i);
		if(i > 3 || i < 1)
		{
			printf("\r\n                       Opcao invalida");
			printf("\r\n\r\n                       Digite outra opcao:");
		}
	}
	while(i > 3 || i < 1);
	return i;
}

// gera uma palavra aleatoria
int randomWord(char *palavra)
{
	// inicializa as variaveis ultilizadas
	FILE *fileTexto;
	char texto[100][25];
	int size = sizeof(texto[0]) / sizeof(char);
	int RN;

	switch(selecionarTema())
	{
	case 1:
		fileTexto = fopen("nomes.txt", "r");
		break;
	case 2:
		fileTexto = fopen("paises.txt", "r");
		break;
	case 3:
		fileTexto = fopen("frutas.txt", "r");
		break;
	default:
		fileTexto = fopen("nomes.txt", "r");
		break;
	}

	// verifica se o arquivo existe
	if(fileTexto == NULL)
	{
		printf("\nErro ao abrir paises.txt\n");
		exit(0);
	}
	else
	{
		// le todas as palavras do .txt
		int i = 0;
		while(fgets(texto[i], size, fileTexto) != NULL)
		{
			i++;
			if(i >= 100) break;
		}

		RN = randomNumber(i, 0);

		// remove a pula de linha e coloca o resultado na palavra
		for(i = 0; i < size; i++)
		{
			if(texto[RN][i] == '\n')
			{
				palavra[i] = (int)NULL;
			}
			else if(texto[RN][i] == ' ')
			{
				palavra[i] = (int)NULL;
			}
			else
			{
				palavra[i] = texto[RN][i];
			}
		}

		// retorna o tamanho da palavra
		for(i = 0; i < size; i++)
		{
			if(palavra[i] == (int)NULL)
			{
				break;
			}
		}
		return i;
	}
}

// imprime um banco de palavras selecionado
void imprimirPalavras()
{
	// inicializa as variaveis ultilizadas
	FILE *fileTexto;
	char texto[25];
	int size = sizeof(texto) / sizeof(char);

	switch(selecionarTema())
	{
	case 1:
		fileTexto = fopen("nomes.txt", "r");
		break;
	case 2:
		fileTexto = fopen("paises.txt", "r");
		break;
	case 3:
		fileTexto = fopen("frutas.txt", "r");
		break;
	default:
		fileTexto = fopen("nomes.txt", "r");
		break;
	}

	// verifica se o arquivo existe
	if(fileTexto == NULL)
	{
		printf("\nErro ao abrir paises.txt\n");
		exit(0);
	}
	else
	{
		// le todas as palavras do .txt e imprime na tela
		int i = 0;
		printf("\r\n");
		while(fgets(texto, size, fileTexto) != NULL)
		{
			i++;
			printf("                       %s", texto);
			if(i >= 100) break;
		}
		printf("\r\n\r\n");
	}
	system("pause");
}


