//luis-fbs

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t p = fork();

	if(p > 0) {
		int nps, i = 0;

		printf("Numero de processos: ");
		scanf("%d", &nps);

		printf("Pai de todos: %d\n", getpid());

		for(i; i < nps && p > 0; i++, p = fork());

		if (p > 0) wait(NULL);
		else if(p == 0) printf("Filho %d: %d, Pai: %d\n", i, getpid(), getppid());
	}

	return 0;
}
