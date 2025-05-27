//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

/**
 * @file Student.cpp
 * @brief Implementierung der Klasse Student
 *        学生类的实现部分
 */

#include <iostream>
#include "Student.h"
using namespace std;
/**
 * @brief 构造函数：创建一个完整的学生对象
 *        Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 * @param matNr 学号 / Matrikelnummer
 * @param name 姓名 / Name
 * @param geburtstag 出生日期 / Geburtstag
 * @param adresse 地址 / Adresse
 */
Student::Student(unsigned int matNr, string name, string geburtstag, string adresse)
    : matNr(matNr), name(name), geburtstag(geburtstag), adresse(adresse)
{ }

/**
 * @brief 默认构造函数：创建一个空学生对象
 *        Standardkonstruktor, der einen leeren Studenten erstellt
 */
Student::Student() : matNr(0), name(""), geburtstag(""), adresse("")
{ }

/**
 * @brief 获取学生的学号
 *        Gibt die Matrikelnummer des Studenten zurück
 * @return 学号 / Matrikelnummer
 */
unsigned int Student::getMatNr() const
{
    return matNr;
}

/**
 * @brief 获取学生姓名
 *        Gibt den Namen des Studenten zurück
 * @return 姓名 / Name
 */
string Student::getName() const
{
    return name;
}

/**
 * @brief 获取学生出生日期
 *        Gibt den Geburtstag des Studenten zurück
 * @return 出生日期 / Geburtstag
 */
string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief 获取学生地址
 *        Gibt die Adresse des Studenten zurück
 * @return 地址 / Adresse
 */
string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief 输出学生的全部数据（控制台输出）
 *        Gibt alle Daten des Studenten in einer Zeile aus
 */
void Student::ausgabe() const
{
    cout << name << ", MatNr. " << matNr << ", geb. am "
              << geburtstag << ", wohnhaft in " << adresse
              << endl;
}
/**
 *@brief 比较大小
 *       vergleichen matnummer
 * @param other
 * @return
 */
bool Student::operator>(const Student& other) const{
    return this->matNr > other.matNr;
}
/**
 *@brief 比较大小
 *       vergleichen matnummer
 * @param other
 * @return
 */
bool Student::operator<(const Student& other) const{
    return this->matNr < other.matNr;
}
/**
 *@brief 比较大小
 *       vergleichen matnummer
 * @param other
 * @return
 */
bool Student::operator==(const Student& other) const{
    return this->matNr == other.matNr;
}
/**
 *@brief Überladet den <<-Operator, um einen Studenten auf einem Ausgabestrom auszugeben.
 *      中文：重载 << 运算符，用于将 Student 对象输出到输出流。
 * @param os
 * @param student
 * @return
 */
ostream& operator<<(ostream& os, const Student& student){
    return os << "name:"
              << student.name
              << ", Matrikelnummer:"
              << student.matNr
              << ", Geburtstag:"
              << student.geburtstag
              << ", Adresse:"
              << student.adresse;
}
/**
 * @brief Überladet den >>-Operator, um einen Studenten vom Eingabestrom einzulesen.
 *        中文：重载 >> 运算符，用于从输入流中读取一个 Student 对象。
 *
 * @param is Der Eingabestrom（输入流，例如 cin）
 * @param s Das Student-Objekt, das eingelesen werden soll（要读取的学生对象）
 * @return Referenz auf den Eingabestrom（返回输入流本身，允许链式操作）
 */
istream& operator>>(istream& is, Student& s) {
        string matnum_s;
        cout << "Name: ";
        getline(is >> ws, s.name);  // ws 去掉前导空白
        cout << "Geburtstag: ";
        getline(is >> ws, s.geburtstag);
        cout << "Address: ";
        getline(is >> ws, s.adresse);
        cout << "Matrikelnummer: ";
        getline(is >> ws, matnum_s);

        try {
            s.matNr = stoi(matnum_s);
        } catch (...) {
            cerr << "Ungültige Eingabe für Matrikelnummer!\n";
            s.matNr = -1; // 或者抛异常
        }

        return is;
    }
