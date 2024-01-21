#include <stdio.h>//biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h>

int registro()//Fun��o responsavel por cadastrar os usu�rio no sistema
{
	//inicio das cria��es de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);	
	
	strcpy(arquivo, cpf);//copia os valores da string
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file, cpf),
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");//definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel achar o arquino, arquivo n�o localizado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas s�o as informa��es do us�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sitema. \n");
		system("pause");
	}
	
	if(file != NULL)
	{
		printf("Usu�rio deletado com sucesso. \n");
		system("pause");
	}
	
}

int main()//principal fun��o do programa
{
	int opcao=0;//Definindo a vari�vel 
	int laco=1;
	
	for(laco=1; laco=1;)
	 {
	 	system("cls");//respons�vel por limpar a tela
			
		setlocale(LC_ALL, "portuguese");//definindo linguagem
	
		printf("Cart�rio\n\n\tEBAC");
		printf("\n\nMenu op��es");
		printf("\n1� \tRegistrar nomes");
		printf("\n2� \tConsultar nomes");
		printf("\n3� \tDeletar nomes\n\n");
		printf("Op��o:");
	
		scanf("%d", &opcao);//armazena vari�veis do tipo inteiro
		
		system("cls");// responsavel por limpar a tela
		
		switch (opcao)//inicio da sele��o
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel\n");
			system("pause");	
		}
  	}
}
