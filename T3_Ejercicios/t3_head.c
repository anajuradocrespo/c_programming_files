// EJERCICIOS PROPUESTOS - TEMA 3 - MYHEAD
/*
Escriba un programa en C llamado “myhead” que se comporte como head(1) leyendo de la entrada estándar, 
es decir, que muestra las 10 primeras líneas recibidas por la entrada estándar, 
o las N primeras si se llama al programa con “myhead N”. 
Se debe usar la función fgets(3) pasándole como tercer argumento la constante stdin, de una forma similar a: 
char buf[1024]; 
fgets(buf, 1024, stdin);
*/

// VERSIÓN PROFE
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{	
	// VARIABLES


	int lineas;			// variable entero llamado lineas. Número de líneas que hay que mostrar
	char buf[1024];		// variable array de chars con 1024 posiciones llamado buf
  	int cuenta = 0;		// variable entero llamado cuenta inicializado a 0
	
	// CONTROLAMOS EL NUMERO DE ARGUMENTOS QUE LLEGAN 

	// Si no so se especifica en la llamada el numero de líneas, por defecto vamos a mostrar 10
	if(argc == 1)
	{
		lineas = 10;
	}
	// Si se especifica el numero de líneas que hay que mostrar
	else if (argc == 2)
	{	
		lineas = atoi(num);			// Convertimos el character que nos ha llegado por parametro en integer
		printf("%s\n", argv[1] + 1 );
		char *num = argv[1] + 1; 	// puntero a character llamado num que es al número 
		
	}
	else
	{
		printf("Uso: \"%s -N\" para ver las N primeras líneas, o \"%s\" para las 10 primeras líneas\n", argv[0], argv[0]);
		return 1;
	}
	
  	
	while((cuenta < lineas) && (fgets(buf, 1024, stdin) != NULL))
	{
		printf("%s", buf);
		cuenta++;
	}
	
	return 0;	
}
