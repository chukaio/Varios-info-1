#include "Input.h"
#include "ArrayList.h"
#include "Employee.h"

//Brief: Menu de opciones del main
//Parameters: Void
//Return: Char de la opcion elegida
//
char menu(void)
{
    char opcion;

    printf(" 1) Parse del archivo data.csv\n");
    printf(" 2) Listar Empleados\n");
    printf(" 3) Ordenar por nombre\n");
    printf(" 4) Agregar un elemento\n");
    printf(" 5) Elimina un elemento\n");
    printf(" 6) Listar Empleados (Desde/Hasta)\n");
    printf(" 7) Borrar lista\n");
    printf(" 8) Salir\n\n\n");
    printf("Opcion ingresada: ");
    fflush(stdin);
    scanf("%c",&opcion);

    return opcion;
}
//Brief: Inicializa un puntero Employee
//Parameters: Void
//Return: la dir de memoria de la estructura Employee o NULL si da error el malloc
//
Employee* employee_new(void)
{
    Employee *returnAux=NULL;

    returnAux=(Employee *)malloc(sizeof(Employee)*1);
    if(returnAux==NULL)
    {
        printf("Error\n");
    }

    return returnAux;
}
//Brief: Setea el campo id a un puntero Employee
//Parameters: Un string con el set incluido y un puntero Employee
//Return: "-1" si el puntero Buffer ingresado es NULL o "0" si esta bien
//
int employee_setId(char *buffer, Employee *location)
{
    int aux, returnAux=-1;

    if(buffer!=NULL)
    {
        aux=atoi(buffer);
        location->id=aux;
        returnAux=0;
    }

    return returnAux;
}
//Brief: Obtiene el campo id de un puntero Employee
//Parameters: Un puntero Employee
//Return: "-1" si el puntero ingresado es NULL o el campo del puntero si esta bien
//
int employee_getId(Employee *emp)
{
    int returnAux=-1;

    if(emp!=NULL)
    {
        returnAux=emp->id;
    }

    return returnAux;
}
//Brief: Setea el campo name a un puntero Employee
//Parameters: Un string con el set incluido y un puntero Employee
//Return: "-1" si el puntero Buffer ingresado es NULL o "0" si esta bien
//
int employee_setName(char *buffer, Employee *location)
{
    int tam, returnAux=-1;

    if(buffer!=NULL)
    {
        tam=strlen(buffer);
        if(tam>50)
        {
            printf("Error\n");
            returnAux=-1;
        }
        else
        {
            strcpy(location->name,buffer);
            returnAux=0;
        }
    }

    return returnAux;
}
//Brief: Obtiene el name name de un puntero Employee
//Parameters: Un puntero Employee
//Return: "NULL" si el puntero ingresado es NULL o el campo del puntero si esta bien
//
char *employee_getName(Employee *emp)
{
    char *returnAux=NULL;

    if(emp!=NULL)
    {
       returnAux=emp->name;
    }

    return returnAux;
}
//Brief: Setea el campo lastName a un puntero Employee
//Parameters: Un string con el set incluido y un puntero Employee
//Return: "-1" si el puntero Buffer ingresado es NULL o "0" si esta bien
//
int employee_setLastName(char *buffer, Employee *location)
{
    int tam, returnAux=-1;

    if(buffer!=NULL)
    {
        tam=strlen(buffer);
        if(tam>50)
        {
            printf("Error\n");
            returnAux=-1;
        }
        else
        {
            strcpy(location->lastName,buffer);
            returnAux=0;
        }
    }

    return returnAux;
}
//Brief: Obtiene el campo lastName de un puntero Employee
//Parameters: Un puntero Employee
//Return: "NULL" si el puntero ingresado es NULL o el campo del puntero si esta bien
//
char *employee_getLastName(Employee *emp)
{
    char *returnAux=NULL;

    if(emp!=NULL)
    {
        returnAux=emp->lastName;
    }

    return returnAux;
}
//Brief: Setea el campo isEmpty a un puntero Employee
//Parameters: Un string con el set incluido y un puntero Employee
//Return: "-1" si el puntero Buffer ingresado es NULL o "0" si esta bien
//
int employee_setIsEmpty(char *buffer, Employee *location)
{
    int aux, returnAux=-1;

    if(buffer!=NULL)
    {
        if(strcmp(buffer,"true")==0)
        {
            aux=1;
            location->isEmpty=aux;
        }
        else if(strcmp(buffer,"true")!=0)
        {
            aux=0;
            location->isEmpty=aux;
        }
        returnAux=0;
    }

    return returnAux;
}
//Brief: Obtiene el campo isEmpty de un puntero Employee
//Parameters: Un puntero Employee
//Return: "-1" si el puntero ingresado es NULL o el campo del puntero si esta bien
//
int employee_getIsEmpty(Employee *emp)
{
    int returnAux=-1;

    if(emp!=NULL)
    {
        returnAux=emp->isEmpty;
    }

    return returnAux;
}
//Brief: Printea el contenido del pruntero Employee
//Parameters: Un puntero Employee
//Return: Void
//
void employee_print(Employee *emp)
{
    int res;
    char auxName[100];
    char auxLastName[100];

    if(emp!=NULL)
    {
        strcpy(auxName,employee_getName(emp));
        strcpy(auxLastName,employee_getLastName(emp));
        printf("|%2d|%-8s|%-10s|",employee_getId(emp),auxName,auxLastName);
        res=employee_getIsEmpty(emp);
        if(res==1)
        {
            printf("VACIO |\n");
        }
        else if(res==0)
        {
            printf("LLENO |\n");
        }
    }
}
//Brief: Printea el contenido del puntero Array List
//Parameters: Un puntero Array List
//Return: Void
//
void employee_printList(ArrayList* this)
{
    int i;
    Employee *emp=NULL;

    if(this!=NULL && this->isEmpty(this)==0)
    {
        printf("-------------------------------\n");
        printf("|ID| NOMBRE | APELLIDO |ESTADO|\n");
        printf("-------------------------------\n");
        for(i=0 ; i<this->len(this) ; i++)
        {
            emp=(Employee *)this->get(this,i);
            employee_print(emp);
        }
        printf("-------------------------------\n");
    }
    else if(this->isEmpty(this)==1)
    {
        printf("Base de datos vacia, favor de parsearla primero!\n");
    }
}
//Brief: Printea el contenido del puntero Array List
//Parameters: Un puntero Array List
//Return: Un puntero Array List
//
ArrayList *employee_printListToFrom(ArrayList* this)
{
    int i, from, to, auxInt;
    Employee *emp=NULL;
    ArrayList *this2=al_newArrayList();

    if(this!=NULL && this->isEmpty(this)==0)
    {
        system("cls");
        printf("--Listado de empleados desde/hasta--\n\n");
        printf("Ingrese desde que ID desea listar\n\n");
        printf("Opcion ingresada: ");
        auxInt=checkFrom(this);
        while(auxInt==-1)
        {
            system("cls");
            printf("--Listado de empleados desde/hasta--\n\n");
            printf("Error, ingrese desde que ID desea listar\n\n");
            printf("Opcion ingresada: ");
            auxInt=checkFrom(this);
        }
        from=auxInt;
        from--;
        printf("\nIngrese hasta que ID desea listar\n\n");
        printf("Opcion ingresada: ");
        auxInt=checkTo(this,from);
        while(auxInt==-1)
        {
            system("cls");
            printf("--Listado de empleados desde/hasta--\n\n");
            printf("Error, ingrese hasta que ID desea listar\n\n");
            printf("Opcion ingresada: ");
            auxInt=checkTo(this,from);
        }
        to=auxInt;
        to--;
        this2=this->subList(this,from,to);
        printf("\n-------------------------------\n");
        printf("|ID| NOMBRE | APELLIDO |ESTADO|\n");
        printf("-------------------------------\n");
        for(i=0 ; i<this->len(this2) ; i++)
        {
            emp=(Employee *)this->get(this2,i);
            employee_print(emp);
        }
        printf("-------------------------------\n\n");
        this=this->clone(this2);
    }
    else if(this->isEmpty(this)==1)
    {
        printf("Base de datos vacia, favor de parsearla primero!\n");
    }

    return this;
}
//Brief: Compara el campo nombre de cada puntero
//Parameters: Dos punteros Employee (emp1 y emp2)
//Return: Un entero de acuerdo al caso de comparacion ("1" si emp2 es menor que emp1, "-1" si emp1 es menor que emp2 o "0" si emp1 es igual a emp2) o "-2" en caso de error.
//
int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int returnAux=-2;
    Employee *emp1=employee_new(), *emp2=employee_new();

    if(pEmployeeA!=NULL && pEmployeeB!=NULL)
    {
        emp1=(Employee *)pEmployeeA;
        emp2=(Employee *)pEmployeeB;
        if(strcmp(employee_getName(emp1),employee_getName(emp2))>0)
        {
            returnAux=1;
        }
        else if(strcmp(employee_getName(emp1),employee_getName(emp2))<0)
        {
            returnAux=-1;
        }
        else
        {
            returnAux=0;
        }
    }
    if(returnAux==-2)
    {
        printf("Error!\n");
        exit(1);
    }

    return returnAux;
}
//Brief: Ordena por el campo nombre a a lista contenida en el punteo Array List
//Parameters: Un puntero Array List
//Return: Void
//
void employee_sort(ArrayList *this)
{
    if(this!=NULL && this->isEmpty(this)==0)
    {
        this->sort(this,employee_compare,1);
        printf("Ordenamiento exitoso!\n");
    }
    else if(this->isEmpty(this)==1)
    {
        printf("Base de datos vacia, favor de parsearla primero!\n");
    }
}
//Brief: Agrega el contenido del puntero Employee contenido en el puntero Array List
//Parameters: Un puntero Array List
//Return: Void
//
void employee_add(ArrayList *this)
{
    int i, error;
    char buffer[500], auxInt[5];
    Employee *emp=employee_new();

    if(this!=NULL && this->isEmpty(this)==0) //this es no nulo y la lista NO esta vacia
    {
        system("cls");
        printf("--Agregar empleado--\n\n");
        printf("Ingrese nombre\n\n");
        fflush(stdin);
        scanf("%[^\n]",buffer);
        error=isLwrThan(buffer,51);
        while(error==1)
        {
            system("cls");
            printf("--Agregar empleado--\n\n");
            printf("Ingrese nombre\n\n");
            fflush(stdin);
            scanf("%[^\n]",buffer);
            error=isLwrThan(buffer,51);
        }
        strcpy(buffer,formatName(buffer));
        strcpy(emp->name,buffer);
        printf("\nIngrese apellido\n\n");
        fflush(stdin);
        scanf("%[^\n]",buffer);
        error=isLwrThan(buffer,51);
        while(error==1)
        {
            system("cls");
            printf("--Agregar empleado--\n\n");
            printf("\nIngrese apellido\n\n");
            scanf("%[^\n]",buffer);
            error=isLwrThan(buffer,51);
        }
        strcpy(buffer,formatName(buffer));
        strcpy(emp->lastName,buffer);
        employee_setIsEmpty("false",emp);
        for(i=0 ; i<this->len(this) ; i++)
        {
            if(i+1==((Employee *)(this->get(this,i)))->id)
            {
                if(i==this->len(this)-1)
                {
                    sprintf(auxInt,"%d",i+2);
                    employee_setId(auxInt,emp);
                    this->add(this,emp);
                    printf("\nEmpleado agregado con exito!\n");
                    break;
                }
                continue;
            }
            else
            {
                sprintf(auxInt,"%d",i+1);
                employee_setId(auxInt,emp);
                this->push(this,i,emp);
                printf("\nEmpleado agregado con exito!\n");
                break;
            }
        }
    }
    else if(this!=NULL && this->isEmpty(this)==1) //this es no nulo y la lista esta vacia
    {
        system("cls");
        printf("--Agregar empleado--\n\n");
        printf("Ingrese nombre\n\n");
        fflush(stdin);
        scanf("%[^\n]",buffer);
        error=isLwrThan(buffer,51);
        while(error==1)
        {
            system("cls");
            printf("--Agregar empleado--\n\n");
            printf("Ingrese nombre\n\n");
            fflush(stdin);
            scanf("%[^\n]",buffer);
            error=isLwrThan(buffer,51);
        }
        strcpy(buffer,formatName(buffer));
        strcpy(emp->name,buffer);
        printf("\nIngrese apellido\n\n");
        fflush(stdin);
        scanf("%[^\n]",buffer);
        error=isLwrThan(buffer,51);
        while(error==1)
        {
            system("cls");
            printf("--Agregar empleado--\n\n");
            printf("\nIngrese apellido\n\n");
            scanf("%[^\n]",buffer);
            error=isLwrThan(buffer,51);
        }
        strcpy(buffer,formatName(buffer));
        strcpy(emp->lastName,buffer);
        employee_setIsEmpty("false",emp);
        sprintf(auxInt,"1");
        employee_setId(auxInt,emp);
        this->add(this,emp);
        printf("\nEmpleado agregado con exito!\n");
    }
    else if(this==NULL) //this ES nulo
    {
        printf("Error!\n");
    }
}
//Brief: Borra el contenido del puntero Employee contenido en el puntero Array List
//Parameters: Un puntero Array List
//Return: Void
//
void employee_delete(ArrayList* this)
{
    int i, id, index;
    char opcion;
    Employee *emp=employee_new();

    if(this!=NULL && this->isEmpty(this)==0)
    {
        system("cls");
        printf("--Eliminar empleado--\n\n");
        printf("Ingrese el ID del empleado a borrar\n\n");
        printf("Opcion ingresada: ");
        id=checkID(this);
        while(id==-1)
        {
            system("cls");
            printf("--Eliminar empleado--\n\n");
            printf("Ingrese el ID del empleado a borrar\n\n");
            printf("Opcion ingresada: ");
            id=checkID(this);
        }
        for(i=0 ; i<this->len(this) ; i++)
        {
            if(id==employee_getId((Employee *)this->get(this,i)))
            {
                index=i;
                break;
            }
        }
        printf("\n");
        emp=(Employee *)this->get(this,index);
        employee_print(emp);
        printf("\nDesea continuar? [s/n]\n\n");
        printf("Opcion ingresada: ");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion=isThat(opcion,'s','n');
        if(opcion=='s')
        {
            emp=(Employee *)this->pop(this,index);
            //this->remove(this,index);
            printf("\nEl empleado\n");
            employee_print(emp);
            printf("ha sido borrado\n\n");
        }
        else
        {
            printf("\nCancelado!\n");
        }
    }
    else if(this->isEmpty(this)==1)
    {
        printf("Base de datos vacia, favor de parsearla primero!\n");
    }
}
//Brief: Borra toda la lista contenida en el puntero Array List
//Parameters: Un puntero Array List
//Return: Void
//
void employee_eraseList(ArrayList *this)
{
    int i;

    if(this!=NULL && this->isEmpty(this)==0)
    {
        for(i=0 ; i<this->len(this) ; i++)
        {
            free( ((Employee *)(this->get(this,i))) );
        }
        printf("Lista borrada!\n");
        this->clear(this);
    }
    else if(this->isEmpty(this)==1)
    {
        printf("La base de datos ya esta vacia!\n");
    }
}
//Brief: Guarda el contenido del puntero Array List en un binario
//Parameters: Un puntero Array List
//Return: Void
//
void employee_saveBin(ArrayList *this)
{
    int i;
    char opcion;
    FILE *fp;

    if(this!=NULL && this->isEmpty(this)==0)
    {
        fp=fopen("save.dat","rb");
        if(fp==NULL)
        {
            fp=fopen("save.dat","wb");
            if(fp==NULL)
            {
                printf("El archivo no puede ser abierto\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            fp=fopen("save.dat","wb");
            if(fp==NULL)
            {
                printf("El archivo no puede ser abierto\n");
                exit(EXIT_FAILURE);
            }
        }
        printf("Desea guardar? [s/n]\n\n");
        printf("Opcion ingresada: ");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion=isThat(opcion,'s','n');
        if(opcion=='s')
        {
            for(i=0 ; i<this->len(this) ; i++)
            {
                fwrite((Employee *)this->get(this,i),sizeof(Employee),1,fp);
            }
            this->deleteArrayList(this);
            fclose(fp);
        }
        else
        {
            this->deleteArrayList(this);
            fclose(fp);
        }
    }
    else if(this->isEmpty(this)==1)
    {
        this->deleteArrayList(this);
    }
}
//Brief: Guarda el contenido del puntero Array List en un .csv
//Parameters: Un puntero Array List
//Return: Void
//
void employee_saveCsv(ArrayList *this)
{
    int i;
    char opcion, emptyAux[10];
    FILE *fp;
    Employee *emp;//=employee_new();

    if(this!=NULL && this->isEmpty(this)==0)
    {
        fp=fopen("save.csv","r");
        if(fp==NULL)
        {
            fp=fopen("save.csv","w");
            if(fp==NULL)
            {
                printf("El archivo no puede ser abierto\n");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            fp=fopen("save.csv","w");
            if(fp==NULL)
            {
                printf("El archivo no puede ser abierto\n");
                exit(EXIT_FAILURE);
            }
        }
        printf("Desea guardar? [s/n]\n\n");
        printf("Opcion ingresada: ");
        fflush(stdin);
        scanf("%c",&opcion);
        opcion=isThat(opcion,'s','n');
        if(opcion=='s')
        {
            fprintf(fp,"id,first_name,last_name,is_empty\n");
            for(i=0 ; i<this->len(this) ; i++)
            {
                emp=this->get(this,i);
                if(emp->isEmpty==0)
                {
                    strcpy(emptyAux,"FALSE");
                }
                else if(emp->isEmpty==1)
                {
                    strcpy(emptyAux,"TRUE");
                }
                fprintf(fp,"%d,%s,%s,%s\n",emp->id,emp->name,emp->lastName,emptyAux);
            }

            this->deleteArrayList(this);
            fclose(fp);
        }
        else
        {
            this->deleteArrayList(this);
            fclose(fp);
        }
    }
    else if(this->isEmpty(this)==1)
    {
        this->deleteArrayList(this);
    }
}
