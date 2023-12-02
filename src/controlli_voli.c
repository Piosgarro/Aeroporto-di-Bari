/**
* @file controlli_voli.c
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "controlli_voli.h"
#include "data_di_iscrizione.h"
#include "volo.h"
#include "costanti.h"
#include "data.h"
#include "ora.h"

/**
 * Questa funzione permette di controllare se il codice del volo inserito e' corretto o meno.Inizialmente controllo se i caratteri inseriti siano diversi a 9.
 *  Successivamente controllo se i primi due caratteri inseriti siano alfabetici e siano in maiuscolo,mentre i restanti 4 siano numerici.
 * @pre id_volo Deve contenere il codice di volo inserito.
 * @post Il codice di volo.
 */
int controllo_id_volo(char id_volo[])
{
	int i=0;
	int flag=0;												///Variabile di ritorno che conterra' 1 se il codice di volo e' inserito correttamente,0 altrimenti
	int lunghezza=strlen(id_volo);
	if (lunghezza!=(CODICE_VOLO-1))
	{
		printf("Codice volo inserito non corretto\n");
		return flag;
	}
	else
	{
		for(i=0;i<2;i++)
		{
			if( ! (isalpha(id_volo[i]) ) )
			{
				printf("Codice volo inserito non corretto\n");
				flag=0;
				return flag;
			}
			else
			{
				if( islower(id_volo[i]) )
				{
					printf("Hai inserito  caratteri minuscolo\n");
					flag=0;
					return flag;
				}
			}
		}

		for(i=2;i<(CODICE_VOLO-1);i++)
		{
			if( ! (isdigit(id_volo[i]) ) )
			{
				printf("Codice volo non corretto\n");
				flag=0;
				return flag;
			}
			else
			{
				flag=1;
			}
		}
	}
	return flag;
}

/**
 * Questa funzione permette di controllare se il codice di volo inserito sia gia' esistente.Confronto il codice di volo inserito con
 * tutti  i codici di volo gia' esistenti.
 * @pre id_volo Deve contenere il codice di volo inserito.
 * @pre numero_voli Deve contenere il numero  dei voli.
 * @pre voli Deve contenere tutti i codici  dei voli. In questa funzione mi serve per confrontare il codice di volo inserito
 * con ciascun codice di volo gia' esistente.
 * @post Il codice di volo
 */
int id_volo_inserito(char id_volo[], int numero_voli, volo voli[])
{
	int i=0;
	int flag=0;							///Variabile di ritorno che conterra' 1 se il codice di volo inserito non e' gia' esistente,0 altrimenti

	for(i=0;i<numero_voli;i++)
	{
		if( strcmp(id_volo,voli[i].id_volo)==0 )
		{
			printf("Codice volo già esistente\n");
			flag=0;
			return flag;
		}
		else
		{
			flag=1;
		}
	}
	return flag;
}

/**
 * Questa funzione permette di controllare il nome della compagnia o la destinazione,inseriti dall'utente.Inizialmente controllo se l'utente inserisce degli spazi
 * prima di scrivere il nome della compagnia o la destinazione.Succcessivamente controllo se la stringa inserita dall'utente sia composta solo da caratteri alfabetici.
 * Infine controllo se l'utente abbia inserito piu' di un spazio.
 * @pre stringa2 vettore di char che deve contenere il nome della compagnia o la destinazione inserita, sulla quale effettuo i vari controlli.
 * @post Il nome della compagnia o la destinazine .
 */
