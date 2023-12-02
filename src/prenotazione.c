/**
* @file prenotazione.c
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "controlli_passeggeri.h"
#include "controlli_voli.h"
#include "passeggero.h"
#include "volo.h"
#include "prenotazione.h"
#include "costanti.h"
#include "menu.h"
#include "data.h"
#include "data_di_iscrizione.h"
#include "svuota_buffer.h"



/**
 * Questa funzione permette di calcolare il numero delle prenotazioni aprendo il file e contando tutte le prenotazioni
 * Viene chiamata ad ogni operazione fatta perchè se viene aggiunta una prenotazione, il numero delle prenotazioni deve essere aggiornato.
 * @post il numero delle prenotazioni presenti nel file prenotazioni.
 */
int numero_delle_prenotazioni()
{
	FILE* file_prenotazioni;
	prenotazione prenotazione_persona;
	int i=0;
	if(	(file_prenotazioni = fopen("prenotazioni.dat","rb")) == NULL)
	{
		printf("Errore nell'apertura\n");
	}
	else
	{
		while(!feof(file_prenotazioni))
		{
			int read=fread(&prenotazione_persona,sizeof(prenotazione),1,file_prenotazioni);  /// Leggo tutti i dati delle prenotazioni e ogni volta incremento la i
			if(read>0)
			{
				i++;
			}
		}
		fclose(file_prenotazioni);
	}
	return i;
}

/**
 * Questa funzione carica i dati dal file passeggeri all'array di struct prenotazione_persona per permettere di lavorare su quei dati.
 * @pre numero_prenotazioni deve contenere il numero effettivo delle prenotazioni
 * @post L'array di struct prenotazione_persona conterra' tutti  i dati delle prenotazioni.
 */
int caricamento_prenotazioni(prenotazione prenotazione_persona[],int numero_prenotazioni)  //Codice caricamento_prenotazioni: C04
{
	FILE* file_prenotazioni;

	if(	(file_prenotazioni = fopen("prenotazioni.dat","rb")) == NULL)
	{

		return ERRORE;
	}
	else
	{
		for(int i=0;i<numero_prenotazioni;i++)
		{
			fread(&prenotazione_persona[i],sizeof(prenotazione),1,file_prenotazioni);		/// Leggo tutti i dati delle prenotazioni dal file e li salvo sull array di struct
		}
		fclose(file_prenotazioni);
	}

	return CORRETTO;
}

/**
 * Questa funzione salva i dati dall'array di struct prenotazione_persona al file delle prenotazioni.
 * Viene chiamata ogni volta che viene effettuata un'operazione, in modo da aggiornare costantemente il file delle prenotazioni e quindi i dati.
 * @pre numero_prenotazioni deve contenere il numero effettivo delle prenotazioni
 * @pre prenotazione_persona deve contenere tutti i dati delle prenotazioni
 * @post I dati delle prenotazioni verranno salvati sul file.
 */
int salvataggio_su_file_prenotazioni(prenotazione prenotazione_persona[],int numero_prenotazioni)  //Codice salvataggio_su_file_prenotazioni: C07
{
	FILE* file_prenotazioni;

	if(	(file_prenotazioni = fopen("prenotazioni.dat","wb+")) == NULL)
	{

		return ERRORE;
	}
	else
	{
		for(int i=0;i<=numero_prenotazioni;i++)
		{
			fwrite(&prenotazione_persona[i],sizeof(prenotazione),1,file_prenotazioni);		/// Scrivo tutti i dati presenti nell array di struct nel file, salvando quindi i dati.
		}
		fclose(file_prenotazioni);
	}

	return CORRETTO;
}

/**
 * Questa funzione permette di visualizzare tutte le prenotazioni presenti nel progetto.
 * Vengono visualizzati tutte le prenotazioni,tranne quelle che sono state elimininate.
 * @pre prenotazione_persona deve contenere tutti i dati delle prenotazioni
 * @pre numero_prenotazioni deve contenere il numero effettivo delle prenotazioni
 * @post I dati di ciascuna prenotazione vengono visualizzati nel terminale.
 */
int visualizza_prenotazioni(prenotazione prenotazione_persona[],int numero_prenotazioni) //Codice visualizza_prenotazioni: C10
{
	int k=0;
	for(k=0;k<numero_prenotazioni;k++)
	{
		if (strcmp(prenotazione_persona[k].id_volo,"")!=0)			///Vizualizzo tutte le prenotazioni, eccetto chi ha l'id del volo  vuoto, cioe' e' stato eliminato.
		{
			printf("\nPrenotazione: %d\n Passeggero: %d\n Volo: %s\n",
					prenotazione_persona[k].id_prenotazione,prenotazione_persona[k].id_passeggero,
					prenotazione_persona[k].id_volo);
		}
		if(prenotazione_persona[k].check_in==0)					///Inoltre dato che imposto che il check in potra' avere essenzialmente valori uguali a 0 o 1, in base al valore stampo determinati messaggi.
		{
			printf(" Check-in non effettuato\n");
		}
		else
		{
			if(prenotazione_persona[k].check_in==1)
			{
			printf(" Check-in effettuato\n");
			}
		}
	}
	return 1;
}

