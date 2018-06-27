#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"

//Brief: Parsea una lista a partir de un archivo .csv
//Parameters: Array List
//Return: "-1" si el puntero Array List ingresado es NULL o "0" si esta bien
//
int parserEmployee(ArrayList* pArrayListEmployee)
{
    int returnAux=-1, cant, error1, error2, error3, error4;
    char buffer1[100], buffer2[100], buffer3[100], buffer4[100];
    Employee *emp, *aux=employee_new();
    FILE *pFile;

    if(pArrayListEmployee!=NULL)
    {
        pFile=fopen("data.csv","r");
        if(pFile==NULL)
        {
            printf("Error\n");
            returnAux=-1;
        }
        else
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer1,buffer2,buffer3,buffer4);
            while(!feof(pFile))
            {
                cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer1,buffer2,buffer3,buffer4);
                if(cant!=4)
                {
                    if(feof(pFile))
                    {
                        break;
                    }
                    else
                    {
                        exit(1);
                    }
                }
                else
                {
                    emp=employee_new();
                    error1=employee_setId(buffer1,aux);
                    if(error1==-1)
                    {
                        returnAux=-1;
                    }
                    else
                    {
                        error2=employee_setName(buffer2,aux);
                        if(error2==-1)
                        {
                            returnAux=-1;
                        }
                        else
                        {
                            error3=employee_setLastName(buffer3,aux);
                            if(error3==-1)
                            {
                                returnAux=-1;
                            }
                            else
                            {
                                error4=employee_setIsEmpty(buffer4,aux);
                                if(error4==-1)
                                {
                                    returnAux=-1;
                                }
                            }
                        }
                    }
                    if(error1!=-1 && error2!=-1 && error3!=-1 && error4!=-1)
                    {
                        *emp=*aux;
                        pArrayListEmployee->add(pArrayListEmployee,emp);
                    }
                    returnAux=0;
                }
            }
        }
    }

    fclose(pFile);
    return returnAux;
}
