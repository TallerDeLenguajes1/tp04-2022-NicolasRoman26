#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Tarea
{
    int TareaID;       // Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
};
typedef struct Tarea tarea;

void cargarTareas(tarea **listaTareas, int cantidadTareas);
void mostrarTareasYMover(tarea **listaTareas, tarea **tareasRealizadas, int cantidadTareas);
void mostrarRealizadasYPorRealizar(tarea **listaTareas, tarea **tareasRealizadas, int cantidasTareas);

void main()
{
    int cantidadTareas = 0;
    tarea **listaTareas;
    tarea **tareasRealizadas;

    printf("Ingrese cuantas tareas desea cargar: ");
    scanf("%d", &cantidadTareas);
    getchar();

    /**********RESERVO MEMORIA**********/

    listaTareas = (tarea **)malloc(cantidadTareas * sizeof(tarea *));
    tareasRealizadas = (tarea **)malloc(cantidadTareas * sizeof(tarea *));

    for (int i = 0; i < cantidadTareas; i++)
    {
        listaTareas[i] = (tarea *)malloc(sizeof(tarea));
    }

    cargarTareas(listaTareas, cantidadTareas);
    mostrarTareasYMover(listaTareas, tareasRealizadas, cantidadTareas);
    mostrarRealizadasYPorRealizar(listaTareas, tareasRealizadas, cantidadTareas);

    for (int i = 0; i < cantidadTareas; i++)
    {
        // free((*(listaTareas + i))->Descripcion);
        free(listaTareas[i]);
        // free((*(tareasRealizadas + i))->Descripcion);
        free(tareasRealizadas[i]);
    }

    free(listaTareas);
    free(tareasRealizadas);
}

void cargarTareas(tarea **listaTareas, int cantidadTareas)
{
    char *buff;
    int duracion = 0;

    buff = (char *)malloc(150 * sizeof(char));

    printf("\n***** CARGAR TAREAS *****\n");

    for (int i = 0; i < cantidadTareas; i++)
    {

        printf("\nTarea numero %d", i + 1);

        (*(listaTareas + i))->TareaID = i + 1;
        printf("\nIngrese una descripcion de la tarea a realizar: ");
        fflush(stdin);
        gets(buff);

        (*(listaTareas + i))->Descripcion = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy((*(listaTareas + i))->Descripcion, buff);

        while (duracion < 10 || duracion > 100)
        {
            printf("Ingrese una duracion de la tarea (entre 10 y 100): ");
            scanf("%d", &duracion);
            getchar();
        }

        (*(listaTareas + i))->Duracion = duracion;

        duracion = 0;
    }

    free(buff);
}

void mostrarTareasYMover(tarea **listaTareas, tarea **tareasRealizadas, int cantidadTareas)
{
    int aux;

    printf("\n***** MOSTRAR DATOS *****\n");

    for (int i = 0; i < cantidadTareas; i++)
    {
        printf("\nTarea numero %d", i + 1);
        printf("\nID: %d", (*(listaTareas + i))->TareaID);
        printf("\nDescripcion: %s", (*(listaTareas + i))->Descripcion);
        printf("\nDuracion: %d", (*(listaTareas + i))->Duracion);

        printf("\n\nSe realizo dicha tarea?(1= SI, 2= NO): ");
        scanf("%d", &aux);
        getchar();

        if (aux == 1)
        {
            *(tareasRealizadas + i) = *(listaTareas + i);
            *(listaTareas + i) = NULL;
        }
        else
        {
            *(tareasRealizadas + i) = NULL;
        }
    }
}

void mostrarRealizadasYPorRealizar(tarea **listaTareas, tarea **tareasRealizadas, int cantidasTareas)
{
    for (int i = 0; i < cantidasTareas; i++)
    {
        if (*(listaTareas + i) != NULL)
        {
            printf("\n\n****TAREA POR REALIZAR****");
            printf("\nID: %d", (*(listaTareas + i))->TareaID);
            printf("\nDescripcion: %s", (*(listaTareas + i))->Descripcion);
            printf("\nDuracion: %d", (*(listaTareas + i))->Duracion);
        }
        else
        {
            printf("\n\n****TAREA YA REALIZADA****");
            printf("\nID: %d", (*(tareasRealizadas + i))->TareaID);
            printf("\nDescripcion: %s", (*(tareasRealizadas + i))->Descripcion);
            printf("\nDuracion: %d", (*(tareasRealizadas + i))->Duracion);
        }
    }
}