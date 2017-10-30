#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    Employee* auxEmpleado;
    char auxId[5];
    char auxNombre[51];
    char auxApellido[51];
    char auxEmpty[6];
    if(pFile != NULL && pArrayListEmployee != NULL){

        fscanf(pFile, "%[^,], %[^,], %[^,], %s\n", auxId, auxNombre, auxApellido, auxEmpty);

        while(!feof(pFile)){

            fscanf(pFile, "%[^,], %[^,], %[^,], %s\n", auxId, auxNombre, auxApellido, auxEmpty);

            auxEmpleado = employee_new();
            if(auxEmpleado !=NULL){
                auxEmpleado->id = atoi(auxId);
                strcpy(auxEmpleado->name, auxNombre);
                strcpy(auxEmpleado->lastName, auxApellido);
                if(strcmp(auxEmpty, "false")== 0){

                    auxEmpleado->isEmpty = 0;
                }
                else{
                     auxEmpleado->isEmpty = 1;
                }

                pArrayListEmployee->add(pArrayListEmployee, auxEmpleado);
            }

        }





    }



    return 0;
}
