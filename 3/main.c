#include "Funciones.h"
int main()
{
    int seguir=1, n;
    char opcion;

    printf("---------------------------------------\n");
    printf("|                                     |\n");
    printf("|         BIENVENIDO AL TP3           |\n");
    printf("|                                     |\n");
    printf("---------------------------------------\n\n\n");
    do
    {
        printf("Elija una de las siguientes opciones\n\n");
        opcion=menu();
        while(opcion<49||opcion>53||isdigit(opcion)==0)
        {
            system("cls");
            printf("Ingrese correctamente una de las siguientes opciones\n\n");
            opcion=menu();
        }
        switch(opcion)
        {
            case '1':
            {
                addMovie();
                n=tamMovie();
                system("pause");
                system("cls");
                break;
            }
            case '2':
            {
                n=tamMovie();
                deleteMovie(n);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '3':
            {
                n=tamMovie();
                modMovie(n);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '4':
            {
                generateWeb(n);
                printf("\n\n");
                system("pause");
                system("cls");
                break;
            }
            case '5':
            {
                generateWeb(n);
                seguir=0;
                break;
            }

        }
    }
    while(seguir==1);

    return 0;
}
