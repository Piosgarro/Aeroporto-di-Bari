/**
* @file volo.h
*	Libreria che contiene tutte le funzioni relative ai voli
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/

#ifndef VOLO_H_
#define VOLO_H_
#include "ora.h"
#include "data.h"
#include "costanti.h"


typedef struct{
	char id_volo[CODICE_VOLO];
	char nome_compagnia[LUNGHEZZA_COMPAGNIA];
	char destinazione[LUNGHEZZA_DESTINAZIONE];
	char tipologia_di_aereo[LUNGHEZZA_TIPO];
	int posti;
	data giorno_di_volo;
	ora ora_di_partenza;
	ora  ora_di_arrivo;
	int durata;
}volo;

/**
 * Questa funzione calcola il numero dei voli.
 * @return il numero dei voli.
 */
int numero_di_voli();

/**
 * Questa funzione permette di caricare i dati sull'array di struct.
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @return corretto cioe' 1 se la funzione ha caricato i dati, 0 altrimenti.
 */
int caricamento_voli(volo voli[],int numero_di_voli);

/**
 * Questa funzione permette di salvare i dati sul file voli.
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @return corretto cioe' 1 se la funzione ha salvato i dati, 0 altrimenti.
 */
int salvataggio_su_file_voli(volo voli[],int numero_di_voli);

/**
 * Questa funzione permette di visualizzare tutti i voli presenti nel progetto.
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @return 1.
 */
int visualizza_voli(volo voli[],int numero_di_voli);

/**
 * Questa funzione permette di visualizzare un determinato volo.
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @param indice_volo l'indice del volo che si vuole visualizzare
 * @return 1.
 */
int visualizza_un_volo(volo voli[],int numero_di_voli,int indice_volo);

/**
 * Questa funzione permette di inserire un nuovo volo.
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @return 1.
 */
int inserisci_nuovo_volo(volo voli[],int numero_di_voli);

/**
 * Questa funzione permette di modificare i dati dei voli.
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @return 1.
 */
int modifica_volo(volo voli[],int numero_di_voli);

/**
 * Questa funzione permette di eliminare un volo.
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param numero_di_voli numero dei voli
 * @return 1.
 */
int elimina_volo(volo voli[],int numero_di_voli);

/**
 * Questa funzione permette di ricercare una determinata compagnia tra tutti i voli.
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param stringa nome compagnia inserito dall'utente per cui si vuole effettuare una ricerca
 * @param numero_di_voli numero dei voli
 * @return 1 se la compagnia inserita dall'utente e' presente nei voli, 0 altrimenti.
 */
int ricerca_per_compagnia(volo voli[],char stringa[],int numero_di_voli);

/**
 * Questa funzione permette di ricercare una determinata destinazione tra tutti i voli.
 * @param voli array di struct che conterra' tutti i dati dei voli
 * @param stringa destinazione inserita dall'utente per cui si vuole effettuare una ricerca
 * @param numero_di_voli numero dei voli
 * @return 1 se la destinazione inserita dall'utente e' presente nei voli, 0 altrimenti.
 */
int ricerca_per_destinazione(volo voli[],char stringa[],int numero_di_voli);

/**
 * Questa funzione permette di ricercare una determinato giorno di volo tra tutti i voli.
 * @param voli array di struct che conterra' tutti i dati dei voli.
 * @param data_ricercata giorno di volo inserito dall'utente per cui si vuole effettuare una ricerca
 * @param numero_di_voli numero dei voli
 * @return 1 se il giorno di volo inserito dall'utente e' presente nei voli, 0 altrimenti.
 */
int ricerca_per_giorno_volo(volo voli[],data data_ricercata,int numero_di_voli);

/**
 * Questa funzione permette di ricercare dei voli secondo un determinato criterio.
 * @param voli array di struct che conterra' tutti i dati dei voli.
 * @param numero_di_voli numero dei voli.
 * @return 1.
 */
int ricerca_voli(volo voli[],int numero_di_voli);

#endif /* VOLO_H_ */
