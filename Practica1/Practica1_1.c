#include <stdio.h>

    int main()
    {
        int x;
        int y;
        int a[50];

        do{
            printf("Ingresa una cantidad (maximo 50): ");
            scanf("%d", &x);

            if(x <= 0 || x > 50)
            {
                printf("El valor no es valido. Ingresa otro numero:\n ");
            }
        
        }
        while(x <= 0 || x > 50);

        printf("\nIngrese %d numeros:\n", x);
        for(y = 0; y < x; y++)
        {
            printf("Elemento %d: ", y);
            scanf("%d", &a[y]);
        }
        
        printf("\nLos elementos del arreglo son:\n");
        for(y = 0; y < x; y++)
        {
            printf("%d ", a[y]);
        }

        printf("\n");
        return 0;
    }