/**
 * Questa funzione permette di visualizzare una determinata prenotazione.
 * Viene chiamata ogni volta che nel programma c'e' bisogno di visualizzare una prenotazione, ad esempio quando si modifica o si elimina una prenotazione.
* @pre prenotazione_persona deve contenere tutti i dati delle prenotazioni
 * @pre numero_prenotazioni deve contenere il numero effettivo delle prenotazioni
 * @pre indice_prenotazione deve contenere l'indice della prenotazione che si vuole visualizzare.
 * @post I dati di un determinata prenotazione vengono visualizzati sul terminale.
 */
int visualizza_una_prenotazione(prenotazione prenotazione_persona[],int numero_prenotazioni, int indice_prenotazione)
{
	if (strcmp(prenotazione_persona[indice_prenotazione].id_volo,"")!=0)			///Vizualizzo una determinata prenotazione, ma se ha l'id del volo vuoto(cioe' e' stata eliminata) non la visualizzo
	{
		printf("\nPrenotazione: %d\n Passeggero: %d\n Volo: %s\n",
				prenotazione_persona[indice_prenotazione].id_prenotazione,prenotazione_persona[indice_prenotazione].id_passeggero,
				prenotazione_persona[indice_prenotazione].id_volo);
	}
	if(prenotazione_persona[indice_prenotazione].check_in==0)				///Inoltre dato che imposto che il check in potra' avere essenzialmente valori uguali a 0 o 1, in base al valore stampo determinati messaggi
	{
		printf(" Check-in non effettuato\n");
	}
	else
	{
		if(prenotazione_persona[indice_prenotazione].check_in==1)
		{
			printf(" Check-in effettuato\n");
		}
	}
	return 1;
}

/**
 * Questa funzione controlla se la prenotazione inserita dall'utente per un determinato passeggero, e' stata gia' effettuata.
 * Inizialmente scorro tutte le prenotazioni presenti, una volta trovato il passeggero inserito dall'utente, controllo se la prenotazione di quell'utente per quel volo e' stata gia' effettuata
 * @pre prenotazione_persona array di struct deve contenere tutti i dati delle prenotazioni
 * @pre numero_prenotazioni deve contenere il numero delle  prenotazioni
 * @pre persona deve contenere l'indice del passeggero di cui si vogliono controllare le prenotazioni
 * @pre indice_utente deve contenere l'indice del passeggero per cui si vogliono controllare le prenotazioni
 * @pre volo_inserito deve contenere il volo per cui si vuole effettuare una prenotazione
 * @post Prenotazione selezionata dall'utente per quel passeggero, in qualunque caso.
 */
int controllo_prenotazione(prenotazione prenotazione_persona[],int numero_prenotazioni,
							passeggero persona[], int indice_utente, volo volo_inserito)
{
	int flag1=0;
	int i=0;

		 for(i=0;i<numero_prenotazioni;i++)
				{
					if(prenotazione_persona[i].id_passeggero==persona[indice_utente].id_passeggero)
					{
						if(strcmp(prenotazione_persona[i].id_volo,volo_inserito.id_volo)==0)
								{
									flag1=0;
									printf("Prenotazione già effettuata\n");
									return flag1;
								}
					}
				}
		 flag1=1;
		 return flag1;
}

/**
 *Questa funzione permette di inserire una nuova prenotazione. Inizialmente viene chiesto all'utente di inserire uno dei passeggeri presenti nel progetto.
 *Successivamente viene chiesto all'utente l'id del volo a cui vuole prenotarsi,tra quelli disponibili.
 *Infine vengono memorizzati i dati della nuova nell'ultima posizione dell'array di struct.
 * @pre prenotazione_persona array di struct deve contenere tutti i dati delle prenotazioni
 * @pre numero_prenotazioni deve contenere il numero delle  prenotazioni
 * @pre persona array di struct deve contenere tutti i dati dei passeggeri
 * @pre numero_passeggeri deve contenere il numero dei passeggeri
 * @pre voli array di struct deve contenere tutti i dati dei voli
 * @pre numero_di_voli  deve contenere il numero dei voli
 * @post  I dati della nuova prenotazione verranno salvati nell'ultima posizione dell'array di struct prenotazione_persona.
*/

