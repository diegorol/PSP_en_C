#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char const *argv[])
{
	/* code */
	pid_t pid_padre;
	pid_t pid_actual;
	pid_t pid;
	pid_t pid_hijo;

	pid_actual = getpid();
	pid_padre = getppid();

	fprintf(stdout,"ANTES DEL FORCK\n");
	fprintf(stdout,"\tPid proceso actual: %d\n", pid_actual);
	fprintf(stdout,"\tPid proceso padre: %d\n\n", pid_padre);

	
	pid = fork();

	if(pid == -1){
		fprintf(stderr, "Error en el fork()\n");
		exit(-1);
	}

	if(pid == 0){//Nos encontramos en el proceso hijo
		fprintf(stdout, "En el hijo. PID: %d\n", getpid());
		fprintf(stdout, "En el hijo. PPIDd: %d\n", getppid());
		sleep(5);
	}else{//este será el proceso padre
		fprintf(stdout, "En el Padre. PID: %d\n", getpid());
		fprintf(stdout, "En el Padre. PPIDd: %d\n", getppid());
		pid_hijo = wait(NULL);
		fprintf(stdout, "En el Padre . Mi hijo con pid: %d, ha finalizado\n", pid_hijo);
	}

	return 0;
}
 

    