#include <stdio.h>
#include <stdlib.h>
#define LINHAS 10
#define MAX_PRESENCA 50

void Limpar(){ // limpa a tela msm se for pc linux/windows
#ifdef __linux__
    system("clear");
#elif _WIN32
    system("cls");
#endif
}

struct lista
{
   int ra;
   int presenca;
   float nota1;
   float nota2;
   int status;
}lista;

void Gerenciar(struct lista alunos[], int *quantAlunos){
                    // sai do programa ou gerencia
    int a = 0;
    printf("\nSair( 0 )  |  Gerenciar ( 1 )\n\t   ");
    scanf("%d",&a);
    switch(a){
    case 0:
        exit(0);
    case 1:
        menu(alunos, &*quantAlunos);
        }

}

void excluir_aluno(struct lista alunos[], int *quantAlunos){
    Limpar();

    printf("Selecione o aluno para excluir.\n");
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n");
    for (int i = 0; i < *quantAlunos; i++) {
        printf("%d\t%.1f\t%.1f\t%d\t%d\tAluno:%d\n", alunos[i].ra , alunos[i].nota1, alunos[i].nota2,
                alunos[i].presenca,alunos[i].status,i+1);
    }

    int indice = 0;
    printf("\nDigite o numero do aluno a ser excluido: ");
    scanf("%d", &indice);

    if (indice <= 0 || indice > *quantAlunos) {
        excluir_aluno(alunos, quantAlunos);
    }

    // Troca o aluno selecionado com o último da lista
    struct lista temp = alunos[indice-1]; // temp é uma var. temporaria so pra fazer a troca
    alunos[indice-1] = alunos[*quantAlunos-1];
    alunos[*quantAlunos-1] = temp;

    // Remove o último aluno da lista
    *quantAlunos -= 1;

    Gerenciar(alunos, &*quantAlunos);
}


void alterar_aluno(struct lista alunos[], int *quantAlunos){
    Limpar();

    printf("Selcione o aluno para alterar.\n");
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n");
    for (int i = 0; i < *quantAlunos; i++) { //roda o num de linhas se inclui for 0, quando inclu aluno roda + 1 vez pra mostrar o aluno incluido

        printf("%d\t%.1f\t%.1f\t%d\t%d\tAluno:%d\n", alunos[i].ra , alunos[i].nota1, alunos[i].nota2,
                alunos[i].presenca,alunos[i].status,i+1);
    }

    int indice =0;

    printf("\nAlterar aluno: "); // escolhe qual aluno alterar
    scanf("%d",&indice);

    if(indice > *quantAlunos|| indice == 0){ // nao altera alunos que nao existem
            alterar_aluno(alunos, &*quantAlunos);
        }

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

Gerenciar(alunos, &*quantAlunos);

    }

void Incluir_aluno(struct lista alunos[], int *quantAlunos){
    Limpar();

        if(*quantAlunos > LINHAS){
            printf("\nArmazenamento cheio.\n"); // limita a 50 alunos incluidos
            Gerenciar(alunos, &*quantAlunos);
        }
        printf("RA: ");
        scanf("%d", &alunos[*quantAlunos].ra);
        printf("Nota 1B: ");
        scanf("%f", &alunos[*quantAlunos].nota1); // coloca dados de novo aluno
        printf("Nota 2B: ");
        scanf("%f", &alunos[*quantAlunos].nota2);
        printf("Num. Presenca: ");
        scanf("%d", &alunos[*quantAlunos].presenca);

        if (alunos[*quantAlunos].presenca > MAX_PRESENCA) { // limita a quantidade de presenças a 50
            alunos[*quantAlunos].presenca = MAX_PRESENCA;
        }
            //verifica status
    if ((alunos[*quantAlunos].nota1 + alunos[*quantAlunos].nota2) / 2 >= 6.0 && alunos[*quantAlunos].presenca >= 37.5) { // > = a 75% de aulas de total de 50 = 38 aulas para passar.
            alunos[*quantAlunos].status = 2;
        } else if ( (alunos[*quantAlunos].nota1 + alunos[*quantAlunos].nota2) / 2 >= 3.0 &&( alunos[*quantAlunos].nota1 + alunos[*quantAlunos].nota2) / 2 < 6.0 && alunos[*quantAlunos].presenca >= 37.5) {
            alunos[*quantAlunos].status = 1;
        } else if((alunos[*quantAlunos].nota1 + alunos[*quantAlunos].nota2) / 2 < 3.0 && alunos[*quantAlunos].presenca <= 37.5){
            alunos[*quantAlunos].status = 0;
        }

        *quantAlunos+=1; // aumenta capacidade de aluno, e faz os for pra mostrar os alunos rodar + 1 pra que mostre o aluno incluido
        Gerenciar(alunos, &*quantAlunos);    // quando checa o num de vez que vai rodar. ex: LINHAS + inclu

}

