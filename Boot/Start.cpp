#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

void IniciaBoot()
{
	system("start Executavel.lnk");
}

void GravaNick(char nick[])
{
	int pos = strlen(nick);
	nick[pos-1] = '\0';
	
	remove("RakSAMPClient.xml");
	
	FILE *arq = fopen("config.xml", "r");
	FILE *arq2 = fopen("RakSAMPClient.xml", "w");
	char linha[256];
	int l = 0;
	fgets(linha, sizeof(linha), arq);
	while(!feof(arq))
	{
		if(l == 4)
			fprintf(arq2, linha, nick);
		else
			fprintf(arq2, linha);
		fgets(linha, sizeof(linha), arq);
		l++;
	}
	fclose(arq);
	fclose(arq2);
}



void IniciaLista(int qtd)
{
	FILE *arq = fopen("Nicks.txt", "r");
	char nick[32];
	int i = 0;
	while(!feof(arq) && i < qtd)
	{
		fgets(nick, sizeof(nick), arq);
		printf("Conectando %s", nick);
		if(strlen(nick) > 3)
		{
			GravaNick(nick);
			Sleep(500);
			IniciaBoot();
			Sleep(1000);
			i++;
		}
		
		
	}
	fclose(arq);
}


int main()
{
	int qtd = 0;
	while(qtd <= 0)
	{
		printf("Qual a quantidade de boots: ");
		fflush(stdin);
		scanf("%d", &qtd);
	}
	IniciaLista(qtd);
}
