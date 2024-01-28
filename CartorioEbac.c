#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocação de texo por região
#include <string.h> //biblioteca responsavél por cuidar das strings


int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final criação de variaveis/string	
	
	printf("Digite o cpf a ser cadastrado: "); //coletando informação do usuario
	scanf("%s", cpf);  //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar o valores das strings
	
	//acessa o file depois mandar criar o arquivo file
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // abre o arquivo e o "w" significa escrever
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo,"a"); // "a" atualização
	fprintf(file,","); //salva valor ou texto no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite um nome a ser cadastrado: "); //coletando informação do usuario
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo,"a"); //abri o arquivo e "a" atualiza
	fprintf(file, nome); // salva o valor da variavel no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); // abri o arquivo para atualizar uma informação
	fprintf(file, ","); // salva o valor da variavel ou texto 
	fclose(file); // fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuario
	scanf("%s", sobrenome); //%s refere-se a string coletada
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar um valor de string ou texto
	fprintf(file,sobrenome); //salva o valor de uma string(variavel) ou texto
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo para atualizar uma string ou texto
	fprintf(file,","); // abre o arquivo para atualizar um valor de variavel ou texto
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação do usuario
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); // abre o arquivo para atualizar uma string ou texto
	fprintf(file,cargo); // abre o arquivo para atualizar um valor de variavel ou texto
	fclose(file); // fecha o arquivo
	
}

int consulta() //Função responsável por consultar os usuários no sistema!
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//inicio da criação de variaveis/string
	char cpf[40]; //para o sistema consultar ele precisa trazer uma variavel
	char conteudo[200];
	//final da criação de variaveis/string
	
	printf("Digite o CPF a ser consultado: "); //coletando informação do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r");// abre o arquivo para "r" escrever no arquivo
	
	if(file == NULL) //NULL se for nulo (se o cpf não existir)
	{
		printf("Não foi possivel abrir o arquivo, Usuário não localizado!.\n");	
	}	
	
	while(fgets(conteudo, 200, file) != NULL) // enquanto ele for buscar os caracteres dentro da variavel
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause"); //responsável para pausar a tela
	
	
}

int deletar() //Função responsável por deletar os usuários no sistema!
{
	//incio da criação das variaveis
	char cpf[40];
	int opcao2=2;
	//final da criação das variaveis
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando a informação do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); //abre o arquivo para escrever a variavel "r" escreve
	fclose(file); //fecha o arquivo
	
	if(file == NULL) // faz a verificação se o valor que usuário passou é nulo ou diferente.
	{
		printf("CPF não encontrado!. \n"); //coletando a informação do usuario
		system("pause"); //pausa a tela para o usuario
	}	
	
	if(file != NULL) // faz a verificação se o valor é diferente de nulo ou seja igual ao que vc digitou.
	{	
		
		printf("Deseja realmente deletar? \n ");
		printf("\tDigite 1 para Sim! \n");
		printf("\tDigite 2 para Não! \n");
		printf("Opção: ");
		
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
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) //incio da repetição
	{
	
		system("cls"); //limpa a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
	
		printf("\tO1 - Registrar nomes\n"); 
		printf("\tO2 - Consultar nomes\n");
		printf("\tO3 - Deletar nomes\n\n");
		printf("Opção: ");//fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
	
		switch(opcao) //Inicio da seleção do menu
		{
			case 1:
			registro(); // chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:	
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
			//fim da seleção
				
		}	
	}		
}

