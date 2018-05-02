#include "funciones.h"

//
void initPersona (ePersona alumno[], int cant)
{
    for (int i=0 ; i<cant ; i++)
    {
        alumno[i].estado=0;
    }
}

//
int srchEspacio (ePersona alumno[], int cant)
{
    int indice, agendaLlena=1;

    for (int i=0 ; i<cant ; i++)
    {
        if (alumno[i].estado==0)
        {
            indice=i;
            agendaLlena=0;
            break;
        }
    }
    if (agendaLlena==1)
    {
        indice=-1;
    }

    return indice;
}

//
void newPersona (ePersona alumno[], int indice)
{
    printf("Ingrese nombre\n   ");
    fflush(stdin);
    scanf("%[^\n]",alumno[indice].nombre);
    strlwr(alumno[indice].nombre);
    for(int i=0 ; alumno[indice].nombre[i]!='\0' ; i++)
    {
        if(i==0)
        {
            alumno[indice].nombre[i]=toupper(alumno[indice].nombre[i]);
        }
        if(alumno[indice].nombre[i]==' ')
        {
            alumno[indice].nombre[i+1]=toupper(alumno[indice].nombre[i+1]);
        }
    }
    printf("\nIngrese edad\n   ");
    scanf("%d",&alumno[indice].edad);
    //Validar que sea edad
    printf("\nIngrese DNI\n   ");
    scanf("%d",&alumno[indice].dni);
    //Validar que sea dni y no letras.
    system("cls");
    alumno[indice].estado=1;
}

//
void clrPersona (ePersona alumno[], int cant)
{
    char rta;

    for (int i=0 ; i<cant ; i++)
    {
        if (alumno[i].estado==1)
        {
            printf("---Entrada %d:\n",i+1);
            printf("Nombre: %s\n",alumno[i].nombre);
            printf("Edad: %d\n",alumno[i].edad);
            printf("Dni: %d\n\n",alumno[i].dni);
            printf("Desea borrar esta entrada? s/n\n");
            fflush(stdin);
            scanf("%c",&rta);
            while ( rta!='s'&&rta!='n' )
            {
                printf("Ingrese respuesta correctamente s/n\n");
                fflush(stdin);
                scanf("%c",&rta);
            }
            if (rta=='s')
            {
                alumno[i].estado=0;
                break;
            }
            if ( i==(cant-1)&&rta=='n' )
            {
                printf("Ha llegado al fin de la agenda\n\n");
                printf("Desea volver al inicio?");
                fflush(stdin);
                scanf("%c",&rta);
                while ( rta!='s'&&rta!='n' )
                {
                    printf("Ingrese respuesta correctamente s/n\n");
                    fflush(stdin);
                    scanf("%c",&rta);
                }
                if ( rta=='s' )
                {
                    i=0;
                }
                else
                {
                    break;
                }
            }
        }
    }
    system("cls");
}
void orderPersona(ePersona alumno[] , int cant)
{
    ePersona aux;

    for(int i=0 ; i<cant-1 ; i++)
    {
        for(int j=i+1 ; j<cant ; j++)
        {
            if( strcmp(alumno[i].nombre,alumno[j].nombre)>0 )
            {
                aux=alumno[i];
                alumno[i]=alumno[j];
                alumno[j]=aux;
            }
        }
    }
}
void prntPersona (ePersona alumno[] , int cant)
{
    int vacio=1, offset;
    char linea[50], aux[15];

    for (int i=0 ; i<cant ; i++)
    {
        if(alumno[i].estado!=0)
        {
            if(vacio==1)
            {
                printf("---------------------------------------------\n");
                printf("|NOMBRE                      |EDAD |DNI     |\n");
                printf("---------------------------------------------\n");
                vacio=0;
            }
            sprintf(linea,"|%s",alumno[i].nombre);
            offset=30-strlen(alumno[i].nombre);
            for(int j=0 ; j<offset-2 ; j++)
            {
                strcat(linea," ");
            }
            strcat(linea,"|");
            sprintf(aux,"%d",alumno[i].edad);
            strcat(linea,aux);
            offset=4-strlen(aux);
            for(int j=0 ; j<=offset ; j++)
            {
                strcat(linea," ");
            }
            strcat(linea,"|");
            sprintf(aux,"%d",alumno[i].dni);
            strcat(linea,aux);
            offset=8-strlen(aux);
            for(int j=0 ; j<offset ; j++)
            {
                strcat(linea," ");
            }
            strcat(linea,"|");
            printf("%s\n",linea);
        }
    }
    printf("---------------------------------------------\n");
}
void fillTable (ePersona alumno[] , int cant)
{
    char table[20][3];

    //Inicializo la tabla
    for(int i=0 ; i<20 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            table[i][j]='-';
        }
    }
    //Lleno la tabla
    for(int i=0 ; i<cant ; i++)
    {

        if(alumno[i].estado==1)
        {
            if(alumno[i].edad<18)
            {
                for(int j=0 ; j<cant ; j++)
                {
                    if(table[j][0]=='-')
                    {
                        table[j][0]='x';
                        break;
                    }
                }
            }
            else if(alumno[i].edad>35)
            {
                for(int j=0 ; j<cant ; j++)
                {
                    if(table[j][2]=='-')
                    {
                        table[j][2]='x';
                        break;
                    }
                }
            }
            else
            {
                for(int j=0 ; j<cant ; j++)
                {
                    if(table[j][1]=='-')
                    {
                        table[j][1]='x';
                        break;
                    }
                }
            }
        }
    }
    prntEdades(table);
}
void prntEdades (char table[20][3])
{
    int hayAlgo=0;

    for(int i=20 ; i>-1 ; i--)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(table[i][j]=='x' && hayAlgo==0)
            {
                hayAlgo=1;
                j=0;
            }
            if(hayAlgo==1)
            {
                if(table[i][j]=='x')
                {
                    printf("  %c  ",table[i][j]);
                }
                else
                {
                    printf("     ");
                }
                if(j==2)
                {
                    printf("\n");
                }
            }
        }
    }
    printf(" <18 19-35 >35\n");
}
