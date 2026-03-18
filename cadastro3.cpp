#include <stdio.h> //biblioteca de comunicação com usuario
#include <stdlib.h> //biblioteca de alocaçao de espaÃço em memoria
#include <locale.h> //biblioteca de texto em portugues/região 
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//inicio criação de variaveis/string
	char arquivo [40];  //Variavel para armazenar no nome do arquivo
	char cpf [40]; //Variavel para armazenar o cpf do usuario
	char nome[40]; //Variavel para armazenar o nome do usuario
	char sobrenome[40]; //Variavel para armazenar o sobrenomedo usuario
	char cargo[40]; //Variavel para armazenar o cargo do usuario
	//final criação de variaveis/string
	
	printf("Digte o CPf a ser cadastrado:"); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //responsavelpor copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo,"w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha aqruivo
	
	file= fopen (arquivo, "a"); //Abre o arquivo e  o "a" significa atualizar.
	fprintf(file,","); //Escreve uma virgula no arquivo
	fclose(file); // Fecha arquivo para liberar memoria
	
	printf("Digite o nome a ser cadastrado:"); //coletando informação do usuário
	scanf("%s",nome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e  o "a" significa atualizar.
	fprintf(file,nome); //Escreve o nome no arquivo
	fclose(file); // Fecha arquivo para liberar memoria
	
	
	file = fopen (arquivo, "a"); //Abre o arquivo e  o "a" significa atualizar.
	fprintf(file,","); //Escreve uma virgula no arquivo
	fclose(file); // Fecha arquivo para liberar memoria
	
	printf("Digite o sobrenome a ser cadastrado:");  //coletando informação do usuário
	scanf("%s",sobrenome); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e  o "a" significa atualizar.
	fprintf(file,sobrenome); //Escreve o sobrenome no arquivo
	fclose(file); // Fecha arquivo para liberar memoria
	
	file= fopen (arquivo, "a"); //Abre o arquivo e  o "a" significa atualizar.
	fprintf(file,","); //Escreve uma virgula no arquivo
	fclose(file); // Fecha arquivo para liberar memoria
	
	printf("Digite o cargo a ser cadastrado:"); //coletando informação do usuário
	scanf("%s",cargo); //%s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo e  o "a" significa atualizar.
	fprintf(file,cargo); //Escreve o cargo no arquivo
	fclose(file); // Fecha arquivo para liberar memoria
	
	system("pause"); //Pausa o programa para melhor visualização do resultado
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem ( Portugues)
	
	char cpf[40]; //Variavel para armazenar o cpf do usuario
	char conteudo[200];//Variavel para armazenar o conteudo do arquivo
	
	printf("Digite o CPF a ser consultado:"); //coletando informação do usuário
	scanf("%s",cpf);//%s refere-se a string
	
	FILE *file; // cria o arquivo
	file = fopen(cpf,"r"); //Abrindo arquivo para leitura
	
	if(file == NULL) //verificando se o arquivo foi aberto corretamente
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //Mensagem para o usuario de arquivo nao localizado
	}
	
	while(fgets(conteudo, 200, file) != NULL) //Laço para ler o arquivo linha por linha
	{
		printf("\nEssas são as informacoes do usuário:"); // Mensagem de informcoes do usuario
		printf("%s", conteudo); //Mostra as informacoes do usuario na tela
		printf("\n\n"); // Espaço entre linhas para melhor visualizaçao
	
	}
	
	system("pause");  //Pausa o programa para melhor visualização do resultado
}



int deletar()
{
	char cpf [40]; //Variavel para armazenar o cpf do usuario
	
	printf("Digite o CPF do usuario que deseja deletar:"); //coletando informação do usuário
	scanf("%s",cpf); // //%s refere-se a string
	
	remove(cpf);
	
	FILE *file; // Variavel para armazenar o arquivo 
	file = fopen(cpf,"r"); //Abrindo arquivo para leitura e o "r" signifca ler
	
	if(file == NULL) // Verificando se o arquivo foi aberto corretamente
	{
		printf("Usuário não se encontra no sistema e ou deletado!.\n"); // Mensagem de deletado ou nao encontrado.
		system("pause");  //Pausa o programa para melhor visualização do resultado
		
	}
}


int main() // Definindo variavel do programa 
    {
    int opcao=0; //variavel para armazenar a escolha do usuario
    int laco=1; // Variavel para controlar o laco de repetição do menu

    for(laco=1;laco=1;) //Laco de repetição do menu
    {    

        system("cls"); //responsável por limpar a tela

        setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem ( Portugues)

        printf("###Cartório EBAC###\n\n"); //Inicio Menu
        printf("Escolha a opção desejada no menu abaixo\n\n"); //Menu de opções para o usuário escolher
        printf("1 - Registrar nomes\n"); //Opções do menu
        printf("2 - Consultar nomes\n"); //Opções do menu
        printf("3 - Deletar nomes\n\n"); //Opções do menu
        printf("Opção:"); //Fim do menu

        scanf("%d", &opcao); // Armazenamento a escolha do usuario

        system("cls"); //Responsável por limpar a tela

		switch(opcao) // Inicio da seleção do menu
		{
			case 1:
			registro(); //Chama a função registro de nome
        	break; //Fim case 1
        	
        	case 2:
        	consulta(); //Chama a função consulta de nome
            break; // Fim case 2
                
            case 3:
            deletar();//Chama a função deletar de nome
            break; // Fim case 3
                
        	default:
        	printf("Essa opcao nao esta disponivel!\n"); //Mensagem de erro para opção invalida
        	system("pause"); // Pausa o programa para o usuario ler a mensagem de erro
        	break; //Fim default
        		
		} //Fim da seleção do menu
		
        

    }

    }
