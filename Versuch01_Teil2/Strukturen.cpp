/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
struct Person{
    std::string sNachname;
    std::string sVorname;
    int iGeburtsjahr;
    int iAlter;
};
int main()
{
    Person nBenutzer;
    std::cout<<"Bitte geben Ihren Vorname ein: ";
    std::cin>>nBenutzer.sVorname;
    std::cout<<"Bitte geben Ihren Nachname ein: ";
    std::cin>>nBenutzer.sNachname;
    std::cout<<"Bitte geben Ihren Geburtsjahr ein: ";
    std::cin>>nBenutzer.iGeburtsjahr;
    std::cout<<"Bitte geben Alter ein: ";
    std::cin>>nBenutzer.iAlter;
    std::cout<<"____Normale____\n Struct(Normale) zeigen: \nName:"<<nBenutzer.sVorname+nBenutzer.sNachname<<"\nVorname: ";
    std::cout<<nBenutzer.sVorname<<"\nNachname: "<<nBenutzer.sNachname<<std::endl;
    std::cout<<"Geburtsinfomationen:\n Geburtsjahr: "<<nBenutzer.iGeburtsjahr<<"\n Alter: "<<nBenutzer.iAlter<<std::endl;
    Person nKopieEinzeln;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;

    // Schritt 5.2: Gesamte Struktur kopieren
    Person nKopieGesamt = nBenutzer;
    std::cout<<"____Einzel____\n Struct(Einzel) zeigen: \nName:"<<nKopieEinzeln.sVorname+nKopieEinzeln.sNachname<<"\nVorname: ";
    std::cout<<nKopieEinzeln.sVorname<<"\nNachname: "<<nKopieEinzeln.sNachname<<std::endl;
    std::cout<<"Geburtsinfomationen:\n Geburtsjahr: "<<nKopieEinzeln.iGeburtsjahr<<"\n Alter: "<<nKopieEinzeln.iAlter<<std::endl;
    std::cout<<"____gesamt____\n Struct(gesamet) zeigen: \nName:"<<nKopieGesamt.sVorname+nKopieGesamt.sNachname<<"\nVorname: ";
    std::cout<<nKopieGesamt.sVorname<<"\nNachname: "<<nKopieGesamt.sNachname<<std::endl;
    std::cout<<"Geburtsinfomationen:\n Geburtsjahr: "<<nKopieGesamt.iGeburtsjahr<<"\n Alter: "<<nKopieGesamt.iAlter<<std::endl;
    return 0;
    
}
