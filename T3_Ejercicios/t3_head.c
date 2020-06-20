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
	int lineas;
	char buf[1024];
  	int cuenta = 0;
	
	if(argc == 1)
	{
		lineas = 10;
	}
	else if (argc == 2)
	{
		char *num = argv[1] + 1;
		lineas = atoi(num);		
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
