#define MAXQUEUE 100

typedef struct sQueue {
    int items[MAXQUEUE];
    int front, rear;
} Queue;