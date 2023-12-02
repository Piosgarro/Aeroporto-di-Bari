/**
* @file controlli_passeggeri.h
*	Libreria che contiene tutte le funzioni relative ai controlli sui passeggeri
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/

#ifndef CONTROLLI_PASSEGGERI_H_
#define CONTROLLI_PASSEGGERI_H_
#include "data.h"




/**
 * Questa funzione permette di controllare il nome o il cognome inserito dall'utente.
 * @param stringa vettore di char che contiene il nome o il cognome inserito.
 * @return 1  se il nome o il cognome inserito e' corretto, 0 altrimenti.
 */
int controllo_Stringa_passeggero(char stringa[]);

/**
 * Questa funzione permette di controllare il codice del passaporto inserito .
 * @param passaporto vettore di char che contiene il codice del passaporto inserito.
 * @return 1  se il codice del passaporto inserito e' corretto, 0 altrimenti.
 *
 */
int controllo_Passaporto(char passaporto[]);

/**
 * Questa funzione permette di controllare il giorno di nascita inserito dall'utente.
 * @param giorno1 vettore di char che contiene il giorno inserito dall'utente.
 * @param giorno_data_di_nascita variabile che conterra' il giorno di nascita convertito in intero.
 * @return 1  se il giorno di nascita inserito e' corretto, 0 altrimenti.
 */
int controllo_giorno_data_di_nascita(char giorno1[],int* giorno_data_di_nascita);

/**
 * Questa funzione permette di controllare il mese di nascita inserito dall'utente.
 * @param mese1 vettore di char che contiene il mese inserito dall'utente.
 * @param mese_data_di_nascita variabile che contiene il mese di nascita convertito in intero.
 * @return 1  se il mese di nascita inserito e' corretto, 0 altrimenti.
 */
int controllo_mese_data_di_nascita(char mese1[],int* mese_data_di_nascita);

/**
 * Questa funzione permette di controllare l'anno di nascita inserito dall'utente.
 * @param anno1 vettore di char che contiene l'anno inserito dall'utente.
 * @param anno_data_di_nascita variabile che contiene l'anno di nascita convertito in intero.
 * @return 1  se l'anno  di nascita inserito e' corretto, 0 altrimenti.
 */
int controllo_anno_data_di_nascita(char anno1[],int* anno_data_di_nascita);

/**
 * Questa funzione permette di controllare se la data di nascita e' realistica.
 * @param data_nascita vettore di struct di tipo data.
 * @return 1 se la data di nascita è realistica, 0 altrimenti.
 */
int	controllo_generale_sulla_data(data data_nascita);



#endif /* CONTROLLI_PASSEGGERI_H_ */
