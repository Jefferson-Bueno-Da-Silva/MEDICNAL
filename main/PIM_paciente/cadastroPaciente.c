#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SZ 100

void cadastroPaciente();
void listarPaciente();


int menuPaciente()
{

    int op; //op�ao
    do{
        system("cls");
        printf("\t\t\tCADASTRO DE PACIENTES\n");
        printf("1 - CADASTRAR PACIENTE\t2 - BUSCAR UM PACIENTE\t3 - VOLTAR AO MENU INICIAL\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                cadastroPaciente();
                break;
            case 2:
                listarPaciente();
                break;
            case 3:
                break;
            default:
                printf("Opcao: %d INVALIDA", op);
            break;
        }
    }
    while(op!=3);

return 0;

}
void cadastroPaciente()
{
    char nome[MAX_SZ];
    char sexo[MAX_SZ];
    char nascimento[MAX_SZ];
    char telefone1[MAX_SZ];
    char telefone2[MAX_SZ];
    char cpf[MAX_SZ];
    char rg[MAX_SZ];
    char cep[MAX_SZ];
    char endereco[MAX_SZ];
    char email[MAX_SZ];

    char nomeDoArquivo[MAX_SZ];
    char caminho[MAX_SZ] = ".\\PIM_paciente\\";
    FILE *arquivo;


    printf("Escreva o nome do paciente: \n");
    scanf(" %[^\n]s", nome);
    
    printf("Escreva o sexo do paciente F feminino M masculino: \n");
    scanf(" %[^\n]s", sexo);
    
    printf("Escreva a data de nascimento: \n");
    scanf(" %[^\n]s", nascimento);
    
    printf("Numero de telefone para contato: \n ");
    scanf(" %[^\n]s", telefone1);
    
    printf("Outro numero de telefone para contato: \n ");
    scanf(" %[^\n]s", telefone2);
    
    printf("Cpf do paciente: \n ");
    scanf(" %[^\n]s", cpf);
    
    printf("Rg do paciente: \n ");
    scanf(" %[^\n]s", rg);
    
    printf("Cep do paciente: \n ");
    scanf(" %[^\n]s", cep);
    
    printf("Endereco do paciente: \n ");
    scanf(" %[^\n]s", endereco);
    
    printf("E-mail do paciente: \n ");
    scanf(" %[^\n]s", email); 

    //--------------------------
    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, nomeDoArquivo);
    //------------------------------
    arquivo = fopen(caminho,"wb");

    fprintf(arquivo,"\n");
	fprintf (arquivo,"Nome: %s\n",nome);
	fprintf (arquivo,"Sexo: %s\n",sexo);
   	fprintf (arquivo,"Data de nascimento: %s\n",nascimento);
   	fprintf (arquivo,"Telefone: %s\n",telefone1);
   	fprintf (arquivo,"Telefone 2: %s\n",telefone2);
   	fprintf (arquivo,"CPF: %s\n",cpf);
   	fprintf (arquivo,"RG: %s\n",rg);
   	fprintf (arquivo,"CEP: %s\n",cep);
   	fprintf (arquivo,"Endereco: %s\n",endereco);
	fprintf (arquivo,"Email: %s\n",email);

    fclose(arquivo);
}

void listarPaciente(){
    char nome[MAX_SZ];
    char nomeDoArquivo[MAX_SZ];
    char linha[5];
    char caminho[MAX_SZ] = ".\\PIM_paciente\\";
    FILE *arquivo;

    system("cls");
    printf("Escreva o nome do paciente: \n");
    scanf(" %[^\n]s", nome);

    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, nomeDoArquivo);
	
    arquivo = fopen(caminho,"rb");

    if (fgets(linha, 80, arquivo) == NULL)
    {
        printf("%s", caminho);
        printf("\nNao exite um agendamento com esse nome!\n");
    }
    while (fgets(linha, 80, arquivo) != NULL)
    {
        printf("%s", linha);
    }
    system("pause");
    fclose(arquivo);
}