int controllo_Stringa2_volo(char stringa2[])
{
	int flag=0;							///Variabile di ritorno che conterra' 1 se il nome della compagnia o la destinazione siano inseriti correttamente,0 altrimenti
	int c=0;							///Variabile che conterra' il numero di caratteri del nome della compagnia o della destinazione.
	int i=0;
	int t=0;							///Variabile che conta gli spazi inseriti dall'utente.

	c=strlen(stringa2);
	stringa2[0]=toupper(stringa2[0]);		///Pongo il primo carattere alfabetico in maiuscolo.

	while(stringa2[0]==' ')					///Delimino tutti gli eventuali spazi inseriti inizialmente dall'utente.
	{
		flag=0;
		printf("Stringa inserita non corretta\n");
		return flag;
	}

	for(i=0;i<c-1;i++)
	{
		if( (isalpha(stringa2[i]) ) )
		{
			flag=1;
		}
		else
		{
			if(stringa2[i]==' ')				///Controllo se l'utente ha inserito eventuali spazi.
			{
				t++;
			}
			else
			{
				flag=0;
				printf("Stringa inserita non correttamente\n");
				return flag;
			}
		}
	}

	if(t>1)														///Controllo se gli spazi inseriti dall'utente sono piu' di uno.
	{
		printf("Hai inserito più di uno spazio\n");
		flag=0;
		return flag;
	}
	else
	{
		flag=1;
	}

	stringa2[c-1]='\0';										///Rimuovo lo \n e lo sovrascrivo con il terminatore di stringa \0
	return flag;
}

/**
 * Questa funzione permette di controllare la tipologia di aereo inserita dall'utente.Inizialmente controllo se l'utente inserisce degli spazi
 * prima di scrivere la tipologia di aereo.Succcessivamente controllo se la stringa inserita dall'utente sia composta solo da caratteri alfanumerici.
 * Infine controllo se l'utente abbia inserito piu' di un spazio.
 * @pre stringa vettore di char che deve contenere la  tipologia  di aereo inserita, sulla quale effettuo i vari controlli.
 * @post La tipologia  di aereo.
 */
int controllo_Stringa_volo(char stringa[] )
{
	int flag=0;						///Variabile di ritorno che conterra' 1 se la tipologia di aereo e' inserita correttamente,0 altrimenti
	int c=0;						///Variabile che conterra' il numero di caratteri del nome della tipologia di aereo.
	int i=0;
	int t=0;						///Variabile che conta gli spazi inseriti dall'utente.

	c=strlen(stringa);
	stringa[0]=toupper(stringa[0]);		///Pongo il primo carattere alfabetico in maiuscolo.

	while(stringa[0]==' ')			///Delimino tutti gli eventuali spazi inseriti inizialmente dall'utente.
	{
		flag=0;
		printf("Stringa inserita non corretta\n");
		return flag;
	}

	for(i=0;i<c-1;i++)
	{
		if( (isalnum(stringa[i]) ) )
		{
			flag=1;
		}
		else
		{
			if(stringa[i]==' ')				///Controllo se l'utente ha inserito eventuali spazi.
			{
				t++;
			}
			else
			{
				flag=0;
				printf("Stringa inserita non correttamente\n");
				return flag;
			}
		}
	}

	if(t>1)											///Controllo se gli spazi inseriti dall'utente sono piu' di uno.
	{
		printf("Hai inserito più di uno spazio\n");
		flag=0;
		return flag;
	}
	else
	{
		flag=1;
	}

	stringa[c-1]='\0';							///Rimuovo lo \n e lo sovrascrivo con il terminatore di stringa \0
	return flag;
}

/**
 * Questa funzione permette di controllare il numero dei  posti inseriti dall'utente.Inizialmente controllo se il numero dei caratteri inseriti
 * dall'utente e' diverso dal massimo del numero dei caratteri,ovvero 3.Successivamente  controllo se il numero dei posti inseriti
 * dall'utente e' composto solo da caratteri numerici.Infine controllo se il numero dei posti inseriti e' compreso tra 100 e 950.
 * @pre posti1 vettore di char che deve contenere il numero dei posti inseriti,sul quale effettuo i  vari controlli.
 * @pre posti	variabile che conterra' il numero dei posti convertito in intero.
 * @post Il numero dei posti.
 */
