#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <dirent.h>

#define SIZE 100
#define TEMP 100
#define MAX_SZ 100


void menuPrincipal(); //MENU QUE LEVA PARA AS OUTRAS FUNÇÕES
void menuFuncionario(); //MENU DO MÓDULO DE FUNCIONARIO
void menuFeedback(); //MENU DO MÓDULO DE FEEDBACK
void menuPaciente(); //MENU DO MÓDULO DE PACIENTE
void menuAgendamento(); // MENU MÓDULO DE AGENDAMENTO
void menuMedico(); //MENU MÓDULO MEDICO
void menuRelatorios(); //MENU MÓDULO DE RELATÓRIOS
void faturamento(); //MÓDULO DE PADAMENTO

//MÓDULO FUNCIONARIOS
void cadastroFuncionario();
void listarFuncionario();

//MÓDULO PASSIENTES
void cadastroPaciente();
void listarPaciente();

//MÓDULO MÉDICO
void cadastroMedico();
void listarMedico();

//MÓDULO AGENDAMENTO
void cadastroAgendamento();
void listarAgendamento();
void cancelaAgendamento();

//MÓDULO USUARIO
void cadastroUsuario();

//MÓDULO FATURAMENTO
void gravaFaturamento();

//MÓDULO RELATÓRIO
void pacientesPorRede();
void medicosPorRede();
void funcionariosPorRede();
void usuariosPorRede();
void redeMaisAtende();
void faturamentoUnidade();
void feedbackUnidade();



struct endereco
{
    char rua    [TEMP], estado  [TEMP],
        cidade  [TEMP], cep     [TEMP],
        numero  [TEMP];
};

struct info
{
	char
    nome[TEMP], cargo [TEMP], telefone [TEMP], 
	CPF[TEMP], status[TEMP],
    salario[TEMP];
    struct endereco end;
};


int main(){
    //DEFININDO VARIAVEIS
    char login[MAX_SZ];
    char senha[MAX_SZ];    
    char nome[MAX_SZ];
    char loginCerto[MAX_SZ];
    char senhaCerta[MAX_SZ];
    char nomeDoArquivo[MAX_SZ];
    int op;
    char unidade[MAX_SZ] = "";
    char caminho[MAX_SZ] = ".\\PIM_login\\";

    volta:
    strcpy(unidade, "");
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL LOGIN");
    //ENTRADA DE DADOS
    system("cls");
    printf("**\t\tMEDCNAL\t\t**\n");

    printf("ESCOLHA A UNIDADE: ");
    scanf("%i", &op);
    switch (op)
    {
    case 1:
        strcat(unidade, "UNIDADE_1\\");
        break;
    case 2:
        strcat(unidade, "UNIDADE_2\\");
        break;
    case 3:
        strcat(unidade, "UNIDADE_3\\");
        break;
    default:
        printf("OP invalida\n");
        system("pause");
        goto volta;
        break;
    }

    printf("LOGIN: ");
    scanf(" %[^\n]s", login); /*aqui você digita o login*/

    //MANIPULAÇÃO DE STRINGS:
//--------------------------
    //COMPIA O NOME DO LOGIN PARA O NOME DO ARQUIVO
    strcpy(nomeDoArquivo, login);

    //ESCREVE A ESTENÇÃO .dat NO ARQUIVO
    strcat(nomeDoArquivo, ".dat");

    //RESET DA VARIAVEL PARA RECEBER O CAMINHO
    strcpy(caminho, ".\\PIM_login\\");

    //RECEBE O CAMINHO DA UNIDADE
    strcat(caminho, unidade);

    //RECEBE O NOME DO ARQUICO
    strcat(caminho, nomeDoArquivo);
//------------------------------
    FILE *fp;
    fp = fopen(caminho,"r");

    fscanf(fp, "%[^\n]s", nome);
    fscanf(fp, "%s", &loginCerto);
    fscanf(fp, "%s", &senhaCerta);

    printf("SENHA: ");
    scanf("%s",senha);/*aqui você digita a senha*/

    //COMPRARA AS DUAS STRIGS DE SENHA
    if((strcmp(loginCerto,login) == 0) && (strcmp(senhaCerta,senha) == 0)){
        //PASSA O NOME E A UNIDADE COMO PARAMETRO
        menuPrincipal(nome, unidade);
    }
    else{
        printf("ERRO\n\n");
        goto volta;
    }
    getch();
    return 0;
}

void menuPrincipal(char nome[MAX_SZ], char unidade[MAX_SZ])
{
    //VARIAVEIS
    int aberto = 1,
        op;

    do
    {
        //DEFINE O NOME DO CONSOLE
        SetConsoleTitle("MEDICNAL");
        //ENTRADAS
        system("cls");
        printf("\n\t\t\tBem vindo, %s!\t\t\t\n", nome);
        printf("\nEscolha uma das opcoes abaixo:\n");
        printf("1 - Agendamentos\t2 - Pacientes\t\t3 - Feedback pacientes\n");
        printf("4 - Medicos\t\t5 - Funcionarios\t6 - Cadastrar novo usuario\n");
        printf("7 - Faturamento \t8 - Relatorio \t\t9 - SAIR\n");
        scanf("%i", &op);
        switch (op)
        {
            //SAIDAS
        case 1:
            menuAgendamento(unidade);
            break;
        case 2:
            menuPaciente(unidade);
            break;    
        case 3:
            menuFeedback(unidade);
            break; 
        case 4:
            menuMedico(unidade);
            break;
        case 5:
            menuFuncionario(unidade);
            break;
        case 6:
            cadastroUsuario(unidade);
            break;
        case 7:
            faturamento(unidade);
            break;
        case 8:
            menuRelatorios();
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("Opcao invalida, por gentileza tente novamente!\n");
            break;
        }
    } while (aberto == 1);
}

