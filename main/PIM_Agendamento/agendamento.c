#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SZ 100

void cadastroAgendamento();
void listarAgendamento();

int menuAgendamento()
{

    int op; //op�ao
    do{
        system("cls");
        printf("Cadastro de consultas\nDigite 1 para cadastrar\nDigite 2 para listar\nDigite 3 para sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                cadastroAgendamento();
                break;
            case 2:
                listarAgendamento();
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
void cadastroAgendamento()
{
    char nome[MAX_SZ];
    char telefone1[MAX_SZ];
    char telefone2[MAX_SZ];
    char dia[MAX_SZ];
    char hora[MAX_SZ];
    char nomeDoArquivo[MAX_SZ];
    char caminho[MAX_SZ] = ".\\PIM_Agendamento\\";
    FILE *arquivo;


    printf("Escreva o nome do paciente: \n");
    scanf(" %[^\n]s", nome);

    printf("Numero de telefone para contato: \n ");
    scanf(" %[^\n]s", telefone1);

    printf("Outro numero de telefone para contato: \n ");
    scanf(" %[^\n]s", telefone2);

    printf("Dia da consulta: \n ");
    scanf(" %[^\n]s", dia);

    printf("Hora da consulta: \n ");
    scanf(" %[^\n]s", hora);

    //--------------------------
    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, nomeDoArquivo);
    //------------------------------
    arquivo = fopen(caminho,"wb");

    fprintf(arquivo,"\n");
    fprintf(arquivo,"nome: %s\n",nome);
    fprintf(arquivo,"telefone: %s\n",telefone1);
    fprintf(arquivo,"telefone: %s\n",telefone2);
    fprintf(arquivo,"dia: %s\n",dia);
    fprintf(arquivo,"hora: %s\n",hora);
    fprintf(arquivo,"Consulta agendada: SIM\n");

    fclose(arquivo);
}

void listarAgendamento(){
    char nome[MAX_SZ];
    char nomeDoArquivo[MAX_SZ];
    char linha[5];
    char caminho[MAX_SZ] = ".\\PIM_Agendamento\\";
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