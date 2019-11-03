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
 * Function: new_dll
 * -------------------------------------
 * Creates a new list instantiting its elements to NULL
 * 
 * 	returns: Pointer to the list. Pointer to the new node
 */
s_node* new_dll() {

	s_node* new_node = (s_node*)malloc(sizeof(s_node));
	
	new_node->line = NULL;
	new_node->prev_line = NULL;
	new_node->next_line = NULL;
	
	return new_node;
}

/*
 * Function: insert_end_list
 * -------------------------------------
 * Inserts a new node at the end of the list. 
 * 
 * 	returns: Nothing
 */
void insert_end_list(){

    /* Find last node */
    Node *last = (*start)->prev; 
  
    // Create Node dynamically 
    struct Node* new_node = new Node; 
    new_node->data = value; 
  
    // Start is going to be next of new_node 
    new_node->next = *start; 
  
    // Make new node previous of start 
    (*start)->prev = new_node; 
  
    // Make last preivous of new node 
    new_node->prev = last; 
  
    // Make new node next of old last 
    last->next = new_node; 
}




// INSERCIÓN
void insert_end_dll();

// BORRADO
void delete_first_node_dll();
void delete_dll();