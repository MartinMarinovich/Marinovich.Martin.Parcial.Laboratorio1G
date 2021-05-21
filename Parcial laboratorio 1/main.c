#include <stdio.h>
#include <stdlib.h>

#include "alquileres.h"
#include "utn.h"
#include "juego.h"
#include "cliente.h"
#include "categoria.h"
#include "empleado.h"


#define TAM_CLIENTES 15
#define TAM_CATEGORIAS 5
#define TAM_JUEGOS 8
#define TAM_ALQUILERES 20
#define TAM_EMPLEADOS 8

int main()
{


    eJuego listaDeJuegos[TAM_JUEGOS];
    eCategoria listaDeCategorias[TAM_CATEGORIAS];
    eCliente listaDeClientes[TAM_CLIENTES];
    eAlquileres listaDeAlquileres[TAM_ALQUILERES];
    eEmpleado listaDeEmpleados[TAM_EMPLEADOS];

    int proximoIdAlquiler = 100;
    int proximoIdCliente = 1;
    int auxModificacion;
    int auxBaja;
    int opcionMenu;

    if(!inicializarClientes(listaDeClientes,TAM_CLIENTES) && !inicializarAlquilers(listaDeAlquileres,TAM_ALQUILERES))
    {
        printf("Sistema inicializado con exito!\n\n");
    }
    else
    {
        printf("Problema para inicializar el sistema\n");
    }


    hardCodearJuegos(listaDeJuegos,TAM_JUEGOS);
    hardCodearCategorias(listaDeCategorias,TAM_CATEGORIAS);
    hardCodearEmpleados(listaDeEmpleados,TAM_EMPLEADOS);
    hardcodearClientes(listaDeClientes,TAM_CLIENTES,&proximoIdCliente);
    hardcodearAlquileres(listaDeAlquileres,TAM_ALQUILERES,&proximoIdAlquiler);

    do
    {
        menu(&opcionMenu);

        switch(opcionMenu)
        {
        case 1:
            if(altaCliente(listaDeClientes,listaDeEmpleados,TAM_EMPLEADOS,TAM_CLIENTES,&proximoIdCliente))
            {

                printf("ALTA EXITOSA!\n");
            }
            else
            {
                printf("Problema para realizar el alta\n");
            }

            break;
        case 2:
            if(verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES)==0)
            {
                auxModificacion = modificarClientes(listaDeClientes,listaDeEmpleados,TAM_CLIENTES,TAM_EMPLEADOS);

                if( auxModificacion == 0)
                {
                    printf("Modificacion exitosa\n");
                }
                else if(auxModificacion == 2)
                {
                    printf("Ha salido de las modificaciones\n");
                }
                else
                {
                    printf("Se ha producido un error en la modificacion\n");
                }

            }
            else
            {
                printf("No hay clientes en el listado\n");
            }
            break;

        case 3:
            if(verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES)==0)
            {
                auxBaja = bajaCliente(listaDeClientes,listaDeEmpleados,TAM_CLIENTES,TAM_EMPLEADOS);

                if(!auxBaja)
                {
                    printf("Baja exitosa\n");
                }
                else
                {
                    if(auxBaja)
                    {
                        printf("La baja ha sido cancelada\n");
                    }
                }
            }
            else
            {
                printf("No hay clientes en el listado\n");
            }
            break;
        case 4:
            system("cls");
            if(!verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES))
            {
                ordenarClientes(listaDeClientes,TAM_CLIENTES),

               // listarClientes(listaDeClientes,TAM_CLIENTES);
             // listarClientes(listaDeClientes,listaDeEmpleados,TAM_CLIENTES,TAM_EMPLEADOS);

               //listarPorCategoria(listaDeAlquileres,listaDeCategorias,listaDeJuegos,listaDeClientes,TAM_CLIENTES,TAM_JUEGOS,TAM_ALQUILERES,TAM_CATEGORIAS);
             // mostrarJuegoFavorito(listaDeAlquileres,listaDeJuegos,TAM_JUEGOS,TAM_ALQUILERES);

            mostrarAcumuladoPorCliente(listaDeAlquileres,listaDeJuegos,listaDeClientes,TAM_CLIENTES,TAM_ALQUILERES,TAM_JUEGOS);
            }
            else
            {
                printf("No hay clientes en la lista\n");
            }

            break;

        case 5:

            if(!verificarExistenciaCliente(listaDeClientes,TAM_CLIENTES))
            {
                //altaAlquiler(listaDeAlquileres,listaDeClientes,TAM_CLIENTES,TAM_ALQUILERES,&proximoIdAlquiler,listaDeJuegos,TAM_JUEGOS)
                if(altaAlquiler(listaDeAlquileres,listaDeClientes,listaDeEmpleados,TAM_EMPLEADOS,TAM_CLIENTES,TAM_ALQUILERES,&proximoIdAlquiler,listaDeJuegos,TAM_JUEGOS))
                {
                    printf("Alta alquiler exirosa!\n");
                }

            }
            else
            {
                printf("No hay clientes en la lista\n");
            }


            break;

        case 6:
            system("cls");
            if(!verificarExistenciaAlquiler(listaDeAlquileres,TAM_ALQUILERES))
            {

                listarAlquilers(listaDeAlquileres,TAM_ALQUILERES,listaDeJuegos,listaDeClientes,listaDeCategorias,TAM_CATEGORIAS,TAM_JUEGOS,TAM_CLIENTES);


            }
            else
            {
                printf("No hay alquileres en la lista\n");
            }

            break;

        }

    }
    while(opcionMenu != 7);

    return 0;
}

