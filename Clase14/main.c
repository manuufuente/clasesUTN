#include <stdio.h>
#include <stdlib.h>
#include <string.h>





typedef struct
{
    int id;
    char marca[20];
    char modelo[15];
    float precio;
    fopen
}eNotebook;

eNotebook* new_notebook (void);
void mostrar_notebook (eNotebook* x);
eNotebook* new_notebook_param (int , char* , char* , float);

int main()
{
    eNotebook* unaNotebook;
    eNotebook* otraNotebook;
    unaNotebook = new_notebook();


    if (unaNotebook == NULL)
    {
        printf("No se puede asignar memoria.");
        exit(1);
    }

    otraNotebook = new_notebook_param(1200, "HP", "Eloin", 30000);



    mostrar_notebook(unaNotebook);
    free(otraNotebook);
    free(unaNotebook);

    return 0;
}


eNotebook* new_notebook (void)

{
    eNotebook* x;
    x = (eNotebook*) malloc(sizeof(eNotebook));

    //seria lo mismo si se pone return y el contenido asignado a x
    if(x != NULL)
    {
        x ->id = 0;
        x->precio = 0;
        strcpy(x->marca," ");
        strcpy(x->modelo," ");
    }

    return x;
}

void mostrar_notebook (eNotebook* x)
{
    printf("id: %d\n", x->id);
    printf("marca: %s\n", x->marca);
    printf("modelo: %s\n",x->modelo);
    printf("precio: %.2f", x->precio);
}


eNotebook* new_notebook_param (int id, char* marca, char* modelo, float precio)

{
    eNotebook* x;
    x = (eNotebook*) malloc(sizeof(eNotebook));

    //seria lo mismo si se pone return y el contenido asignado a x
    if(x != NULL)
    {
        x ->id = id;
        x->precio = precio;
        strcpy(x->marca, marca);
        strcpy(x->modelo, modelo);
    }

    return x;
}
