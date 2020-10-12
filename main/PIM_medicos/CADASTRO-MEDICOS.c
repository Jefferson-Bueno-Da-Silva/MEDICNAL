#include <stdio.h>
#include <string.h>
#define SIZE 100

void menuMedico();
void cadastroMedico();
void listarMedico();

void menuMedico(){
    int op;

    do{
        system("cls");
        printf("\t\t\t\t\tGerenciamento de Medicos\n");
        printf("1 - CADASTRAR UM MEDICO NOVO\t2 - LISTAR MEDICOS CADASTRADOS\t3 - VOLTAR AO MENU PRINCIPAl\n");
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            cadastroMedico();
            break;
        case 2:
            listarMedico();
            break;
        case 3:
            break;
        default:
            printf("**\tOpcao invalida!!\t**");
            break;
        }
        
    }while(op != 3);
}

void cadastroMedico()
{
    char nome[SIZE];
    char crm[SIZE];
    char email[SIZE];
    char cpf [SIZE];
    char telefone [SIZE];
    char nomeArquivo[SIZE];
    char caminho[SIZE] = ".\\PIM_medicos\\";
    FILE *arquivo;

    printf("Escreva o nome do Medico: \n");
    scanf(" %[^\n]s", nome);

    printf("Numero do crm: \n ");
    scanf(" %[^\n]s", crm);

    printf("E-mail para contato: \n ");
    scanf(" %[^\n]s", email);

    printf("CPF: \n ");
    scanf(" %[^\n]s", cpf);

    printf("Telefone para contato: \n ");
    scanf(" %[^\n]s", telefone);

    //--------------------------
    strcpy(nomeArquivo, nome);

    strcat(nomeArquivo, ".bin");

    strcat(caminho, nomeArquivo);
    //------------------------------
    arquivo = fopen(caminho,"wb");

    fprintf(arquivo,"\n");
    fprintf(arquivo,"nome: %s\n",nome);
    fprintf(arquivo,"CRM: %s\n",crm);
    fprintf(arquivo,"EMAIL: %s\n",email);
    fprintf(arquivo,"CPF: %s\n",cpf);
    fprintf(arquivo,"TELEFONE: %s\n",telefone);

    fclose(arquivo);
}

void listarMedico(){
    char nome[SIZE];
    char nomeDoArquivo[SIZE];
    char linha[5];
    char caminho[SIZE] = ".\\PIM_medicos\\";
    FILE *arquivo;

    system("cls");
    printf("Escreva o nome do Doutor(a): \n");
    scanf(" %[^\n]s", nome);

    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, nomeDoArquivo);
	
    arquivo = fopen(caminho,"rb");

    if (fgets(linha, 80, arquivo) == NULL)
    {
        printf("%s", caminho);
        printf("\nNao exite um medico com esse nome!\n");
    }
    while (fgets(linha, 80, arquivo) != NULL)
    {
        printf("%s", linha);
    }
    system("pause");
    fclose(arquivo);
}
