#include "categoria.h"
#include "fecha.h"
#include "cliente.h"
#include "juego.h"

#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct
{
    int codigoAlquiler;
    int codigoJuego;
    int codigoCliente;
    eFecha fechaAlquiler;
    int isEmpty;


}eAlquileres;


#endif // ALQUILERES_H_INCLUDED

/*Brief Para incicar que todas las posiciones en el array estan vacias
 * esta funcion recorre el array y pone el flag"isEmpty" en 1,retorna 0 si se ejecuto correctamente
 * 1 si no se pudo realizara
 *
 * param listaDeAlquileres
 * param tamanioAlquileres del array que pasamos por referencia
 * return 0 si esta ok o 1 si salio mal
 */
int inicializarAlquilers(eAlquileres listaDeAlquileres[],int tamanioAlquileres);

/*Brief La funcion buscarLibreAlquiler recorre el array en busca de la primer posicion libre y la retorna si la encontro

 * param listaDeAlquileres
 * param tamanioAlquileres del array que pasamos por referencia

 * return la posicion libre en el array
 */

int buscarLibreAlquiler(eAlquileres listaDeAlquileres[], int tamanioAlquileres);


/*Brief La funcion altaAlquiler solicita al usuario que ingrese los datos que va a llevar el alquiler que ingresemos al sistema a traves de los vectores
 * estructura "listaDeAlquileres,listaDeClientes,listaDeJuegos, y sus respectivos tamanios, para luego una vez que asigno los datos y el puntero al ID autoincremental
 *
 * param  listaDeClientes vector estructura de clientes
 * param  listaDeAlquileres vector estructura de empleados
 * param  tamEmpleados  vector estructura de empleados
 * param  tamanioClientes vector estructura de clientes
 * param  pIdAlquiler puntero a la variable id autoincremental
 * param listaDeJuegos vector estructura de juegos
 * param tamJuego tamanio de lvector juegos

 * return 0 si esta ok o 1 si salio mal
 */

int altaAlquiler(eAlquileres listaDeAlquileres[],eCliente listaDeClientes[],eEmpleado listaDeEmpleados[], int tamEmpleados, int tamClientes, int tamanioAlquileres,int* pIdAlquiler,eJuego listaDeJuegos[], int tamJuego);
//int altaAlquiler(eAlquileres listaDeAlquileres[],eCliente listaDeClientes[], int tamClientes, int tamanioAlquileres,int* pIdAlquiler,eJuego listaDeJuegos[], int tamJuego);

/*Brief la funcion listarAlquilers recibe listaDeAlquileres y tamanio del listado, listaJuegos, listaClientes, listaDeCategorias y sus respectivos tamanios
 *
 * param listaDeClientes vector de estructura de clientes
 * param listaDeAlquileres vector de estructura de alquileres
 * param listaJuegos vector de estructura de juegos
 *return 0 si salio bien 1 si salio mal
 */
int listarAlquilers(eAlquileres listaDeAlquileres[],int tamAlquilers,eJuego listaJuegos[],eCliente listaClientes[],eCategoria listaDeCategorias[],int tamcategorias,int tamJuego, int tamCliente);

/*Brief la funcion bajaAlquiler recibe la lista de alquileres el tamanio del alquiler y relaaciona el id del cliente dado de baja para dar de baja el alquiler
 *
 * param tamAlquileres tamanio vec
 * param listaDeAlquileres vector de estructura de alquileres
 * param idCliente id del cliente dado de baja
 *return 0 si salio bien 1 si salio mal
 */
int bajaAlquiler(eAlquileres listaDeAlquileres[],int tamAlquileres,int idCliente);

/*Brief la funcion verificarExistenciaALquiler recibe la lista y el tamanio su tarea es determinar si esta cargado almenos 1 vez
 *
 * param tamAlquileres tamanio vec
 * param listaDeAlquileres vector de estructura de alquileres

 *return 0 si salio bien 1 si salio mal
 */
