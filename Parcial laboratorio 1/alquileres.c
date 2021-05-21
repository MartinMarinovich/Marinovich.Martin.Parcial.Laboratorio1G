#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#include "alquileres.h"
#include "categoria.h"
#include "cliente.h"

#include "juego.h"
#include "utn.h"

int hardcodearAlquileres(eAlquileres listaDeAlquileres[],int tamanioAlquileres, int *pIdAlquiler)
{
    int retorno = -1;

    int codigoJuego[10] = {1007,1001,1002,1003,1004,1002,1007,1007,1006,1006};
    int dias [10] = {4,5,8,8,30,20,11,22,22,4};
    int meses [10] = {12,12,1,3,4,4,5,6,6,4};
    int anios [10] = {1996,1996,2020,2020,2004,2001,2001,2004,2019,2020};
    int idCliente[10] = {4,4,1,1,2,5,3,7,10,10};
    if(listaDeAlquileres != NULL && tamanioAlquileres >0 && pIdAlquiler !=NULL)
    {
        for(int i = 0; i<10; i++)
        {
            listaDeAlquileres[i].codigoAlquiler = *pIdAlquiler;
            (*pIdAlquiler)++;
            listaDeAlquileres[i].fechaAlquiler.dia = dias[i];
            listaDeAlquileres[i].fechaAlquiler.mes = meses[i];
            listaDeAlquileres[i].fechaAlquiler.anio = anios[i];
            listaDeAlquileres[i].codigoJuego = codigoJuego[i];
            listaDeAlquileres[i].codigoCliente = idCliente[i];
            listaDeAlquileres[i].isEmpty = 0;

        }
        retorno = 0;

    }


    return retorno;

}

int inicializarAlquilers(eAlquileres listaDeAlquileres[],int tamanioAlquileres)
{
    int error = -1;

    if(listaDeAlquileres != NULL &&tamanioAlquileres>0)
    {
        error = 0;

        for (int i = 0; i < tamanioAlquileres; ++i)
        {
            listaDeAlquileres[i].isEmpty = 1;
        }
    }
    return error;
}

