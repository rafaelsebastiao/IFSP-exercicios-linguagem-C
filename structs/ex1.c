#include <stdio.h>

//Quantidade de processos
#define NUMPROCESSOS 5

typedef struct processo{
    int numero;
    char dataAbertura[20];
    char nomeSolicitante[50];
    char nomeAdvgoado[50];


} Processo;

//Protótipo de função para leitura de processos
void leituraProcessos(Processo processo[], int indice);
//Protótipo de função para impressão de processos
void imprimeProcessos(Processo processo[], int n);


int main(){
    Processo processo[NUMPROCESSOS];

    for(int i = 0; i < NUMPROCESSOS; i++){
            leituraProcessos(processo, i+1);
    }

    imprimeProcessos(processo, NUMPROCESSOS-1);

    return 0;
}


//Implementação leitura de processos
void leituraProcessos(Processo processo[], int indice){
    printf("=====================");
    printf("\nPROCESSO %d\n", indice);
    printf("=====================\n\n");


    printf("Digite o numero do processo: ");
    scanf("%d", &processo[indice].numero);

    printf("Digite a data de abertura do processo: ");
    scanf("%s", processo[indice].dataAbertura);

    printf("Digite o nome do solicitante do processo: ");
    scanf("%s", &processo[indice].nomeSolicitante);

    printf("Digite o nome do advgado do solicitante: ");
    scanf("%s", processo[indice].nomeAdvgoado);



}

//Implementação da função recursiva que imprime um número n de processos
void imprimeProcessos(Processo processo[], int n){
    if(n == 0){
        printf("\n\nO processo de numero %d, aberto em %s, tem como solicitante %s representado por %s.\n", processo[n].numero, processo[n].dataAbertura, processo[n].nomeSolicitante, processo[0].nomeAdvgoado );
    }else{

        imprimeProcessos(processo, n-1);

        printf("O processo de numero %d, aberto em %s, tem como solicitante %s representado por %s.\n", processo[n].numero, processo[n].dataAbertura, processo[n].nomeSolicitante, processo[n].nomeAdvgoado);
        
    }
}