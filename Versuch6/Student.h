#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

/**
 * @class Student
 * @brief 表示一名学生，包括学号、姓名、生日和地址。
 *        Repräsentiert einen Studenten mit Matrikelnummer, Name, Geburtstag und Adresse.
 */
class Student
{
public:
    /**
     * @brief 默认构造函数
     *        Standardkonstruktor
     */
    Student();

    /**
     * @brief 构造函数，带有全部初始化信息
     *        Konstruktor mit vollständigen Informationen
     * @param matNr 学号 / Matrikelnummer
     * @param name 姓名 / Name
     * @param geburtstag 出生日期 / Geburtstag (z.B. "01.01.2000")
     * @param address 地址 / Adresse
     */
    Student(unsigned int matNr, std::string name, std::string geburtstag, std::string address);

    /**
     * @brief 获取学号 / Gibt die Matrikelnummer zurück
     * @return 学号 / Matrikelnummer
     */
    unsigned int getMatNr() const;

    /**
     * @brief 获取姓名 / Gibt den Namen zurück
     * @return 姓名 / Name
     */
    std::string getName() const;

    /**
     * @brief 获取出生日期 / Gibt das Geburtsdatum zurück
     * @return 出生日期 / Geburtstag
     */
    std::string getGeburtstag() const;

    /**
     * @brief 获取地址 / Gibt die Adresse zurück
     * @return 地址 / Adresse
     */
    std::string getAdresse() const;

    /**
     * @brief 在终端输出学生信息
     *        Gibt die Studentendaten auf der Konsole aus
     */
    void ausgabe() const;

private:
    unsigned int matNr;         ///< 学号 / Matrikelnummer
    std::string name;           ///< 姓名 / Name
    std::string geburtstag;     ///< 出生日期 / Geburtstag
    std::string adresse;        ///< 地址 / Adresse
};

#endif // STUDENT_H_
