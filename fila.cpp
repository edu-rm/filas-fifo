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

// int remove(Queue* queue);




int main(){
    Queue *queue = criaFila();

    insertLe(queue, 20);
    insertLe(queue, 30);
    insertLe(queue, 40);


    return 0;
}

Queue* criaFila()  {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    Elemento* front = (Elemento*)malloc(sizeof(Elemento));
    front->dado = 0;
    Elemento* rear= (Elemento*)malloc(sizeof(Elemento));
    front->dado = -1;
    queue->front = front;
    queue->rear = rear;
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
    novo->prev = queue->rear;
    novo->next = NULL;

    queue->rear = novo;
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