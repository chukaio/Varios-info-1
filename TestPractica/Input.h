#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Employee.h"

int isNum(char []);
int intOrFloat(char []);
char isThat(char,char,char);
int checkFrom(ArrayList *);
int checkTo(ArrayList *,int);
int checkID(ArrayList *);
char *formatName(char *);
int isLwrThan(char [],int);

#endif // INPUT_H_INCLUDED

