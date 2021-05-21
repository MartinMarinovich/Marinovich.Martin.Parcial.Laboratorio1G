#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "empleado.h"
#include "utn.h"
#include "cliente.h"



int hardcodearClientes(eCliente listaDeClientes[],int tamanioClientes, int *pIdCliente)
{

    int retorno = -1;


    char nombres[10][51]= {"Donato","German","Gunda","Carmen","Daniela","Maria","Alex","Damian","Gaston","Santiago"};
    char apellidos[10][51]= {"Perez","Morales","Lopez","Huber","Fraiese","Parodi","Ferraro","Taboada","Zermo","Contardi"};
    int idEmpleados[10] = {100,106,102,101,101,104,105,102,105,103};
    char telefonos[10][21]= {"4204-6286","11-2650-6432","15-2435-8963","4265-9842","4895-6542","11-2256-6845","15-4789-7263","11-3548-4632","4289-4563","4222-4555"};
    char sexos[10]= {'m','m','f','f','f','f','m','m','m','m'};

    if(listaDeClientes != NULL && tamanioClientes >0 && pIdCliente !=NULL)
    {
        for(int i = 0; i<10; i++)
        {

            listaDeClientes[i].codigo = *pIdCliente;
            (*pIdCliente)++;

            strcpy(listaDeClientes[i].nombre,nombres[i]);
            strcpy(listaDeClientes[i].apellido,apellidos[i]);
            listaDeClientes[i].idEmpleado = idEmpleados[i];
            strcpy(listaDeClientes[i].telefono,telefonos[i]);
            listaDeClientes[i].sexo = sexos[i];
            listaDeClientes[i].isEmpty = 0;

        }
        retorno = 0;

    }


    return retorno;

}

int inicializarClientes(eCliente listaDeClientes[],int tamanioClientes)
{
    int error = -1;

    if(listaDeClientes != NULL &&tamanioClientes>0)
    {
        error = 0;

        for (int i = 0; i < tamanioClientes; ++i)
        {
            listaDeClientes[i].isEmpty = 1;
        }
    }
    return error;
}


