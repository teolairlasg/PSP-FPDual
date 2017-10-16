#include "persona.h"
#include <time.h>
#include <stdio.h>


unsigned short int obtener_edad(persona *p){

	time_t t =time(NULL);
	struct tm *t_local = localtime(&t);

	short int dia = t_local->tm_mday;
	short int mes = t_local->tm_mon+1;
	short int anyo = (t_local->tm_year)+1900;

	short int edad;

	if(mes > p->fecha_nac.mes || (mes == p->fecha_nac.mes && dia >= p->fecha_nac.dia) ){
		edad = anyo - p->fecha_nac.anyo;
	}else{
		edad = anyo - p->fecha_nac.anyo - 1;
	}
	 
	return  edad;
}