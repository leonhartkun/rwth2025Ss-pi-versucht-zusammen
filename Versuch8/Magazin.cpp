//
// Created by leonh on 25-6-3.
//

#include "Magazin.h"
#include <iostream>
#include "Datum.h"

/**
 * @brief Konstruktor für die Klasse Magazin.
 *
 * Initialisiert ein Magazin mit Titel, Erscheinungsdatum und thematischer Sparte.
 *
 * @param initTitel Der Titel des Magazins.
 * @param initDatumAusgabe Das Erscheinungsdatum des Magazins.
 * @param initSparte Die Sparte, z. B. Politik, Wissenschaft, Sport.
 */
Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
    : Medium(initTitel), datumAusgabe(initDatumAusgabe), sparte(initSparte) {}

/**
 * @brief Virtueller Destruktor der Klasse Magazin.
 *
 * Wird benötigt, um polymorphe Objekte korrekt zu löschen.
 */
Magazin::~Magazin() = default;

/**
 * @brief Gibt alle Informationen zum Magazin in den übergebenen Ausgabestrom aus.
 *
 * Zusätzlich zu den Basisinformationen (ID, Titel, Verleihstatus) werden
 * Erscheinungsdatum und Sparte ausgegeben.
 *
 * @param os Der Ausgabestrom (z. B. std::cout oder eine Datei).
 */
void Magazin::ausgabe(std::ostream& os) const
{
    Medium::ausgabe(os);  ///< Aufruf der Basisausgabe
    os << "Type: Magazin" << "\n";
    os << "Erscheinungsdatum: " << datumAusgabe << "\n";
    os << "Sparte: " << sparte << "\n";
}

/**
 * @brief Versucht, das Magazin zu verleihen.
 *
 * Magazine, die am selben oder vorangehenden Tag erschienen sind (also neueste Ausgabe),
 * dürfen nicht ausgeliehen werden. Wenn das Erscheinungsdatum mindestens 1 Tag
 * zurückliegt, wird die Standard-Ausleihlogik von Medium verwendet.
 *
 * @param person Die Person, die das Magazin ausleihen möchte.
 * @param ausleihdatum Das gewünschte Ausleihdatum.
 * @return true, wenn die Ausleihe erlaubt und erfolgreich ist; false, wenn die neueste Ausgabe gesperrt ist.
 */
bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    if (ausleihdatum - datumAusgabe < 1)  ///< Neueste Ausgabe darf nicht verliehen werden
    {
        std::cout << "Dieses Magazin ist die neueste Ausgabe und darf nicht ausgeliehen werden." << std::endl;
        return false;
    }
    return Medium::ausleihen(person, ausleihdatum);  ///< Standardverhalten der Basisklasse
}
