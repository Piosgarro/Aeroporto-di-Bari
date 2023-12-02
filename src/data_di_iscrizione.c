/**
* @file data_di_iscrizione.c
*
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data.h"
#include "data_di_iscrizione.h"

/**
 *Questa funzione mi permette di riuscire a risalire alla data del sistema, attraverso la struct tm presente nella libreria time.h.
 * @post la funzione dovrà restituire la data del sistema, modificando i vari parametri.
 */
 void acquisisci_data(data* data_iscrizione)
 {
   time_t rawtime;
   struct tm *info;

   time( &rawtime );

   info = localtime( &rawtime );

   data_iscrizione->giorno=info->tm_mday;
   data_iscrizione->mese=info->tm_mon+1;
   data_iscrizione->anno=info->tm_year+1900;
}
