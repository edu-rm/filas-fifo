typedef struct sEstacionamento{
  struct sElemento *front;
  struct sElemento *rear;
  int size;
} Estacionamento;

typedef struct sCarro{
  struct sCarro *next;
  struct sCarro *prev;
  int placa;
} Carro;

Estacionamento* criaEstacionamento();

void estacionarCarro(Estacionamento* est, int placa);
void verEstacionamento(Estacionamento* queue);

void liberarVaga(Estacionamento* est, Carro* carro );


int main (){

    






    return 0;
}


Estacionamento* criaEstacionamento(){
    Estacionamento *est = (Estacionamento*)malloc(sizeof(Estacionamento));

    est->front = NULL;
    est->rear = NULL;
    est->size = 0;
    return est;
}

