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
void insertLe(Queue* queue, int dado);
Queue* criaFila();
void imprime(Queue* queue);

void remove(Queue* queue);




int main(){
    Queue *queue = criaFila();

    insertLe(queue, 20);
    insertLe(queue, 30);
    insertLe(queue, 40);
    remove(queue);    
    remove(queue);
    remove(queue);
    remove(queue);
    remove(queue);


    imprime(queue);


    return 0;
}

Queue* criaFila()  {
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    Elemento* front = (Elemento*)malloc(sizeof(Elemento));

    Elemento* rear= (Elemento*)malloc(sizeof(Elemento));

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}

bool empty(Queue* queue) {
    // Vazia sempre: q->rear < q->front
    if( queue->rear < queue->front){
        return true;
    }
    return false;
}

void insert(Queue* queue, int dado){
    // Ignorando overflow ou underflow
    // queue->items[++quear->rear] = dado
}

void insertLe(Queue* queue, int dado){
    // Para se inserir teria de receber o elemento pivo como tail
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->dado = dado;

    if(queue->size == 0){
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

void remove(Queue* queue){
    if( queue->size == 0) {
        printf("\nA lista já está vazia\n");
    }else{
        if( queue->size == 1) {
            printf("\nElemento %d removido\n", queue->front->dado);
            free(queue->front);
        }else {
            Elemento* remover = (Elemento*)malloc(sizeof(Elemento));
            remover= queue->front;
            queue->front = queue->front->next;
            printf("\nElemento %d removido\n", remover->dado);
            free(remover);
        }
        queue->size--;
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



// int remove(Queue* queue){
//     int x = queue->items[queue->front++];

//     printf("\nElemento %d removido com sucesso\n", x);
//     return x;
// }



// Assim que eu inserir um elemento esse rear passa a ser 0


// A quantidade de elemtos que possui um a fila é sempre: q->rear - q->front + 1

// Considerar a possibilidade de fazer o deslocamento dos elementos do vetor
// para o começo dele, isso quando o rear atingir 100 (objetivando evitar overflow)