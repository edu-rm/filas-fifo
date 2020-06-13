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
Carro* novoCarro(int placa);

void imprimeEstacionamento(Estacionamento* est);
void imprimeEspera(Espera* espera);


void adicionarCarroEstacionamento(Estacionamento* est, Carro* carro, Espera* espera );
void adicionarCarroEspera(Espera *espera, Carro* carro);
void verEstacionamento(Estacionamento* queue);

void partida(Estacionamento* est, Espera* espera, int placa );

Carro* buscaEstacionamento(Estacionamento* est, int placa);
// bool buscaEspera(Espera* espera, int placa);

int main (){
    Estacionamento* est = criaEstacionamento();
    Espera* espera = criaEspera();

    int flag = 0;
    int placa;
    int placateste = 0 ;
    int cp ; 
    //futura C ou P, aqui C = 0 e p = 1
    cp = 0;
    // for(int i = 0 ; i <= 11 ; i++) {
    //     placa = i;
        
        
    //     if(cp == 0){
    //         Carro* carro =novoCarro(placa);
    //         adicionarCarroEstacionamento(est, carro, espera);
    //     }else{
    //         partida(est,espera, placateste);
    //     }
    //     if( i == 6) {
    //         cp = 1;
    //         placateste = 6;
    //     }
    // }
    Carro* carro = novoCarro(1);
    adicionarCarroEstacionamento(est, carro, espera );

    carro = novoCarro(2);
    adicionarCarroEstacionamento(est, carro, espera );

    carro = novoCarro(3);
    adicionarCarroEstacionamento(est, carro, espera );

    carro = novoCarro(4);
    adicionarCarroEstacionamento(est, carro, espera );

    imprimeEstacionamento(est);

    partida(est, espera, 3);
    partida(est, espera, 2);


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
    printf("\nESTACIONAMENTO: ");
    for(int i = 0; i < est->size; i++){
        printf(" %d -> ", aux->placa);
        aux = aux->next;
    }
}

void imprimeEspera(Espera* espera){
    Carro* aux = (Carro*)malloc(sizeof(Carro));
    aux = espera->front;
    printf("\nESPERA: ");
    for(int i = 0; i < espera->size; i++){
        printf(" %d -> ", aux->placa);
        aux = aux->next;
    }
}

// Carro* buscaEstacionamento(Estacionamento* est, int placa){
//     Carro* aux;
//     aux = est->front;

//     for(int i = 0; i < est->size; i++){
//         if(aux->placa == placa) {
//             printf("\n\nO carro está no estacionamento\n\n");
//             return aux;
//         }
//         aux = aux->next;
//     }
//     return NULL;
// }

void partida(Estacionamento* est, Espera* espera, int placa ){
    Carro* carro;
    carro = est->front;
    bool estacionado;
    for(int i = 0; i < est->size; i++){
        if(carro->placa == placa) {
            printf("\n\nO carro está no estacionamento\n\n");
            estacionado=true;
            break;
        }
        carro = carro->next;
    }


    if(estacionado){
        printf("Entrei");
        int flag = 0;
        Carro* aux = 
        aux = est->front;

        while(flag == 0){
            if(aux == carro) {
                if(est->front != aux && est->rear != aux){
                    aux->prev->next = aux->next;
                    aux->next->prev = aux->prev;
                    Carro* salvaAux = aux;
                    aux = aux->prev;
                    while(aux != NULL) {
                        aux->qtdDeslocamento++;
                        aux = aux->prev;
                    }
                    free(salvaAux);
                    flag = 1;
                }else{
                    if(est->front == aux){
                        aux->qtdDeslocamento++;
                        aux->prev->next = NULL;
                        free(aux);
                        flag = 1; 
                    }
                    if(est->rear == aux){
                        aux->prev->next = NULL;
                        Carro* salvaAux = aux;
                        

                        while(aux != NULL) {
                            aux->qtdDeslocamento++;
                            aux = aux->prev;
                        }

                        free(salvaAux);
                        flag = 1;
                    }
                }
                est->size--;
            }else{
                aux = aux->next;
            }
        }
    }else {
        // contar um na quantidade de desolcamento 
        carro->qtdDeslocamento++;
        printf("Entrei aqui");

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