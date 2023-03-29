#include <stdio.h>
#include <stdlib.h>
#define LINHAS 3
#define MAX_PRESENCA 50

void Limpar(){ // limpa a tela msm se for pc linux/windows
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
}

typedef struct lista
{
   int ra;
   int presenca;
   float nota1;
   float nota2;
   int status;
}lista;

int inclu =0; // var para aumentar capacidade de alunos

void Gerenciar(lista *alunos){
                    // sai do programa ou gerencia
    int a = 0;
    printf("\nSair( 0 )  |  Gerenciar ( 1 )\n\t   ");
    scanf("%d",&a);
    switch(a){
    case 0:
        exit(0);
    case 1:
        menu(alunos);
        }

}

void excluir_aluno(lista *alunos){
    Limpar();

    printf("Selcione o aluno para Excluir.\n");
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n");
    for (int i = 0; i < LINHAS + inclu; i++) { //roda o num de linhas se inclui for 0, quando inclu aluno roda + 1 vez pra mostrar o aluno incluido
            if(alunos[i].nota1 == -1 && alunos[i].nota2 == -1 && alunos[i].presenca == -1 && alunos[i].status == -1){
               continue; } // nao imprime alunos excluidos
        printf("%d\t%.1f\t%.1f\t%d\t%d\tAluno:%d\n", alunos[i].ra , alunos[i].nota1, alunos[i].nota2,
                alunos[i].presenca,alunos[i].status,i+1);
    }

    int indice =0;

    printf("\nExcluir aluno: "); // escolhe aluno para excluir
    scanf("%d",&indice);

        if(indice > LINHAS + inclu || indice == 0){ // nao exclui alunos que nao existem
            excluir_aluno(alunos);}

        if(alunos[indice - 1].nota1 == -1){ // nao exclui aluno ja excluido
            excluir_aluno(alunos);}

        alunos[indice -1].nota1 = -1;
        alunos[indice - 1].nota2 = -1; // alunos excluidos recebem dados = -1
        alunos[indice - 1].presenca = -1;
        alunos[indice -1].status = -1;

        Gerenciar(alunos); // fecha programa ou vai pro menu

}

void alterar_aluno(lista *alunos){
    Limpar();

    printf("Selcione o aluno para alterar.\n");
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n");
    for (int i = 0; i < LINHAS + inclu; i++) { //roda o num de linhas se inclui for 0, quando inclu aluno roda + 1 vez pra mostrar o aluno incluido
            if(alunos[i].nota1 == -1 && alunos[i].nota2 == -1 && alunos[i].presenca == -1 && alunos[i].status == -1){
               continue; } // nao imprime alunos excluidos
        printf("%d\t%.1f\t%.1f\t%d\t%d\tAluno:%d\n", alunos[i].ra , alunos[i].nota1, alunos[i].nota2,
                alunos[i].presenca,alunos[i].status,i+1);
    }

    int indice =0;

    printf("\nAlterar aluno: "); // escolhe qual aluno alterar
    scanf("%d",&indice);

    if(indice > LINHAS + inclu || indice == 0){ // nao altera alunos que nao existem
            alterar_aluno(alunos);
        }

    if(alunos[indice - 1].nota1 == -1){ // nao altera aluno excluido
        alterar_aluno(alunos);}

        Limpar();

        printf("Nota 1B: ");
        scanf("%f", &alunos[indice -1].nota1);
        printf("Nota 2B: ");
        scanf("%f", &alunos[indice - 1].nota2); // altera dados aluno
        printf("Num. Presenca: ");
        scanf("%d", &alunos[indice - 1].presenca); // altera os dados, nao a pessoa entao nao altera o ra

        if (alunos[indice-1].presenca > MAX_PRESENCA) { // limita a quantidade de presenças a 50
            alunos[indice-1].presenca = MAX_PRESENCA;   // se falarem que a nota é maior que 50...
        }
            //verifica status
    if ((alunos[indice-1].nota1 + alunos[indice -1].nota2) / 2 >= 6.0 && alunos[indice-1].presenca >= 37.5) { // > = a 75% de aulas de total de 50 = 38 aulas para passar.
            alunos[indice-1].status = 2;
        } else if ( (alunos[indice-1].nota1 + alunos[indice-1].nota2) / 2 >= 3.0 &&( alunos[indice-1].nota1 + alunos[indice-1].nota2) / 2 < 6.0 && alunos[indice-1].presenca >= 37.5) {
            alunos[indice-1].status = 1;
        } else if((alunos[indice-1].nota1 + alunos[indice-1].nota2) / 2 < 3.0 && alunos[indice-1].presenca <= 37.5){
            alunos[indice-1].status = 0;
        }

Gerenciar(alunos);

    }

