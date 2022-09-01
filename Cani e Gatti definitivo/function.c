#include "header.h"

//--------------------------------------------------------------------------------------------
// Distanza tra due punti (Pitagora)

/* Funzione che ha calcola la distanza tra il cane e il gatto,unico dato di output. Tale funzione
ha come dati di input la posizione del cane e gatto sulle asse x asse y della scacchiera */
//--------------------------------------------------------------------------------------------
double distance(int x1, int x2, int y1, int y2){
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));}

//----------------------------------------------------------------------------------------
// Posiziona animale su casella libera

/*Funzione che ha l`obiettivo di inserire l`animale in una posizione ,pseudocasuale,sulla scacchiera. I dati di input
di questa funzione sono la scacchiera e l`animale e come dato di output la sua posizione sulla scacchiera,valore della riga(x) 
e colonna(y) passata per indirizzo inserirlo nella nuova posizione  */
//-----------------------------------------------------------------------------
void place_animal(tchess s, char animal, int* yanimal, int* xanimal){
    while(1){
        int y = rand() % 8;    //Generazione della valore della colonna tra un range [0,7]
        int x = rand() % 8;    //Generazione della valore della riga tra un range [0,7]
        if ('.' == s[y][x]){   // Animale posizionato se coordinate libere
            s[y][x] = animal;
            *yanimal = y;
            *xanimal = x;
            break;}}}

//-----------------------------------------------------------------------------
// Movimento gatto pseudocasuale
/* Funzione che ha l`obiettivo di far muovere il gatto di una casella alla volta in 4 possibili direzioni. I dati di input sono
la scacchiera e il gatto.Come dati di output le coordinate del gatto,passate per indirizzo per modificarne il valore e assegnare
 al gatto la nuova posizone*/
//-----------------------------------------------------------------------------
void move_cat(tchess s, char cat, int *ycat, int *xcat){
     
    int decision = 0;
    short spostato = 0; //Variabile di avvenuto spostamento del gatto
    do{
        decision = rand()%4;
		if(decision == 0){ //andiamo su
			if(*ycat == 0)
				decision = 2;
			else{
                //Controllo se e` possibile effettuare spostamento.
                if(s[*ycat - 1][*xcat] == '.')
                {
                    //Effettuo spostamento
                    *ycat = *ycat-1;
                    s[*ycat+1][*xcat] = '.';
                    s[*ycat][*xcat] = cat;
                    //Confermo l'avvenuto spostamento
                    spostato = 1;
                }
				
			}	
		}
     	
		if(decision == 1){ //andiamo destra
			if(*xcat == 7)
				decision = 3; //andiamo a sinistra
			else{
                //Controllo se e` possibile effettuare spostamento.
                if(s[*ycat][*xcat + 1] == '.')
                {
                    *xcat = *xcat+1;
                    s[*ycat][*xcat-1] = '.';
                    s[*ycat][*xcat] = cat;
                    //Confermo l'avvenuto spostamento
                    spostato = 1;
                }
				
			}
		}
			
		if(decision == 2){ //andiamo giu
			if(*ycat == 7)
				decision = 0; //andiamo su  
			else{
                if(s[*ycat + 1][*xcat] == '.')
                {
                    *ycat = *ycat+1;
                    s[*ycat-1][*xcat] = '.';
                    s[*ycat][*xcat] = cat;
                    //Confermo l'avvenuto spostamento
                    spostato = 1;
                }
			
			}
		}
		
		if(decision == 3){ //andiamo a sinistra
			if(*xcat == 0)
				decision = 1;
			else{
                if(s[*ycat][*xcat - 1] == '.')
                {
                    *xcat = *xcat-1;
                    s[*ycat][*xcat+1] = '.';
                    s[*ycat][*xcat] = cat;
                    //Confermo l'avvenuto spostamento
                    spostato = 1;
                }
				
			}
		}

    }while(spostato == 0);
}

//-----------------------------------------------------------------------------
// Singolo spostamento del cane verso il gatto

/* Funzione che ha l`obiettivo di avvicinare il cane al gatto di una posizione e di verificare la sopravvivenza di quest`ultimo.I dati di input di tale funzione sono la scacchiera,il cane, la posizione del gatto.
I dati di output sono le coordinate del cane e la sopravvivenza del gatto ,passati entrambe per indirizzo */
//-----------------------------------------------------------------------------
void step_dog(tchess s, char dog, int* ydog, int* xdog, int ycat, int xcat, int* alive){
    int y = *ydog;
    int x = *xdog;
    if (y != ycat)    // avvicinamento alle coordinate gatto, la Y ha la precedenza
        if (ycat > y)
            ++y;
        else
            --y;
    else
        if (xcat > x)
            ++x;
        else
            --x;
    // Se le nuove coordinate non sono un cane la mossa
    // viene effettuata, altrimenti sta fermo
    if (s[y][x] != 'c' && s[y][x] != 'C'){
        s[*ydog][*xdog] = '.';
        s[y][x] = dog;
        *ydog = y;
        *xdog = x;
        if (y == ycat && x == xcat)
        {
            // Gatto ucciso se raggiunto
            printf("Gatto e` stato raggiunto da %c.\n", dog);
            *alive = 0;
        }
    }
    
}

//-----------------------------------------------------------------------------
// Scelta del gatto da inseguire, se non ci sono piu` gatti, il cane sta fermo

/* Funzione che ha l`obiettivo di muovere i cani verso i gatti piu` vicini ad essi. I dati di input sono la scacchiera,il cane e le coordinate dei gatti.
I dati di output sono le cordinate del cane passate e la sopravvivenza dei due gatti,passati per indirizzo */
//-----------------------------------------------------------------------------
void move_dog(tchess chess, char dog, int* ydog, int* xdog, int ycat1,
              int xcat1, int* alive1, int ycat2, int xcat2, int* alive2){
    if (*alive1 && *alive2){
        double d1 = distance(*xdog, xcat1, *ydog, ycat1);
        double d2 = distance(*xdog, xcat2, *ydog, ycat2);
        // In caso di distanze uguali si insegue gatto1
        if (d1 <= d2)
            step_dog(chess, dog, ydog, xdog, ycat1, xcat1, alive1); //primo cane va incontro al primo gatto
        else
            step_dog(chess, dog, ydog, xdog, ycat2, xcat2, alive2);} //primo cane va incontro al secondo gatto
    else
        if (*alive1)
            step_dog(chess, dog, ydog, xdog, ycat1, xcat1, alive1); //secondo cane va incontro al primo gatto
        else
            if (*alive2)
                step_dog(chess, dog, ydog, xdog, ycat2, xcat2, alive2);} //secondo cane va incontro al secondo gatto

//-----------------------------------------------------------------------------
// Stampa scacchiera
//-----------------------------------------------------------------------------
void print_chess(tchess s){
    int y, x;
    printf("\n   a b c d e f g h\n\n");
    for(y=0; y<8; y++){
        printf("%d ", 8-y);
        for(x=0; x<8; x++)
            printf(" %c", s[y][x]);
        printf("\n");}
    printf("\n");}

//-----------------------------------------------------------------------------
