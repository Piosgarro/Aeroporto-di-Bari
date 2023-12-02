/**
* @file volo.c
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "costanti.h"
#include "menu.h"
#include "data.h"
#include "data_di_iscrizione.h"
#include "svuota_buffer.h"
#include "volo.h"
#include "controlli_voli.h"
#include "passeggero.h"



/**
 * Questa funzione permette di calcolare il numero dei voli aprendo il file e contando tutti i voli.
 * Viene chiamata ad ogni operazione fatta perchè se viene aggiunto un volo, il numero dei voli deve essere aggiornato.
 * @post il numero dei voli presenti nel file voli.
 */
int numero_di_voli()
{
	FILE* file_voli;
	volo voli;
	int i=0;
	if(	(file_voli = fopen("voli.dat","rb")) == NULL)
	{
		printf("Errore nell'apertura\n");
	}
	else
	{
		while(!feof(file_voli))
		{
			int read=fread(&voli,sizeof(volo),1,file_voli);  /// Leggo tutti i dati dei voli e ogni volta incremento la i
			if(read>0)
			{
				i++;
			}
		}
		fclose(file_voli);
	}
	return i;
}

/**
 * Questa funzione carica i dati dal file voli all'array di struct voli per permettere di lavorare su quei dati.
 * @pre numero_dei_voli deve contenere il numero effettivo dei voli
 * @post L'array di struct voli conterra' tutti  i dati dei voli.
 */
int caricamento_voli(volo voli[],int numero_di_voli)   //Codice funzione caricamento_voli: C03
{
	FILE* file_voli;

	if(	(file_voli = fopen("voli.dat","rb")) == NULL)
	{

		return ERRORE;
	}
	else
	{
		for(int i=0;i<numero_di_voli;i++)
		{
			fread(&voli[i],sizeof(volo),1,file_voli);  /// Leggo tutti i dati dei voli dal file e li salvo sull array di struct
		}
		fclose(file_voli);
	}

	return CORRETTO;
}

/**
 * Questa funzione salva i dati dall'array di struct voli al file dei voli.
 * Viene chiamata ogni volta che viene effettuata un'operazione, in modo da aggiornare costantemente il file voli e quindi i dati.
 * @pre numero_di_voli deve contenere il numero effettivo dei voli
 * @pre voli deve contenere tutti i dati dei voli
 * @post I dati dei voli verranno salvati sul file.
 */
int salvataggio_su_file_voli(volo voli[],int numero_di_voli) //Codice funzione salvataggio_su_file_voli: C06
{
	FILE* file_voli;

	if(	(file_voli = fopen("voli.dat","wb+")) == NULL)
	{

		return ERRORE;
	}
	else
	{
		for(int i=0;i<=numero_di_voli;i++)
		{
			fwrite(&voli[i],sizeof(volo),1,file_voli);  /// Scrivo tutti i dati presenti nell array di struct nel file, salvando quindi i dati.
		}
		fclose(file_voli);
	}

	return CORRETTO;
}

/**
 * Questa funzione permette di visualizzare tutti i voli presenti nel progetto.
 * Vengono visualizzati tutti i voli,tranne quelli che sono stati elimininati.
 * @pre voli deve contenere tutti i dati dei voli
 * @pre numero_di_voli deve contenere il numero effettivo dei voli
 * @post I dati di ciascun volo vengono visualizzati nel terminale.
 */
int visualizza_voli(volo voli[],int numero_di_voli) //Codice funzione visualizza_voli: C09
{
	int k=0;
	for(k=0;k<numero_di_voli;k++)
	{
		if (strcmp(voli[k].nome_compagnia,"")!=0)  ///Vizualizzo tutti i voli, eccetto chi ha il nome vuoto, cioe' e' stato eliminato.
		{
			printf("\nVolo: %s\n Nome Compagnia: %s\n Destinazione: %s\n Tipologia  di aereo: %s\n Posti: %d\n Giorno di volo: %d.%d.%d\n Ora di partenza: %d.%d\n Ora di arrivo: %d.%d\n Durata in minuti: %d\n",voli[k].id_volo,voli[k].nome_compagnia,
					voli[k].destinazione,voli[k].tipologia_di_aereo,voli[k].posti,voli[k].giorno_di_volo.giorno,voli[k].giorno_di_volo.mese,
					voli[k].giorno_di_volo.anno,voli[k].ora_di_partenza.ora,voli[k].ora_di_partenza.minuti,voli[k].ora_di_arrivo.ora,voli[k].ora_di_arrivo.minuti,voli[k].durata);
		}

	}
	return 1;
}

/**
 * Questa funzione permette di visualizzare un determinato volo.
 * Viene chiamata ogni volta che nel programma c'e' bisogno di visualizzare un volo, ad esempio quando si modifica o si elimina un volo.
 * @pre voli deve contenere tutti i dati dei voli
 * @pre numero_di_voli deve contenere il numero effettivo dei voli
 * @pre indice_volo deve contenere l'indice del volo che si vuole visualizzare.
 * @post I dati di un determinato volo vengono visualizzati sul terminale.
 */
int visualizza_un_volo(volo voli[],int numero_di_voli,int indice_volo)
{
	if (strcmp(voli[indice_volo].nome_compagnia,"")!=0)   ///Vizualizzo un determinato volo, ma se ha il nome compagnia vuoto(cioe' e' stato eliminato) non lo visualizzo.
	{
		printf("Volo: %s\n Nome Compagnia: %s\n Destinazione: %s\n Tipologia  di aereo: %s\n Posti: %d\n Giorno di volo: %d.%d.%d\n Ora di partenza: %d.%d\n Ora di arrivo: %d.%d\n Durata in minuti: %d\n",voli[indice_volo].id_volo,voli[indice_volo].nome_compagnia,
				voli[indice_volo].destinazione,voli[indice_volo].tipologia_di_aereo,voli[indice_volo].posti,voli[indice_volo].giorno_di_volo.giorno,voli[indice_volo].giorno_di_volo.mese,
				voli[indice_volo].giorno_di_volo.anno,voli[indice_volo].ora_di_partenza.ora,voli[indice_volo].ora_di_partenza.minuti,voli[indice_volo].ora_di_arrivo.ora,voli[indice_volo].ora_di_arrivo.minuti,voli[indice_volo].durata);
	}
	return 1;
}

