// SO - PRÁCTICA 1 - lista_doble_enlazada.h
// LISTA DOBLEMENTE ENLAZADA - ARCHIVO DE CABECERA .h
#ifndef _LISTA_DOBLE_ENLAZADA_H
#define _LISTA_DOBLE_ENLAZADA_H

struct node{
	char* line;
	struct nodo* next_line;
	struct nodo* prev_line;
};

typedef struct node s_node;  // s_node es el alias de struct node (para no tener que poner struct node en todos sitios)

/* Funciones */

// INICIALIZACIÓN
s_node* new_dll();

// INSERCIÓN
void insert_end_dll();

// BORRADO
void delete_first_node_dll();
void delete_dll();

#endif