// ============ INICIO DO MÓDULO DE FUNCIONARIO ================
void menuFuncionario(char unidade[MAX_SZ])
{
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL FUNCIONARIOS");
    //ENTRADA DE TEXTO COM ACENTUAÇÃO
    setlocale(LC_ALL, "Portuguese");
    //DEFININDO VARIAVEIS
    int opt;
    int aberto = 1;
    //RODA O PROGRAMA INFINITAMENTE
    while (aberto)
    {
        do{
            system("cls");
            printf("===================== Menu de funcionarios =========================\n");
			printf("1 - Incluir funcionario.\t");
            printf("2 - Buscar funcionario.\t\t");
            printf("3 - Sair.\n\n");
            printf("Digite sua opcao: ");            
            scanf("%i", &opt);
        } while ((opt < 1) && (opt > 3));

        switch (opt)
        {
            case 1:
                cadastroFuncionario(unidade);
                break;
            case 2:
                listarFuncionario(unidade);
                break;
            case 3:
                aberto = 0;
                break;
        }
    }
}


void cadastroFuncionario(char unidade[MAX_SZ])
{
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL CADASTRO FUNCIONARIOS");
    //VARIAVEIS
    struct info _info;
    char nomeDoArquivo[TEMP];
    char caminho[TEMP] = ".\\PIM_funcionario\\";
    FILE *arquivo;

    //ENTRADA DE DADOS
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

    //GRAVA O TXT COM O NOME DIGITADO
    //--------------------------
    strcpy(nomeDoArquivo, _info.nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, unidade);

    strcat(caminho, nomeDoArquivo);

    //------------------------------
    arquivo = fopen(caminho,"wb");

    //GRAVA AS INFORMAÇÕES DENTRO DO TXT
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

    //FECHA O ARQUIVO
    fclose(arquivo);
}

void listarFuncionario(char unidade[MAX_SZ])
{
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL LISTAGEM FUNCIONARIOS");
    //DEFININDO VARIAVEIS
    char nome[TEMP];
    char nomeDoArquivo[TEMP];
    char linha[5];
    char caminho[TEMP] = ".\\PIM_funcionario\\";
    FILE *arquivo;
    
    //ENTRADA
    system("cls");
    printf("Escreva o nome do Colaborador: \n");
    scanf(" %[^\n]s", nome);

    //GRAVAÇÃO EM ARQUIVO COM O NOME DIGITADO
    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, unidade);

    strcat(caminho, nomeDoArquivo);
	
    arquivo = fopen(caminho,"rb");

    //LEITURA DOS DADOS
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
    
    //FECHA O ARQUIVO
    fclose(arquivo);
}
// ============ FIM DO MÓDULO DE FUNCIONARIO ================
// ============ INICIO DO MÓDULO DE PACIENTES ================
void menuPaciente(char unidade[MAX_SZ])
{
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL MENU PACIENTE");
    //DEFININDO VARIAVEIS
    int op; //op�ao
    do{
        //ENTRADA DE DADOS
        system("cls");
        printf("\t\t\tCADASTRO DE PACIENTES\n");
        printf("1 - CADASTRAR PACIENTE\t2 - BUSCAR UM PACIENTE\t3 - VOLTAR AO MENU INICIAL\n");
        scanf("%d", &op);

        //ESCOLHA
        switch(op){
            //SAIDAS
            case 1:
                cadastroPaciente(unidade);
                break;
            case 2:
                listarPaciente(unidade);
                break;
            case 3:
                break;
            default:
                printf("Opcao: %d INVALIDA", op);
            break;
        }
    }
    while(op!=3);
}


void cadastroPaciente(char unidade[MAX_SZ])
{
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL CADASTRO PACIENTE");
    //DEFININDO VARIAVEIS
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

    //ENTRADA DE DADOS
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

    //CRIAÇÃO DO TXT COM NOME DO PACIENTE
    //--------------------------
    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, unidade);

    strcat(caminho, nomeDoArquivo);
    //------------------------------
    arquivo = fopen(caminho,"wb");

    //GRAVAÇÃO DOS DADOS NO ARQUIVO
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

    //FECHA O ARQUIVO
    fclose(arquivo);
}

void listarPaciente(char unidade[MAX_SZ]){
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL LISTAGEM PACIENTE");

    //DEFININDO VARIAVEIS
    char nome[MAX_SZ];
    char nomeDoArquivo[MAX_SZ];
    char linha[5];
    char caminho[MAX_SZ] = ".\\PIM_paciente\\";
    FILE *arquivo;

    //ENTRADA DE DADOS
    system("cls");
    printf("Escreva o nome do paciente: \n");
    scanf(" %[^\n]s", nome);

    //ABERTURA DO ARQUIVO COM O NOME DO PACIENTE
    //=============================
    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, unidade);

    strcat(caminho, nomeDoArquivo);
    //=============================
	
    arquivo = fopen(caminho,"rb");

    //LEITURA DO ARQUIVO
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
// ============ FIM DO MÓDULO DE PACIENTES ================
// ============ INICIO DO MÓDULO DE MÉDICO ================
void menuMedico(char unidade[MAX_SZ]){
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL MENU MEDICO");

    //VARIAVEIS
    int op;

    do{
        //ENTRADA DE DADOS
        system("cls");
        printf("\t\t\t\t\tGERENCIAMENTO DE MEDICOS\n");
        printf("1 - CADASTRAR UM MEDICO NOVO\t2 - LISTAR MEDICOS CADASTRADOS\t3 - VOLTAR AO MENU PRINCIPAl\n");
        scanf("%i", &op);
        switch (op)
        {
            //SAIDAS
        case 1:
            cadastroMedico(unidade);
            break;
        case 2:
            listarMedico(unidade);
            break;
        case 3:
            break;
        default:
            printf("**\tOpcao invalida!!\t**");
            break;
        }
        
    }while(op != 3);
}

