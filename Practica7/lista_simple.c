#include <stdio.h>
#include <stdlib.h>

struct Nodo 
{
    int dato;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **cabeza, int valor)
 {
    struct Nodo *nuevo = (struct Nodo*) malloc (sizeof(struct Nodo));
    nuevo -> dato = valor;
    nuevo -> siguiente = *cabeza;
    *cabeza = nuevo;
}

void recorrer(struct Nodo *cabeza)
 {
    struct Nodo *actual = cabeza;
    while (actual != NULL)
     {
        printf("%d -> ", actual -> dato);
        actual = actual -> siguiente;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **cabeza, int valor) 
{
    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = NULL;

    while (actual != NULL && actual->dato != valor)
     {
        anterior = actual;
        actual = actual -> siguiente;
    }

    if (actual == NULL)
     {
        printf("Ese valor no existe en la lista.\n");
        return;
    }

    if (anterior == NULL) {
        *cabeza = actual -> siguiente;
    } else {
        anterior -> siguiente = actual -> siguiente;
    }

    free(actual);
}

void liberar(struct Nodo *cabeza)
 {
    struct Nodo *actual = cabeza;
    struct Nodo *tmp;

    while (actual != NULL)
     {
        tmp = actual;
        actual = actual -> siguiente;
        free(tmp);
    }

    printf("Memoria liberada correctamente.\n");
}

int main()
 {
    struct Nodo *cabeza = NULL;
    int n, valor, eliminarValor;

    printf("Cuantos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Ingresa un valor: ");
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        printf("Lista actual: ");
        recorrer(cabeza);
    }

    printf("\nQue valor deseas eliminar? ");
    scanf("%d", &eliminarValor);

    eliminar(&cabeza, eliminarValor);

    printf("Lista despues de eliminar: ");
    recorrer(cabeza);

    liberar(cabeza);

    return 0;
}