#include <stdio.h>
#include <stdlib.h>

int main()
{
	//_____VARIAVEIS _____//
	int departmentNo;
	char doctor[30];
	int evaluationNote;
	char comment[101];
	char username[] = "John Wick";
	char Yes;
	//_____VARIAVEIS _____//

	//_____ENTRADA_____//
	printf("\n\n\n OLA!");
	printf("\n\n Nos, no MediCnal queremos sempre fazer o melhor para voce.");
	printf("\n\n Por isso nos pedimos avaliar sua experencia conosco e deixar um comentario do que voce gostou e do que nao.");
	//_____ENTRADA_____//

	printf("\n\n________________________________________________________________________________________________________________");

	//_____DEPARTAMENTO_____//
	printf("\n\n\n Informe numero qual departamento de clinica prestou servico para voce: ");
	printf("\n\n 1.Cardiologia                6.Gastroenterologia          11.Pediatria");
	printf("\n\n 2.Cirurgia Geral             7.Ginecologia                12.Psicologia");
	printf("\n\n 3.Cirurgia Plastica          8.Neurologia                 13.Psiquiatria");
	printf("\n\n 4.Dermatologia               9.Nutricao                   14.Reumatologia");
	printf("\n\n 5.Fisioterapia               10.Ortopedia                 15.Urologia\n\n");

	printf(" Numero de departamento: ");
	scanf("%d", &departmentNo);
	//_____DEPARTAMENTO_____//

	//_____SE DEPARTAMENTO NÃO EXISTE_____//
	while (departmentNo <= 0 || departmentNo > 15)
	{
		printf("\n\n________________________________________________________________________________________________________________");
		printf("\n\n\n Desculpa mas nao existe departamento %d. Tente de novo:", departmentNo);
		printf("\n\n Informe numero qual departamento de clinica prestou servico para voce: ");
		printf("\n\n 1. Cardiologia                6. Gastroenterologia          11. Pediatria");
		printf("\n\n 2. Cirurgia Geral             7. Ginecologia                12. Psicologia");
		printf("\n\n 3. Cirurgia Plastica          8. Neurologia                 13. Psiquiatria");
		printf("\n\n 4. Dermatologia               9. Nutricao                   14. Reumatologia");
		printf("\n\n 5. Fisioterapia               10. Ortopedia                 15. Urologia\n\n");

		printf(" Numero de departamento: ");
		scanf("%d", &departmentNo);
	}
	//_____SE DEPARTAMENTO NÃO EXISTE_____//

	printf("\n\n________________________________________________________________________________________________________________");

	//_____NOME DO MEDICO_____//
	printf("\n\n\n Escreve nome do seu medico: ");
	scanf("%s", &doctor);
	//_____NOME DO MEDICO_____//

	printf("\n\n________________________________________________________________________________________________________________");

	//_____AVALIAÇÃO___//
	printf("\n\n\n Em escala de 1 ate 5 como voce avalia sua experiencia (1 = muito ruim e 5 = muito bom): ");
	printf("\n 1 - 2 - 3 - 4 - 5");
	printf("\n\n SUA AVALIACAO: ");
	scanf("%d", &evaluationNote);

	//_____SE NOTA NÃO EXISTE_____//
	while (evaluationNote <= 0 || evaluationNote > 5)
	{
		printf("\n\n Desculpa mas nota %d e incorreta. Tente de novo:", evaluationNote);
		printf("\n 1 - 2 - 3 - 4 - 5");
		printf("\n________________________________________________________________________________________________________________");
		printf("\n\n SUA AVALIACAO: ");
		scanf("%d", &evaluationNote);
	}
	//_____SE NOTA NÃO EXISTE_____//

	printf("\n\n________________________________________________________________________________________________________________");

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

	//_____COMENTARIO___//
	printf("\n\n\n COMENTARIO:\n ");
	scanf("%s", &comment);

	printf("\n\n________________________________________________________________________________________________________________");

	printf("\n\n\n Antes terminar Voce deseja informar seu nome?");
	printf("\n\n Escreve letra S(sim)/N(nao):");
	scanf("%s", &Yes);

	if (Yes == 's' || Yes == 'S')
	{
		printf("\n\n Escreve seu nome:");
		scanf("%s", &username);
	}
	else
	{
		printf("\n\n Voce preferiu nao informar seu nome.");
	}

	

	//_____SAIDA_____//
	printf("\n\n\n Agradecemos sua opiniao =)\n\n");
	//_____SAIDA_____//

	system("pause");
	return 0;
}
