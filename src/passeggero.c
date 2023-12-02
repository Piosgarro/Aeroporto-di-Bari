/**
* @file passeggero.c
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "controlli_passeggeri.h"
#include "passeggero.h"
#include "costanti.h"
#include "menu.h"
#include "data.h"
#include "data_di_iscrizione.h"
#include "svuota_buffer.h"


/**
 * Questa funzione permette di calcolare il numero dei passeggeri aprendo il file e contando tutti i passeggeri
 * Viene chiamata ad ogni operazione fatta perchè se viene aggiunto un passeggero, il numero dei passeggeri deve essere aggiornato.
 * @post il numero dei passeggeri presenti nel file passeggeri.
 */
int numero_di_passeggeri()
{
	FILE* file_passeggeri;
	passeggero persona;
	int i=0;
	if(	(file_passeggeri = fopen("passeggeri.dat","rb")) == NULL)
	{
		printf("Errore nell'apertura\n");
	}
	else
	{
		while(!feof(file_passeggeri))
		{
			int read=fread(&persona,sizeof(passeggero),1,file_passeggeri); /// Leggo tutti i dati dei passeggeri e ogni volta incremento la i
			if(read>0)
			{
				i++;
			}
		}
		fclose(file_passeggeri);
	}
	return i;
}

/**
 * Questa funzione carica i dati dal file passeggeri all'array di struct persona per permettere di lavorare su quei dati.
 * @pre numero_passeggeri deve contenere il numero effettivo dei passeggeri
 * @post L'array di struct persona conterra' tutti  i dati dei passeggeri.
 */
int caricamento_persone(passeggero persona[],int numero_passeggeri)    //Codice funzione caricamento_persone: C02
{
	FILE* file_passeggeri;

	if(	(file_passeggeri = fopen("passeggeri.dat","rb")) == NULL)
	{

		return ERRORE;
	}
	else
	{
		for(int i=0;i<numero_passeggeri;i++)
		{
			fread(&persona[i],sizeof(passeggero),1,file_passeggeri); /// Leggo tutti i dati dei passeggeri dal file e li salvo sull array di struct
		}
		fclose(file_passeggeri);
	}

	return CORRETTO;
}

/**
 * Questa funzione salva i dati dall'array di struct persona al file dei passeggeri.
 * Viene chiamata ogni volta che viene effettuata un'operazione, in modo da aggiornare costantemente il file passeggeri e quindi i dati.
 * @pre numero_passeggeri deve contenere il numero effettivo dei passeggeri
 * @pre persona deve contenere tutti i dati dei passeggeri
 * @post I dati dei passeggeri verranno salvati sul file.
 */
int salvataggio_su_file_passeggeri(passeggero persona[],int numero_passeggeri)  //Codice funzione salvataggio_su_file_prenotazioni: C05
{
	FILE* file_passeggeri;

	if(	(file_passeggeri = fopen("passeggeri.dat","wb+")) == NULL)
	{

		return ERRORE;
	}
	else
	{
		for(int i=0;i<=numero_passeggeri;i++)
		{
			fwrite(&persona[i],sizeof(passeggero),1,file_passeggeri); /// Scrivo tutti i dati presenti nell array di struct nel file, salvando quindi i dati.
		}
		fclose(file_passeggeri);
	}

	return CORRETTO;
}

/**
 * Questa funzione permette di visualizzare tutti i passeggeri presenti nel progetto.
 * Vengono visualizzati tutti i passeggeri,tranne quelli che sono stati elimininati.
 * @pre persona deve contenere tutti i dati dei passeggeri
 * @pre numero_passeggeri deve contenere il numero effettivo dei passeggeri
 * @post I dati di ciascun passeggero vengono visualizzati nel terminale.
 */
