#include "listase.h"

// ascii arts do BEM VINDO AO JOGO DA FORCA
int artBemVindo()
{
	printf("         ____                  __      ___           _       ");
	printf("\n");
	printf("        |  _ \\                 \\ \\    / (_)         | |      ");
	printf("\n");
	printf("        | |_) | ___ _ __ ___    \\ \\  / / _ _ __   __| | ___  ");
	printf("\n");
	printf("        |  _ < / _ \\ '_ ` _ \\    \\ \\/ / | | '_ \\ / _` |/ _ \\ ");
	printf("\n");
	printf("        | |_) |  __/ | | | | |    \\  /  | | | | | (_| | (_) |");
	printf("\n");
	printf("        |____/ \\___|_| |_| |_|     \\/   |_|_| |_|\\__,_|\\___/ ");

	printf("\n");

	printf("                               __ _  ___  ");
	printf("\n");
	printf("                              / _` |/ _ \\ ");
	printf("\n");
	printf("                             | (_| | (_) |");
	printf("\n");
	printf("                              \\__,_|\\___/ ");

	printf("\n");

	printf("       _                     _____          ______                  ");
	printf("\n");
	printf("      | |                   |  __ \\        |  ____|                 ");
	printf("\n");
	printf("      | | ___   __ _  ___   | |  | | __ _  | |__ ___  _ __ ___ __ _ ");
	printf("\n");
	printf("  _   | |/ _ \\ / _` |/ _ \\  | |  | |/ _` | |  __/ _ \\| '__/ __/ _` |");
	printf("\n");
	printf(" | |__| | (_) | (_| | (_) | | |__| | (_| | | | | (_) | | | (_| (_| |");
	printf("\n");
	printf("  \\____/ \\___/ \\__, |\\___/  |_____/ \\__,_| |_|  \\___/|_|  \\___\\__,_|");
	printf("\n");
	printf("                __/ |                                               ");
	printf("\n");
	printf("               |___/                                                ");

	printf("\n");

	printf("                        __  __                  ");
	printf("\n");
	printf("                       |  \\/  |                 ");
	printf("\n");
	printf("                       | \\  / | ___ _ __  _   _ ");
	printf("\n");
	printf("                       | |\\/| |/ _ \\ '_ \\| | | |");
	printf("\n");
	printf("                       | |  | |  __/ | | | |_| |");
	printf("\n");
	printf("                       |_|  |_|\\___|_| |_|\\__,_|");

	printf("\n\n");

	printf("                       1 para jogar\n");
	printf("                       2 para mostrar todas as palavras\n");
	printf("                       3 para sair\n\n");
	printf("                       Digite uma das opcoes:");

	int i;
	scanf("%i", &i);
	return i;
}

// ascii arts do pessonagem sendo inforcado tendo 9 verçoes
// 1 para quando esta morto e 8 para quando esta morrendo
// nao sao chamadas diretamente sao chamadas apartir do artForca
void artForca0()
{
	printf("\n          _____________________");
	printf("\n         /  ___________________|");
	printf("\n         | |                   |");
	printf("\n         | |              _____|_____");
	printf("\n         | |             |           |");
	printf("\n         | |             |  X     X  |");
	printf("\n         | |             |  _______  |");
	printf("\n         | |             | /       \\ |");
	printf("\n         | |             |___________|");
	printf("\n         | |           _______| |_______");
	printf("\n         | |          |  _           _  |");
	printf("\n         | |          | | |         | | |");
	printf("\n         | |          | | |         | | |");
	printf("\n         | |          | | |         | | |");
	printf("\n         | |          | | |         | | |");
	printf("\n         | |          |_| |         | |_|");
	printf("\n         | |              |   ___   |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |__|   |__|");
	printf("\n         | |");
	printf("\n ________| |________    ");
	printf("\n|___________________|   ");
}

void artForca1()
{
	printf("\n          _____________________");
	printf("\n         /  ___________________|");
	printf("\n         | |                   |");
	printf("\n         | |              _____|_____");
	printf("\n         | |             |           |");
	printf("\n         | |             |  0     0  |");
	printf("\n         | |             |  _______  |");
	printf("\n         | |             | /       \\ |");
	printf("\n         | |             |___________|");
	printf("\n         | |           _______| |_______");
	printf("\n         | |          |  _           _  |");
	printf("\n         | |          | | |         | | |");
	printf("\n         | |          | | |         | | |");
	printf("\n         | |          | | |         | | |");
	printf("\n         | |          | | |         | | |");
	printf("\n         | |          |_| |         | |_|");
	printf("\n         | |              |   ___   |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |__|   |__|");
	printf("\n         | |");
	printf("\n ________| |________    ");
	printf("\n|___________________|   ");
}