int controllo_posti(char posti1[],int* posti)
{
	int flag1;								///Variabile di ritorno che conterra' 1 se il numero dei posti e' stato inserito correttamente,0 altrimenti
	int i=0;
	int lunghezza_posti=strlen(posti1);

	if( (lunghezza_posti!=LUNGHEZZA_POSTI ) )
	{
		printf("Posti inseriti non corretti\n");
		flag1=0;
	}
	else{

		for(i=0;i<lunghezza_posti;i++)
		{
			if( ! (isdigit(posti1[i]) ) )
			{
				printf("Hai inserito un carattere non numerico\n");
				flag1=0;
				return flag1;
			}
			else
			{
				flag1=1;
			}
		}
		*posti=atoi(posti1);										///Converto il giorno di volo in intero.
		if( (*posti>MAX_POSTI ) || (*posti<MIN_POSTI) )
		{
			printf("Posti inseriti maggiori di 950 o minori di 100\n");
			flag1=0;
		}
		else{
			flag1=1;
		}
		return flag1;
	}
	return flag1;
}

/**
 * Questa funzione permette di controllare il giorno di volo inserito dall'utente. Inizialmente controllo se i caratteri inseriti dall'utente siano
 * compresi  tra 1 e 2.Successivamente controllo se i caratteri inseriti siano numerici. Infine controllo se il giorno inserito dall'utente sia compreso
 * tra 1 e 31.
 * @pre giorno1 vettore di char che deve contenere il giorno inserito, sul quale effettuo i vari controlli.
 * @post giorno_di_volo variabile che conterra' il giorno convertito in intero.
 * @post Il giorno di volo.
 */
int controllo_giorno_di_volo(char giorno1[],int* giorno_di_volo)
{
	int lunghezza_giorno=0;
	int flag3=0;													///Variabile di ritorno che conterra' 1 se il giorno di volo e' inserito correttamente,0 altrimenti
	int i=0;
	lunghezza_giorno=strlen(giorno1);

	if( (lunghezza_giorno>MAX_LUNGHEZZA_GIORNO ) || (lunghezza_giorno<MIN_LUNGHEZZA_GIORNO ) )
	{
		printf("Giorno inserito non corretto\n");
		flag3=0;
	}
	else
	{

		for(i=0;i<lunghezza_giorno;i++)
		{
			if( ! (isdigit(giorno1[i]) ) )
			{
				printf("Hai inserito un carattere non numerico\n");
				flag3=0;
				return flag3;
			}
			else
			{

				flag3=1;
			}
		}
		*giorno_di_volo=atoi(giorno1);								///Converto il giorno di volo in intero.
		if( (*giorno_di_volo>MAX_GIORNO ) || (*giorno_di_volo<MIN_GIORNO) )
		{
			printf("Giorno inserito maggiore di 31 o minore di 1\n");
			flag3=0;
		}
		else{
			flag3=1;
		}
		return flag3;
	}
	return flag3;



}

/**
 * Questa funzione permette di controllare il mese di volo inserito dall'utente. Inizialmente controllo se i caratteri inseriti dall'utente siano
 * compresi  tra 1 e 2.Successivamente controllo se i caratteri inseriti siano numerici. Infine controllo se il mese inserito dall'utente sia compreso
 * tra 1 e 12.
 * @pre mese1 vettore di char che deve contenere il mese inserito, sul quale effettuo i vari controlli.
 * @post mese_di_volo variabile che conterra' il giorno convertito in intero.
 * @post Viene  restituito il mese di volo.
 */
int controllo_mese_di_volo(char mese1[],int* mese_di_volo)
{
	int lunghezza_mese=0;
	int flag4;										///Variabile di ritorno che conterra' 1 se il mese di volo e' inserito correttamente,0 altrimenti
	int p=0;

	lunghezza_mese=strlen(mese1);

	if( (lunghezza_mese>MAX_LUNGHEZZA_MESE ) || (lunghezza_mese<MIN_LUNGHEZZA_MESE ) )
	{
		printf("Mese inserito non corretto\n");
		flag4=0;
	}
	else
	{
		for(p=0;p<lunghezza_mese;p++)
		{
			if( ! (isdigit(mese1[p]) ) )
			{
				printf("Hai inserito caratteri non numerico\n");
				flag4=0;
				return flag4;
			}
			else
			{
				flag4=1;
			}
		}
		*mese_di_volo=atoi(mese1);										///Converto il mese di nascita in intero.
		if( (*mese_di_volo>MAX_MESE ) || (*mese_di_volo<MIN_MESE) )
		{
			printf("Mese inserito maggiore di 12 o minore di 1\n");
			flag4=0;
		}
		else{
			flag4=1;
		}
		return flag4;
	}
	return flag4;
}

