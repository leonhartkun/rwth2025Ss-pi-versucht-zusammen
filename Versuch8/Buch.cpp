//
// Created by leonh on 25-6-3.
//

#include "Buch.h"
#include <iostream>

/**
 * @brief Konstruktor für die Klasse Buch.
 *
 * Initialisiert ein Buch mit einem gegebenen Titel und Autor.
 * Der Titel wird an den Konstruktor der Basisklasse Medium übergeben.
 *
 * @param initTitel Der Titel des Buches.
 * @param initAutor Der Autor des Buches.
 */
Buch::Buch(std::string initTitel, std::string initAutor)
    : Medium(initTitel), autor(initAutor) {}

/**
 * @brief Destruktor für die Klasse Buch.
 *
 * Standardmäßig implementiert. Wird benötigt, da die Basisklasse
 * einen virtuellen Destruktor verwendet.
 */
Buch::~Buch() = default;

/**
 * @brief Gibt alle Informationen zum Buch in den übergebenen Ausgabestrom aus.
 *
 * Diese Methode überschreibt die virtuelle Methode ausgabe() aus der
 * Basisklasse Medium. Zuerst werden die allgemeinen Mediendaten (ID, Titel, Ausleihstatus)
 * mittels Medium::ausgabe() ausgegeben, danach folgt die spezifische Angabe des Autors.
 *
 * @param os Der Ausgabestrom, in den die Informationen geschrieben werden sollen.
 */
void Buch::ausgabe(std::ostream& os) const {
    Medium::ausgabe(os);  ///< Ruft die Ausgabe der Basisklasse auf
    os << "Autor: " << autor << "\n";  ///< Gibt den Autor des Buches aus
}
