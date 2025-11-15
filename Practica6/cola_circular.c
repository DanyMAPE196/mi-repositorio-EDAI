#include <stdio.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int inicio;
    int final;
    int size;
} ColaCircular;

void inicializar(ColaCircular *c) {
    c -> inicio = 0;
    c -> final = 0;
    c -> size = 0;
    printf("Cola circular inicializada.\n");
}

int isEmpty(ColaCircular *c) {
    return c -> size == 0;
}

int isFull(ColaCircular *c) {
    return c -> size == MAX;
}

void enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("La cola esta llena. No se puede encolar.\n");
        return;
    }

    c -> datos[c -> final] = valor;
    c -> final = (c -> final + 1) % MAX;
    c -> size++;
}

int dequeue(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("La cola esta vacia. No se puede desencolar.\n");
        return -1;
    }

    int valor = c -> datos[c -> inicio];
    c -> inicio = (c -> inicio + 1) % MAX;
    c -> size--;

    return valor;
}

int peek(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("La cola esta vacia.\n");
        return -1;
    }
    return c -> datos[c -> inicio];
}

void printQueue(ColaCircular *c) {
    printf("Cola actual: ");
    int idx = c -> inicio;

    for (int i = 0; i < c -> size; i++) {
        printf("%d ", c -> datos[idx]);
        idx = (idx + 1) % MAX;
    }

    printf("\nIndices -> inicio: %d , final: %d , size: %d\n", c->inicio, c -> final, c -> size);
}

int main() {

    ColaCircular c;
    inicializar(&c);

    printf("\n--- Prueba 1 ---\n");
    enqueue(&c, 5);
    enqueue(&c, 10);
    enqueue(&c, 15);
    printQueue(&c);

    printf("\n--- Prueba 2 ---\n"); 
    dequeue(&c);
    printQueue(&c);

    printf("\n--- Prueba 3 ---\n");
    enqueue(&c, 20);
    enqueue(&c, 25);
    enqueue(&c, 30);
    printQueue(&c);

    return 0;
}