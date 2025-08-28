#include <stdio.h>


int main()
{
    int a, b, c, temp;
    int v[50];

    printf("Ingresa la cantidad de elementos que tendrá el arreglo: ");
    scanf("%d", &a);

    for(b = 0; b < a; b++)
    {
        printf("Elemento %d: ", b);
        scanf("%d", &v[b]);
    }

b = 0;
c = a - 1;

while (b < c)
{
    temp = v[b];
    v[b] = v[c];
    v[c] = temp;

    b = b +1; 
    c = c -1;
}

printf("\nArreglo invertido:\n");
for( b = 0; b < a; b++)
{
    printf("%d", v[b]);
}
printf("\n");

return 0;
} 