void cadastroMedico(char unidade[MAX_SZ])
{
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL CADASTRO MEDICO");
    //DEFININDO VARIAVEIS
    char nome[SIZE];
    char crm[SIZE];
    char email[SIZE];
    char cpf [SIZE];
    char telefone [SIZE];
    char nomeArquivo[SIZE];
    char caminho[SIZE] = ".\\PIM_medicos\\";
    FILE *arquivo;

    //ENTRADAS
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

    //GRAVA O TXT COM O NOME DO MEDICO
    //--------------------------
    strcpy(nomeArquivo, nome);

    strcat(nomeArquivo, ".bin");

    strcat(caminho, unidade);

    strcat(caminho, nomeArquivo);
    //------------------------------
    arquivo = fopen(caminho,"wb");

    //GRAVA AS INFORMAÇÕES
    fprintf(arquivo,"\n");
    fprintf(arquivo,"nome: %s\n",nome);
    fprintf(arquivo,"CRM: %s\n",crm);
    fprintf(arquivo,"EMAIL: %s\n",email);
    fprintf(arquivo,"CPF: %s\n",cpf);
    fprintf(arquivo,"TELEFONE: %s\n",telefone);

    //FECHA O ARQUIVO
    fclose(arquivo);
}

void listarMedico(char unidade[MAX_SZ]){
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL LISTAGEM MEDICO");

    //DEFININDO VARIAVEIS
    char nome[SIZE];
    char nomeDoArquivo[SIZE];
    char linha[5];
    char caminho[SIZE] = ".\\PIM_medicos\\";
    FILE *arquivo;

    //ENTRADA DE DADOS
    system("cls");
    printf("Escreva o nome do Doutor(a): \n");
    scanf(" %[^\n]s", nome);

    //PROCURA O ARQUIVO COM O NOME DO MEDICO
    //=============================
    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, unidade);

    strcat(caminho, nomeDoArquivo);
    //==============================
	
    arquivo = fopen(caminho,"rb");

    //LEITURA DAS INFORMAÇÕES DO ARQUIVO
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
    //FECHA O ARQUIVO
    fclose(arquivo);
}
// ============ FIM DO MÓDULO DE MÉDICO ================
// ============ INICIO DO MÓDULO DE FEEDBACK ================
void menuFeedback(char unidade[MAX_SZ])
{
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL FEEDBACK");

	//_____VARIAVEIS _____//
	int departmentNo;
	int evaluationNote;
	char username[MAX_SZ];
	char comment[MAX_SZ];
	char Yes;
    char caminho[MAX_SZ] = ".\\PIM_feedback\\";
	//_____VARIAVEIS _____//

	system("cls");

	//_____ENTRADA_____//
	printf("\n\n\n OLA!");
	printf("\n\n Nos, no MediCnal queremos sempre fazer o melhor para voce.");
	printf("\n\n Por isso nos pedimos avaliar sua experencia conosco e deixar um comentario do que voce gostou e do que nao.\n\n");
	//_____ENTRADA_____//

	system("pause");

	//_____NOME_____//
	printf("\n\n\n Voce deseja informar seu nome?");
	printf("\n\n Escreve letra S(sim)/N(nao): ");
	scanf("%s", &Yes);

	if (Yes == 's' || Yes == 'S')
	{
		printf("\n\n Escreve seu nome: ");
		scanf(" %[^\n]s", username);
	}
	else
	{
		printf("\n\n Voce preferiu nao informar seu nome.");
	}
	//_____NOME_____//

	printf("\n\n________________________________________________________________________________________________________________");

	//_____DEPARTAMENTO_____//
	do
	{
		printf("\n\n\n Informe numero qual departamento de clinica prestou servico para voce: ");
		printf("\n\n 1.Cardiologia                6.Gastroenterologia          11.Pediatria");
		printf("\n\n 2.Cirurgia Geral             7.Ginecologia                12.Psicologia");
		printf("\n\n 3.Cirurgia Plastica          8.Neurologia                 13.Psiquiatria");
		printf("\n\n 4.Dermatologia               9.Nutricao                   14.Reumatologia");
		printf("\n\n 5.Fisioterapia               10.Ortopedia                 15.Urologia\n\n");

		printf(" Numero de departamento: ");
		scanf("%d", &departmentNo);
		if (departmentNo <= 0 || departmentNo > 15)
		{
			printf("\n\n________________________________________________________________________________________________________________");
			printf("\n\n\n ***ERROR***\n\n\n Desculpa mas nao existe departamento %d. Tente de novo:", departmentNo);
		}
		else
		{
			printf("\n\n________________________________________________________________________________________________________________");
		}

	} while (departmentNo <= 0 || departmentNo > 15);
	//_____DEPARTAMENTO_____//

	do
	{
		printf("\n\n\n Em escala de 1 ate 5 como voce avalia sua experiencia (1 = muito ruim e 5 = muito bom): ");
		printf("\n 1 - 2 - 3 - 4 - 5");
		printf("\n\n SUA AVALIACAO: ");
		scanf("%d", &evaluationNote);
		if (evaluationNote <= 0 || evaluationNote > 5)
		{
			printf("\n\n________________________________________________________________________________________________________________");
			printf("\n\n\n ***ERROR***\n\n\n Desculpa mas nao tem nota %d. Tente de novo:", evaluationNote);
		}
		else
		{
			printf("\n\n________________________________________________________________________________________________________________");
		}

	} while (evaluationNote <= 0 || evaluationNote > 5);
	//_____DO AVALIAÇÃO WHILE NOTA <= 0 OU NOTA > 15_____//

	if (evaluationNote >= 1 && evaluationNote < 4)
	{
		printf("\n\n\n UFA! Nao e bom!\n\n O que podemos fazer para melhorar sua experencia conosco? ");
	}
	else if (evaluationNote == 4)
	{
		printf("\n\n\n Obrigado pela avaliacao!\n\n Como podemos ainda mais melhorar sua experencia conosco?");
	}
	else if (evaluationNote == 5)
	{
		printf("\n\n\n Ficamos felizes que voce esta satisfeito!\n\n Pode excrever o que voce gostou mais da sua epxerencia conosco?");
	}
	//_____AVALIAÇÃO___//

	//_____COMENTARIO____//
	printf("\n\n\n COMENTARIO:\n ");
	scanf(" %[^\n]s", comment);
	//_____COMENTARIO____//

	printf("\n\n________________________________________________________________________________________________________________");

	//_____BANCO DE DADOS____//
	FILE *feedback;

    strcat(caminho, unidade);

    strcat(caminho, "feedbacks.txt");

	feedback = fopen(caminho, "a");

	fprintf(feedback, "NOME: %s\n", username);
	fprintf(feedback, "DEPARTAMENTO: %d\n", departmentNo);
	fprintf(feedback, "%i\n", evaluationNote);
	fprintf(feedback, "COMENTARIO: %s\n", comment);
	fprintf(feedback, "_______________________________________________________\n");

	fclose(feedback);
	//_____BANCO DE DADOS____//

	//_____SAIDA_____//
	printf("\n\n\n Agradecemos sua opiniao =)\n\n");

	if (Yes == 'S' || Yes == 's')
	{
		printf("\n NOME: %s", username);
	}
	else
	{
		printf("\n\n NOME: Anonymo");
	}
	printf("\n\n DEPARTAMENTO: %d", departmentNo);
	printf("\n\n NOTA: %d", evaluationNote);
	printf("\n\n COMENTARIO: %s", comment);
	printf("\n\n");
	//_____SAIDA_____//

	system("pause");
}
// ============ FIM DO MÓDULO DE FEEDBACK ================
// ============ INICIO DO MÓDULO DE AGENDAMENTOS ================
void menuAgendamento(char unidade[MAX_SZ])
{
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL MENU AGENDAMENTOS");

    //DEFININDO VARIAVEIS
    int op; //op�ao
    do{
        //ENTRADA DE DADOS
        system("cls");
        printf("\t\t\tCADASTRO DE CONSULTAS\n");
        printf("1 - AGENDAR CONSULTA\t2 - BUSCAR CONSULTA\t3 - CANCELAR CONSULTA\n\t\t\t4 - VOTLAR AO MENU INICIAL\n");
        scanf("%d", &op);

        switch(op){
            //SAIDAS
            case 1:
                cadastroAgendamento(unidade);
                break;
            case 2:
                listarAgendamento(unidade);
                break;
            case 3:
                cancelaAgendamento(unidade);
                break;
            case 4:
                break;
            default:
                printf("Opcao: %d INVALIDA", op);
            break;
        }
    }
    while(op!=4);
}

