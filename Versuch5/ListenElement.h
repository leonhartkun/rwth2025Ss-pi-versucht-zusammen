//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

/**
 * @class ListenElement
 * @brief 链表中的一个节点，包含学生数据和指向下一个节点的指针。
 *        Ein Listenelement mit Studentendaten und einem Zeiger auf das nächste Element.
 */
class ListenElement
{
private:
    Student data;                ///< 学生数据 / Studentendaten
    ListenElement* next;        ///< 指向下一个节点的指针 / Zeiger auf das nächste Listenelement
    ListenElement* prev;        ///< 指向前一个节点的指针 / Zeiger auf das Vorgänge Listenelement

public:
    /**
     * @brief 构造函数，初始化数据和指针
     *        Konstruktor zur Initialisierung von Daten und Zeiger
     * @param pData 学生数据 / Studentendaten
     * @param pNext 指向下一个元素的指针 / Zeiger auf das nächste Element
     * @param pPrev 指向前一个元素的指针 / Zeiger auf das Vorgänge Element
     */
    ListenElement(Student pData, ListenElement* pNext, ListenElement* pPrev);

    /**
     * @brief 设置学生数据 / Setzt die Studentendaten
     * @param pData 新的数据 / Neue Daten
     */
    void setData(Student pData);

    /**
     * @brief 设置指向下一个节点的指针 / Setzt den Zeiger auf das nächste Element
     * @param pNext 下一个节点 / Nächstes Element
     */
    void setNext(ListenElement* pNext);

    /**
     * @brief 设置指向上一个节点的指针
     * @param pPrev
     */
    void setPrev(ListenElement* pPrev);

    /**
     * @brief 获取当前存储的学生数据 / Gibt die gespeicherten Studentendaten zurück
     * @return 学生数据 / Student
     */
    Student getData() const;

    /**
     * @brief 获取指向下一个节点的指针 / Gibt den Zeiger auf das nächste Element zurück
     * @return 下一个节点指针 / Zeiger auf nächstes Listenelement
     */
    ListenElement* getNext() const;

    /**
     *
     * @brief 获取指向下一个节点的指针 / Gibt den Zeiger auf das vorgänge Element zurück
     * @return 下一个节点指针 / Zeiger auf vorgänges Listenelment
     */
    ListenElement* getPrev() const;  //

};

#endif // _LISTENELEMENT_H_
