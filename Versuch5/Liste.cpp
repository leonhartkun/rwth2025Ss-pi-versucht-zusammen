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
 * @brief Fügt ein neues Listenelement am Ende der Liste hinzu.
 *        在链表末尾添加一个新节点。
 *
 * @param pData Das Student-Objekt, das eingefügt werden soll.
 *              要插入的 Student 对象。
 */
void Liste::pushBack(const Student& pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);
    if (front == nullptr) /**< Liste ist leer / 链表为空 */
    {
        front = back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);   /**< Verknüpfe altes Ende mit neuem Element / 将原尾节点与新节点连接 */
        neuesElement->setPrev(back);   /**< Verknüpfe neues Element zurück auf altes Ende / 将新节点的 prev 指向原尾节点 */
        back = neuesElement;           /**< Aktualisiere back-Zeiger / 更新尾指针 */
    }
}

/**
 * @brief Entfernt das erste Element der Liste (von vorne).
 *        移除链表头部的第一个元素。
 *
 * @note Wenn die Liste leer ist, passiert nichts.
 *       如果链表为空，则不做任何操作。
 */
void Liste::popFront()
{
    if (front == nullptr)
        return;

    ListenElement* cursor = front;
    if (front == back) /**< Nur ein Element vorhanden / 只有一个节点 */
    {
        delete front;
        front = back = nullptr;
    }
    else
    {
        front = front->getNext();      /**< Bewege front zum nächsten Element / 将头指针移至下一个节点 */
        front->setPrev(nullptr);       /**< Entferne prev-Verknüpfung / 断开新头节点的 prev */
        delete cursor;                 /**< Lösche altes erstes Element / 删除原头节点 */
    }
}

/**
 * @brief Prüft, ob die Liste leer ist.
 *        检查链表是否为空。
 *
 * @return true, falls leer; sonst false.
 *         若为空返回 true，否则返回 false。
 */
bool Liste::empty() const
{
    return front == nullptr;
}

/**
 * @brief Liefert die Daten des ersten Elements der Liste.
 *        获取链表头部第一个元素的数据。
 *
 * @return Student-Objekt am Anfang der Liste, oder Standardobjekt bei leerer Liste.
 *         返回列表最前端的 Student 对象；若链表为空则返回默认构造的对象。
 */
Student Liste::dataFront() const
{
    if (front)
        return front->getData();
    else
        return Student(); /**< Alternativ könnte eine Exception geworfen werden / 也可抛出异常 */
}

/**
 * @brief Gibt alle Studentendaten von vorne nach hinten aus.
 *        从头到尾输出链表中所有学生的信息。
 */
void Liste::ausgabeVorwaerts() const
{
    for (ListenElement* cur = front; cur; cur = cur->getNext())
    {
        cur->getData().ausgabe(); /**< Ausgabe jedes Studenten / 输出每个学生 */
    }
}

/**
 * @brief Gibt alle Studentendaten von hinten nach vorne aus.
 *        从尾到头输出链表中所有学生的信息。
 */
void Liste::ausgabeHinterwaerts() const
{
    for (ListenElement* cur = back; cur; cur = cur->getPrev())
    {
        cur->getData().ausgabe(); /**< Ausgabe jedes Studenten / 输出每个学生 */
    }
}

/**
 * @brief Sucht einen Studenten anhand der Matrikelnummer und entfernt ihn.
 *        根据学号查找并删除学生节点。
 *
 * @param num Matrikelnummer des zu löschenden Studenten.
 *            要删除学生的学号。
 *
 * @note Gibt eine Warnung aus, falls die Matrikelnummer nicht gefunden wurde.
 *       如果未找到指定学号，则输出警告信息。
 */
void Liste::delete_student(int num)
{
    ListenElement* node = find_student(num);
    if (!node)
    {
        std::cout << "⚠️ Matrikelnummer " << num << " nicht gefunden!" << std::endl;
        return;
    }

    Student s = node->getData();
    // Verknüpfe Vorgänger und Nachfolger neu / 重新连接前后节点
    if (node->getPrev())
        node->getPrev()->setNext(node->getNext());
    else
        front = node->getNext();

    if (node->getNext())
        node->getNext()->setPrev(node->getPrev());
    else
        back = node->getPrev();

    delete node; /**< Entferne das Element physisch / 物理删除节点 */

    std::cout << "Student gelöscht:" << std::endl;
    s.ausgabe(); /**< Ausgabe der gelöschten Daten / 输出被删除的学生信息 */
}

/**
 * @brief Findet einen Studenten anhand der Matrikelnummer.
 *        根据学号查找学生节点。
 *
 * @param matnum Matrikelnummer des zu suchenden Studenten.
 *               要查找学生的学号。
 * @return Zeiger auf das gefundene Listenelement, oder nullptr.
 *         返回指向找到的节点的指针；若未找到则返回 nullptr。
 */
ListenElement* Liste::find_student(int matnum) const
{
    for (ListenElement* cur = front; cur; cur = cur->getNext())
    {
        if (cur->getData().getMatNr() == matnum)
            return cur;
    }
    std::cout<<"n"<<std::endl;
    return nullptr;

}

/**
 * @brief Fügt ein neues Listenelement am Anfang der Liste hinzu.
 *        在链表头部添加一个新节点。
 *
 * @param pData Das Student-Objekt, das eingefügt werden soll.
 *              要插入的 Student 对象。
 */
void Liste::push_front(const Student& pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr, nullptr);
    if (front == nullptr) /**< Liste ist leer / 链表为空 */
    {
        front = back = neuesElement;
    }
    else
    {
        neuesElement->setNext(front); /**< Verknüpfe neues Element mit altem ersten Element / 将新节点的 next 指向原头节点 */
        front->setPrev(neuesElement); /**< Verknüpfe altes erstes Element zurück auf neues Element / 将原头节点的 prev 指向新节点 */
        front = neuesElement;        /**< Aktualisiere front-Zeiger / 更新头指针 */
    }
}