#include <stdio.h>

#define MAX 10


typedef struct {
    int datos[MAX];
    int front;
    int size;
} Deque;


int isEmpty(Deque *dq) {
    return dq -> size == 0;
}

int isFull(Deque *dq) {
    return dq -> size == MAX;
}

int getRearIndex(Deque *dq) {
    return (dq -> front + dq -> size - 1) % MAX;
}


void insert_front(Deque *dq, int valor) {
    if (isFull(dq)) {
        printf("ERROR: Deque lleno, no se puede insertar por el frente.\n");
        return;
    }

    dq -> front = (dq -> front - 1 + MAX) % MAX;
    dq -> datos[dq -> front] = valor;
    dq -> size++;
    printf("Insertado %d por el frente.\n", valor);
}

void insert_rear(Deque *dq, int valor) {
    if (isFull(dq)) {
        printf("ERROR: Deque lleno, no se puede insertar por el final.\n");
        return;
    }

    int rear = getRearIndex(dq);
    rear = (rear + 1) % MAX;

    dq -> datos[rear] = valor;
    dq -> size++;
    printf("Insertado %d por el final.\n", valor);
}

int delete_front(Deque *dq) {
    if (isEmpty(dq)) {
        printf("ERROR: Deque vacío, no se puede eliminar por el frente.\n");
        return -1;
    }

    int valor = dq -> datos[dq -> front];
    dq -> front = (dq -> front + 1) % MAX;
    dq -> size--;

    printf("Eliminado %d por el frente.\n", valor);
    return valor;
}

int delete_rear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("ERROR: Deque vacío, no se puede eliminar por el final.\n");
        return -1;
    }

    int rear = getRearIndex(dq);
    int valor = dq -> datos[rear];

    dq -> size--;
    printf("Eliminado %d por el final.\n", valor);
    return valor;
}

int peek_front(Deque *dq) {
    if (isEmpty(dq)) return -1;
    return dq -> datos[dq -> front];
}

int peek_rear(Deque *dq) {
    if (isEmpty(dq)) return -1;
    return dq->datos[getRearIndex(dq)];
}

void printDeque(Deque *dq) {
    printf("Deque (front=%d, size=%d): ", dq -> front, dq -> size);

    if (isEmpty(dq)) {
        printf("[vacio]\n");
        return;
    }

    int idx = dq -> front;
    for (int i = 0; i < dq -> size; i++) {
        printf("%d ", dq -> datos[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}


int main() {
    Deque dq;
    dq.front = 0;
    dq.size = 0;

    printf("Deque inicializado.\n");

    
    insert_front(&dq, 10);
    insert_rear(&dq, 15);
    insert_rear(&dq, 20);
    insert_front(&dq, 30);
    insert_rear(&dq, 40);

    printDeque(&dq);

    delete_front(&dq);
    delete_rear(&dq);

    printDeque(&dq);

    insert_front(&dq, 99);
    insert_rear(&dq, 77);

    printDeque(&dq);

    return 0;
}