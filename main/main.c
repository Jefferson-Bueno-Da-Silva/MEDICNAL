#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <conio.h>

#define SIZE 100
#define TEMP 100
#define MAX_SZ 100

void menuPrincipal();
void menuFuncionario();
void menuFeedback();
void menuPaciente();
void menuAgendamento();
void cadastroPaciente();
void listarPaciente();
void menuMedico();
void cadastroMedico();
void listarMedico();
void cadastroAgendamento();
void listarAgendamento();
void cadastroUsuario();


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


void main(){
    //DEFININDO VARIAVEIS
    char login[MAX_SZ];
    char senha[MAX_SZ];    
    char nome[MAX_SZ];
    char loginCerto[MAX_SZ];
    char senhaCerta[MAX_SZ];
    char nomeDoArquivo[MAX_SZ];
    char caminho[MAX_SZ] = ".\\PIM_login\\";

    volta:

    //ENTRADA DE DADOS
    system("cls");
    // menuPrincipal();
    printf("**\t\tMEDCNAL\t\t**\n");
    // printf("login:\n");

    printf("LOGIN: ");
    scanf(" %[^\n]s", login); /*aqui você digita o login*/
//--------------------------
    strcpy(nomeDoArquivo, login);

    strcat(nomeDoArquivo, ".dat");

    strcat(caminho, nomeDoArquivo);
//------------------------------
    FILE *fp;
    fp = fopen(caminho,"r");

    fscanf(fp, "%[^\n]s", nome);
    fscanf(fp, "%s", &loginCerto);
    fscanf(fp, "%s", &senhaCerta);



    printf("SENHA: ");
    scanf("%s",senha);/*aqui você digita a senha*/

    if((strcmp(loginCerto,login) == 0) && (strcmp(senhaCerta,senha) == 0)){
        menuPrincipal(nome);
    }
    else{
        printf("ERRO\n\n");
        goto volta;
    }
    getch();
}

void menuPrincipal(char nome[MAX_SZ])
{
    SetConsoleTitle("MEDICNAL");
    int aberto = 1,
        op;

    do
    {
        system("cls");
        printf("\n\t\t\tBem vindo, %s!\t\t\t\n", nome);
        printf("Escolha uma das opcoes abaixo:\n");
        printf("1 - Agendamentos\t2-Pacientes\t\t3-Feedback pacientes\n");
        printf("4 - Medicos\t\t5 - Funcionarios\t6 - Cadastrar novo usuario\n");
        printf("\t\t\t7 - SAIR\n");
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            menuAgendamento();
            break;
        case 2:
            menuPaciente();
            break;    
        case 3:
            menuFeedback();
            break; 
        case 4:
            menuMedico();
            break;
        case 5:
            menuFuncionario();
            break;
        case 6:
            cadastroUsuario();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Opcao invalida, por gentileza tente novamente!\n");
            break;
        }
    } while (aberto == 1);
}

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

void menuFuncionario()
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
}


void menuPaciente()
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

void menuMedico(){
    int op;

    do{
        system("cls");
        printf("\t\t\t\t\tGERENCIAMENTO DE MEDICOS\n");
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

void menuFeedback()
{
	//_____VARIAVEIS _____//
	int departmentNo;
	int evaluationNote;
	// char doctorName[MAX_SZ];
	// char doctorSurname[MAX_SZ];
	char username[MAX_SZ];
	char comment[MAX_SZ];
	char Yes;
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

	// //_____NOME DO MEDICO_____//
	// printf("\n\n\n Escreve nome do seu medico em ordem [NOME] [SOBRENOME]: ");
	// scanf("%s %s", &doctorName, &doctorSurname);
	// //_____NOME DO MEDICO_____//

	// printf("\n\n________________________________________________________________________________________________________________");

	//_____AVALIAÇÃO___//
	//_____DO AVALIAÇÃO WHILE NOTA <= 0 OU NOTA > 15_____//
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
	// printf("myComment: %s", comment);
	//_____COMENTARIO____//

	printf("\n\n________________________________________________________________________________________________________________");

	//_____BANCO DE DADOS____//
	FILE *feedback;
	feedback = fopen("PIM_feedback\\feedbacks.txt", "a");

	fprintf(feedback, "NOME: %s\n", username);
	fprintf(feedback, "DEPARTAMENTO: %d\n", departmentNo);
	fprintf(feedback, "NOTA: %d\n", evaluationNote);
	fprintf(feedback, "COMENTARIO: %s\n", comment);
	fprintf(feedback, "_______________________________________________________\n\n");
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

void menuAgendamento()
{

    int op; //op�ao
    do{
        system("cls");
        printf("\t\t\tCADASTRO DE CONSULTAS\n");
        printf("1 - AGENDAR UMA CONSULTA\t2 - BUSCAR CONSULTA\t3 - VOTLAR AO MENU INICIAL\n");
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



//FUNÇÃO PARA CADASTRO DE USUARIOS
void cadastroUsuario()
{
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

    if(strcmp(senha,senha2) == 0){
        
        //--------------------------
        strcpy(nomeDoArquivo, login);

        strcat(nomeDoArquivo, ".dat");

        strcat(caminho, nomeDoArquivo);
        //------------------------------
        arquivo = fopen(caminho,"wb");

        fprintf(arquivo,"%s\n",nome);
        fprintf(arquivo,"%s\n",login);
    
        fprintf(arquivo,"%s\n",senha2);
        
    }else{
        printf("As duas senhas não conferem!\n");
        getch();
        goto inicio;
    }

    fclose(arquivo);
    system("pause");
}