void Listar_reprovados(struct lista alunos[], int *quantAlunos){
Limpar();
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n"); // mostra alunos reprovados
    for (int i = 0; i < *quantAlunos; i++) {
            if(alunos[i].status == 0){

        printf("%d \t %.1f \t %.1f \t %d \t %d \n", alunos[i].ra, alunos[i].nota1,
                alunos[i].nota2, alunos[i].presenca, alunos[i].status); }
    }
        Gerenciar(alunos, &*quantAlunos);
}

void Listar_recuperacao(struct lista alunos[], int *quantAlunos){
Limpar();
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n"); // mostra alunos em rec
    for (int i = 0; i < *quantAlunos; i++) {
            if(alunos[i].status == 1){

        printf("%d \t %.1f \t %.1f \t %d \t %d \n", alunos[i].ra, alunos[i].nota1,
                alunos[i].nota2, alunos[i].presenca, alunos[i].status); }
    }
        Gerenciar(alunos, &*quantAlunos);
}

void Listar_aprovados(struct lista alunos[], int *quantAlunos){
Limpar();
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n"); // mostra alunos aprovados
    for (int i = 0; i < *quantAlunos; i++) {
            if(alunos[i].status == 2){

        printf("%d \t %.1f \t %.1f \t %d \t %d \n", alunos[i].ra, alunos[i].nota1,
                alunos[i].nota2, alunos[i].presenca, alunos[i].status); }
    }
        Gerenciar(alunos, &*quantAlunos);
}

void Listar_alunos(struct lista alunos[], int *quantAlunos){
Limpar();
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n"); // mostra alunos
    for (int i = 0; i < *quantAlunos; i++) {

        printf("%d \t %.1f \t %.1f \t %d \t %d \n", alunos[i].ra, alunos[i].nota1,
                alunos[i].nota2, alunos[i].presenca, alunos[i].status);
    }
        Gerenciar(alunos, &*quantAlunos);

}

void menu(struct lista alunos[], int *quantAlunos){
    Limpar();

    int opcao_menu = 0; // opçao pra escolher menu
    printf("\n\t\t\tGerenciamento de Dados\n\t\t\t======================\n");
    printf("\n\t\t\t1. Listar todos os alunos.\n\n\t\t\t2. Listar os alunos aprovados.\n\n\t\t\t3. Listar os alunos em recuperacao.");
    printf("\n\n\t\t\t4. Listar os alunos reprovados.\n\n\t\t\t5. Incluir aluno.");
    printf("\n\n\t\t\t6. Alterar dados.\n\n\t\t\t7. Excluir aluno.\n\n\t\t\t8. Sair do programa.\n\t\t\t\t");
    scanf("%d",&opcao_menu);

    switch(opcao_menu){
        case 1:
            Listar_alunos(alunos, &*quantAlunos); break;
        case 2:
            Listar_aprovados(alunos, &*quantAlunos); break;
        case 3:
            Listar_recuperacao(alunos, &*quantAlunos); break;
        case 4:
            Listar_reprovados(alunos, &*quantAlunos); break;
        case 5:
            Incluir_aluno(alunos, &*quantAlunos); break;
        case 6:
            alterar_aluno(alunos, &*quantAlunos); break;
        case 7:
            excluir_aluno(alunos, &*quantAlunos); break;
        case 8:
            exit(0); break;
        default:
            Limpar();
            printf("Opcao Invalida.\n");
            system("pause");
            menu(alunos, &*quantAlunos);
    }

}

int main(){

        struct lista alunos[LINHAS]; // inicia a struct
        int quantAlunos;

        Limpar();

    for(int i=0;i<3;i++){
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
        quantAlunos+=1;
    }
        Limpar();
    printf("Numero\tNota 1\tNota 2\tPres.\tStatus\n"); // mostra alunos
    for (int i = 0; i < quantAlunos; i++) {
        printf("%d \t %.1f \t %.1f \t %d \t %d \n", alunos[i].ra, alunos[i].nota1,
                alunos[i].nota2, alunos[i].presenca, alunos[i].status);
    }

    Gerenciar(alunos, &quantAlunos); // fecha programa ou vai pro Menu

    return 0;
}
