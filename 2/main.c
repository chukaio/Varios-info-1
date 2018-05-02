#include "funciones.h"

int main()
{
    ePersona alumno[CANT];
    char seguir='s', opcion;
    int indice, contEntradas;


    initPersona(alumno,CANT);
    printf("---------------------------------------\n");
    printf("|                                     |\n");
    printf("|         BIENVENIDO AL TP2           |\n");
    printf("|                                     |\n");
    printf("---------------------------------------\n\n\n");
    do
    {
        printf("+++++++++Eliga una de las siguientes opciones [1-5]+++++++++\n\n\n");
        printf(" 1) Agregar una persona\n");
        printf(" 2) Borrar una persona\n");
        printf(" 3) Imprimir lista ordenada por nombre\n");
        printf(" 4) Imprimir grafico de edades\n");
        printf(" 5) Salir\n\n\n");
        printf("Opcion elegida: ");
        fflush(stdin);
        scanf("%c",&opcion);
        if(isdigit(opcion)==0)
        {
            printf("\n");
            printf(" ...INPUT ERROR...\n\n");
            break;
        }
        system("cls");
        while ( opcion<49||opcion>53 )
        {
            printf("+++++++++Eliga CORRECTAMENTE una de las siguientes opciones [1-5]+++++++++\n\n\n");
            printf(" 1) Agregar una persona\n");
            printf(" 2) Borrar una persona\n");
            printf(" 3) Imprimir lista ordenada por nombre\n");
            printf(" 4) Imprimir grafico de edades\n");
            printf(" 5) Salir\n\n\n");
            printf("Opcion elegida: ");
            fflush(stdin);
            scanf("%c",&opcion);
            if(isdigit(opcion)==0)
            {
                printf("\n");
                printf(" ...INPUT ERROR...\n\n");
                break;
            }
            system("cls");
        }
        switch(opcion)
        {
            case 49:
                {
                    indice=srchEspacio(alumno,CANT);
                    if (indice==-1)
                    {
                        printf("No hay espacio libre en agenda\n\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                    else
                    {
                        newPersona(alumno,indice);
                        break;
                    }
                }
            case 50:
                {
                    for (int i=0 ; i<CANT ; i++)
                    {
                        if(i==0)
                        {
                            contEntradas=0;
                        }
                        if(alumno[i].estado==1)
                        {
                            contEntradas++;
                        }
                    }
                    if (contEntradas!=0)
                    {
                        clrPersona(alumno,CANT);
                    }
                    else
                    {
                        printf("La agenda esta vacia, no hay nada que borrar\n\n");
                    }
                    system("pause");
                    system("cls");
                    break;
                }
            case 51:
                {
                    for (int i=0 ; i<CANT ; i++)
                    {
                        if(i==0)
                        {
                            contEntradas=0;
                        }
                        if(alumno[i].estado==1)
                        {
                            contEntradas++;
                        }
                    }
                    if(contEntradas==0)
                    {
                        printf("No hay nada que imprimir\n\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                    orderPersona(alumno,CANT);
                    prntPersona(alumno,CANT);
                    printf("\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
            case 52:
                {
                    contEntradas=0;
                    for(int i=0 ; i<CANT ; i++)
                    {
                        if(alumno[i].estado==0)
                        {
                            contEntradas++;
                        }
                    }
                    if(contEntradas==CANT)
                    {
                        printf("La agenda esta vacia, no hay estadistica que mostrar\n\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                    else
                    {
                        printf("La tabla de edades es la siguiente:\n\n");
                        fillTable(alumno,CANT);
                        printf("\n\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }
            case 53:
                {
                    seguir='n';
                    break;
                }
        }
    }
    while (seguir=='s');

    return 0;
}
