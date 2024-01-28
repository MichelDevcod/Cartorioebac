#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texo por regi�o
#include <string.h> //biblioteca responsav�l por cuidar das strings


int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variaveis/string	
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar o valores das strings
	
	//acessa o file depois mandar criar o arquivo file
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // abre o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo,"a"); // "a" atualiza��o
	fprintf(file,","); //salva valor ou texto no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite um nome a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abri o arquivo e "a" atualiza
	fprintf(file, nome); // salva o valor da variavel no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // abri o arquivo para atualizar uma informa��o
	fprintf(file, ","); // salva o valor da variavel ou texto 
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", sobrenome); //%s refere-se a string coletada
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar um valor de string ou texto
	fprintf(file,sobrenome); //salva o valor de uma string(variavel) ou texto
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo para atualizar uma string ou texto
	fprintf(file,","); // abre o arquivo para atualizar um valor de variavel ou texto
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo para atualizar uma string ou texto
	fprintf(file,cargo); // abre o arquivo para atualizar um valor de variavel ou texto
	fclose(file); // fecha o arquivo
	
}

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema!
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da cria��o de variaveis/string
	char cpf[40]; //para o sistema consultar ele precisa trazer uma variavel
	char conteudo[200];
	//final da cria��o de variaveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��o do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r");// abre o arquivo para "r" escrever no arquivo
	
	if(file == NULL) //NULL se for nulo (se o cpf n�o existir)
	{
		printf("N�o foi possivel abrir o arquivo, Usu�rio n�o localizado!.\n");	
	}	
	
	while(fgets(conteudo, 200, file) != NULL) // enquanto ele for buscar os caracteres dentro da variavel
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //respons�vel para pausar a tela
	
	
}

int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema!
{
	//incio da cria��o das variaveis
	char cpf[40];
	int opcao2=2;
	//final da cria��o das variaveis
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando a informa��o do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo para escrever a variavel "r" escreve
	fclose(file); //fecha o arquivo
	
	if(file == NULL) // faz a verifica��o se o valor que usu�rio passou � nulo ou diferente.
	{
		printf("CPF n�o encontrado!. \n"); //coletando a informa��o do usuario
		system("pause"); //pausa a tela para o usuario
	}	
	
	if(file != NULL) // faz a verifica��o se o valor � diferente de nulo ou seja igual ao que vc digitou.
	{	
		
		printf("Deseja realmente deletar? \n ");
		printf("\tDigite 1 para Sim! \n");
		printf("\tDigite 2 para N�o! \n");
		printf("Op��o: ");
		
		scanf("%d", &opcao2);
		
		if(opcao2 ==1)
		{
			printf("Usuario deletado com sucesso!\n ");
			remove(cpf);
			system("pause");
		}
		
	}
	

	

}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) //incio da repeti��o
	{
	
		system("cls"); //limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
	
		printf("\tO1 - Registrar nomes\n"); 
		printf("\tO2 - Consultar nomes\n");
		printf("\tO3 - Deletar nomes\n\n");
		printf("Op��o: ");//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
	
		switch(opcao) //Inicio da sele��o do menu
		{
			case 1:
			registro(); // chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:	
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
			//fim da sele��o
				
		}	
	}		
}

