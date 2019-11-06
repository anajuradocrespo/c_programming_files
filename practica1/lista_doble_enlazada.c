// SO - PRÁCTICA 1 - lista_doble_enlazada.c
// LISTA DOBLEMENTE ENLAZADA - ARCHIVO FUENTE .c
/********************************************************
 * NOMBRE DEL FICHERO: lista_doble_enlazada.c 		    *
 * 													   	*
 * PROPÓSITO: Implementar las funciones de la librería 	*
 *			  descrita en lista_doble_enlazada.h       *
 * 			  y sus funciones auxiliares.               *
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

/*
 * Function: init_list
 * ---------------------------------
 *  Crea una nueva lista con la funcion de ordenacion que se pase como paremetro
 * 	Si se pasa NULL utilizará la funcion dummy_order_function
 * 	Inicializa los campos de la lista
 * 
 * 	ord_fun: La funcion que quiere que se utilice para comparar elementos de la lista al introducir uno nuevo
 * 		Si se pasa NULL utilizará la funcion dummy_order_function
 *
 * 	returns: Devuelve la lista preparada para su uso
 */
s_dllist_start_end* init_list(d_output_order_function ord_fun){
	s_dllist_start_end* new_dllist=(s_dllist_start_end*)malloc(sizeof(s_dllist_start_end));
	
	new_dllist->start=NULL;
	new_dllist->end=NULL;
	new_dllist->order_function=(d_output_order_function)malloc(sizeof(d_output_order_function));
	
	if (ord_fun!=NULL) {
		new_dllist->order_function=ord_fun;
	}
	else {
		new_dllist->order_function=dummy_order_function;
	}

	return new_dllist;
}

/*
 * Function: add_node_ordered
 * ---------------------------------
 * Argumentos:
 * 	lista: La lista a la cual agregar el nuevo elemento
 * 	new_line: La cadena a insertar
 *
 * Uso: Inserta un elemento con new_line segun el orden establecido por la funcion que ordena
 *
 */
void add_node_ordered(s_dllist_start_end* lista,char* new_line){
	
	s_node* temp_node_line=(s_node*)malloc(sizeof(s_node)); /**/
	s_node* dllist_iterator = NULL;
	int out_loop=0;

	temp_node_line->line=strdup(new_line);
	(*temp_node_line).prev_node=NULL;
	(*temp_node_line).next_node=NULL;

	if (lista->start==NULL) // El 1º elementos que se agregue será tanto principio como fin de la lista
	{
		(*temp_node_line).prev_node=temp_node_line;
		(*temp_node_line).next_node=temp_node_line;
		lista->start=temp_node_line;
		lista->end=temp_node_line;
	}
	else // Insertará el nuevo elemento de la lista segun el orden
	{
		dllist_iterator=lista->start;
		do{
			if (lista->order_function(temp_node_line->line,dllist_iterator->line)>0){
				insert_node_after(dllist_iterator->prev_node,temp_node_line);
				if(dllist_iterator==lista->start)
					lista->start=temp_node_line;
				out_loop=1;
			}
			else{
				dllist_iterator=dllist_iterator->next_node;
			}

		}while((out_loop==0) && (dllist_iterator!=lista->start));
		if (out_loop==0){ // Caso en el que el elemento debe ir al final de la lista (segun el ocriterio de orden)
			insert_node_after(lista->end,temp_node_line);
			lista->end=temp_node_line;
		}
	}
}

/*
 * Argumentos:
 * 	previous_node: Elemento anterior al cual se insertará el nuevo
 * 	new_line: La cadena a insertar
 *
 * Uso: Inserta un elemento con new_line despues del elemento anterior
 *
 * Return: Devuelve eñ muevo elemento introducido
 */
s_node* insert_node_after(s_node* previous_node,s_node* new_node){
	s_node* temp=previous_node->next_node;
	previous_node->next_node=new_node;
	temp->prev_node=new_node;
	new_node->next_node=temp;
	new_node->prev_node=previous_node;
	return new_node;
}



/*
 * Function: delete_first_node_dll
 * -------------------------------------
 * Deletes the first element of the list
 * 
 *  lista: 
 * 
 * 	returns: Nothing
 */
void delete_node_start(s_dllist_start_end* lista){
	s_node* temp;
	if (lista != NULL && lista->start != NULL){
		temp=lista->start;
		if (lista->start == lista->end){
			lista->start = NULL;
			lista->end = NULL;
		}
		else{
			lista->start=lista->start->next_node;
			temp->prev_node->next_node=temp->next_node;
			temp->next_node->prev_node=temp->prev_node;
		}

		free(temp->line);
		free(temp);

	}
}



/*
 * Argumentos:
 * 	lista: La lista donde se va a eliminar el ultimo elemento
 *
 * Uso: Elimina el ultimo elemento de la cola
 *
 */

void delete_node_end(s_dllist_start_end* lista){
	s_node* temp;
	if (lista!=NULL && lista->start != NULL){
		temp=lista->end;
		if(lista->end==lista->start)
		{
			lista->start=NULL;
			lista->end=NULL;
		}
		else{
			lista->end=lista->end->prev_node;
			temp->prev_node->next_node=temp->next_node;
			temp->next_node->prev_node=temp->prev_node;
		}

		free(temp->line);
		free(temp);

	}
}


/*
 * Argumentos:
 * 	lista: La lista que va a ser eliminada
 *
 * Uso: Borra todos los elemento de la lista
 *
 */
void delete_list(s_dllist_start_end* lista){
	while(lista!=NULL && lista->start!=NULL)
		delete_node_end(lista);
}


// FUNCIONES AUXILIARES

/*
 * Argumentos:
 * 	c1: Cadena 1
 * 	c2: Cadena 2
 *
 * Uso: Funcion de ordenacion por defecto, siempre indica que el 1º elemento es mayor que el 2º
 *
 * Return: Devuelve siempre 1
 */
int dummy_order_function(char* c1,char* c2){
	return 1;
}
