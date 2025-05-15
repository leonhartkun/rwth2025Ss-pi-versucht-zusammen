//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

int main()
{
    int iErste = 0;
    int iZweite = 0;

    // Hier folgt Ihr eigener Code
    std::cout<<"bitte input erste Nummer";
    std::cin>>iErste;
    std::cout<<"bitte input zweite Nummer";
    std::cin>>iZweite;
    while (iZweite == 0) {
        std::cout<<"bitte input zweite nummer (!=0)";
        std::cin>>iZweite;
    }
    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite;
    std::cout<<"double Type in int Form"<<"Summe = "<<dSumme<<" ,Quotient="<<dQuotient<<std::endl;
    double dSummeCast = (double)iErste + (double)iZweite;
    double dQuotientCast  = (double)iErste / (double)iZweite;
    std::cout<<"double Type in double Form"<<"Summe = "<<dSummeCast<<" ,Quotient="<<dQuotientCast<<std::endl;
    std::string sVorname;
    std::string sNachname;
    std::cout<<"Bitte geben Sie Ihren Vornamen ein:";
    std::cin>>sVorname;
    std::cout<<"Bitte geben Sie Ihren Nachnamen ein:";
    std::cin>>sNachname;
    std::string sVornameName = sVorname+" "+sNachname;
    std::string sNameVorname = sNachname+" "+sVorname;
    std::cout<<"Form Vorname Nachname: "<<sVornameName<<std::endl<<"Form Nachname Vorname: "<<sNameVorname<<std::endl;
    {
        int iFeld[2] = {1, 2};
        std::cout << "a) " << iFeld[0] << " " << iFeld[1] << std::endl;
    }

    // b)
    {
        int spielfeld[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
        };
        std::cout << "b) ";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::cout << spielfeld[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }


    // c)
    {
        iZweite = 1;
        std::cout << "c) " << iZweite << std::endl;
    }

    // 输出块外的 iZweite
    std::cout << "Ausserhalb des Blocks: " << iZweite << std::endl;

    int iName1 = sVorname[0];
    int iName2 = sVorname[1];
    std::cout <<"ASCII erste Buchstabe des Vorname"<< iName1 << " \n"<< "ASCII zweitte Buchstabe des Vorname" << iName2 << std::endl;
    std::cout <<"Position erste Buchstabe des Vorname"<< iName1%32 << " \n"<< "Position zweitte Buchstabe des Vorname" << iName2%32 << std::endl;
}
