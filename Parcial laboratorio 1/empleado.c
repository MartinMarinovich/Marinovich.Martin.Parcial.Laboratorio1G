
#include "empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hardCodearEmpleados(eEmpleado listaDeEmpleados[], int tamEmpleados)
{
	int error = -1;
	int idEmpleado [8] = {100,101,102,103,104,105,106,107};
	char Empleado [8][51]= {
		"Martin",
		"Alma",
		"Gabriel",
		"Juan",
		"Yamila",
		"Pamela",
		"Lucio",
		"Edward"
	};

    char sexos[8] = {'m','f','m','m','m','f','f','m','m'};

	for(int i = 0; i<tamEmpleados;i++)
	{
		strcpy(listaDeEmpleados[i].nombre,Empleado[i]);
		listaDeEmpleados[i].codigo = idEmpleado[i];
		listaDeEmpleados[i].sexo = sexos[i];

	}


	return error;
}

void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf(" %d         %10s \n",unEmpleado.codigo,unEmpleado.nombre);
}

int listarEmpleados(eEmpleado listaDeEmpleados[], int tamanioEmpleados)
{
	int error = -1;

    if(listaDeEmpleados !=NULL && tamanioEmpleados>0)
	{
    	system("cls");
	    printf(" ****  LISTADO DE EMPLEADOS  ****\n");
	    printf("Id        Nombre\n");
    	printf("----------------------------------\n");

        for(int i = 0 ; i<tamanioEmpleados; i++)
	    {

	    	mostrarEmpleado(listaDeEmpleados[i]);
    	}
        error = 0;
	}
	return error;
}
