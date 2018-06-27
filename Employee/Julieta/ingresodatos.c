#include "ingresodatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

//INGRESO Y VALIDAR DATOS INGRESADOS

float IngresarEnteroFlotante(char mensaje[], int min, int max)
{
    char datoflot[15];
    float numero;
    int numerovalidado=0;

    do
    {
    printf("%s:\n", mensaje);
    gets(datoflot);

    numero = validarEnteroFlotante(datoflot, min, max, 15);//9999999.000000 14 son las colunas mas el espacio al final

    numerovalidado = RangoValidoFlotante(numero, min, max);


    }while(numerovalidado==0);


    return numero;
}


float validarEnteroFlotante(char datoflot[], int min, int max, int tam)
{
    float numeroflotante=0;
    int puntos=0;
    int esflotante=0;
    int contadordecimales=0;
    int cifraentero=0;


    int len;
    len = strlen(datoflot);

    do
    {
        for (int i=0; i<len; i++)
        {
            if(!(isdigit(datoflot[i])))
            {
                if((datoflot[i] == '.') && puntos < 1)
                {
                    puntos++;

                    cifraentero=i;

                    if (cifraentero>7)
                    {
                        esflotante=0;
                        printf("Ha superado la el tamano del entero permitido\n");
                        break;

                    }

                }
                else
                {
                    esflotante=0;
                    break;
                }
            }

            else
            {
                esflotante=1;

            }



        if(puntos == 1)
            {
                contadordecimales++;

                if(contadordecimales>6 || contadordecimales < 1 )
                {
                    esflotante=0;
                    printf("Error en cantidad de los decimales\n");
                    break;

                }
            }

        }

        if(esflotante==0)
        {
            printf("Dato no v%clido reingresar:\n", 160, min, max);
            gets(datoflot);
            len = strlen(datoflot);
            puntos=0;
            contadordecimales=0;

        }


    }while(esflotante ==0);

    numeroflotante = atof(datoflot);

    return numeroflotante;

}


int  RangoValidoFlotante(float numero, int min, int max)
{

    int validacion=0;

    if ( numero >= min && numero <= max)
        {
        validacion=1;
        }
    else{
            printf("Fuera de Rango ");
        }

        return validacion;
}




//ENTEROS



int IngresarEntero(char mensaje[], int min, int max)
{
    char entero[6];
    int numero;
    int numerovalidado=0;

    do
    {
    printf("%s", mensaje);
    fflush(stdin);
    gets(entero);

    numero = validarEntero(entero, min, max, 6);//

    numerovalidado = validarRangoEntero(numero, min, max);


    }while(numerovalidado==0);



    return numero;
}




int validarRangoEntero (int dato, int min, int max)
{
   int datovalido=0;

    if(dato >= min && dato <= max)
    {

        datovalido=1;

    }
    else{
            printf("Fuera de Rango ");
        }

    return datovalido;

}


float validarEntero(char dato[], int min, int max, int tam)
{
    int numero=0;
    int esentero=0;


    int len;
    len = strlen(dato);

    do
    {
        for (int i=0; i<len; i++)
        {
            if(!(isdigit(dato[i])))
            {
                    esentero=0;
                    break;
            }
            else
                {
               esentero=1;

            }
        }


        if(esentero==0)
        {
            printf("Dato no v%clido reingresar:\n", 160, min, max);
            gets(dato);
            len = strlen(dato);

        }


    }while(esentero ==0);

    numero = atoi(dato);

    return numero;

}

void getString(char mensaje[],char input[], int min, int max)
{
    int len;
    int valido=0;

    do
    {
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);

    len = strlen(input);
    if(len < min || len > max)
    {
        printf("Error,");
    }
    else
    {
       valido =1 ;

    }
    }
    while(valido ==0);

}

void getStringletras(char mensaje[],char input[], int min, int max)
{
        int estex=0;
        do
        {
        getString(mensaje, input, min,max);

        estex = esTexto(input);

        if (estex == 0)
        {
            printf("Error, ingresar %cnicamente letras", 163);
        }

        }
        while (estex == 0);
}


void getStringEntero(char mensaje[],char input[], int min, int max)
{
        int esnum=0;
        do
        {
        getString(mensaje, input, min,max);

        esnum = esNumero(input);

        if (esnum == 0)
        {
            printf("Error, ingresar %cnicamente n%cmeros", 163, 163);
        }

        }
        while (esnum == 0);
}







int esTexto(char texto[])
{

    int estexto = 0;

    int len = strlen(texto);

    for (int i=0; i<len; i++)
    {
        if (isalpha(texto[i]) || isspace(texto[i]))
        {
            estexto = 1;
        }
        else
        {

            estexto = 0;
            break;

        }



    }

    return estexto;

}




int esNumero(char numero[])
{

    int esnum = 0;

    int len = strlen(numero);

    for (int i=0; i<len; i++)
    {
        if (isdigit(numero[i]))
        {
            esnum = 1;
        }
        else
        {

            esnum = 0;
            break;

        }



    }

    return esnum;

}

int Confirmacion(char mensaje[])
{
     char confirma;
     int retorno=0;

      printf("\n.....................................................");


     printf("\n%s s/n: ", mensaje);



     confirma= getche();
     confirma= tolower(confirma);


     if(confirma == 's')
     {
         retorno=1;

     }

     return retorno;

}


