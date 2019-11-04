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

//#include "libreria.h"
#include "lista_doble_enlazada.h"

s_node* head; 	/* Variable global. Puntero al primer elemento de la lista*/


/*
 * Function: new_node_dll
 * -------------------------------------
 * Creates a new list instantiting its elements to NULL
 * 
 * 	returns: Pointer to the list. Pointer to the new node
 */
s_node* new_node_dll() {

	s_node* new_node = (s_node*)malloc(sizeof(s_node));
	
	new_node->line = NULL;
	new_node->prev_line = NULL;
	new_node->next_line = NULL;
	
	return new_node;
}

/*
 * Function: insert_node_end_
 * -------------------------------------
 * Inserts a new node at the end of the list. 
 * 
 * 	returns: Nothing
 */
void insert_node_end_dll(s_node* lista,char* linea){
	
	/* Creamos un nodo temporal y un puntero a nodo */
	s_node* new_node = new_node_dll();
	s_node* temp_node = head;

	new_node->line=strdup(linea); 	/* Añadimos la linea a new_node*/

	/* Si el prev_line de lista es nulo, signfica que la lista no existía antes */
	/* Al ser el primer elemento, se va a apuntar a sí mismo */
	/* El puntero HEAD se queda apuntando al primer elemento de la lista*/
	if (head == NULL){
		head = new_node;
		return;
	}
	/* Si head es no nulo, significa que la lista ya tiene al menos un nodo */
    /* 1. Buscamos el último nodo */
    while (temp_node->next_line != NULL) 
    	temp_node = temp_node->next_line; 
  	/* 2. Una vez encontrado el último nodo, insertamos el nuevo nodo creado al final */
    temp_node->next_line = new_node;
    new_node->prev_line = new_node;
}


/*
// BORRADO
void delete_first_node_dll();
void delete_dll();
*/

// MOSTRAR
//Prints all the elements in linked list in forward traversal order
void show_lines_std_output() {
	s_node* temp_node = head;
	printf("La lista es: \n");
	while(temp_node != NULL) {
		printf("%s\n", temp_node->line);
		temp_node = temp_node->next_line;
	}
}

// Para ir probando las funciones
int main(){

	s_node* lista;
	char* buffer;
	size_t bufTam=1024;
	size_t charact = 0;
	int i;

	lista=new_node_dll();

	buffer = (char *)malloc(bufTam * sizeof(char));

	for (i = 0; i < 3; i++){
		charact=getline( &buffer ,&bufTam, stdin);
		{
			insert_node_end_dll(lista,buffer);
		}
	}//end for
	printf("\n"); // Al final de la frase añadimos un salto de linea
	
	// Imprimimos la lista
	show_lines_std_output();



	/*
	printf("new_node: \n");
	printf("	new_node.next_line: %p\n", new_node->next_line);
	printf("	new_node.prev_line: %p\n", new_node->prev_line);
	printf("	new_node.line: %s\n", new_node->line);
	printf("____________________________________________________________\n");
	*/

}

