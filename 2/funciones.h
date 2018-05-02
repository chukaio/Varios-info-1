//Include y define
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define CANT 20

//Estructuras
typedef struct
{
    char nombre[30];
    int edad;
    int dni;
    int estado;
}ePersona;

//Funciones
void initPersona (ePersona[] , int);
int srchEspacio (ePersona[] , int);
void newPersona (ePersona[] , int);
void clrPersona (ePersona[] , int);
void orderPersona(ePersona[] , int);
void prntPersona (ePersona[] , int);
void fillTable (ePersona[] , int);
void prntEdades (char[20][3]);