/**
 * Questa funzione permette di inserire un nuovo volo. Inizialmente vengono controllati che i dati del nuovo volo
 * vengano inseriti correttamente. Infine vengono memorizzati i dati del nuovo volo nell'ultima posizione dell'array di struct.
 * @pre voli deve contenere tutti i dati dei voli.In particolare in questa funzione serve per memorizzare i dati del nuovo volo inserito.
 * @pre numero_di_voli deve contenere il numero effettivo dei voli
 * @post I dati del nuovo volo verranno salvati nell'ultima posizione dell'array di struct volo.
 */
int inserisci_nuovo_volo(volo voli[], int numero_di_voli)
{   //Codice inserisci_nuovo_volo:C14

	setbuf(stdout,NULL);
	volo ultimo;													///Variabile di tipo volo utilizzata contenere i dati del nuovo volo inseriti dall'utente.
	passeggero persona;												///Variabile di tipo passeggero utilizzata per prendere successivamente la data del sistema.
	char posti[MAX_POSTI];											///Vettore "posti" che contiene i posti del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sui posti inserito.
	char giorno[MAX_LUNGHEZZA_GIORNO];								///Vettore "giorno" che contiene il giorno di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sul giorno di volo inserito.
	char mese[MAX_LUNGHEZZA_MESE];									///Vettore "mese" che contiene il mese di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sul mese di volo inserito.
	char anno[LUNGHEZZA_ANNO];										///Vettore "anno" che contiene l'anno di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sull'anno di volo inserito
	char ora[MAX_LUNGHEZZA_ORA_E_MINUTI];							///Vettore "ora" che contiene il l'ora di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sull'ora di volo inserito
	char minuti[MAX_LUNGHEZZA_ORA_E_MINUTI];						///Vettore "minuti" che contiene i minuti di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sui minuti di volo inserito
	int flag0=0;													///Variabile che conterra' 1 se l'id del volo sara' diverso dagli altri,0 altrimenti.
	int flag1=0;													///Variabile che conterra' 1 se l'id del volo e' stato inserito correttamente,0 altrimenti.
	int flag2=0;													///Variabile che conterra' 1 se i posti sono stati inseriti correttamente,0 altrimenti.
	int flag3=0;													///Variabile che conterra' 1 se il giorno di volo e' stato inserito correttamente,0 altrimenti.
	int flag4=0;													///Variabile che conterra' 1 se il mese e' stato inserito correttamente,0 altrimenti.
	int flag5=0;													///Variabile che conterra' 1 se l'anno e' stato inserito correttamente,0 altrimenti.
	int flag6=0;													///Variabile che conterra' 1 se la data inserita e' reale,0 altrimenti.
	int flag7=0;													///Variabile che conterra' 1 se la data inserita e' corretta, cioe' e' successiva alla data del sistema,0 altrimenti.
	int flag8=0;													///Variabile che conterra' 1 se l'ora di partenza e' stata inserita correttamente,0 altrimenti.
	int flag9=0;													///Variabile che conterra' 1 se i minuti di partenza sono stati inseriti correttamente,0 altrimenti.
	int flag10=0;													///Variabile che conterra' 1 se l'ora di partenza(ora e minuti) inseriti sono reali,0 altrimenti.
	int flag11=0;													///Variabile che conterra' 1 se l'ora di arrivo e' stata inserita correttamente,0 altrimenti.
	int flag12=0;													///Variabile che conterra' 1 se i minuti di arrivo sono stati inseriti correttamente,0 altrimenti.
	int flag13=0;													///Variabile che conterra' 1 se l'ora di arrivo(ora e minuti) inseriti sono reali(cioe' sono successivi all'ora di arrivo),0 altrimenti.
	int stringa1=0;													///Variabile che conterra' 1 se il nome della compagnia e' stata inserita correttamente,0 altrimenti.
	int stringa2=0;													///Variabile che conterra' 1 se la destinazione e' stata inserita correttamente,0 altrimenti.
	int stringa3=0;													///Variabile che conterra' 1 se la tipologia di volo e' stata inserito correttamente,0 altrimenti.
	int giorno_corrente=0;											///Variabile che conterra' il giorno del sistema
	int mese_corrente=0;											///Variabile che conterra' il mese del sistema.
	int anno_corrente=0;											///Variabile che conterra' l'anno del sistema.
	int k= numero_di_voli;

	while((flag1==0)||(flag0==0))									///Ciclo che permette all'utente di inserire un nuovo id_volo finche' non inserisce un id_volo valido.
	{
		flag0=0;
		flag1=0;

		printf("Inserisci codice volo\n");
		scanf("%s",ultimo.id_volo);
		flag1=controllo_id_volo(ultimo.id_volo);
		flag0=id_volo_inserito(ultimo.id_volo,numero_di_voli,voli);
	}
	svuota_buffer();

	while(stringa1==0)											///Ciclo che permette all'utente di inserire un nome di compagnia finche' non inserisce un nome valido.
	{
		printf("Inserisci nome compagnia (max 29 caratteri) \n");
		fgets(ultimo.nome_compagnia,LUNGHEZZA_COMPAGNIA,stdin);
		fflush(stdin);
		stringa1=controllo_Stringa2_volo(ultimo.nome_compagnia);
	}

	while(stringa2==0)  										///Ciclo che permette all'utente di inserire una destinazione finche' non inserisce una destinazione valida.
	{
		printf("Inserisci una destinazione (max 29 caratteri) \n");
		fgets(ultimo.destinazione,LUNGHEZZA_DESTINAZIONE,stdin);
		fflush(stdin);
		stringa2=controllo_Stringa2_volo(ultimo.destinazione);
	}


	while(stringa3==0)										///Ciclo che permette all'utente di inserire una tipologia di aereo finche' non inserisce una tipologia valida.
	{
		printf("Inserisci una tipologia di aereo (max 19 caratteri)\n");
		fgets(ultimo.tipologia_di_aereo,LUNGHEZZA_TIPO,stdin);
		fflush(stdin);
		stringa3=controllo_Stringa_volo(ultimo.tipologia_di_aereo);
	}


	while(flag2==0)										///Ciclo che permette all'utente di inserire dei posti finche' non inserisce posti validi.
	{
		printf("Inserisci i posti dell'aereo \n");
		scanf("%s",posti);
		flag2=controllo_posti(posti,&ultimo.posti);
	}
	svuota_buffer();


	acquisisci_data(&persona.data_di_iscrizione);
	giorno_corrente=persona.data_di_iscrizione.giorno;
	mese_corrente=persona.data_di_iscrizione.mese;
	anno_corrente=persona.data_di_iscrizione.anno;

	while( (flag7==0) || (flag6==0) )										///Ciclo che permette all'utente di inserire una data finche' non inserisce una data reale e corretta.
	{
		printf("Inserisci un nuovo giorno di volo\n");
		flag3=0;
		flag4=0;
		flag5=0;
		flag6=0;
		flag7=0;

		while(flag3==0)													///Ciclo che permette all'utente di inserire un giorno di volo finche' non inserisce un giorno valido.
		{
			printf("Inserisci giorno di volo: ");
			scanf("%s",giorno);
			flag3=controllo_giorno_di_volo(giorno,&ultimo.giorno_di_volo.giorno);
		}

		while(flag4==0)													///Ciclo che permette all'utente di inserire un mese di volo finche' non inserisce un mese valido.
		{
			printf("Inserisci mese: ");
			scanf("%s",mese);
			flag4=controllo_mese_di_volo(mese,&ultimo.giorno_di_volo.mese);
		}

		while(flag5==0)													///Ciclo che permette all'utente di inserire un anno di volo finche' non inserisce un anno valido.
		{
			printf("Inserisci anno: ");
			scanf("%s",anno);
			flag5=controllo_anno_di_volo(anno,&ultimo.giorno_di_volo.anno);
		}
		flag6=data_volo_corretta_1(ultimo.giorno_di_volo);

		flag7=data_volo_corretta_2(ultimo.giorno_di_volo,giorno_corrente,mese_corrente,anno_corrente);
	}

	svuota_buffer();

	while (flag10==0)											///Ciclo che permette all'utente di inserire un'ora di partenza(ora e minuti) di volo finche' non ne inserisce una reale.
	{
		printf("Inserisci l'ora di partenza del volo da Bari\n");
		flag8=0;
		flag9=0;

		while (flag8==0)										///Ciclo che permette all'utente di inserire un'ora di partenza di volo finche' non inserisce un'ora valida.
		{
			printf("Inserisci ora di partenza del volo: ");
			scanf("%s",ora);
			flag8=controllo_ora_e_minuti(ora,&ultimo.ora_di_partenza.ora);
		}

		while (flag9==0)										///Ciclo che permette all'utente di inserire dei minuti di partenza di volo finche' non inserisce minuti validi.
		{
			printf("Inserisci minuti di partenza del volo: ");
			scanf("%s",minuti);
			flag9=controllo_ora_e_minuti(minuti,&ultimo.ora_di_partenza.minuti);
		}

		flag10=ora_di_partenza_corretta(ultimo.ora_di_partenza);
	}

	while (flag13==0)											///Ciclo che permette all'utente di inserire un'ora di arrivo(ora e minuti) di volo finche' non ne inserisce una reale.
	{
		printf("Inserisci l'ora di arrivo del volo a Bari\n");
		flag12=0;
		flag11=0;

		while (flag11==0)										///Ciclo che permette all'utente di inserire un'ora di arrivo di volo finche' non inserisce un'ora valida.
		{
			printf("Inserisci ora di arrivo del volo ");
			scanf("%s",ora);
			flag11=controllo_ora_e_minuti(ora,&ultimo.ora_di_arrivo.ora);
		}

		while (flag12==0)										///Ciclo che permette all'utente di inserire dei minuti di arrivo di volo finche' non inserisce minuti validi.
		{
			printf("Inserisci minuti di arrivo del volo ");
			scanf("%s",minuti);
			flag12=controllo_ora_e_minuti(minuti,&ultimo.ora_di_arrivo.minuti);
		}

		flag13=ora_di_arrivo_corretta(ultimo.ora_di_partenza,ultimo.ora_di_arrivo);
	}

	ultimo.durata=calcola_durata(ultimo.ora_di_partenza,ultimo.ora_di_arrivo);
	printf("Durata in minuti\n%d\n",ultimo.durata);
	svuota_buffer();


	strcpy(voli[k].id_volo,ultimo.id_volo);
	strcpy(voli[k].nome_compagnia,ultimo.nome_compagnia);
	strcpy(voli[k].destinazione,ultimo.destinazione);
	strcpy(voli[k].tipologia_di_aereo,ultimo.tipologia_di_aereo);
	voli[k].posti=ultimo.posti;
	voli[k].giorno_di_volo.giorno=ultimo.giorno_di_volo.giorno;
	voli[k].giorno_di_volo.mese=ultimo.giorno_di_volo.mese;
	voli[k].giorno_di_volo.anno=ultimo.giorno_di_volo.anno;
	voli[k].ora_di_partenza.ora=ultimo.ora_di_partenza.ora;
	voli[k].ora_di_partenza.minuti=ultimo.ora_di_partenza.minuti;
	voli[k].ora_di_arrivo.ora=ultimo.ora_di_arrivo.ora;
	voli[k].ora_di_arrivo.minuti=ultimo.ora_di_arrivo.minuti;
	voli[k].durata=ultimo.durata;

	printf("Volo inserito correttamente\n");
	visualizza_un_volo(voli,numero_di_voli,k);

	return 1;
}

