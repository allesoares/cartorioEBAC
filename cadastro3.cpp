#include <stdio.h> // biblioteca de comunicacao com o usuario
#include <stdlib.h> // biblioteca de alocacao de espaco em memoria
#include <locale.h> // biblioteca de alocacoes de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar das string

int regitro()  //Função responsavel por cadastrar os usuarios no sistema 
{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da criação de variaveis/string
	
	printf(" Digite o CPF a ser cadastrado;"); //coletando imformação do usuario
	scanf("%s", cpf); //%s refere-se a string

	strcpy(arquivo, cpf); // Responsavel por copiar o valor das string

	FILE*file; // cria arquivo
	file = fopen(arquivo, "w"); // abre o arquivo e  o "w" significa escrever.
	fprintf(file,cpf);  //  salvo valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e  o "a" significa atualizar.
	fprintf(file,","); //  salvo valor da variavel
	fclose(file); //fecha arquivo
	
	printf("Digite o nome a ser cadastrado:"); //coletando imformação do usuario
	scanf("%s", nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e  o "a" significa atualizar.
	fprintf(file,nome); //salvo valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e  o "a" significa atualizar.
	fprintf(file,","); //salvo valor da variavel
	fclose(file); //fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado:"); //coletando imformação do usuario
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo,"a");  //abre o arquivo e  o "a" significa atualizar.
	fprintf(file,sobrenome); //salvo valor da variavel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e  o "a" significa atualizar.
	fprintf(file,","); //salvo valor da variavel
	fclose(file); //fecha arquivo
	
	printf("Digite ocargo a ser cadastrado:");  //coletando imformação do usuario
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //abre o arquivo e  o "a" significa atualizar.
	fprintf(file,cargo); //salvo valor da variavel
	fclose(file); //fecha arquivo
	

}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser Consultado:"); //coletando imformação do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file== NULL)
{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: "); 
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{

	char cpf[40];
	
	printf("Digite o CPF a ser deletado: "); //coletando imformação do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		
	 } 

}


int main()
	{
	int opcao=0; //Definindo variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("### CARTÓRIO da EBAC###\n\n"); //inicio menu 
		printf("Escolha a opção desejada do menu\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n\n");  
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//fim menu
	
		scanf("%d", &opcao); // armazenando escolha do usuario
	
		system("cls"); //responsavel por limpar a tela
	
		switch(opcao) // inicio seleção do menu
		{
			case 1:
				regitro(); //chamada de funções
    			break;
    			
    		case 2:
    			consulta();
				break;
				
			case 3:
				deletar();
				break;
				
			case 4:
				printf("Obrigado por usar o sistema!\n");
				return 0;
				break;
				
				
		
			default:
				printf("Esta opcao nao esta disponivel\n");
				system("pause");
				break;
				//fim da seleção 
		}
	
    
	
    }    
}
