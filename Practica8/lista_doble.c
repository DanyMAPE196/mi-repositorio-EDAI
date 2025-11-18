#include <stdio.h>
#include <stdlib.h>

struct Nodo 
{
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **inicio, int valor)
 {
    struct Nodo *nuevo = (struct Nodo*) malloc (sizeof(struct Nodo));
    nuevo -> dato = valor;
    nuevo -> anterior = NULL;
    nuevo -> siguiente = *inicio;

    if (*inicio != NULL) 
    {
        (*inicio) -> anterior = nuevo;
    }

    *inicio = nuevo;
}

void insertarFinal(struct Nodo **inicio, int valor) 
{
    struct Nodo *nuevo = (struct Nodo*) malloc (sizeof(struct Nodo));
    nuevo -> dato = valor;
    nuevo -> siguiente = NULL;

    if (*inicio == NULL) 
    {
        nuevo -> anterior = NULL;
        *inicio = nuevo;
        return;
    }

    struct Nodo *actual = *inicio;
    while (actual -> siguiente != NULL)
     {
        actual = actual -> siguiente;
    }

    actual -> siguiente = nuevo;
    nuevo -> anterior = actual;
}

void recorrerAdelante(struct Nodo *inicio)
 {
    struct Nodo *actual = inicio;

    printf("Recorrido adelante: ");
    while (actual != NULL) {
        printf("%d -> ", actual -> dato);
        actual = actual -> siguiente;
    }
    printf("NULL\n");
}

void recorrerAtras(struct Nodo *inicio)
 {
    if (inicio == NULL) 
    {
        printf("Recorrido atras: lista vacia\n");
        return;
    }

    struct Nodo *actual = inicio;
    

    while (actual->siguiente != NULL)
     {
        actual = actual->siguiente;
    }

    printf("Recorrido atras: ");
    while (actual != NULL)
     {
        printf("%d -> ", actual -> dato);
        actual = actual -> anterior;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **inicio, int valor) 
{
    struct Nodo *actual = *inicio;

    while (actual != NULL && actual -> dato != valor) 
    {
        actual = actual -> siguiente;
    }

    if (actual == NULL) 
    {
        printf("Valor no encontrado.\n");
        return;
    }

    
    if (actual->anterior == NULL) 
    {
        *inicio = actual -> siguiente;
        if (*inicio != NULL) 
        {
            (*inicio) -> anterior = NULL;
        }
    }
    
    else if (actual -> siguiente == NULL) 
    {
        actual -> anterior -> siguiente = NULL;
    }

    else 
    {
        actual -> anterior -> siguiente = actual -> siguiente;
        actual -> siguiente -> anterior = actual -> anterior;
    }

    free(actual);
    printf("Nodo eliminado.\n");
}

void liberar(struct Nodo *inicio) 
{
    struct Nodo *actual = inicio;

    while (actual != NULL)
     {
        struct Nodo *temp = actual;
        actual = actual -> siguiente;
        free(temp);
    }

    printf("Memoria liberada correctamente.\n");
}

int main()
 {
    struct Nodo *inicio = NULL;
    int n, valor;

    printf("Cuantos valores deseas insertar al inicio? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
    {
        printf("Valor: ");
        scanf("%d", &valor);
        insertarInicio(&inicio, valor);
        recorrerAdelante(inicio);
    }

    printf("\nCuantos valores deseas insertar al final? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
     {
        printf("Valor: ");
        scanf("%d", &valor);
        insertarFinal(&inicio, valor);
        recorrerAdelante(inicio);
    }

    printf("\nLista completa:\n");
    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    printf("\nValor a eliminar: ");
    scanf("%d", &valor);
    eliminar(&inicio, valor);

    printf("\nLista actualizada:\n");
    recorrerAdelante(inicio);
    recorrerAtras(inicio);

    liberar(inicio);

    return 0;
}
