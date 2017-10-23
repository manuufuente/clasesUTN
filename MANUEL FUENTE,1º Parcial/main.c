#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>


#define TAM 7


typedef struct{
int id;
int dni;
char nombre[30];
char apellido[20];
int estado;
}eCliente;

typedef struct{
int idCliente;
char equipo[20];
int tiempoEstmado;
char operador[20];
char estado[20];
int tiempoReal;
int cant;
}eAlquiler;

int main()
{
    eCliente clientes[]={{0,123,"manuel","Fuente",1},{1,345,"juan","torres",1},{2,321,"ariel","sardo",1},{3,678,"dani","cardone",1},{4,987,"nico","botte",1}};
    eAlquiler alquileres[]={{0,"mezcladora",2,"juan","FINALIZADO",10,0},{0,"amoladora",2,"juan","alquilado",7,0},{1,"mezcladora",3,"juan","FINALIZADO",6,0},{2,"taladro",3,"juan","FINALIZADO",5,0},{3,"mezcladora",6,"juan","FINALIZADO",3,0},{4,"taladro",9,"juan","FINALIZADO",11,0},{3,"amoladora",2,"juan","FINALIZADO",6,0}};

       // eCliente clientes[TAM];
      //  eAlquiler alquileres[TAM];

    int  id=0,idc,idx,idcAlqui=0,opcion;
    char auxid[20];
    char seguir='s';



   // inicializarEstado(clientes,TAM);
    while(seguir=='s')
    {
        printf("1- Agregar cliente\n");
        printf("2- Modificar persona\n");
        printf("3- Borrar persona\n");
        printf("4- Agregar alquiler\n");
        printf("5- Fin de alquiler\n");
        printf("6- Mostrar datos\n");
        printf("7- Salir\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        system("cls");



        switch(opcion)
        {
            case 1:
                     idc=buscarLibre(clientes,TAM);
                    if(idc==-1)
                    {
                        printf("\nMEMORIA LLENA\n");
                            break;
                    }
                    printf("%d",idc);
                    altaCliente(clientes,id,idc);
                    id++;

                break;
            case 2:
                    printf("Ingrese ID a modificar: ");
                    fflush(stdin);
                    gets(auxid);
                        while(esNumero(auxid)==0)
                        {
                            printf("El ID debe ser solo numerico.Reingrese ID a modificar: ");
                            fflush(stdin);
                            gets(auxid);
                        }
                       idx=atoi(auxid);

                       for(int i=0;i<TAM;i++)
                       {
                           if(clientes[i].id==idx)
                           {
                               idc=i;
                           }

                       }
                       modificarCliente(clientes,idx,idc);

                        break;
                case 3:
                    printf("Ingrese ID a eliminar: ");
                    fflush(stdin);
                    gets(auxid);
                        while(esNumero(auxid)==0)
                        {
                            printf("El ID debe ser solo numerico.Reingrese ID a eliminar: ");
                            fflush(stdin);
                            gets(auxid);
                        }
                       idx=atoi(auxid);
                       for(int i=0;i<TAM;i++)
                       {
                           if(clientes[i].id=idx)
                           {
                               idc=i;
                           }
                       }
                       clientes[idc].estado==0;
                break;
                case 4:
                       if(idcAlqui>=TAM)
                       {
                            printf("\nEspacio lleno\n\n");
                            system("pause");
                            system("cls");
                       }else{
                        nuevoAlquiler(alquileres,idcAlqui);
                            }
                        idcAlqui++;

                break;
                case 5:
                    printf("Ingrese ID del cliente: ");
                    fflush(stdin);
                    gets(auxid);
                        while(esNumero(auxid)==0)
                        {
                            printf("El ID debe ser solo numerico.Reingrese ID del cliente: ");
                            fflush(stdin);
                            gets(auxid);
                        }
                       idx=atoi(auxid);
                       for(int i=0;i<TAM;i++)
                       {
                           if(alquileres[i].idCliente=idx)
                           {
                               idc=i;
                           }
                       }
                       finDeAlquiler(alquileres,idc);


                break;
                case 6:
                    printf("\n-----------------------------------------------------------\n");
                    printf("ID\tNOMBRE\tAPELLIDO\tEQUIPO\tESTADO\n\n");
                    mostrarClientes(clientes,alquileres,TAM);
                    printf("\n-----------------------------------------------------------\n");
                    printf("          PROMEDIO DE TIEMPO REAL\n\n");
                    mostrarPromedioTimpoRal(alquileres,TAM);
                    mostrarCliMasAlqui(clientes,alquileres,TAM);
                    system("pause");
                    system("cls");


                    break;

                case 7:
                    seguir='n';
                    break;
        }

    }
    return 0;
}

