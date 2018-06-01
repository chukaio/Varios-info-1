#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "Input.h"
#define VACIO 1
#define LLENO 0

typedef struct
{
    int id;
    char titulo[50];
    char genero[15];
    int duracion;
    char descripcion[300];
    int puntaje;
    char url[200];
    int isEmpty;
}eMovie;

int tamMovie(void);
void initArrayMovie(eMovie *);
void setDataMovie(eMovie *);
void setURL(eMovie *);
void setID(int);
void addMovie(void);
void deleteMovie(int);
void modMovie(int);
void generateWeb(int);

#endif // FUNCIONES_H_INCLUDED
