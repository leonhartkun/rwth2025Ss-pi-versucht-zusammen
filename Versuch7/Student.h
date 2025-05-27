#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

using namespace std;

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
    Student(unsigned int matNr, string name, string geburtstag, string address);

    /**
     * @brief 获取学号 / Gibt die Matrikelnummer zurück
     * @return 学号 / Matrikelnummer
     */
    unsigned int getMatNr() const;

    /**
     * @brief 获取姓名 / Gibt den Namen zurück
     * @return 姓名 / Name
     */
    string getName() const;

    /**
     * @brief 获取出生日期 / Gibt das Geburtsdatum zurück
     * @return 出生日期 / Geburtstag
     */
    string getGeburtstag() const;

    /**
     * @brief 获取地址 / Gibt die Adresse zurück
     * @return 地址 / Adresse
     */
    string getAdresse() const;

    /**
     * @brief 在终端输出学生信息
     *        Gibt die Studentendaten auf der Konsole aus
     */
    void ausgabe() const;

    /**
     *@brief 比较大小
     *       vergleichen matnummer
     * @param other
     * @return
     */
    bool operator>(const Student& other) const;
    /**
     *@brief 比较大小
     *       vergleichen matnummer
     * @param other
     * @return
     */
    bool operator<(const Student& other) const;
    /**
     *@brief 比较大小
     *       vergleichen matnummer
     * @param other
     * @return
     */
    bool operator==(const Student& other) const;

    /**
     *@brief Überladet den <<-Operator, um einen Studenten auf einem Ausgabestrom auszugeben.
     *      中文：重载 << 运算符，用于将 Student 对象输出到输出流。
     * @param os
     * @param student
     * @return
     */
    friend ostream& operator<<(ostream& os, const Student& student);
    /**
     * @brief Überladet den >>-Operator, um einen Studenten vom Eingabestrom einzulesen.
     *        中文：重载 >> 运算符，用于从输入流中读取一个 Student 对象。
     *
     * @param is Der Eingabestrom（输入流，例如 cin）
     * @param s Das Student-Objekt, das eingelesen werden soll（要读取的学生对象）
     * @return Referenz auf den Eingabestrom（返回输入流本身，允许链式操作）
     */
    friend istream& operator>>(istream& is, Student& s);
private:
    unsigned int matNr;         ///< 学号 / Matrikelnummer
    string name;           ///< 姓名 / Name
    string geburtstag;     ///< 出生日期 / Geburtstag
    string adresse;        ///< 地址 / Adresse
};

#endif // STUDENT_H_
