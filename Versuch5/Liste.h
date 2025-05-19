/**
 * @file main.cpp
 * @brief Praktikum Informatik 1 MMXXV - Versuch 5: Dynamische Datenstrukturen
 *        本程序为 Praktikum Informatik 1 的实验 5，实现了一个基于双链表的简单学生数据库。
 *        Dieses Programm implementiert eine einfache Studentendatenbank basierend auf einer doppelt verketteten Liste.
 *
 * @author
 *
 * @date 2025-05-19
 */

#include <iostream>
#include <string>
#include "Liste.h"
#include "Student.h"
#include <windows.h>

/**
 * @brief 主函数 / Hauptfunktion
 *        Führt ein textbasiertes Menü aus zur Verwaltung einer Studentendatenbank
 *        运行一个基于文本菜单的学生数据库管理程序
 *
 * @return int Rückgabewert 0 bei regulärem Programmende / 程序正常结束时返回 0
 */
int main()
{
    // 设置控制台编码为 UTF-8 / Konsole auf UTF-8 einstellen
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Liste studentenListe;    /**< 双链表，保存学生数据 / doppelt verkettete Liste für Studentendaten */
    Student student;        /**< 临时保存学生对象 / temporärer Studentengenerator */

    char abfrage;           /**< 用户菜单输入 / Nutzereingabe für Menü */
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    /**
     * @brief 自动填充示例数据 / Automatisches Vorfüllen der Liste
     * 当用户输入不是 'j' 时，预填充若干示例学生 / Wenn Eingabe ungleich 'j', wird die Liste mit Beispieldaten gefüllt
     */
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

    /**
     * @brief Hauptmenü-Schleife / 主菜单循环
     *        Bietet Optionen zum Hinzufügen, Entfernen, Suchen und Ausgeben von Studenten
     */
    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Matrikelnummer finden und loeschen" << std::endl
                  << "(5): Datenelement vorne hinzufuegen" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            case '1':/**< 插入至链表尾部 / Element hinten hinzufügen */
            {
                unsigned int matNr = 0;
                std::string name;
                std::string geburtstag;
                std::string adresse;

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

            case '2':/**< 删除链表头部元素 / Element vorne entfernen */
            {
                if (!studentenListe.empty())
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

            case '3':/**< 正向和反向输出列表内容 / Liste vorwärts und rückwärts ausgeben */
                if (!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    studentenListe.ausgabeVorwaerts();
                    std::cout << "Inhalt der Liste hinterwaerts:" << std::endl;
                    studentenListe.ausgabeHinterwaerts();
                }
                else
                {
                    std::cout << "Die Liste ist leer!" << std::endl;
                }
                break;

            case '4':/**< 按学号查找并删除学生 / Matrikelnummer finden und löschen */
            {
                std::cout << "Bitte geben Sie die Matrikelnummer ein: " << std::endl;
                int matnum;
                std::cin >> matnum;
                studentenListe.delete_student(matnum);
            }
            break;

            case '5':/**< 插入至链表头部 / Element vorne hinzufügen */
            {
                unsigned int matNr;
                std::string name, geburtstag, adresse;

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
                studentenListe.push_front(student);
            }
            break;

            case '0':/**< 程序结束 / Programm beenden */
                std::cout << "Das Programm wird nun beendet." << std::endl;
                break;

            default:/**< 输入错误提示 / Falsche Eingabe */
                std::cout << "Falsche Eingabe, bitte nochmal." << std::endl;
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
