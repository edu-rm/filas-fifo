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