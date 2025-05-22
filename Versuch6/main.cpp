/**
* @file main.cpp
 * @brief Praktikum Informatik 1 MMXXV - Versuch 5: Dynamische Datenstrukturen
 *
 *        DE: Dieses Programm implementiert eine einfache Studentendatenbank basierend auf einem Vektor.
 *        CN: 本程序为 Praktikum Informatik 1 的实验 5，使用 std::vector 实现了一个简单的学生数据库。
 *
 *        Funktionen umfassen:
 *        - Einlesen von Studierendendaten aus einer Datei
 *        - Ausgabe der Daten vorwärts und rückwärts
 *        - Hinzufügen/Löschen von Einträgen an verschiedenen Positionen
 *        - Speichern der Daten in eine Datei
 *
 *        Hauptmenü-Befehle:
 *        1: 读取文件 / Datei einlesen
 *        2: 正序输出 / Vorwärts ausgeben
 *        3: 反序输出 / Rückwärts ausgeben
 *        4: 前插数据 / Element vorne einfügen
 *        5: 删除末尾元素 / Hinten löschen
 *        6: 删除开头元素 / Vorne löschen
 *        7: 按索引插入 / Per Index einfügen
 *        8: 按索引删除 / Per Index löschen
 *        9: 保存文件 / In Datei speichern
 *        0: 退出程序 / Beenden
 *
 * @author Jiakun Yu
 * @date 2025-05-19
 */
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include <windows.h>
#include <fstream>

#define FP "D:\\rwth_eclipse_workstation\\Versuch6\\studenten.txt"

using namespace std;
/**
 * @brief DE: Fragt die Bestätigung für eine Aktion am Objekt ab.
 *        CN: 确认是否对某个学生对象执行指定操作。
 *
 * @param object Das betroffene Student-Objekt / 要操作的学生对象
 * @param action Die Aktion (als String) / 操作描述（如"löschen"）
 * @return true bei Bestätigung / 用户确认执行返回 true
 */
bool check(Student object, string action)
{
    cout<<"Moechten Sie"<<endl<<endl<<"\t";
    object.ausgabe();
    cout<<endl<<"wirklich "<<action<<"? (J/N):";
    string antwort;
    getline(cin, antwort);
    const char eingabe = static_cast<char>(toupper(antwort[0]));
    // 转为大写并判断
    if (!antwort.empty()) {
        if (eingabe == 'J') {
            return true;
        }
    }
    return false;
}
/**
 * @brief DE: Erfasst die Eingabe eines neuen Studenten vom Benutzer.
 *        CN: 从用户处获取一个新的学生数据。
 *
 * @return Student Das erzeugte Student-Objekt / 返回构造的学生对象
 */
