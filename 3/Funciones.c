#include "Funciones.h"

//Brief: Obtiene el tamaño del file
//Parameters: void
//Return: Devuelve el tamaño
//
int tamMovie(void)
{
    int n=1, total;
    FILE *listMovie;

    listMovie=fopen("MovieList.dat","rb");
    if(listMovie==NULL)
    {
        printf("\nError\n");
        return -1;
    }
    else
    {
        listMovie=fopen("MovieList.dat","r+b");
        if(listMovie==NULL)
        {
            printf("\nError\n");
            return -1;
        }
    }
    fseek(listMovie,0L,SEEK_END);
    total=ftell(listMovie);
    n=total/sizeof(eMovie);

    fclose(listMovie);
    return n;
}
//Brief: Inicializa el arrayMovie
//Parameters: 1 puntero a estructura eMovie
//Return: void
//
void initArrayMovie(eMovie *peli)
{
    if(peli!=NULL)
    {
        peli->isEmpty=VACIO;
    }
    else
    {
        printf("No se puede inicilizar, hay un error en el puntero al array\n");
        return;
    }
}
//Brief: Setea la URL
//Parameters: 1 puntero a estructura eMovie
//Return: void
//
void setURL(eMovie *peli)
{
    int nombreURL, error, isFloat;
    char URL[200]="./FOTOS/", aux[20], auxString[200];

    printf("\n-URL\n");
    printf("1) Abra la carpeta \"FOTOS\"\n");
    printf("2) Seleccione la foto a añadir segun el numero correspondiente\n\nOpcion ingresada : ");
    fflush(stdin);
    scanf("%s",auxString);
    error=isNum(auxString);
    isFloat=intOrFloat(auxString);
    while(error==1||isFloat!=0)
    {
        printf("\nIngrese numero correctamente: ");
        scanf("%s",auxString);
        error=isNum(auxString);
        isFloat=intOrFloat(auxString);
    }
    nombreURL=atoi(auxString);
    sprintf(aux,"%d.jpg",nombreURL);
    strcat(URL,aux);
    strcpy(peli->url,URL);
}
//Brief: Setea los datos de un puntero a estructura eMovie
//Parameters: 1 puntero a estructura eMovie
//Return: void
//
void setDataMovie(eMovie *peli)
{
    int error, isFloat, isCero;
    char auxString[400], aux[100];

    //ID
    printf("\nIngrese id distinto de 0 (cero): ");
    scanf("%s",aux);
    error=isNum(aux);
    isFloat=intOrFloat(aux);
    isCero=esCero(aux);
    while(error==1||isFloat!=0||isCero==1)
    {
        printf("\nIngrese id correctamente: ");
        scanf("%s",aux);
        error=isNum(aux);
        isFloat=intOrFloat(aux);
        isCero=esCero(aux);
    }
    peli->id=atoi(aux);
    //TITULO
    printf("\nIngrese titulo: ");
    fflush(stdin);
    scanf("%[^\n]",auxString);
    error=isLwrThan(auxString,50);
    while(error==1)
    {
        printf("\nSe ha excedido de los 50 caracteres, ingrese titulo nuevamente: ");
        fflush(stdin);
        scanf("%[^\n]",auxString);
        error=isLwrThan(auxString,50);
    }
    strcpy(peli->titulo,formatName(auxString));
    //GENERO
    printf("\nIngrese genero: ");
    fflush(stdin);
    scanf("%[^\n]",auxString);
    error=isLwrThan(auxString,15);
    while(error==1)
    {
        printf("\nSe ha excedido de los 15 caracteres, ingrese genero nuevamente: ");
        fflush(stdin);
        scanf("%[^\n]",auxString);
        error=isLwrThan(auxString,15);
    }
    strcpy(peli->genero,formatName(auxString));
    //DURACION
    printf("\nIngrese duracion: ");
    fflush(stdin);
    scanf("%s",auxString);
    error=isNum(auxString);
    isFloat=intOrFloat(auxString);
    while(error==1||isFloat!=0)
    {
        printf("\nIngrese duracion correctamente: ");
        scanf("%s",auxString);
        error=isNum(auxString);
        isFloat=intOrFloat(auxString);
    }
    peli->duracion=atoi(auxString);
    //DESCRIPCION
    printf("\nIngrese descripcion: ");
    fflush(stdin);
    scanf("%[^\n]",auxString);
    error=isLwrThan(auxString,300);
    while(error==1)
    {
        printf("\nSe ha excedido de los 300 caracteres, ingrese descripcion nuevamente: ");
        fflush(stdin);
        scanf("%[^\n]",auxString);
        error=isLwrThan(auxString,300);
    }
    strcpy(peli->descripcion,auxString);
    //PUNTAJE
    printf("\nIngrese puntaje: ");
    fflush(stdin);
    scanf("%s",auxString);
    error=isNum(auxString);
    isFloat=intOrFloat(auxString);
    while(error==1||isFloat!=0)
    {
        printf("\nIngrese puntaje correctamente: ");
        scanf("%s",auxString);
        error=isNum(auxString);
        isFloat=intOrFloat(auxString);
    }
    peli->puntaje=atoi(auxString);
    //URL
    setURL(peli);
    //ESTADO
    peli->isEmpty=LLENO;
    printf("\n----------\n");
}
//Brief: Agrega estructuras eMovie
//Parameters: void
//Return: void
//
void addMovie(void)
{
    int i, dim=1;
    char confirma;
    eMovie *peli, *auxPeli;
    FILE *listMovie;

    system("cls");
    printf("---Agregar pelicula---\n\n");
    listMovie=fopen("MovieList.dat","rb");
    if(listMovie==NULL)
    {
        listMovie=fopen("MovieList.dat","wb");
        if(listMovie==NULL)
        {
            printf("El archivo no puede ser abierto\n");
            return;
        }
    }
    else
    {
        listMovie=fopen("MovieList.dat","r+b");
    }
    peli=(eMovie *)malloc(sizeof(eMovie)*1);
    if(peli==NULL)
    {
        printf("No se puede reservar memoria para dicha estructura\n");
        return;
    }
    else
    {
        initArrayMovie(peli);
        fseek(listMovie,0L,SEEK_END);
        for(i=0 ; (peli+i)->isEmpty==VACIO ; i++)
        {
            printf("\n----------\n");
            setDataMovie(peli+i);
            fwrite(peli+i,sizeof(eMovie),1,listMovie);
            printf("\nDesea continuar ingresando peliculas?\n\n-Opcion ingresada: ");
            fflush(stdin);
            scanf("%c",&confirma);
            confirma=isThat(confirma,'s','n');
            printf("\n");
            if(confirma=='n')
            {
                printf("\n-Alta exitosa!\n\n");
                break;
            }
            else
            {
                dim++;
                auxPeli=(eMovie *)realloc(peli,(sizeof(eMovie)*dim));
                if(auxPeli==NULL)
                {
                    printf("No hay espacio en memoria para agregar nueva pelicula\n");
                    return;
                }
                else
                {
                    peli=auxPeli;
                    initArrayMovie(peli+i+1);
                }
            }
        }
    }

    free(peli);
    fclose(listMovie);
}
//Brief: Borra una estructuras eMovie
//Parameters: 1 entero tamaño
//Return: void
//
void deleteMovie(int n)
{
    int i, j, indice, cant, auxInt, error, isFloat, firstTime=1;
    char confirma, auxString[100];
    eMovie *peli;
    FILE *listMovie;

    system("cls");
    printf("---Borrar pelicula---\n\n");
    listMovie=fopen("MovieList.dat","rb");
    if(listMovie==NULL)
    {
        printf("\nNo existe lista de peliculas, primero cree una\n");
        return;
    }
    else
    {
        listMovie=fopen("MovieList.dat","r+b");
        if(listMovie==NULL)
        {
            printf("\nNo puede abrirse la lista de peliculas\n");
            return;
        }
    }
    peli=(eMovie *)malloc(sizeof(eMovie)*n);
    if(peli==NULL)
    {
        printf("No se puede reservar memoria para dicha estructura\n");
        return;
    }
    else
    {
        fseek(listMovie,0L,SEEK_SET);
        for(i=0 ; i<n ; i++)
        {
            cant=fread(peli+i,sizeof(eMovie),1,listMovie);
            if(cant!=1)
            {
                printf("Error\n");
                return;
            }
        }
        fseek(listMovie,0L,SEEK_SET);
        printf("Indique el ID de la pelicula a borrar o 0 (cero) para salir\n\n|ID| TITULO |\n\n");
        for(i=0 ; i<n ; i++)
        {
            if((peli+i)->isEmpty==LLENO)
            {
                printf("|%d| %s | ",(peli+i)->id,(peli+i)->titulo);
                if(i==n-1)
                {
                    printf("\n\n");
                }
            }
        }
        printf("-Opcion ingresada: ");
        fflush(stdin);
        scanf("%s",auxString);
        error=isNum(auxString);
        isFloat=intOrFloat(auxString);
        while(error==1||isFloat!=0)
        {
            printf("\nIngrese ID correctamente: ");
            fflush(stdin);
            scanf("%s",auxString);
            error=isNum(auxString);
            isFloat=intOrFloat(auxString);
        }
        auxInt=atoi(auxString);
        printf("\n");
        if(auxInt==0)
        {
            printf("\n\n-Borrado cancelado!");
            return;
        }
        fseek(listMovie,0L,SEEK_SET);
        for(i=0 ; i<n ; i++)
        {
            if((peli+i)->isEmpty==LLENO&&(peli+i)->id==auxInt&&firstTime==1)
            {
                (peli+i)->isEmpty=VACIO;
                indice=i;
                for(j=0 ; j<n ; j++)
                {
                    if(j==indice)
                    {
                        printf("Confirma que desea borrar \"%s\"?\n\n-Opcion elegida: ",(peli+indice)->titulo);
                        fflush(stdin);
                        scanf("%c",&confirma);
                        confirma=isThat(confirma,'s','n');
                        if(confirma=='n')
                        {
                            printf("\n\n-Borrado cancelado!");
                            return;
                        }
                        else
                        {
                            fwrite(peli+indice,sizeof(eMovie),1,listMovie);
                            printf("\n\n-Borrado exitoso!");
                            firstTime=0;
                        }
                    }
                    fseek(listMovie,sizeof(eMovie)*1,SEEK_CUR);
                }
            }
            else if((peli+i)->isEmpty==LLENO&&(peli+i)->id!=auxInt&&firstTime==1&&i==(n-1))
            {
                i=-1;
                printf("Indique el ID correctamente de la pelicula a borrar o 0 (cero) para salir\n\n");
                printf("-Opcion ingresada: ");
                fflush(stdin);
                scanf("%s",auxString);
                error=isNum(auxString);
                isFloat=intOrFloat(auxString);
                while(error==1||isFloat!=0)
                {
                    printf("\nIngrese ID correctamente: ");
                    fflush(stdin);
                    scanf("%s",auxString);
                    error=isNum(auxString);
                    isFloat=intOrFloat(auxString);
                }
                auxInt=atoi(auxString);
                printf("\n");
                if(auxInt==0)
                {
                    printf("\n\n-Borrado cancelado!");
                    return;
                }
            }
        }
    }

    fclose(listMovie);
    free(peli);
}
//Brief: Modifica una estructura eMovie
//Parameters: 1 entero tamaño
//Return: void
//
void modMovie(int n)
{
    int i, j, indice, cant, seguir=1, error, isFloat, repetido=0, auxInt, firstTime=1;
    char confirma, auxString[100], opcion;
    eMovie *peli;
    FILE *listMovie;

    system("cls");
    printf("---Modificar pelicula---\n\n");
    listMovie=fopen("MovieList.dat","rb");
    if(listMovie==NULL)
    {
        printf("\nNo existe lista de peliculas, primero cree una\n");
        return;
    }
    else
    {
        listMovie=fopen("MovieList.dat","r+b");
        if(listMovie==NULL)
        {
            printf("\nNo puede abrirse la lista de peliculas\n");
            return;
        }
    }
    peli=(eMovie *)malloc(sizeof(eMovie)*n);
    if(peli==NULL)
    {
        printf("No se puede reservar memoria para dicha estructura\n");
        return;
    }
    else
    {
        fseek(listMovie,0L,SEEK_SET);
        for(i=0 ; i<n ; i++)
        {
            cant=fread(peli+i,sizeof(eMovie),1,listMovie);
            if(cant!=1)
            {
                printf("Error\n");
                return;
            }
        }
        fseek(listMovie,0L,SEEK_SET);
        printf("Indique el ID de la pelicula a modificar o 0 (cero) para salir\n\n|ID| TITULO |\n\n");
        for(i=0 ; i<n ; i++)
        {
            if((peli+i)->isEmpty==LLENO)
            {
                printf("|%d| %s | ",(peli+i)->id,(peli+i)->titulo);
                if(i==n-1)
                {
                    printf("\n\n");
                }
            }
        }
        printf("-Opcion ingresada: ");
        fflush(stdin);
        scanf("%s",auxString);
        error=isNum(auxString);
        isFloat=intOrFloat(auxString);
        while(error==1||isFloat!=0)
        {
            printf("\nIngrese ID correctamente: ");
            scanf("%s",auxString);
            error=isNum(auxString);
            isFloat=intOrFloat(auxString);
        }
        auxInt=atoi(auxString);
        printf("\n");
        if(auxInt==0)
        {
            printf("\n\n-Modificados cancelado!");
            return;
        }
        fseek(listMovie,0L,SEEK_SET);
        for(i=0 ; i<n ; i++)
        {
            if((peli+i)->isEmpty==LLENO&&(peli+i)->id==auxInt)
            {
                indice=i;
                for(j=0 ; j<n ; j++)
                {
                    if(j==indice&&firstTime==1)
                    {
                        printf("Confirma que desea modificar \"%s\"?\n\n-Opcion elegida: ",(peli+indice)->titulo);
                        fflush(stdin);
                        scanf("%c",&confirma);
                        confirma=isThat(confirma,'s','n');
                        if(confirma=='n')
                        {
                            printf("\n\n-Modificado cancelado!\n\n");
                            return;
                        }
                        else
                        {
                            do
                            {
                                opcion=submenu();
                                while(opcion<49||opcion>55||isdigit(opcion)==0)
                                {
                                    system("cls");
                                    printf("Ingrese correctamente una de las siguientes opciones\n\n");
                                    opcion=submenu();
                                }
                                switch(opcion)
                                {
                                    case '1':
                                    {
                                        printf("\n\"%s\"\n",(peli+indice)->titulo);
                                        printf("\nIngrese titulo: ");
                                        fflush(stdin);
                                        scanf("%[^\n]",auxString);
                                        error=isLwrThan(auxString,50);
                                        while(error==1||repetido==1)
                                        {
                                            printf("\nSe ha excedido de los 50 caracteres, ingrese titulo nuevamente: ");
                                            fflush(stdin);
                                            scanf("%[^\n]",auxString);
                                            error=isLwrThan(auxString,50);
                                        }
                                        strcpy((peli+indice)->titulo,formatName(auxString));
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '2':
                                    {
                                        printf("\n\"%s\"\n",(peli+indice)->genero);
                                        printf("\nIngrese genero: ");
                                        fflush(stdin);
                                        scanf("%[^\n]",auxString);
                                        error=isLwrThan(auxString,15);
                                        while(error==1)
                                        {
                                            printf("\nSe ha excedido de los 15 caracteres, ingrese genero nuevamente: ");
                                            fflush(stdin);
                                            scanf("%[^\n]",auxString);
                                            error=isLwrThan(auxString,15);
                                        }
                                        strcpy((peli+indice)->genero,formatName(auxString));
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '3':
                                    {
                                        printf("\n\"%d\"\n",(peli+indice)->duracion);
                                        printf("\nIngrese duracion: ");
                                        fflush(stdin);
                                        scanf("%s",auxString);
                                        error=isNum(auxString);
                                        isFloat=intOrFloat(auxString);
                                        while(error==1||isFloat!=0)
                                        {
                                            printf("\nIngrese duracion correctamente: ");
                                            scanf("%s",auxString);
                                            error=isNum(auxString);
                                            isFloat=intOrFloat(auxString);
                                        }
                                        (peli+indice)->duracion=atoi(auxString);
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '4':
                                    {
                                        printf("\n\"%s\"\n",(peli+indice)->descripcion);
                                        printf("\nIngrese descripcion: ");
                                        fflush(stdin);
                                        scanf("%[^\n]",auxString);
                                        error=isLwrThan(auxString,300);
                                        while(error==1)
                                        {
                                            printf("\nSe ha excedido de los 300 caracteres, ingrese descripcion nuevamente: ");
                                            fflush(stdin);
                                            scanf("%[^\n]",auxString);
                                            error=isLwrThan(auxString,300);
                                        }
                                        strcpy((peli+indice)->descripcion,auxString);
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '5':
                                    {
                                        printf("\n\"%d\"\n",(peli+indice)->puntaje);
                                        printf("\nIngrese puntaje: ");
                                        fflush(stdin);
                                        scanf("%s",auxString);
                                        error=isNum(auxString);
                                        isFloat=intOrFloat(auxString);
                                        while(error==1||isFloat!=0)
                                        {
                                            printf("\nIngrese puntaje correctamente: ");
                                            scanf("%s",auxString);
                                            error=isNum(auxString);
                                            isFloat=intOrFloat(auxString);
                                        }
                                        (peli+indice)->puntaje=atoi(auxString);
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '6':
                                    {
                                        printf("\n\"%s\"\n",(peli+indice)->url);
                                        setURL(peli+indice);
                                        printf("\n\n");
                                        system("pause");
                                        system("cls");
                                        break;
                                    }
                                    case '7':
                                    {
                                        fwrite(peli+indice,sizeof(eMovie),1,listMovie);
                                        seguir=0;
                                        firstTime=0;
                                        break;
                                    }
                                }
                            }
                            while(seguir==1&&firstTime==1);
                            printf("\n\n-Modificado exitoso!");
                        }
                    }
                    fseek(listMovie,sizeof(eMovie)*1,SEEK_CUR);
                }
            }
            else if((peli+i)->isEmpty==LLENO&&(peli+i)->id!=auxInt&&i==(n-1)&&firstTime==1)
            {
                i=-1;
                printf("Indique el ID correctamente de la pelicula a modificar o 0 (cero) para salir\n\n");
                printf("-Opcion ingresada: ");
                fflush(stdin);
                scanf("%s",auxString);
                error=isNum(auxString);
                isFloat=intOrFloat(auxString);
                while(error==1||isFloat!=0)
                {
                    printf("\nIngrese ID correctamente: ");
                    fflush(stdin);
                    scanf("%s",auxString);
                    error=isNum(auxString);
                    isFloat=intOrFloat(auxString);
                }
                auxInt=atoi(auxString);
                printf("\n");
                if(auxInt==0)
                {
                    printf("\n\n-Modificado cancelado!");
                    return;
                }
            }
        }
    }

    fclose(listMovie);
    free(peli);
}
//Brief: Genera una pagina web a partir del binario de lista de peliculas
//Parameters: 1 entero tamaño
//Return: void
//
void generateWeb(int n)
{
    int i, puntaje, duracion, cant;
    char head[]="<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>";
    char tail[]="</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>";
    char body[10000];
    char url[100], titulo[100], genero[50], descripcion[500];
    eMovie *peli;
    FILE *listMovie, *web;

    system("cls");
    printf("---Generar pagina web---\n\n");
    listMovie=fopen("MovieList.dat","rb");
    if(listMovie==NULL)
    {
        listMovie=fopen("MovieList.dat","wb");
        if(listMovie==NULL)
        {
            printf("El archivo no puede ser abierto\n");
            return;
        }
    }
    else
    {
        listMovie=fopen("MovieList.dat","r+b");
    }
    web=fopen("index.html","r");
    if(web==NULL)
    {
        web=fopen("index.html","w");
        if(web==NULL)
        {
            printf("El archivo no puede ser abierto\n");
            return;
        }
    }
    else
    {
        web=fopen("index.html","w");
        if(web==NULL)
        {
            printf("El archivo no puede ser abierto\n");
            return;
        }
    }
    peli=(eMovie *)malloc(sizeof(eMovie)*n);
    if(peli==NULL)
    {
        printf("No se puede reservar memoria para dicha estructura\n");
        return;
    }
    else
    {
        fseek(listMovie,0L,SEEK_SET);
        for(i=0 ; i<n ; i++)
        {
            cant=fread(peli+i,sizeof(eMovie),1,listMovie);
            if(cant!=1)
            {
                printf("Error\n");
                return;
            }
        }
        fseek(listMovie,0L,SEEK_SET);
        fseek(web,0L,SEEK_SET);
        fwrite(head,sizeof(char),strlen(head),web);
        for(i=0 ; i<n ; i++)
        {
            if((peli+i)->isEmpty==LLENO)
            {
                strcpy(titulo,(peli+i)->titulo);
                strcpy(genero,(peli+i)->genero);
                strcpy(url,(peli+i)->url);
                strcpy(descripcion,(peli+i)->descripcion);
                puntaje=(peli+i)->puntaje;
                duracion=(peli+i)->duracion;
                sprintf(body,"<!-- Repetir esto para cada pelicula --><article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul><p>%s</p></article><!-- Repetir esto para cada pelicula -->",url,titulo,genero,puntaje,duracion,descripcion);
                fwrite(body,sizeof(char),strlen(body),web);
            }
        }
        fwrite(tail,sizeof(char),strlen(tail),web);
        printf("\n\n-Pagina web generada exitosamente!\n\n");
    }

    free(peli);
    fclose(web);
    fclose(listMovie);
}

