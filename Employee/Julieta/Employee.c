#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include "ingresodatos.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
   int retorno=0;

   Employee* aux1= (Employee*)pEmployeeA;
   Employee* aux2= (Employee*)pEmployeeB;

   if(aux1!=NULL && aux2!=NULL)
   {
   if(strcmp(employee_getName(aux1),employee_getName(aux2))>0)
   {
       retorno=1;
       //printf("%s", (aux1->name));

   }
   /*if(employee_getId(aux1) != employee_getId(aux2))
   {
       retorno=1;
       printf("%s",employee_getName(aux1));

   }*/
   }else if(strcmp(employee_getName(aux1),employee_getName(aux2))<0)
   {
        retorno=-1;
   }

    return retorno;
}


void employee_print(Employee* this)
{
      printf("%10d\t%15s\t%15s\t%15d\t\n", this->id, this->name, this->lastName, this->isEmpty );

}

void employees_print_all(ArrayList* pArrayListEmployee)
{
  Employee* aux;
  int len;

  len=al_len(pArrayListEmployee);

  for (int i=0; i<len; i++)
  {
    aux = (Employee*)al_get(pArrayListEmployee, i);//apunta
    employee_print(aux);

  }

}


void employees_sort(ArrayList* pArrayListEmployee, int orden)
{

  al_sort(pArrayListEmployee,employee_compare,orden);

}


void employees_add(ArrayList* pArrayListEmployee)
{

 Employee* NuevoEmpleado = employee_new();

 if(NuevoEmpleado !=NULL)
 {
     getStringletras("Ingresar Nombre: ",NuevoEmpleado->name, 1, 25);
     getStringletras("Ingresar Apellido: ",NuevoEmpleado->lastName, 1, 25);
     NuevoEmpleado->isEmpty=1;
     NuevoEmpleado->id=pArrayListEmployee->size;



     al_add(pArrayListEmployee,NuevoEmpleado);

 }





}




Employee* employee_new(void)
{

    Employee* returnAux = NULL;

    returnAux =(Employee*)malloc(sizeof(Employee));

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{

    int id;

    id = (int) malloc(sizeof(int));

    if(this!=NULL)
    {
        id=this->id;
    }

    return id;
}

char* employee_getName(Employee* this)
{

    char* texto;

    texto = (char*)malloc(sizeof(char)*50);


    if(this!=NULL)
    {
        strcpy(texto,this->name);

    }

    return texto;
}


int employee_SetName(Employee* this, char* texto)
{
    int retorno =0;
    if(this!=NULL)
    {
        strcpy(this->name,texto);
        retorno =1;

    }

    return retorno;
}


