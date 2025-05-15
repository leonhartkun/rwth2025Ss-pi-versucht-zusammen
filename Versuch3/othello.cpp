/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 * mark佳坤
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
* @mainpage Othello
*
* Dokumentation des Spiels Othello im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "othelloKI.h"

//definition GROSSE_X und GROSSE_Y
#define GROESSE_X 8
#define GROESSE_Y 8

/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{

    // Hier erfolgt jetzt Ihre Implementierung ...
	if (0<=posX&&posX<GROESSE_X && 0<=posY&&posY<GROESSE_Y)
		{
			return true;
		}
    return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return true, wenn zug gueltig sind, sonst false
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Hier erfolgt jetzt Ihre Implementierung ...
        	if (i == 0 && j == 0){
        		continue;
        	}

        	int y = posY+j;
        	int x = posX+i;

        	if (0<=x<GROESSE_X && 0<=y<GROESSE_Y && spielfeld[y][x] == gegner)
        	{
        		x += i;
        		y += j;

        		while (0<=x+i&&x+i<GROESSE_X && 0<=y+j&&y+j<GROESSE_Y)
        		{
        			if (spielfeld[y][x] == 0)
        			{
        				break;
        			}
        			if(spielfeld[y][x] == aktuellerSpieler)
        			{
        			    return true;
        			}

        			x+=i;
        			y+=j;
        		}
        	}
        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *        执行玩家的一步落子，并翻转所有被夹住的对方棋子
 *
 * @param spielfeld Das aktuelle Spielfeld      当前棋盘
 * @param aktuellerSpieler Der aktuelle Spieler 当前玩家（1=黑, 2=白）
 * @param posX Die aktuelle Spalte              落子列
 * @param posY Die aktuelle Zeile               落子行
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    // Setze eigenen Stein auf das Feld
    spielfeld[posY][posX] = aktuellerSpieler;

    // Alle 8 Richtungen überprüfen
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            if (i == 0 && j == 0)
                continue; // nicht in die eigene Richtung schauen

            int x = posX + i;
            int y = posY + j;
            bool richtungGueltig = false;

            // Zuerst prüfen, ob direkt daneben ein gegnerischer Stein liegt
            if (x >= 0 && x < GROESSE_X && y >= 0 && y < GROESSE_Y && spielfeld[y][x] == gegner)
            {
                // In der Richtung weitergehen
                x += i;
                y += j;

                while (x >= 0 && x < GROESSE_X && y >= 0 && y < GROESSE_Y)
                {
                    if (spielfeld[y][x] == 0)
                    {
                        break; // Leeres Feld -> keine Umwandlung möglich
                    }
                    if (spielfeld[y][x] == aktuellerSpieler)
                    {
                        richtungGueltig = true;
                        break; // Richtung gültig zum Umwandeln
                    }
                    x += i;
                    y += j;
                }
            }

            // Wenn Richtung gültig, dann alle gegnerischen Steine zurückgehen und umwandeln
            if (richtungGueltig)
            {
                x = posX + i;
                y = posY + j;

                while (spielfeld[y][x] == gegner)
                {
                    spielfeld[y][x] = aktuellerSpieler;
                    x += i;
                    y += j;
                }
            }
        }
    }
}


/**
 * @brief Gibt die Anzahl aller moeglichen Zuege fuer den aktuellen Spieler zurueck
 *        返回当前玩家所有合法落子数量
 *
 * @param spielfeld Das aktuelle Spielfeld 当前棋盘
 * @param aktuellerSpieler Der Spieler, fuer den die Zuege geprueft werden 当前玩家（1或2）
 * @return Anzahl gueltiger Zuege 所有可落子的数量
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    int anzahl = 0; // 计数器

    for (int y = 0; y < GROESSE_Y; y++)
    {
        for (int x = 0; x < GROESSE_X; x++)
        {
            if (zugGueltig(spielfeld, aktuellerSpieler, x, y))
            {
                anzahl++; // 找到一个合法位置
            }
        }
    }

    return anzahl;
}

/**
 *
 * @param spielfeld Das aktuelle Spielfeld 当前棋盘
 * @param aktuellerSpieler Der Spieler, fuer den die Zuege geprueft werden 当前玩家（1或2）
 * @return true, wenn der menschlicher zug gueltig sind, sonst false
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl;

    return true;
}

/**
 *  um die Spiele zu laufen
 *  computer 2 computer or computer 2 mensch
 *  运行程序 电脑对电脑或者人和电脑下
 *
 * @param spielerTyp MENSCH oder COMPUTER
 */
void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);
    std::cout<<spielerTyp[0]<<" "<<spielerTyp[1]<<std::endl;

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    while (true) {
        computerZug(spielfeld,aktuellerSpieler);
        aktuellerSpieler = 3-aktuellerSpieler;
        if (spielerTyp[aktuellerSpieler-1] == MENSCH) {
            menschlicherZug(spielfeld, aktuellerSpieler);
        }
        zeigeSpielfeld(spielfeld);
        if (moeglicheZuege(spielfeld,aktuellerSpieler)==0)
        {
            break;
        }

    }
    
    switch (gewinner(spielfeld))
    {
        // Hier erfolgt jetzt Ihre Implementierung ...
        case 1:
            std::cout<<"1 was win!"<<std::endl;
            break;
        case 2:
            std::cout<<"2 was win!"<<std::endl;
    }
}

/**
 * main function: the begin of the programm, first run the test programm and then use the spiele function
 * 主函数 程序的开始 先运行test.cpp然后使用"spiele"函数
 * @return
 */
int main()
{
    std::cout << "Programm gestartet." << std::endl;

    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    int spielfeld[GROESSE_Y][GROESSE_X];

    initialisiereSpielfeld(spielfeld);

    zeigeSpielfeld(spielfeld);

    int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    spielen(spielerTyp);
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    
    return 0;
}
