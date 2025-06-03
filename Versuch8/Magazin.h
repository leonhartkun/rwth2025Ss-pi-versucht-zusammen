//
// Created by leonh on 25-6-3.
//

#ifndef MAGAZIN_H
#define MAGAZIN_H

#include "Medium.h"

/**
 * @class Magazin
 * @brief Repräsentiert eine Zeitschrift als spezielles Medium.
 *
 * Die Klasse Magazin erweitert die abstrakte Basisklasse Medium um das Ausgabedatum
 * und die Sparte (z. B. Wissenschaft, Sport, Mode).
 */
class Magazin : public Medium
{
public:
    /**
     * @brief Konstruktor für ein Magazin.
     *
     * Initialisiert ein Magazin mit Titel, Ausgabedatum und Sparte.
     *
     * @param initTitel Der Titel des Magazins.
     * @param initDatumAusgabe Das Ausgabedatum des Magazins.
     * @param initSparte Die Sparte (z. B. Wissenschaft, Politik, Kultur).
     */
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

    /**
     * @brief Virtueller Destruktor.
     *
     * Ermöglicht korrektes Löschen von Objekten über einen Zeiger auf Medium.
     */
    virtual ~Magazin();

    /**
     * @brief Gibt die Informationen des Magazins in den Ausgabestrom aus.
     *
     * Überschreibt die virtuelle Methode ausgabe() aus der Basisklasse.
     *
     * @param os Der Ausgabestrom (z. B. std::cout oder Datei).
     */
    void ausgabe(std::ostream& os) const override;

    /**
     * @brief Verleiht das Magazin, falls es noch nicht ausgeliehen ist.
     *
     * Magazine sind normalerweise nicht ausleihbar. In der Standardumsetzung
     * kann dies entsprechend angepasst oder eingeschränkt werden.
     *
     * @param person Die ausleihende Person.
     * @param ausleihdatum Das Datum der Ausleihe.
     * @return true, wenn die Ausleihe erfolgreich war; sonst false.
     */
    bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    /**
     * @brief Ausgabedatum des Magazins.
     */
    Datum datumAusgabe;

    /**
     * @brief Thematische Sparte des Magazins.
     */
    std::string sparte;
};

#endif //MAGAZIN_H
