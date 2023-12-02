/**
* @file passeggero.h
*	Libreria che contiene tutte le funzioni relative ai passeggeri
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/


#ifndef PASSEGGERO_H_
#define PASSEGGERO_H_
#include "data.h"
#include "costanti.h"

typedef struct{
	int id_passeggero;
	char nome[LUNGHEZZA_NOME];
	char cognome[LUNGHEZZA_COGNOME] ;
	data data_di_nascita;
	data data_di_iscrizione;
	char passaporto[N_PASSAPORTO];
}passeggero;

/**
 * Questa funzione calcola il numero dei passeggeri.
 * @return il numero dei passeggeri.
 */
int numero_di_passeggeri();

/**
 * Questa funzione permette di caricare i dati sull'array di struct.
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param numero_passeggeri numero dei passeggeri
 * @return corretto cioe' 1 se la funzione ha caricato i dati, 0 altrimenti.
 */
int caricamento_persone(passeggero persona[],int numero_passeggeri);

/**
 * Questa funzione permette di salvare i dati sul file passeggeri.
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param numero_passeggeri numero dei passeggeri
 * @return corretto cioe' 1 se la funzione ha salvato i dati, 0 altrimenti.
 */
int salvataggio_su_file_passeggeri(passeggero persona[],int numero_passeggeri);

/**
 * Questa funzione permette di visualizzare tutti i passeggeri presenti nel progetto.
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param numero_passeggeri numero dei passeggeri
 * @return 1.
 */
int visualizza_passeggeri(passeggero persona[],int numero_passeggeri);

/**
 * Questa funzione permette di visualizzare un determinato passeggero.
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param numero_passeggeri numero dei passeggeri
 * @param indice_passeggero l'indice del passeggero che si vuole visualizzare
 * @return 1.
 */
int visualizza_un_passeggero(passeggero persona[],int numero_passeggeri, int indice_passeggero);

/**
 * Questa funzione permette di inserire un nuovo passeggero.
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param numero_passeggeri numero dei passeggeri
 * @return 1.
 */
int inserisci_nuovo_utente(passeggero persona[],int numero_passeggeri);

/**
 * Questa funzione permette di modificare i dati dei passeggeri.
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param numero_passeggeri numero dei passeggeri
 * @return 1.
 */
int modifica_utente(passeggero persona[],int numero_passeggeri);

/**
 * Questa funzione permette di eliminare un passeggero.
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param numero_passeggeri numero dei passeggeri
 * @return 1.
 */
int elimina_utente(passeggero persona[], int numero_passeggeri);

/**
 * Questa funzione permette di ricercare un determinato nome tra tutti i passeggeri.
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param stringa nome inserito dall'utente per cui si vuole effettuare una ricerca
 * @param numero_dei_passeggeri numero dei passeggeri
 * @return 1 se il nome inserito dall'utente e' presente nei passeggeri, 0 altrimenti.
 */
int ricerca_per_nome(passeggero persona[],char stringa[], int numero_dei_passeggeri);

/**
 * Questa funzione permette di ricercare un determinato cognome tra tutti i passeggeri.
 * @param persona  array di struct che conterra' tutti i dati dei passeggeri.
 * @param stringa cognome inserito dall'utente per cui si vuole effettuare una ricerca
 * @param numero_dei_passeggeri numero dei passeggeri
 * @return 1 se il cognome inserito dall'utente e' presente nei passeggeri, 0 altrimenti.
 */
int ricerca_per_cognome(passeggero persona[],char stringa[], int numero_dei_passeggeri);

/**
 * Questa funzione permette di ricercare una determinata data di nascita tra tutti i passeggeri.
 * @param persona array di struct che conterra' tutti i dati dei passeggeri.
 * @param data_ricercata data di nascita inserita dall'utente per cui si vuole effettuare una ricerca
 * @param numero_dei_passeggeri numero dei passeggeri
 * @return 1 se la data di nascita inserita dall'utente e' presente nei passeggeri, 0 altrimenti.
 */
int ricerca_per_data_di_nascita(passeggero persona[],data data_ricercata,int numero_dei_passeggeri);

/**
 * Questa funzione permette di ricercare dei passeggeri secondo un determinato criterio.
 * @param persona array di struct che conterra' tutti i dati dei passeggeri.
 * @param numero_di_passeggeri numero dei passeggeri.
 * @return 1.
 */
int ricerca_passeggeri(passeggero persona[], int numero_di_passeggeri);





#endif /* PASSEGGERO_H_ */
