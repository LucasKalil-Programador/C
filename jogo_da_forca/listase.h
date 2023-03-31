#ifndef LISTASE_H
#define LISTASE_H

#include<stdio.h>
#include <stdlib.h>

typedef char tp_item;

typedef struct tp_no
{
	tp_item info;
	struct tp_no *prox;
} tp_listase;

tp_listase *inicializa_listase()
{
	return NULL;
}

int listase_vazia(tp_listase *lista)
{
	if(lista == NULL) return 1;
	return 0;
}

tp_listase *aloca_listase()  // ela ir� alocar um espa�o na mem�ria;
{
	tp_listase *novo_no;
	novo_no = (tp_listase*) malloc(sizeof(tp_listase));
	return novo_no;
}

int insere_listase_no_fim(tp_listase **l, tp_item e)  // Esse **l � um ponteiro que est� apontando para outro ponteiro para o endere�o de mem�ria original da listase*, o que est� apontando para o NULL
{
	tp_listase *novo_no, *atu;
	novo_no = aloca_listase(); // aqui est� pegando o novo n� e apontando para o NULL;
	if(novo_no == NULL) return 0; // N�o alocou mem�ria
// atribuir os valores para o novo n�;
	novo_no->info = e;
	novo_no->prox = NULL;
//finaliza o encadeamento do n�
	if(listase_vazia(*l)) // se for o primeiro n� entra aqui
	{
		*l = novo_no;
	}
	else
	{
		atu = *l;
		while(atu->prox != NULL)
		{
			atu = atu->prox; // aponta para o ultimo n�
		}
		atu->prox = novo_no;
	}
	return 1;
}


int insere_listase_inicio(tp_listase **l, tp_item e)  // Esse **l � um ponteiro que est� apontando para outro ponteiro para o endere�o de mem�ria original da listase*, o que est� apontando para o NULL
{
	tp_listase *novo_no;
	novo_no = aloca_listase(); // aqui est� pegando o novo n� e apontando para o NULL;

//fica assim:
//foti 23/10/2017
// *lista = *l
	if(novo_no == NULL) return 0; // N�o alocou mem�ria
// atribuir os valores para o novo n�;
	novo_no->info = e;
	novo_no->prox = NULL;
//finaliza o encadeamento do n�
	if(listase_vazia(*l)) // se for o primeiro n� entra aqui
	{
		*l = novo_no;
	}
	else
	{
		//atu = *l;
		//while(atu->prox!=NULL){
		//atu=atu->prox; // aponta para o ultimo n�

		//}
		novo_no->prox = *l; // add
		*l = novo_no; // add

		//atu->prox=novo_no;

	}
	return 1;
}

void imprime_listase(tp_listase *lista)
{
	tp_listase *atu;
	atu = lista;
	while (atu != NULL)
	{
		printf("%c", atu->info);
		atu = atu->prox;
	}
}

void imprime_listase_formatado(tp_listase *lista)
{
	tp_listase *atu;
	atu = lista;
	if(atu != NULL){
		printf("As letras chutadas --> |");	
	}
	
	while (atu != NULL)
	{
		printf(" %c |", atu->info);
		atu = atu->prox;
	}
}

char pegar_da_listase(tp_listase *lista, int n)
{
	tp_listase *atu;
	atu = lista;
	int i = 0;
	while (atu != NULL)
	{
		if(i == n) return atu->info;
		atu = atu->prox;
		i++;
	}
	return '0';
}

int remove_listase(tp_listase **lista, tp_item e)
{
	tp_listase * ant, *atu;
	atu = *lista;
	ant = NULL;
	while ((atu != NULL) && (atu->info != e))
	{
		ant = atu;
		atu = atu->prox;
	}
	if (atu == NULL) return 0; // n�o foi encontrado o elemento
	if (ant == NULL) // se for retirado o primeiro termo
	{
		*lista = atu->prox; // fazendo a lista apontar para o termo subsequente que foi retirado
	}
	else
	{
		ant->prox = atu->prox; //fazendo a interliga��o entre o termo anterior e o termo subsequente ao termo retirado
	}
	free(atu);
	atu = NULL;
	return 1;
}

