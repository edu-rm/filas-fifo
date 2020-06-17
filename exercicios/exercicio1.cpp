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
void relatorio(Estacionamento* est);

// Carro* buscaEstacionamento(Estacionamento* est, int placa);
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

    partida(est, espera, 4);
    partida(est, espera, 9);

    partida(est, espera, 10);
    partida(est, espera, 11);


    // partida(est, espera, 3);


    // partida(est, espera, 20);

    relatorio(est);
    imprimeEstacionamento(est);
    // imprimeEspera(espera);

    return 0;
}
Carro* novoCarro(int placa){
    Carro* car = (Carro*)malloc(sizeof(Carro));

    car->placa = placa;
    car->qtdDeslocamento = 0;

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
    printf("\n");
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


void partida(Estacionamento* est, Espera* espera, int placa ){
    Carro* carro;
    carro = est->front;
    bool estacionado =false;
    for(int i = 0; i < est->size; i++){
        printf("%d ", carro->placa);
        if(carro->placa == placa) {
            printf("\n\nO carro está no estacionamento\n\n");
            estacionado=true;
            break;
        }
        carro = carro->next;
    }


    if(estacionado){
        printf("\nEntrei\n");
        int flag = 0;
        Carro* aux ;
        aux = carro;

        if(est->front != aux && est->rear != aux){
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            
            Carro* salvaAux = aux;
            salvaAux->qtdDeslocamento++;

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
                est->front = aux->next;
                aux->next->prev = NULL;
                free(aux);
                flag = 1; 
            }
            if(est->rear == aux){
                aux->prev->next = NULL;
                est->rear = aux->prev;
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

    }else {
        bool esperando = false;
        Carro * carro2 ;
        carro2 = espera->front;
        for(int i = 0; i < espera->size; i++){
            // printf("%d ", carro->placa);
            if(carro2->placa == placa) {
                printf("\n\nO carro está esperando vaga\n\n");
                esperando=true;
                break;
            }
            carro2 = carro2->next;
        }

        if(esperando) {
            carro2->qtdDeslocamento++;
        }else {
            printf("\nO carro %d n existe\n", placa);
        }

    }

}

void relatorio(Estacionamento* est) {
    Carro* aux = est->front;

    for(int i = 0; i < est->size; i++){
        printf("\n\n");
        printf("\nCarro: %d\nDeslocamentos: %d\n\n", aux->placa, aux->qtdDeslocamento );
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

    // while(aux != NULL) {
        //     if(flag == 0) {
        //         if(est->rear != aux && est->front != aux){

        //         }else {
        //             if(est->front == aux){
        //                 aux->qtdDeslocamento++;
        //                 aux->next->prev = NULL;
        //                 est->front = aux->next;
        //                 // free(aux);

        //             }
        //             if (est->rear == aux){
        //                 aux->prev->next = NULL;
        //                 aux->qtdDeslocamento++;
        //                 Carro* salvaAux = aux;
        //                 est->rear = aux->prev;
        //             }
        //         }

        //         flag =1;
        //     }

        //     aux = aux->prev;
        // }
        //teste