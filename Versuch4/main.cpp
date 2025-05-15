/**
* @file main.cpp
 * @brief Hauptprogramm zur Berechnung der Sichtweite über die Erdkrümmung.
 *
 * Dieses Programm verwendet die Klasse Vektor, um eine einfache
 * geometrische Simulation durchzuführen. Es wird berechnet,
 * wie weit man von einem erhöhten Punkt aus sehen kann,
 * bevor die Erdkrümmung die Sichtlinie unterbricht.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Vektor.h"

int main()
{
    // Beispiel-Vektoren
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);

    vector1.ausgabe();
    vector2.ausgabe();

    const double R = 6371.0;      // Erdradius in km
    const double hoehe = 0.5557;  // Höhe über dem Erdboden in km

    Vektor aussichtsPunkt(0, R + hoehe, 0); // Position des Beobachters
    Vektor sicht(0, -1, 0);                 // Start-Sichtvektor

    double winkel = 0.0;
    double step = 0.01;
    int schritte = 0;

    while (std::fabs(step) > 1e-9) {
        Vektor blick = sicht;
        blick.rotiereUmZ(winkel);

        Vektor sichtVektor = Vektor(
            aussichtsPunkt.getX() + blick.getX(),
            aussichtsPunkt.getY() + blick.getY(),
            0
        );

        double dot = sichtVektor.skalarProd(sichtVektor.sub(Vektor(0, 0, 0)));

        if (dot < R * R) {
            winkel -= step;
            step *= -0.1;
        } else {
            winkel += step;
        }

        schritte++;
    }

    double sichtDist = R * winkel;

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Sie können " << sichtDist << " Km weit sehen." << std::endl;
    std::cout << "Sie sind " << hoehe * 1000 << " Meter hoch." << std::endl;
    std::cout << "Der Winkel beträgt " << winkel * 180.0 / M_PI << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << schritte << std::endl;

    return 0;
}