int visualizza_passeggeri(passeggero persona[],int numero_passeggeri)   //Codice funzione visualizza_passeggeri: C08
{
	int k=0;
	for(k=0;k<numero_passeggeri;k++)
	{
		if (strcmp(persona[k].nome,"")!=0) ///Vizualizzo tutti i passeggeri, eccetto chi ha il nome vuoto, cioe' e' stato eliminato.
		{
			printf("\nPasseggero: %d\n Nome: %s\n Cognome: %s\n Data di nascita: %d.%d.%d\n Data di iscrizione: %d.%d.%d\n Passaporto: %s\n ",persona[k].id_passeggero,persona[k].nome,
					persona[k].cognome,persona[k].data_di_nascita.giorno,persona[k].data_di_nascita.mese,persona[k].data_di_nascita.anno,
					persona[k].data_di_iscrizione.giorno,persona[k].data_di_iscrizione.mese,persona[k].data_di_iscrizione.anno,persona[k].passaporto);
		}
	}
	return 1;
}

/**
 * Questa funzione permette di visualizzare un determinato passeggero.
 * Viene chiamata ogni volta che nel programma c'e' bisogno di visualizzare un passeggero, ad esempio quando si modifica o si elimina un passeggero.
 * @pre persona deve contenere tutti i dati dei passeggeri
 * @pre numero_passeggeri deve contenere il numero effettivo dei passeggeri
 * @pre indice_passeggero deve contenere l'indice del passeggero che si vuole visualizzare.
 * @post I dati di un determinato passeggero vengono visualizzati sul terminale.
 */
int visualizza_un_passeggero(passeggero persona[],int numero_passeggeri, int indice_passeggero)
{
		if (strcmp(persona[indice_passeggero].nome,"")!=0) ///Vizualizzo un determinato passeggero, ma se ha il nome vuoto(cioe' e' stato eliminato) non lo visualizzo.
		{
			printf("Passeggero: %d\n Nome: %s\n Cognome: %s\n Data di nascita: %d.%d.%d\n Data di iscrizione: %d.%d.%d\n Passaporto: %s\n ",persona[indice_passeggero].id_passeggero,persona[indice_passeggero].nome,
					persona[indice_passeggero].cognome,persona[indice_passeggero].data_di_nascita.giorno,persona[indice_passeggero].data_di_nascita.mese,persona[indice_passeggero].data_di_nascita.anno,
					persona[indice_passeggero].data_di_iscrizione.giorno,persona[indice_passeggero].data_di_iscrizione.mese,persona[indice_passeggero].data_di_iscrizione.anno,persona[indice_passeggero].passaporto);
		}
	return 1;
}

/**
 * Questa funzione permette di inserire un nuovo passeggero. Inizialmente vengono controllati che i dati del nuovo passeggero
 * vengano inseriti correttamente. Infine vengono memorizzati i dati del nuovo passeggero nell'ultima posizione dell'array di struct.
 * @pre persona deve contenere tutti i dati dei passeggeri.In particolare in questa funzione serve per memorizzare i dati del nuovo passeggero inserito.
 * @pre numero_passeggeri deve contenere il numero effettivo dei passeggeri
 * @post  I dati del nuovo passeggero verranno salvati nell'ultima posizione dell'array di struct persona.
 */