int buscarJuego(eJuego listaDeJuegos[], int tamJuegos,int idJuego)
{
    int indice=-1;

    if(listaDeJuegos!=NULL && tamJuegos>0 && idJuego >0)
    {

        for(int i=0; i<tamJuegos; i++)
        {
            if(idJuego == listaDeJuegos[i].codigo)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}


int buscarLibreAlquiler(eAlquileres listaDeAlquileres[], int tamanioAlquileres)
{
    int indice = -1;

    for(int i = 0; i < tamanioAlquileres; i++)
    {
        if(listaDeAlquileres[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int altaAlquiler(eAlquileres listaDeAlquileres[],eCliente listaDeClientes[],eEmpleado listaDeEmpleados[], int tamEmpleados, int tamClientes, int tamanioAlquileres,int* pIdAlquiler,eJuego listaDeJuegos[], int tamJuego)
{

    int retorno=-1;
    int indice;
    int aux;
    int idCliente;
    int idJuego;


    if(listaDeAlquileres!=NULL && pIdAlquiler != NULL && listaDeClientes != NULL && tamClientes>0 && tamanioAlquileres >0 )
    {
        system("cls");
        printf(" *** Alta Alquiler ***\n\n");

        indice = buscarLibreAlquiler(listaDeAlquileres,tamanioAlquileres);

        if(indice!=-1)
        {
            listarClientes(listaDeClientes,listaDeEmpleados,tamClientes,tamEmpleados);

            if(utn_getNumero(&idCliente,"Ingrese el numero del cliente:","Error numero invalido\n",1,20,10))
            {
                aux = buscarCliente(listaDeClientes,tamClientes,idCliente);

                if(aux != -1)
                {

                    listarJuegos(listaDeJuegos,tamJuego);

                    if(utn_getNumero(&idJuego,"Ingrese la id del juego\n","Error, ID invalido\n",1000,1007,5)
                            && utn_getNumero(&listaDeAlquileres[indice].fechaAlquiler.dia,"Ingrese el dia de alquiler\n","Error, ingrese dia  valida\n",1,30,5)
                            &&utn_getNumero(&listaDeAlquileres[indice].fechaAlquiler.mes,"Ingrese el mes de alquiler\n","Error, ingrese mes valida\n",1,12,5)
                            && utn_getNumero(&listaDeAlquileres[indice].fechaAlquiler.anio,"Ingrese el anio de alquiler\n","Error, ingrese anio valida\n",1900,2021,5))
                    {
                        listaDeAlquileres[indice].codigoJuego = idJuego;
                        listaDeAlquileres[indice].isEmpty = 0;
                        listaDeAlquileres[indice].codigoAlquiler = *pIdAlquiler;
                        (*pIdAlquiler)++;
                        listaDeAlquileres[indice].codigoCliente = idCliente;
                        retorno = 1;
                    }

                }
                else
                {
                    printf("Error, no exite un cliente con esa  ID\n");
                }
            }
            else
            {
                printf("Error, no se pudo dar de alta el alquiler.");
            }
        }
        else
        {
            printf("No hay lugar para cargar mas alquileres.\n");
        }
    }
    return retorno;


}

int obtenerDescripcionCliente(eCliente listaDeClientes[], int tamanioClientes, int id, char nombreCliente[], char apellidoCliente[])
{
    int error = -1;

    if(listaDeClientes != NULL && tamanioClientes > 0 && nombreCliente != NULL && apellidoCliente != NULL)
    {
        for(int i = 0; i<tamanioClientes; i++)
        {
            if(listaDeClientes[i].codigo == id)
            {
                strcpy(nombreCliente, listaDeClientes[i].nombre);
                strcpy(apellidoCliente, listaDeClientes[i].apellido);
                error = 1;
                break;
            }
        }
    }
    return error;
}

int obtenerDescripcionJuego(eJuego listaDeJuegos[],int tamJuegos, int idJuego, char descripcionJuego[],float *precio)
{
    int error = -1;

    if(listaDeJuegos != NULL && descripcionJuego != NULL)
    {
        for(int i = 0; i<tamJuegos; i++)
        {
            if(listaDeJuegos[i].codigo == idJuego)
            {
                strcpy(descripcionJuego, listaDeJuegos[i].descripcion);
                *precio = listaDeJuegos[i].importe;
                error = 1;
                break;
            }
        }
    }

    return error;
}

int obtenerDescripcionCategoria(eCategoria listaDeCategorias[],eJuego listaDeJuegos[],int tamJuegos,int tamcategorias,int idJuego, char descripcionCategoria[])
{
    int error = -1;
    int indice;

    if(listaDeCategorias != NULL && descripcionCategoria != NULL && tamcategorias >0 && idJuego>0 && descripcionCategoria != NULL)
    {
        for(int i = 0; i<tamcategorias; i++)
        {
            indice = buscarJuego(listaDeJuegos,tamJuegos,idJuego);

            if(listaDeJuegos[indice].idCategoria == listaDeCategorias[i].idCategoria)
            {
                strcpy(descripcionCategoria, listaDeCategorias[i].descripcion);
                error = 1;
                break;
            }
        }
    }

    return error;
}

void mostrarUnAlquiler(eAlquileres unAlquiler,eJuego listaJuegos[],eCliente listaClientes[],eCategoria listaDeCategorias[],int tamcategorias,int tamJuego, int tamCliente)
{
    char juego [20];
    char nombreCliente [20];
    char apellidoCliente [20];
    char categoria [20];
    float precio = 0;

    if(obtenerDescripcionJuego(listaJuegos,tamJuego,unAlquiler.codigoJuego,juego,&precio)&&
            obtenerDescripcionCliente(listaClientes,tamCliente,unAlquiler.codigoCliente,nombreCliente,apellidoCliente)&&
            obtenerDescripcionCategoria(listaDeCategorias,listaJuegos,tamJuego,tamcategorias,unAlquiler.codigoJuego,categoria))
    {

        printf("    %d             %10s        %10s                %d          %10s                %10s             %02d/%02d/%03d             %.4f\n",unAlquiler.codigoAlquiler,juego,categoria,unAlquiler.codigoCliente,nombreCliente,apellidoCliente,unAlquiler.fechaAlquiler.dia,unAlquiler.fechaAlquiler.mes,unAlquiler.fechaAlquiler.anio,precio);
    }


}

int listarAlquilers(eAlquileres listaDeAlquileres[],int tamAlquilers,eJuego listaJuegos[],eCliente listaClientes[],eCategoria listaDeCategorias[],int tamcategorias,int tamJuego, int tamCliente)
{

    int error = 1;
    int flag = 0;

    if( listaDeAlquileres != NULL && tamAlquilers > 0 )
    {
        system("cls");
        //ordenarAlquileres(listaDeAlquileres,tamNotebook);
        printf(" Codigo Alquiler           Juego          Categoria      Codigo Cliente     Nombre Cliente      Apellido Cliente          Fecha de Alquiler          Precio\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tamAlquilers; i++)
        {
            if(!verificarExistenciaAlquiler(listaDeAlquileres,tamAlquilers) && listaDeAlquileres[i].isEmpty == 0 && listaClientes[i].isEmpty == 0)
            {

                mostrarUnAlquiler(listaDeAlquileres[i],listaJuegos,listaClientes,listaDeCategorias,tamcategorias,tamJuego,tamCliente);
                flag = 1;
                error = 0;
            }
        }
        printf("\n");
        if( flag == 0)
        {
            printf("    No hay Alquilers en la lista\n");
        }

    }
    return error;

}

int verificarExistenciaAlquiler(eAlquileres listarAlquileres[], int tamAlquileres)
{
    int error= -1;

    if(listarAlquileres!=NULL && tamAlquileres > 0)
    {
        for(int i=0; i<tamAlquileres; i++)
        {
            if(listarAlquileres[i].isEmpty == 0)
            {
                error=0;
                break;
            }
        }
    }
    return error;
}

int listarPorCategoria(eAlquileres listaDeAlquileres[],eCategoria listaDeCategorias[],eJuego listaDeJuegos[],eCliente listaDeClientes[],int tamClientes, int tamJuegos,int tamAlquileres, int tamCategoria)
{
    int retorno = -1;
    int idCategoria;
    int flag = 0;

    if(listaDeAlquileres != NULL && listaDeCategorias != NULL && listaDeJuegos != NULL && listaDeClientes !=NULL && tamJuegos >0 && tamAlquileres >0 && tamCategoria >0)
    {
        printf("*** LISTADO DE ALQUILERES POR CATEGORIA ***\n");

        listarCategorias(listaDeCategorias,tamCategoria);
        if(utn_getNumero(&idCategoria,"Ingrese el ID de la categoria que desea listar\n","Eror, categoria inexistente\n",1,5,5))
        {
            printf(" Codigo Alquiler           Juego          Categoria      Codigo Cliente     Nombre Cliente      Apellido Cliente          Fecha de Alquiler          Precio\n");
            printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
            for(int i = 0; i<tamAlquileres; i++)
            {
                for(int j = 0; j<tamJuegos; j++)
                {
                    if(listaDeAlquileres[i].isEmpty == 0 &&  listaDeAlquileres[i].codigoJuego == listaDeJuegos[j].codigo)
                    {
                        if(listaDeJuegos[j].idCategoria == idCategoria)
                        {
                            mostrarUnAlquiler(listaDeAlquileres[i],listaDeJuegos,listaDeClientes,listaDeCategorias,tamCategoria,tamJuegos,tamClientes);
                            flag = 1;
                        }
                    }
                }
            }

        }

        if(!flag)
        {
            printf("No hay alquileres dados de alta con esa categoria\n");
        }

    }
    return retorno;

}
int mostrarJuegoFavorito(eAlquileres listaDeAlquileres[],eJuego listaDeJuegos[], int tamJuegos,int tamAlquileres)
{
    int error = 1;
    int contadores[tamAlquileres];
    int mayor = 0;
    int flag = 0;


    for(int i = 0; i<tamJuegos; i++)
    {
        contadores[i]  = 0;
    }


    if(listaDeAlquileres != NULL && tamAlquileres > 0 && tamJuegos>0)
    {
        //system("cls");
        printf(" *** JUEGO FAVORITO ***\n");



        for(int i = 0; i<tamAlquileres; i++)
        {
            for(int j = 0; j<tamJuegos; j++)
            {
                if(listaDeAlquileres[i].isEmpty == 0 && listaDeAlquileres[i].codigoJuego == listaDeJuegos[j].codigo)
                {

                    contadores[j]++;
                    error = 0;
               }

            }
        }

        for(int i = 0; i<tamJuegos; i++)
        {

            if(contadores[i] > mayor || flag == 0)
            {
                mayor = contadores[i];
                flag = 1;
            }
        }


        printf("El o los juegos favoritos son: \n\n");

        for(int i = 0; i<tamJuegos; i++)
        {
            if(contadores[i]>= mayor)
            {
                printf("%s\n",listaDeJuegos[i].descripcion);
            }
        }

    }

    return error;
}

int mostrarAcumuladoPorCliente(eAlquileres listaDeAlquileres[],eJuego listaDeJuegos [],eCliente listaDeClientes[],int tamClientes,int tamAlquileres,int tamJuegos)
{
    int error = -1;
    int indice;
    float acumulador[tamClientes];

    if(listaDeAlquileres != NULL && tamAlquileres > 0 && tamJuegos>0)
    {
        printf("*** DINERO A PAGAR POR CLIENTE ***\n");
        for(int i = 0; i<tamAlquileres;i++)
        {

            for(int j = 0; j<tamClientes;j++)
            {
                if(listaDeAlquileres[i].codigoCliente == listaDeClientes[j].codigo)
                {
                    indice = buscarJuego(listaDeJuegos,tamJuegos,listaDeAlquileres[i].codigoJuego);

                    acumulador[i] = listaDeJuegos[indice].importe;
                }
            }
            printf("%.2f\n",acumulador[i]);
        }
    }

    return error;
}

