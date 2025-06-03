//
// Created by leonh on 25-6-3.
//

#ifndef BUCH_H
#define BUCH_H

#include "Medium.h"

/**
 * @class Buch
 * @brief Repräsentiert ein Buch als spezielles Medium.
 *
 * Die Klasse Buch erbt von der abstrakten Basisklasse Medium und erweitert diese
 * um einen zusätzlichen Attribut `autor`, um den Verfasser des Buches zu speichern.
 */
class Buch : public Medium
{
private:
    /**
     * @brief Der Autor des Buches.
     */
    std::string autor;

public:
    /**
     * @brief Konstruktor zum Initialisieren eines Buches.
     * @param initTitel Der Titel des Buches.
     * @param autor Der Name des Autors.
     */
    Buch(std::string initTitel, std::string autor);

    /**
     * @brief Virtueller Destruktor.
     *
     * Sorgt für korrektes Löschen von Objekten über einen Zeiger auf die Basisklasse.
     */
    virtual ~Buch();

    /**
     * @brief Gibt Informationen zum Buch in den übergebenen Ausgabestrom aus.
     * @param os Der Ausgabestrom, z.B. std::cout oder eine Datei.
     *
     * Diese Methode überschreibt die rein virtuelle Methode ausgabe()
     * der Basisklasse Medium.
     */
    void ausgabe(std::ostream& os) const override;
};

#endif //BUCH_H