/**
 * Questa funzione permette di modificare i dati di un volo esistente.
 * Inizialmente viene chiesto all'utente di scegliere uno tra i voli presenti da modificare.
 * Successivamente gli viene mostrato un secondo menu' dove vengono indicati i vari campi di quel volo da modificare.
 * Una volta modificato uno tra quei campi, il volo scelto dall'utente verra' modificato.
 * @pre voli deve contenere tutti i dati dei voli
 * @pre numero_di_voli deve contenere il numero effettivo dei voli
 * @post I dati di un determinato volo verranno modificati.
 */
int modifica_volo(volo voli[],int numero_di_voli)     //Codice modifica_volo:C15
{
	setbuf(stdout,NULL);
	volo volo_modificato;											/// Variabile di tipo volo utilizzata per contenere uno dei campi modificati inseriti dall'utente.
	passeggero persona;												///Variabile di tipo passeggero utilizzata per prendere successivamente la data del sistema.
	char posti[MAX_POSTI];											///Vettore "posti" che contiene i posti del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sui posti inserito.
	char giorno[MAX_LUNGHEZZA_GIORNO];								///Vettore "giorno" che contiene il giorno di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sul giorno di volo inserito.
	char mese[MAX_LUNGHEZZA_MESE];									///Vettore "mese" che contiene il mese di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sul mese di volo inserito.
	char anno[LUNGHEZZA_ANNO];										///Vettore "anno" che contiene l'anno di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sull'anno di volo inserito
	char ora[MAX_LUNGHEZZA_ORA_E_MINUTI];							///Vettore "ora" che contiene il l'ora di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sull'ora di volo inserito
	char minuti[MAX_LUNGHEZZA_ORA_E_MINUTI];						///Vettore "minuti" che contiene i minuti di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sui minuti di volo inserito
	int scelta=0;													///Variabile che conterra' 1 se l'id del volo e' stato inserito correttamente,0 altrimenti.
	int scelta2=0;													///Variabile che conterra' 1 se l'id del volo sara' diverso dagli altri,0 altrimenti.
	int flag0=0;													///Variabile che conterra' 1 se l'id del volo esiste (e' presente nel file) ,0 altrimenti.
	int flag1=0;													///Variabile che conterra' 1 se l'id del volo e' stato inserito correttamente,0 altrimenti.
	int flag2=0;													///Variabile che conterra' 1 se i posti sono stati inseriti correttamente,0 altrimenti.
	int flag3=0;													///Variabile che conterra' 1 se il giorno di volo e' stato inserito correttamente,0 altrimenti.
	int flag4=0;													///Variabile che conterra' 1 se il mese e' stato inserito correttamente,0 altrimenti.
	int flag5=0;													///Variabile che conterra' 1 se l'anno e' stato inserito correttamente,0 altrimenti.
	int flag6=0;													///Variabile che conterra' 1 se la data inserita e' reale,0 altrimenti.
	int flag7=0;													///Variabile che conterra' 1 se la data inserita e' corretta, cioe' e' successiva alla data del sistema,0 altrimenti.
	int flag8=0;													///Variabile che conterra' 1 se l'ora di partenza e' stata inserita correttamente,0 altrimenti.
	int flag9=0;													///Variabile che conterra' 1 se i minuti di partenza sono stati inseriti correttamente,0 altrimenti.
	int flag10=0;													///Variabile che conterra' 1 se l'ora di partenza(ora e minuti) inseriti sono reali,0 altrimenti.
	int flag11=0;													///Variabile che conterra' 1 se l'ora di arrivo e' stata inserita correttamente,0 altrimenti.
	int flag12=0;													///Variabile che conterra' 1 se i minuti di arrivo sono stati inseriti correttamente,0 altrimenti.
	int flag13=0;													///Variabile che conterra' 1 se l'ora di arrivo(ora e minuti) inseriti sono reali(cioe' sono successivi all'ora di arrivo),0 altrimenti.
	int stringa1=0;													///Variabile che conterra' 1 se il nome della compagnia e' stata inserita correttamente,0 altrimenti.
	int stringa2=0;													///Variabile che conterra' 1 se la destinazione e' stata inserita correttamente,0 altrimenti.
	int stringa3=0;													///Variabile che conterra' 1 se la tipologia di volo e' stata inserito correttamente,0 altrimenti.
	int giorno_corrente=0;											///Variabile che conterra' il giorno del sistema
	int mese_corrente=0;											///Variabile che conterra' il mese del sistema.
	int anno_corrente=0;											///Variabile che conterra' l'anno del sistema.
	int r=numero_di_voli;
	int indice_volo=0;												/// Variabile che conterra' l'indice del volo da modificare
	int i=0;														/// Variabile utilizzata per uscire dal ciclo.
	int p=0;														/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int s=0;														/// Variabile che conterra' la scelta inserita, relativa a quale campo si vuole modificare.
	int j;															///Variabile che conterra' l'indice di ogni volo

	printf("Di quale volo vuoi modificare le informazioni?\n");

	do
	{
		scelta=0;
		flag0=0;
		scanf("%s",volo_modificato.id_volo);
		scelta=controllo_id_volo(volo_modificato.id_volo);
		for(j=0;j<r;j++)
		{
			if( (strcmp(volo_modificato.id_volo,voli[j].id_volo)==0) )  /// Scorrendo tutti i voli, se il volo inserito dall'utente e' presente nel file voli, mi salvo l'indice di quel volo, in modo da modificarlo
			{
				flag0=1;
				indice_volo=j;
			}
		}
		if (flag0==0)
		{
			printf("Codice inserito non esistente\n");
			printf("Inserire un codice valido\n");
		}

	}while( (scelta==0) || (flag0==0) );								///Ciclo che permette all'utente di inserire un id_volo finche' non inserisce un id_volo valido ed esistente.

	svuota_buffer();

	visualizza_un_volo(voli,numero_di_voli,indice_volo);


	do
	{
		printf ("\n Quale informazione vuoi modificare?\n");
		printf ("\n 1.CODICE VOLO");
		printf ("\n 2.NOME COMPAGNIA");
		printf ("\n 3.DESTINAZIONE");
		printf ("\n 4.TIPOLOGIA DI AEREO");
		printf ("\n 5.POSTI");
		printf ("\n 6.GIORNO DI VOLO");
		printf ("\n 7.ORA DI ARRIVO E PARTENZA");
		printf ("\n 8.TORNA AL MENU' INIZIALE");
		printf("\n Scelta: ");

		do
		{
			s=acquisisci_scelta(&p);
		}while(p==0);


		switch(s)
		{
		case 1:
			while((flag1==0)||(scelta2==0))									///Ciclo che permette all'utente di inserire un  id_volo finche' non inserisce un id_volo valido.
			{
				scelta2=0;
				flag1=0;

				printf("Inserisci codice volo\n");
				scanf("%s",volo_modificato.id_volo);
				flag1=controllo_id_volo(volo_modificato.id_volo);
				scelta2=id_volo_inserito(volo_modificato.id_volo,numero_di_voli,voli);
			}

			strcpy(voli[indice_volo].id_volo,volo_modificato.id_volo);		///Il campo modificato dall'utente viene salvato in quella posizione dell'array di struct dei voli.
			svuota_buffer();
			i++;
			break;


		case 2:

			while(stringa1==0)											///Ciclo che permette all'utente di inserire un nome di compagnia finche' non inserisce un nome valido.
			{
				printf("Inserisci nome compagnia (max 29 caratteri) \n");
				fgets(volo_modificato.nome_compagnia,LUNGHEZZA_COMPAGNIA,stdin);
				fflush(stdin);
				stringa1=controllo_Stringa2_volo(volo_modificato.nome_compagnia);
			}
			strcpy(voli[indice_volo].nome_compagnia,volo_modificato.nome_compagnia);	///Il campo modificato dall'utente viene salvato in quella posizione dell'array di struct dei voli.
			i++;
			break;


		case 3:

			while(stringa2==0)										///Ciclo che permette all'utente di inserire una destinazione finche' non inserisce una destinazione valido.
			{
				printf("Inserisci una destinazione (max 29 caratteri) \n");
				fgets(volo_modificato.destinazione,LUNGHEZZA_DESTINAZIONE,stdin);
				fflush(stdin);
				stringa2=controllo_Stringa2_volo(volo_modificato.destinazione);
			}
			strcpy(voli[indice_volo].destinazione,volo_modificato.destinazione);	///Il campo modificato dall'utente viene salvato in quella posizione dell'array di struct dei voli.
			i++;
			break;


		case 4:

			while(stringa3==0)									///Ciclo che permette all'utente di inserire una tipologia di aereo finche' non inserisce una tipologia valido.
			{
				printf("Inserisci una tipologia di aereo (max 19 caratteri)\n");
				fgets(volo_modificato.tipologia_di_aereo,LUNGHEZZA_TIPO,stdin);
				fflush(stdin);
				stringa3=controllo_Stringa_volo(volo_modificato.tipologia_di_aereo);
			}
			i++;
			break;


		case 5:

			while(flag2==0)									///Ciclo che permette all'utente di inserire dei posti finche' non inserisce posti validi
			{
				printf("Inserisci i posti dell'aereo \n");
				scanf("%s",posti);
				flag2=controllo_posti(posti,&volo_modificato.posti);
			}
			voli[indice_volo].posti=volo_modificato.posti;
			svuota_buffer();
			i++;
			break;


		case 6:

			acquisisci_data(&persona.data_di_iscrizione);
			giorno_corrente=persona.data_di_iscrizione.giorno;
			mese_corrente=persona.data_di_iscrizione.mese;
			anno_corrente=persona.data_di_iscrizione.anno;

			while( (flag7==0) || (flag6==0) )			///Ciclo che permette all'utente di inserire una data finche' non inserisce una data reale e corretta.
			{
				printf("Inserisci un nuovo giorno di volo\n");
				flag3=0;
				flag4=0;
				flag5=0;
				flag6=0;
				flag7=0;

				while(flag3==0)							///Ciclo che permette all'utente di inserire un giorno di volo finche' non inserisce un giorno valido.
				{
					printf("Inserisci giorno di volo: ");
					scanf("%s",giorno);
					flag3=controllo_giorno_di_volo(giorno,&volo_modificato.giorno_di_volo.giorno);
				}

				while(flag4==0)						///Ciclo che permette all'utente di inserire un mese di volo finche' non inserisce un mese valido.
				{
					printf("Inserisci mese: ");
					scanf("%s",mese);
					flag4=controllo_mese_di_volo(mese,&volo_modificato.giorno_di_volo.mese);
				}

				while(flag5==0)						///Ciclo che permette all'utente di inserire un anno di volo finche' non inserisce un anno valido.
				{
					printf("Inserisci anno: ");
					scanf("%s",anno);
					flag5=controllo_anno_di_volo(anno,&volo_modificato.giorno_di_volo.anno);
				}
				flag6=data_volo_corretta_1(volo_modificato.giorno_di_volo);

				flag7=data_volo_corretta_2(volo_modificato.giorno_di_volo,giorno_corrente,mese_corrente,anno_corrente);
			}

			voli[indice_volo].giorno_di_volo.giorno=volo_modificato.giorno_di_volo.giorno;	///Il campo modificato dall'utente viene salvato in quella posizione dell'array di struct dei voli.
			voli[indice_volo].giorno_di_volo.mese=volo_modificato.giorno_di_volo.mese;
			voli[indice_volo].giorno_di_volo.anno=volo_modificato.giorno_di_volo.anno;
			svuota_buffer();
			i++;
			break;


		case 7:

			while (flag10==0)										///Ciclo che permette all'utente di inserire un'ora di partenza(ora e minuti) di volo finche' non ne inserisce una reale.
			{
				printf("Inserisci l'ora di partenza del volo da Bari\n");
				flag8=0;
				flag9=0;

				while (flag8==0)									///Ciclo che permette all'utente di inserire un'ora di partenza di volo finche' non inserisce un'ora valida.
				{
					printf("Inserisci ora di partenza del volo: ");
					scanf("%s",ora);
					flag8=controllo_ora_e_minuti(ora,&volo_modificato.ora_di_partenza.ora);
				}

				while (flag9==0)								///Ciclo che permette all'utente di inserire dei minuti di partenza di volo finche' non inserisce minuti valida.
				{
					printf("Inserisci minuti di partenza del volo: ");
					scanf("%s",minuti);
					flag9=controllo_ora_e_minuti(minuti,&volo_modificato.ora_di_partenza.minuti);
				}

				flag10=ora_di_partenza_corretta(volo_modificato.ora_di_partenza);
			}

			while (flag13==0)									///Ciclo che permette all'utente di inserire un'ora di arrivo(ora e minuti) di volo finche' non ne inserisce una reale.
			{
				printf("Inserisci l'ora di arrivo del volo a Bari\n");
				flag12=0;
				flag11=0;

				while (flag11==0)								///Ciclo che permette all'utente di inserire un'ora di arrivo di volo finche' non inserisce un'ora valida.
				{
					printf("Inserisci ora di arrivo del volo: ");
					scanf("%s",ora);
					flag11=controllo_ora_e_minuti(ora,&volo_modificato.ora_di_arrivo.ora);
				}

				while (flag12==0)								///Ciclo che permette all'utente di inserire dei minuti di partenza di volo finche' non inserisce minuti valida.
				{
					printf("Inserisci minuti di arrivo del volo: ");
					scanf("%s",minuti);
					flag12=controllo_ora_e_minuti(minuti,&volo_modificato.ora_di_arrivo.minuti);
				}

				flag13=ora_di_arrivo_corretta(volo_modificato.ora_di_partenza,volo_modificato.ora_di_arrivo);
			}
			volo_modificato.durata=calcola_durata(volo_modificato.ora_di_partenza,volo_modificato.ora_di_arrivo);  ///Il campo modificato dall'utente viene salvato in quella posizione dell'array di struct dei voli.
			voli[indice_volo].ora_di_partenza.ora=volo_modificato.ora_di_partenza.ora;
			voli[indice_volo].ora_di_partenza.minuti=volo_modificato.ora_di_partenza.minuti;
			voli[indice_volo].ora_di_arrivo.ora=volo_modificato.ora_di_arrivo.ora;
			voli[indice_volo].ora_di_arrivo.minuti=volo_modificato.ora_di_arrivo.minuti;
			voli[indice_volo].durata=volo_modificato.durata;
			svuota_buffer();
			i++;
			break;


		case 8:
			menu();
			i++;
			break;

		default:

			printf("\n Valore inserito non corretto \n");
			printf("Inserire un nuovo valore");
		}
	}while(i==0); /// Se l'utente non inserisce una tra le scelte presenti nel menu', dovra' inserire una nuova scelta

	printf("Il volo %s è stato modificato correttamente\n",voli[indice_volo].id_volo);
	visualizza_un_volo(voli,numero_di_voli,indice_volo);

	return 1;


}