tp_listase *busca_listase(tp_listase *lista,
						  tp_item e)
{
	tp_listase *atu;
	atu = lista;
	while((atu != NULL) && (atu->info != e))
	{
		atu = atu->prox;
	}
	if (atu == NULL) return NULL;
	return atu;
}

int tamanho_listase(tp_listase *lista)
{
	int cont = 0;
	tp_listase *atu;
	atu = lista;
	while(atu != NULL)
	{
		cont++;
		atu = atu->prox;
	}
	return cont;
}


/*
1o Alocamos mem�ria para o n�
2o Preenchemos os dados do n� (info)
3o Encadear o n� na lista
	3.1o Quando a lista estiver vazia => Ligo o novo n� ao ponteiro do main (*lista)
	3.2o Quando a lista n�o estiver vazia => Ligo o novo n� com o que antes era o �ltimo n�
*lista [320] ->  [10 |100] -> [ 20 | 120 ]	-> [ 30 |200 ]  -> [ 32 | 130 ] -> [35 |150 ] -> [40 | NULL]
				  320 		   100	 			120	    		200				130		       150	*/



int insere_em_ordem_listase(tp_listase **lista, tp_item e)  // Esse **lista � um ponteiro que est� apontando para outro ponteiro para o endere�o de mem�ria original da listase*, o que est� apontando para o NULL
{
	tp_listase *novo_no, *atu, *ant;
	novo_no = aloca_listase(); // aqui est� pegando o novo n� e alocando ele (criando a struct);
	if(novo_no == NULL) return 0; // N�o alocou mem�ria
	// atribuir os valores para o novo n�;
	novo_no->info = e; // atribuindo valores para o novo n�
	atu = *lista;
	ant = NULL;
	//la�o para percorrer a lista encadeada enquanto n�o chegar no fim
	while((atu != NULL) && (atu->info < novo_no->info))
	{
		ant = atu;
		atu = atu->prox;
	}
	if (ant == NULL) // inserir antes do primeiro
	{
		*lista = novo_no;
	}
	else
	{
		ant->prox = novo_no;
	}
	novo_no->prox = atu;
	return 1;
}
/*
4)	Construa uma fun��o que receba duas listas e retorne 1
 caso elas sejam id�nticas ou 0, caso contr�rio.*/



int listase_igual(tp_listase *l1, tp_listase *l2)
{
	tp_listase *atu1, *atu2;
	atu1 = l1;
	atu2 = l2;
	if(tamanho_listase(atu1) != tamanho_listase(atu2)) return 0;
	while(atu1 != NULL)
	{
		if(atu1->info != atu2->info)
		{
			return 0;
		}
		atu1 = atu1->prox;
		atu2 = atu2->prox;
	}
	return 1;
}



int qtde_nos_maiores(tp_listase *lista, tp_item n)
{
	int cont = 0;
	tp_listase *atu;
	atu = lista;
	while(atu != NULL)
	{
		if (atu->info > n)
			cont++;
		atu = atu->prox;
	}
	return cont;
}


void listacircular(tp_listase *lista1, tp_listase *lista2)
{
	tp_listase *atu1, *atu2;
	atu1 = lista1;
	atu2 = lista2;
	while(atu1->prox != NULL)
	{
		atu1 = atu1->prox;
	}
	atu1->prox = lista2;
	while(atu2->prox != NULL)
	{
		atu2 = atu2->prox;
	}
	atu2->prox = lista1;
	lista2 = lista1;
}

void concatena_listas(tp_listase ** l1, tp_listase **l2)
{
	tp_listase *atu;
	atu = *l1;
	while(atu->prox != NULL)
	{
		atu = atu->prox;
	}
	atu->prox = *l2;
	atu = *l2;
	//  imprime_listase(*l1);
	while(atu->prox != NULL)
	{
		atu = atu->prox;
	}
	atu->prox = *l1;
	*l2 = *l1;
}


void destroi_listase(tp_listase **l)
{
	tp_listase *atu;
	atu = *l;
	while (atu != NULL)
	{
		*l = atu->prox;
		free(atu);
		atu = *l;
	}
	*l = NULL;
}

#endif


