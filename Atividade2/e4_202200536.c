//luis-fbs

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t p = fork();

	if (p > 0){
		p = fork();
		if(p == 0){
			FILE * arquivon;

			arquivon = fopen("numeros", "w");
			if (arquivon){
				for(int n = 1; n < 10; n++)
					fprintf(arquivon, "%d\n", n);
				fclose(arquivon);
			}

		} else {
			wait(NULL);
			wait(NULL);

			FILE * numeros, * letras;
			char linha[4];
			
			numeros = fopen("numeros", "r");
			if(numeros){
				while (fscanf(numeros, "%s", linha) == 1)
					printf("%s\n", linha);
				fclose(numeros);
			}
			
			letras = fopen("letras", "r");
			if(letras){
				while(fscanf(letras, "%s", linha) == 1)
					printf("%s\n", linha);
				fclose(letras);
			}

		}
	} else{
		FILE * arquivol;

		arquivol = fopen("letras", "w");
		if (arquivol){
			for(char l = 'A'; l <= 'Z'; l++)
				fprintf(arquivol, "%c\n", l);
			fclose(arquivol);
		}
	}

	return 0;
}
