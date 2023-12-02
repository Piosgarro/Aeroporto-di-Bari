/**
* @file menu.c
*
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "passeggero.h"
#include "svuota_buffer.h"
#include "costanti.h"
#include "volo.h"
#include "prenotazione.h"

/**
 * Questa funzione controlla se la scelta inserita e' un numero.
 * @pre t deve essere inizializzata a 0.
 * @post La t conterra' 1 se la scelta inserita e' corretta oppure 0 altrimenti.
 * @post La s conterra' la scelta inserita dall'utente.
 */
int acquisisci_scelta(int* t)
{
	char* buffer;					///Vettore che conterra' i caratteri non numerici nel caso vengano inseriti dall'utente.
	char scelta[LUNGHEZZA_SCELTA]; /// Variabile che conterra' la scelta dell'utente
	int s;                         /// Variabile che conterra' la scelta dell'utente trasformata in un numero.

	*t=0;
	fgets (scelta,LUNGHEZZA_SCELTA,stdin);   ///La funzione strtol prende in input un valore in formato stringa e lo converte in un long. La parte rimanente viene
											///memorizzata in una ulteriore stringa(buffer). Effettuo il  cast int.
	fflush(stdin);
	s=(int) strtol(scelta,&buffer,0);
	if (strcmp(buffer, "\n") == 0)
	{			///In questo controllo si entrera' se la scelta inserita dall'utente e' un numero.
		*t=1;
	}
	else
	{
		printf("\nValore inserito non corretto \n");
		printf("Inserire un nuovo valore\n");

	}
	return s;
}

/**
 * Questa funzione visualizza il menu iniziale del programma.
 * Viene mostrato all'utente un menu con tutte le funzionalita' possibili del programma.
 * Una volta effettuata una scelta tra le disponibili, verranno chiamate altre funzioni che si occupeanno di quella determinata scelta.
 */
