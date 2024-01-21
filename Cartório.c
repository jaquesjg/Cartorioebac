#include <stdio.h>//biblioteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço de memória
#include <locale.h>//biblioteca de alocação de texto por região
#include <string.h>

int registro()//Função responsavel por cadastrar os usuário no sistema
{
	//inicio das criações de variáveis
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
		printf("Não foi possivel achar o arquino, arquivo não localizado.\n\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)
	{
		printf("\nEssas são as informações do usário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usuário ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sitema. \n");
		system("pause");
	}
	
	if(file != NULL)
	{
		printf("Usuário deletado com sucesso. \n");
		system("pause");
	}
	
}

int main()//principal função do programa
{
	int opcao=0;//Definindo a variável 
	int laco=1;
	
	for(laco=1; laco=1;)
	 {
	 	system("cls");//responsável por limpar a tela
			
		setlocale(LC_ALL, "portuguese");//definindo linguagem
	
		printf("Cartório\n\n\tEBAC");
		printf("\n\nMenu opções");
		printf("\n1° \tRegistrar nomes");
		printf("\n2° \tConsultar nomes");
		printf("\n3° \tDeletar nomes\n\n");
		printf("Opção:");
	
		scanf("%d", &opcao);//armazena variáveis do tipo inteiro
		
		system("cls");// responsavel por limpar a tela
		
		switch (opcao)//inicio da seleção
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
			printf("Essa opção não está disponivel\n");
			system("pause");	
		}
  	}
}
