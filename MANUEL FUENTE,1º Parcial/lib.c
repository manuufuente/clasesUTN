#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "lib.h"
int esNumero(char str[])
{
  int cont = 0;

    while(str[cont] != '\0')
    {
     if((str[cont]<'0'||str[cont]>'9'))
      {
        return 0;
      }
      cont++;
    }
  return 1;
}
int largodecadena (char numero[],int tam)
{
    int retorno=0;

        if(strlen(numero)<tam+1)
            retorno=1;

      return retorno;
}
int esLetra(char str[])
{
  int cont = 0;
  while(str[cont] != '\0')
  {
     if((str[cont] != ' ')&&(str[cont]<'a'||str[cont]>'z')&&(str[cont]<'A'||str[cont]>'Z'))
      {
        return 0;
      }
      cont++;
  }
  return 1;
}

void inicializarEstado(eCliente cli[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        cli[i].estado=0;
    }
}

int buscarLibre(eCliente cliente[],int tam)
{
    int retorno=-1;
    for(int i=0;i<tam;i++)
    {
        if(cliente[i].estado==0)
        {
            retorno=i;

        }

    }

    return retorno;
}

void altaCliente(eCliente cliente[],int id,int idc)
{
    char auxdni[50],auxNom[100],auxApe[100];
    int xdni;



     printf("\nIngrese DNI: ");
     fflush(stdin);
     gets(auxdni);
     system("pause");
     system("cls");
            while(esNumero(auxdni)==0)
            {
                printf("\nEl DNI debe ser solo numerico. Reingrese DNI: ");
                fflush(stdin);
                gets(auxdni);
                system("pause");
                system("cls");
            }
           xdni= atoi(auxdni);

     printf("\nIngrese Nombre: ");
     fflush(stdin);
     gets(auxNom);
     system("pause");
     system("cls");
            while(esLetra(auxNom)==0)
            {
                printf("\nEl Nombre debe ser solo letras. Reingrese nombre: ");
                fflush(stdin);
                gets(auxNom);
                system("pause");
                system("cls");
            }

     printf("\nIngrese Apellido: ");
     fflush(stdin);
     gets(auxApe);
     system("pause");
     system("cls");
            while(esLetra(auxApe)==0)
            {
                printf("\nEl Apellido debe ser solo letras. Reingrese Apellido: ");
                fflush(stdin);
                gets(auxApe);
                system("pause");
                system("cls");
            }
        cliente[idc].dni=xdni;
        strcpy(cliente[idc].nombre,auxNom);
        strcpy(cliente[idc].apellido,auxApe);
        cliente[idc].id=id;
        cliente[idc].estado=1;

        printf("\n------------------------------------------\n\n");
        printf("ID\tDNI\tAPELLIDO\tNOMBRE\n\n");

        printf("%d\t%d\t%s\t\t%s\n",cliente[idc].id,cliente[idc].dni,cliente[idc].apellido,cliente[idc].nombre);
        system("pause");
        system("cls");



  }
void modificarCliente(eCliente cliente[],int id,int idc)
{

    char auxdni[50],auxNom[100],auxApe[100];
    int xdni;

     printf("\n------------------------------------------\n\n");
        printf("ID\tDNI\tAPELLIDO\tNOMBRE\n\n");
        printf("%d\t%d\t%s\t\t%s\n\n\n",cliente[idc].id,cliente[idc].dni,cliente[idc].apellido,cliente[idc].nombre);


     printf("\nIngrese DNI: ");
     fflush(stdin);
     gets(auxdni);

            while(esNumero(auxdni)==0)
            {
                printf("\nEl DNI debe ser solo numerico. Reingrese DNI: ");
                fflush(stdin);
                gets(auxdni);

            }
           xdni= atoi(auxdni);

     printf("\nIngrese Nombre: ");
     fflush(stdin);
     gets(auxNom);

            while(esLetra(auxNom)==0)
            {
                printf("\nEl Nombre debe ser solo letras. Reingrese nombre: ");
                fflush(stdin);
                gets(auxNom);

            }

     printf("\nIngrese Apellido: ");
     fflush(stdin);
     gets(auxApe);

            while(esLetra(auxApe)==0)
            {
                printf("\nEl Apellido debe ser solo letras. Reingrese Apellido: ");
                fflush(stdin);
                gets(auxApe);

            }
        cliente[idc].dni=xdni;
        strcpy(cliente[idc].nombre,auxNom);
        strcpy(cliente[idc].apellido,auxApe);




        printf("\n\nCliente modificado..\n\n");
        system("pause");
        system("cls");


}

