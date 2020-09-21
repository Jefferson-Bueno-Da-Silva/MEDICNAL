#include <stdio.h>
#include <stdlib.h>

int main()
{
	int evaluationNote;
	char comment[101];
	char username[] = "John Doe";
	printf("\n\n\nOLA %s!\n", username);
	printf("\nNos, no MediCnal queremos sempre fazer o melhor para voce.\n");
	printf("\nPor isso nos pedimos avaliar sua experencia conosco e deixar um comentario do que voce gostou e do que nao.\n");
	printf("\nNos avalia em escala 1 - 10 (1 = muito ruim e 10 = muito bom): ");
	printf("\n1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10 \n");
	printf("\nSua avaliacao: ");
	scanf("%d", &evaluationNote);

	if (evaluationNote >= 1 && evaluationNote < 6)
	{
		printf("\nUFA! Nao e bom! ");
		printf("\nO que podemos fazer para melhorar sua experencia conosco?\n\n");
	}
	else if (evaluationNote >= 6 && evaluationNote < 8)
	{
		printf("\nAgradecemos pela avaliacao!\nComo podemos ainda mais melhorar sua experencia conosco?\n\n");
	}
	else if (evaluationNote >= 8 && evaluationNote < 11)
	{
		printf("\nFicamos felizes que voce esta satisfeito!");
		printf("\nPode excrever o que voce gostou mais da sua epxerencia conosco?\n\n");
	}
	else
	{
		printf("\nDesculpa mas nota %d e incorreta. Tente de novo:", evaluationNote);
		printf("\n1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10 \n");
		printf("\nSua avaliacao: ");
		scanf("%d", &evaluationNote);
	}

	printf("Comentario: ");
	scanf("%s", &comment);

	printf("\nAgradecemos sua opiniao =)\n\n");

	system("pause");
	return 0;
}
