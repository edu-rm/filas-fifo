#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 100

typedef struct sQueue {
    int items[MAXQUEUE];
    int front, rear;
} Queue;

bool empty(Queue* queue);

int main(){
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    // Assim que eu inserir um elemento esse rear passa a ser 0
    queue->rear = -1;






    return 0;
}

bool empty(Queue* queue) {
    // Vazia sempre: q->rear < q->front
    if( queue->rear < queue->front){
        return true;
    }
    return false;
}
