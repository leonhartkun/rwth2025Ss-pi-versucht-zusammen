//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

/**
 * @file ListenElement.cpp
 * @brief Implementierung der Klasse ListenElement (Knoten einer doppelt verketteten Liste)
 *        链表节点类 ListenElement 的实现文件（用于双向链表）
 */

#include "ListenElement.h"

/**
 * @brief Konstruktor: Initialisiert ein Listenelement mit Studentendaten und Zeigern
 *        构造函数：初始化学生数据和前后指针
 *
 * @param pData Studentendaten / 要存储的学生对象
 * @param pNext Zeiger auf das nächste Element / 指向下一个链表节点的指针
 * @param pPrev Zeiger auf das vorherige Element / 指向上一个链表节点的指针
 */
ListenElement::ListenElement(Student pData, ListenElement* pNext, ListenElement* pPrev)
    : data(pData), next(pNext), prev(pPrev)
{
}

/**
 * @brief Setzt neue Studentendaten in das Element
 *        设置当前节点的学生数据
 *
 * @param pData Neue Studentendaten / 新的学生对象
 */
void ListenElement::setData(Student pData)
{
    data = pData;
}

/**
 * @brief Setzt den Zeiger auf das nächste Element
 *        设置指向下一个节点的指针
 *
 * @param pNext Nächstes Listenelement / 下一个节点指针
 */
void ListenElement::setNext(ListenElement* pNext)
{
    next = pNext;
}

/**
 * @brief Setzt den Zeiger auf das vorherige Element
 *        设置指向上一个节点的指针
 *
 * @param pPrev Vorheriges Listenelement / 上一个节点指针
 */
void ListenElement::setPrev(ListenElement* pPrev)
{
    prev = pPrev;
}

/**
 * @brief Gibt die gespeicherten Studentendaten zurück
 *        获取当前节点中的学生数据
 *
 * @return Studentendaten / 学生对象的副本
 */
Student ListenElement::getData() const
{
    return data;
}

/**
 * @brief Gibt den Zeiger auf das nächste Element zurück
 *        获取指向下一个节点的指针
 *
 * @return Zeiger auf Nachfolger / 后继节点的指针
 */
ListenElement* ListenElement::getNext() const
{
    return next;
}

/**
 * @brief Gibt den Zeiger auf das vorherige Element zurück
 *        获取指向上一个节点的指针
 *
 * @return Zeiger auf Vorgänger / 前驱节点的指针
 */
ListenElement* ListenElement::getPrev() const
{
    return prev;
}
