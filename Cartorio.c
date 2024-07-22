#include <stdio.h>  //biblioteca da comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de  texto por regi�o
#include <string.h> //biblioteca responsavel pelas string 
    
int main()
{
	int opcao=0;                                                             // Defini��o de Variavel      // = atributo 
	int x=1;
	
	for(x=1;x=1;)                                                            // x = laco 
	
	{
	   system("cls");
	    
	   setlocale(LC_ALL, "Portuguese");                                      // Defini��o de Linguagem
	
	    printf("\t\t ������ Cart�rio da EBAC ������  \n\n");	             // Incicio do Menu
	    printf("\t Escola Brit�nica de Artes Criativas & Tecnologia\n\n\n");
	
	        printf("Escolha a op��o desejada atrav�s do menu:\n\n\n");       // Identa��o = organiza��o
	
               	printf("\t1 - Registrar Usu�rio \n\n");                      // Comandos Menu
               	
	            printf("\t2 - Consultar Usu�rio \n\n");                      // Comandos Menu
	            
	            printf("\t3 - Deletar Usu�rio\n\n");	                     // Comandos Menu e Final do Menu
	            
	            printf("\t4 - Sair do Sistema\n\n\n");

                printf("Digite sua Op��o:");
		            
	            
	   scanf("%d", &opcao);                                               // Scanear e Armazenar informa��oes  // o scanf pausa o programa // variavel do tipo inteiro %d 
	
       system("cls");                                                     // system "cls" = limpar os registros anteriores  
	            
	
	   
	   switch(opcao)    // Inicio Sele��o de do Menu                    
	   {
	   	    case 1:
	   	    Registro();    // Chamado de Fun��es
			break;
		    
		    case 2:
	   	    Consulta();	   // == compara��o 
		    break;
		    
		    case 3:
	   	    Deletar();    // Chamado de Fun��es
		    break;
		    
		    
		    case 4:
		    printf("Obrigado por Utilizar o Sistema !");
			return 0;                                               // Retona O valor 0 = Quebra la�o	e fun��o e sai do sistema
			break;                                                    
		   		       
		    default:
		    printf("Esta op��o n�o esta disponivel!\n\n");
		    system("pause");
		    break;
		             
					 // Final Sele��o de do Menu 		    
		}
    }
}

    int Registro() // Fun��o responsavel por cadastrar os usu�rios no sistema
   {
   	
   		setlocale(LC_ALL, "Portuguese");
   		
   		// Inicio cria��o de variaveis/string 	
   		char arquivo[40];
		char cpf[40];
		char nome [40];
		char cargo [40];
		char sobrenome[40];
		// Final da cria��o de variaveis/string 
	
		printf("Registro de Dados EBAC: \n\n");                        
		printf("Digite o CPF a ser cadastrado: ");                     //  Coletando Informarma��es dos Usuarios
    	scanf("%s", cpf);                                              // %s = Salvar dentro da String
    
    	strcpy(arquivo, cpf);                                          // Strcpy = Copiar os valores das String   // evitar de perguntar duas vezes,salva o valor da variavel x em outra variavel y 
    
    	FILE *file;                                                    // FILE = Chamamos uma fun��o ja predefinida pelo sistema - *file = criar arquivo 
    	file = fopen(arquivo,"w");                                     // cria o arquivo com a varievel "w" // "w" = write/escrever 
		fprintf(file, "\n CPF: ");                                     // Complemento
    	fprintf(file, cpf);                                            // salvo o valor da variavel
    	fclose(file);                                                  // fecha o arquivo
    
    	file = fopen(arquivo, "a");                                    // "a" = Atualizar a informa��o
    	fprintf(file, "\n Nome e Sobrenome: ");
    	fclose(file);
    
     
    	printf("Digite o Nome a ser cadastrado: ");
    	scanf("%s", nome);
    
    	file = fopen(arquivo, "a");                                                                                   
    	fprintf(file, nome);
    	fclose(file);
    
    	file = fopen(arquivo, "a");                                                                                    
    	fprintf(file, " ");                                            // Complemento
    	fclose(file);
	
		printf("Digite o Sobrenome a ser cadastrado: ");
    	scanf("%s", sobrenome);
    
    	file = fopen(arquivo, "a");                                                                                   
    	fprintf(file, sobrenome);
    	fclose(file);
    
    	file = fopen(arquivo, "a");                                                                                    
    	fprintf(file, "\n Cargo: ");                                  // Complemento
    	fclose(file);
    
    	printf("Digite o Cargo a ser cadastrado: ");
    	scanf("%s", cargo);
    
    
    	file = fopen(arquivo, "a");                                                                                   
    	fprintf(file, cargo);
    	fprintf(file,"\n\n");
    	fclose(file);
    
    	system("pause");
     
    
   }

    int Consulta() // Fun��o responsavel por Consultar Usuario
   {
	
		setlocale(LC_ALL, "Portuguese");
		
		// Inicio cria��o de variaveis/string 
		char cpf [40];
		char conteudo[200];
		// Final da cria��o de variaveis/string 
	
		printf("Digite o CPF a ser consultado:");                                 // Complemento 
		scanf("%s", cpf);
	
		system("cls");                                                            // system "cls" = limpar os registros anteriores 
	
		FILE *file;
		file = fopen(cpf , "r");                                                  // "r" = ler
    
    	printf("\nEssas s�o as informa��es do usu�rio:\n ");                      // Complemento                                        
	
		if(file == NULL)
		{
		printf("\nN�o foi possivel abrir o arquivo, n�o localizado!.\n\n");       // Complemento
		}
		
		while(fgets(conteudo, 200, file) != NULL)                                 // while = enquanto
		{
		printf("%s", conteudo);
		}
		                                                              
		system("pause");
	
   }

    int Deletar() // Fun��o responsavel por Deletar Usuario
   {
	
		setlocale(LC_ALL, "Portuguese");
		
		// Inicio cria��o de variaveis/string	
		char cpf[40];
		// Final da cria��o de variaveis/string 
	
		printf("Digite o CPF do usu�rio a ser Deletado: ");
		scanf("%s", cpf);
	
		system("cls");
	
		FILE *file;
		file = fopen(cpf , "r");
    	fclose(file);                                              // Colocar o fclose aqui para deletar o arquivo
		
	
		if(file == NULL)
		{
		printf("\nO Usuario n�o se encontra no sistema !. \n\n");
		system("pause");
		}
	
		else
		{
		remove(cpf);
		printf("\nDados de usu�rio deletado com sucesso!\n\n" );
		system("pause");
		}
	
   }
   
   
   
   
   // Perguntas a Fazer : Logo depois e Registrar um usuario n�o da pra deletar ele por que, o arquivo n�o some.



