// EJERCICIOS PROPUESTOS - TEMA 3 - MYCD
/*
Escriba un programa en C llamado “mycd” que cambie el directorio actual. Dicho programa debe permitir tanto el acceso mediante rutas absolutas como relativas, además de la posibilidad de acceder al directorio especificado en la variable HOME si no recibe ningún argumento, escribiendo la ruta absoluta del nuevo directorio actual de trabajo. 

Ejemplo: 
	$ ./mycd /home/user/directorio 
		/home/user/directorio 
	$ ./mycd 
		/home/user/ 
Algunas llamadas al sistema y funciones necesarias: chdir(2), getenv(3), getcwd(3) 

*/
