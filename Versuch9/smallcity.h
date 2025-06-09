#ifndef SMALLCITY_H
#define SMALLCITY_H

#include "city.h"

/**
 * @class SmallCity
 * @brief Repräsentiert eine kleine Stadt auf der Karte
 * @brief Represents a small city on the map
 * @brief 表示地图上的一个小城市
 */
class SmallCity : public City
{
public:
    /**
     * @brief Konstruktor für SmallCity
     * @brief Constructor for SmallCity
     * @brief SmallCity 的构造函数
     * @param name Name der Stadt
     * @param name Name of the city
     * @param name 城市名称
     * @param x X-Koordinate der Stadt
     * @param x X coordinate of the city
     * @param x 城市的 X 坐标
     * @param y Y-Koordinate der Stadt
     * @param y Y coordinate of the city
     * @param y 城市的 Y 坐标
     */
    SmallCity(QString name, int x, int y);

    /**
     * @brief Zeichnet die Stadt als kleine Stadt in die Szene
     * @brief Draws the city as a small city into the scene
     * @brief 将城市以“小城市”样式绘制到图形场景中
     * @param scene Zielszene zur Darstellung
     * @param scene Target scene for rendering
     * @param scene 用于绘图的目标场景
     */
    void draw(QGraphicsScene& scene) const override;
};

#endif // SMALLCITY_H
