#include <stdio.h>
#include <string.h>
#include "persona.h"

int main(int argc, char const *argv[])
{
	
	persona p1;
	strcpy(p1.nombre,"Juan");
	strcpy(p1.apellido,"López");
	fecha fnac={1960 , 10 , 17};
	p1.fecha_nac = fnac;

	printf("Nombre:%s, %s\nEdad: %d", p1.apellido, p1.nombre, obtener_edad(&p1));
	return 0;
}

