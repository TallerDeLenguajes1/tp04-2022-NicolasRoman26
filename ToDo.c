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

int main()
{
    int cantidadTareas;
    struct Tarea **tareasPendientes;
    char *buff;

    buff = (char *)malloc(100 * sizeof(char));

    printf("Ingrese la cantidad de tareas que quiere realizar: ");
    scanf("%d", &cantidadTareas);
    getchar();

    tareasPendientes = (struct Tarea **)malloc(cantidadTareas * sizeof(struct Tarea *));

    for (int i = 0; i < cantidadTareas; i++)
    {
        tareasPendientes[i] = (struct Tarea *)malloc(sizeof(struct Tarea));
    }

    printf("\n******CARGO LAS TAREAS******\n");

    for (int i = 0; i < cantidadTareas; i++)
    {
        tareasPendientes[i]->TareaID = i + 1;

        printf("Ingrese la descripcion de la tarea\n: ");
        gets(buff);
        tareasPendientes[i]->Descripcion = (char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(tareasPendientes[i]->Descripcion, buff);

        printf("Ingrese la duracion de la tarea: \n");
        scanf("%d", &tareasPendientes[i]->Duracion);
        getchar();
    }

    printf("\n******TODAS LAS TAREAS******\n");

    for (int i = 0; i < cantidadTareas; i++)
    {

        printf("ID de la tarea: %d\n", tareasPendientes[i]->TareaID);
        printf("Decripcion de la tarea: %s\n", tareasPendientes[i]->Descripcion);
        printf("Duracion de la tarea: %d\n", tareasPendientes[i]->Duracion);
    }

    getchar();
    return 0;
}