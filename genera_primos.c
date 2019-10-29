// GENERA-PRIMOS
#include <stdio.h>

// Funcion que nos dice si un número es primo o no.
// primo = 0 es FALSE
// primo = 1 es TRUE
int es_primo(int n){
	int i, j, primo;
	primo = 1;
	for (j=2; j<=n/2; j++)
		if (n % j == 0){
			primo = 0;
			break;
		}
	return primo
}

int main(void){
	// Necesitamos un descriptor de fichero, que no es más que un puntero a FILE (tipo de dato que está incluído en la definición de stdio.h)
	FILE * fp; // descriptor de fichero (es un entero no negativo)
	int i, n;

	
	// APERTURA DE UN FICHERO:
	// int open (char* name, int flags [, mode_t mode]);
	fp = fopen("primos.txt", "w");

}