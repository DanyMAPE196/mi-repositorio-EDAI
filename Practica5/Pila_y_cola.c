#include <stdio.h>
#define MAX 5

typedef struct 
{
    int datos[MAX];
    int tope;
} Pila;

void inicializarPila(Pila *p)
{
    p -> tope = -1;
    printf("Pila inicializada vacia.\n");
}

int pilaVacia(Pila *p)
{
    return p -> tope == -1;
}

int pilaLlena(Pila *p)
{
    return p -> tope == MAX - 1;
}

void push(Pila *p, int valor)
{
    if(pilaLlena(p))
    {
        printf("La pila esta llena. No se puede insertar.\n");
        return;
    }
    p -> tope++;
    p -> datos[p -> tope] = valor;
}

int pop(Pila *p)
{
    if(pilaVacia(p))
    {
        printf("La pila esta vacia. No se puede extraer.\n");
        return -1;
    }
    int valor = p -> datos[p -> tope];
    p -> tope--;
    return valor;
}

void mostrarPila(Pila *p)
{
    printf("Pila: ");
    for(int i = 0; i <= p -> tope; i++)
    {
        printf("%d ", p -> datos[i]);
    }
    printf("\n");
}

typedef struct {
    int datos[MAX];
    int inicio;
    int final;
} Cola;

void inicializarCola(Cola *c)
{
    c -> inicio = 0;
    c -> final = -1;
    printf("Cola inicializada vacia.\n");
}

int colaLlena(Cola *c)
{
    return c -> final == MAX - 1;
}

int colaVacia(Cola *c)
{
    return c -> final < c -> inicio;
}

void enqueue(Cola *c, int valor)
{
    if(colaLlena(c))
    {
        printf("La cola esta llena. No se puede insertar.\n");
        return;
    }
    c -> final++;
    c -> datos[c -> final] = valor;
}

int dequeue(Cola *c)
{
    if(colaVacia(c))
    {
        printf("La cola esta vacia. No se puede extraer.\n");
        return -1;
    }
    int valor = c -> datos[c -> inicio];
    c -> inicio++;
    return valor;
}

void mostrarCola(Cola *c)
{
    printf("Cola: ");
    for(int i = c -> inicio; i <= c -> final; i++)
    {
        printf("%d ", c -> datos[i]);
    }
    printf("\n");
}

int main()
{
    Pila p;
    Cola c;
    int n, valor;

    inicializarPila(&p);

    printf("Cuantos elementos desea apilar? (max 5): ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Ingrese valor %d: ", i + 1);
        scanf("%d", &valor);
        push(&p, valor);
        mostrarPila(&p);
    }

    printf("Cuantos elementos desea desapilar? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int salido = pop(&p);
        if(salido != -1)
            printf("Salio: %d\n", salido);
        mostrarPila(&p);
    }

    inicializarCola(&c);

    printf("Cuantos elementos desea encolar? (max 5): ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        printf("Ingrese valor %d: ", i + 1);
        scanf("%d", &valor);
        enqueue(&c, valor);
        mostrarCola(&c);
    }

    printf("Cuantos elementos desea desencolar? ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        int salido = dequeue(&c);
        if(salido != -1)
            printf("Salio: %d\n", salido);
        mostrarCola(&c);
    }

    printf("\nResumen:\n");
    printf("Pila -> LIFO (ultimo en entrar, primero en salir)\n");
    printf("Cola -> FIFO (primero en entrar, primero en salir)\n");

    return 0;
}