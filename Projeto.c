#include <stdio.h>  //biblioteca da comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de  texto por região
#include <string.h> //biblioteca responsavel pelas string 
    
int main()
{
	int opcao=0;                                                             // Definição de Variavel      // = atributo 
	int x=1;
	
	for(x=1;x=1;)                                                            // x = laco 
	
	{
	   system("cls");
	    
	   setlocale(LC_ALL, "Portuguese");                                      // Definição de Linguagem
	
	    printf("\t\t ¦¦¦¦¦¦ Cartório da EBAC ¦¦¦¦¦¦  \n\n");	             // Incicio do Menu
	    printf("\t Escola Britânica de Artes Criativas & Tecnologia\n\n\n");
	
	        printf("Escolha a opção desejada através do menu:\n\n\n");       // Identação = organização
	
               	printf("\t1 - Registrar Usuário \n\n");                      // Comandos Menu
               	
	            printf("\t2 - Consultar Usuário \n\n");                      // Comandos Menu
	            
	            printf("\t3 - Deletar Usuário\n\n");	                     // Comandos Menu e Final do Menu
	            
	            printf("\t4 - Sair do Sistema\n\n\n");

                printf("Digite sua Opção:");
		            
	            
	   scanf("%d", &opcao);                                               // Scanear e Armazenar informaçãoes  // o scanf pausa o programa // variavel do tipo inteiro %d 
	
       system("cls");                                                     // system "cls" = limpar os registros anteriores  
	            
	
	   
	   switch(opcao)    // Inicio Seleção de do Menu                    
	   {
	   	    case 1:
	   	    Registro();    // Chamado de Funções
			break;
		    
		    case 2:
	   	    Consulta();	   // == comparação 
		    break;
		    
		    case 3:
	   	    Deletar();    // Chamado de Funções
		    break;
		    
		    
		    case 4:
		    printf("Obrigado por Utilizar o Sistema !");
			return 0;                                               // Retona O valor 0 = Quebra laço	e função e sai do sistema
			break;                                                    
		   		       
		    default:
		    printf("Esta opção não esta disponivel!\n\n");
		    system("pause");
		    break;
		             
					 // Final Seleção de do Menu 		    
		}
    }
}

    int Registro() // Função responsavel por cadastrar os usuários no sistema
   {
   	
   		setlocale(LC_ALL, "Portuguese");
   		
   		// Inicio criação de variaveis/string 	
   		char arquivo[40];
		char cpf[40];
		char nome [40];
		char cargo [40];
		char sobrenome[40];
		// Final da criação de variaveis/string 
	
		printf("Registro de Dados EBAC: \n\n");                        
		printf("Digite o CPF a ser cadastrado: ");                     //  Coletando Informarmações dos Usuarios
    	scanf("%s", cpf);                                              // %s = Salvar dentro da String
    
    	strcpy(arquivo, cpf);                                          // Strcpy = Copiar os valores das String   // evitar de perguntar duas vezes,salva o valor da variavel x em outra variavel y 
    
    	FILE *file;                                                    // FILE = Chamamos uma função ja predefinida pelo sistema - *file = criar arquivo 
    	file = fopen(arquivo,"w");                                     // cria o arquivo com a varievel "w" // "w" = write/escrever 
		fprintf(file, "\n CPF: ");                                     // Complemento
    	fprintf(file, cpf);                                            // salvo o valor da variavel
    	fclose(file);                                                  // fecha o arquivo
    
    	file = fopen(arquivo, "a");                                    // "a" = Atualizar a informação
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

    int Consulta() // Função responsavel por Consultar Usuario
   {
	
		setlocale(LC_ALL, "Portuguese");
		
		// Inicio criação de variaveis/string 
		char cpf [40];
		char conteudo[200];
		// Final da criação de variaveis/string 
	
		printf("Digite o CPF a ser consultado:");                                 // Complemento 
		scanf("%s", cpf);
	
		system("cls");                                                            // system "cls" = limpar os registros anteriores 
	
		FILE *file;
		file = fopen(cpf , "r");                                                  // "r" = ler
    
    	printf("\nEssas são as informações do usuário:\n ");                      // Complemento                                        
	
		if(file == NULL)
		{
		printf("\nNão foi possivel abrir o arquivo, não localizado!.\n\n");       // Complemento
		}
		
		while(fgets(conteudo, 200, file) != NULL)                                 // while = enquanto
		{
		printf("%s", conteudo);
		}
		                                                              
		system("pause");
	
   }

    int Deletar() // Função responsavel por Deletar Usuario
   {
	
		setlocale(LC_ALL, "Portuguese");
		
		// Inicio criação de variaveis/string	
		char cpf[40];
		// Final da criação de variaveis/string 
	
		printf("Digite o CPF do usuário a ser Deletado: ");
		scanf("%s", cpf);
	
		system("cls");
	
		FILE *file;
		file = fopen(cpf , "r");
    	fclose(file);                                              // Colocar o fclose aqui para deletar o arquivo
		
	
		if(file == NULL)
		{
		printf("\nO Usuario não se encontra no sistema !. \n\n");
		system("pause");
		}
	
		else
		{
		remove(cpf);
		printf("\nDados de usuário deletado com sucesso!\n\n" );
		system("pause");
		}
	
   }
   
   
   
   
   // Perguntas a Fazer : Logo depois e Registrar um usuario não da pra deletar ele por que, o arquivo não some.



