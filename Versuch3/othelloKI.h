/**
 * Praktikum Informatik 1 
 * 
 *
 * @file othelloKI.h
 *
 * Stellt eine KI fuer das Spiel Othello zur Verfuegung
 */

#ifndef OTHELLOKI_H_
#define OTHELLOKI_H_

#include "config.h"

/**
 * Eine Funktion, die eine KI fuer das Spiel Othello zur Verfuegung stellt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return True wenn der Zug ausgefuehrt wurde. False wenn kein Zug moeglich ist.
 */
bool computerZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler);

#endif /* OTHELLOKI_H_ */
