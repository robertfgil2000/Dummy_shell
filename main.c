/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: John Sanabria - john.sanabria@correounivalle.edu.co
 * Fecha: 2021-02-26
 */

 /// NOTA: CAMBIAR EL NOMBRE main DEL ARCHIV (EN REPL.IT SÓLO SE CORRE SI EL NOMBRE ES main)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {
  //char comando[BUFSIZ]; // Eliminamos esto, porque los parámetros ya los otorga argv
  char **vector[argc-1];
  

  if(argc < 2) {
	printf("Indique el programa que desea ejecutar\n");
  }else{ 

    pid_t pid;
    
    pid = fork();
    if (pid < 0) {
      perror("No se pudo crear un proceso\n");
      exit(1);
    } else if (pid == 0) {
      
    
      for(int i=0; i<argc-1;i++){
        vector[i] = &argv[i+1];
      }

      printf("%s o %s",argv[0],argv[1]);

      execvp(*vector[0],*vector);
      perror("Return from execlp() not expected");
      exit(EXIT_FAILURE);
    } else {
      wait(NULL);
    }

  }
  return 0;
}