/**
 * Questa funzione permette di controllare l'anno di volo inserito dall'utente. Inizialmente controllo se i caratteri inseriti dall'utente siano
 * compresi  tra 1 e 4.Successivamente controllo se i caratteri inseriti siano numerici. Infine controllo se l'anno inserito dall'utente sia compreso
 * tra 2019 e 2020.
 * @pre anno1 vettore di char che deve contenere l'anno inserito, sul quale effettuo i vari controlli.
 * @post anno_di_volo variabile che conterra' l'anno convertito in intero.
 * @post Viene restituito l'anno di volo.
 */
int controllo_anno_di_volo(char anno1[],int* anno_di_volo)
{
	int lunghezza_anno=0;
	int flag5;								///Variabile di ritorno che conterra' 1 se il giorno di volo e' inserito correttamente,0 altrimenti.
	int j=0;

	lunghezza_anno=strlen(anno1);

	if( (lunghezza_anno!=LUNGHEZZA_ANNO ) )
	{
		printf("Anno inserito non corretto\n");
		flag5=0;
		return flag5;
	}
	else{
		for(j=0;j<lunghezza_anno;j++){
			if( ! (isdigit(anno1[j]) ) )
			{
				printf("Hai inserito un carattere non numerico\n");
				flag5=0;
				return flag5;
			}
			else{
				flag5=1;
			}
		}
		*anno_di_volo=atoi(anno1);							///Converto l'anno di volo in intero.
		if( (*anno_di_volo<2019 ) || (*anno_di_volo>2020) )
		{
			printf("Anno inserito minore di 2019 o maggiore di 2020\n");
			flag5=0;
		}
		else{
			flag5=1;
		}
		return flag5;

	}
}

/**
 * Questa funzione permette di controllare se la data di volo inserita e' realistica. Inizialmente controllo se il giorno inserito sia compreso tra 1 e 30
 *  nel caso se il mese fosse Aprile,Giugno,Settembre,Novembre. Nel caso se il mese fosse Febbraio verifico che l'anno sia o meno bisestile. In caso positivo
 *  il massimo dei  giorni sara' 29 altrimenti 28.In tutti gli altri mesi il massimo è 31
 * @pre giorno_volo vettore di struct di tipo data che deve contenere la data di volo  inserita dall'utente.
 * @post  Viene restituita la data di volo.
 */
int data_volo_corretta_1(data giorno_volo)
{
	int flag4=0;


	switch(giorno_volo.mese)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		if( (giorno_volo.giorno < MIN_GIORNO) || (giorno_volo.giorno > (MAX_GIORNO-1) ))
		{
			printf ("Giorno inserito non corretto\n");
			flag4=0;
			return flag4;
		}
		break;
	case 2:
		if ( (giorno_volo.anno % 4)== 0)
		{
			if( (giorno_volo.giorno < MIN_GIORNO) || (giorno_volo.giorno > MAX_GIORNO-2 ) )
			{
				printf ("Giorno inserito non corretto\n");
				flag4=0;
				return flag4;
			}
		}

		else
		{
			if( (giorno_volo.giorno < MIN_GIORNO) || (giorno_volo.giorno > MAX_GIORNO-3 ) )
			{
				printf ("Giorno inserito non corretto\n");
				flag4=0;
				return flag4;
			}
		}
		break;
	default:
		if( (giorno_volo.giorno < MIN_GIORNO) || (giorno_volo.giorno > MAX_GIORNO ) )
		{
			printf ("Giorno inserito non corretto\n");
			flag4=0;
			return flag4;
		}
		break;
	}
	flag4=1;
	return flag4;
}

