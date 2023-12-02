/**
* @file menu.h
* Libreria che contiene le funzioni principali del programma
*
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/

#ifndef MENU_H_
#define MENU_H_
#include "passeggero.h"

/**
 * Questa funzione controlla la scelta inserita dall'utente.
 * @param t utilizzato come valore sentinella per vedere se la scelta inserita e' corretta o meno
 * @return la scelta inserita
 */

int acquisisci_scelta(int* t);

/**
 * Questa funzione visualizza il menu iniziale del programma.
 */
void menu();

#endif /* MENU_H_ */
