#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca para cuidar das strings

int registro()
{
	char arquivo[40];
	char cpf [40];             //Criando as strings
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");  //aparece pro usu�rio  
	scanf("%s",cpf);							//armazenando o cpf	%s = strings						
	
	strcpy(arquivo, cpf);					//igualando o cpf a variavel arquivo para o nome do arquivo ser o CPF
	
	FILE * file;
	file = fopen(arquivo, "w"); 			// aqui vai criar um arquivo
	fprintf (file,cpf);				
	fclose (file); 	
	
	file = fopen(arquivo,"a"); 				//como j� criamos em cima ent�o vamos atulizar somente usando o "a" de atualizar
	fprintf (file,",");	 
	fclose (file);
	 
	printf("Digite o nome a ser cadastrado: "); 
	scanf("%s",nome);   //armazenando o nome	%s = strings
	
	file = fopen (arquivo,"a");
	fprintf(file,nome);      		//abrindo o arquivo e atualizando com essa informa��o
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");			//abrindo o arquivo e atualizando com essa informa��o
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
	file = fopen (cpf,"r");  // esse "r" � para ler 
	

	
				
	
	if(file == NULL)
{
	printf("Arquivo n�o localizado, usu�rio n�o cadastrado...\n\n");  // Isso � uma valida��o caso o cpf n�o exista  no bnaco de dados...	
																	
		}
		
	while (fgets (conteudo, 200,file ) !=NULL )         // enquanto tiver dados no arquivo vai ler, gra�as ao NULL
	
	{
	printf("Essas s�o as informa��es do usu�rio: ");
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
	
	printf("Digite o CPF do usu�rio que deseja deletar: \n");
	scanf ("%s", cpf); 		
	
	
	FILE *file;
	file = fopen (cpf,"r");
	fclose(file);		// "r" � ler o arquivo
	
		remove(cpf);					//c�digo para remover...
		
		printf("Usu�rio deletado com sucesso! \n\n");
	     
	
	if(file == NULL) 								//caso n�o exista esse cpf ent�o:
	{
		printf("CPF n�o localizado no sistema... \n\n");
	}
	

		
	system("pause");

}

int main()	

  {
 
	int opcao=0; 	//Definindo vari�veis
	int laco=1;

	
	for(laco=1;laco=1;) //La�o infinito para voltar ao menu
	{
		
		system("cls");

		
		setlocale(LC_ALL, "Portuguese");//Definindo a l�nguagem


		printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registar nome\n");
    	printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Op��o: "); //Fim do menu
	
	    scanf("%d", &opcao);   //Armazenando a escolha do usu�rio
 
	    system("cls");
	    
	    switch(opcao)
	 {
	     	
	    case 1 :	
			registro();         
			break;
				 	
		case 2 :
			consultar();					//chamada de fun��es 
			break;
			
		case 3 :
			deletar();
			break;
		
		default :
			printf("Essa op��o est� indispon�vel!\n");
			system("pause");
			break;
 }
	 }	
 	}
 		
	   