void Incluir_aluno(lista *alunos){
    Limpar();

        if(LINHAS + inclu > 50){
                printf("%d",inclu);
            printf("\nArmazenamento cheio.\n"); // limita a 50 alunos incluidos
            Gerenciar(alunos);
        }
        printf("%d",inclu);
        printf("RA: ");
        scanf("%d", &alunos[LINHAS + inclu].ra);
        printf("Nota 1B: ");
        scanf("%f", &alunos[LINHAS + inclu].nota1); // coloca dados de novo aluno
        printf("Nota 2B: ");
        scanf("%f", &alunos[LINHAS + inclu].nota2);
        printf("Num. Presenca: ");
        scanf("%d", &alunos[LINHAS + inclu].presenca);

        if (alunos[LINHAS + inclu].presenca > MAX_PRESENCA) { // limita a quantidade de presenças a 50
            alunos[LINHAS + inclu].presenca = MAX_PRESENCA;
        }
            //verifica status
    if ((alunos[LINHAS + inclu].nota1 + alunos[LINHAS + inclu].nota2) / 2 >= 6.0 && alunos[LINHAS + inclu].presenca >= 37.5) { // > = a 75% de aulas de total de 50 = 38 aulas para passar.
            alunos[LINHAS + inclu].status = 2;
        } else if ( (alunos[LINHAS + inclu].nota1 + alunos[LINHAS + inclu].nota2) / 2 >= 3.0 &&( alunos[LINHAS + inclu].nota1 + alunos[LINHAS + inclu].nota2) / 2 < 6.0 && alunos[LINHAS + inclu].presenca >= 37.5) {
            alunos[LINHAS + inclu].status = 1;
        } else if((alunos[LINHAS + inclu].nota1 + alunos[LINHAS + inclu].nota2) / 2 < 3.0 && alunos[LINHAS + inclu].presenca <= 37.5){
            alunos[LINHAS + inclu].status = 0;
        }
        inclu++; // aumenta capacidade de aluno, e faz os for pra mostrar os alunos rodar + 1 pra que mostre o aluno incluido
        Gerenciar(alunos);    // quando checa o num de vez que vai rodar. ex: LINHAS + inclu

}

void Listar_reprovados(lista *alunos){
Limpar();
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n"); // mostra alunos reprovados
    for (int i = 0; i < LINHAS + inclu; i++) {
            if(alunos[i].status == 0){
                    if(alunos[i].nota1 == -1 && alunos[i].nota2 == -1 && alunos[i].presenca == -1 && alunos[i].status == -1){
               continue; } // nao imprime alunos excluidos
        printf("%d \t %.1f \t %.1f \t %d \t %d \n", alunos[i].ra, alunos[i].nota1,
                alunos[i].nota2, alunos[i].presenca, alunos[i].status); }
    }
        Gerenciar(alunos);
}

void Listar_recuperacao(lista *alunos){
Limpar();
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n"); // mostra alunos em rec
    for (int i = 0; i < LINHAS + inclu; i++) {
            if(alunos[i].status == 1){
                    if(alunos[i].nota1 == -1 && alunos[i].nota2 == -1 && alunos[i].presenca == -1 && alunos[i].status == -1){
               continue; } // nao imprime alunos excluidos
        printf("%d \t %.1f \t %.1f \t %d \t %d \n", alunos[i].ra, alunos[i].nota1,
                alunos[i].nota2, alunos[i].presenca, alunos[i].status); }
    }
        Gerenciar(alunos);
}

