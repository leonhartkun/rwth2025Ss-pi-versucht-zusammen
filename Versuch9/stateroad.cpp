#include "stateroad.h"
#include <QDebug>
#include <QGraphicsScene>

/**
 * @brief Konstruktor für eine Landstraße, leitet an die Basisklasse Street weiter.
 * @brief Constructor for a state road, forwards to the base class Street.
 * @brief 州道构造函数，参数传递给基类 Street。
 *
 * @param city1 Erste Stadt / First city / 起点城市
 * @param city2 Zweite Stadt / Second city / 终点城市
 */
Stateroad::Stateroad(City* city1, City* city2) : Street(city1, city2) {}


/**
 * @brief Zeichnet die Straße in die Szene ein (dünne schwarze Linie).
 * @brief Draws the street into the scene (thin black line).
 * @brief 将该州道绘制到图形场景中（细黑线）。
 *
 * @param scene Die Zielszene / Target scene / 图形目标场景
 */
void Stateroad::draw_street(QGraphicsScene& scene) const
{
    scene.addLine(start->get_x(), start->get_y(), end->get_x(), end->get_y(), QPen(Qt::black, 1));
}


/**
 * @brief Gibt die durchschnittliche Geschwindigkeit dieser Straße zurück.
 * @brief Returns the average speed for this street.
 * @brief 返回该州道的平均行驶速度。
 *
 * @return Durchschnittsgeschwindigkeit / Average speed / 平均速度
 */
int Stateroad::getAverageSpeed() const
{
    qDebug() << "slow";
    return slowspeed;
}