int inserisci_nuovo_utente(passeggero persona[],int numero_passeggeri)
{ //Codice inserisci_nuovo_utente:C11
	setbuf (stdout,NULL);
	passeggero ultimo;						///Variabile di tipo passeggero utilizzata contenere i dati del nuovo passeggero inseriti dall'utente.
	char giorno[MAX_LUNGHEZZA_GIORNO];		///Vettore "giorno" che contiene il giorno di nascita del nuovo utente.
											///Lo dichiaro char in modo tale da effettuare vari controlli sul giorno inserito.

	char mese[MAX_LUNGHEZZA_MESE];			///Dichiaro un vettore "mese" che contiene il mese di nascita del nuovo utente.
											///Lo dichiaro char in modo tale da effettuare vari controlli sul mese inserito.

	char anno[LUNGHEZZA_ANNO];				///Dichiaro un vettore "anno" che contiene l'anno di nascita del nuovo utente.
											///Lo dichiaro char in modo tale da effettuare vari controlli sull'anno inserito.

	int stringa1=0;							///Variabile che conterra' 1 se il nome e' stato inserito correttamente,0 altrimenti.
	int flag1=0;							///Variabile che conterra' 1 se il giorno di nascita e' stato inserito correttamente,0 altrimenti.
	int flag2=0;							///Variabile che conterra' 1 se il mese di nascita e' stato inserito correttamente,0 altrimenti.
	int flag3=0;							///Variabile che conterra' 1 se l'anno di nascita e' stato inserito correttamente,0 altrimenti.
	int flag4=0;							///Variabile che conterra' 1 se la data di nascita inserita è reale,0 altrimenti.
	int stringa2=0;							///Variabile che conterra' 1 se il cognome e' stato inserito correttamente,0 altrimenti.
	int passaporto=0;						///Variabile che conterra' 1 se il codice del passaporto e' stato inserito correttamente, 0 altrimenti.

	int k=numero_passeggeri;

	while(stringa1==0)         ///Ciclo che permette all'utente di inserire un nome finche' non inserisce un nome valido.
	{
		printf("Inserisci nome (max 19 caratteri)\n");
		fgets(ultimo.nome,LUNGHEZZA_NOME,stdin);
		fflush(stdin);
		stringa1=controllo_Stringa_passeggero(ultimo.nome);
	}

	while(stringa2==0)      ///Ciclo che permette all'utente di inserire un cognome finche' non inserisce un nome valido.
	{
		printf("Inserisci cognome (max 19 caratteri)\n");
		fgets(ultimo.cognome,LUNGHEZZA_COGNOME,stdin);
		fflush(stdin);
		stringa2=controllo_Stringa_passeggero(ultimo.cognome);
	}

	while(flag4==0)       ///Ciclo che permette all'utente di inserire una data finche' non inserisce una data reale.
	{
		printf("Inserisci data di nascita\n");
		flag1=0;
		flag2=0;
		flag3=0;

		while (flag1==0)     ///Ciclo che permette all'utente di inserire un giorno finche' non inserisce un giorno valido.
		{
			printf("Inserisci giorno di nascita: ");
			scanf("%s",giorno);
			flag1=controllo_giorno_data_di_nascita(giorno,&ultimo.data_di_nascita.giorno);
		}

		while(flag2==0)   ///Ciclo che permette all'utente di inserire un mese finche' non inserisce un mese valido.
		{
			printf("Inserisci mese di nascita: ");
			scanf("%s",mese);
			flag2=controllo_mese_data_di_nascita(mese,&ultimo.data_di_nascita.mese);
		}
		while(flag3==0) ///Ciclo che permette all'utente di inserire un anno finche' non inserisce un anno valido.
		{
			printf("Inserisci anno di nascita: ");
			scanf("%s",anno);
			flag3=controllo_anno_data_di_nascita(anno,&ultimo.data_di_nascita.anno);
		}
		flag4=controllo_generale_sulla_data(ultimo.data_di_nascita);
	}

	printf("Data inserita corretta\n");
	svuota_buffer();

	printf("Data di iscrizione\n");
	acquisisci_data(&ultimo.data_di_iscrizione);
	printf("%d.",ultimo.data_di_iscrizione.giorno);
	printf("%d.",ultimo.data_di_iscrizione.mese);
	printf("%d\n",ultimo.data_di_iscrizione.anno);

	while(passaporto==0)     ///Ciclo che permette all'utente di inserire un passaporto finche' non inserisce un passaporto valido.
	{
		printf("Inserisci passaporto\n");
		scanf("%s",ultimo.passaporto);
		passaporto=controllo_Passaporto(ultimo.passaporto);
		svuota_buffer();
	}


	persona[k].id_passeggero=k+1;
	strcpy(persona[k].nome,ultimo.nome);
	strcpy(persona[k].cognome,ultimo.cognome);
	persona[k].data_di_nascita.giorno=ultimo.data_di_nascita.giorno;
	persona[k].data_di_nascita.mese=ultimo.data_di_nascita.mese;
	persona[k].data_di_nascita.anno=ultimo.data_di_nascita.anno;
	persona[k].data_di_iscrizione.giorno=ultimo.data_di_iscrizione.giorno;
	persona[k].data_di_iscrizione.mese=ultimo.data_di_iscrizione.mese;
	persona[k].data_di_iscrizione.anno=ultimo.data_di_iscrizione.anno;
	strcpy(persona[k].passaporto,ultimo.passaporto);


	printf("Passeggero inserito correttamente\n");
	visualizza_un_passeggero(persona,numero_passeggeri,k);

	return 1;

}

