#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10    
#define NUM_DIR 2   

struct pelicula {
    char nombre[50];
    char genero[50];
    int  anio;
    int  numDirectores;
    char directores[NUM_DIR][50];
};

int main(void) {
    struct pelicula *videoteca;
    videoteca = (struct pelicula*) malloc(TAM * sizeof(struct pelicula));

    if (videoteca == NULL) {
        printf("Error al reservar memoria\n");
        return 1;
    }

    strcpy(videoteca[0].nombre, "ToyStory");
    strcpy(videoteca[0].genero, "Animacion");
    videoteca[0].anio = 1995;
    videoteca[0].numDirectores = 1;
    strcpy(videoteca[0].directores[0], "John Lasseter");

    strcpy(videoteca[1].nombre, "Frozen");
    strcpy(videoteca[1].genero, "Musical");
    videoteca[1].anio = 2013;
    videoteca[1].numDirectores = 2;
    strcpy(videoteca[1].directores[0], "Chris Buck");
    strcpy(videoteca[1].directores[1], "Jennifer Lee");

    strcpy(videoteca[2].nombre, "Moana");
    strcpy(videoteca[2].genero, "Aventura");
    videoteca[2].anio = 2016;
    videoteca[2].numDirectores = 2;
    strcpy(videoteca[2].directores[0], "Ron Clements");
    strcpy(videoteca[2].directores[1], "John Musker");

    strcpy(videoteca[3].nombre, "Ratatouille");
    strcpy(videoteca[3].genero, "Fantasia");
    videoteca[3].anio = 2007;
    videoteca[3].numDirectores = 1;
    strcpy(videoteca[3].directores[0], "Brad Bird");

    strcpy(videoteca[4].nombre, "Mulan");
    strcpy(videoteca[4].genero, "Accion");
    videoteca[4].anio = 1998;
    videoteca[4].numDirectores = 2;
    strcpy(videoteca[4].directores[0], "Tony Bancroft");
    strcpy(videoteca[4].directores[1], "Barry Cook");

    strcpy(videoteca[5].nombre, "Elementos");
    strcpy(videoteca[5].genero, "Fantasia");
    videoteca[5].anio = 2023;
    videoteca[5].numDirectores = 1;
    strcpy(videoteca[5].directores[0], "Peter Sohn");

    strcpy(videoteca[6].nombre, "Coco");
    strcpy(videoteca[6].genero, "Musical");
    videoteca[6].anio = 2017;
    videoteca[6].numDirectores = 2;
    strcpy(videoteca[6].directores[0], "Lee Unkrich");
    strcpy(videoteca[6].directores[1], "Adriana Molina");

    strcpy(videoteca[7].nombre, "Tarzan");
    strcpy(videoteca[7].genero, "Aventura");
    videoteca[7].anio = 1999;
    videoteca[7].numDirectores = 2;
    strcpy(videoteca[7].directores[0], "Kevin Lima");
    strcpy(videoteca[7].directores[1], "Chris Buck");

    strcpy(videoteca[8].nombre, "Hercules");
    strcpy(videoteca[8].genero, "Fantasia");
    videoteca[8].anio = 1997;
    videoteca[8].numDirectores = 2;
    strcpy(videoteca[8].directores[0], "Ron Clements");
    strcpy(videoteca[8].directores[1], "John Musker");

    strcpy(videoteca[9].nombre, "Zootopia");
    strcpy(videoteca[9].genero, "Animacion");
    videoteca[9].anio = 2016;
    videoteca[9].numDirectores = 2;
    strcpy(videoteca[9].directores[0], "Byron Howard");
    strcpy(videoteca[9].directores[1], "Rich Moore");


    printf("\n=== Videoteca Disney ===\n");
    for (int i = TAM - 1; i >= 0; i--) {
        printf("Pelicula: %s\n", videoteca[i].nombre);
        printf("Genero: %s\n", videoteca[i].genero);
        printf("Anio: %d\n", videoteca[i].anio);
        printf("Directores (%d):\n", videoteca[i].numDirectores);
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            printf("  - %s\n", videoteca[i].directores[j]);
        }
        printf("\n");
    }

    char buscar[50];
    int encontrado = 0;
    printf("\nBuscar pelicula por nombre: ");
    scanf("%49s", buscar);

    for (int i = 0; i < TAM; i++) {
        if (strcmp(buscar, videoteca[i].nombre) == 0) {
            printf("Encontrada: %s (%d)\n", videoteca[i].nombre, videoteca[i].anio);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("La pelicula %s no se encuentra en la videoteca.\n", buscar);
    }

    int anioBuscar;
    encontrado = 0;
    printf("\nBuscar pelicula por anio: ");
    scanf("%d", &anioBuscar);

    for (int i = 0; i < TAM; i++) {
        if (videoteca[i].anio == anioBuscar) {
            printf("Encontrada: %s (%s)\n", videoteca[i].nombre, videoteca[i].genero);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontraron peliculas del anio %d.\n", anioBuscar);
    }

    char directorBuscar[50];
    encontrado = 0;
    printf("\nBuscar pelicula por director: ");
    scanf("%49s", directorBuscar);

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < videoteca[i].numDirectores; j++) {
            if (strcmp(directorBuscar, videoteca[i].directores[j]) == 0) {
                printf("Encontrada: %s (%d)\n", videoteca[i].nombre, videoteca[i].anio);
                encontrado = 1;
            }
        }
    }
    if (!encontrado) {
        printf("No se encontro ninguna pelicula dirigida por %s.\n", directorBuscar);
    }

    printf("\nContador de peliculas por genero:\n");
    for (int i = 0; i < TAM; i++) {
        int yaContado = 0;
        
        for (int k = 0; k < i; k++) {
            if (strcmp(videoteca[i].genero, videoteca[k].genero) == 0) {
                yaContado = 1;
                break;
            }
        }
        if (!yaContado) {
            int contador = 0;
            for (int j = 0; j < TAM; j++) {
                if (strcmp(videoteca[i].genero, videoteca[j].genero) == 0) {
                    contador++;
                }
            }
            printf("Genero %s: %d peliculas\n", videoteca[i].genero, contador);
        }
    }

    free(videoteca);
    return 0;
}