#include <stdio.h> //biblioteca de comunicacao do usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar das strings

int creditos()//creditos da aplicacao
{
	printf("Programa desenvolvido por MOZART SOARES\n");
	system("pause");
}
int registro()//fun��o responsavel pelo cadastro
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40]; //criando vari�veis
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];//fim das variaveis
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //%s armazena op��o do usu�rio numa string de vari�veis(salvar string)
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores da string
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo,"w"); //cria o arquivo com o nome da vari�vel e o "w" � o comando para write (criar o arquivo)
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //a � o comando para accessar o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
    fprintf(file,"\nO nome �: %s", nome);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    fprintf(file,"\nO sobrenome �: %s", sobrenome);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo); 
    fprintf(file,"\nO cargo �: %s",cargo);
    fclose(file);
	
	system("pause");
}
int consultar()//fun��o de consultar nomes
{ 
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[500];
		
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf); //%s armazena op��o do usu�rio numa string de vari�veis(salvar string)
		
	FILE *file;
	file = fopen(cpf,"r"); //comando "r" de read para ler o arquivo
		
	if(file == NULL)// mensagem para exibir se o arquivo for inexistente
	{
		printf("N�o foi poss�vel encontrar o arquivo. \n"); //comando a ser realizado se nao encontrar o arquivo
	}
	while(fgets(conteudo,500,file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n\n");
	}	
	fclose(file);
	system("pause");
}
int deletar()//func�o de deletar nomes
{	
	setlocale(LC_ALL, "Portuguese");
	int opcao=0;
	char cpf[40];
	char conteudo[500];
		
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf); //%s armazena op��o do usu�rio numa string de vari�veis
		
	FILE *file;
	file = fopen(cpf,"r"); //comando "r" de read para ler o arquivo
		
	if(file == NULL)
	{
		printf("N�o foi poss�vel encontrar o arquivo. \n");
		system("pause");
		return 0;
	}
	while(fgets(conteudo,500,file) != NULL)
	{
		printf("%s", conteudo); // mostra conteudo para usu�rio 
	}	
	printf("\nTem certeza de que deseja deletar este usu�rio? \n");
	printf("\t1 - Prosseguir\n"); //opcao 1
	printf("\t2 - Cancelar\n"); //opcao 2
	
	printf("Digite o n�mero da op��o: ");
	scanf("%d" , &opcao);
	
	switch(opcao)
	{
		case 1: //usu�rio escolhe opcao 1 "prosseguir"
		fclose(file);
		remove(cpf);
		printf("Usu�rio deletado com sucesso \n"); 
		system("pause");
		break;
	
		case 2: //usu�rio escolhe opcao 1 "cancelar"
		printf("O usu�rio n�o foi deletado \n");
		fclose(file);
		system("pause");
		break;
		
		default: //usu�rio escolhe opcao indisponivel
		indisponivel();
		break;	
	}
}
int indisponivel()//func�o para ser chamada quando op��o inexistente for escolhida
{
	printf("op��o indispon�vel\n");
	system("pause");
}
int main() //primeira func�o a ser carregada do menu principal
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //definindo vari�veis
	int laco=1; 
	int loop=3;
	char senhadigitada[]="a";
	int comparacao;
	
	for(laco=3;laco=3;)//inicio do loop de login
	{
	
		printf("### Cart�rio da EBAC ###\n\n");//Texto e comandos para receber informa��es de login
		printf("Login de administrador\n\nDigite a sua senha: ");
		scanf("%s",senhadigitada);
	
		comparacao = strcmp(senhadigitada,"admin");//strcmpm � uma fun��o da biblioteca string.h
	
		if(comparacao == 0)
		{
			system("cls");
			for(laco=1;laco=1;) //inicio do laco
			{
				system("cls");
				setlocale(LC_ALL, "Portuguese"); //definindo linguagem
				printf("### Cart�rio da EBAC ###\n\n"); //opcoes do menu para o usu�rio
				printf("Escolha a op��o desejada do menu:\n\n");
				printf("\t1 - Registrar nomes\n");
				printf("\t2 - Consultar nomes\n");
				printf("\t3 - Deletar nomes\n");
				printf("\t4 - Cr�ditos\n\n");
				printf("\t5 - Sair\n");
				printf("\nDigite o n�mero da op��o: "); //fim das opcoes

				scanf("%d" , &opcao); // armazena na variavel opcao valor digitado pelo usu�rio
		
				system("cls");  //fun��o de limpar a tela ap�s escolher opcao,atua no sistema operaciona,no caso windows
	
				switch(opcao) //inicio de switch case para armazewnar info do usu�rio
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
					creditos();//chama a funcao dos cr�ditos
					break;	
			
					case 5:
					printf("Obrigado por utilizar o sistema\n");
					return 0; //comando para retornar 0 (fechar o programa quebrando la�os de repeti��o, fun��es e etc...)
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
