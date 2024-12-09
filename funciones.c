#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu() {
    int opc=0;
    printf("Menu:\n");
    printf("1. Registrar libros\n");
    printf("2. Mostrar libros\n");
    printf("3. Buscar libro por id\n");
    printf("4. Buscar libro por titulo\n");
    printf("5. Editar estado de libro\n");
    printf("6. Eliminar libro\n");
    printf("7. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opc);
}

void registrarLibros(struct Libro libros[20], int i) {
        printf("Ingrese el id del libro: ");
        scanf("%d", &libros[i].id);
        printf("Ingrese el titulo del libro: ");
        scanf("%s", libros[i].titulo);
        printf("Ingrese el autor del libro: ");
        scanf("%s", libros[i].autor);
        printf("Ingrese el anio del libro: ");
        scanf("%d", &libros[i].anio);
        printf("Ingrese el estado del libro: ");
        scanf("%s", libros[i].estado);
}

void mostrarLibros(struct Libro libros[20]) {
    printf("Libros registrados:\n");
    printf("ID\t\tTitulo\t\tAutor\t\tAnio\t\tEstado\n");
    for (int i = 0; i < 20; i++)
    {
        if(libros[i].id != 0) {
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n", libros[i].id,
                                               libros[i].titulo,
                                               libros[i].autor,
                                               libros[i].anio,
                                               libros[i].estado);
        }
    }
}

void buscarLibroId(struct Libro libros[20], int id) {
    for (int i = 0; i < 20; i++)
    {
        if (libros[i].id == id)
        {
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n", libros[i].id,
                                               libros[i].titulo,
                                               libros[i].autor,
                                               libros[i].anio,
                                               libros[i].estado);
        }
    }
}

void buscarLibroTitulo(struct Libro libros[20], char titulo[100]) {
    for (int i = 0; i < 20; i++)
    {
        if (strcmp(libros[i].titulo,titulo) == 0)
        {
            printf("%d\t\t%s\t\t%s\t\t%d\t\t%s\n", libros[i].id,
                                               libros[i].titulo,
                                               libros[i].autor,
                                               libros[i].anio,
                                               libros[i].estado);
        }
    }
}

void editarLibroEstado(struct Libro libros[20], int id, char estado[50]) {
    for (int i = 0; i < 20; i++)
    {
        if (libros[i].id == id)
        {
            strcpy(libros[i].estado, estado);
        }
    }
}

void eliminarLibro(struct Libro libros[20], int id) {
    for (int i = 0; i < 20; i++)
    {
        if (libros[i].id == id)
        {
            libros[i].id = 0;
            strcpy(libros[i].titulo, "");
            strcpy(libros[i].autor, "");
            libros[i].anio = 0;
            strcpy(libros[i].estado, "");
        }
    }
}