int verificarExistenciaAlquiler(eAlquileres listarAlquileres[], int tamAlquileres);

/*Brief la funcion mostrarAlquiler recibe el alquiler de esa posicion y listaws de juegos, clientes, categorias y sus tamaños para mostrarlo 1 vez
 *
 * param tamAlquileres tamanio vec
 * param unAlquiler estructura alquiler
 * param listaJuegos vector de estructura de juegos
 * param listaClientes vector de estructura de clientes
 * param listaDeCategorias vector de estructura de categorias
 * param tamcategorias tamanio
 * param tamJuego tamanio
 * param tamCliente tamanio

 *return 0 si salio bien 1 si salio mal
 */
void mostrarUnAlquiler(eAlquileres unAlquiler,eJuego listaJuegos[],eCliente listaClientes[],eCategoria listaDeCategorias[],int tamcategorias,int tamJuego, int tamCliente);

/*Brief la funcion obtenerDescripcionJuego reibe la lsita de juegos, su tamaño, el id del juego buscado, vector para caergar la descripcion y el precio
 *
 * param*precio
 * param descripcionJuego
 * param idJuego tamanio vec
 * param tamJuegos estructura alquiler
 * param listaJuegos vector de estructura de juegos
 * return 0 si salio bien 1 si salio mal
 */
int obtenerDescripcionJuego(eJuego listaDeJuegos[],int tamJuegos, int idJuego, char descripcionJuego[],float *precio);
int obtenerDescripcionCliente(eCliente listaDeClientes[], int tamanioClientes, int id, char nombreCliente[], char apellidoCliente[]);
int obtenerDescripcionCategoria(eCategoria listaDeCategorias[],eJuego listaDeJuegos[],int tamJuegos,int tamcategorias,int idJuego, char descripcionCategoria[]);

int listarPorCategoria(eAlquileres listaDeAlquileres[],eCategoria listaDeCategorias[],eJuego listaDeJuegos[],eCliente listaDeClientes[],int tamClientes, int tamJuegos,int tamAlquileres, int tamCategoria);
int hardcodearAlquileres(eAlquileres listaDeAlquileres[],int tamanioAlquileres, int *pIdAlquiler);
int mostrarJuegoFavorito(eAlquileres listaDeAlquileres[],eJuego listaDeJuegos[], int tamJuegos,int tamAlquileres);
int mostrarAcumuladoPorCliente(eAlquileres listaDeAlquileres[],eJuego listaDeJuegos [],eCliente listaDeClientes[],int tamClientes,int tamAlquileres,int tamJuegos,eEmpleado listaDeEmpleados[],int tamEmpleados);

/*Brief La funcion mostrarAlquileresPorCliente recibe la lista de alquileres, lista de juegos, lista de clientes, lista de categorias y sus tamanios para hacer la busqueda por ID del cliente
 * para luego mostrar cada alquiler que posee ese cliente
 *
 * param  listaDeClientes vector estructura de clientes
 * param  listaDeAlquileres vector estructura de empleados
 * param  tamEmpleados  vector estructura de empleados
 * param  tamanioClientes vector estructura de clientes
 * param  pIdAlquiler puntero a la variable id autoincremental
 * param listaDeJuegos vector estructura de juegos
 * param tamJuego tamanio de lvector juegos

 * return 0 si esta ok o 1 si salio mal
 */
int mostrarAlquileresPorCliente(eAlquileres listaDeAlquileres[],eJuego listaDeJuegos [],eCliente listaDeClientes[],eCategoria listaDeCategorias[],eEmpleado listaDeEmpleados[], int tamEmpleados,int tamCategorias,int tamClientes,int tamAlquileres,int tamJuegos);
int mostrarAlquileresPorFecha(eAlquileres listaDeAlquileres[],eJuego listaJuegos[],eCliente listaClientes[],eCategoria listaDeCategorias[],int tamAlquileres,int tamcategorias,int tamJuego, int tamCliente);
