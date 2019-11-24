// Ejemplo uso de PTHREADS
#include <pthread.h>
#include <stdio.h>
	
int sum = 0;

void *suma(void *num) { // hebra
	
	// num es un puntero, porque al crear el hilo necesitamos parsarle un puntero a los argumentos de la función
	// Para poder comparar con i, que es un int, tenemos que convertir a num en un integer
	
	// (int *)num  -> El argumento nos llega como un (void *num), es decir, nos llega como un puntero a void
	// El primer paso es decirle que ese argumento es un puntero a int, no a void, a si que hacemos un cast: (int *)num 
	// El segundo paso es obtener el valor del argumento al que estamos apuntando. Para obtener el valor se usa *, a si que: *(int *)num 
	int limite = *(int *) num;

	for(int i = 0; i <= limite; i++)
		sum += i; // En la variable global sum , vamos guardando el resultado de ir sumando

	// Una vez hemos terminado, matamos el hilo
	// To allow other threads to continue execution, the main thread should terminate by calling pthread_exit() rather than exit(3).
	pthread_exit(NULL);
}

int main() {

	pthread_t tid;

	int N = 10;

	// Creamos un nuevo hilo: pthread_create()
		// &tid es el thread id 
		// NULL es el puntero a uns estructura que define los atributos
		// suma es el puntero a la subrutina que será ejecutada por el hilo
		// (void *) &N es el puntero a void que contiene los argumentos que hay que pasarle a la función
	pthread_create(&tid, NULL, suma, (void *) &N);

	// Esperamos a que finalice el hilo
	// tid es el thread id del hilo que estamos esperando
	// NULL puntero a la localización donde se guarda el output del hilo al que estamos esperando
	pthread_join(tid, NULL);

	printf("SUMA = %d\n", sum); //SUMA = suma de los N primeros numeros

	return 0;
}

// Para utilizarla se debe incluir la directiva #include <pthread.h>
// Para compilar haciendo uso de la librería Pthread se debe incluir “-lpthread” en la compilación. 
// Ej: gcc SO_Tema4_Diapos_Thread.c -o hilos -lpthread


/*
pthread_create: used to create a new thread
Syntax:
int pthread_create(pthread_t * thread, 
                   const pthread_attr_t * attr, 
                   void * (*start_routine)(void *), 
                   void *arg);

Parameters:
	thread: pointer to an unsigned integer value that returns the thread id of the thread created.
	attr: pointer to a structure that is used to define thread attributes like detached state, scheduling policy, stack address, etc. Set to NULL for default thread attributes.
	start_routine: pointer to a subroutine that is executed by the thread. The return type and parameter type of the subroutine must be of type void *. The function has a single attribute but if multiple values need to be passed to the function, a struct must be used.
	arg: pointer to void that contains the arguments to the function defined in the earlier argument



pthread_join: used to wait for the termination of a thread.
Syntax:
int pthread_join(pthread_t th, void **thread_return);

Parameters: 
	th: thread id of the thread for which the current thread waits.
	thread_return: pointer to the location where the exit status of the thread mentioned in th is stored.
*/


/*
PROGRAM OUTPUT:
	➜ T4_Ejemplos git:(t4/ejercicios) ✗ ./hilos
   	SUMA = 55
*/

