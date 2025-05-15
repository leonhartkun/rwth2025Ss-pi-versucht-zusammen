///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	string op;
	// Hier folgt Ihr Code
	for (int i = 0; i < wort.length(); i++) {
		for (int sch = 0; sch < 26; sch++) {
			if (wort[i] == schluessel[0][sch]) {
				op+=schluessel[1][sch];
			}
		}
	}
	return op;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	string op;
	for (int i = 0; i < wort.length(); i++) {
		for (int sch = 0; sch < 26; sch++) {
			if (wort[i] == schluessel[1][sch]) {
				op+=schluessel[0][sch];
			}
		}
	}

	return op;
}

int main()
{
	// Hier folgt Ihr Code
	int bewegen = 1;
	char schluessel[2][26];
	for (int i = 0; i < 26; i++) {
		schluessel[0][i] = 65+i;
		schluessel[1][i] = (65+i+bewegen)%65+65;
	}
	string klartext;
	cout << "Bitte geben Sie ein Wort in Grossbuchstaben ein: ";
	cin >> klartext;
	cout<<"klartest: ";
	cout << klartext << std::endl;
	cout<<"verschluesselntext: ";
	cout<<verschluesseln(schluessel,klartext)<<endl;
	cout<<"entschluesselntext: ";
	cout<<entschluesseln(schluessel,verschluesseln(schluessel,klartext))<<endl;



	return 0;
}
