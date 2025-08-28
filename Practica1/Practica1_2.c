#include <stdio.h>

int main(){
    int n, i;
    int min, max;
    int suma = 0;
    int posicion_min = 0, posicion_max = 0;
    int v[50];

    printf("Ingresa la cantidad de elementos que tendra el vector: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Elemento %d: ", i);
        scanf("%d", &v[i]);
    }

    min = v[50];
    max = v[0];

    for( i = 0; i < n; i++)
    {
        suma = suma + v[i];

        if(v[i] < min)
        {
            min = v[i];
            posicion_min = i;
        }

    if(v[i] > max)
        {
           max = v[i];
            posicion_max = i;
        }
    }

    float promedio = (float)suma / n;

    printf("\nSuma: %d\n", suma);
    printf("Promedio: %.2f\n",promedio);
    printf("Minimo: %d en la posicion %d\n", min, posicion_min);
    printf("Maximo: %d en la posicion %d\n", max, posicion_max);

    return 0;
}