#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char menu(void);
char submenu(void);
int isLwrThan(char [],int);
char *formatName(char *);
int isNum(char []);
int intOrFloat(char []);
char isThat(char,char,char);
int esCero(char []);


#endif // INPUT_H_INCLUDED