void cadastroAgendamento(char unidade[MAX_SZ])
{
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL CADASTRO DE AGENDAMENTO");

    //DEFININDO VARIAVEIS
    char nome[MAX_SZ];
    char telefone1[MAX_SZ];
    char telefone2[MAX_SZ];
    char dia[MAX_SZ];
    char hora[MAX_SZ];
    char nomeDoArquivo[MAX_SZ];
    char caminho[MAX_SZ] = ".\\PIM_Agendamento\\";
    FILE *arquivo;

    //ENTRADAS
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

    //CRIA UM ARQUIVO COM O NOME DO PACIENTE AGENDADO
    //--------------------------
    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, unidade);

    strcat(caminho, nomeDoArquivo);
    //------------------------------
    arquivo = fopen(caminho,"wb");

    //GRAVAÇÃO DE DADOS NO ARQUIVO
    fprintf(arquivo,"\n");
    fprintf(arquivo,"nome: %s\n",nome);
    fprintf(arquivo,"telefone: %s\n",telefone1);
    fprintf(arquivo,"telefone: %s\n",telefone2);
    fprintf(arquivo,"dia: %s\n",dia);
    fprintf(arquivo,"hora: %s\n",hora);
    fprintf(arquivo,"Consulta agendada: SIM\n");

    //FECHA O ARQUIVO
    fclose(arquivo);
}

void listarAgendamento(char unidade[MAX_SZ]){
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL LISTAR AGENDAMENTO");

    //DEFININDO VARIAVEIS
    char nome[MAX_SZ];
    char nomeDoArquivo[MAX_SZ];
    char linha[5];
    char caminho[MAX_SZ] = ".\\PIM_Agendamento\\";
    FILE *arquivo;

    //ENTRADA
    system("cls");
    printf("Escreva o nome do paciente: \n");
    scanf(" %[^\n]s", nome);

    //PROCURA O ARQUIVO COM O NOME DIGITADO
    //=============================
    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, unidade);

    strcat(caminho, nomeDoArquivo);
	//==============================

    arquivo = fopen(caminho,"rb");

    //LEITURA DO ARQUIVO
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

