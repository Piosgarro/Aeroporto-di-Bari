/**
* @file costanti.h
* Libreria che contiene tutte le costanti del programma
*
* @authors Sgarro Vincenzo Pio, Sokoli Afrim
*/

#ifndef COSTANTI_H_
#define COSTANTI_H_
/**
 * Massima lunghezza del nome(19)
 */
#define LUNGHEZZA_NOME 20
/**
 * Massima lunghezza del cognome(19)
 */
#define LUNGHEZZA_COGNOME 20
/**
 * Numero di caratteri necessari per un passaporto valido
 */
#define N_PASSAPORTO 9

/**
 * Massima lunghezza dei caratteri per contenere ore e minuti
 */
#define MAX_LUNGHEZZA_ORA_E_MINUTI 2
/**
 * Minima lunghezza dei caratteri per contenere ore e minuti
 */
#define MIN_LUNGHEZZA_ORA_E_MINUTI 1
/**
 * Minima ora presente nel giorno
 */
#define MIN_ORA 0
/**
 * Massima ora presente nel giorno
 */
#define	MAX_ORA 23
/**
 * Il minimo dei minuti presenti in un'ora
 */
#define MIN_MINUTI 0
/**
 * Il massimo dei minuti presenti in un'ora
 */
#define	MAX_MINUTI 59
/**
 * Massima lunghezza dei caratteri per contenere un giorno
 *
 */
#define MAX_LUNGHEZZA_GIORNO 2
/**
 * Minima lunghezza dei caratteri per contenere ore e minuti
 *
 */
#define MIN_LUNGHEZZA_GIORNO 1
/**
 * Massimo giorno prensente un mese
 */
#define MAX_GIORNO 31
/**
 * Minimo giorno prensente un mese
 */
#define MIN_GIORNO 01
/**
 * Massima lunghezza dei caratteri per contenere un mese
 *
 */
#define MAX_LUNGHEZZA_MESE 2
/**
 *Minima lunghezza dei caratteri per contenere un mese
 *
 */
#define MIN_LUNGHEZZA_MESE 1
/**
 * Massimo mese presente in un anno
 */
#define MAX_MESE 12
/**
 * Minimo mese presente in un anno
 */
#define MIN_MESE 01

/**
 * Lunghezza caratteri per contenere un anno
 */
#define LUNGHEZZA_ANNO 4
/**
 * Anno più vecchio di nascita per cui e' possibile iscriversi al sistema
 */
#define MAX_ANNO 1960
/**
 * Ultimo anno di nascita per cui e' possibile iscriversi al sistema
 */
#define MIN_ANNO 2001
/**
 * Numero di caratteri necessari per un codice volo valido +1
 */
#define CODICE_VOLO 7 //2 LETTERE E 4 NUMERI
/**
 * Massima lunghezza della compagnia(29)
 */
#define LUNGHEZZA_COMPAGNIA 30
/**
 * Massima lunghezza destinazione(29)
 */
#define LUNGHEZZA_DESTINAZIONE 30
/**
 * Massima lunghezza tipo di aereo(19)
 */
#define LUNGHEZZA_TIPO 20
/**
 *Lunghezza dei caratteri per contenere i posti di un volo
 */
#define LUNGHEZZA_POSTI 3
/**
 * Numero massimo di posti che puo' avere un volo
 */
#define MAX_POSTI 950
/**
 * Numero minimo di posti che puo' avere un volo
 */
#define MIN_POSTI 100
/**
 * Costante usata quando viene inserita una scelta nei vari menu' del programma
 */
#define LUNGHEZZA_SCELTA 5

/**
 * costante utilizzata nel caricamento e nel salvataggio dei dati
 */
#define ERRORE 0;
/**
 * costante utilizzata nel caricamento e nel salvataggio dei dati
 */
#define CORRETTO 1;
/**
 * costante utilizzata per contenere le prenotazioni di un determinato passeggero
 */
#define NUMERO_PRENOTAZIONI 10
#endif /* COSTANTI_H_ */
