/**
* @file controlli_voli.h
*	Libreria che contiene tutte le funzioni relative ai controlli sui voli
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/

#ifndef CONTROLLI_VOLI_H_
#define CONTROLLI_VOLI_H_
#include "data.h"
#include "ora.h"
#include "volo.h"




/**
 * Questa funzione permette di controllare il codice di volo inserito .
 * @param id_volo vettore di char che contiene il codice di volo inserito.
 * @return 1  se il codice di volo inserito e' corretto, 0 altrimenti.
 */
int controllo_id_volo(char id_volo[]);

/**
 * Questa funzione permette di controllare se il codice di volo inserito esiste gia'.
 * @param id_volo vetttore di char che  contiene il codice di volo inserito.
 * @param numero_voli Il numero  di voli.
 * @param voli vettore di struct di tipo volo.
 * @return 1 se il codice volo inserito non e' esistente,0 altrimenti.
 */
int id_volo_inserito(char id_volo[], int numero_voli, volo voli[]);

/**
 * Questa funzione permette di controllare il nome della compagnia o la destinazione inseriti dall'utente.
 * @param stringa2 vettore di char che contiene il nome della compagnia o la destinazione inseriti.
 * @return 1  se il nome compagnia o destinazione  inserita e' corretta, 0 altrimenti.
 */
int controllo_Stringa2_volo(char stringa2[]);

/**
 * Questa funzione permette di controllare la tipologia di aereo inserita dall'utente.
 * @param stringa vettore di char che contiene la  tipologia  di aereo inserita.
 * @return 1 se la tipologia  di aereo inserita e' corretta, 0 altrimenti.
 */
int controllo_Stringa_volo(char stringa[]);

/**
 * Questa funzione permette di controllare il numero dei posti inseriti dall'utente.
 * @param posti1 vettore di char che contiene il giorno inserito dall'utente.
 * @param posti	variabile che conterra' il numero dei posti convertito in intero.
 * @return 1 se il numero dei posti inserito  e' corretto,0 altrimenti.
 */
int controllo_posti(char posti1[],int* posti);

/**
 * Questa funzione permette di controllare il giorno di volo inserito dall'utente.
 * @param giorno1 vettore di char che contiene il giorno inserito dall'utente.
 * @param giorno_di_volo variabile che conterra' il giorno di volo convertito in intero.
 * @return 1  se il giorno di volo inserito e' corretto, 0 altrimenti.
 */
int controllo_giorno_di_volo(char giorno1[],int* giorno_di_volo);
/**
 * Questa funzione permette di controllare il mese di volo inserito dall'utente.
 * @param mese1 vettore di char che contiene il mese inserito dall'utente.
 * @param mese_di_volo variabile che conterra' il mese di volo convertito in intero.
 * @return 1  se il mese di volo inserito e' corretto, 0 altrimenti.
 */
int controllo_mese_di_volo(char mese1[],int* mese_di_volo);
/**
 * Questa funzione permette di controllare l'anno di volo inserito dall'utente.
 * @param anno1 vettore di char che contiene l'anno inserito dall'utente.
 * @param anno_di_volo variabile che conterra' l'anno di volo convertito in intero.
 * @return 1  se l'anno  di volo inserito e' corretto, 0 altrimenti.
 */
int controllo_anno_di_volo(char anno1[],int* anno_di_volo);
/**
 * Questa funzione permette di controllare se la data di volo e' realistica.
 * @param giorno_volo vettore di struct di tipo data.
 * @return 1 se la data di volo è realistica, 0 altrimenti.
 */
int data_volo_corretta_1(data giorno_volo);

/**
 *Questa funzione permette  di controllare  se la data di volo inserita e' maggiore o uguale della data del sistema.
 * @param giorno_volo vettore di struct che contiene la data di volo inserita dall'utente.
 * @param giorno_sistema contiene il giorno del  sistema.
 * @param mese_sistema contiene il mese del sistema.
 * @param anno_sistema contiene l'anno del sistema.
 * @return 1 se la data di volo e' maggiore o uguale della data del sistema, 0 altrimenti.
 */
int data_volo_corretta_2(data giorno_volo,int giorno_sistema,int mese_sistema,int anno_sistema);

/**
 * Questa funzione permette di controllare l'ora o i minuti (sia di partenza che di arrivo) inseriti dall'utente.
 * @param ora_e_minuti	vettore di char che contiene l'ora o i minuti inseriti.
 * @param ora_e_minuti2 variabile  che conterra' l'ora o i minuti convertiti in intero.
 * @return 1  se l'ora o i minuti siano inseriti correttamente, 0 altrimenti.
 */
int controllo_ora_e_minuti(char ora_e_minuti[], int* ora_e_minuti2);

/**
 * Questa funzione permette  di controllare l'ora di partenza inserita dall'utente.
 * @param ora_partenza	vettore di struct che contiene l'ora di partenza inserita dall'utente.
 * @return 1 se l'ora di partenza inserita e' corretta,0 altrimenti.
 */
int ora_di_partenza_corretta(ora ora_partenza);

/**
 * Questa funzione permette  di controllare l'ora di arrivo inserita dall'utente.
 * @param ora_partenza vettore di struct che contiene l'ora di partenza inserita dall'utente.
 * @param ora_arrivo vettore di struct che contiene l'ora di arrivo inserita dall'utente.
 * @return  1 se l'ora di arrivo inserita e' corretta,0 altrimenti.
 */
int ora_di_arrivo_corretta(ora ora_partenza,ora ora_arrivo);

/**
 * Questa funzione permette di calcolare la durata di un volo.
 * @param ora_partenza  vettore di struct che deve contenere l'ora di partenza.
 * @param ora_arrivo  vettore di struct che deve contenere l'ora di arrivo.
 * @return la durata.
 */
int calcola_durata(ora ora_partenza,ora ora_arrivo);
#endif /* CONTROLLI_VOLI_H_ */
