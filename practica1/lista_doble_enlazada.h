// SO - PRÁCTICA 1 - lista_doble_enlazada.h
// LISTA DOBLEMENTE ENLAZADA - ARCHIVO DE CABECERA .h
#ifndef _LISTA_DOBLE_ENLAZADA_H
#define _LISTA_DOBLE_ENLAZADA_H

struct node{
	//char* line;
	char* line;
	struct node* next_line;
	struct node* prev_line;
};

typedef struct node s_node;  // s_node es el alias de struct node (para no tener que poner struct node en todos sitios)

// INICIALIZACIÓN
s_node* new_node_dll();

// INSERCIÓN
void insert_node_end_dll(s_node* lista, char* linea);

/*
// BORRADO
void delete_first_node_dll();
void delete_dll();
*/

// MOSTRAR
void show_lines_std_output();

#endif