void cancelaAgendamento(char unidade[MAX_SZ]){

    //DEFININDO VARIAVEIS
    int op;
    char nome[MAX_SZ];
    char cancelamento[MAX_SZ] = "Consulta agendada: NAO\n";
    char linha[MAX_SZ];
    char nomeDoArquivo[MAX_SZ];
    char caminho[MAX_SZ] = ".\\PIM_Agendamento\\";

    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL CANCELAR AGENDAMENTO");

    //ENTRADA DE DADOS
    system("cls");
    printf("Escreva o nome do paciente: \n");
    scanf(" %[^\n]s", nome);
    
    //PROCURA O ARQUIVO COM O NOME
//--------------------------
    strcpy(nomeDoArquivo, nome);

    strcat(nomeDoArquivo, ".bin");

    strcat(caminho, unidade);

    strcat(caminho, nomeDoArquivo);
//------------------------------
    
    //ABRE UM ARQUIVO
    FILE *fp;
    fp = fopen(caminho,"rb+");

    do{
        //VERIFICA SE O ARQUIVO EXISTE
        if (fgets(linha, 80, fp) == NULL)
        {
            printf("\nNao exite um agendamento com esse nome! %s\n", nome);
        }

        //FAZ A LEITURA DO ARQUIVO
        while (fgets(linha, 80, fp) != NULL)
        {
            printf("%s", linha);
        }

        //ENTRADA DE DADOS
        printf("Deseja cancelar esta consulta ?\n(1 - SIM / 2 - NAO): ");
        scanf("%i", &op);

        //SAIDA DE DADOS NO ARQUIVO
        if (op == 1)
        {
            fseek(fp, -23, SEEK_END);
            fputs(cancelamento, fp);
            printf("Consulta Cancelada!\n");
            getch();
            break;
        }
        fclose(fp);
    }while(op != 2);
}

// ============ FIM DO MÓDULO DE AGENDAMENTOS ================

// ============ INICIO DO MÓDULO DE USUARIOS =================
//FUNÇÃO PARA CADASTRO DE USUARIOS
void cadastroUsuario(char unidade[MAX_SZ])
{
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL CADASTRO");

    //DEFININDO VARIAVEIS
    char login[MAX_SZ];
    char senha[MAX_SZ];
    char senha2[MAX_SZ];
    char nome[MAX_SZ];
    char nomeDoArquivo[MAX_SZ];
    char caminho[MAX_SZ] = ".\\PIM_login\\";
    FILE *arquivo;

    inicio:

    //ENTRADA DE DADOS
    system("cls");
    printf("**\tCadastro de usuarios\t**\n");
    printf("Digite o nome do funcionario a ser cadastrado: \n");
    scanf(" %[^\n]s", nome);
    printf("Digite o login:\n");
    scanf(" %[^\n]s", login);
    printf("Digite a senha: \n");
    scanf("%s", senha);
    printf("Digite a senha novamente: \n");
    scanf(" %[^\n]s", senha2);

    //COMPARA SE AS SENHAS SÃO IGUAIS
    if(strcmp(senha,senha2) == 0){
        
        //CRIA UM ARQUIVO PARA A GRAVAÇÃO DOS DADOS
        //--------------------------
        strcpy(nomeDoArquivo, login);

        strcat(nomeDoArquivo, ".dat");

        strcat(caminho, unidade);

        strcat(caminho, nomeDoArquivo);
        //------------------------------

        arquivo = fopen(caminho,"wb");

        //GRAVAÇÃO DOS DADOS
        fprintf(arquivo,"%s\n",nome);
        fprintf(arquivo,"%s\n",login);
    
        fprintf(arquivo,"%s\n",senha2);
        
    }else{
        //SE AS SENHAS ESTÃO DIFERENTES ELE REPETE
        printf("As duas senhas não conferem!\n");
        getch();
        goto inicio;
    }

    //FECHA O ARQUIVO
    fclose(arquivo);
    system("pause");
}
// ============ FIM DO MÓDULO DE USUARIOS ================

// ============ INICIO MÓDULO FATURAMENTO ================
void faturamento(char unidade[MAX_SZ]){
    
    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL FATURAMENTO");

    //DEFININDO VARIAVEIS
    int op; //op�ao
    int parcelas; //quarda a quantidade de parcelas
    do{
        //ENTRADA DE DADOS
        system("cls");
        printf("\t\t\tFATURAMENTO\n\n");
        printf("\t\t\tEscolha a forma de pagamento:\n");
        printf("1 - Debito \t2 - Credito \t3 - A Vista\t4 - VOTLAR AO MENU INICIAL\n");
        scanf("%d", &op);

        switch(op){
            //SAIDAS
            case 1:
                printf("\n\t\t\t***\tForma de pagamento selecionada: DEBITO\t***\n");
                gravaFaturamento(unidade, op);
                printf("Pamamento registrado com sucesso\n");
                getch();
                break;
            case 2:
                printf("\n\t\t\t***\tForma de pagamento selecionada: CREDITO\t***\n");
                printf("Quantidade de parcelas: ");
                scanf("%i", &parcelas);
                gravaFaturamento(unidade, op);
                printf("Pamamento registrado com sucesso\n");
                getch();
                break;
            case 3:
                printf("\n\t\t\t***\tForma de pagamento selecionada: A VISTA\t***\n");
                gravaFaturamento(unidade, op);
                printf("Pamamento registrado com sucesso\n");
                getch();
                break;
            case 4:
                break;
            default:
                printf("Opcao: %d INVALIDA", op);
            break;
        }
    }
    while(op!=4);

}