int inserisci_nuova_prenotazione(prenotazione prenotazione_persona[],int numero_prenotazioni,  //Codice inserisci_nuova_prenotazione: C17
		passeggero persona[],int numero_passeggeri,
		volo voli[], int numero_di_voli)
{
	setbuf(stdout,NULL);
	volo volo_inserito;										///Variabile che conterra' il volo per cui si vuole effettuare una prenotazione
	int flag0=0;											///Variabile che conterra' 1 se l'id del volo inserito esiste,0 altrimenti
	int flag1=0;											///Variabile che conterra' 1 se la prenotazione non e' stata inserita in precedenza,0 altrimenti
	int indice_utente=0;									///Variabile che conterra' l'indice delle'utente per cui si vuole effettuare una prenotazione
	int k=numero_prenotazioni;
	int r=numero_di_voli;
	int t=0;												/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int t2=0;												/// Variabile che conterra' 1 se la scelta inserita sara' tra i passeggeri esistenti, 0 altrimenti.
	int j;													///Variabile che conterra' l'indice di ogni volo
	int scelta=0;											///Variabile che conterra' 1 se l'id del volo e' stato inserito correttamente,0 altrimenti

	do
	{

	printf("Inserisci il passeggero che vuole prenotarsi ad un volo\n");

	do
	{
		t=0;
		t2=0;
		indice_utente=acquisisci_scelta(&t)-1;				/// Decremento di 1 la scelta inserita dall'utente per risalire all'indice di quel passeggero.
		if((indice_utente>(numero_passeggeri-1))||(indice_utente<0)|| (strcmp(persona[indice_utente].nome,"")==0) )     /// Oltre al controllo del range dei passeggeri esistenti, controllo anche se un passeggero e' stato eliminato
		{
			printf("Utente inserito non esistente\n");
			printf("Inserire un nuovo utente\n");
		}
		else
		{
			t2=1;
		}
	}while( (t==0) ||(t2==0) );


	printf("Inserisci un volo a cui prenotarsi\n");

	do
	{
		scelta=0;
		flag0=0;
		scanf("%s",volo_inserito.id_volo);
		scelta=controllo_id_volo(volo_inserito.id_volo);
		for(j=0;j<r;j++)
		{
			if( (strcmp(volo_inserito.id_volo,voli[j].id_volo)==0) && (strcmp(voli[j].nome_compagnia,"")!=0) )  /// Scorrendo tutti i voli, se il volo inserito dall'utente e' presente nel file voli, vuol dire che esiste, quindi incremento il flag
			{
				flag0=1;
			}
		}
		if (flag0==0)
		{
			printf("Codice inserito non esistente\n");
			printf("Inserire un codice valido\n");
		}

	}while( (scelta==0) || (flag0==0) );						///Ciclo che permette all'utente di inserire un id_volo finche' non inserisce un id_volo valido ed esistente.

	flag1=controllo_prenotazione(prenotazione_persona,numero_prenotazioni,persona,indice_utente,volo_inserito);

	svuota_buffer();

	}while( flag1==0);


	prenotazione_persona[k].id_prenotazione=k+1;
	prenotazione_persona[k].id_passeggero=persona[indice_utente].id_passeggero;
	strcpy(prenotazione_persona[k].id_volo,volo_inserito.id_volo);
	prenotazione_persona[k].check_in=0;

	printf("Prenotazione effettuata con successo\n");
	visualizza_una_prenotazione(prenotazione_persona,numero_prenotazioni,k);

	return 1;

}

