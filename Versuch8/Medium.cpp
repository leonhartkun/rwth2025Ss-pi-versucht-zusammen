/*!
 * @file Medium.cpp
 * @brief Implementierung der Basisklasse Medium für das Praktikum Informatik 1.
 */

#include "Medium.h"
#include <string>
#include <iostream>

// Initialisierung der statischen ID-Zählvariable
unsigned int Medium::currentID = 1;

/**
 * @brief Konstruktor für Medium.
 *
 * Initialisiert ein Medium mit dem gegebenen Titel, setzt den Verleihstatus auf „nicht ausgeliehen“
 * und vergibt eine eindeutige ID.
 *
 * @param initTitel Titel des Mediums.
 */
Medium::Medium(std::string initTitel)
: titel(initTitel)
, status(false)
{
    ID = currentID++;
}

/**
 * @brief Virtueller Destruktor.
 *
 * Erforderlich, um Vererbung korrekt zu unterstützen.
 */
Medium::~Medium(void)
{
}

/**
 * @brief Gibt alle Informationen des Mediums in den übergebenen Ausgabestrom aus.
 *
 * Gibt ID, Titel und Verleihstatus (inkl. Datum und Name der Person) aus.
 *
 * @param os Ausgabestrom, z.B. std::cout oder Datei.
 */
void Medium::ausgabe(std::ostream& os) const
{
    os << "ID: " << ID << "\n";
    os << "Titel: " << titel << "\n";

    if (status)
    {
        os << "Status : Das Medium ist seit dem " << datumAusgeliehen
           << " an " << personAusgeliehen.getName() << " ausgeliehen." << "\n";
    }
    else
    {
        os << "Status: Medium ist zurzeit nicht verliehen." << "\n";
    }
}

/**
 * @brief Verleiht das Medium an eine bestimmte Person.
 *
 * Prüft, ob das Medium bereits ausgeliehen ist. Falls nicht, wird es verliehen
 * und die entsprechenden Daten gespeichert.
 *
 * @param person Die Person, die das Medium ausleiht.
 * @param ausleihdatum Das Datum der Ausleihe.
 * @return true Wenn die Ausleihe erfolgreich war.
 * @return false Wenn das Medium bereits verliehen ist.
 */
bool Medium::ausleihen(Person person, Datum ausleihdatum)
{
    if (status)
    {
        std::cout << "Das Medium \"" << titel << "\" ist bereits verliehen!" << std::endl;
        return false;
    }
    else
    {
        status = true;
        personAusgeliehen = person;
        datumAusgeliehen = ausleihdatum;
        std::cout << "Das Medium \"" << titel << "\" wird an "
                  << person.getName() << " verliehen." << std::endl;
        return true;
    }
}

/**
 * @brief Gibt das Medium zurück.
 *
 * Setzt den Status auf „nicht ausgeliehen“, wenn es zuvor verliehen war.
 */
void Medium::zurueckgeben()
{
    if (status)
    {
        status = false;
        std::cout << "Das Medium \"" << titel << "\" wurde zurückgegeben." << std::endl;
    }
    else
    {
        std::cout << "Das Medium \"" << titel << "\" ist nicht verliehen!" << std::endl;
    }
}

/**
 * @brief Gibt die ID des Mediums zurück.
 *
 * @return Die eindeutige ID-Nummer des Mediums.
 */
unsigned int Medium::getID()
{
    return ID;
}

bool Medium::get_status() const{
    return status;
}

std::ostream& operator<<(std::ostream& os, const Medium& m) {
    m.ausgabe(os);
    return os;
}
