#include <stdio.h>
#include <stdlib.h>

struct Nodo
 {
    int dato;
    struct Nodo *siguiente;
};

void insertarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor)
 {
    struct Nodo *nuevo = (struct Nodo*) malloc (sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*cabeza == NULL)
     {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo -> siguiente = nuevo;
    } else {
        nuevo -> siguiente = *cabeza;
        (*ultimo) -> siguiente = nuevo;
        *cabeza = nuevo;
    }
}

void recorrerCircular(struct Nodo *cabeza) 
{
    if (cabeza == NULL) return;

    struct Nodo *actual = cabeza;
    do {
        printf("%d -> ", actual -> dato);
        actual = actual -> siguiente;
    } while (actual != cabeza);

    printf("\n");
}

void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor)
 {
    if (*cabeza == NULL) return;

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = *ultimo;

    do {
        if (actual -> dato == valor) 
        {
            if (actual == *cabeza) 
            {
                *cabeza = actual -> siguiente;
                (*ultimo) -> siguiente = *cabeza;
            } else
             {
                anterior -> siguiente = actual -> siguiente;
                if (actual == *ultimo)
                 {
                    *ultimo = anterior;
                }
            }

            free(actual);
            return;
        }

        anterior = actual;
        actual = actual -> siguiente;
    } while (actual != *cabeza);

    printf("Valor no encontrado.\n");
}

int main()
 {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int n, valor, eliminarValor;

    printf("Cuantos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Ingresa un valor: ");
        scanf("%d", &valor);
        insertarCircular(&cabeza, &ultimo, valor);
        printf("Lista circular actual: ");
        recorrerCircular(cabeza);
    }

    printf("\nQue valor deseas eliminar? ");
    scanf("%d", &eliminarValor);

    eliminarCircular(&cabeza, &ultimo, eliminarValor);

    printf("Lista despues de eliminar: ");
    recorrerCircular(cabeza);

    return 0;
}