void gravaFaturamento(char unidade[MAX_SZ], int op){
    //VARIAVEIS
    float valor, clienteValor, troco;
    char nomeDoArquivo[MAX_SZ] = "faturamento";
    char caminho[MAX_SZ] = ".\\PIM_Faturamento\\";

    //ponteiro para struct que armazena data e hora
    struct tm *data_hora_atual;

    //variável do tipo time_t para armazenar o tempo em segundos  
    time_t segundos;
  
    //obtendo o tempo em segundos  
    time(&segundos); 

    //para converter de segundos para o tempo local  
    //utilizamos a função localtime  
    data_hora_atual = localtime(&segundos); 

    FILE *arquivo;
    
    //FIM VARIAVEIS

    //PROCESSAMENTO
    do{
        printf("Digite o valor cobrado: \n");
        scanf("%f", &valor);
        if(op == 3){
            printf("Valor entregue pelo cliente: ");
            scanf("%f", &clienteValor);

            troco = clienteValor - valor;

            printf("Troco: %.2f\n", troco);
            getch();
        }

        //CRIA UM ARQUIVO PARA A GRAVAÇÃO DOS DADOS
        //--------------------------

        strcat(nomeDoArquivo, ".dat");

        strcat(caminho, unidade);

        strcat(caminho, nomeDoArquivo);
        //------------------------------

        arquivo = fopen(caminho,"ab");

        //SAIDA
        //DIA
        fprintf(arquivo, "%d\n", data_hora_atual->tm_mday);
        //MES
        fprintf(arquivo, "%d\n", data_hora_atual->tm_mon+1);
        //VALOR DO PAGAMENTO
        fprintf(arquivo, "%f\n", valor);
        break;

    }while(1);
    //FECHA O ARQUIVO
    fclose(arquivo);
}
// ============ FIM MÓDULO FATURAMENTO    ================

//============= INICIO MÓDULO RELATÓRIOS  ================

void menuRelatorios(){

    //NOME DO CONSOLE
    SetConsoleTitle("MEDICNAL MENU RELATORIOS");

    //DEFININDO VARIAVEIS
    int op; //op�ao
    do{
        //ENTRADA DE DADOS
        system("cls");
        printf("\t\t\t\tRELATORIOS\n");
        printf("1 - Pacientes por unidade de rede\t2 - Medicos por unidade de rede\n");
        printf("3 - Funcionarios por unidade de rede\t4 - Usuarios por unidade de rede\n");
        printf("5 - Unidade da rede que mais atende\t6 - Faturamento mensal por unidade\n");
        printf("\t\t\t7 - VOLTAR AO MENU INICIAL\n");
        scanf("%d", &op);

        switch(op){
            //SAIDAS
            case 1:
                pacientesPorRede();
                break;
            case 2:
                medicosPorRede();
                break;
            case 3:
                funcionariosPorRede();
                break;
            case 4:
                usuariosPorRede();
                break;
            case 5:
                redeMaisAtende();
                break;
            case 6:
                faturamentoUnidade();
                break;
            case 7:
                break;
            default:
                printf("Opcao: %d INVALIDA", op);
            break;
        }
    }
    while(op!=7);

}

void pacientesPorRede(){
    
    //VARIAVEIS
    int op, cont = 0, i;
    char unidade[MAX_SZ] = "";
    char nomearquivo[MAX_SZ];
    char verNomearquivo[MAX_SZ];
    char caminho[MAX_SZ] = ".\\PIM_paciente\\";
    DIR *dir;
    struct dirent *lsdir;
    
    //LABEL DE VOLTA
    volta:

    //ENTRADA
    system("cls");
    printf("Digite a unidade: ");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        strcat(unidade, "UNIDADE_1\\");
        break;
    case 2:
        strcat(unidade, "UNIDADE_2\\");
        break;
    case 3:
        strcat(unidade, "UNIDADE_3\\");
        break;
    default:
        printf("OP invalida\n");
        goto volta;
        break;
    }

    //CAMINHO DA UNIDADE ESCOLHIDA
    strcat(caminho, unidade);

    //ABERTURA DA PASTA
    dir = opendir(caminho);

    // ESCREVE O NOME DOS ARQUIVOS
    for(i = 0; ( lsdir = readdir(dir) ) != NULL; i++ )
    {
        if (i >= 2)
        {
            strcpy(nomearquivo, lsdir->d_name);
            strncpy(verNomearquivo, nomearquivo, strlen(nomearquivo) - 4);
            printf (" --> %s\n", verNomearquivo);
            cont++;
        }
    }
    //SAIDA DE DADS
    
    printf("Quantidade de pacientes na unidade %i eh: %i", op, cont);

    //PAUSE
    getch();

    //FECHA A PASTA
    closedir(dir);
}

