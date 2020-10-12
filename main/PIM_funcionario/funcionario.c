#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TEMP 100


struct endereco
{
    char rua     [TEMP], estado  [TEMP],
        cidade  [TEMP], cep     [TEMP],
        numero[TEMP];
};

struct info
{
	char
    nome[TEMP], cargo [TEMP], telefone [TEMP], 
	CPF[TEMP], status[TEMP],
    salario[TEMP];
    struct endereco end;
};

void cadastroFuncionario()
{
    struct info _info;
    char nomeDoArquivo[TEMP];
    char caminho[TEMP] = ".\\PIM_funcionario\\";
    FILE *arquivo;

    system("cls");
    printf("Nome: \n");
    scanf(" %[^\n]s", _info.nome);

    printf("Cargo: \n ");
    scanf(" %[^\n]s", _info.cargo);

    printf("Telefone: \n ");
    scanf(" %[^\n]s", _info.telefone);

    printf("CPF: \n ");
    scanf(" %[^\n]s", _info.CPF);

    printf("Salario: \n ");
    scanf(" %[^\n]s", _info.salario);

    printf("Status: \n");
    scanf(" %[^\n]s", _info.status);

    printf("Rua: \n ");
    scanf(" %[^\n]s", _info.end.rua);

    printf("Estado: \n ");
    scanf(" %[^\n]s", _info.end.estado);

    printf("Cidade: \n ");
    scanf(" %[^\n]s", _info.end.cidade);

    printf("CEP: \n ");
    scanf(" %[^\n]s", _info.end.cep);

    printf("Numero: \n ");
    scanf(" %[^\n]s", _info.end.numero);

    //--------------------------
    strcpy(nomeDoArquivo, _info.nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, nomeDoArquivo);
    //------------------------------
    arquivo = fopen(caminho,"wb");

    fprintf(arquivo,"\n");
    fprintf(arquivo,"Nome: %s\n", _info.nome);
    fprintf(arquivo,"Cargo: %s\n",_info.cargo);
    fprintf(arquivo,"Telefone: %s\n", _info.telefone);
    fprintf(arquivo,"CPF: %s\n",_info.CPF);
    fprintf(arquivo,"Salario: %s\n", _info.salario);
    fprintf(arquivo,"Status: %s\n", _info.status);
    fprintf(arquivo,"Rua: %s\n", _info.end.rua);
    fprintf(arquivo,"Estado: %s\n", _info.end.estado);
    fprintf(arquivo,"Cidade: %s\n", _info.end.cidade);
    fprintf(arquivo,"CEP: %s\n", _info.end.cep);
    fprintf(arquivo,"Numero: %s\n", _info.end.numero);

    fclose(arquivo);
}

void listarFuncionario(){
    char nome[TEMP];
    char nomeDoArquivo[TEMP];
    char linha[5];
    char caminho[TEMP] = ".\\PIM_funcionario\\";
    FILE *arquivo;

    system("cls");
    printf("Escreva o nome do Colaborador: \n");
    scanf(" %[^\n]s", nome);

    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, nomeDoArquivo);
	
    arquivo = fopen(caminho,"rb");

    if (fgets(linha, 80, arquivo) == NULL)
    {
        printf("%s", caminho);
        printf("\nNao exite um Colaborador com esse nome!\n");
    }
    while (fgets(linha, 80, arquivo) != NULL)
    {
        printf("%s", linha);
    }
    system("pause");
    fclose(arquivo);
}

int menuFuncionario()
{
    setlocale(LC_ALL, "Portuguese");
    int opt;
    int aberto = 1;
    while (aberto)
    {
        do{
            system("cls");
            printf("===================== Software de Controle de funcionarios =========================\n");
			printf("1 - Incluir funcionario.\t");
            printf("2 - Buscar funcionario.\t\t");
            printf("3 - Sair.\n\n");
            printf("Digite sua opcao:\n");
            printf("====================================================================================\n");            
            scanf("%i", &opt);
        } while ((opt < 1) && (opt > 3));

        switch (opt)
        {
            case 1:
                cadastroFuncionario();
                break;
            case 2:
                listarFuncionario();
                break;
            case 3:
                aberto = 0;
                break;
        }
    }
    return 0;
}
