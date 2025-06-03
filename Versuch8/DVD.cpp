//
// Created by leonh on 25-6-3.
//

#include "DVD.h"
#include <iostream>

/**
 * @brief Konstruktor für die Klasse DVD.
 *
 * Initialisiert eine DVD mit Titel, Altersfreigabe und Genre.
 *
 * @param initTitel Der Titel der DVD.
 * @param initAltersfreigabe Die Altersfreigabe (z. B. 12, 16, 18).
 * @param initGenre Das Genre der DVD (z. B. Action, Komödie).
 */
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
    : Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre) {}

/**
 * @brief Virtueller Destruktor.
 *
 * Wird automatisch aufgerufen und benötigt keine besondere Implementierung.
 */
DVD::~DVD() = default;

/**
 * @brief Gibt alle Informationen zur DVD in den übergebenen Ausgabestrom aus.
 *
 * Die Basisinformationen (ID, Titel, Status) werden durch Medium::ausgabe()
 * ausgegeben, anschließend folgen spezifische Angaben zur Altersfreigabe und Genre.
 *
 * @param os Der Ausgabestrom (z. B. std::cout oder eine Datei).
 */
void DVD::ausgabe(std::ostream& os) const {
    Medium::ausgabe(os);
    os << "Altersfreigabe: " << altersfreigabe << "\n";
    os << "Genre: " << genre << "\n";
}

/**
 * @brief Verleiht die DVD, sofern die Altersfreigabe eingehalten wird.
 *
 * Überprüft anhand des Geburtsdatums der Person, ob sie alt genug ist, um
 * die DVD auszuleihen. Wenn nicht, wird die Ausleihe verweigert.
 *
 * @param person Die Person, die die DVD ausleihen möchte.
 * @param ausleihdatum Das gewünschte Ausleihdatum.
 * @return true, wenn die Ausleihe erlaubt ist.
 * @return false, wenn die Person zu jung ist.
 */
bool DVD::ausleihen(Person person, Datum ausleihdatum) {
    // Hinweis: Alter = aktuelles Datum - Geburtsdatum
    int alter = ausleihdatum - person.getGeburtsdatum();  // Datum muss Differenz als int liefern
    if (alter < altersfreigabe) {
        std::cout << "Diese Person erfüllt die Altersbeschränkung für diese DVD nicht." << std::endl;
        return false;
    }
    return Medium::ausleihen(person, ausleihdatum);
}
