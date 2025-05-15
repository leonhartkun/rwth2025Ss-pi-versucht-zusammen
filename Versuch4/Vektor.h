/**
* @file Vektor.h
 * @brief Definition der Klasse Vektor zur Darstellung und Berechnung von 3D-Vektoren.
 */

#ifndef Vektor_H
#define Vektor_H

#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * @class Vektor
 * @brief Repräsentiert einen Vektor im dreidimensionalen Raum.
 */
class Vektor
{
public:
    /**
     * @brief Konstruktor mit x-, y-, z-Komponenten
     * @param x X-Komponente
     * @param y Y-Komponente
     * @param z Z-Komponente
     */
    Vektor(double x, double y, double z);

    /**
     * @brief Destruktor
     */
    ~Vektor();

    /**
     * @brief Gibt die Vektorkomponenten auf der Konsole aus.
     */
    void ausgabe() const;

    /**
     * @brief Berechnet die Differenz zu einem anderen Vektor.
     * @param input Der andere Vektor
     * @return Ein neuer Vektor (this - input)
     */
    Vektor sub(const Vektor& input) const;

    /**
     * @brief Berechnet die Länge (Betrag) des Vektors.
     * @return Länge des Vektors
     */
    double laenge() const;

    /**
     * @brief Berechnet das Skalarprodukt mit einem anderen Vektor.
     * @param input Der andere Vektor
     * @return Skalarprodukt
     */
    double skalarProd(const Vektor& input) const;

    /**
     * @brief Berechnet den Winkel (in Grad) zwischen zwei Vektoren.
     * @param input Der andere Vektor
     * @return Winkel in Grad
     */
    double winkel(const Vektor& input) const;

    /**
     * @brief Rotiert den Vektor um die Z-Achse.
     * @param rad Winkel im Bogenmaß
     */
    void rotiereUmZ(const double rad);

    /**
     * @brief Gibt die X-Komponente zurück.
     */
    double getX() const { return x; }

    /**
     * @brief Gibt die Y-Komponente zurück.
     */
    double getY() const { return y; }

    /**
     * @brief Gibt die Z-Komponente zurück.
     */
    double getZ() const { return z; }

private:
    double x; ///< X-Komponente
    double y; ///< Y-Komponente
    double z; ///< Z-Komponente
};

#endif
