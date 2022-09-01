#include "header.h"

/* I dati di input della suguente function sono: l'array di record(Dizionario),il suo size e la parola ricercata dall`utente(tutti per valore). La finalita` della function e`confrontare quest`ultima con ogni
parola contenuta nel dizionario.Il dato di output e` una variabile di tipo intero,cioe` un numero che,nel caso in cui l`esito del confronto dovesse essere positivo, assumerebbe valore 0,
mentre nel caso in cui l`esito dovesse essere negativo,la variabile assumerebbe valore -1.   */

int ricerca_binaria_iterativa(struct parola dizionario[], int n, char ricerca[]) 
{
	int l,r,m;
	l = 0;
	r = n-1;
	while(l<=r) {
		m = (l+r)/2;
		
		if (strcmp(dizionario[m].nome,ricerca)==0)
			return m; // valore x trovato alla posizione m
		else if (strcmp(dizionario[m].nome,ricerca) > 0)
			r = m-1;
		else
			l = m+1;  
	}
	// se il programma arriva a questo punto vuol dire che
	// il valore x non è presente in lista, ma se ci fosse
	// dovrebbe trovarsi alla posizione r (nota che qui r==l)
	return -1;
} 

/*/* I dati di input della seguente function sono: l'array di record(Dizionario),il suo size (entrambi passati per valore).L'obiettivo della function e`quello di confrontare ogni lettera di 
ogni parola del dizionario con ogni singola vocale contenute in una stringa per trovare la parola con piu`vocali e assegnarla al unico dato di output:un array di stringhe(passato per indirizzo). */

void conta_voc(struct parola dizionario[],int n, char *voc)
{
	int i,j,x,max=0,cont=0;
	int b;
	
	char vocali[]={'a','e','i','o','u'};
	for(i=0; i<n; i++)
	{
		for(x = 0; x < strlen(dizionario[i].nome); x++)
		{
			for(j=0;j<5;j++)
			{
				if(dizionario[i].nome[x] == vocali[j])
				{
					cont++;
			 		if(cont>max)
			 		{
			    		max=cont;
			    		for(b = 0; b < 20; b++)
			    			voc[b] = '\0';
			    	
			    		strcpy(voc,dizionario[i].nome);
			 		}
		   		}
			}
		}
		cont = 0;
	}
}

