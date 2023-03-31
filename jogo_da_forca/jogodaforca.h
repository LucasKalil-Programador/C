#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "listase.h"
#include "util.h"

void jogar()
{


	// gera uma nova palavra aleatoria
	char string[25];
	int size = randomWord(string);
	tp_listase *palavra = inicializa_listase();
	tp_listase *listaseChutes = inicializa_listase();

	// insere a palavra na listase palavra
	int i;
	for(i = 0; i < size; i++)
	{
		char ch = string[i];
		// transforma todas as letras em maiusculo
		insere_listase_no_fim(&palavra, toupper(ch));
	}

	short tentativas = 8;
	short acertos = 0;

	do
	{
		// zera os acertos para contar novamente
		acertos = 0;

		// escreve chutes na palavra
		printf("\r\n");
		artForca(tentativas, listaseChutes);
		for(i = 0; i < size; i++)
		{
			char r = '_';
			char letra = pegar_da_listase(palavra, i);
			int k;
			for(k = 0; k < tamanho_listase(listaseChutes); k++)
			{
				// caso a letra da lista de palavra exista na lista de chutes ele imprime na tela
				if(letra == pegar_da_listase(listaseChutes, k))
				{
					r = letra;
					break;
				}
			}
			// caso a letra seja diferente do underline ele faz um ponto
			if(r != '_')
			{
				acertos++;
			}
			printf("%c ", r);
		}

		// verifica vitoria
		// caso o usuario acerte o todas as letras o do{}while para e vitoria
		if(acertos >= size)
		{
			break;
		}
		else
		{
			printf(" Voce tem %d tentativas\r\n\r\n", tentativas);
		}

		// pede um novo chute e converte o chute para letra maiuscula
		char chute;
		printf("Digite seu chute:");
		scanf(" %c", &chute);
		chute = toupper(chute);

		// verifica tentativas
		if(busca_listase(palavra, chute) == NULL && busca_listase(listaseChutes, chute) == NULL)
		{
			tentativas--;
		}

		// verifica se o chute ja foi chutado antes
		// caso ele tenha repetido um chute ele continua e pede um novo chute
		// caso ele tenha colocado um novo chute ele verifica se o chute não é nulo e insere na lista de chutes
		if(busca_listase(listaseChutes, chute) == NULL)
		{
			// insere o novo chute na listase Chutes
			if(chute != '\0')
			{
				insere_listase_no_fim(&listaseChutes, chute);
			}
		}
	}
	while(tentativas > 0);

	// caso o jogador perca ou seja tentativas = 0
    // mostra as mensagens e fala qual era a palavra secreta
    // pede para o usuario apertar qualquer tecla para continuar
	if(tentativas <= 0)
	{
		artForca(0, listaseChutes);
		printf(" Que pena voce perdeu a palavra era | ");
		imprime_listase(palavra);
		printf(" |\r\n\r\n");
		system("pause");
	}
	// caso o jogador tenha ganhado ou seja acertos == size
    // mostra a mensagens de parabens
    // pede para o usuario apertar qualquer tecla para continuar
	else if(acertos >= size)
	{
		printf("| Parabens voce ganhou !!!");
		printf("\r\n\r\n");
		system("pause");
	}
}

