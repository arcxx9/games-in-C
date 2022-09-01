#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct parola{
	char lettera;
	char *nome;
	char *significato;
	char *sinonimi;
};
typedef struct parola Parola;



int ricerca_binaria_iterativa(struct parola dizionario[], int n, char ricerca[]);
void conta_voc(struct parola dizionario[],int n, char *voc);

