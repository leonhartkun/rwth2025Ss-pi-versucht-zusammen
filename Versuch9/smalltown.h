#ifndef SMALLTOWN_H
#define SMALLTOWN_H

#include "city.h"

/**
 * @class SmallTown
 * @brief Repräsentiert eine mittelgroße Stadt auf der Karte
 * @brief Represents a medium-sized town on the map
 * @brief 表示地图上的一个中等规模的城市
 */
class SmallTown : public City
{
public:
    /**
     * @brief Konstruktor für SmallTown
     * @brief Constructor for SmallTown
     * @brief SmallTown 的构造函数
     * @param name Name der Stadt
     * @param name Name of the town
     * @param name 城市名称
     * @param x X-Koordinate der Stadt
     * @param x X coordinate of the town
     * @param x 城市的 X 坐标
     * @param y Y-Koordinate der Stadt
     * @param y Y coordinate of the town
     * @param y 城市的 Y 坐标
     */
    SmallTown(QString name, int x, int y);

    /**
     * @brief Zeichnet die Stadt als mittelgroße Stadt in die Szene
     * @brief Draws the town as a medium-sized town into the scene
     * @brief 将城市以“中等城市”样式绘制到图形场景中
     * @param scene Zielszene zur Darstellung
     * @param scene Target scene for rendering
     * @param scene 用于绘图的目标场景
     */
    void draw(QGraphicsScene& scene) const override;
};

#endif // SMALLTOWN_H
