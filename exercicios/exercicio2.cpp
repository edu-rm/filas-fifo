#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 100


// Lista encadeada

typedef struct sQueue{
  struct sElemento *front;
  struct sElemento *rear;
  int size;
} Queue;

typedef struct sElemento{
  struct sElemento *next;
  struct sElemento *prev;
  int dado;
} Elemento;


// typedef struct sQueue {
//     int items[MAXQUEUE];
//     int front, rear;
// } Queue;

// bool empty(Queue* queue);
// int size(Queue* queue);
// void insert(Queue* queue, int dado);
void pqinsert(Queue* queue, int dado);
Queue* criaFila();
void imprime(Queue* queue);

void pqmindelete(Queue* queue);




int main(){
    Queue *queue = criaFila();

    pqinsert(queue, 10);
    pqinsert(queue, 30);
    pqinsert(queue, 2);

    pqmindelete(queue);    
    // pqmindelete(queue);
    // pqmindelete(queue);
    // pqmindelete(queue);
    // pqmindelete(queue);


    imprime(queue);


    return 0;
}

Queue* criaFila()  {
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

bool empty(Queue* queue) {
    // Vazia sempre: q->rear < q->front
    if( queue->size == 0){
        return true;
    }
    return false;
}

void pqinsert(Queue* queue, int dado){
    // Para se inserir teria de receber o elemento pivo como tail
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->dado = dado;

    if(empty(queue)){
        queue->front = novo;
        queue->rear = novo;
    }else{
        if (queue->size == 1){
            novo->prev = queue->front;
            queue->front->next = novo;
            novo->next = NULL;
            queue->rear = novo;
        }else {
            novo->prev = queue->rear;
            novo->next = NULL;
            queue->rear->next =novo;
            queue->rear = novo;
        }
    } 

    queue->size++;
}

void pqmindelete(Queue* queue){
    if( empty(queue) ) {
        printf("\nA lista já está vazia\n");
    }else{
        Elemento* aux = queue->front;
        Elemento* paraRemover;
        int menor = 99999;
        for(int i = 0; i < queue->size; i++){
            if(aux->dado< menor){
                menor = aux->dado;
                paraRemover = aux;
            }
            aux = aux->next;
        }
        printf("aqui");
        if(paraRemover != queue->front && paraRemover != queue->rear){
            paraRemover->prev->next = paraRemover->next;
            paraRemover->next->prev = paraRemover->prev;

        }else {
            if(paraRemover == queue->front ){
                queue->front = paraRemover->next;
                paraRemover->next->prev = NULL;
            }

            if(paraRemover == queue->rear){
                queue->rear = paraRemover->prev;
                paraRemover->prev->next = NULL;
            }
        }
        
        
        
        queue->size--;
        printf("\n\nElemento %d vai ser removido\n\n", paraRemover->dado);
        free(paraRemover);   
    }   

}


void imprime(Queue* queue){
    Elemento* aux = (Elemento*)malloc(sizeof(Elemento));
    aux = queue->front;

    for(int i = 0; i < queue->size; i++){
        printf("\n%d\n", aux->dado);
        aux = aux->next;
    }
}
