#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int main()
{

    FILE* F;
    F = fopen("Prueba.txt","w");
    if (F == NULL)
    {
        printf("No se pudo crear el fichero.");
        exit(1);
    }

    fprintf(F, "Aeaeae\n");
    fclose(F);


    return 0;
}*/

/*
int main()
{
    char cadena[] = {"Japish"};
    int cant = strlen(cadena);
    int escritos;

    FILE* F;

    if (F == NULL)
    {
        printf("No se pudo crear el fichero.");
        exit(1);
    }
    F = fopen("Prueba.txt","w");

    escritos = fwrite(cadena, sizeof(char), cant, F);
    if (escritos < cant)
    {
            printf("Problema al escribir en el fichero.\n");
    }

    fclose(F);


    return 0;
}*/
/*
int main()
{
    char x;



    FILE* F;

    if (F == NULL)
    {
        printf("No se pudo crear el fichero.");
        exit(1);
    }
    F = fopen("Prueba.txt","r");


    while (x != EOF)
    {
        x = fgetc(F);

        printf("%c",x);
    }

    fclose(F);
    return 0;
}
*/




int main()
{


    char carga[] = {"Japish jejeeeerp"};

    FILE* F;

    if (F == NULL)
    {
        printf("No se pudo crear el fichero.");
        exit(1);
    }
    F = fopen("Prueba.txt","r");


    while (!feof(F))
    {
        fgets(carga, 50, F);

        printf("%s", carga);
    }

    fclose(F);
    return 0;
}

