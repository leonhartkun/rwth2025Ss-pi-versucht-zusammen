/**
 * @file Vektor.cpp
 * @brief Implementierung der Klasse Vektor
 */

#include "Vektor.h"
#include <cmath>
#include <iostream>
#include <iomanip>

/**
 * @brief Konstruktor: Initialisiert den Vektor mit x-, y- und z-Komponenten.
 * @param inX X-Komponente
 * @param inY Y-Komponente
 * @param inZ Z-Komponente
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{
}

/**
 * @brief Destruktor
 */
Vektor::~Vektor()
{
}

/**
 * @brief Berechnet die Länge (Betrag) des Vektors und gibt diese auf der Konsole aus.
 * @return Länge des Vektors
 */
double Vektor::laenge() const
{
    std::cout << std::sqrt(x * x + y * y + z * z) << std::endl;
    return std::sqrt(x * x + y * y + z * z);
}

/**
 * @brief Berechnet die Differenz zwischen dem aktuellen Vektor und einem Eingabevektor.
 * @param input Der Vektor, der abgezogen wird.
 * @return Neuer Vektor mit der Differenz
 */
Vektor Vektor::sub(const Vektor& input) const
{
    return Vektor(x - input.x, y - input.y, z - input.z);
}

/**
 * @brief Berechnet das Skalarprodukt (inneres Produkt) mit einem anderen Vektor.
 * @param input Der andere Vektor
 * @return Das Skalarprodukt
 */
double Vektor::skalarProd(const Vektor& input) const
{
    return x * input.x + y * input.y + z * input.z;
}

/**
 * @brief Berechnet den Winkel (in Grad) zwischen diesem Vektor und einem anderen.
 *
 * Gibt bei fehlerhaften Eingaben (z. B. Nullvektor) 0 zurück.
 * Es wird sichergestellt, dass der Wert für acos im gültigen Bereich liegt.
 *
 * @param input Der andere Vektor
 * @return Winkel in Grad
 */
double Vektor::winkel(const Vektor& input) const
{
    std::cout << "test" << std::endl;
    double dot = skalarProd(input);
    double len1 = laenge();
    double len2 = input.laenge();

    if (len1 == 0 || len2 == 0)
        return 0.0;

    double cosWinkel = dot / (len1 * len2);

    if (cosWinkel > 1.0) cosWinkel = 1.0;
    if (cosWinkel < -1.0) cosWinkel = -1.0;

    double rad = std::acos(cosWinkel);
    std::cout << rad << std::endl;
    return rad * 180.0 / M_PI;
}

/**
 * @brief Rotiert den Vektor um die Z-Achse im Uhrzeigersinn.
 * @param rad Rotationswinkel im Bogenmaß (Radian)
 */
void Vektor::rotiereUmZ(const double rad)
{
    double xNeu = x * std::cos(rad) - y * std::sin(rad);
    double yNeu = x * std::sin(rad) + y * std::cos(rad);
    x = xNeu;
    y = yNeu;
}

/**
 * @brief Gibt die Komponenten des Vektors auf der Konsole aus.
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}
/**
 * @file Vektor.cpp
 * @brief Implementierung der Klasse Vektor
 */
