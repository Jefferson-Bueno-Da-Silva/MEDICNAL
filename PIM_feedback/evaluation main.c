#include <stdio.h>
#include <stdlib.h>

#define MAX_SZ 1001

int main()
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
	feedback = fopen("feedbacks.txt", "a");

	fprintf(feedback, "NOME: %s\n", username);
	fprintf(feedback, "DEPARTAMENTO: %d\n", departmentNo);
	fprintf(feedback, "NOTA: %d\n", evaluationNote);
	fprintf(feedback, "COMENTARIO: %s\n", comment);
	fprintf(feedback, "_______________________________________________________\n\n", comment);
	fclose(feedback);
	//_____BANCO DE DADOS____//

	//_____SAIDA_____//
	printf("\n\n\n Agradecemos sua opiniao =)\n\n");

	if (Yes == 'S' || Yes == 's')
	{
		printf("\n\ NOME: %s", username);
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
	return 0;
}
