#include <stdio.h> //biblioteca de comunicacao do usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsável por cuidar das strings

int creditos()//creditos da aplicacao
{
	printf("Programa desenvolvido por MOZART SOARES\n");
	system("pause");
}
int registro()//função responsavel pelo cadastro
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40]; //criando variáveis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];//fim das variaveis
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s armazena opção do usuário numa string de variáveis(salvar string)
	
	strcpy(arquivo, cpf); //responsável por copiar os valores da string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo,"w"); //cria o arquivo com o nome da variável e o "w" é o comando para write (criar o arquivo)
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //a é o comando para accessar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
    fprintf(file,"\nO nome é: %s", nome);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    fprintf(file,"\nO sobrenome é: %s", sobrenome);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo); 
    fprintf(file,"\nO cargo é: %s",cargo);
    fclose(file);
	
	system("pause");
}
int consultar()//função de consultar nomes
{ 
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[500];
		
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf); //%s armazena opção do usuário numa string de variáveis(salvar string)
		
	FILE *file;
	file = fopen(cpf,"r"); //comando "r" de read para ler o arquivo
		
	if(file == NULL)// mensagem para exibir se o arquivo for inexistente
	{
		printf("Não foi possível encontrar o arquivo. \n"); //comando a ser realizado se nao encontrar o arquivo
	}
	while(fgets(conteudo,500,file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n\n");
	}	
	fclose(file);
	system("pause");
}
int deletar()//funcão de deletar nomes
{	
	setlocale(LC_ALL, "Portuguese");
	int opcao=0;
	char cpf[40];
	char conteudo[500];
		
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf); //%s armazena opção do usuário numa string de variáveis
		
	FILE *file;
	file = fopen(cpf,"r"); //comando "r" de read para ler o arquivo
		
	if(file == NULL)
	{
		printf("Não foi possível encontrar o arquivo. \n");
		system("pause");
		return 0;
	}
	while(fgets(conteudo,500,file) != NULL)
	{
		printf("%s", conteudo); // mostra conteudo para usuário 
	}	
	printf("\nTem certeza de que deseja deletar este usuário? \n");
	printf("\t1 - Prosseguir\n"); //opcao 1
	printf("\t2 - Cancelar\n"); //opcao 2
	
	printf("Digite o número da opção: ");
	scanf("%d" , &opcao);
	
	switch(opcao)
	{
		case 1: //usuário escolhe opcao 1 "prosseguir"
		fclose(file);
		remove(cpf);
		printf("Usuário deletado com sucesso \n"); 
		system("pause");
		break;
	
		case 2: //usuário escolhe opcao 1 "cancelar"
		printf("O usuário não foi deletado \n");
		fclose(file);
		system("pause");
		break;
		
		default: //usuário escolhe opcao indisponivel
		indisponivel();
		break;	
	}
}
int indisponivel()//funcão para ser chamada quando opção inexistente for escolhida
{
	printf("opção indisponível\n");
	system("pause");
}
int main() //primeira funcão a ser carregada do menu principal
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //definindo variáveis
	int laco=1; 
	int loop=3;
	char senhadigitada[]="a";
	int comparacao;
	
	for(laco=3;laco=3;)//inicio do loop de login
	{
	
		printf("### Cartório da EBAC ###\n\n");//Texto e comandos para receber informações de login
		printf("Login de administrador\n\nDigite a sua senha: ");
		scanf("%s",senhadigitada);
	
		comparacao = strcmp(senhadigitada,"admin");//strcmpm é uma função da biblioteca string.h
	
		if(comparacao == 0)
		{
			system("cls");
			for(laco=1;laco=1;) //inicio do laco
			{
				system("cls");
				setlocale(LC_ALL, "Portuguese"); //definindo linguagem
				printf("### Cartório da EBAC ###\n\n"); //opcoes do menu para o usuário
				printf("Escolha a opção desejada do menu:\n\n");
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n");
				printf("\t4 - Créditos\n\n");
				printf("\t5 - Sair\n");
				printf("\nDigite o número da opção: "); //fim das opcoes

				scanf("%d" , &opcao); // armazena na variavel opcao valor digitado pelo usuário
		
				system("cls");  //função de limpar a tela após escolher opcao,atua no sistema operaciona,no caso windows
	
				switch(opcao) //inicio de switch case para armazewnar info do usuário
				{
					case 1:
					registro(); //chama a funcao registro
					break;
			
					case 2:
					consultar();//chama a funcao consulta
					break;
			
					case 3:
					deletar();//chama a funcao deletar
					break;
			
					case 4:
					creditos();//chama a funcao dos créditos
					break;	
			
					case 5:
					printf("Obrigado por utilizar o sistema\n");
					return 0; //comando para retornar 0 (fechar o programa quebrando laços de repetição, funções e etc...)
					break;
					
					default:
					indisponivel();//chama a funcao indisponivel
					break;
				} //Fim do switch case
			} //fim do laco	
		}else
			{
				printf("senha incorreta\n");
				system("pause");
				system("cls");
			}
	} //fim do loop de login
}
