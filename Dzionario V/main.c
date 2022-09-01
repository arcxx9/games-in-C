#include "header.h"
//-------------------------------------------------------------------------------------------------------------------------------
// Progetto d`esame di Laboratorio di Programmazione I di Antonio Sommella 01240011689
/* Il seguente codice simula il dizionario della lingua italiana ,dove ogni parola contiene il significato e i relativi sinonimi.
   La finalita` dell` algoritmo e` quello di permettere all utente di ricercare una parola nel dizionario , visualizzarne il 
   significato e di poter visualizzare quale tra queste contiene piu` vocali */
//-------------------------------------------------------------------------------------------------------------------------------



int main()
{
	int i,j, scelta,massimo;
	int k=0;
	int n=63; //grandezza del dizionario
	char ricerca[20],p[20];

	Parola dizionario[]={
            {'a',"albergo","edificio nel quale si dà alloggio o anche vitto a pagamento","hotel,pensione, motel, ostello, locanda, osteria"},
            {'a',"albero","pianta con fusto alto, legnoso, provvisto di rami nella parte superiore","pianta,tronco,fusto,ceppo"},
            {'a',"anaconda","(Eunectes murinos) serpente della famiglia dei Boidi, dell'ordine degli Squamati, diffuso nelle foreste tropicali del Sudamerica"},
			{'b',"bacheca","cassetta con coperchio di vetro spesso inclinato, nella quale si espongono cose preziose, libri rari e simili","di musei, sale d’esposizione) vetrina, vetrinetta, teca"},
 	        {'b',"bacio","gesto di affetto, amore, passione, rispetto, devozione, ecc., compiuto accostando le labbra su qualcuno o qualcosa e talora facendole schioccare; anche in formule di saluto verbali o epistolari","fam. al bacio: alla perfezione; fig. bacio di Giuda: tradimento."},
			{'b',"bacheca","cassetta con coperchio di vetro spesso inclinato, nella quale si espongono cose preziose, libri rari e simili","di musei, sale d’esposizione) vetrina, vetrinetta, teca"},
			{'b',"biro","Penna a sfera","penna"},
			{'c',"canto","Emissione di suoni modulati ","vocalizzo,voce modulata, gorgheggio" },
			{'c',"casa","Struttura utilizzata dall'uomo per ripararsi dagli agenti atmosferici.","edificio, stabile, costruzione, fabbricato,abitazione"},
			{'c',"conto","Insieme di scritture relative ad un dato oggetto di cui si mette in evidenza la variabile e commensurabile grandezza","1. calcolo, conteggio, computo, somma,parcella"},
			{'c',"culla","Mobile in cui vengono tenuti i neonati","lettino,fig. luogo di origine, terra natale, natali"},
			{'d',"dado","cubetto recante su ciascuna delle sei facce un numero dall'uno al sei, segnato per mezzo di puntini; serve per parecchi giochi, spesso d'azzardo","(arch.) piedistallo, basamento"},
			{'d',"daga","spada larga e corta con lama a due tagli","Gener. spada."},
			{'d',"danno"," tutto ciò ché nuoce materialmente o moralmente","danneggiamento, rottura, guasto, rovina, deterioramento"},
			{'e',"erba","ogni pianta il cui fusto rimane verde e tenero, senza diventare legnoso","pianta erbacea,verdure, ortaggi, erbaggi; spezie, droghe"},
			{'e',"etichetta"," cartellino che si applica su oggetti vari e specialmente su recipienti, per indicare alcune caratteristiche del contenuto","cartellino, targhetta, fascetta, marchio, adesivo"},
			{'e',"etico"," proprio dell'etica, relativo alla filosofia morale","morale, moralistico","morale, moralistico"},
			{'f',"fabbro","artigiano che lavora il ferro"," fig., lett. artefice, creatore"},
			{'f',"fachiro","asceta musulmano o indiano","Gener. asceta."},
			{'f',"facilita`","l'essere facile","semplicità, comodità, agio"},
			{'g',"galassia","ogni sistema stellare, e specialmente la Via Lattea","estens. sistema stellare, sistema di stellefig. gruppo, circolo, ambiente, sfera, mondo, universo, insieme"},
			{'g',"gelatina","brodo di carne o pesce solidificato mediante raffreddamento o mediante aggiunta di sostanze collose","brodo solidificato; confettura"},
			{'g',"gatto","mammifero carnivoro domestico dal corpo agilissimo e flessuoso, capo rotondo, occhi fosforescenti, baffi (vibrisse) sul labbro superiore, zampe con artigli retrattili (famiglia: Felidi)","micio,gattino,amento"},
			{'h',"hacker","gergale chi riesce a inserirsi illegalmente in un sistema di elaborazione per disturbarlo o sabotarlo, superandone le protezioni e le restrizioni di accesso","cracker, pirata informatico."},
			{'h',"hotel","Impresa ricettiva che fornisce un alloggio previo pagamento, utilizzato solitamente per soggiorni di breve durata e specialmente dai turisti.","albergo, pensione, motel"},
			{'i',"ibernazione","trattamento per cui si determina un abbassamento della temperatura corporea durante interventi chirurgici difficili","letargo, svernamento"},
			{'i',"icona","nell'arte bizantina e russa, immagine sacra dipinta su tavola","segno visivo, figura, immagine."},
			{'i',"iettatore","nasce quasi per scherno e per gioco, ma spesso la situazione degenera e la vittima di queste prese in giro può trovare serie difficoltà di integrazione, al punto di venire isolato - o di isolarsi volontariamente - dalla propria comunità, fino ad arrivare a gesti estremi, come il suicidio oppure la vendetta personale.","menagramo (s.m.), uccello del malaugurio (s.m.)" },
			{'l',"labirinto","edificio con un complesso di stanze e corridoi assai intricati","fig. confusione, caos, ginepraio, intrigo, imbroglio, groviglio, intrico, garbuglio, inviluppo."},
			{'l',"laboratorio","complesso di locali attrezzati per ricerche scientifiche"," fabbrica, officina, bottega, Specif. manifattura, opificio"},
	     	{'l',"lasagne ","si indica generalmente una pasta all'uovo tagliata in grossi quadrati, o rettangoli, usati soprattutto per pasticci al forno","pasta"},
			{'m',"macchina","insieme di componenti, di cui almeno uno mobile, collegati tra loro, dotati di azionatori, circuiti di comando, ecc... e connessi solidalmente per un'applicazione ben determinata, capace quindi di compiere lavoro con una forza di natura diversa da quella dell'uomo (ad eccezione delle macchine semplici).","congegno, dispositivo, apparecchio, meccanismo, apparecchiatura"},
			{'m',"mano","organo prensile che si trova all'estremità del braccio, collegato a questo tramite il polso","organo tattile; palma, palmo, le dita,fig.stile"},
			{'m',"mela","La mela e' il frutto (più precisamente si tratta di un falso frutto a pomo) del melo."},
			{'n',"narcisista","persona dedita al culto esclusivo e sterile di sé o della propria personalità; chi è affetto da narcisismo","vanesio, innamorato di sé, fatuo, vanitoso"},
			{'n',"nave","un mezzo di trasporto studiato per il trasporto su acqua di merci o persone","imbarcazione, Specif. bastimento, vascello, veliero, lett. legno."},
			{'n',"nido","luogo di rifugio costruito da molti animali per proteggere le proprie uova dai predatori."," (di animali) ricovero, riparo, tana,fig. casa, dimora"},
			{'o',"obbligo","incolo imposto da una legge, da un'autorità o da ragioni morali","imposizione, dovere, impegno, vincolo, coercizione, peso, onere, responsabilità"},
			{'o',"obsolescenza","invecchiare, diventare inutili"},
			{'o',"oca","nome italiano di un numero considerevole di uccelli, appartenenti alla famiglia Anatidae. Questa famiglia include anche i cigni, la maggior parte dei quali sono più grandi delle oche, e le anatre, piu' piccole.","papera, papero,fig. (spec. di donna) stupido, ingenuo, sciocco."},
			{'p',"pacco","involto ben legato","pacchetto, scatola, involucro, fagotto, cartoccio, rotolo, carico, fardello, imballaggio, collo"},
			{'p',"paese","grande estensione di territorio abitato e coltivato","centro abitato, villaggio, borgo, borgata, località"},
		    {'p',"pane","prodotto alimentare ottenuto dalla lievitazione e successiva cottura in forno di un impasto a base di farina di cereali e acqua, confezionato con diverse modalità, arricchito e caratterizzato sovente da ingredienti prettamente regionali.","pagnotta, panino, sfilatino, filone, baguette"},
			{'q',"quadro","(geometria) che ha quattro lati, che è di forma squadrata","spazio quadrato, riquadro"},
			{'q',"quarantena","(geometria) che ha quattro lati, che è di forma squadrata","isolamento, segregazione"},
			{'r',"rabbia","violento turbamento dell'animo irritato","collera, ira, odio, irritazione, rancore"},
			{'r',"radice","parte delle piante superiori che solitamente si addentra nel terreno ed ha funzione di sostegno e di assorbimento degli alimenti","(di piante) radica, barba, ceppo, bulbo, tubero, rizoma"},
			{'r',"raro","non comune, non frequente","particolare, singolare, originale, speciale, straordinario, eccezionale, curioso"},
			{'s',"sabbia","deposito di minutissimi detriti provenienti dalla disgregazione delle rocce","arena, lett. rena"},
			{'s',"saccarosio","denominazione scientifica dello zucchero comune, costituito da glucosio e fruttosio","zucchero"},
			{'s',"sacerdote","ministro del culto","prete, religioso, ecclesiastico, padre, reverendo"},
			{'t',"taccagno","che è molto attaccato al denaro","avaro, spilorcio, tirchio, pitocco"},
			{'t',"tacchino","grosso uccello da cortile commestibile dal corpo pesante, con penne nerastre, testa e collo nudi rosso-violacei, coda erigibile a ruota nel maschio (famiglia: Fasianidi)","uccello"},
			{'t',"taccia","mputazione attribuita dalla voce pubblica","nomea, fama, cattiva fama."},
			{'u',"uccelleria","negozio in cui si vendono uccelli domestici vivi"},
			{'u',"ufficiale","estinato ad un ufficio, di ufficio"," formale, pubblico, legale, riconosciuto, autorizzato"},
			{'u',"uggiosamente","(avv.)In modo uggioso; noiosamente, fastidiosamente","noiosamente,fastidiosamente"},
			{'u',"uva","frutto della vite"," uva di mare: sargasso, Gener. alga; uva spina: uva selvaggia, ribes."},
			{'v',"vacca"," Femmina adulta dei bovini: una mandria di vacche; la v. ha partorito due vitelli","mucca, Specif. giovenca"},
			{'v',"vaccino","Preparato medico ottenuto con batteri o virus morti o vivi","vaccinazione, antidoto."},
			{'v',"vagabondo"," Di persona senza fissa dimora che vive spostandosi da un luogo all'altro","girovago, nomade, sradicato, ambulante"},
			{'z',"zattera","Piattaforma galleggiante di forma quadrata o rettangolare, costituita di tavole o tronchi congiunti insieme mediante cavi, usata per trasportare persone o cose su acque marine o fluviali",""},
			{'z',"zavorra","Peso costituito da materiale solido o liquido, che si dispone all'interno di un natante per assicurargli giusto assetto, equilibrio e stabilità","contrappeso, peso, massa"},
			{'z',"zelante","Che ha, che mostra zelo, fervore per qualcosa","attento, scrupoloso, premuroso, diligente, sollecito"},
	};
	do{
		printf("\t\tDizionario della lingua italiana\n");
		printf("\n\tScegli l'opzione 1 o 2\n\n\t1: Ricerca il significato una parola\n\t2: Visualizzare la parola del dizionario contenente piu vocali\n\n\t0: ESCI\n\n");
		scanf("%d", &scelta);
		switch (scelta){                                                                                     
			case 1:// Inserire parola della quale si vuole sapere il significato	
				fflush(stdin);
				printf("\t\tRICERCA SIGNIFICATO\n");
				fflush(stdin);
				printf("Inserisci la parola da ricercare\n");
				fflush(stdin);
				gets(ricerca);                
				printf("%s\n", ricerca);
				k = ricerca_binaria_iterativa(dizionario, n, ricerca);
				if(k!=-1)
				{
					printf("Lettera: %c\n",dizionario[k].lettera);
					printf("\tNome: %s\n",dizionario[k].nome);
					printf("\tSignificato: %s\n",dizionario[k].significato);
				}
				else
					printf("Parola non presente nel dizionario.\n\n");
			break;
			case 2:  // Ricerca della parola da visualizzare contenente più vocali
			    conta_voc(dizionario,n, p);
			    printf("La parola e`: %s",p);
				break;
			case 0: // Uscita dal programma
				printf("A presto :)\n");
			break;
		
			//condizione di errore
			default:
				printf("Scelta non corretta.\n");
			break;
			system("PAUSE");
		}
	}while(scelta != 0);
	return 0;
}
