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


int main()
{
    int n, seguir=1;
    char opcion;
    ArrayList *this=al_newArrayList();

    printf("---------------------------------------\n");
    printf("|                                     |\n");
    printf("|         BIENVENIDO AL TP4           |\n");
    printf("|                                     |\n");
    printf("---------------------------------------\n\n\n");
    do
    {
        printf("Elija una de las siguientes opciones\n\n");
        opcion=menu();
        while(opcion<49||opcion>56||isdigit(opcion)==0)
        {
            system("cls");
            printf("Ingrese correctamente una de las siguientes opciones\n\n");
            opcion=menu();
        }
        switch(opcion)
        {
            case '1':
            {
                system("cls");
                printf("--Parser de data.csv--\n");
                n=parserEmployee(this);
                if(n==-1)
                {
                    printf("Error\n");
                    exit(1);
                }
                else
                {
                    printf("\n--Parser Exitoso!\n\n");
                }
                system("pause");
                system("cls");
                break;
            }
            case '2':
            {
                system("cls");
                printf("--Listado de empleados--\n\n");
                employee_printList(this);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '3':
            {
                system("cls");
                printf("--Listado Ordenada por nombre--\n\n");
                employee_sort(this);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '4':
            {
                system("cls");
                printf("--Agregar empleado--\n\n");
                employee_add(this);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '5':
            {
                system("cls");
                printf("--Eliminar empleado--\n\n");
                employee_delete(this);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '6':
            {
                system("cls");
                printf("--Listado de empleados desde/hasta--\n\n");
                employee_printListToFrom(this);
                //this=employee_printListToFrom(this);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '7':
            {
                system("cls");
                printf("--Borrando toda la lista--\n\n");
                employee_eraseList(this);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '8':
            {
                system("cls");
                printf("--Saliendo de la base de datos--\n\n");
                //employee_saveBin(this); //Binario
                employee_saveCsv(this); //Csv
                seguir=0;
                break;
            }
        }
    }
    while(seguir==1);

    return 0;
}