/**
 *Questa funzione permette di modificare i dati di una prenotazione esistente.
  Inizialmente viene chiesto all'utente di inserire una delle prenotazioni presenti da modificare.
 * Successivamente gli viene mostrato un secondo menu' dove vengono indicati i vari campi di quella prenotazione da modificare.
 * Una volta modificato uno tra quei campi, la prenotazione scelta dall'utente verra' modificata.
 * @pre prenotazione_persona array di struct deve contenere tutti i dati delle prenotazioni
 * @pre numero_prenotazioni deve contenere il numero delle  prenotazioni
 * @pre persona array di struct deve contenere tutti i dati dei passeggeri
 * @pre numero_passeggeri deve contenere il numero dei passeggeri
 * @pre voli array di struct deve contenere tutti i dati dei voli
 * @pre numero_di_voli  deve contenere il numero dei voli
 * @post  I dati di una determinata prenotazione verranno modificati.
*/
int modifica_prenotazione(prenotazione prenotazione_persona[],int numero_prenotazioni,passeggero persona[],  //Codice funzione modifica_prenpotazione:C18
		int numero_passeggeri,volo voli[], int numero_di_voli)
{
	setbuf(stdout,NULL);
	volo volo_inserito;											///Variabile che conterra' il volo per cui si vuole modificare una prenotazione
	int flag0=0;												///Variabile che conterra' 1 se l'id del volo inserito esiste,0 altrimenti
	int indice_utente=0;										///Variabile che conterra' il nuovo indice dell'utente che avra' effettuato quella prenotazione.
	int indice_prenotazione=0;									///Variabile che conterra' l'indice della prenotazione da modificare
	int r=numero_di_voli;
	int t=0;													/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int t2=0;													/// Variabile che conterra' 1 se la scelta inserita sara' tra le prenotazioni esistenti, 0 altrimenti.
	int t3=0;													/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int t4=0;													/// Variabile che conterra' 1 se la scelta inserita sara' tra i passeggeri esistenti, 0 altrimenti.
	int j;														///Variabile che conterra' l'indice di ogni volo
	int p=0;													/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int s=0;													/// Variabile che conterra' la scelta inserita, relativa a quale campo si vuole modificare.
	int i=0;													///Variabile usata per uscire dal ciclo
	int scelta=0;												///Variabile che conterra' 1 se l'id del volo e' stato inserito correttamente,0 altrimenti

	printf("Quale prenotazione vuoi modificare?\n");

	do
	{
		t=0;
		t2=0;

		indice_prenotazione=acquisisci_scelta(&t)-1;   /// Decremento di 1 la scelta inserita dall'utente per risalire all'indice di quella prenotazione
		if((indice_prenotazione>(numero_prenotazioni-1))||(indice_prenotazione<0)|| (strcmp(prenotazione_persona[indice_prenotazione].id_volo,"")==0) )  /// Oltre al controllo del range delle prenotazioni esistenti, controllo anche se una prenotazione e' stata eliminata
		{
			printf("Prenotazione inserita non esistente\n");
			printf("Inserire un nuova prenotazione\n");
		}
		else
		{
			t2=1;
		}
	}while( (t==0) ||(t2==0) );

	visualizza_una_prenotazione(prenotazione_persona,numero_prenotazioni,indice_prenotazione);

	do
	{
		printf ("\n Quale informazione vuoi modificare?\n");
		printf ("\n 1.UTENTE");
		printf ("\n 2.VOLO");
		printf("\n 3.TORNA AL MENU INIZIALE");
		printf("\n Scelta: ");

		do
		{
			s=acquisisci_scelta(&p);
		}while(p==0);


		switch(s)
		{
		case 1:
			printf("Inserire un passeggero valido\n");
			do
			{
				t3=0;
				t4=0;
				indice_utente=acquisisci_scelta(&t4)-1;     /// Decremento di 1 la scelta inserita dall'utente per risalire all'indice di quel passeggero
				if((indice_utente>(numero_passeggeri-1))||(indice_utente<0)|| (strcmp(persona[indice_utente].nome,"")==0) ) /// Oltre al controllo del range dei passeggeri esistenti, controllo anche se un passeggero e' stato eliminato
				{
					printf("Passeggero inserito non esistente\n");
					printf("Inserire un nuovo passeggero\n");
				}
				else
				{
					t3=1;
				}
			}while( (t4==0) ||(t3==0) );
			prenotazione_persona[indice_prenotazione].id_passeggero=persona[indice_utente].id_passeggero;   ///Il campo modificato dall'utente viene salvato in quella posizione dell'array di struct delle prenotazioni

			i++;
			break;

		case 2:
			printf("Inserire un volo valido\n");
			do
			{
				scelta=0;
				flag0=0;
				scanf("%s",volo_inserito.id_volo);
				scelta=controllo_id_volo(volo_inserito.id_volo);
				for(j=0;j<r;j++)
				{
					if( (strcmp(volo_inserito.id_volo,voli[j].id_volo)==0) && (strcmp(voli[j].nome_compagnia,"")!=0) )  /// Scorrendo tutti i voli, se il volo inserito dall'utente e' presente nel file voli, vuol dire che esiste, quindi incremento il flag
					{
						flag0=1;
					}
				}
				if (flag0==0)
				{
					printf("Codice inserito non esistente\n");
					printf("Inserire un codice valido\n");
				}

			}while( (scelta==0) || (flag0==0) );                                                 ///Ciclo che permette all'utente di inserire un id_volo finche' non inserisce un id_volo valido ed esistente.
			strcpy(prenotazione_persona[indice_prenotazione].id_volo,volo_inserito.id_volo);     ///Il campo modificato dall'utente viene salvato in quella posizione dell'array di struct delle prenotazioni
			svuota_buffer();
			i++;
			break;

		case 3:
			menu();
			i++;
			break;

		default:
			printf("\n Valore inserito non corretto \n");
			printf("Inserire un nuovo valore ");
		}
	}while(i==0);											/// Se l'utente non inserisce una tra le scelte presenti nel menu', dovra' inserire una nuova scelta

	printf("Prenotazione %d è stata modificata correttamente\n",prenotazione_persona[indice_prenotazione].id_prenotazione);
	visualizza_una_prenotazione(prenotazione_persona,numero_prenotazioni,indice_prenotazione);

	return 1;

}

