// SO - PRÁCTICA 1 - test.c
/********************************************************
 * NOMBRE DEL FICHERO: test.c 					   		*
 * 													   	*
 * PROPÓSITO: Testar las funciones implementadas en     *
 * 			  en la libreria                            *
 * 														*
 * AUTOR: Ana Jurado 								   	*
 * CREADO: Nov.2019							  			*
 *******************************************************/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "libreria.h"

int ret=0;
int n_lineas=10;

int main(int argc,char** argv){

	// Si tenemos un tercer argumento, será el numero de líneas
	char *param;
	if (argc==3){
		// printf("NUMERO DE ARGUMENTOS RECIBIDOS: %d \n" ,argc );
		// printf("\n argv[2][0]: %c \n" ,argv[2][0]);
		if(argv[2][0]=='-'){
			param=argv[2] + 1;
			printf("PARAM: %s \n" ,param);
			if(strlen(argv[2])>1){
				n_lineas=atoi(param); // Se convierte a numero
			}
		}
	}

	// printf("FINAL: n_lineas: %d\n", n_lineas);

	// Comprobamos si el segundo commando es "head"
	if(strcmp(argv[1],"head")==0){
		ret=head(n_lineas);
	}
	return ret;
}


// gcc test.c libreria.c -o test