void menu()
{     // Codice funzione menù: C01

	int s;			///Variabile che contiene la scelta inserita,relativa a quale funzionalita' si vuole effettuare.
	int t=0;		///Variabile che conterrà 1 se la scelta inserita sara' un numero, 0 altrimenti.

	do
	{

		int numero_passeggeri=numero_di_passeggeri();
		passeggero persona[numero_passeggeri+1];   /// Dichiaro un vettore di struct di tipo passeggero composto dal numero dei passeggeri piu' 1
	 	 											///per permettermi successivamente di inserire un nuovo passeggero.

		int numero_voli=numero_di_voli();
		volo voli[numero_voli+1];					/// Dichiaro un vettore di struct di tipo volo composto dal numero dei voli piu' 1
													///per permettermi successivamente di inserire un nuovo volo

		int numero_prenotazioni=numero_delle_prenotazioni();
		prenotazione prenotazione_persona[numero_prenotazioni+1]; /// Dichiaro un vettore di struct di tipo prenotazione composto dal numero delle prenotazioni
																///piu' 1 per permettermi di inserire successivamente una nuova prenotazione.

		caricamento_persone(persona,numero_passeggeri);
		caricamento_voli(voli,numero_voli);
		caricamento_prenotazioni(prenotazione_persona,numero_prenotazioni);


		printf ("\n----------AEROPORTO DI BARI----------\n");

		printf ("\n 1.INSERIRE NUOVO UTENTE");
		printf ("\n 2.MODIFICA INFORMAZIONI DEGLI UTENTI ESISTENTI");
		printf ("\n 3.CANCELLAZIONE DEGLI UTENTI ESISTENTI ");

		printf ("\n 4.INSERIRE UN NUOVO VOLO");
		printf ("\n 5.MODIFICA INFORMAZIONI DEI VOLI ESISTENTI");
		printf ("\n 6.CANCELLAZIONE DEI VOLI ESISTENTI");

		printf ("\n 7.INSERIRE UNA NUOVA PRENOTAZIONE");
		printf ("\n 8.MODIFICA INFORMAZIONI DELLE PRENOTAZIONI ESISTENTI");
		printf ("\n 9.CANCELLAZIONE DELLE PRENOTAZIONI ESISTENTI");

		printf ("\n 10.CHECK-IN PASSEGGERO");
		printf ("\n 11.RICERCA PASSEGGERI");
		printf ("\n 12.RICERCA VOLI");
		printf ("\n 13.RICERCA PRENOTAZIONI");

		printf ("\n 14.VISUALIZZA PASSEGGERI");
		printf ("\n 15.VISUALIZZA VOLI");
		printf ("\n 16.VISUALIZZA PRENOTAZIONI");

		printf ("\n 17 .ESCI DAL PROGRAMMA");
		printf("\n Scelta: ");

		do
		{
			s=acquisisci_scelta(&t);
		}while(t==0);


		switch(s)
		{
		case 1:
			inserisci_nuovo_utente(persona,numero_passeggeri);
			salvataggio_su_file_passeggeri(persona,numero_passeggeri);
			break;

		case 2:
			modifica_utente(persona,numero_passeggeri);
			salvataggio_su_file_passeggeri(persona,numero_passeggeri-1); ///decremento 1 al numero dei passeggeri in modo da non considerare la struct vuota
																		///nel caso di modifica o eliminazione.
			break ;

		case 3:
			elimina_utente(persona,numero_passeggeri);
			salvataggio_su_file_passeggeri(persona,numero_passeggeri-1);
			break;

		case 4:
			inserisci_nuovo_volo(voli,numero_voli);
			salvataggio_su_file_voli(voli,numero_voli);
			break;

		case 5:
			modifica_volo(voli,numero_voli);
			salvataggio_su_file_voli(voli,numero_voli-1); ///decremento 1 al numero di voli in modo da non considerare la struct vuota
															///nel caso di modifica o eliminazione.
			break;

		case 6:
			elimina_volo(voli,numero_voli);
			salvataggio_su_file_voli(voli,numero_voli-1);
			break;

		case 7:
			inserisci_nuova_prenotazione(prenotazione_persona,numero_prenotazioni,persona,numero_passeggeri,voli,numero_voli);
			salvataggio_su_file_prenotazioni(prenotazione_persona,numero_prenotazioni);
			break;

		case 8:
			modifica_prenotazione(prenotazione_persona,numero_prenotazioni,persona,numero_passeggeri,voli,numero_voli);
			salvataggio_su_file_prenotazioni(prenotazione_persona,numero_prenotazioni-1); ///decremento 1 al numero delle prenotazioni in modo da non considerare la struct vuota
																							///nel caso di modifica o eliminazione.
			break;

		case 9:
			elimina_prenotazione(prenotazione_persona,numero_prenotazioni);
			salvataggio_su_file_prenotazioni(prenotazione_persona,numero_prenotazioni-1);
			break;

		case 10:
			check_in(prenotazione_persona,numero_prenotazioni,persona,numero_passeggeri,voli,numero_voli);
			salvataggio_su_file_prenotazioni(prenotazione_persona,numero_prenotazioni-1);
			break;

		case 11:
			ricerca_passeggeri(persona,numero_passeggeri);
			break;

		case 12:
			ricerca_voli(voli,numero_voli);
			break;

		case 13:
			ricerca_prenotazioni(prenotazione_persona,numero_prenotazioni,persona,numero_passeggeri,voli,numero_voli);
			break;

		case 14:
			visualizza_passeggeri(persona,numero_passeggeri);
			break;

		case 15:
			visualizza_voli(voli,numero_voli);
			break;

		case 16:
			visualizza_prenotazioni(prenotazione_persona,numero_prenotazioni);
			break;

		case 17:
			exit(0);
			break;
		default:

			printf("\n Valore inserito non corretto \n");
		}

	}while(s!=17);   /// Se l'utente non inserisce una tra le scelte presenti nel menu', dovra' inserire una nuova scelta.
	 	 	 	 	 	/// Inoltre se inserisce 17, termina il programma.



}

