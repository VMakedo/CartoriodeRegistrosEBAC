#include <stdio.h>//bilioteca de comunicação com usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>// biblioteca de alocações de texto por região
#include <string.h>// biblioteca responsável pela gestão das string
#include <stdbool.h>

int addReg ()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");
	char archive06[220];
	char cpf[40];
	char name[40];
	char surname[40];
	char role[40];
	
	printf("Registro de indivíduo. Insira o CPF a ser cadastrado: \n"); 
	scanf("%s", cpf); 
	getchar(); 
	
	strcpy(archive06, cpf); 
	
	FILE *file; 
	file = fopen(archive06, "w"); 
	fprintf(file, "%s\n", cpf); 
	fclose(file); 
	
	printf("Registro de indivíduo. Insira o nome a ser cadastrado: \n"); 
	fgets(name, sizeof(name), stdin); 
	
	file = fopen(archive06, "a"); 
	fprintf(file, "%s", name); 
	fclose(file); 
	
	printf("Registro de indivíduo. Insira o sobrenome a ser cadastrado: \n"); 
	fgets(surname, sizeof(surname), stdin); 
	
	file = fopen(archive06, "a"); 
	fprintf(file, "%s", surname); 
	fclose(file); 
	
	printf("Registro de indivíduo. Insira o cargo a ser cadastrado: \n"); 
	fgets(role, sizeof(role), stdin); 
	
	file = fopen(archive06, "a"); 
	fprintf(file, "%s", role); 
	fclose(file); 
	
	printf("Informações de indivíduo registradas com sucesso.\n"); 
	system("pause"); 
	return 0;
}
int conReg() 
{ 
	setlocale(LC_ALL, "pt_BR.UTF-8");
    char cpf[40]; 
    char content[400]; 

    printf("Consulta de cadastro de indivíduo. Insira o CPF para consulta:\n"); 
    scanf("%s", cpf); 
    
    FILE *file = fopen(cpf, "r"); 

    if (file == NULL) { printf("Não foi possível encontrar este CPF. Tente novamente.\n"); 
    
    system("pause"); 
    return 1; 
    } 
    
    printf("\nInformações do indivíduo obtidas com sucesso:\n"); 
   
    char* titles[] = { "CPF: ", "Nome: ", "Sobrenome: ", "Cargo: " }; 
    int tt = 0; 
    
    while (fgets(content, sizeof(content), file) != NULL && tt < sizeof(titles)/sizeof(titles[0])) 
    { 
        printf("%s%s", titles[tt], content,"%s"); tt++;
        } 
        fclose(file); 
        system("pause"); 
    return 0;
}
int delReg ()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");
	char cpf [40];

	printf("Apagar cadastro de indivíduo. Insira o CPF que deverá ser apagado:\n");
	scanf("%s", cpf);
	
	if (remove(cpf) == 0) 
	{ 
	printf("Informações apagadas conforme solicitado.\n"); 
	} 
	else 
	{ 
	printf("Não foi possível encontrar este CPF. Tente novamente.\n"); 
	}
			
	system("pause");
	return 0;
}

bool askRet() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int choice; 
    printf("Deseja realizar outra operação? (1 - Sim, 0 - Não): "); 
    scanf("%d", &choice); 
    getchar(); 
    return (choice == 1); 
}

int main()
{
	int opcao = 0;
	int q = 1;
	char pSystem [18];
	setlocale(LC_ALL, "pt_BR.UTF-8");
	
	while(true) 
	{
	setlocale(LC_ALL, "pt_BR.UTF-8");
	printf("--- Cartório de Registros EBAC ---\n\n");
	printf("Administrador, realize seu login!\n\n Digite sua senha: ");
	scanf("%18s", pSystem);
	system("cls");
	
	if(strcmp(pSystem, "admin") == 0)
	{
	for (q=1;q=1;)
	{	
		printf("--- Cartório de Registros EBAC ---\n\n");
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registro de indivíduo\n\n"); 
		printf("\t2 - Consulta de cadastro de indivíduo\n\n"); 
		printf("\t3 - Apagar cadastro de indivíduo\n\n");
		printf("\t4 - Sair\n\n");
		
		printf("Opção: ");
		
		scanf ("%d", &opcao);
		
		system("cls");
				
				switch (opcao) { 
					case 1: 
						do { 
							addReg(); 
									} 
						while (askRet()); 
						break; 
						
					case 2: 
						do { 
							conReg(); 
									} 
						while (askRet()); 
						break; 
						
					case 3: 
						do { 
							delReg(); 
									} 
						while (askRet());
						break;
					
					case 4: 
                        printf("Executando saída do sistema...\n");
                        system("pause");
                        return 0;
			
					default:
						printf("A opção selecionada não corresponde a um dos valores válido. Insira 1, 2, 3 ou 4.\n");
							system("pause");
					break;
								}
		system("cls");
        }
    }
        else
        {
            printf("Senha incorreta! Por favor consulte com seu administrador.\n\n");
            system("pause");
            system("cls");
        }
    }
    return 0;
}
	//printf("###This software belongs to an EBAC student and is part of a personal project, all rights reserved.###");