void nuevoAlquiler(eAlquiler alqui[],int idc)
{
    char auxid[50],auxEqui[30],auxtime[30],auxOpe[30];
    int xid,xtime;



     printf("\nIngrese ID: ");
     fflush(stdin);
     gets(auxid);
     system("pause");
     system("cls");
            while(esNumero(auxid)==0)
            {
                printf("\nEl ID debe ser solo numerico. Reingrese ID: ");
                fflush(stdin);
                gets(auxid);
                system("pause");
                system("cls");
            }
           xid= atoi(auxid);

     printf("\nIngrese Equipo: ");
     fflush(stdin);
     gets(auxEqui);
     system("pause");
     system("cls");
            while(esLetra(auxEqui)==0)
            {
                printf("\nEl Equipo debe ser solo letras. Reingrese equipo : ");
                fflush(stdin);
                gets(auxEqui);
                system("pause");
                system("cls");
            }

            printf("\nIngrese tiempo estimado (DIAS): ");
     fflush(stdin);
     gets(auxtime);
     system("pause");
     system("cls");
            while(esNumero(auxtime)==0)
            {
                printf("\nEl tiempo debe ser solo numerico. Reingrese tiempo estimado (DIAS): ");
                fflush(stdin);
                gets(auxtime);
                system("pause");
                system("cls");
            }
           xtime= atoi(auxtime);

     printf("\nIngrese Operador: ");
     fflush(stdin);
     gets(auxOpe);
     system("pause");
     system("cls");
            while(esLetra(auxOpe)==0)
            {
                printf("\nEl operador debe ser solo letras. Reingrese operador: ");
                fflush(stdin);
                gets(auxOpe);
                system("pause");
                system("cls");
            }

        alqui[idc].idCliente=xid;
        alqui[idc].tiempoEstmado=xtime;
        strcpy(alqui[idc].equipo,auxEqui);
        strcpy(alqui[idc].operador,auxOpe);
        strcpy(alqui[idc].estado,"ALQUILADO");

}
void finDeAlquiler(eAlquiler alqui[],int idc)
{
     char auxtime[50];
    int xtime;



     printf("\nIngrese tiempo real del alquiler (DIAS): ");
     fflush(stdin);
     gets(auxtime);
     system("pause");
     system("cls");
            while(esNumero(auxtime)==0)
            {
                printf("\nEl tiempo debe ser solo numerico. Reingrese tiempo real de alquiler: ");
                fflush(stdin);
                gets(auxtime);
                system("pause");
                system("cls");
            }
           xtime= atoi(auxtime);

     alqui[idc].tiempoReal=xtime;
     strcpy(alqui[idc].estado,"FINALIZADO");
}
void mostrarCliente(eCliente cli,eAlquiler alqui)
{
    printf("%d\t%s\t%s\t  %12s\t%s\n",cli.id,cli.apellido,cli.nombre,alqui.equipo,alqui.estado);
}
void mostrarClientes(eCliente cli[],eAlquiler alqui[],int tam)
{
    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)

        {
            if(cli[i].id==alqui[j].idCliente&&cli[i].estado==1)
            {

                mostrarCliente(cli[i],alqui[j]);
            }
        }
    }
}
void mostrarPromedioTimpoRal(eAlquiler alqui[],int tam)
{
    int acum=0;
    int cont=0;
    float promedio;
    for(int i=0;i<7;i++)
    {
        if(strcmp(alqui[i].estado,"FINALIZADO")==0)
        {
            acum+=alqui[i].tiempoReal;
            cont++;
        }
    }
    promedio=(float)acum/cont;

    printf("El Promedio del tiempo real es: %.2f \n\n",promedio);

}
void mostrarCliMasAlqui(eCliente cli[],eAlquiler alqui[],int tam)
{
    int max,flag=0,id;

    for(int i=0;i<tam;i++)
    {
        alqui[i].cant=0;
    }

    for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            if(cli[i].id==alqui[j].idCliente)
            {
                if(alqui[j].estado=="FINALIZADO"||alqui[j].estado=="alquilando")
                {
                    alqui[j].cant++;
                }
            }
        }
    }
    for(int i=0;i<tam;i++)
    {
        if(flag==0)
        {
            max=alqui[i].cant;
            flag=+1;
        }else{
            if(alqui[i].cant>max)
            {
                max=alqui[i].cant;
                id=i;
            }
        }

    }

        printf("--------------------------------------------------------------------\n");
        printf("-------------------CLIENTE CON MAS ALQUILERES-------------------------------\n\n");
        printf("NOMBRE\tAPELLIDO\tCANTIDAD\n");
for(int i=0;i<tam;i++)
    {
        for(int j=0;j<tam;j++)
        {
            if(j==id)
            {
                printf("%s\t%s\t%d\n",cli[i].nombre,cli[i].apellido,alqui[j].cant);
            }
        }

    }
}

