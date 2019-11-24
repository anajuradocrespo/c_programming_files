#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 


int main(int argc, char **argv) {
	
	int pipe_des[2]
	int pid;
	char buf[1024];
	
	FILE *fd; // FILE POINTER 
	
	// Creamos el pipeline
	// pipe() nos devuelve: 0 si todo va bien y -1 si hay algún error
	// En este caso no utilizamos ese output para comprobar si la creación del pipeline ha ido bien o no
	pipe(pipe_des);
	
	// Creamos un nuevo proceso. 
	// pid es el resultado de la creación del proceso hijo. 
				// pid < 0 creación errónea
				// pid = 0, es el proceso hijo
				// pid > 0, es el proceso padre
	pid = fork();

	// Hijo
	if(pid == 0) { 
		//El hijo solo recibe, cierro el pipe[1]
		close(pipe_des[1]); 

		// Tenemos el FILE * con el descriptor del pipe
		fd = fdopen(pipe_des[0], "r"); 
		fgets(buf, 1024, fd);
		fclose(fd);
		printf("Hijo: Recibido el siguiente mensaje: \"%s\"\n ", buf);
	}

	// Padre
	else { 
		//El padre solo envía, cierro el pipe[0]
		close(pipe_des[0]); 

		// Tenemos el FILE * con el descriptor del pipe
		fd = fdopen(pipe_des[1], "w"); 
		fprintf(fd,"Hola hijo");
		
		fflush(fd);
		
		fclose(fd);
		
		wait(NULL);
		
		puts("Padre: El hijo terminó");
	}

	exit(0);
}


/* PROGRAM OUTPUT

*/

/* FILE POINTER

File descriptor is an int whereas a FILE * is a file pointer. The main difference is that the latter is buffered while the former is not.

A file pointer (FILE*) typically contains more information about the stream such as current location, end of file marker, errors on the stream etc. 
But a file descriptor is simply a positve integer representing a "file" (which could a pipe, socket or any other stream).

You can get file descriptor from file pointer using fileno():   int fd = fileno(fp);
*/