#include "Input.h"

//Brief: Menu de opciones del main
//Parameters: Void
//Return: Devuelve un char correspondiente a la opcion elegida.
//
char menu(void)
{
    char opcion;

    printf(" 1) Agregar pelicula\n");
    printf(" 2) Borrar pelicula\n");
    printf(" 3) Modificar pelicula\n");
    printf(" 4) Generar pagina web\n");
    printf(" 5) Salir\n\n\n");
    printf("Opcion ingresada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
//Brief: Menu de opciones de modMovie
//Parameters: Void
//Return: Devuelve un char correspondiente a la opcion elegida.
//
char submenu(void)
{
    char opcion;

    system("cls");
    printf("Seleccione que desea modificar\n\n");
    printf(" 1 - Titulo\n");
    printf(" 2 - Genero\n");
    printf(" 3 - Duracion\n");
    printf(" 4 - Descripcion\n");
    printf(" 5 - Puntaje\n");
    printf(" 6 - Url\n");
    printf(" 7 - Atras\n\n\n");
    printf("Opcion ingresada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
//Brief: Chequea si el string ingresado tiene como maximo tantos caracteres como indicado por tam
//Parameters: Un string y el tamanio
//Return: Devuelve un "0" si no hay errores o "1" si hay.
//
int isLwrThan(char nombre[], int tam)
{
    int error=1;

    if(strlen(nombre)<=tam)
    {
        error=0;
    }

    return error;
}
//Brief: Formatea un string de nombre todo a minuscula e iniciales mayusculas
//Parameters: Un puntero a string
//Return: El mismo puntero a string
//
char *formatName(char *nombre)
{
    int i;

    strlwr(nombre);
    for(i=0 ; nombre[i]!='\0' ; i++)
    {
        if(i==0)
        {
            nombre[i]=toupper(nombre[i]);
        }
        if(nombre[i]==' ')
        {
            nombre[i+1]=toupper(nombre[i+1]);
        }
    }

    return nombre;
}
//Brief: Chequea si el string ingresado es un entero
//Parameters: Un string
//Return: "0" si el string ingresado es un entero o "1" si no es un entero
//
int isNum(char aux[])
{
    int i, error=0, cont=0, soyUnPosibleFloat=0;

    for(i=0 ; i<strlen(aux) ; i++)
    {
        if(aux[i]=='.')
        {
            cont=cont+1;
        }
        if(cont==1)
        {
            soyUnPosibleFloat=1;
        }
    }
    for(i=0 ; i<strlen(aux) ; i++)
    {
        if(!isdigit(aux[i]))
        {
            if(soyUnPosibleFloat==1)
            {
                soyUnPosibleFloat=0;
                continue;
            }
            error=1;
            break;
        }
    }

    return error;
}
//Brief: Cuenta la cantidad de puntos en un string
//Parameters: Un string
//Return: Devuelve el numero de puntos
//
int intOrFloat(char aux[])
{
    int i, cont=0;

    for(i=0 ; aux[i]!='\0' ; i++)
    {
        if(aux[i]=='.')
        {
          cont++;
        }
    }

    return cont;
}
//Brief: Chequea si source es distinto a los 2 char a y b
//Parameters: 1 char source y 2 char a y b al que compararlo con source
//Return: Devuelve el char source
//
char isThat(char source,char a, char b)
{
    source=tolower(source);
    a=tolower(a);
    b=tolower(b);
    while(source!=a&&source!=b)
    {
        printf("\nError, vuelva a ingresar\n");
        fflush(stdin);
        scanf("%c",&source);
        source=tolower(source);
    }

    return source;
}
//Brief: Chequea si aux es un cero
//Parameters: 1 string
//Return: Devuelve "1" si es cero o "0" si no lo es
//
int esCero(char aux[])
{
    int res=0, i;

    for(i=0 ; aux[i]!='\0' ; i++)
    {
        if(aux[i]=='0')
        {
          res=1;
        }
    }

    return res;
}