/**
 * Questa funzione permette di modificare i dati di un passeggero esistente.
 * Inizialmente viene chiesto all'utente di scegliere uno tra i passeggeri presenti da modificare.
 * Successivamente gli viene mostrato un secondo menu' dove vengono indicati i vari campi di quel passeggero da modificare.
 * Una volta modificato uno tra quei campi, il passeggero scelto dall'utente verra' modificato.
 * @pre persona deve contenere tutti i dati dei passeggeri
 * @pre numero_passeggeri deve contenere il numero effettivo dei passeggeri
 * @post I dati di un determinato passeggero verranno modificati.
 */
int modifica_utente(passeggero persona[],int numero_passeggeri) //Codice modifica_utente:C12
{
	setbuf (stdout,NULL);
	passeggero persona_modificata;     /// Variabile di tipo passeggero utilizzata per contenere uno dei campi modificati inseriti dall'utente
	char giorno[MAX_LUNGHEZZA_GIORNO]; /// Vettore che conterra' il giorno inserito dall'utente
	char mese[MAX_LUNGHEZZA_MESE];		/// Vettore che conterra' il mese inserito dall'utente
	char anno[LUNGHEZZA_ANNO];			/// Vettore che conterra' l'anno inserito dall'utente
	int stringa1=0;						/// Variabile che conterra' 1 se il nome e' stato inserito correttamente, 0 altrimenti.
	int flag1=0;						/// Variabile che conterra' 1 se il giorno e' stato inserito correttamente, 0 altrimenti.
	int flag2=0;						/// Variabile che conterra' 1 se il mese e' stato inserito correttamente, 0 altrimenti.
	int flag3=0;						/// Variabile che conterra' 1 se l'anno e' stato inserito correttamente, 0 altrimenti.
	int flag4=0;						/// Variabile che conterra' 1 se la data inserita e' reale, 0 altrimenti.
	int stringa2=0;						/// Variabile che conterra' 1 se il cognome e' stato inserito correttamente, 0 altrimenti.
	int passaporto=0;					/// Variabile che conterra' 1 se il passaporto e' stato inserito correttamente, 0 altrimenti.
	int indice_utente=0;				/// Variabile che conterra' l'indice del passeggero da modificare
	int t=0;							/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int t2=0;							/// Variabile che conterra' 1 se la scelta inserita sara' tra i passeggeri esistenti, 0 altrimenti.
	int p=0;							/// Variabile che conterra' 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int s=0;							/// Variabile che conterra' la scelta inserita, relativa a quale campo si vuole modificare.
	int i=0;							/// Variabile utilizzata per uscire dal ciclo.

	printf("Di quale passeggero vuoi modificare le informazioni?\n");
	do
	{
		t=0;
		t2=0;

		indice_utente=acquisisci_scelta(&t)-1; /// Decremento di 1 la scelta inserita dall'utente per risalire all'indice di quel passeggero.
		if((indice_utente>(numero_passeggeri-1))||(indice_utente<0)|| (strcmp(persona[indice_utente].nome,"")==0) ) /// Oltre al controllo del range dei passeggeri esistenti, controllo anche se un passeggero e' stato eliminato.
		{
			printf("Passeggero inserito non esistente\n");
			printf("Inserire un nuovo passeggero\n");
		}

		else
		{
			t2=1;
		}
	}while( (t==0) ||(t2==0) );

	visualizza_un_passeggero(persona,numero_passeggeri,indice_utente);

	do
	{
		printf ("\n Quale informazione vuoi modificare?\n");
		printf ("\n 1.NOME");
		printf ("\n 2.COGNOME");
		printf ("\n 3.DATA DI NASCITA");
		printf ("\n 4.PASSAPORTO");
		printf ("\n 5.TORNA AL MENU' INIZIALE");
		printf("\n Scelta: ");

		do
		{
			s=acquisisci_scelta(&p);
		}while(p==0);


		switch(s)
		{
		case 1:

			while(stringa1==0)  ///Ciclo che permette all'utente di inserire un nome finche' non inserisce un nome valido.
			{
				printf("Inserisci un nome (max 19 caratteri)\n");
				fgets(persona_modificata.nome,LUNGHEZZA_NOME,stdin);
				fflush(stdin);
				stringa1=controllo_Stringa_passeggero(persona_modificata.nome);
			}
			strcpy(persona[indice_utente].nome,persona_modificata.nome); ///Il campo modificato dall'utente viene salvato in quella posizione dell'array di struct dei passeggeri.

			i++;
			break;

		case 2:

			while(stringa2==0) ///Ciclo che permette all'utente di inserire un cognome finche' non inserisce un nome valido.
			{
				printf("Inserisci un cognome (max 19 caratteri)\n");
				fgets(persona_modificata.nome,LUNGHEZZA_COGNOME,stdin);
				fflush(stdin);
				stringa2=controllo_Stringa_passeggero(persona_modificata.cognome);
			}
			strcpy(persona[indice_utente].cognome,persona_modificata.cognome); ///Il campo modificato dall'utente viene salvato in quella posizione dell'array di struct dei passeggeri.
			i++;
			break;

		case 3:
			while(flag4==0) ///Ciclo che permette all'utente di inserire una data finche' non inserisce una data reale.
			{
				printf("Inserisci data di nascita\n");
				flag1=0;
				flag2=0;
				flag3=0;

				while (flag1==0) ///Ciclo che permette all'utente di inserire un giorno finche' non inserisce un giorno valido.
				{
					printf("Inserisci giorno di nascita: ");
					scanf("%s",giorno);
					flag1=controllo_giorno_data_di_nascita(giorno,&persona_modificata.data_di_nascita.giorno);
				}

				while(flag2==0) ///Ciclo che permette all'utente di inserire un mese finche' non inserisce un mese valido.
				{
					printf("Inserisci mese di nascita: ");
					scanf("%s",mese);
					flag2=controllo_mese_data_di_nascita(mese,&persona_modificata.data_di_nascita.mese);
				}
				while(flag3==0) ///Ciclo che permette all'utente di inserire un anno finche' non inserisce un anno valido.
				{
					printf("Inserisci anno di nascita: ");
					scanf("%s",anno);
					flag3=controllo_anno_data_di_nascita(anno,&persona_modificata.data_di_nascita.anno);
				}
				flag4=controllo_generale_sulla_data(persona_modificata.data_di_nascita);
			}
			persona[indice_utente].data_di_nascita.giorno=persona_modificata.data_di_nascita.giorno; ///Il campo modificato dall'utente viene salvato in quella posizione dell'array di struct dei passeggeri.
			persona[indice_utente].data_di_nascita.mese=persona_modificata.data_di_nascita.mese;
			persona[indice_utente].data_di_nascita.anno=persona_modificata.data_di_nascita.anno;
			svuota_buffer();
			i++;
			break;

		case 4:
			while(passaporto==0) ///Ciclo che permette all'utente di inserire un passaporto finche' non inserisce un passaporto valido.
			{
				printf("Inserisci passaporto\n");
				scanf("%s",persona_modificata.passaporto);
				passaporto=controllo_Passaporto(persona_modificata.passaporto);
			}
			strcpy(persona[indice_utente].passaporto,persona_modificata.passaporto);   ///Il campo modificato dall'utente viene salvato in quella posizione dell'array di struct dei passeggeri.
			svuota_buffer();
			i++;
			break;

		case 5:
			menu();
			i++;
			break;

		default:
			printf("\n Valore inserito non corretto \n");
			printf("Inserire un nuovo valore ");
		}
	}while(i==0); /// Se l'utente non inserisce una tra le scelte presenti nel menu', dovra' inserire una nuova scelta

	printf("Il passeggero %d è stato modificato correttamente\n",persona[indice_utente].id_passeggero);

	visualizza_un_passeggero(persona,numero_passeggeri,indice_utente);

	return 1;

}

