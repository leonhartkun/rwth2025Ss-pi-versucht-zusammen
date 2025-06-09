#include "motorway.h"
#include <QDebug>
#include <QGraphicsScene>

/**
 * @brief Konstruktor der Autobahnklasse.
 * @brief Constructor for the Motorway class.
 * @brief 构造函数：初始化高速公路街道，连接两个城市。
 *
 * @param city1 Startstadt / Starting city / 起点城市
 * @param city2 Zielstadt / Target city / 终点城市
 */
Motorway::Motorway(City* city1, City* city2) : Street(city1, city2) {}

/**
 * @brief Zeichnet die Autobahn in die Szene als dicke schwarze Linie.
 * @brief Draws the motorway as a thick black line in the scene.
 * @brief 在场景中以粗黑线方式绘制高速公路。
 *
 * @param scene Die Zielszene / Target scene / 目标场景
 */
void Motorway::draw_street(QGraphicsScene& scene) const
{
    scene.addLine(start->get_x(), start->get_y(), end->get_x(), end->get_y(), QPen(Qt::black, 3));
}

/**
 * @brief Gibt die durchschnittliche Geschwindigkeit auf der Autobahn zurück.
 * @brief Returns the average speed on the motorway.
 * @brief 返回高速公路的平均速度。
 *
 * @return int Durchschnittsgeschwindigkeit / Average speed / 平均速度
 */
int Motorway::getAverageSpeed() const
{
    qDebug() << "fast";
    return fastspeed;
}