/**
 * Questa funzione permette di eliminare una prenotazione.
 * Inizialmente viene controllato che l'id della prenotazione da eliminare e' stato inserito corretamente.
 *  Infine vengono eliminati i dati della prenotazione.
 * @pre prenotazione_persona array di struct deve contenere tutti i dati delle prenotazioni
 * @pre numero_prenotazioni deve contenere il numero delle  prenotazioni
* @post La prenotazione selezionata dall'utente verra' eliminata e i suoi dati non verranno visualizzati nell'array di struct.
 */
int elimina_prenotazione(prenotazione prenotazione_persona[],int numero_prenotazioni) //Codice funzione elimina_prenotazione C19
{
	setbuf (stdout,NULL);
	int t=0;													/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int t2=0;													/// Variabile che conterra' 1 se la scelta inserita sara' tra le prenotazioni esistenti, 0 altrimenti.
	int k=0;													///Variabile che conterra' l'indice della prenotazione da eliminare


	printf("Quale prenotazione vorresti eliminare?\n");
	do
	{
		t=0;
		t2=0;

		k=acquisisci_scelta(&t)-1;								/// Decremento di 1 la scelta inserita dall'utente per risalire all'indice di quella prenotazione
		if( (k> (numero_prenotazioni-1) ) || (k<0) || (strcmp(prenotazione_persona[k].id_volo,"")==0) )    /// Oltre al controllo del range delle prenotazioni esistenti, controllo anche se una prenotazione e' stata eliminata
		{
			printf("Valore inserito non corretto\n");
			printf("Inserisci un nuovo valore\n");
		}
		else
		{
			t2=1;
		}
	}while( (t==0) || (t2==0) );

	visualizza_una_prenotazione(prenotazione_persona,numero_prenotazioni,k);


	prenotazione_persona[k].id_passeggero=0;
	strcpy(prenotazione_persona[k].id_volo,"");
	prenotazione_persona[k].check_in=2;											///Imposto il valore del check-in della prenotazione da eliminare a 2, in modo da non farlo visualizzare
	printf("La prenotazione %d è stata eliminata correttamente\n",prenotazione_persona[k].id_prenotazione);

	return 1;
}

/**
 * Questa funzione permette di controllore se l'imbarco per un determinato volo e' concluso.
 *  Attraverso l'indice della prenotazione di cui si e' effettuato il check-in, si scorrono i voli finche' non si trova quel determinato volo.
 *  Una volta trovato il volo, si scorrono tutte le prenotazioni e ogni volta che si trova quel volo nelle prenotazioni, si incrementa un contatore di tutte le prenotazioni di quel volo di cui e' stato effettuato il check-in
 *  Una volta contati tutti i check-in effettuati per quel volo, si confronta questo numero con il numero dei posti di quel volo, e se sono uguali viene stampato il messaggio di imbarco completato
 * @pre prenotazione_persona array di struct deve contenere  tutti i dati delle prenotazioni
 * @pre numero_prenotazioni deve contenere il  numero effettivo delle  prenotazioni
 * @pre voli array di struct deve contenere tutti i dati dei voli
 * @pre numero_di_voli  deve contenere il numero effettivo dei voli
 * @pre n deve contenere l'indice della prenotazione di cui si vuole effettuare il check-in
 * @post Il messaggio che l'imbarco e' stato completato, altrimenti niente il contrario
 */
int imbarco(prenotazione prenotazione_persona[],int numero_prenotazioni,volo voli[],int numero_di_voli,int n)
{
	int i=0;
	int j=0;
	int indice_volo=0;
	int c=0;
	for(i=0;i<numero_di_voli;i++)
	{
		if( (strcmp(prenotazione_persona[n].id_volo,voli[i].id_volo)) == 0)
		{
			indice_volo=i;
		}
	}
	for(j=0;j<numero_prenotazioni;j++)
	{
		if( (strcmp(voli[indice_volo].id_volo,prenotazione_persona[j].id_volo)))
		{
			if(prenotazione_persona[j].check_in==1)
			{
				c++;
			}
		}
	}
	if(c==voli[indice_volo].posti)
	{
		printf("Imbarco completato\n");
	}

	return 1;
}