void medicosPorRede(){
    
    //VARIAVEIS
    int op, cont = 0, i;
    char unidade[MAX_SZ] = "";
    char nomearquivo[MAX_SZ];
    char verNomearquivo[MAX_SZ];
    char caminho[MAX_SZ] = ".\\PIM_medicos\\";
    DIR *dir;
    struct dirent *lsdir;
    
    //LABEL DE VOLTA
    volta:

    //ENTRADA
    system("cls");
    printf("Digite a unidade: ");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        strcat(unidade, "UNIDADE_1\\");
        break;
    case 2:
        strcat(unidade, "UNIDADE_2\\");
        break;
    case 3:
        strcat(unidade, "UNIDADE_3\\");
        break;
    default:
        printf("OP invalida\n");
        goto volta;
        break;
    }

    //CAMINHO DA UNIDADE ESCOLHIDA
    strcat(caminho, unidade);

    //ABERTURA DA PASTA
    dir = opendir(caminho);

    // ESCREVE O NOME DOS ARQUIVOS
    for(i = 0; ( lsdir = readdir(dir) ) != NULL; i++ )
    {
        if (i >= 2)
        {
            strcpy(nomearquivo, lsdir->d_name);
            strncpy(verNomearquivo, nomearquivo, strlen(nomearquivo) - 4);
            printf (" --> %s\n", verNomearquivo);
            cont++;
        }
    }
    //SAIDA DE DADS
    
    printf("Quantidade de medicos na unidade %i eh: %i", op, cont);

    //PAUSE
    getch();

    //FECHA A PASTA
    closedir(dir);
}

void funcionariosPorRede(){
    
    //VARIAVEIS
    int op, cont = 0, i;
    char unidade[MAX_SZ] = "";
    char nomearquivo[MAX_SZ];
    char verNomearquivo[MAX_SZ];
    char caminho[MAX_SZ] = ".\\PIM_funcionario\\";
    DIR *dir;
    struct dirent *lsdir;
    
    //LABEL DE VOLTA
    volta:

    //ENTRADA
    system("cls");
    printf("Digite a unidade: ");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        strcat(unidade, "UNIDADE_1\\");
        break;
    case 2:
        strcat(unidade, "UNIDADE_2\\");
        break;
    case 3:
        strcat(unidade, "UNIDADE_3\\");
        break;
    default:
        printf("OP invalida\n");
        goto volta;
        break;
    }

    //CAMINHO DA UNIDADE ESCOLHIDA
    strcat(caminho, unidade);

    //ABERTURA DA PASTA
    dir = opendir(caminho);

    // ESCREVE O NOME DOS ARQUIVOS
    for(i = 0; ( lsdir = readdir(dir) ) != NULL; i++ )
    {
        if (i >= 2)
        {
            strcpy(nomearquivo, lsdir->d_name);
            strncpy(verNomearquivo, nomearquivo, strlen(nomearquivo) - 4);
            printf (" --> %s\n", verNomearquivo);
            cont++;
        }
    }
    //SAIDA DE DADS
    
    printf("Quantidade de funcionarios na unidade %i eh: %i", op, cont);

    //PAUSE
    getch();

    //FECHA A PASTA
    closedir(dir);
}

void usuariosPorRede(){
    
    //VARIAVEIS
    int op, cont = 0, i;
    char unidade[MAX_SZ] = "";
    char nomearquivo[MAX_SZ];
    char verNomearquivo[MAX_SZ];
    char caminho[MAX_SZ] = ".\\PIM_login\\";
    DIR *dir;
    struct dirent *lsdir;
    
    //LABEL DE VOLTA
    volta:

    //ENTRADA
    system("cls");
    printf("Digite a unidade: ");
    scanf("%i", &op);

    switch (op)
    {
    case 1:
        strcat(unidade, "UNIDADE_1\\");
        break;
    case 2:
        strcat(unidade, "UNIDADE_2\\");
        break;
    case 3:
        strcat(unidade, "UNIDADE_3\\");
        break;
    default:
        printf("OP invalida\n");
        goto volta;
        break;
    }

    //CAMINHO DA UNIDADE ESCOLHIDA
    strcat(caminho, unidade);

    //ABERTURA DA PASTA
    dir = opendir(caminho);

    // ESCREVE O NOME DOS ARQUIVOS
    for(i = 0; ( lsdir = readdir(dir) ) != NULL; i++ )
    {
        if (i >= 2)
        {
            strcpy(nomearquivo, lsdir->d_name);
            strncpy(verNomearquivo, nomearquivo, strlen(nomearquivo) - 4);
            printf (" --> %s\n", verNomearquivo);
            cont++;
        }
    }
    //SAIDA DE DADS
    
    printf("Quantidade de usuarios na unidade %i eh: %i", op, cont);

    //PAUSE
    getch();

    //FECHA A PASTA
    closedir(dir);
}


void redeMaisAtende(){

    //VARIAVEIS
    int i, j;
    char nomearquivo[MAX_SZ];
    char *unidades[3];
    unidades[0] = "UNIDADE_1";
    unidades[1] = "UNIDADE_2";
    unidades[2] = "UNIDADE_3";
    int cont[3];

    char caminho[MAX_SZ] = "";
    DIR *dir;
    struct dirent *lsdir;

    //ESTRUTURA DE REPEDIÇÃO
    for(j = 0; j < 3; j++){

        cont[j] = 0;
        //RESET DO CAMINHO
        strcpy(caminho, ".\\PIM_Agendamento\\");
        //CAMINHO DA UNIDADE
        strcat(caminho, unidades[j]);
        //ABRE O DIRETORIO
        dir = opendir(caminho);


        //PROCESSAMENTO, ENTRA NO DIRETORIO E CONTRA QUANTOS ARQUIVOS
        //PULA A PASTA RAIZ E O ".."
        for(i = 0; ( lsdir = readdir(dir) ) != NULL; i++ )
        {
            if (i >= 2)
            {
                cont[j]++;
            }
        }
        closedir(dir);
    }
    //FECHA A PASTA
    system("cls");
    //SAIDA DE DADOS
    printf("UNIDADE 1\tUNIDADE 2\tUNIDADE 3\n");
    printf("   %i \t\t    %i \t\t    %i \n", cont[0], cont[1], cont[2]);

    //VERIFICAÇÃO DE UNIDADE QUE MAIS ATENDE
    if(cont[0] > cont[1] && cont[0] > cont[2]){
        printf("A unidade que mais atende eh: %s\n", unidades[0]);
    }else if(cont[1] > cont[0] && cont[1] > cont[2]){
        printf("A unidade que mais atende eh: %s\n", unidades[1]);
    }else if(cont[2] > cont[1] && cont[2] > cont[0]){
        printf("A unidade que mais atende eh: %s\n", unidades[2]);
    }else if(cont[0] == cont[1]){
        printf("As unidades %s e %s estao empatadas\n", unidades[0], unidades[1]);
    }else if(cont[1] == cont[2]){
        printf("As unidades %s e %s estao empatadas\n", unidades[1], unidades[2]);
    }else if(cont[2] == cont[0]){
        printf("As unidades %s e %s estao empatadas\n", unidades[0], unidades[2]);
    }

    getch();
}

