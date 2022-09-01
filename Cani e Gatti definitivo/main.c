#include "header.h"
//Progetto di laboratorio di programmazione I di Antonio Sommella 0124001689
//Traccia 1: Cani e Gatti
/* Il seguente programma permette di simulare un gioco tra cani e gatti, dove questi ultimi vengono inseguiti dai primi.
Il termine del gioco avviente quando i cani raggiungono il loro obiettivo,ovvero la cattura dei gatti,oppure raggiunto 
un totale di Step(15),pur non avendo conseguito il punto chiave del gioco*/
//-----------------------------------------------------------------------------
// Inizializzazione e ciclo principale programma
//-----------------------------------------------------------------------------
 int main(){
    int  alive1=1, alive2=1, n;
    int  xcat1, xcat2, ycat1, ycat2, xdog1, xdog2, ydog1, ydog2;
    char cat1='g', cat2='G', dog1='C', dog2='c';
    char columns[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    tchess chess = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'}};
    srand(time(NULL));/* Funzione che inizializza lo pseudo-random. Se non ci fosse, ad ogni avvio del programma
                                  la posizione dei cani e dei gatti, sarebbe sempre la stessa.*/
    place_animal(chess, cat1, &ycat1, &xcat1);
    place_animal(chess, cat2, &ycat2, &xcat2);
    place_animal(chess, dog1, &ydog1, &xdog1);
    place_animal(chess, dog2, &ydog2, &xdog2);
    printf("  Posizione iniziale\n");
    print_chess(chess);
    for(n=0; n<MAXSTEP && (alive1 || alive2); n++){
		if (alive1)
            move_cat(chess, cat1, &ycat1, &xcat1);
        if (alive2)
			move_cat(chess, cat2, &ycat2, &xcat2);
        move_dog(chess, dog1, &ydog1, &xdog1, ycat1, xcat1, &alive1, ycat2, xcat2, &alive2);
        move_dog(chess, dog2, &ydog2, &xdog2, ycat1, xcat1, &alive1, ycat2, xcat2, &alive2);
        printf("\n       Step %d\n", n+1);
        print_chess(chess);
        printf("Premere un tasto per continuare.\n");
        getchar();
    }
    return 0;
}
//-----------------------------------------------------------------------------
