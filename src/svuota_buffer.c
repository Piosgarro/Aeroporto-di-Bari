/**
* @file svuota_buffer.c
*
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/
#include <stdio.h>
#include <stdlib.h>
#include "svuota_buffer.h"

/**
 * Questa funzione viene utilizzata per svuotare il buffer in modo da migliorare la visibilità del programma ed evitare alcuni errori.
 */
void svuota_buffer()
{
	char c;
	while(( c = getchar())!= '\n'  && c!=EOF);
}