/**
 *Questa funzione permette di effettuare il check-in di una prenotazione esistente.
  Inizialmente viene chiesto all'utente di inserire il numero del passaporto di un passeggero.
 * Successivamente viene mostrato all'utente tutte le prenotazioni del passeggero scelto, cosi da sceglierne una di cui effettuare il check-in.
* Infine l'utente inserira' la prenotazione di quel passeggero tra le presenti, e il check-in sara' completato
 * @pre prenotazione_persona array di struct deve contenere tutti i dati delle prenotazioni
 * @pre numero_di_prenotazioni deve contenere il numero delle  prenotazioni
 * @pre persona array di struct deve contenere tutti i dati dei passeggeri
 * @pre numero_di_passeggeri deve contenere il numero dei passeggeri
 * @pre voli array di struct deve contenere tutti i dati dei voli
 * @pre numero_di_voli  deve contenere il numero dei voli
 * @post Il check-in della prenotazione scelta verra' effettuato
*/
int check_in(prenotazione prenotazione_persona[],int numero_di_prenotazioni,passeggero persona[], //Codice funzione check-in:C20
		int numero_di_passeggeri,volo voli[],int numero_di_voli)
{

	int passaporto=0;							///Variabile che conterra' 1 se il passaporto inserito e' corretto,0 altrimenti.
	int prenotazioni[NUMERO_PRENOTAZIONI];		///Vettore utilizzato per contenere le prenotazioni di un determinato passeggero
	int i=0;									///Variabile che conterra' l'indice di ogni passeggero
	int l=0;									///Variabile che conterra' l'indice di ogni prenotazione
	int j=0;									///Variabile che conterra' tutte le prenotazioni di un determinato passeggero
	int y=0;									///Variabile che conterra' l'indice di ogni prenotazione effettuata da un determinato passeggero
	int t=0;									/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int t2=0;									/// Variabile che conterra' 1 se la scelta inserita sara' tra le prenotazioni esistenti e non e' stato gia' effettuato il check-in, 0 altrimenti.
	int k=0;									///Variabile che conterra' l'indice della prenotazione di cui effettuare il check-in
	int flag0=0;								/// Variabile che conterra' 1 se il passaporto inserito esiste, 0 altrimenti.
	int flag2=0;								/// Variabile che conterra' 1 se un determinato passeggero ha effettuato delle prenotazioni, 0 altrimenti.
	int indice_utente;							/// Variabile che conterra' l'indice del passeggero di cui si vogliono visualizzare le prenotazioni
	passeggero persona1;						///Variabile di tipo passeggero che conterra' il passaporto di un passeggero
	int posto;									/// Variabile  che conterra' un posto assegnato su un volo, una volta effettuato il check-in
	int seed=time(NULL);
	srand(seed);

	while( (passaporto==0) || flag0==0){						///Ciclo che permette all'utente di inserire un passaporto finche' non inserisce un passaporto valido ed esistente
		printf("Inserisci passaporto\n");
		scanf("%s",persona1.passaporto);
		passaporto=controllo_Passaporto(persona1.passaporto);
		svuota_buffer();
		for(i=0;(i<numero_di_passeggeri)&&(flag0==0);i++)
		{
			if( (strcmp(persona1.passaporto,persona[i].passaporto)) == 0)
			{
				indice_utente=i;
				flag0=1;
			}
		}
		if(flag0==0)
		{
			printf("Passaporto inserito non esistente\n");
		}
	}


	for(l=0;l<numero_di_prenotazioni;l++)							///Controllo se ci sono prenotazioni per quel passeggero selezionato, e le visualizzo
	{
		if( persona[indice_utente].id_passeggero==prenotazione_persona[l].id_passeggero)
		{
			;
			printf("\nPasseggero: %d\n Prenotazione: %d\n Volo: %s\n",
					prenotazione_persona[l].id_passeggero,prenotazione_persona[l].id_prenotazione,
					prenotazione_persona[l].id_volo);
			prenotazioni[j]=prenotazione_persona[l].id_prenotazione;
			j++;												///Ogni volta che trovo una prenotazione, incremento un contatore che mi servira' in seguito
			flag2=1;
		}
	}

	if(flag2==0)
	{
		printf("Prenotazione non effettuata\n");
		menu();
	}


	do
	{
		t=0;
		t2=0;
		printf("Inserisci la prenotazione della quale vuoi effettuare il check_in\n");
		k=acquisisci_scelta(&t)-1;																		/// Decremento di 1 la scelta inserita dall'utente per risalire all'indice di quella prenotazione
		if( (k> (numero_di_prenotazioni-1) ) || (k<0) || (strcmp(prenotazione_persona[k].id_volo,"")==0) )  /// Oltre al controllo del range delle prenotazioni esistenti, controllo anche se una prenotazione e' stata eliminata
		{
			printf("Valore inserito non corretto\n");
			printf("Inserisci un nuovo valore\n");
		}
		else
		{
			for( y=0;y<j;y++)
			{
				if(k+1==prenotazioni[y])      ///Incremento k di 1 per risalire alla prenotazione inserita precedentemente, dato che prima l'avevo decrementata per risalire all'indice
				{
					if(prenotazione_persona[k].check_in==1)         ///Inoltre controllo se l'utente inserisce una prenotazione valida per quel passeggero e se e' stato gia' effettuato il check- in della prenotazione scelta
					{
						t2=0;
					}
					else
					{
						t2=1;

					}
				}
			}
			if(t2==0)
			{
				printf("Questo passeggero non ha effettuato questa prenotazione o il check-in è stato già effettuato\n");
			}
		}
	}while( (t==0) || (t2==0) );

	prenotazione_persona[k].check_in=1;        ///Una volta che tutti i dati sono corretti, imposto il valore del check-in a 1
	printf("Check-in effettuato  correttamente\n");
	posto=rand() % 100+1;
	printf("Il posto dell'utente %s %s per il volo %s è %d\n",persona[indice_utente].nome,persona[indice_utente].cognome,prenotazione_persona[k].id_volo,posto);
	imbarco( prenotazione_persona, numero_di_prenotazioni,voli,numero_di_voli,k);

	return 1;
}