/**
 * Questa funzione permette di eliminare un passeggero.
 * Inizialmente viene controllato che l'id del passeggero da eliminare e' stato inserito corretamente.
 *  Infine vengono eliminati i dati del passeggero.
 * @pre persona deve contenere tutti i dati dei passeggeri
 * @pre numero_passeggeri deve contenere il numero effettivo dei passeggeri
 * @post Il passeggero selezionato dall'utente verra' eliminato e i suoi dati non verranno visualizzati nell'array di struct.
 */
int elimina_utente(passeggero persona[],int numero_passeggeri )
{   //Codice elimina_utente:C13
	setbuf (stdout,NULL);
	int t=0;			///Variabile che conterrà 1 se la scelta inserita sara' un numero, 0 altrimenti.
	int t2=0;			///Variabile che conterra' 1 se la scelta inserita sara' tra i passeggeri esistenti,0 altrimenti.
	int indice_utente;		///Variabile che conterra' l'indice del passeggero da eliminare.


	printf("Quale passeggero vorresti eliminare?\n");
	do
	{
		t=0;
		t2=0;

		indice_utente=acquisisci_scelta(&t)-1; /// Decremento di 1 la scelta inserita dall'utente per risalire all'indice di quel passeggero.
		if( (indice_utente> (numero_passeggeri-1) ) || (indice_utente<0) || (strcmp(persona[indice_utente].nome,"")==0) ) /// Oltre al controllo del range dei passeggeri esistenti, controllo anche se un passeggero e' stato gia' eliminato
		{
			printf("Valore inserito non corretto\n");
			printf("Inserisci un nuovo valore\n");
		}
		else
		{
			t2=1;
		}
	}while( (t==0) || (t2==0) );

	visualizza_un_passeggero(persona,numero_passeggeri,indice_utente);

	strcpy(persona[indice_utente].nome,"");
	strcpy(persona[indice_utente].cognome,"");
	persona[indice_utente].data_di_nascita.giorno=0;
	persona[indice_utente].data_di_nascita.mese=0;
	persona[indice_utente].data_di_nascita.anno=0;
	persona[indice_utente].data_di_iscrizione.giorno=0;
	persona[indice_utente].data_di_iscrizione.mese=0;
	persona[indice_utente].data_di_iscrizione.anno=0;
	strcpy(persona[indice_utente].passaporto,"");

	printf("Il passeggero %d è stato eliminato correttamente\n",persona[indice_utente].id_passeggero);

	return 1;
}

