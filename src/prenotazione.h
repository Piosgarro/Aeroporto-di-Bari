/**
* @file passeggero.h
*	Libreria che contiene tutte le funzioni relative alle prenotazioni
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/
#ifndef PRENOTAZIONE_H_
#define PRENOTAZIONE_H_
#include "costanti.h"
#include "passeggero.h"
#include "volo.h"

typedef struct{
	int id_prenotazione;
	int id_passeggero;
	char id_volo[CODICE_VOLO];
	int check_in;
}prenotazione;

/**
 * Questa funzione calcola il numero delle prenotazioni.
 * @return il numero delle prenotazioni.
 */
int numero_delle_prenotazioni();

/**
 * Questa funzione permette di caricare i dati sull'array di struct.
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_prenotazioni numero delle  prenotazioni
 * @return corretto cioe' 1 se la funzione ha caricato i dati, 0 altrimenti.
 */
int caricamento_prenotazioni(prenotazione prenotazione_persona[],int numero_prenotazioni);

/**
 * Questa funzione permette di salvare i dati sul file prenotazioni.
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_prenotazioni numero delle  prenotazioni
 * @return corretto cioe' 1 se la funzione ha salvato i dati, 0 altrimenti.
 */
int salvataggio_su_file_prenotazioni(prenotazione prenotazione_persona[],int numero_prenotazioni);

/**
* Questa funzione permette di visualizzare tutte le prenotazioni presenti nel progetto.
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_prenotazioni numero delle  prenotazioni
 * @return 1.
 */
int visualizza_prenotazioni(prenotazione prenotazione_persona[],int numero_prenotazioni);

/**
 * Questa funzione permette di visualizzare una determinata prenotazione.
* @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_prenotazioni numero delle  prenotazioni
 * @param indice_prenotazione l'indice della prenotazione che si vuole visualizzare
 * @return 1.
 */
int visualizza_una_prenotazione(prenotazione prenotazione_persona[],int numero_prenotazioni, int indice_prenotazione);

/**
 * Questa funzione controlla se la prenotazione inserita dall'utente di un determinato passeggero, e' stata gia' effettuata
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_prenotazioni numero delle  prenotazioni
 * @param persona passeggero di cui si vogliono controllare le prenotazioni
 * @param indice_utente l'indice del passeggero per cui si vogliono controllare le prenotazioni
 * @param volo_inserito il volo per cui si vuole effettuare una prenotazione
 * @return 1 se la prenotazione di quel determinato passeggero non e' stata ancora effettuata, 0 altrimenti.
 */
int controllo_prenotazione(prenotazione prenotazione_persona[],int numero_prenotazioni,
							passeggero persona[], int indice_utente, volo volo_inserito);

/**
 * Questa funzione permette di inserire una nuova prenotazione.
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_prenotazioni numero delle  prenotazioni
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param numero_passeggeri numero dei passeggeri
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @return 1.
 */
int inserisci_nuova_prenotazione(prenotazione prenotazione_persona[],int numero_prenotazioni,passeggero persona[],
									int numero_passeggeri,volo voli[], int numero_di_voli);

/**
 * Questa funzione permette di modificare i dati di una prenotazione.
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_prenotazioni numero delle  prenotazioni
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param numero_passeggeri numero dei passeggeri
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @return 1.
 */
int modifica_prenotazione(prenotazione prenotazione_persona[],int numero_prenotazioni,passeggero persona[],
									int numero_passeggeri,volo voli[], int numero_di_voli);

/**
 * Questa funzione permette di eliminare una prenotazione.
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_prenotazioni numero delle  prenotazioni
 * @return 1.
 */
int elimina_prenotazione(prenotazione prenotazione_persona[],int numero_prenotazioni);

/**
 * Questa funzione permette di controllore se l'imbarco per un determinato volo e' concluso.
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_prenotazioni numero delle  prenotazioni
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @param n conterra' l'indice della prenotazione di cui si vuole effettuare il check-in
 * @return 1.
 */
int imbarco(prenotazione prenotazione_persona[],int numero_prenotazioni,volo voli[],int numero_di_voli,int n);

/**
 * Questa funzione permette di effettuare il check-in di una prenotazione.
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_di_prenotazioni numero delle  prenotazioni
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param numero_di_passeggeri numero dei passeggeri
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @return 1.
 */
int check_in(prenotazione prenotazione_persona[],int numero_di_prenotazioni,passeggero persona[],
									int numero_di_passeggeri,volo voli[], int numero_di_voli);

/**
 * Questa funzione permette di ricercare un determinato passeggero tra tutti i passeggeri che hanno effettuato almeno una prenotazione.
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_di_prenotazioni numero delle  prenotazioni
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param indice_utente indice del passeggero inserito dall'utente per cui si vuole effettuare una ricerca sulle sue prenotazioni
 * @return 1 se il passeggero inserito dall'utente ha effettuato almeno una prenotazione, 0 altrimenti.
 */
int ricerca_per_utente(prenotazione prenotazione_persona[],int numero_di_prenotazioni,passeggero persona[],int indice_utente);

/**
 * Questa funzione permette di ricercare un determinato passeggero tra tutti i passeggeri che hanno effettuato almeno una prenotazione.
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param id_volo volo inserito dall'utente per cui si vuole effettuare una ricerca sulle sue prenotazioni
 * @param numero_di_prenotazioni numero delle  prenotazioni
 * @return 1 se sul volo inserito dall'utente e' stata effettuata almeno una prenotazione, 0 altrimenti.
 */
int ricerca_per_volo(prenotazione prenotazione_persona[],char id_volo[],int numero_di_prenotazioni);

/**
 * Questa funzione permette di ricercare una prenotazione secondo un determinato criterio.
 * @param prenotazione_persona array di struct che conterra' tutti i dati delle prenotazioni
 * @param numero_di_prenotazioni numero delle  prenotazioni
 * @param persona array di struct che conterra' tutti i dati dei passeggeri
 * @param numero_passeggeri numero dei passeggeri
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @return 1.
 */
int ricerca_prenotazioni(prenotazione prenotazione_persona[],int numero_di_prenotazioni,passeggero persona[],
		int numero_passeggeri,volo voli[],int numero_di_voli);


#endif /* PRENOTAZIONE_H_ */