/**
 * Questa funzione permette di cercare il passeggero inserito in precedenza dall'utente, controllando che abbia effettuato almeno una prenotazione tra quella inserite nel file.
 * Inoltre una volta trovato quel passeggero tra le prenotazioni, verranno visualizzati i dati della sua prenotazione, o eventualmente delle prenotazioni che  ha effettuato.
 * @pre prenotazione_persona array di struct deve contenere tutti i dati delle prenotazioni
 * @pre numero_di_prenotazioni deve contenere il numero delle  prenotazioni
 * @pre persona array di struct deve contenere tutti i dati dei passeggeri
 * @pre indice_utente deve contenere l'indice del passeggero inserito dall'utente per cui si vuole effettuare una ricerca sulle sue prenotazioni
 * @post I dati di quella o quelle prenotazioni(di quel passeggero) cercate, che saranno attraverso una funzione visualizzati all'utente.
 */
int ricerca_per_utente(prenotazione prenotazione_persona[],int numero_di_prenotazioni,passeggero persona[],int indice_utente)
{
	int i=0;
	int flag=0;
	for(i=0;i<numero_di_prenotazioni;i++)
	{
		if(prenotazione_persona[i].id_passeggero==persona[indice_utente].id_passeggero)
		{
			visualizza_una_prenotazione(prenotazione_persona,numero_di_prenotazioni,i);
					flag=1;
		}
	}
	if(flag==0)
	{
		printf("Nessuna prenotazione effettuata per questo passeggero\n");
	}
	return flag;
}

/**
 * Questa funzione permette di cercare il volo inserito in precedenza dall'utente, controllando che si sia effettuata almeno una prenotazione tra quella inserite nel file.
 * Inoltre una volta trovato quel volo tra le prenotazioni, verranno visualizzati i dati della  prenotazione su quel volo, o eventualmente delle prenotazioni che si sono effettuate su di esso.
 * @pre prenotazione_persona array di struct deve contenere tutti i dati delle prenotazioni
 * @pre id_volo deve contenere il volo inserito dall'utente per cui si vuole effettuare una ricerca sulle sue prenotazioni
 * @pre numero_di_prenotazioni deve contenere il numero delle  prenotazioni
 * @post I dati di quella o quelle prenotazioni(su quel volo) cercate, che saranno attraverso una funzione visualizzati all'utente.
 */
