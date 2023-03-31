#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AsciiArt.h"
#include "jogodaforca.h"

int main()
{
	// sistema que determina o prograsso do programa
	// no caso 1 o usuario vai jogar escolher o tema e jogar normalmente
	// no caso 2 o usuario vai ter acesso ao banco de palavras dos tres temas
	// no caso 3 o usuario finaliza o programa
	while (TRUE)
	{
		system("cls");
		switch (artBemVindo())
		{
		case 1:
			jogar();
			break;
		case 2:
			imprimirPalavras();
			break;
		case 3:
			exit(0);
			break;
		default:
			exit(0);
			break;
		}
	}
	return 0;
}
