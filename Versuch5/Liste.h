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
    void pushBack(Student pData);

    /**
     * @brief 移除链表头部的元素
     *        Entfernt das erste Element aus der Liste
     */
    void popFront();

    /**
     * @brief 检查链表是否为空
     *        Prüft, ob die Liste leer ist
     * @return 若为空返回 true / Gibt true zurück, wenn die Liste leer ist
     */
    bool empty();

    /**
     * @brief 获取第一个元素中的学生数据（不删除）
     *        Gibt die Daten des ersten Elements zurück (ohne es zu löschen)
     * @return 第一个学生对象 / Student-Objekt am Anfang der Liste
     */
    Student dataFront();

    /**
     * @brief 从前向后输出整个链表的学生信息
     *        Gibt alle Studentendaten der Liste von vorne nach hinten aus
     */
    void ausgabeVorwaerts() const;
    /**
     * @brief 从后向前输出整个链表的学生信息
     *        Gibt alle Studentendaten der Liste von hinter nach vorne aus
     */
    void ausgabeHinterwaerts() const;
};

#endif /*LISTE_H_*/
