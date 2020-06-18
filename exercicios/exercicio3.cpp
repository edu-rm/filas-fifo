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
    pqmindelete(queue);
    // pqmindelete(queue);
    // pqmindelete(queue);
    // pqmindelete(queue);


    imprime(queue);


    return 0;
}

Queue* criaFila()  {
    // Aloca a memória pra fila
    Queue *queue = (Queue*)malloc(sizeof(Queue));

    //atribui os valores padrões pra ela e a retorna
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    return queue;
}


// Verifica se ela está vazia, nesse caso usando o size 
// Mas na teoria a forma correta é vendo se o rear < front
bool empty(Queue* queue) {
    if( queue->size == 0){
        return true;
    }
    return false;
}

void pqinsert(Queue* queue, int dado){
    // Para se inserir teria de receber o elemento pivo como tail
    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));
    novo->dado = dado;

    // verifica se está vazia
    if(empty(queue)){
        // Se vazia o front e o rear serão o mesmo elemento
        queue->front = novo;
        queue->rear = novo;
    }else{
        // Se o tamanho dela é 1 então coloca ela como front e o existente como rear
        if (queue->size == 1){
            novo->prev = queue->front;
            queue->front->next = novo;
            novo->next = NULL;
            queue->rear = novo;
        }else {
            // Se ela tiver mais de um elemento o coloca com rear
            novo->prev = queue->rear;
            novo->next = NULL;
            queue->rear->next =novo;
            queue->rear = novo;
        }
    } 

    queue->size++;
}

// Função que eliminará o menor elemento da lista.

void pqmindelete(Queue* queue){
    if( empty(queue) ) {
        printf("\nA lista já está vazia\n");
    }else{
        Elemento* aux = queue->front;
        Elemento* paraRemover;
        int menor = 99999;
        // Varifica qual elemento é o que possui o menor valor
        for(int i = 0; i < queue->size; i++){
            if(aux->dado< menor){
                menor = aux->dado;
                paraRemover = aux;
            }
            aux = aux->next;
        }
        //Removendo se ele não for o front e nem o rear 
        if(paraRemover != queue->front && paraRemover != queue->rear){
            // Junta o próximo com o anterior
            paraRemover->prev->next = paraRemover->next;
            paraRemover->next->prev = paraRemover->prev;

        }else {
            if(paraRemover == queue->front ){
                // Se for o front o Next dele assumirá seu lugar
                queue->front = paraRemover->next;
                paraRemover->next->prev = NULL;
            }
            if(paraRemover == queue->rear){
                // Se for o rear o anterior assumirá a posição do rear
                queue->rear = paraRemover->prev;
                paraRemover->prev->next = NULL;
            }
        }
        
        
        // Diminui o tamanho da fila
        queue->size--;
        printf("\n\nElemento %d foi removido\n\n", paraRemover->dado);
        // libera o espaço da memória destinado a armazenar o elemento que foi solicitado a remoção
        free(paraRemover);   
    }   

}


void imprime(Queue* queue){
    Elemento* aux = (Elemento*)malloc(sizeof(Elemento));
    aux = queue->front;
    // parte do primeiro até o último
    for(int i = 0; i < queue->size; i++){
        printf("\n%d\n", aux->dado);
        aux = aux->next;
    }
}
