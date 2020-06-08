#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct sEspera{
  struct sCarro *front;
  struct sCarro *rear;
  int size;
} Espera;

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
Espera* criaEspera();

void imprimeEstacionamento(Estacionamento* est);
void imprimeEspera(Espera* espera);


void adicionarCarroEstacionamento(Estacionamento* est, Carro* carro, Espera* espera );
void adicionarCarroEspera(Espera *espera, Carro* carro);
void verEstacionamento(Estacionamento* queue);

void liberarVaga(Estacionamento* est, Carro* carro );
Carro* novoCarro(int placa);

int main (){
    Estacionamento* est = criaEstacionamento();
    Espera* espera = criaEspera();

    int flag = 0;
    int placa;
    int cp ; //futura C ou P, aqui C = 0 e p = 1
    for(int i = 0 ; i <= 11 ; i++) {
        placa = i;
        cp = 0;
        
        Carro* carro =novoCarro(placa);
        if(cp == 0){
            adicionarCarroEstacionamento(est, carro, espera);
        }
    }

    imprimeEstacionamento(est);
    imprimeEspera(espera);

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

Espera* criaEspera(){
    Espera *esp = (Espera*)malloc(sizeof(Espera));

    esp->front = NULL;
    esp->rear = NULL;
    esp->size = 0;
    return esp;
}

void adicionarCarroEstacionamento(Estacionamento *est, Carro* carro, Espera* espera){
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
        est->size++;

    }else {
        printf("\nNão existem vagas, ele será colocado na lista de espera\n");
        adicionarCarroEspera(espera, carro);

    }

    

}

void adicionarCarroEspera(Espera *espera, Carro* carro){

    if(espera->size == 0){
            espera->front = carro;
            espera->rear = carro;
            printf("\nEle está na lista de espera, posição 1\n");
        }else{
            if (espera->size == 1){
                carro->prev = espera->front;
                espera->front->next = carro;
                carro->next = NULL;
                espera->rear = carro;
                printf("\nEle está na lista de espera, posição 2\n");
            }else {
                carro->prev = espera->rear;
                carro->next = NULL;
                espera->rear->next =carro;
                espera->rear = carro;
                printf("\nEle está na lista de espera, posição %d\n", espera->size+1);

            }
         }
    espera->size++; 
}

void imprimeEstacionamento(Estacionamento* est){
    Carro* aux = (Carro*)malloc(sizeof(Carro));
    aux = est->front;
    printf("\nCarros no estacionamento %d\n", est->size);
    for(int i = 0; i < est->size; i++){
        printf(" %d ", aux->placa);
        aux = aux->next;
    }
}
void imprimeEspera(Espera* espera){
    Carro* aux = (Carro*)malloc(sizeof(Carro));
    aux = espera->front;
    printf("\nCarros na espera\n");

    for(int i = 0; i < espera->size; i++){
        printf(" %d ", aux->placa);
        aux = aux->next;
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