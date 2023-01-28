#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> // biblioteca para cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf [40];             //Criando as strings
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");  //aparece pro usuário  
	scanf("%s",cpf);							//armazenando o cpf	%s = strings						
	
	strcpy(arquivo, cpf);					//igualando o cpf a variavel arquivo para o nome do arquivo ser o CPF
	
	FILE * file;
	file = fopen(arquivo, "w"); 			// aqui vai criar um arquivo
	fprintf (file,cpf);				
	fclose (file); 	
	
	file = fopen(arquivo,"a"); 				//como já criamos em cima então vamos atulizar somente usando o "a" de atualizar
	fprintf (file,",");	 
	fclose (file);
	 
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome);   //armazenando o nome	%s = strings
	
	file = fopen (arquivo,"a");
	fprintf(file,nome);      		//abrindo o arquivo e atualizando com essa informação
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");			//abrindo o arquivo e atualizando com essa informação
	fclose(file);
	
	
	
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen (arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo,"a");
	fprintf (file,",");
	fclose(file);
	
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen (arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	
	 system("pause");  // a tela fica pausado aqui 
		
}

int consultar()
{
	char cpf[40];    		 			//definindo as strings
	char conteudo[200];

	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen (cpf,"r");  // esse "r" é para ler 
	

	
				
	
	if(file == NULL)
{
	printf("Arquivo não localizado, usuário não cadastrado...\n\n");  // Isso é uma validação caso o cpf não exista  no bnaco de dados...	
																	
		}
		
	while (fgets (conteudo, 200,file ) !=NULL )         // enquanto tiver dados no arquivo vai ler, graças ao NULL
	
	{
	printf("Essas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
			
 }
	
system("pause");
fclose(file);	
	
	
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");  //definindo a linguagem
	
	char cpf[40];			//cirando a string
	
	printf("Digite o CPF do usuário que deseja deletar: \n");
	scanf ("%s", cpf); 		
	
	
	FILE *file;
	file = fopen (cpf,"r");
	fclose(file);		// "r" é ler o arquivo
	
		remove(cpf);					//código para remover...
		
		printf("Usuário deletado com sucesso! \n\n");
	     
	
	if(file == NULL) 								//caso não exista esse cpf então:
	{
		printf("CPF não localizado no sistema... \n\n");
	}
	

		
	system("pause");

}

int main()	

  {
 
	int opcao=0; 	//Definindo variáveis
	int laco=1;

	
	for(laco=1;laco=1;) //Laço infinito para voltar ao menu
	{
		
		system("cls");

		
		setlocale(LC_ALL, "Portuguese");//Definindo a línguagem


		printf("### Cartório da EBAC ###\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registar nome\n");
    	printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção: "); //Fim do menu
	
	    scanf("%d", &opcao);   //Armazenando a escolha do usuário
 
	    system("cls");
	    
	    switch(opcao)
	 {
	     	
	    case 1 :	
			registro();         
			break;
				 	
		case 2 :
			consultar();					//chamada de funções 
			break;
			
		case 3 :
			deletar();
			break;
		
		default :
			printf("Essa opção está indisponível!\n");
			system("pause");
			break;
 }
	 }	
 	}
 		
	   
