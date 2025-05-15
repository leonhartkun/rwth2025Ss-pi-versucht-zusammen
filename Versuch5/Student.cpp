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

/**
 * @brief 构造函数：创建一个完整的学生对象
 *        Konstruktor, der einen neuen Studenten mit allen Werten erstellt
 * @param matNr 学号 / Matrikelnummer
 * @param name 姓名 / Name
 * @param geburtstag 出生日期 / Geburtstag
 * @param adresse 地址 / Adresse
 */
Student::Student(unsigned int matNr, std::string name, std::string geburtstag, std::string adresse)
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
std::string Student::getName() const
{
    return name;
}

/**
 * @brief 获取学生出生日期
 *        Gibt den Geburtstag des Studenten zurück
 * @return 出生日期 / Geburtstag
 */
std::string Student::getGeburtstag() const
{
    return geburtstag;
}

/**
 * @brief 获取学生地址
 *        Gibt die Adresse des Studenten zurück
 * @return 地址 / Adresse
 */
std::string Student::getAdresse() const
{
    return adresse;
}

/**
 * @brief 输出学生的全部数据（控制台输出）
 *        Gibt alle Daten des Studenten in einer Zeile aus
 */
void Student::ausgabe() const
{
    std::cout << name << ", MatNr. " << matNr << ", geb. am "
              << geburtstag << ", wohnhaft in " << adresse
              << std::endl;
}