/**
 * Questa funzione permette di cercare il nome inserito in precedenza dall'utente, controllando che sia presente tra quelli inseriti nel file.
 * Inoltre una volta trovato quel nome, verranno visualizzati i dati di quel passeggero, o eventualmente dei passeggeri che hanno quel nome.
 * @pre persona deve contenere tutti i dati dei passeggeri
 * @pre stringa deve contenere il nome inserito dall'utente per cui si  vuole effettuare una ricerca
 * @pre numero_dei_passeggeri deve contenere il numero effettivo dei passeggeri
 * @post I dati di quel o di quei passeggeri cercati, che saranno attraverso una funzione visualizzati all'utente.
 */
int ricerca_per_nome(passeggero persona[],char stringa[],int numero_dei_passeggeri)
{
	int i=0;
	int flag=0;
	for(i=0;i<numero_dei_passeggeri;i++)
	{
		if( (strcmp(stringa,persona[i].nome)) == 0 )
		{
			visualizza_un_passeggero(persona,numero_dei_passeggeri,i);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Passeggero non esistente\n");
	}
	return flag;
}

/**
 * Questa funzione permette di cercare il cognome inserito in precedenza dall'utente, controllando che sia presente tra quelli inseriti nel file.
 * Inoltre una volta trovato quel cognome, verranno visualizzati i dati di quel passeggero, o eventualmente dei passeggeri che hanno quel cognome.
 * @pre persona deve contenere tutti i dati dei passeggeri
 * @pre stringa deve contenere il cognome inserito dall'utente per cui si vuole effettuare una ricerca
 * @pre numero_dei_passeggeri deve contenere il numero effettivo dei passeggeri
 * @post I dati di quel o di quei passeggeri cercati, che saranno attraverso una funzione visualizzati all'utente.
 */
int ricerca_per_cognome(passeggero persona[],char stringa[],int numero_dei_passeggeri)
{
	int i=0;
	int flag=0;
	for(i=0;i<numero_dei_passeggeri;i++)
	{
		if( (strcmp(stringa,persona[i].cognome)) == 0 )
		{
			visualizza_un_passeggero(persona,numero_dei_passeggeri,i);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Passeggero non esistente\n");
	}
	return flag;
}

/**
* Questa funzione permette di cercare la data di nascita inserita in precedenza dall'utente, controllando che sia presente tra quelle inserite nel file.
 * Inoltre una volta trovata quella data di nascita, verranno visualizzati i dati di quel passeggero, o eventualmente dei passeggeri che sono nati in quella data.
 * @pre persona deve contenere tutti i dati dei passeggeri
 * @pre data_ricercata deve contenere la data di nascita inserita dall'utente per cui si vuole effettuare una ricerca
 * @pre numero_dei_passeggeri deve contenere il numero effettivo dei passeggeri
 * @post I dati di quel o di quei passeggeri cercati, che saranno attraverso una funzione visualizzati all'utente.
 */
int ricerca_per_data_di_nascita(passeggero persona[],data data_ricercata,int numero_dei_passeggeri)
{
	int i=0;
	int flag=0;
	for(i=0;i<numero_dei_passeggeri;i++)
	{
		if( (data_ricercata.giorno == persona[i].data_di_nascita.giorno) && (data_ricercata.mese == persona[i].data_di_nascita.mese) && (data_ricercata.anno == persona[i].data_di_nascita.anno))
		{
			visualizza_un_passeggero(persona,numero_dei_passeggeri,i);
			flag=1;
		}
	}
	if (flag==0)
	{
		printf("Data di nascita non esisente\n ");
	}
	return flag;
}

/**
 * Questa funzione permette di ricercare dei passeggeri secondo un determinato criterio.
 * Inizialmente  viene mostrato all'utente un menu' dove vengono indicati i vari campi per i quali ricercare un passeggero.
 * Una volta selezionato uno tra i criteri da ricercare,verranno chiamate altre funzioni.
 * @pre persona deve contenere tutti i dati dei passeggeri
 * @pre numero_di_passeggeri deve contenere il numero effettivo dei passeggeri
 * @post Attraverso altre funzioni presenti in questa funzione, verranno ricercati e successivamente visualizzati i passeggeri, secondo un  criterio inserito dall'utente.
 */
int ricerca_passeggeri(passeggero persona[],int numero_di_passeggeri)   //Codice funzione ricerca_passeggeri:C21
{
	int s=0;					///Variabile che conterra' la scelta inserita in base a quale campo si vuole ricercare.
	int p=0;					///Variabile che conterra' 1  se la scelta inserita sara' un numero,0 altrimenti.
	int i=0;					///VAriabile utilizzata per uscire dal ciclo.
	int stringa1=0;					///Variabile che conterra' 1 se il nome e' stato inserito correttamente,0 altrimenti.
	int ricerca_nome=0;				///Variabile che conterra' 1 se il nome inserito e' presente tra i passeggeri esistenti.
	int stringa2=0;					///Variabile che conterra' 1 se il cognome e' stato inserito correttamente,0 altrimenti.
	int ricerca_cognome=0;				///Variabile che conterra' 1 se il cognome inserito e' presente tra i passeggeri esistenti.
	int flag1=0;					///Variabile che conterra' 1 se il giorno di nascita e' stato inserito correttamente,0 altrimenti.
	int flag2=0;					///Variabile che conterra' 1 se il mese di nascita e' stato inserito correttamente,0 altrimenti.
	int flag3=0;					///Variabile che conterra' 1 se l'anno di nascita e' stato inserito correttamente,0 altrimenti.
	int flag4=0;					///Variabile che conterra' 1 se la data di nascita inserita è reale,0 altrimenti.
	int ricerca_data=0;				///Variabile che conterra' 1 se la data di nascita inserita e' presente tra i passeggeri esistenti.
	char giorno[MAX_LUNGHEZZA_GIORNO]; /// Vettore che conterra' il giorno che si vuole ricercare
	char mese[MAX_LUNGHEZZA_MESE];		/// Vettore che conterra' il mese che si vuole ricercare
	char anno[LUNGHEZZA_ANNO];			/// Vettore che conterra' l'anno che si vuole ricercare

	passeggero persona_ricercata;			///Variabile di tipo passeggero utilizzata per contenere uno dei campi del passeggero ricercato.



	do
	{
		printf ("\n Ricerca i passeggeri in base al:\n");
		printf ("\n 1.NOME");
		printf ("\n 2.COGNOME");
		printf ("\n 3.DATA DI NASCITA");
		printf ("\n 4.TORNA AL MENU' INIZIALE");
		printf("\n Scelta: ");

		do
		{
			s=acquisisci_scelta(&p);
		}while(p==0);


		switch(s)
		{
		case 1:

			while( (stringa1==0) || (ricerca_nome==0) )    ///Ciclo che permette all'utente di inserire un nome finche' non inserisce un nome valido di un passeggero esistente.
			{
				stringa1=0;
				ricerca_nome=0;
				printf("Inserisci il nome da ricercare (max 19 caratteri)\n");
				fgets(persona_ricercata.nome,LUNGHEZZA_NOME,stdin);
				fflush(stdin);
				stringa1=controllo_Stringa_passeggero(persona_ricercata.nome);
				ricerca_nome=ricerca_per_nome(persona,persona_ricercata.nome,numero_di_passeggeri);
			}
			i++;
			break;

		case 2:

			while( (stringa2==0) || (ricerca_cognome==0) )  ///Ciclo che permette all'utente di inserire un cognome finche' non inserisce un cognome di un passeggero esistente.
			{
				stringa2=0;
				ricerca_cognome=0;
				printf("Inserisci il cognome da ricercare (max 19 caratteri)\n");
				fgets(persona_ricercata.cognome,LUNGHEZZA_COGNOME,stdin);
				fflush(stdin);
				stringa2=controllo_Stringa_passeggero(persona_ricercata.cognome);
				ricerca_cognome=ricerca_per_cognome(persona,persona_ricercata.cognome,numero_di_passeggeri);
			}
			i++;
			break;

		case 3:
			while( (flag4==0) || (ricerca_data==0) )              ///Ciclo che permette all'utente di inserire una data finche' non inserisce una data reale e presente tra i passeggeri.
			{
				printf("Inserisci data di nascita da ricercare\n");
				flag1=0;
				flag2=0;
				flag3=0;
				flag4=0;
				ricerca_data=0;
				while (flag1==0)
				{
					printf("Inserisci giorno di nascita: ");   ///Ciclo che permette all'utente di inserire un giorno finche' non inserisce un giorno valido.
					scanf("%s",giorno);
					flag1=controllo_giorno_data_di_nascita(giorno,&persona_ricercata.data_di_nascita.giorno);
				}

				while(flag2==0)       							///Ciclo che permette all'utente di inserire un mese finche' non inserisce un mese valido.
				{
					printf("Inserisci mese di nascita: ");
					scanf("%s",mese);
					flag2=controllo_mese_data_di_nascita(mese,&persona_ricercata.data_di_nascita.mese);
				}
				while(flag3==0)									///Ciclo che permette all'utente di inserire un anno finche' non inserisce un anno valido.
				{
					printf("Inserisci anno di nascita: ");
					scanf("%s",anno);
					flag3=controllo_anno_data_di_nascita(anno,&persona_ricercata.data_di_nascita.anno);
				}
				flag4=controllo_generale_sulla_data(persona_ricercata.data_di_nascita);
				ricerca_data=ricerca_per_data_di_nascita(persona,persona_ricercata.data_di_nascita,numero_di_passeggeri);
			}
			svuota_buffer();
			i++;
			break;

		case 4:

			menu();
			break;

		default:
			printf("\n Valore inserito non corretto \n");
			printf("Inserire un nuovo valore ");
		}
	}while(i==0);   /// Se l'utente non inserisce una tra le scelte presenti nel menu', dovra' inserire una nuova scelta

	return 1;
}
























