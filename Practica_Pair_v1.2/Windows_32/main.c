#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/
int menu();

int main()
{
    ArrayList* lista = al_newArrayList();
    Employee* aux;

    FILE* f = fopen("data.csv", "r");
    if(f == NULL){
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    parserEmployee(f, lista);

    int cantidad = lista->len(lista);
int i;

    lista->sort(lista,employee_compare,0);


    for(i = 0; i < cantidad; i++){
        aux = (Employee*)lista->get(lista, i);
        employee_print(aux);

    }




    return 0;
}
int menu()
{
    int opcion;
    system("cls");
        printf("**Menu de opciones**\n\n");
        printf("1. Parse del archivo data.csv\n");
        printf("2. Listar Empleados\n");
        printf("3. Ordenar por nombre\n");
        printf("4. Agregar un elemento\n");
        printf("5. Elimina un elemento\n");
        printf("6. Listar Empleados (Desde/Hasta)\n");
        printf("7. Salir\n\n");
        printf("Indique opcion: ");
        scanf("%d",&opcion);
        while(opcion<1||opcion>7)
        {
            printf("OPCION INCORRECTA. Reingrese opcion: ");
            scanf("%d",&opcion);
        }
        return opcion;
}