void artForca2()
{
	printf("\n          _____________________");
	printf("\n         /  ___________________|");
	printf("\n         | |                   |");
	printf("\n         | |              _____|_____");
	printf("\n         | |             |           |");
	printf("\n         | |             |  0     0  |");
	printf("\n         | |             |  _______  |");
	printf("\n         | |             | |_______| |");
	printf("\n         | |             |___________|");
	printf("\n         | |           _______| |____");
	printf("\n         | |          |  _           ");
	printf("\n         | |          | | |         |");
	printf("\n         | |          | | |         |");
	printf("\n         | |          | | |         |");
	printf("\n         | |          | | |         |");
	printf("\n         | |          |_| |         |");
	printf("\n         | |              |   ___   |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |__|   |__|");
	printf("\n         | |");
	printf("\n ________| |________    ");
	printf("\n|___________________|   ");
}

void artForca3()
{
	printf("\n          _____________________");
	printf("\n         /  ___________________|");
	printf("\n         | |                   |");
	printf("\n         | |              _____|_____");
	printf("\n         | |             |           |");
	printf("\n         | |             |  0     0  |");
	printf("\n         | |             |           |");
	printf("\n         | |             |  _______  |");
	printf("\n         | |             |___________|");
	printf("\n         | |              ____| |____");
	printf("\n         | |                         ");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |   ___   |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |  |   |  |");
	printf("\n         | |              |__|   |__|");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n ________| |________    ");
	printf("\n|___________________|   ");
}

void artForca4()
{
	printf("\n          _____________________");
	printf("\n         /  ___________________|");
	printf("\n         | |                   |");
	printf("\n         | |              _____|_____");
	printf("\n         | |             |           |");
	printf("\n         | |             |  0     0  |");
	printf("\n         | |             |           |");
	printf("\n         | |             | \\_______/ |");
	printf("\n         | |             |___________|");
	printf("\n         | |              ____| |____");
	printf("\n         | |                         ");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |   ___   |");
	printf("\n         | |                     |  |");
	printf("\n         | |                     |  |");
	printf("\n         | |                     |  |");
	printf("\n         | |                     |  |");
	printf("\n         | |                     |  |");
	printf("\n         | |                     |  |");
	printf("\n         | |                     |__|");
	printf("\n         | |                         ");
	printf("\n ________| |________    ");
	printf("\n|___________________|   ");
}
void artForca5()
{
	printf("\n          _____________________");
	printf("\n         /  ___________________|");
	printf("\n         | |                   |");
	printf("\n         | |              _____|_____");
	printf("\n         | |             |           |");
	printf("\n         | |             |  0     0  |");
	printf("\n         | |             |           |");
	printf("\n         | |             | \\_______/ |");
	printf("\n         | |             |___________|");
	printf("\n         | |              ____| |____");
	printf("\n         | |                         ");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |         |");
	printf("\n         | |              |   ___   |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n ________| |________    ");
	printf("\n|___________________|   ");
}

void artForca6()
{
	printf("\n          _____________________");
	printf("\n         /  ___________________|");
	printf("\n         | |                   |");
	printf("\n         | |              _____|_____");
	printf("\n         | |             |           |");
	printf("\n         | |             |  0     0  |");
	printf("\n         | |             |\\         /|");
	printf("\n         | |             | \\_______/ |");
	printf("\n         | |             |___________|");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n ________| |________    ");
	printf("\n|___________________|   ");
}

void artForca7()
{
	printf("\n          _____________________");
	printf("\n         /  ___________________|");
	printf("\n         | |                   |");
	printf("\n         | |              _____|_____");
	printf("\n         | |             |           |");
	printf("\n         | |             |           |");
	printf("\n         | |             |           |");
	printf("\n         | |             |           |");
	printf("\n         | |             |___________|");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n ________| |________    ");
	printf("\n|___________________|   ");
}

void artForca8()
{
	printf("\n          _____________________");
	printf("\n         /  ___________________|");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n         | |");
	printf("\n ________| |________    ");
	printf("\n|___________________|   ");
}

// determina qual a ascii art vai ser exibida
// o i determina a ascii art
void artForca(int i, tp_listase *chutes)
{
	//limpa a tela para que um novo quadro seja gerado
	system("cls");

	//imprime a lista de modo especifico com a formataçao bonita
	imprime_listase_formatado(chutes);

	//sistema que de acordo com o i faz uma das 9 ascii art seja exibida
	switch(i)
	{
	case 0:
		artForca0();
		break;
	case 1:
		artForca1();
		break;
	case 2:
		artForca2();
		break;
	case 3:
		artForca3();
		break;
	case 4:
		artForca4();
		break;
	case 5:
		artForca5();
		break;
	case 6:
		artForca6();
		break;
	case 7:
		artForca7();
		break;
	case 8:
		artForca8();
		break;
	default:
		artForca8();
		break;
	}
}


