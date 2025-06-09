#ifndef STATEROAD_H
#define STATEROAD_H

#include "street.h"

/**
 * @class Stateroad
 * @brief Repräsentiert eine Landstraße zwischen zwei Städten
 * @brief Represents a state road between two cities
 * @brief 表示两座城市之间的普通国道（Landstraße）
 */
class Stateroad : public Street
{
public:
    /**
     * @brief Konstruktor für eine Landstraße
     * @brief Constructor for a state road
     * @brief Stateroad 的构造函数
     * @param city1 Erste Stadt
     * @param city1 First city
     * @param city1 第一个城市
     * @param city2 Zweite Stadt
     * @param city2 Second city
     * @param city2 第二个城市
     */
    Stateroad(City* city1, City* city2);

    /**
     * @brief Zeichnet die Landstraße in die Szene
     * @brief Draws the state road into the scene
     * @brief 将普通道路绘制到图形场景中
     * @param scene Zielszene
     * @param scene Target scene
     * @param scene 目标图形场景
     */
    void draw_street(QGraphicsScene& scene) const override;

    /**
     * @brief Gibt die durchschnittliche Geschwindigkeit auf der Landstraße zurück
     * @brief Returns the average speed on the state road
     * @brief 返回国道的平均速度
     * @return Durchschnittsgeschwindigkeit
     * @return Average speed
     * @return 平均速度
     */
    int getAverageSpeed() const override;
};

#endif // STATEROAD_H
