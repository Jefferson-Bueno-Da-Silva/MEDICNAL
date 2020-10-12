#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "PIM_Agendamento\\agendamento.c"
#include "PIM_feedback\\feedback.c"
#include "PIM_medicos\\CADASTRO-MEDICOS.c"
#include "PIM_paciente\\cadastroPaciente.c"

//LOGIN AQUI//


int main()
{
    SetConsoleTitle("MEDICNAL");
    int aberto = 1,
        op;

    do
    {
        system("cls");
        printf("\n\t\t\tBem vindo!\t\t\t\n");
        printf("Escolha uma das opcoes abaixo:\n");
        printf("1 - Agendamentos\t2-Pacientes\t3-Feedback pacientes\n");
        printf("4 - Medicos\t5-sair\t\n");
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
            exit(0);
            break;
        default:
            printf("Opcao invalida, por gentileza tente novamente!\n");
            break;
        }
    } while (aberto == 1);
    
    return 0;
}
