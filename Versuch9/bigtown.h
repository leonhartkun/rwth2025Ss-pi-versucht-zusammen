#ifndef BIGTOWN_H
#define BIGTOWN_H

#include "city.h"
#include <QString>
#include <QGraphicsScene>

/**
 * @class BigTown
 * @brief Repräsentiert eine größere Stadt, die auf einer Karte gezeichnet werden kann
 * @brief Represents a larger city that can be drawn on a map
 * @brief 表示地图上可以绘制的大城市
 */
class BigTown : public City
{
public:
    /**
     * @brief Konstruktor für BigTown
     * @brief Constructor for BigTown
     * @brief BigTown 的构造函数
     * @param name Name der Stadt
     * @param name Name of the city
     * @param name 城市名称
     * @param x X-Koordinate
     * @param x X coordinate
     * @param x X 坐标
     * @param y Y-Koordinate
     * @param y Y coordinate
     * @param y Y 坐标
     */
    BigTown(QString name, int x, int y);

    /**
     * @brief Zeichnet die Stadt auf die gegebene Szene
     * @brief Draws the city onto the given scene
     * @brief 将城市绘制到给定的图形场景中
     * @param scene Die QGraphicsScene, auf der die Stadt gezeichnet wird
     * @param scene The QGraphicsScene on which the city will be drawn
     * @param scene 要绘制城市的 QGraphicsScene 场景
     */
    void draw(QGraphicsScene& scene) const override;
};

#endif // BIGTOWN_H
