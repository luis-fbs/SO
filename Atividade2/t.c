#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define TAM_CAMINHO 32
#define TAM_NOME_PROGRAMA 16
#define MAX_PARAMETROS 10
#define TAM_PARAMETROS 16


int main(){
	pid_t p;
	char caminho[TAM_CAMINHO] = "/bin/";
	char nomePrograma[TAM_NOME_PROGRAMA];
	int nParametros;

	printf("Nome do programa: ");
	scanf("%s", nomePrograma);
	strcat(caminho, nomePrograma);

	printf("Numero de parametros: ");
	scanf("%d", &nParametros);

	if (nParametros > 0 && nParametros <= MAX_PARAMETROS){
	 	char parametrosLidos[MAX_PARAMETROS][TAM_PARAMETROS];
        	char *parametros[MAX_PARAMETROS + 1];
		char * ambiente[] = { NULL};
		int i = 0;

		for(i; i < nParametros; i++){
			printf("Parametro %d: ", i);
			scanf("%s", parametrosLidos[i]);
		}

		parametros[0] = caminho;
		for(i = 1; i < nParametros; i++) parametros[i] = parametrosLidos[i-1];
		parametros[i] = NULL;

		execve(caminho, parametros, ambiente);
		printf("teste\n");
	}

//	printf("%s\n", caminho);

	return 0;
}