/**
 * Questa funzione permette di eliminare un volo.
 * Inizialmente viene controllato che l'id del volo da eliminare e' stato inserito corretamente.
 *  Infine vengono eliminati i dati del volo.
 * @pre voli deve contenere tutti i dati dei voli
 * @pre numero_di_voli deve contenere il numero effettivo dei voli
 * @post Il volo selezionato dall'utente verra' eliminato e i suoi dati non verranno visualizzati nell'array di struct.
 */
int elimina_volo(volo voli[],int numero_di_voli)   //Codice funzione elimina_volo:C16
{
	setbuf (stdout,NULL);
	int indice_volo=0;						///Variabile che conterra' l'indice del volo da eliminare.
	int flag0=0;							///Variabile che conterra' 1 se l'id del volo esiste (e' presente nel file) ,0 altrimenti.
	int scelta=0;							///Variabile che conterra' 1 se l'id del volo e' stato inserito correttamente,0 altrimenti.
	int i=0;								///Variabile che conterra' l'indice di ogni volo
	int k=numero_di_voli;
	volo volo_eliminato;					/// Variabile di tipo volo utilizzata per contenere l'id del volo che l'utente vuole eliminare.

	printf("Quale volo vorresti eliminare?\n");
	do
	{
		scelta=0;
		flag0=0;
		scanf("%s",volo_eliminato.id_volo);
		scelta=controllo_id_volo(volo_eliminato.id_volo);
		for(i=0;i<k;i++)
		{
			if( (strcmp(volo_eliminato.id_volo,voli[i].id_volo)  == 0) )  /// Scorrendo tutti i voli, se il volo inserito dall'utente e' presente nel file voli, mi salvo l'indice di quel volo, in modo da eliminarlo
			{
				flag0=1;
				indice_volo=i;
			}
		}
		if(flag0==0)
		{
			printf("Codice inserito non esistente\n");
			printf("Inserire un codice valido\n");
		}
	}while( (flag0==0) || (scelta==0) ) ;								///Ciclo che permette all'utente di inserire un id_volo finche' non inserisce un id_volo valido ed esistente.

	svuota_buffer();

	visualizza_un_volo(voli,numero_di_voli,indice_volo);


	strcpy(voli[indice_volo].id_volo,"");
	strcpy(voli[indice_volo].nome_compagnia,"");
	strcpy(voli[indice_volo].destinazione,"");
	strcpy(voli[indice_volo].tipologia_di_aereo,"");
	voli[indice_volo].posti=0;
	voli[indice_volo].giorno_di_volo.giorno=0;
	voli[indice_volo].giorno_di_volo.mese=0;
	voli[indice_volo].giorno_di_volo.anno=0;
	voli[indice_volo].ora_di_partenza.ora=0;
	voli[indice_volo].ora_di_partenza.minuti=0;
	voli[indice_volo].ora_di_arrivo.ora=0;
	voli[indice_volo].ora_di_arrivo.minuti=0;
	voli[indice_volo].durata=0;

	printf("Il volo %s è stato eliminato correttamente\n",voli[indice_volo].id_volo);

	return 1;

}