int ricerca_per_volo(prenotazione prenotazione_persona[],char id_volo[],int numero_di_prenotazioni)
{
	int i=0;
	int flag=0;
	for(i=0;i<numero_di_prenotazioni;i++)
	{
		if(strcmp(prenotazione_persona[i].id_volo,id_volo)==0)
		{
			visualizza_una_prenotazione(prenotazione_persona,numero_di_prenotazioni,i);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Nessuna prenotazione effettuata per questo volo\n");
	}
	return flag;
}

/**
 * Questa funzione permette di ricercare delle prenotazioni secondo un determinato criterio.
 * Inizialmente  viene mostrato all'utente un menu' dove vengono indicati i vari campi per i quali ricercare una prenotazione.
 * Una volta selezionato uno tra i criteri da ricercare,verranno chiamate altre funzioni.
 * @pre prenotazione_persona array di struct deve contenere tutti i dati delle prenotazioni
 * @pre numero_di_prenotazioni deve contenere il numero delle  prenotazioni
 * @pre persona array di struct deve contenere tutti i dati dei passeggeri
 * @pre numero_passeggeri deve contenere il numero dei passeggeri
 * @pre voli array di struct deve contenere tutti i dati dei voli
 * @pre numero_di_voli  deve contenere il numero dei voli
 * @post Attraverso altre funzioni presenti in questa funzione, verranno ricercate e successivamente visualizzate le prenotazioni, secondo un  criterio inserito dall'utente.
*/
int ricerca_prenotazioni(prenotazione prenotazione_persona[],int numero_di_prenotazioni,passeggero persona[],    //Codice funzione ricerca_prenotazioni:C23
		int numero_passeggeri,volo voli[],int numero_di_voli)
{
	setbuf(stdout,NULL);
	volo volo_inserito;									///Variabile che conterra' il volo per cui si vuole ricercare una prenotazione
	int flag0=0;										///Variabile che conterra' 1 se il volo inserito e' esistente, 0 altrimenti
	int indice_utente=0;								/// Variabile che conterra' l'indice del passeggero di cui si vogliono visualizzare le prenotazioni
	int r=numero_di_voli;
	int t3=0;											/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int t4=0;											/// Variabile che conterra' 1 se la scelta inserita sara' tra i passeggeri esistenti, 0 altrimenti.
	int j;												///Variabile che conterra' l'indice di ogni volo
	int p=0;											/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int s=0;											/// Variabile che conterra' la scelta inserita, relativa a quale campo si vuole modificare.
	int i=0;											///Variabile usata per uscire dal ciclo
	int scelta=0;										///Variabile che conterra' 1 se l'id del volo e' stato inserito correttamente,0 altrimenti
	int ricerca_utente=0;								///Variabile che conterra' 1 se il passeggero inserito ha effettuato almeno una prenotazione
	int ricerca_volo=0;									///Variabile che conterra' 1 se sul volo inserito si e' effettuata almeno una prenotazione

	do
	{
		printf ("\n Ricerca della prenotazione in base al: \n");
		printf ("\n 1.UTENTE");
		printf ("\n 2.VOLO");
		printf("\n 3.TORNA AL MENU INIZIALE");
		printf("\n Scelta: ");

		do
		{
			s=acquisisci_scelta(&p);
		}while(p==0);


		switch(s)
		{
		case 1:
			printf("Inserire un passeggero da ricercare\n");
			do
			{
				t3=0;
				t4=0;
				ricerca_utente=0;

				indice_utente=acquisisci_scelta(&t4)-1;
				if((indice_utente>(numero_passeggeri-1))||(indice_utente<0)|| (strcmp(persona[indice_utente].nome,"")==0) )
				{
					printf("Passeggero inserito non esistente\n");
					printf("Inserire un nuovo passeggero\n");
				}
				else
				{
					t3=1;
				}
				ricerca_utente=ricerca_per_utente(prenotazione_persona,numero_di_prenotazioni,persona,indice_utente);
			}while( (t4==0) ||(t3==0) || (ricerca_utente==0) );					///Ciclo che permette all'utente di inserire un passeggero finche' non inserisce un passeggero valido, esistente e ha effettuato almeno una prenotazione.

			i++;
			break;

		case 2:
			printf("Inserire un volo valido\n");
			do
			{
				scelta=0;
				flag0=0;
				ricerca_volo=0;

				scanf("%s",volo_inserito.id_volo);
				scelta=controllo_id_volo(volo_inserito.id_volo);
				for(j=0;j<r;j++)
				{
					if( (strcmp(volo_inserito.id_volo,voli[j].id_volo)==0) && (strcmp(voli[j].nome_compagnia,"")!=0) )
					{
						flag0=1;
					}
				}
				if (flag0==0)
				{
					printf("Codice inserito non esistente\n");
					printf("Inserire un codice valido\n");
				}
				ricerca_volo=ricerca_per_volo(prenotazione_persona,volo_inserito.id_volo,numero_di_prenotazioni);

			}while( (scelta==0) || (flag0==0) || (ricerca_volo==0) );				///Ciclo che permette all'utente di inserire un volo finche' non inserisce un volo valido, esistente e sul quale si e' effettuata almeno una prenotazione.
			svuota_buffer();
			i++;
			break;

		case 3:
			menu();
			i++;
			break;

		default:
			printf("\n Valore inserito non corretto \n");
			printf("Inserire un nuovo valore ");
		}
	}while(i==0);					/// Se l'utente non inserisce una tra le scelte presenti nel menu', dovra' inserire una nuova scelta

	return 1;
}



















