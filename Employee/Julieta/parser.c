#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(char nombreArchivo[], ArrayList* pArrayListEmployee)
{

    Employee* aux;

    FILE* pFile;

    pFile = fopen(nombreArchivo,"r");

    int r;
    int i=0;
    char var1[50],var3[50],var2[50],var4[50];

    if(pFile == NULL)
    {
        printf("El archivo no existe");
        exit(EXIT_FAILURE);
    }
    do
    {
        aux = (Employee*) malloc(sizeof(Employee));//le asigna una dire de memoria cada vez que entra al while

        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4)
        {
            //printf("Lei: %s %s %s %s\n",var1,var2,var3,var4);

            (aux)->id = atoi(var1);
            strncpy((aux)->name,var2,sizeof((aux)->name));
            strncpy((aux)->lastName,var3,sizeof((aux)->lastName));

            if(strcmp(var4,"true"))
            {
                (aux)->isEmpty = 1;
            }
            else
            {
                (aux)->isEmpty = 0;

            }

            al_add(pArrayListEmployee, (aux));

            i++;

        }
        else
            break;
    }
    while(!feof(pFile));
    fclose(pFile);
    //exit(EXIT_SUCCESS);



    return 0;
}
