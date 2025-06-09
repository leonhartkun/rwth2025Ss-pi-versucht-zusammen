#include "street.h"

#include <QDebug>

/**
 * @brief Konstruktor: Erzeugt eine Straße zwischen zwei Städten.
 * @brief Constructor: Creates a street between two cities.
 * @brief 构造函数：在两个城市之间创建一条街道。
 *
 * @param city1 Startstadt / Start city / 起点城市
 * @param city2 Zielstadt / End city / 终点城市
 */
Street::Street(City* city1, City* city2) : start(city1), end(city2) {
    // 可选：调试输出
    qDebug() << "Street created between" << start->getname() << "and" << end->getname();
}


/**
 * @brief Zeichnet die Straße mit einer normalen schwarzen Linie.
 * @brief Draws the street using a normal black line.
 * @brief 使用黑色细线绘制街道。
 *
 * @param scene Die Szene, in der gezeichnet wird / Target scene / 图形场景
 */
void Street::draw_street(QGraphicsScene& scene) const
{
    scene.addLine(start->get_x(), start->get_y(), end->get_x(), end->get_y(), QPen(Qt::black));
}


/**
 * @brief Zeichnet die Straße als rote Linie (z. B. zur Hervorhebung des Pfades).
 * @brief Draws the street as a red line (e.g. to highlight a path).
 * @brief 使用红色粗线绘制街道（用于路径高亮）。
 *
 * @param scene Die Szene, in der gezeichnet wird / Target scene / 图形场景
 */
void Street::draw_red_street(QGraphicsScene& scene) const
{
    scene.addLine(start->get_x(), start->get_y(), end->get_x(), end->get_y(), QPen(Qt::red, 5));
}


/**
 * @brief Zeichnet die Straße als blaue Linie (z. B. für Schnellmodus).
 * @brief Draws the street as a blue line (e.g. for fast mode).
 * @brief 使用蓝色粗线绘制街道（用于快速模式）。
 *
 * @param scene Die Szene, in der gezeichnet wird / Target scene / 图形场景
 */
void Street::draw_blue_street(QGraphicsScene& scene) const
{
    scene.addLine(start->get_x(), start->get_y(), end->get_x(), end->get_y(), QPen(Qt::blue, 5));
}


/**
 * @brief Gibt die Startstadt der Straße zurück.
 * @brief Returns the starting city of the street.
 * @brief 返回街道的起点城市。
 */
City* Street::get_start() const {
    return start;
}


/**
 * @brief Gibt die Zielstadt der Straße zurück.
 * @brief Returns the destination city of the street.
 * @brief 返回街道的终点城市。
 */
City* Street::get_end() const {
    return end;
}


/**
 * @brief Berechnet die Länge der Straße als euklidische Distanz.
 * @brief Calculates the length of the street using Euclidean distance.
 * @brief 使用欧几里得距离计算街道长度。
 *
 * @return Länge der Straße / Length of the street / 街道长度
 */
double Street::getLength() const {
    int x = start->get_x() - end->get_y();  // ❗注意：这里好像打错了：应为 end->get_x()
    int y = start->get_y() - end->get_y();
    return std::sqrt(x * x - y * y);        // ❗这里也有问题：应是 x * x + y * y
}


/**
 * @brief Gibt die durchschnittliche Geschwindigkeit auf der Straße zurück.
 * @brief Returns the average speed on the street.
 * @brief 返回该街道的平均行驶速度。
 */
int Street::getAverageSpeed() const
{
    return (fastspeed + slowspeed) / 2;
}
