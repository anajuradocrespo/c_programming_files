// SO - PRÁCTICA 1 - libreria.c
/********************************************************
 * NOMBRE DEL FICHERO: libreria.c 					   	*
 * 													   	*
 * PROPÓSITO: Implementar las funciones de la librería 	*
 *			  deescrita en libreria.h y sus funciones  	*
 *			  auxiliares.                              	*
 * 														*
 * AUTOR: Ana Jurado 								   	*
 * CREADO: Nov.2019							  			*
 *******************************************************/

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#include "libreria.h"
#include "lista_doble_enlazada.h"

char* buffer;
int nerrno;
int output = 0;
size_t buf_size=2;
size_t charact;
int n_saved_lines = 0;

/*
 * Function: head 
 * --------------------
 * Reads from standar input the first N lines, save them in a list and show them on the standar output
 *  
 *  N: number of lines to show on standar output
 *
 *  returns: Show the N first lines on the standar input. Error code:
 * 			output =0:	Execution OK
 * 			output!=0:	Execution FAIL
 */
int head(int N){
	if (N>0)
	{
		buffer = (char *)malloc(buf_size * sizeof(char)); 	/* Instanciamos el buffer */
		//printf("SIZE OF BUFFER: %lu\n", sizeof(buffer));
		do{
			charact=getline( &buffer ,&buf_size, stdin);
			if (charact==-1) 		/* -1 si EOF o error */
			{
				nerrno=errno;
				if (nerrno!=0){ 	/* charact = -1 debido a un error (no por EOF) */
					fputs(strerror(nerrno), stderr);
					output=2;
				}
			}
			else
			{
				/* Si no ha habido error se lee la linea */
				printf("%s",buffer);	
				N--; /* Decremento numero de lineas que quedan*/
				// printf("N: %d\n", N ); 
			}

		}while(charact!=-1 && N>0); // Mostrará lineas hasta leer las nLineas primeras o llegue al final del fichero
	}
	return output;
}

/*
 * Function: tail
 * --------------------
 * Reads from standar input the last N lines, save them in a list and show them on the standar output
 *  
 *  N: number of lines to show on standar output
 *
 *  returns: Show the N last lines on the standar input. Error code:
 * 			output =0:	Execution OK
 * 			output!=0:	Execution FAIL
 */
int tail(int N){
	if (N>0){
		dll = new_double_linked_list();   /* lista_doble es un puntero al primer nodo de la lista*/

		buffer = (char *)malloc(bufTam * sizeof(char));

		do{
			charact=getline( &buffer ,&buf_size, stdin);
			if (charact==-1) 		/* -1 si EOF o error */
			{
				nerrno=errno;
				if (nerrno!=0){ 	/* charact = -1 debido a un error (no por EOF) */
					fputs(strerror(nerrno), stderr);
					output=2;
				}
			}
			else
			{
				if (n_saved_lines==N) // En el momento en que se alcance el Nº de lineas, eliminará la 1º linea de la cola
				{
					delete_first_node_dll(dll);
				}
				else{
					n_saved_lines++;
				}
				insert_end_dll(dll,buffer); // Introduce al final de la cola la nueva linea
			}

		}while(charact!=-1); // Permanece leyendo lineas hasta que alcanza EOF
		if (output==0) // Solo mostrara el resultado si no ha habido errores
		{
			show_lines_std_output(dll); // Mostrara por pantalla las lineas almacenadas

			delete_dll(dll);
			free(dll);
		}
	}
	return output;
}


show_lines_std_output();
