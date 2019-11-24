//  REDIRECCIONES CON PIPES
/*
	§ Se puede comunicar dos procesos redirigiendo la salida
	  estándar del primero a la entrada estándar del segundo
	  mediante pipes y dup.
	§ Ejemplo: comunicación padre-hijo donde ambos hacen exec().
*/

int fd[2], pid;

pipe(fd);
pid = fork();

// PROCESO PADRE
if (pid > 0) {
	close(fd[0]);
	close(STDOUT_FILENO);
	dup(fd[1]);
	close(fd[1]);
	exec...(...);
...
}

// PROCESO HIJO
else if (pid == 0) 

{
	close(fd[1]);
	close(STDIN_FILENO);
	dup(fd[0]);
	close(fd[0]);
	exec...(...);
...
}