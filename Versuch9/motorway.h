#ifndef MOTORWAY_H
#define MOTORWAY_H

#include "street.h"

/**
 * @class Motorway
 * @brief Repräsentiert eine Autobahn zwischen zwei Städten
 * @brief Represents a motorway between two cities
 * @brief 表示两座城市之间的高速公路
 */
class Motorway : public Street
{
public:
    /**
     * @brief Konstruktor für eine Autobahn
     * @brief Constructor for a motorway
     * @brief 高速公路的构造函数
     * @param city1 Erste Stadt
     * @param city1 First city
     * @param city1 第一个城市
     * @param city2 Zweite Stadt
     * @param city2 Second city
     * @param city2 第二个城市
     */
    Motorway(City* city1, City* city2);

    /**
     * @brief Zeichnet die Autobahn in die Szene
     * @brief Draws the motorway into the scene
     * @brief 将高速公路绘制到图形场景中
     * @param scene Zielszene
     * @param scene Target scene
     * @param scene 目标场景
     */
    void draw_street(QGraphicsScene& scene) const override;

    /**
     * @brief Gibt die durchschnittliche Geschwindigkeit auf der Autobahn zurück
     * @brief Returns the average speed on the motorway
     * @brief 返回高速公路的平均速度
     * @return Durchschnittsgeschwindigkeit
     * @return Average speed
     * @return 平均速度
     */
    int getAverageSpeed() const override;
};

#endif // MOTORWAY_H