Student get_info() {
    string name;
    string geburtstag;
    string address;
    string matnum_s;
    cout<<"name:";
    getline(cin,name);
    cout<<"geburtstag:";
    getline(cin,geburtstag);
    cout<<"address:";
    getline(cin,address);
    cout<<"matnum:";
    getline(cin,matnum_s);
    int matnum = stoi(matnum_s);
    Student tmp(matnum, name, geburtstag, address);
    return tmp;
}
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

    vector<Student> studentenListe;

    /**
     * @brief Hauptmenü-Schleife / 主菜单循环
     *        Bietet Optionen zum Hinzufügen, Entfernen, Suchen und Ausgeben von Studenten
     */
    char abfrage;
    /**
    * @brief Hauptmenü-Schleife / 主菜单循环
    *        Bietet Optionen zum Einlesen, Hinzufügen, Entfernen und Speichern von Studentendaten.
    *        提供读取、插入、删除和保存学生数据的操作选项。
    */

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Daten aus Datei einlesen" << std::endl
                  << "(2): Durch iterator von vornen nach hinten ausgeben" << std::endl
                  << "(3): Durch iterator von hinten nach vornen ausgeben" << std::endl
                  << "(4): Datenelement hinten hinzufuegen" << std::endl
                  << "(5): Datenelement hinten entfernen" << std::endl
                  << "(6): Datenelement vornen entfernen" << std::endl
                  << "(7): Datenelement durch index hinzufuegen" << std::endl
                  << "(8): Datenelement durch index entfern" << std::endl
                  << "(9): Daten in Datei sichern" << std::endl
                  << "(0): Beenden" << std::endl;
        cin >> abfrage;
        cin.ignore(10, '\n');

        switch (abfrage)
        {
            case '1': {// case 1: Datei einlesen / 从文件读取学生信息
                studentenListe.clear();
                cout<<"bitte geben Sie die Path fuer die Datei ein"<<endl;
                string file_path;
                cin >> file_path;
                cin.ignore(10, '\n');
                if (file_path == "/") {
                    file_path = FP;
                }
                ifstream file_inhalt(file_path);
                if (!file_inhalt) {
                    cout<<"Datei nicht oeffen kann"<<endl;
                }

                string line;

                while (true) {
                    Student student_tmp;
                    string name;
                    string geburtstag;
                    string address;
                    string matnum_s;

                    if (!std::getline(file_inhalt, matnum_s)) break;
                    if (!std::getline(file_inhalt, name)) break;
                    if (!std::getline(file_inhalt, geburtstag)) break;
                    if (!std::getline(file_inhalt, address)) break;

                    int matnum = stoi(matnum_s);

                    student_tmp = Student(matnum, name, geburtstag, address);
                    studentenListe.push_back(student_tmp);
                }

                break;
            }

            case '2': {// case 2: Ausgabe von vorne nach hinten / 正序输出
                if (studentenListe.size() == 0) {
                    cout<<"Liste ist empty"<<endl;
                    break;
                }
                int num = 0;
                for (auto it = studentenListe.begin(); it != studentenListe.end(); it++) {
                    cout<<"("<<num<<")";
                    it->ausgabe();
                    num++;
                }
                break;
            }
            case '3':// case 3: Ausgabe von hinten nach vorne / 反序输出
            {
                if (studentenListe.size() == 0) {
                    cout<<"Liste ist empty"<<endl;
                    break;
                }
                for (auto rit = studentenListe.rbegin(); rit != studentenListe.rend(); rit++) {
                    rit->ausgabe();
                }
                break;
            }

            case '4':// case 4: Element vorne einfügen / 插入到前方
            {

                Student student_tmp = get_info();
                if (check(student_tmp,"hinzufuegen")) {
                    studentenListe.insert(studentenListe.begin(),student_tmp);
                    student_tmp.ausgabe();
                    cout<<"Datei hinzufuegt"<<endl;
                    break;
                }
                cout<<"Datei wurde nicht hinzufuegen"<<endl;
            }

            case '5':// case 5: Element hinten löschen / 删除最后一个
            {
                if (check(studentenListe.back(),"loeschen"))
                    {
                    studentenListe.pop_back();
                    cout<<"Datei geloescht"<<endl;
                    break;
                    }
                cout<<"Datei wurde nicht geloescht."<<endl;
                break;
            }
            case '6':// case 6: Element vorne löschen / 删除第一个
            {

                    if (check(studentenListe[0],"loeschen"))
                    {
                        studentenListe.erase(studentenListe.begin());
                        cout<<"Datei geloescht"<<endl;
                        break;
                    }
                    cout<<"Datei wurde nicht geloescht."<<endl;
                break;
            }
            case '7':// case 7: Element nach Index einfügen / 按索引插入
            {
                Student student_tmp = get_info();
                if (check(student_tmp,"hinzufuegen"))
                    {
                    cout<<"Bitte geben Sie die Index ein"<<endl;
                    int index;
                    cin>>index;
                    studentenListe.insert(studentenListe.begin()+index,student_tmp);
                    cout<<"Datei hinzufuegt"<<endl;
                    break;
                }
                cout<<"Datei wurde nicht hinzufuegt"<<endl;
                break;
            }
            case '8':// case 8: Element nach Index löschen / 按索引删除
            {
                cout<<"Bitte geben Sie die Index ein:"<<endl;
                string index_s;
                getline(cin,index_s);
                int index = stoi(index_s);
                if (check(studentenListe[index],"loeschen")) {
                    studentenListe.erase(studentenListe.begin()+index);
                    cout<<"Datei geloescht"<<endl;
                    break;
                }
                cout<<"Datei wurde nicht geloescht"<<endl;
                break;
            }
            case '9':// case 9: Datei speichern / 保存至文件
            {
                cout<<"Bitte geben Sie der Filename ein:";
                string filename;
                getline(cin,filename);
                cout<<"Moechten Sie"<<endl<<endl<<"\t"<<filename<<endl<<"wirklich aufbauen? (J/N):";
                string abfrage;
                getline(cin,abfrage);
                if (abfrage=="J" || abfrage=="j") {
                    ofstream opfile(filename);
                    opfile.clear();
                    for (auto it = studentenListe.begin(); it != studentenListe.end(); it++) {
                        opfile<<it->getMatNr()<<endl;
                        opfile<<it->getName()<<endl;
                        opfile<<it->getGeburtstag()<<endl;
                        opfile<<it->getAdresse()<<endl;
                    }
                    opfile.close();
                    cout<<"Daten sichert"<<endl;
                    break;
                }
                cout<<"Daten wurde nicht sichert"<<endl;
                break;
            }
            case '0':// case 0: Programm beenden / 退出程序
                std::cout << "Das Programm wird nun beendet." << std::endl;
                return 0;
                break;

            default:/**< 输入错误提示 / Falsche Eingabe */
                std::cout << "Falsche Eingabe, bitte nochmal." << std::endl;
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
