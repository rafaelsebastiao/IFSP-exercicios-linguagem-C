/*
Escreva um programa em linguagem C que irá ler os dados de dois carro, sendo a placa (até 8 caracteres), a distância percorrida (em quilômetros) e o tempo (em horas) realizado, e, em seguida, informe qual o carro teve maior velocidade média. Para isso, você deve definir a estrutura carro (incluindo uma variável para a velocidade média do carro), e escrever três rotinas:

a) lerCarro que irá ler os dados de um carro (placa, distância e tempo);  

b) calcularVelocidade que receba um parâmetro do tipo da estrutura carro e retorne o valor da velocidade média (velocidade média é igual a distância dividida pelo tempo).

c)   verificarMaiorVelocidade que receba dois parâmetros do tipo estrutura carro e escreva na tela a placa do carro de maior velocidade.

Assim, a função main deve chamar as rotinas acima para dizer ao usuário fornecer dados de dois carros e dizer qual foi o mais rápido.

*/

#include <stdio.h>

typedef struct carro{
    char placa[8];
    float distancia;
    int tempo;
    float velocMedia;

}Carro;


void lerCarro(Carro *carro);
float calcularVelocidade(Carro carro);
void verificarMaiorVelocidade(Carro c1, Carro c2);



int main(){
    Carro c1, c2;

    lerCarro(&c1);
    lerCarro(&c2);

    c1.velocMedia = calcularVelocidade(c1);
    c2.velocMedia = calcularVelocidade(c2);

    verificarMaiorVelocidade(c1, c2);

    return 0;
}



void lerCarro(Carro *carro){
    printf("Informe a placa do carro: ");
    scanf("%s", carro->placa);
    
    printf("Informe a distancia percorrida pelo carro (km): ");
    scanf("%f", &carro->distancia);

    printf("Informe o tempo que o carro demorou para percorrer (h): ");
    scanf("%d", &carro->tempo);
    
}

float calcularVelocidade(Carro carro){
    float velocMedia = carro.distancia / carro.tempo;

    return velocMedia;
}

void verificarMaiorVelocidade(Carro c1, Carro c2){
    if(c1.velocMedia > c2.velocMedia)
        printf("O carro placa %s e o mais rapido!", c1.placa);
    else if(c2.velocMedia > c1.velocMedia)
        printf("O carro placa %s e o mais rapido!", c2.placa);
    else
        printf("Ambos os carros possuem a mesma velocidade!");
}
