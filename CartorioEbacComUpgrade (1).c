#include <stdio.h> //biblioteca de comunicacao do usuario
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca respons�vel por cuidar das strings

int creditos()//creditos da aplicacao
{
	printf("Programa desenvolvido por MOZART SOARES\n");
	system("pause");
}
int registro()// funcao responsavel pelo cadastro
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
	fprintf(file,"\nO nome �: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a"); 
	fprintf(file,"\nO sobrenome �: ");
	fclose(file);

	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); 
	fprintf(file,"\nO cargo �: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file); //esses sao comandos para inserir de modo organizado no bloco de notas as informacoes registradas
	
	system("pause");
}
int consultar()//funcao de consultar nomes
{ 
	char cpf[40];
	char conteudo[500];
		
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf); //%s armazena op��o do usu�rio numa string de vari�veis(salvar string)
		
	FILE *file;
	file = fopen(cpf,"r"); //comando "r" de read para ler o arquivo
		
	if(file == NULL)
	{
		printf("N�o foi poss�vel encontrar o arquivo. \n"); //comando a ser realizado se nao encontrar o arquivo
	}
	while(fgets(conteudo,500,file) != NULL)
	{
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}
int deletar()//funcao de deletar nomes
{	
	int opcao=0;
	char cpf[40];
	char conteudo[200];
		
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf); //%s armazena op��o do usu�rio numa string de vari�veis
		
	FILE *file;
	file = fopen(cpf,"r"); //comando "r" de read para ler o arquivo
		
	if(file == NULL)
	{
		printf("N�o foi poss�vel encontrar o arquivo. \n");
	}
	while(fgets(conteudo,200,file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio que ser� deletado:  \n");// mostra conteudo para usu�rio e pergunta se tem certeza que deseja deletar
		printf("%s", conteudo); 
		printf("\n\n");
		printf("Tem certeza de que deseja deletar este usu�rio? \n");
		printf("\t1 - Prosseguir\n"); //opcao 1
		printf("\t2 - Cancelar\n"); //opcao 2
	}
	system("pause");
	
	switch(opcao)
	{
		case 1: //usu�rio escolhe opcao 1 "prosseguir"
		remove(cpf);
		printf("Usu�rio deletado com sucesso \n"); 
		system("pause");
		break;
	
		case 2: //usu�rio escolhe opcao 1 "cancelar"
		printf("O usu�rio n�o foi deletado \n");
		system("pause");
		break;
		
		default: //usu�rio escolhe opcao indisponivel
		indisponivel();
		break;	
	}
	//adicionar sistema para mostar infos do usuario antes de deletar, usar um sistema similar da fun��o consulta no trecho do while
}
int indisponivel()// funcao para ser chamada quando opcao inexistente for escolhida
{
	printf("op��o indispon�vel\n");
	system("pause");
}
int main() //primeira funcao a sercarregada do menu principal
{
	int opcao=0; //definindo vari�veis
	int laco=1; 
	
	for(laco=1;laco=1;) //inicio do laco
	{
		system("cls");
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
		printf("### Cart�rio da EBAC ###\n\n"); //opcoes do menu para o usu�rio
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Cr�ditos\n");
		printf("\t5 - Sair do sistema\n");
		printf("op��o: "); //fim das opcoes

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
			return 0; //comando para retornar 0 (fechar o programa e quebrar la�os de repeti��o,fun��es e etc...)
			break;
				
			default:
			indisponivel();//chama a funcao indisponivel
			break;
		} //Fim do switch case
	} //fim do laco
}