/**
 * Questa funzione permette di cercare il nome della compagnia inserita in precedenza dall'utente, controllando che sia presente tra quelli inseriti nel file.
 * Inoltre una volta trovato quel nome, verranno visualizzati i dati di quel volo, o eventualmente dei voli che hanno quel nome.
 * @pre voli deve contenere tutti i dati dei voli
 * @pre stringa deve contenere la compagnia inserita dall'utente per cui si  vuole effettuare una ricerca
 * @pre numero_di_voli deve contenere il numero effettivo dei voli
 * @post I dati di quel o di quei voli cercati, che saranno attraverso una funzione visualizzati all'utente.
 */
int ricerca_per_compagnia(volo voli[],char stringa[],int numero_di_voli)
{
	int i=0;
	int flag=0;

	for(i=0;i<numero_di_voli;i++)
	{
		if( (strcmp(stringa,voli[i].nome_compagnia) ) ==0)
		{
			visualizza_un_volo(voli,numero_di_voli,i);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Nome compagnia non esistente\n");
	}
	return flag;
}

/**
 * Questa funzione permette di cercare la destinazione inserita in precedenza dall'utente, controllando che sia presente tra quelle inseriti nel file.
 * Inoltre una volta trovato quella destinazione, verranno visualizzati i dati di quel volo, o eventualmente dei voli che hanno quella destinazione.
 * @pre voli deve contenere tutti i dati dei voli
 * @pre stringa deve contenere la destinazione inserita dall'utente per cui si  vuole effettuare una ricerca
 * @pre numero_di_voli deve contenere il numero effettivo dei voli
 * @post I dati di quel o di quei voli cercati, che saranno attraverso una funzione visualizzati all'utente.
 */
int ricerca_per_destinazione(volo voli[],char stringa[],int numero_di_voli)
{
	int i=0;
	int flag=0;

	for(i=0;i<numero_di_voli;i++)
	{
		if( (strcmp(stringa,voli[i].destinazione) ) ==0)
		{
			visualizza_un_volo(voli,numero_di_voli,i);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Destinazione non esistente\n");
	}
	return flag;
}

/**
* Questa funzione permette di cercare il giorno di volo inserito in precedenza dall'utente, controllando che sia presente tra quelli inseriti nel file.
 * Inoltre una volta trovato quel giorno di volo, verranno visualizzati i dati di quel volo, o eventualmente dei voli che partono quel giorno.
 * @pre voli deve contenere tutti i dati dei voli
 * @pre data_ricercata deve contenere il giorno di volo inserito dall'utente per cui si vuole effettuare una ricerca
 * @pre numero_di_voli deve contenere il numero effettivo dei voli
 * @post I dati di quel o di quei voli cercati, che saranno attraverso una funzione visualizzati all'utente.
 */
int ricerca_per_giorno_volo(volo voli[],data data_ricercata,int numero_di_voli)
{
	int i=0;
	int flag=0;
	for(i=0;i<numero_di_voli;i++)
	{
		if( (data_ricercata.giorno == voli[i].giorno_di_volo.giorno) && (data_ricercata.mese == voli[i].giorno_di_volo.mese) && (data_ricercata.anno == voli[i].giorno_di_volo.anno) )
		{
			visualizza_un_volo(voli,numero_di_voli,i);
			flag=1;
		}
	}
	if (flag==0)
	{
		printf("Giorno di volo non esistente\n");
	}
	return flag;
}

/**
 * Questa funzione permette di ricercare dei voli secondo un determinato criterio.
 * Inizialmente  viene mostrato all'utente un menu' dove vengono indicati i vari campi per i quali ricercare un volo.
 * Una volta selezionato uno tra i criteri da ricercare,verranno chiamate altre funzioni.
 * @pre voli deve contenere tutti i dati dei voli
 * @pre numero_di_voli deve contenere il numero effettivo dei passeggeri
 * @post Attraverso altre funzioni presenti in questa funzione, verranno ricercati e successivamente visualizzati i voli, secondo un  criterio inserito dall'utente.
 */
int ricerca_voli(volo voli[],int numero_di_voli)				//Codice funzione ricerca_voli:C22
{
	setbuf(stdout,NULL);
	volo volo_ricercato;											///Variabile di tipo volo utilizzata per contenere uno dei campi del passeggero ricercato
	passeggero persona;												///Variabile di tipo passeggero utilizzata per prendere successivamente la data del sistema.
	char giorno[MAX_LUNGHEZZA_GIORNO];								///Vettore "giorno" che contiene il giorno di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sul giorno di volo inserito.
	char mese[MAX_LUNGHEZZA_MESE];									///Vettore "mese" che contiene il mese di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sul mese di volo inserito.
	char anno[LUNGHEZZA_ANNO];										///Vettore "anno" che contiene l'anno di volo del nuovo volo.
																	///Lo dichiaro char in modo tale da effettuare vari controlli sull'anno di volo inserito
	int flag3=0;													///Variabile che conterra' 1 se il giorno di volo e' stato inserito correttamente,0 altrimenti.
	int flag4=0;													///Variabile che conterra' 1 se il mese e' stato inserito correttamente,0 altrimenti.
	int flag5=0;													///Variabile che conterra' 1 se l'anno e' stato inserito correttamente,0 altrimenti.
	int flag6=0;													///Variabile che conterra' 1 se la data inserita e' reale,0 altrimenti.
	int flag7=0;													///Variabile che conterra' 1 se la data inserita e' corretta, cioe' e' successiva alla data del sistema,0 altrimenti.
	int stringa1=0;													///Variabile che conterra' 1 se il nome della compagnia e' stata inserita correttamente,0 altrimenti.
	int stringa2=0;													///Variabile che conterra' 1 se la destinazione e' stata inserita correttamente,0 altrimenti.
	int giorno_corrente=0;											///Variabile che conterra' il giorno del sistema
	int mese_corrente=0;											///Variabile che conterra' il mese del sistema.
	int anno_corrente=0;											///Variabile che conterra' l'anno del sistema.
	int ricerca_compagnia=0;										///Variabile che conterra' 1 se il nome della compagnia inserito e' presente tra i voli esistenti
	int ricerca_destinazione=0;										///Variabile che conterra' 1 se la destinazione inserita e' presente tra i voli esistenti
	int ricerca_giorno_volo=0;										///Variabile che conterra' 1 se il giorno di volo inserito e' presente tra i voli esistenti
	int i=0;														/// Variabile utilizzata per uscire dal ciclo.
	int p=0;														/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int s=0;														/// Variabile che conterra' la scelta inserita, relativa a quale campo si vuole modificare.


	do
	{
		printf ("\n Ricerca i voli in base al:\n");
		printf ("\n 1.NOME COMPAGNIA");
		printf ("\n 2.DESTINAZIONE");
		printf ("\n 3.GIORNO DI VOLO");
		printf ("\n 4.TORNA AL MENU' INIZIALE");
		printf("\n Scelta: ");

		do
		{
			s=acquisisci_scelta(&p);
		}while(p==0);


		switch(s)
		{

		case 1:
			while( (stringa1==0) || (ricerca_compagnia==0) )			///Ciclo che permette all'utente di inserire un nome di una compagnia finche' non inserisce un nome valido di un volo esistente.
			{
				stringa1=0;
				ricerca_compagnia=0;

				printf("Inserisci nome compagnia da ricercare (max 29 caratteri) \n");
				fgets(volo_ricercato.nome_compagnia,LUNGHEZZA_COMPAGNIA,stdin);
				fflush(stdin);
				stringa1=controllo_Stringa2_volo(volo_ricercato.nome_compagnia);
				ricerca_compagnia=ricerca_per_compagnia(voli,volo_ricercato.nome_compagnia,numero_di_voli);
			}
			i++;
			break;

		case 2:
			while( (stringa2==0) || (ricerca_destinazione==0) )      ///Ciclo che permette all'utente di inserire una destinazione finche' non inserisce una destinazione valida di un volo esistente.
			{
				stringa2=0;
				ricerca_destinazione=0;

				printf("Inserisci una destinazione da ricercare (max 29 caratteri) \n");
				fgets(volo_ricercato.destinazione,LUNGHEZZA_DESTINAZIONE,stdin);
				fflush(stdin);
				stringa2=controllo_Stringa2_volo(volo_ricercato.destinazione);
				ricerca_destinazione=ricerca_per_destinazione(voli,volo_ricercato.destinazione,numero_di_voli);

			}
			i++;
			break;

		case 3:
			acquisisci_data(&persona.data_di_iscrizione);
			giorno_corrente=persona.data_di_iscrizione.giorno;
			mese_corrente=persona.data_di_iscrizione.mese;
			anno_corrente=persona.data_di_iscrizione.anno;

			while( (flag7==0) || (flag6==0)  || (ricerca_giorno_volo==0))	///Ciclo che permette all'utente di inserire un giorno finche' non inserisce un giorno reale e presente tra i voli.
			{
				printf("Inserisci un nuovo giorno di volo da ricercare\n");
				flag3=0;
				flag4=0;
				flag5=0;
				flag6=0;
				flag7=0;
				ricerca_giorno_volo=0;

				while(flag3==0)											 ///Ciclo che permette all'utente di inserire un giorno finche' non inserisce un giorno valido.
				{
					printf("Inserisci giorno di volo da ricercare: ");
					scanf("%s",giorno);
					flag3=controllo_giorno_di_volo(giorno,&volo_ricercato.giorno_di_volo.giorno);
				}

				while(flag4==0)											 ///Ciclo che permette all'utente di inserire un mese finche' non inserisce un giorno valido.
				{
					printf("Inserisci mese da ricercare: ");
					scanf("%s",mese);
					flag4=controllo_mese_di_volo(mese,&volo_ricercato.giorno_di_volo.mese);
				}

				while(flag5==0)											 ///Ciclo che permette all'utente di inserire un anno finche' non inserisce un giorno valido.
				{
					printf("Inserisci anno da ricercare: ");
					scanf("%s",anno);
					flag5=controllo_anno_di_volo(anno,&volo_ricercato.giorno_di_volo.anno);
				}
				flag6=data_volo_corretta_1(volo_ricercato.giorno_di_volo);
				flag7=data_volo_corretta_2(volo_ricercato.giorno_di_volo,giorno_corrente,mese_corrente,anno_corrente);
				ricerca_giorno_volo=ricerca_per_giorno_volo(voli,volo_ricercato.giorno_di_volo,numero_di_voli);
			}

			svuota_buffer();
			i++;
			break;

		case 4:
			menu();
			i++;
			break;

		default:

			printf("\n Valore inserito non corretto \n");
			printf("Inserire un nuovo valore");
		}
	}while(i==0);							/// Se l'utente non inserisce una tra le scelte presenti nel menu', dovra' inserire una nuova scelta

	return 1;

}











