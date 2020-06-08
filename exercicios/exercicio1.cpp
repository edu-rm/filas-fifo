#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



typedef struct sEstacionamento{
  struct sCarro *front;
  struct sCarro *rear;
  int size;
} Estacionamento;

typedef struct sCarro{
  struct sCarro *next;
  struct sCarro *prev;
  int placa;
  int qtdDeslocamento;
} Carro;

Estacionamento* criaEstacionamento();

void adicionarCarroEstacionamento(Estacionamento* est, Carro* carro );
void verEstacionamento(Estacionamento* queue);

void liberarVaga(Estacionamento* est, Carro* carro );
Carro* novoCarro(int placa);

int main (){
    Estacionamento* est = criaEstacionamento();
    int flag = 0;
    int placa;
    int cp ; //futura C ou P, aqui C = 0 e p = 1
    for(int i = 0 ; i < 11 ; i++) {
        placa = i;
        cp = 0;
        
        Carro* carro =novoCarro(placa);
        if(cp == 0){
            adicionarCarroEstacionamento(est, carro);
        }
    }







    // while(flag==0){
    //     char acao;

    //     int placa;
    //     printf("\nc = chegada | p = partida\n");
    //     scanf("%c", &acao);
    //     printf("\nDigite a placa\n");

    //     scanf("%d", &placa);

    //     chegada(est, placa);

    //     int flag = 0;
    // }
    return 0;
}
Carro* novoCarro(int placa){
    Carro* car = (Carro*)malloc(sizeof(Carro));

    car->placa = placa;
    car->qtdDeslocamento = 1;

    printf("\nCarro %d criado\n", car->placa);
    return car;
}


Estacionamento* criaEstacionamento(){
    Estacionamento *est = (Estacionamento*)malloc(sizeof(Estacionamento));

    est->front = NULL;
    est->rear = NULL;
    est->size = 0;
    return est;
}

void adicionarCarroEstacionamento(Estacionamento *est, Carro* carro){
    // Para se inserir teria de receber o elemento pivo como tail


    if(est->size <= 10) {
        printf("Exite vagas disponiveis ");


        if(est->size == 0){
            est->front = carro;
            est->rear = carro;
            printf("\nEle foi estacionado na posição 1\n");
        }else{
            if (est->size == 1){
                carro->prev = est->front;
                est->front->next = carro;
                carro->next = NULL;
                est->rear = carro;
                printf("\nEle foi estacionado na posição 2\n");
            }else {
                carro->prev = est->rear;
                carro->next = NULL;
                est->rear->next =carro;
                est->rear = carro;
                printf("\nEle foi estacionado na posição %d\n", est->size);

            }
         } 
    }else {
        printf("não existem vagas");
    }

    

    est->size++;
}
