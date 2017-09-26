#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define TAM 5


typedef struct
{
    int id;
    char nombre[20];
    char categoria;
    int proyecto;
    int estado;
}
eProgramador;

typedef struct{
int id;
char descripcion[50];
}eProyectos;

typedef struct{
int idProyecto;
int idProg;
int hs;
}eAsignaciones;

typedef struct{
int idProyecto;
int hs;
}eHoras;

//a = Senior
//b = SemiSenior
//c = Junior

int menu();
void inicializar(eProgramador[], int);
void mostrarprogramadores(eProgramador[],int);
void mostrarProgramador(eProgramador);
void mostrarProgrProyHs(eProgramador[],eProyectos[],eAsignaciones[]);
void ProyectoConMasHoras(eHoras[],eProyectos[],eAsignaciones[],int);
void inicializarHoras(eHoras[],int);

int main()
{
    eProgramador programador[]={{123,"Manuel",'a',1,1},{234,"Nico",'b',1,1},{345,"Daniel",'b',3,1},{456,"Nehuen",'c',2,1},{567,"Sebas",'b',3,1},{678,"Eze",'c',3,1}};
    eProyectos proyecto[]={{1,"Links"},{2,"Santan"},{3,"Galicia"}};
    eAsignaciones asignacion[]={{1,123,3},{1,234,3},{3,345,2},{2,456,5},{3,567,4},{3,678,1},};
    eHoras horas[]={{1,0},{2,0},{3,0},};



    int salir = 1;
    do{

        switch(menu()){
    case 1:
        system("cls");
        printf("Opcion1");
        getch();

        break;

    case 2:
         system("cls");
        printf("Opcion2");
        getch();


        break;
    case 3:
         system("cls");
        printf("Opcion3");
        getch();

        break;

    case 4:
         system("cls");
         mostrarprogramadores(programador,6);
        mostrarProgrProyHs(programador,proyecto,asignacion);
        ProyectoConMasHoras(horas,proyecto,asignacion,3);

        break;



    case 5:
      salir = 0;



        break;

        }

    }while(salir);
    return 0;
}


    int menu(){
        int opcion;
        system("cls");
        printf("\n***Programadores***\n\n\n");
        printf("1- Alta Programador\n");
        printf("2- Modificacion Programador\n");
        printf("3- Baja Programador\n");
        printf("4- Listado Programadores\n");
        printf("5- Salir\n");
        printf("\n\nIngrese opcion: ");
        scanf("%d", &opcion);

        return opcion;

    }

void inicializar(eProgramador lista[], int tam)
{
    for(int i=0;i<tam;i++)
    {
         lista[i].estado=0;
    }
}

void(mostrarprogramadores(eProgramador lista[],int tam))
{
    int flag=0;

    for(int i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
            mostrarProgramador(lista[i]);
            flag=1;
        }
        if(flag==0)
        {
            printf("No hay programadores que mostrar");
        }
    }
}
void mostrarProgramador(eProgramador prog)
{
    printf("%s\t %c\t %d \n",prog.nombre,prog.categoria,prog.proyecto);
}
void mostrarProgrProyHs(eProgramador prog[],eProyectos proy[],eAsignaciones asig[])
{
    printf("\n---------------------------------------------\n");
    printf("NOMBRE\tPROYECTO\tHS\n\n");
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(prog[i].id==asig[j].idProg)
            {

                for(int k=0;k<3;k++)
                {
                    if(proy[k].id==asig[j].idProyecto)
                    {
                        printf("%s\t%s\t%10d\n",prog[i].nombre,proy[k].descripcion,asig[j].hs);

                    }
                }
            }
        }

    }

}
void ProyectoConMasHoras(eHoras horas[],eProyectos proy[],eAsignaciones asig[], int tam)
{
    printf("\n---------------------------------------------------------------\n");
    printf(" \t PROYECTO CON MAS HORAS ASIGNADAS\n\n");
    int max=0;
    int auxid;

    for(int i=0;i<6;i++)
    {
        for(int j=0;j<tam;j++)
        {
            if(asig[i].idProyecto==proy[j].id)
            {
                horas[j].hs+=asig[i].hs;
            }
        }
    }

    for(int i=0;i<tam;i++)
    {
        if(horas[i].hs>max)
        {
            max=horas[i].hs;
            auxid=horas[i].idProyecto;
        }
    }
    for(int i=0;i<tam;i++)
    {
        if(proy[i].id==auxid)
        {
            printf("EL Proyecto %s tiene %d horas asignadas",proy[i].descripcion,max);
        }
    }

    printf("\n\n-------------------------------------------------\n\n");
    system("pause");
    system("cls");
}
void inicializarHoras(eHoras horas[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        horas[i].hs=0;
    }
}