/**
 * Questa funzione permette  di controllare  se la data di volo inserita e' maggiore o uguale della data del sistema.
 * Inizialmente controllo se l'anno di volo inserito dall'utente sia maggiore dell'anno di sistema.Nel caso caso fosse vero qualsiasi
 * data di volo con l'anno minore del 2020 sara' corretta,altrimenti controllo se l'anno di volo sia uguale all'anno del sistema.
 * Nel caso fosse vero controllo se il mese di volo inserito sia uguale al mese di sistema, se vero controllo se il giorno di volo
 * inserito sia maggiore o uguale al giorno di sistema, altrimenti controllo se sia maggiore del mese  di  sistema.
 * @pre giorno_volo Deve contenere la data di volo inserita dall'utente. In questa funzione viene confrontata con la data del sistema.
 * @pre giorno_sistema Deve contenere il giorno del  sistema.
 * @pre mese_sistema Deve contenere il mese del sistema
 * @pre anno_sistema Deve contenere l'anno del sistema.
 * @post Viene restituita la data di volo.
 */
int data_volo_corretta_2(data giorno_volo,int giorno_sistema,int mese_sistema,int anno_sistema)
{
	int flag7=0;
	if(giorno_volo.anno>anno_sistema)
	{
		flag7=1;
	}
	else
	{
		if(giorno_volo.anno==anno_sistema)
		{
			if(giorno_volo.mese==mese_sistema)
			{
				if(giorno_volo.giorno>=giorno_sistema)
				{
					flag7=1;
				}
				else
				{
					flag7=0;
					return flag7;
				}

			}
			else
			{
				if(giorno_volo.mese>mese_sistema)
				{
					flag7=1;
				}
				else
				{
					flag7=0;
					return flag7;
				}
			}
		}
		else
		{
			flag7=1;
		}
	}
	return flag7;
}


/**
 * Questa funzione permette di controllare l'ora o i minuti (sia di partenza che di arrivo) inseriti dall'utente.
 * Inizialmente controllo se i  caratteri  inseriti dall'utente siano compresi tra 1 e 2.Successivamente controllo se l'utente abbia
 * inserito dei caratteri non numerici.
 * @pre ora_e_minuti	vettore di char che deve contenere l'ora o i minuti inseriti, sul quale effettuo i vari controlli.
 * @post ora_e_minuti2 variabile  che conterra' l'ora o i minuti convertiti in intero.
 * @post Vengono  restituiti l'ora o i minuti.
 */
int controllo_ora_e_minuti(char ora_e_minuti[], int* ora_e_minuti2)
{
	int flag3=0;							///Variabile di ritorno che conterra' 1 se l'ora o i minuti sono inseriti correttamente,0 altrimenti
	int j=0;

	int lunghezza_ora_e_minuti=strlen(ora_e_minuti);
	if( (lunghezza_ora_e_minuti>MAX_LUNGHEZZA_ORA_E_MINUTI ) || (lunghezza_ora_e_minuti<MIN_LUNGHEZZA_ORA_E_MINUTI ) )
	{
		printf("Ora o minuti non corretti\n");
		flag3=0;
		return flag3;
	}
	else
	{
		for(j=0;j<lunghezza_ora_e_minuti;j++)
		{
			if( ! (isdigit(ora_e_minuti[j]) ) )
			{
				printf("Hai inserito un carattere non numerico\n");
				flag3=0;
				return flag3;
			}
			else
			{
				flag3=1;
			}
		}
		*ora_e_minuti2=atoi(ora_e_minuti);			///Converto l'ora o i minuti in intero.

	}
	return flag3;
}

/**
 * Questa funzione permette di controllare se l'ora di partenza inserita dall'utente e' corretta.
 * Inizialmente controllo se l'ora di partenza inserita e' compresa tra 0 e 23. Se vero controllo se i minuti inseriti
 * sono compresi tra 0 e 59.
 * @pre ora_partenza vettore di struct che contiene l'ora di partenza inserita dall'utente.Viene utilizzata per effettuare controlli sull'ora e i minuti inseriti.
 * @post L'ora di partenza.
 */
