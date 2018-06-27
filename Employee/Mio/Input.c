#include "input.h"

//Brief: Chequea si el string ingresado es un numero
//Parameters: Un string
//Return: "0" si el string ingresado es un numero o "1" si no es un numero
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
//Brief: Chequea si el "from" esta incluido y si es valido
//Parameters: Un puntero Array List
//Return: "0" si no hay error o "1" si hay error
//
int checkFrom(ArrayList *this)
{
    int i, Num, isFloat, error=1, auxInt, returnAux=0;
    char aux[15];

    fflush(stdin);
    scanf("%s",aux);
    Num=isNum(aux);
    isFloat=intOrFloat(aux);
    auxInt=atoi(aux);
    for(i=0 ; i<this->len(this)-1 ; i++)
    {
        if(auxInt==employee_getId((Employee *)this->get(this,i)))
        {
            error=0;
            break;
        }
    }
    if(Num!=0 || isFloat!=0 || error!=0)
    {
        returnAux=-1;
    }
    else if(Num==0 && isFloat==0 && error==0)
    {
        returnAux=auxInt;
    }

    return returnAux;
}
//Brief: Chequea si el "to" esta incluido y si es valido
//Parameters: Un puntero Array List
//Return: "0" si no hay error o "1" si hay error
//
int checkTo(ArrayList *this, int from)
{
    int i, Num, isFloat, error=1, auxInt, returnAux=0;
    char aux[15];

    fflush(stdin);
    scanf("%s",aux);
    Num=isNum(aux);
    isFloat=intOrFloat(aux);
    auxInt=atoi(aux);
    for(i=from ; i<this->len(this) ; i++)
    {
        if(auxInt==employee_getId((Employee *)this->get(this,i)))
        {
            error=0;
            break;
        }
    }
    if(Num!=0 || isFloat!=0 || error!=0)
    {
        returnAux=-1;
    }
    else if(Num==0 && isFloat==0 && error==0)
    {
        returnAux=auxInt;
    }

    return returnAux;
}
//Brief: Chequea si el "ID" esta incluido y si es valido
//Parameters: Un puntero Array List
//Return: "0" si no hay error o "-1" si hay error
//
int checkID(ArrayList *this)
{
    int i, Num, isFloat, error=1, auxInt, returnAux=0;
    char aux[15];

    fflush(stdin);
    scanf("%s",aux);
    Num=isNum(aux);
    isFloat=intOrFloat(aux);
    auxInt=atoi(aux);
    for(i=0 ; i<this->len(this) ; i++)
    {
        if(auxInt==employee_getId((Employee *)this->get(this,i)))
        {
            error=0;
            break;
        }
    }
    if(Num!=0 || isFloat!=0 || error!=0)
    {
        returnAux=-1;
    }
    else if(Num==0 && isFloat==0 && error==0)
    {
        returnAux=auxInt;
    }

    return returnAux;
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
//Brief: Chequea si el string ingresado es inferior al tamanio ingresado
//Parameters: Un string nombre y un int tamanio
//Return: "0" si el string ingresado es correcto o "1" si hay error
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