int buscarLibre(eCliente listaDeClientes[], int tamanioClientes)
{
    int indice = -1;

    for(int i = 0; i < tamanioClientes; i++)
    {
        if(listaDeClientes[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int buscarCliente(eCliente listaDeClientes[], int tamClientes,int idCliente)
{
    int indice=-1;

    if(listaDeClientes!=NULL && tamClientes>0)
    {

        for(int i=0; i<tamClientes; i++)
        {
            if(idCliente == listaDeClientes[i].codigo && !listaDeClientes[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }

    return indice;
}

//int altaCliente(eCliente listaDeClientes[], int tamanioClientes,int* pIdCliente)

int altaCliente(eCliente listaDeClientes[],eEmpleado listaDeEmpleados[],int tamEmpleados, int tamanioClientes,int* pIdCliente)
{

    int retorno=-1;
    int indice;
    eCliente nuevoCliente;

    if(listaDeClientes!=NULL && pIdCliente != NULL && listaDeEmpleados != NULL && tamanioClientes >0 && tamEmpleados >0)
    {
        system("cls");
        printf("      Alta Cliente\n\n");
        indice = buscarLibre(listaDeClientes,tamanioClientes);
        if(indice!=-1)
        {

            if(utn_getCadena(nuevoCliente.nombre,51,"Ingrese nombre: ","Error re ingrese el nombre\n",5)&&
                    utn_getCadena(nuevoCliente.apellido,51,"Ingrese apellido: ","Error re ingrese el apellido \n",5)&&
                    utn_getCaracter(&nuevoCliente.sexo,"Ingrese sexo: ","Error re ingrese sexo\n",'f','m',5)&&
                    utn_getCadena(nuevoCliente.telefono,21,"Ingrese el telefono: ","Error telefono demasiado largo.\n",5)
              )

            {
                listarEmpleados(listaDeEmpleados,tamEmpleados);
                // DEPENDE EL PROFE

                if(utn_getNumero(&nuevoCliente.idEmpleado,"Ingrese el ID del empleado\n","Error, re ingrese ID",100,107,4))
                {
                    strcpy(listaDeClientes[indice].nombre,nuevoCliente.nombre);
                    strcpy(listaDeClientes[indice].apellido,nuevoCliente.apellido);
                    listaDeClientes[indice].sexo = nuevoCliente.sexo;
                    listaDeClientes[indice].isEmpty = 0;
                    listaDeClientes[indice].codigo = *pIdCliente;
                    listaDeClientes[indice].idEmpleado = nuevoCliente.idEmpleado;
                    strcpy( listaDeClientes[indice].telefono,nuevoCliente.telefono);
                    listaDeClientes[indice].idEmpleado = nuevoCliente.idEmpleado;
                    (*pIdCliente)++;
                    retorno = 1;

                }
                else
                {
                    printf("Error, no se pudo dar de alta el cliente.");
                }

            }
            else
            {
                printf("Error, no se pudo dar de alta el cliente.");
            }
        }
        else
        {
            printf("No hay lugar para cargar mas clientes.\n");
        }
    }
    return retorno;


}


int menu (int *opcionMenu)
{
    int error = -1;
    int opcion;

    if(opcionMenu != NULL)
    {


        printf("\n*** ABM Juegos ***\n\n");
        printf("1 Alta Cliente\n");
        printf("2 Modificar Cliente\n");
        printf("3 Baja Cliente\n");
        printf("4 Listar Clientes\n");
        printf("5 Alta Alquiler\n");
        printf("6 Listar Alquiler\n");
        printf("7 Salir\n");


        if(utn_getNumero(&opcion,"\nIngrese la opcion deseada\n","Error, opcion invalida\n",1,7,4))
        {
            *opcionMenu = opcion;
        }
        error = 0;

    }
    return error;
}


//int listarClientes(eCliente listaDeClientes[],int tamClientes)
int listarClientes(eCliente listaDeClientes[],eEmpleado listaDeEmpleados [],int tamClientes,int tamEmpleados)
{

    int error = 1;
    int flag = 0;

    if( listaDeClientes != NULL && tamClientes > 0 )
    {
        system("cls");
        //ordenarNotebooks(listaDeClientes,tamNotebook);
        printf(" Codigo           Nombre             Apellido             Sexo           Telefono       IdEmpleado      Empleado\n");
        printf("---------------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tamClientes; i++)
        {
            if(!verificarExistenciaCliente(listaDeClientes,tamClientes)&& listaDeClientes[i].isEmpty == 0)
            {
                //  mostrarUnCliente(listaDeClientes[i]);
                mostrarUnCliente(listaDeClientes[i],listaDeEmpleados,tamEmpleados);
                flag = 1;
                error = 0;
            }
        }

        if( flag == 0)
        {
            printf("    No hay clientes en la lista\n");
        }

    }
    return error;

}

int obtenerDescripcionEmpleado(eEmpleado listaDeEmpleados[],int tamEmpleados,int idEmpleado, char descripcionEmpleado[])
{
    int error = -1;

    if(listaDeEmpleados != NULL && descripcionEmpleado != NULL && tamEmpleados >0 && idEmpleado>0)
    {
        for(int i = 0; i<tamEmpleados; i++)
        {
            if(listaDeEmpleados[i].codigo == idEmpleado)
            {
                strcpy(descripcionEmpleado, listaDeEmpleados[i].nombre);
                error = 1;
                break;
            }
        }
    }

    return error;
}


int mostrarUnCliente(eCliente unCliente,eEmpleado listaDeEmpleados [], int tamEmpleados)
{
    int error = -1;
    char empleado [51];

    if(listaDeEmpleados != NULL && tamEmpleados >0 && obtenerDescripcionEmpleado(listaDeEmpleados,tamEmpleados,unCliente.idEmpleado,empleado))
    {
        error = 1;

        printf("%d             %10s           %10s              %c          %10s        %d         %10s\n",unCliente.codigo,unCliente.nombre,unCliente.apellido,unCliente.sexo,unCliente.telefono,unCliente.idEmpleado,empleado);
    }
    return error;
}


int verificarExistenciaCliente(eCliente listaDeClientes[], int tamClientes)
{
    int error= -1;

    if(listaDeClientes!=NULL && tamClientes > 0)
    {
        for(int i=0; i<tamClientes; i++)
        {
            if(listaDeClientes[i].isEmpty == 0)
            {
                error=0;
                break;
            }
        }
    }
    return error;
}

int modificarClientes(eCliente listaDeClientes[], eEmpleado listaDeEmpleados [],int tamClientes, int tamEmpleados)
{
    int retorno= -1;
    int flag = 0;
    int indice;
    int opcion;
    int idCliente;
    eCliente auxCliente;


    if(listaDeClientes!=NULL && listaDeEmpleados != NULL && tamClientes>0 && tamEmpleados) // CAMBIAR
    {
        //listarClientes(listaDeClientes,tamClientes);
        listarClientes(listaDeClientes,listaDeEmpleados,tamClientes,tamEmpleados);
        utn_getNumero(&idCliente,"ingrese la ID del cliente","Error, numero invalido",1,20,4);

        indice = buscarCliente(listaDeClientes,tamClientes,idCliente);

        if(indice==-1)
        {
            printf("No se encontro ningun cliente con ese codigo.\n");
        }
        else
        {

            printf(" Codigo           Nombre             Apellido             Sexo           Telefono       IdEmpleado      Empleado\n");
            printf("---------------------------------------------------------------------------------------------------------------------\n");

            mostrarUnCliente(listaDeClientes[indice],listaDeEmpleados,tamEmpleados);

            do
            {
                if(utn_getNumero(&opcion,"Ingrese la opcion para modificar\n1-Nombre\n2-Apellido\n3-Sexo\n4-Empleado\n5-Salir\n","Error, opcion no valida\n",1,5,4))
                {
                    switch(opcion)
                    {
                    case 1:
                        if(utn_getCadena(auxCliente.nombre,51,"Ingrese el nombre a reemplazar\n","Error\n",4))
                        {
                            strcpy(listaDeClientes[indice].nombre,auxCliente.nombre);
                            flag = 1;
                        }
                        break;

                    case 2:
                        if(utn_getCadena(auxCliente.apellido,51,"Ingrese el apellido a reemplazar\n","Error\n",4))
                        {
                            strcpy(listaDeClientes[indice].apellido,auxCliente.apellido);
                            flag = 1;
                        }
                        break;
                    case 3:
                        if(utn_getCaracter(&auxCliente.sexo,"Ingrese sexo\n","Error, parametro incorrecto\n",'f','m',4))
                        {
                            listaDeClientes[indice].sexo = auxCliente.sexo;
                            flag = 1;
                        }
                        break;

                    case 4:

                        listarEmpleados(listaDeEmpleados,tamEmpleados);

                        if(utn_getNumero(&auxCliente.idEmpleado,"Ingrese el Id del empleado a modificar\n","Error, ID inexistente\n",100,107,5))
                        {
                            listaDeClientes[indice].idEmpleado = auxCliente.idEmpleado;
                            flag = 1;
                        }
                        break;
                    case 5:
                        if(flag)
                        {
                            retorno = 0;
                        }
                        else
                        {
                            retorno = 2;
                        }
                        break;

                    }
                }

            }
            while(opcion!=5);
        }
    }
    return retorno;
}


int bajaCliente(eCliente listaDeClientes[], eEmpleado listaDeEmpleados [],int tamClientes, int tamEmpleados)
{
    int retorno= -1;
    int indice;
    int opcion;
    int idCliente;

    printf("*** Baja Cliente ***\n\n");
    if(listaDeClientes!=NULL && tamClientes >0)
    {
        listarClientes(listaDeClientes,listaDeEmpleados,tamEmpleados,tamClientes);
        utn_getNumero(&idCliente,"\ningrese la ID","Error, numero invalido",1,20,4);
        indice = buscarCliente(listaDeClientes, tamClientes,idCliente);

        if(indice==-1)
        {
            printf("No se encontro ningun cliente con ese codigo.\n");
        }
        else
        {
            printf(" Codigo           Nombre             Apellido             Sexo\n");
            printf("-------------------------------------------------------------------------\n");
            mostrarUnCliente(listaDeClientes[indice],listaDeEmpleados,tamEmpleados);

            if(utn_getNumero(&opcion,"Desea dar de baja a este cliente?\n1-Si\2-No\n", "Error, numero incorrecto.\n",0,1,10))
            {
                if(opcion == 1)
                {
                    listaDeClientes[indice].isEmpty=1;
                    retorno = 0;
                }
                else
                {
                    printf("Baja cancelada.\n");
                    retorno = 1;
                }
            }

        }
    }

    return retorno;
}

int ordenarClientes(eCliente listaDeClientes [], int tamClientes)
{
    int retorno = -1;
    eCliente auxCliente;

    if(listaDeClientes != NULL && tamClientes >0)
    {
        for(int i = 0; i<tamClientes-1; i++)
        {
            for(int j = i +1; j<tamClientes; j++)
            {
                retorno = 1;
                if(strcmp(listaDeClientes[i].apellido,listaDeClientes[j].apellido)>0)
                {
                    auxCliente = listaDeClientes[i];
                    listaDeClientes[i] = listaDeClientes[j];
                    listaDeClientes[j] = auxCliente;
                }
                else
                {
                    if(strcmp(listaDeClientes[i].apellido,listaDeClientes[j].apellido) == 0)
                    {
                        if(strcmp(listaDeClientes[i].nombre,listaDeClientes[j].nombre)>0)
                        {
                            auxCliente = listaDeClientes[i];
                            listaDeClientes[i] = listaDeClientes[j];
                            listaDeClientes[j] = auxCliente;
                        }
                    }
                }
            }
        }

    }

    return retorno;
}
