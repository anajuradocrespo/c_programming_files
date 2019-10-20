#include <stdio.h>
#define LONBUFFER 2561024

int main (void) {
	int fde, fds, nr;
	char *entrada = "entrada";
	char *salida = "salida";
	char buffer[LONBUFFER];

	// Quiero saber qué contiene buffer: the content of buffer is: 0x7ffee8479540
	printf("--------------------------\n");
	printf("the content of buffer is: %p \n", buffer);
	printf("--------------------------\n");

	// WIP
	/*
	if ((fde=open(entrada,O_RDONLY)) < 0) {
		printf("Error al abrir el fichero %s.\n%s.\n", entrada,strerror(errno));

		return 1;
	}
	else if ((fds=open(salida,O_WRONLY|O_TRUNC|O_CREAT,S_IRUSR|S_IWUSR|S_IRGRP,S_IROTH)) < 0) {
		printf("Error al abrir el fichero %s.\n%s.\n", salida,strerror(errno));
		close(fde);
		return 1;
	}
	*/

}