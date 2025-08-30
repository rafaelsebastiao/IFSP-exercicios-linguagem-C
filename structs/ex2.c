/*Elabore um programa em linguagem C que represente um conjunto de notas de atividades por meio de estruturas e que possuem as informações: nome do aluno, primeira nota, segunda nota, terceira nota, quarta nota, resultado final.

O seu programa deve conter uma função para a leitura dos dados de notas de atividade e outra função que imprima a seguinte informação sobre as notas:

"O aluno NNNNN, com notas:

Atividade 1                 NN.NN

Atividade 2                 NN.NN

Atividade 3                 NN.NN

Atividade 4                 NN.NN

e resultado RR.RR"


A função main deverá solicitar a leitura dos dados das notas e, em seguida, escrever os dados das notas na tela do usuário.*/


#include <stdio.h>
#include <stdlib.h>

struct aluno{
    char nome[20];

    float notas[4];
    float resultadoFinal;


};
typedef struct aluno Aluno;


void leituraDados(Aluno alunos[], int n);
void imprimeResultAluno(Aluno alunos[], int n);



int main(){
    int quantAlunos;
    Aluno * alunos = NULL;

    printf("Informe a quantidade de alunos: ");
    scanf("%d", &quantAlunos);

    alunos = malloc(quantAlunos*sizeof(Aluno));

    printf("\n\n");

    leituraDados(alunos, quantAlunos);

    imprimeResultAluno(alunos, quantAlunos-1);


    return 0;
}

void leituraDados(Aluno alunos[], int n){
    int i = 0;

    for(int i = 0; i < n; i++){
        printf("Digite o nome do %d aluno: ", i+1);
        scanf("%s", alunos[i].nome);

        for(int j = 0; j < 4; j++){
            printf("Digite a %d nota do %d aluno: ", j+1, i+1);
            scanf("%f", &alunos[i].notas[j]);

            alunos[i].resultadoFinal += alunos[i].notas[j];
        }

        alunos[i].resultadoFinal /= 4;
        printf("\n\n");
    }

}

void imprimeResultAluno(Aluno alunos[], int n){
    if(n == 0){
        printf("\n\nO aluno %s, com notas:\n", alunos[0].nome);
        
        printf("Atividade 1\t%.2f\n", alunos[0].notas[0]);
        printf("Atividade 2\t%.2f\n", alunos[0].notas[1]);
        printf("Atividade 3\t%.2f\n", alunos[0].notas[2]);
        printf("Atividade 4\t%.2f\n", alunos[0].notas[3]);
       
        printf("e resultado %.2f", alunos[0].resultadoFinal);

    }else{
        imprimeResultAluno(alunos, n-1);

        printf("\n\nO aluno %s, com notas:\n", alunos[n].nome);
        
        printf("Atividade 1\t%.2f\n", alunos[n].notas[0]);
        printf("Atividade 2\t%.2f\n", alunos[n].notas[1]);
        printf("Atividade 3\t%.2f\n", alunos[n].notas[2]);
        printf("Atividade 4\t%.2f\n", alunos[n].notas[3]);
       
        printf("e resultado %.2f", alunos[n].resultadoFinal);
    }

}