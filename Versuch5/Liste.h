//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>
#include "ListenElement.h"
#include "Student.h"

/**
 * @class Liste
 * @brief 表示一个学生链表，用于存储和操作学生数据。
 *        Repräsentiert eine doppelt verkettete Liste von Studenten.
 */
class Liste
{
private:
    ListenElement* front; ///< 指向第一个元素的指针 / Zeiger auf das erste Listenelement
    ListenElement* back;  ///< 指向最后一个元素的指针 / Zeiger auf das letzte Listenelement

public:
    /**
     * @brief 构造函数，初始化空链表
     *        Konstruktor zur Initialisierung der leeren Liste
     */
    Liste();

    /**
     * @brief 在链表末尾添加一个学生数据项
     *        Fügt ein neues Studentenelement am Ende der Liste hinzu
     * @param pData 要添加的学生数据 / Studentendaten, die hinzugefügt werden
     */
    void pushBack(const Student& pData);

    /**
     * @brief 在链表头部添加一个学生数据项
     *        Fügt ein neues Studentenelement am Anfang der Liste hinzu
     * @param pData 要添加的学生数据 / Studentendaten, die hinzugefügt werden
     */
    void push_front(const Student& pData);

    /**
     * @brief 移除链表头部的元素
     *        Entfernt das erste Element aus der Liste
     * @note 如果列表为空，则不执行任何操作 / Kein Effekt, wenn die Liste leer ist
     */
    void popFront();

    /**
     * @brief 检查链表是否为空
     *        Prüft, ob die Liste leer ist
     * @return 若为空返回 true / Gibt true zurück, wenn die Liste leer ist
     */
    bool empty() const;

    /**
     * @brief 获取第一个元素中的学生数据（不删除）
     *        Gibt die Daten des ersten Elements zurück (ohne es zu löschen)
     * @return 第一个学生对象 / Student-Objekt am Anfang der Liste
     * @pre 列表不能为空 / Die Liste darf nicht leer sein
     */
    Student dataFront() const;

    /**
     * @brief 从前向后输出整个链表的学生信息
     *        Gibt alle Studentendaten der Liste von vorne nach hinten aus
     */
    void ausgabeVorwaerts() const;

    /**
     * @brief 从后向前输出整个链表的学生信息
     *        Gibt alle Studentendaten der Liste von hinten nach vorne aus
     */
    void ausgabeHinterwaerts() const;

    /**
     * @brief 根据学号查找并删除学生节点
     *        Sucht das Studentenelement anhand der Matrikelnummer und entfernt es
     * @param num 要删除的学生的 Matrikelnummer / Matrikelnummer des zu löschenden Studenten
     * @note 如果未找到，输出提示信息 / Gibt eine Meldung aus, falls nicht gefunden
     */
    void delete_student(int num);

    /**
     * @brief 根据学号查找学生节点
     *        Findet das Studentenelement anhand der Matrikelnummer
     * @param matnum 要查找的 Matrikelnummer / Matrikelnummer des gesuchten Studenten
     * @return 如果找到，返回对应的节点指针 / Zeiger auf das gefundene Listenelement, sonst nullptr
     */
    ListenElement* find_student(int matnum) const;
};

#endif /* LISTE_H_ */
