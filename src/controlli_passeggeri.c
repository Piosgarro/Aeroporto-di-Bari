/**
* @file controlli_passeggeri.c
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "controlli_passeggeri.h"
#include <stdlib.h>
#include "passeggero.h"
#include "costanti.h"
#include "data.h"

/**
 * Questa funzione permette di controllare il nome o il cognome inseriti dall'utente.Inizialmente controllo se l'utente inserisce degli spazi
 * prima di scrivere il nome o il cognome. Succcessivamente controllo se la stringa inserita dall'utente sia composta solo da caratteri alfabetici.
 * Infine controllo se l'utente abbia inserito piu' di un spazio.
 * @pre stringa vettore di char che deve contenere il nome o il cognome inserito , sulla quale effettuo i vari controlli.
 * @post Il nome o il cognome inserito.
 */
int controllo_Stringa_passeggero(char stringa[])
{
		int flag=0;									     ///Variabile di ritorno che conterra' 1 se il nome o il cognome siano inseriti correttamente,0 altrimenti
		int c=0;										///Variabile che conterra' il numero di caratteri del nome o cognome inserito.
		int i=0;
		int t=0;										///Variabile che conta gli spazi inseriti dall'utente.

		c=strlen(stringa);
		stringa[0]=toupper(stringa[0]);					///Pongo il primo carattere alfabetico in maiuscolo.

		while(stringa[0]==' ')									///Delimino tutti gli eventuali spazi inseriti inizialmente dall'utente.
		{
			flag=0;
			printf("Stringa inserita non corretta\n");
			return flag;
		}

		for(i=0;i<c-1;i++)
		{
			if( (isalpha(stringa[i]) ) )
			{
				flag=1;
			}
			else
			{
				if(stringa[i]==' ')										///Controllo se l'utente ha inserito eventuali spazi.
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

		if(t>1)															///Controllo se gli spazi inseriti dall'utente sono piu' di uno.
		{
			printf("Hai inserito più di uno spazio\n");
			flag=0;
			return flag;
		}
		else
		{
			flag=1;
		}

		stringa[c-1]='\0';												///Rimuovo lo \n e lo sovrascrivo con il terminatore di stringa \0
		return flag;
	}


/**
 * Funzione che permette di controllare il codice di passaporto inserito. Inizialmente controllo se i caratteri inseriti siano diversi di 9.
 *  Successivamente controllo se i primi due caratteri inseriti siano alfabetici e siano in maiuscolo,mentre i restanti 7 siano numerici.
 * @pre passaporto vettore di char che deve contenere il codice di passaporto sul quale effettuo i vari controlli.
 * @post Il codice del passaporto inserito.
 */
int controllo_Passaporto(char passaporto[])
{
	int i=0;
	int flag=0; 									///Variabile di ritorno che conterra' 1 se il codice di passaporto e' stato inserito correttamente,0 altrimenti
	int lunghezza=strlen(passaporto);
	if (lunghezza!=N_PASSAPORTO)
	{
		printf("Codice passaporto inserito non corretto\n");
		return flag;
	}
	else
	{
		for(i=0;i<2;i++)
		{
			if( ! (isalpha(passaporto[i]) ) )
			{
				printf("Codice passaporto inserito non corretto\n");
				flag=0;
				return flag;
			}
			else
			{
				if( islower(passaporto[i]) )
				{
					printf("Hai inserito caratteri minuscoli\n");
					flag=0;
					return flag;
				}
			}
		}


	for(i=2;i<N_PASSAPORTO;i++){
		if( ! (isdigit(passaporto[i]) ) )
		{
			printf("Codice passaporto non corretto\n");
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
 * Questa funzione permette di controllare il giorno di nascita inserito dall'utente. Inizialmente controllo se i caratteri inseriti dall'utente siano
 * compresi  tra 1 e 2.Successivamente controllo se i caratteri inseriti siano numerici. Infine controllo se il giorno inserito dall'utente sia compreso
 * tra 1 e 31.
 * @pre giorno1 vettore di char che deve contenere il giorno inserito, sul quale effettuo i vari controlli.
 * @post giorno_data_di_nascita variabile che conterra' il giorno convertito in intero.
 * @post Il giorno di nascita.
 */
int controllo_giorno_data_di_nascita(char giorno1[],int* giorno_data_di_nascita)
{
	int lunghezza_giorno=0;
	int flag1;											///Variabile di ritorno che conterra' 1 se il giorno di nascita e' stato inserito correttamente,0 altrimenti
	int i=0;
	lunghezza_giorno=strlen(giorno1);

	if( (lunghezza_giorno>MAX_LUNGHEZZA_GIORNO ) || (lunghezza_giorno<MIN_LUNGHEZZA_GIORNO ) )
	{
		printf("Giorno inserito non corretto\n");
		flag1=0;
	}
	else
	{

		for(i=0;i<lunghezza_giorno;i++)
		{
			if( ! (isdigit(giorno1[i]) ) )
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
		*giorno_data_di_nascita=atoi(giorno1);								///Converto il giorno di nascita in intero in modo tale da controllare se e' minore  di 1 o maggiore di 31.
		if( (*giorno_data_di_nascita>MAX_GIORNO ) || (*giorno_data_di_nascita<MIN_GIORNO) )
		{
			printf("Giorno inserito maggiore di 31 o minore di 1\n");
			flag1=0;
		}
		else
		{
			flag1=1;
		}
		return flag1;
	}
	return flag1;
}

/**
 * Questa funzione permette di controllare il mese di nascita inserito dall'utente. Inizialmente controllo se i caratteri inseriti dall'utente siano
 * compresi  tra 1 e 2.Successivamente controllo se i caratteri inseriti siano numerici. Infine controllo se il mese inserito dall'utente sia compreso
 * tra 1 e 12.
 * @pre mese1 vettore di char che deve contenere il mese inserito, sul quale effettuo i vari controlli.
 * @post mese_data_di_nascita variabile che conterra' il giorno convertito in intero.
 * @post Il mese di nascita.
 */
int controllo_mese_data_di_nascita(char mese1[],int* mese_data_di_nascita)
{
	int lunghezza_mese=0;
	int flag2=0;											///Variabile di ritorno che conterra' 1 se il mese di nascita e' stato inserito correttamente,0 altrimenti
	int p=0;

	lunghezza_mese=strlen(mese1);

	if( (lunghezza_mese>MAX_LUNGHEZZA_MESE ) || (lunghezza_mese<MIN_LUNGHEZZA_MESE ) )
	{
		printf("Mese inserito non corretto\n");
		flag2=0;
	}
	else
	{
		for(p=0;p<lunghezza_mese;p++)
		{
			if( ! (isdigit(mese1[p]) ) )
			{
				printf("Hai inserito caratteri non numerici\n");
				flag2=0;
				return flag2;
			}
			else
			{
				flag2=1;
			}
		}
		*mese_data_di_nascita=atoi(mese1);					///Converto il mese di nascita in intero in modo tale da controllare se e' minore  di 1 o maggiore di 12.
		if( (*mese_data_di_nascita>MAX_MESE ) || (*mese_data_di_nascita<MIN_MESE) )
		{
			printf("Mese inserito maggiore di 12 o minore di 1\n");
			flag2=0;
		}
		else{
			flag2=1;
		}
		return flag2;
	}
	return flag2;
}

/**
 * Questa funzione permette di controllare l'anno di nascita inserito dall'utente. Inizialmente controllo se i caratteri inseriti dall'utente siano
 * compresi  tra 1 e 4.Successivamente controllo se i caratteri inseriti siano numerici. Infine controllo se l'anno inserito dall'utente sia compreso
 * tra 1960 e 2001.
 * @pre anno1 vettore di char che deve contenere l'anno inserito, sul quale effettuo i vari controlli.
 * @post anno_data_di_nascita variabile che conterra' l'anno convertito in intero.
 * @post L'anno di nascita
 */
int controllo_anno_data_di_nascita(char anno1[],int* anno_data_di_nascita)
{
	int lunghezza_anno=0;
	int flag3=0;								///Variabile di ritorno che conterra' 1 se il giorno di nascita e' inserito correttamente,0 altrimenti
	int j=0;

	lunghezza_anno=strlen(anno1);

	if( (lunghezza_anno!=LUNGHEZZA_ANNO ) )
	{
		printf("Anno inserito non corretto\n");
		flag3=0;
		return flag3;
	}
	else
	{
		for(j=0;j<lunghezza_anno;j++)
		{
			if( ! (isdigit(anno1[j]) ) )
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
		*anno_data_di_nascita=atoi(anno1);							///Converto il giorno di nascita in intero in modo tale da controllare se e' minore  di 1960 o maggiore di 2001.
		if( (*anno_data_di_nascita<MAX_ANNO ) || (*anno_data_di_nascita>MIN_ANNO) )
		{
			printf("Anno inserito minore di 1960 o maggiore di 2001\n");
			flag3=0;
		}
		else
		{
			flag3=1;
		}
		return flag3;

	}
}

/**
 * Questa funzione permette di controllare se la data di nascita inserita e' realistica. Inizialmente controllo se il giorno inserito sia compreso tra 1 e 30
 *  nel caso il mese fosse Aprile,Giugno,Settembre,Novembre. Nel caso se il mese fosse Febbraio verifico che l'anno sia o meno bisestile. In caso positivo
 *  il massimo dei  giorni sara' 29 altrimenti 28.In tutti gli altri mesi il massimo è 31
 * @pre data_nascita vettore di struct di tipo data che deve contenere la data di nascita  inserita dall'utente.
 * @post  La data di nascita
 */
int	controllo_generale_sulla_data(data data_nascita)
{

	int flag4=0;						///Variabile di ritorno che conterra' 1 se la data di nascita e' inserita correttamente,0 altrimenti


	switch(data_nascita.mese)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		if( (data_nascita.giorno < MIN_GIORNO) || (data_nascita.giorno > (MAX_GIORNO-1) ))
		{
			printf ("Giorno inserito non corretto\n");
			flag4=0;
			return flag4;
		}
		break;
	case 2:
		if ( (data_nascita.anno % 4)== 0)
		{
			if( (data_nascita.giorno < MIN_GIORNO) || (data_nascita.giorno > MAX_GIORNO-2 ) )
			{
				printf ("Giorno inserito non corretto\n");
				flag4=0;
				return flag4;
			}
		}

		else
		{
			if( (data_nascita.giorno < MIN_GIORNO) || (data_nascita.giorno > MAX_GIORNO-3 ) )
			{
				printf ("Giorno inserito non corretto\n");
				flag4=0;
				return flag4;
			}
		}
		break;
	default:
		if( (data_nascita.giorno < MIN_GIORNO) || (data_nascita.giorno > MAX_GIORNO ) )
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


