/** @mainpage
 * @brief Praktikum Informatik 1 MMXXV
 * Versuch 5: Dynamische Datenstrukturen
 *
 * Dieses Programm implementiert eine einfache Studentendatenbank basierend auf einer doppelt verketteten Liste.
 * 本程序为 Praktikum Informatik 1 的实验 5，实现了一个基于双链表的简单学生数据库。
 */

#include <iostream>
#include <string>
#include "Liste.h"
#include "Student.h"

/**
 * @brief 主函数 / Hauptfunktion
 * Führt ein textbasiertes Menü aus zur Verwaltung einer Studentendatenbank
 * 运行一个基于文本菜单的学生数据库管理程序
 *
 * @return 0 程序正常结束 / Rückgabewert 0 bei regulärem Programmende
 */
int main()
{
    Liste studentenListe;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    // 自动填充示例数据 / Automatisches Vorfüllen der Liste
    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.pushBack(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.pushBack(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.pushBack(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.pushBack(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wüllnerstr.9");
        studentenListe.pushBack(student);
    }

    // 主菜单循环 / Hauptmenü-Schleife
    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            case '1':  // 添加学生数据
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben Sie die Daten für den Studenten ein.\nName: ";
                    getline(std::cin, name);

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);
                    studentenListe.pushBack(student);
                }
                break;

            case '2':  // 删除学生数据（头部）
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.dataFront();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe();
                        studentenListe.popFront();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!" << std::endl;
                    }
                }
                break;

            case '3':  // 输出全部学生
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    studentenListe.ausgabeVorwaerts();
                }
                else
                {
                    std::cout << "Die Liste ist leer!" << std::endl;
                }
                break;

            case '0':  // 程序结束
                std::cout << "Das Programm wird nun beendet." << std::endl;
                break;

            default:
                std::cout << "Falsche Eingabe, bitte nochmal." << std::endl;
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
