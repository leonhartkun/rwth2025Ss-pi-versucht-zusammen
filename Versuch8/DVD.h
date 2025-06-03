//
// Created by leonh on 25-6-3.
//

#ifndef DVD_H
#define DVD_H

#include <vector>
#include "Medium.h"

/**
 * @class DVD
 * @brief Repräsentiert eine DVD als spezielles Medium.
 *
 * Die Klasse DVD erweitert die abstrakte Basisklasse Medium um zusätzliche
 * Eigenschaften wie Altersfreigabe und Genre.
 */
class DVD : public Medium
{
public:
    /**
     * @brief Konstruktor für eine DVD.
     *
     * Initialisiert eine DVD mit Titel, Altersfreigabe und Genre.
     *
     * @param initTitel Der Titel der DVD.
     * @param initAltersfreigabe Die Altersfreigabe der DVD (z. B. 12, 16, 18).
     * @param initGenre Das Genre der DVD (z. B. Action, Komödie, Drama).
     */
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);

    /**
     * @brief Virtueller Destruktor für DVD.
     *
     * Ermöglicht korrektes Löschen polymorpher Objekte.
     */
    virtual ~DVD();

    /**
     * @brief Gibt alle Informationen zur DVD in den angegebenen Ausgabestrom aus.
     *
     * Überschreibt die Methode ausgabe() der Basisklasse.
     *
     * @param os Der Ausgabestrom (z. B. std::cout).
     */
    void ausgabe(std::ostream& os) const override;

    /**
     * @brief Verleiht die DVD an eine Person, falls das Alter geeignet ist.
     *
     * Wenn die Person zu jung ist (basierend auf Altersfreigabe), wird die Ausleihe verweigert.
     *
     * @param person Die Person, die die DVD ausleihen möchte.
     * @param ausleihdatum Das Datum der Ausleihe.
     * @return true, wenn die Ausleihe erfolgreich war.
     * @return false, wenn die Person zu jung ist.
     */
    bool ausleihen(Person person, Datum ausleihdatum) override;

private:
    /**
     * @brief Altersfreigabe der DVD.
     */
    int altersfreigabe;

    /**
     * @brief Genre der DVD.
     */
    std::string genre;
};

#endif //DVD_H
