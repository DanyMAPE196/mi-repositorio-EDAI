#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    int *arr1 = NULL;
    int *arr2 = NULL;


    printf("Cuantos enteros desea almacenar? ");
    scanf("%d", &n);

    arr1 = (int*) malloc (n * sizeof(int));
    
    
    if(arr1 == NULL)
    {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    printf("\nValores iniciales (basura): \n");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n\n");


    printf("Cuantos enteros desea almacenar? ");
    scanf("%d", &n);

    arr2 = (int*) calloc (n, sizeof(int));
    if(arr2 == NULL)
    {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    printf("\nValores iniciales:\n ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");


    printf("\nIngrese los %d valores para llenar el arreglo:\n ", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }


    printf("\nDetermine un nuevo tamano para el arreglo: ");
    scanf("%d", &m);


    int * temp = realloc(arr2, m * sizeof(int));

    if(temp == NULL)
    {
        printf("Error al redimensionar.\n");
        free(arr2);
        return 1;
    }

    arr2 = temp;


    if(m > n)
    {
        printf("Ingrese los valores faltantes (%d valores):\n", m - n);
        for(int i = n; i < m; i++)
        {
            scanf("%d", &arr2[i]);
        }
    }

    printf("\nValores finales del arreglo:\n");
    for(int i = 0; i < m; i++)
    {
        printf("%d ", arr2[i]);
    }


    free(arr1);
    free(arr2);

    printf("\n\nMemoria liberada correctamente.\n");

    return 0;
}