void Listar_aprovados(lista *alunos){
Limpar();
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n"); // mostra alunos aprovados
    for (int i = 0; i < LINHAS + inclu; i++) {
            if(alunos[i].status == 2){
                    if(alunos[i].nota1 == -1 && alunos[i].nota2 == -1 && alunos[i].presenca == -1 && alunos[i].status == -1){
               continue; } // nao imprime alunos excluidos
        printf("%d \t %.1f \t %.1f \t %d \t %d \n", alunos[i].ra, alunos[i].nota1,
                alunos[i].nota2, alunos[i].presenca, alunos[i].status); }
    }
        Gerenciar(alunos);
}

void Listar_alunos(lista *alunos){
Limpar();
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n"); // mostra alunos
    for (int i = 0; i < LINHAS + inclu ; i++) {
            if(alunos[i].nota1 == -1 && alunos[i].nota2 == -1 && alunos[i].presenca == -1 && alunos[i].status == -1){
               continue; } // nao imprime alunos excluidos
        printf("%d \t %.1f \t %.1f \t %d \t %d \n", alunos[i].ra, alunos[i].nota1,
                alunos[i].nota2, alunos[i].presenca, alunos[i].status);
    }
        Gerenciar(alunos);

}

void menu(lista *alunos){
    Limpar();

    int opcao_menu = 0; // opçao pra escolher menu
    printf("\n\t\t\tGerenciamento de Dados\n\t\t\t======================\n");
    printf("\n\t\t\t1. Listar todos os alunos.\n\n\t\t\t2. Listar os alunos aprovados.\n\n\t\t\t3. Listar os alunos em recuperacao.");
    printf("\n\n\t\t\t4. Listar os alunos reprovados.\n\n\t\t\t5. Incluir aluno.");
    printf("\n\n\t\t\t6. Alterar dados.\n\n\t\t\t7. Excluir aluno.\n\n\t\t\t8. Sair do programa.\n\t\t\t\t");
    scanf("%d",&opcao_menu);

    switch(opcao_menu){
        case 1:
            Listar_alunos(alunos); break;
        case 2:
            Listar_aprovados(alunos); break;
        case 3:
            Listar_recuperacao(alunos); break;
        case 4:
            Listar_reprovados(alunos); break;
        case 5:
            Incluir_aluno(alunos); break;
        case 6:
            alterar_aluno(alunos); break;
        case 7:
            excluir_aluno(alunos); break;
        case 8:
            exit(0); break;
        default:
            Limpar();
            printf("Opcao Invalida.\n");
            system("pause");
            menu(alunos);
    }

}

int main(){

        lista alunos[50]; // inicia a struct

        Limpar();

    for(int i=0;i<LINHAS;i++){
        printf("\nAluno %d\n", i+1); //coloca dados dos primeiros alunos
        printf("Digite o RA: ");
        scanf("%d", &alunos[i].ra);
        printf("Nota 1B: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2B: ");
        scanf("%f", &alunos[i].nota2);
        printf("Num. Presenca: ");
        scanf("%d", &alunos[i].presenca);

        if (alunos[i].presenca > MAX_PRESENCA) { // limita a quantidade de presenças a 50
            alunos[i].presenca = MAX_PRESENCA;
        }
            //verifica status
    if ((alunos[i].nota1 + alunos[i].nota2) / 2 >= 6.0 && alunos[i].presenca >= 37.5) { // > = a 75% de aulas de total de 50 = 38 aulas para passar.
            alunos[i].status = 2;
        } else if ( (alunos[i].nota1 + alunos[i].nota2) / 2 >= 3.0 &&( alunos[i].nota1 + alunos[i].nota2) / 2 < 6.0 && alunos[i].presenca >= 37.5) {
            alunos[i].status = 1;
        } else if((alunos[i].nota1 + alunos[i].nota2) / 2 < 3.0 && alunos[i].presenca <= 37.5){
            alunos[i].status = 0;
        }

    }
        Limpar();
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n"); // mostra alunos
    for (int i = 0; i < LINHAS; i++) {
        printf("%d \t %.1f \t %.1f \t %d \t %d \n", alunos[i].ra, alunos[i].nota1,
                alunos[i].nota2, alunos[i].presenca, alunos[i].status);
    }

    Gerenciar(alunos); // fecha programa ou vai pro Menu

    return 0;
}
