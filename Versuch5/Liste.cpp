//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor: Erzeugt eine leere doppelt verkettete Liste.
 *        默认构造函数：创建一个空的双向链表。
 */
Liste::Liste() : front(nullptr), back(nullptr)
{
}

/**
 * @brief Fügt ein neues Listenelement am Ende der Liste hinzu. / 在链表末尾添加一个新节点。
 *
 * @param pData Ein Objekt vom Typ Student, das eingefügt werden soll. / 要插入的 Student 对象。
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);
    if (front == nullptr) // Liste ist leer / 链表为空
    {
        front = back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);     // 原尾节点的 next 指向新节点
        neuesElement->setPrev(back);     // 新节点的 prev 指向原尾节点
        back = neuesElement;             // 更新尾指针
    }

}

/**
 * @brief Entfernt das erste Element der Liste (von vorne). / 移除链表头部的第一个元素。
 */
void Liste::popFront()
{
    if (front == nullptr)
        return; // Liste ist bereits leer / 链表已空

    ListenElement* cursor = front;

    if (front == back) // Nur ein Element vorhanden / 只有一个元素
    {
        delete front;
        front = back = nullptr;
    }
    else
    {
        front = front->getNext();       // 移动头指针
        front->setPrev(nullptr);        // 设置新头节点的 prev 为 nullptr
        delete cursor;                  // 删除原头节点
    }
}

/**
 * @brief Prüft, ob die Liste leer ist. / 检查链表是否为空。
 *
 * @return true, falls leer, sonst false. / 若为空则返回 true，否则返回 false。
 */
bool Liste::empty()
{
    return front == nullptr;
}

/**
 * @brief Liefert die Daten des ersten Elements in der Liste. / 获取链表头部第一个元素的数据。
 *
 * @return Ein Objekt vom Typ Student. Falls die Liste leer ist, wird ein Standardobjekt zurückgegeben. / 返回 Student 类型对象；若链表为空，则返回默认对象。
 */
Student Liste::dataFront()
{
    if (front != nullptr)
        return front->getData();
    else
        return Student(); // 或可抛出异常 / 或者返回空对象
}

/**
 * @brief Gibt die Liste vom ersten bis zum letzten Element aus. / 从前向后输出链表中所有元素的数据。
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}
