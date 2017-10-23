
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

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

int esLetra(char[]);
int esNumero(char[]);
int largodecadena(char[],int);
void inicializarEstado(eCliente[],int);
int buscarLibre(eCliente[],int);
void altaCliente(eCliente[],int,int);
void modificarCliente(eCliente[],int,int);
void nuevoAlquiler(eAlquiler[],int);
void finDeAlquiler(eAlquiler[],int);
void mostrarPromedioTimpoRal(eAlquiler[],int);
void mostrarCliMasAlqui(eCliente[],eAlquiler[],int);
#endif
