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
void insertLe(Queue* queue, Elemento* pivo);

// int remove(Queue* queue);




int main(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front->dado = 0;
    // Assim que eu inserir um elemento esse rear passa a ser 0
    queue->rear->dado = -1;


    // A quantidade de elemtos que possui um a fila é sempre: q->rear - q->front + 1

    // Considerar a possibilidade de fazer o deslocamento dos elementos do vetor
    // para o começo dele, isso quando o rear atingir 100 (objetivando evitar overflow)



    return 0;
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

void insertLe(Queue* queue, Elemento* pivo){
    // Para se inserir teria de receber o elemento pivo como tail

    if ( pivo != queu)
}


int remove(Queue* queue){
    int x = queue->items[queue->front++];

    printf("\nElemento %d removido com sucesso\n", x);
    return x;
}


