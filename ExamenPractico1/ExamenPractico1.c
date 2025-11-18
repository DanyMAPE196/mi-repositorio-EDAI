# include <stdio.h>
# include <stdlib.h>

int main(){
    int n; //variable para el número de estudiantes
    int agregar; //variable para cantidad extra
    int i; // variable para el contador 
    float *calificaciones = NULL; //puntero para almacenar dinamicamente las calificaciones
    float suma = 0.0; //variable para acumular la suma
    float promedio; //variable para calcular el promedio

    //Pedimos al usuario la cantidad de estudiantes que desea registrar 
    printf("¿Cuántos estudiantes deseas ingresar?: ");
    scanf("%d", &n);

    //Reservamos la memoria dinámica para almacenar las calificaciones
    calificaciones = (float*) malloc(n * sizeof(float));
    if (calificaciones == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1; //para salir si el malloc falla
    }


//Se capturan las calificaciones iniciales
for(i = 0; i < n; i++)
{
    printf("Calificación del estudiante %d: ", i + 1);
    scanf("%f", &calificaciones[i]);
    suma += calificaciones [i]; //Para sumar las calificaciones y calcular el pormedio 
}

//Calculamos e  imprimimos el promedio inicial 
promedio = suma / n;
printf("Promedio inicial: %.2f\n", promedio);

//Preguntamos al usuario si desea agregar más estudiantes
printf ("¿Deseas agregar más estudiantes? (cantidad, 0 para no): ");
scanf("%d", &agregar);


if(agregar > 0)
{
    //Ampliamos el arreglo (realloc) para almacenar más calificaciones si es solicitado
    float*tmp = (float*)realloc(calificaciones, (n + agregar) * sizeof(float));
    if(tmp == NULL)
    {
        printf("Error al ampliar memoria.\n");
        free(calificaciones);
        return 1; //Liberamos memoria si realloc falla
    }
    calificaciones = tmp; //Actualizamos el puntero con la nueva memoria

    //Campturamos las calificaciones agregadas y se actualiza la suma
    for(i = n; i <n + agregar; i++)
    {
        printf("Calificación del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones [i]);
        suma += calificaciones[i];
    }

    n += agregar; //Se actualiza el total de estudiantes
    promedio = suma / n; //Se vuelve a calcular el promedio total 
}

//Se imprimen todas las calificaciones registradas
printf("=== Calificaciones registradas===\n");
for(i = 0; i < n; i++)
{
    printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
}

//Se imprime el promedio  total 
printf("Promedio general: %.2f\n\n", promedio);

//Liberamos la memoria 
    free(calificaciones);
    printf("Memoria liberada correctamente.\n");


    return 0;

}