int ora_di_partenza_corretta(ora ora_partenza)
{
	int flag1=0;						///Variabile di ritorno che conterra' 1 se l'ora di partenza e' inserita correttamente,0 altrimenti.
	if( (ora_partenza.ora>MAX_ORA ) || (ora_partenza.ora<MIN_ORA) )
	{
		printf("Ora di partenza inserita maggiore di 23 o minore di 0\n");
		flag1=0;
		return flag1;
	}
	else
	{
		if( (ora_partenza.minuti>MAX_MINUTI ) || (ora_partenza.minuti<MIN_MINUTI) )
		{
			printf("Minuti inseriti maggiori di 59 o minori di 0\n");
			flag1=0;
			return flag1;
		}
		else
		{
			flag1=1;
		}
	}
	return flag1;
}

/**
 * Questa funzione permette di controllare se l'ora di arrivo inserita dall'utente e' corretta. Inizialmente controllo se l'ora di
 * arrivo inserita e' minore di 0 o maggiore di 23 o se e' minore dell'ora di arrivo. Successivamente controllo se i minuti di arrivo
 * inseriti sono compresi tra 0 e 59. Nel caso l'ora di arrivo e' uguale all'ora di partenza controllo che i minuti di arrivo siano maggiori
 * dei minuti di partenza.
 * @pre ora_partenza	vettore di struct che deve contenere l'ora di partenza.
 * @pre ora_arrivo	vettore di struct che deve contenere l'ora di arrivo.
 * @post L'ora di arrivo.
 */
int ora_di_arrivo_corretta(ora ora_partenza,ora ora_arrivo)
{
	int flag1=0;											///Variabile di ritorno che conterra'  1 se l'ora di arrivo e' inserita correttamente,0 altrimenti.
	if( (ora_arrivo.ora>MAX_ORA ) || (ora_arrivo.ora<MIN_ORA) || (ora_arrivo.ora<ora_partenza.ora) )
	{
		printf("Ora di arrivo inserita non corretta\n");
		flag1=0;
		return flag1;
	}
	else
	{
		if( (ora_arrivo.minuti>MAX_MINUTI ) || (ora_arrivo.minuti<MIN_MINUTI) )
		{
			printf("Minuti inseriti maggiori di 59 o minori di 0\n");
			flag1=0;
			return flag1;
		}
		else
		{
			if( (ora_arrivo.ora==ora_partenza.ora) )
			{
				if ( (ora_arrivo.minuti<=ora_partenza.minuti ) )
				{
					printf("Minuti inseriti non corretti\n");
					flag1=0;
					return flag1;
				}
				else
				{
					flag1=1;
				}
			}
			else
			{
				flag1=1;
			}
		}
	}
	return flag1;
}


/**
 * Questa funzione permette di calcolare la durata di un volo.Inizialmente controllo se l'ora di arrivo e' maggiore dell'ora di partenza
 *  e se i minuti di arrivo sono maggiori o uguali ai minuti di partenza. Successivamente controllo se l'ora di arrivo e' maggiore
 *  dell'ora di partenza e i minuti di arrivo sono minori dei minuti di partenza. Infine controllo il caso in cui l'ora di arrivo sia
 *  uguale all'ora di partenza e i minuti di arrivo siano maggiori dei  minuti di partenza.
 * @pre ora_partenza vettore di struct che deve contenere l'ora di partenza.
 * @pre ora_arrivo vettore di  struct che deve contenere l'ora di arrivo.
 * @post Viene restituita durata.
 */
int calcola_durata(ora ora_partenza,ora ora_arrivo)
{
	int durata=0;												///Variabile di ritorno che conterra' la durata.
	if ( (ora_arrivo.ora>ora_partenza.ora) && (ora_arrivo.minuti>=ora_partenza.minuti) )
	{
		durata=((ora_arrivo.ora-ora_partenza.ora)*60)+(ora_arrivo.minuti-ora_partenza.minuti);
	}
	else
		if	( (ora_arrivo.ora>ora_partenza.ora) && (ora_arrivo.minuti<ora_partenza.minuti))
		{
			durata=((ora_arrivo.ora-ora_partenza.ora)*60)-(ora_partenza.minuti-ora_arrivo.minuti);

		}
		else
		{
			if ( (ora_arrivo.ora==ora_partenza.ora) && (ora_arrivo.minuti>ora_partenza.minuti) )
			{
				durata=(ora_arrivo.minuti-ora_partenza.minuti);

			}

		}
	return durata;
}