void faturamentoUnidade(){
    //VARIAVEIS
    int i, j, k = 0, l = 0, cont;
    int op;
    float resultadoDias[3];
    float resultadoMeses[3];
    float media[3];

    //ponteiro para struct que armazena data e hora
    struct tm *data_hora_atual;

    //variável do tipo time_t para armazenar o tempo em segundos  
    time_t segundos;
  
    //obtendo o tempo em segundos  
    time(&segundos); 

    //para converter de segundos para o tempo local  
    //utilizamos a função localtime  
    data_hora_atual = localtime(&segundos); 

    int diaAtual = data_hora_atual->tm_mday;

    int mesAtual = data_hora_atual->tm_mon + 1;

    int mesAtualVerifica = data_hora_atual->tm_mon + 1;


    //VARIAVEIS DE PASTA
    char *unidades[3];
    unidades[0] = "UNIDADE_1\\";
    unidades[1] = "UNIDADE_2\\";
    unidades[2] = "UNIDADE_3\\";
    char caminho[MAX_SZ] = "";
    char nomearquivo[MAX_SZ];
    DIR *dir;
    struct dirent *lsdir;

    //VARIAVEIS DE ARQUIVOS
    int *dias;
    int dia;
    dias = (int *) malloc(dia * sizeof(int));
    int *meses;
    int mes;
    meses = (int *) malloc(mes * sizeof(int));
    float *valores;
    float valor;
    valores = (float *) malloc(valor * sizeof(float));
    
    FILE *arquivo;



    //ENTRADA
    volta:
    system("cls");
    printf("\t\tFaturamento %i/%i\n", diaAtual, mesAtual);
    printf("Deseja selecionar uma data especifica?\n");
    printf("0 - Dia/Mes atual\t1 - escolher data especifica: ");
    scanf("%i", &op);
    if(op == 1){
        printf("Dia: ");
        scanf("%i", &diaAtual);
        printf("Mes: ");
        scanf("%i", &mesAtual);
        if(mesAtual > mesAtualVerifica){
            printf("DATA INVALIDA!!!!\n");
            getch();
            goto volta;
        }
    }
    //PROCESSAMENTO

    //ESTRUTURA DE REPEDIÇÃO
    for(j = 0; j < 3; j++){
        //RESET DO CAMINHO
        strcpy(caminho, ".\\PIM_Faturamento\\");
        //CAMINHO DA UNIDADE
        strcat(caminho, unidades[j]);
        //ABRE O DIRETORIO
        dir = opendir(caminho);


        //PROCESSAMENTO, ENTRA NO DIRETORIO E CONTRA QUANTOS ARQUIVOS
        //PULA A PASTA RAIZ E O ".."
        for(i = 0; ( lsdir = readdir(dir) ) != NULL; i++ )
        {
            if (i >= 2)
            {
                //ENTRA NA PASTA PARA LER OS ARQUIVOS
                strcpy(nomearquivo, lsdir->d_name);

                //CONCATENA O NOME DO ARQUIVO NO CAMINHO
                strcat(caminho, nomearquivo);

                //PROCESSAMENTO DO ARQUIVO
                arquivo = fopen(caminho, "rb");

                while(fscanf(arquivo, "%i", &dias[k]) != EOF && fscanf(arquivo, "%i", &meses[k]) != EOF && fscanf(arquivo, "%f", &valores[k]) != EOF){
                    //CALCULO DIA ATUAL:
                    if(diaAtual == dias[k] && mesAtual == meses[k]){
                        resultadoDias[l] += valores[k];
                    }

                    if(mesAtual == meses[k]){
                        resultadoMeses[l] += valores[k];
                        cont++;
                    }
                    k++;
                }
                l++;
                fclose(arquivo);
            }
        }
    }
    closedir(dir);

    for(i = 0; i < 3; i++){
        media[i] = resultadoMeses[i] / cont;

    }

    //SAIDA DE DADOS
    system("cls");
    printf("\t\tFaturamento %i/%i\n", diaAtual, mesAtual);
    printf("\t\tDo dia\t\tDo mes\t\tMedia mes\n");
    printf("Unidade 1:\t%.2f\t\t %.2f\t%.2f \n", resultadoDias[0], resultadoMeses[0], media[0]);
    printf("Unidade 2:\t%.2f\t\t %.2f\t\t%.2f \n", resultadoDias[1], resultadoMeses[1], media[1]);
    printf("Unidade 3:\t%.2f\t\t %.2f\t\t%.2f \n", resultadoDias[2], resultadoMeses[2], media[2]);
    //PAUSE
    getch();
}
// ============ FIM MÓDULO RELATÓRIOS ================
