/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

struct
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;

}typedef Employee;

char menu(void);
Employee* employee_new(void);
int employee_setId(char *,Employee *);
int employee_getId(Employee *);
int employee_setName(char *,Employee *);
char *employee_getName(Employee *);
int employee_setLastName(char *,Employee *);
char *employee_getLastName(Employee *);
int employee_setIsEmpty(char *,Employee *);
int employee_getIsEmpty(Employee *);
void employee_print(Employee *);
void employee_printList(ArrayList* this);
ArrayList *employee_printListToFrom(ArrayList* this);
int employee_compare(void*,void*);
void employee_sort(ArrayList *);
void employee_add(ArrayList *);
void employee_delete(ArrayList *);
void employee_saveBin(ArrayList *);
void employee_saveCsv(ArrayList *);
void employee_eraseList(ArrayList *);

#endif // _EMPLOYEE_H



