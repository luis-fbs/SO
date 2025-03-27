//luis-fbs

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#define NFILHOS 5

int main(){
	pid_t ps = 0;
	int i = 0;

	for(i; i < NFILHOS && ps == 0; i++, ps = fork());

	if(ps > 0){
		wait(NULL);
		if (i == 1) printf("Primeiro pai: %d\n", getpid());
                else printf("Filho %d: %d, Pai: %d\n", i, getpid(), getppid());
	}

	return 0;
}
