#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>

/**
 * @class City
 * @brief Repräsentiert eine allgemeine Stadt mit Position und Name
 * @brief Represents a general city with position and name
 * @brief 表示具有名称和坐标的一般城市类
 */
class City
{
protected:
    /**
     * @brief Name der Stadt
     * @brief Name of the city
     * @brief 城市名称
     */
    QString name;

    /**
     * @brief X-Koordinate der Stadt
     * @brief X coordinate of the city
     * @brief 城市的 X 坐标
     */
    int x;

    /**
     * @brief Y-Koordinate der Stadt
     * @brief Y coordinate of the city
     * @brief 城市的 Y 坐标
     */
    int y;

public:
    /**
     * @brief Konstruktor für City
     * @brief Constructor for City
     * @brief City 的构造函数
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
    City(QString name, int x, int y);

    /**
     * @brief Zeichnet die Stadt auf eine Szene (kann überschrieben werden)
     * @brief Draws the city onto a scene (can be overridden)
     * @brief 将城市绘制到图形场景中（可重写）
     * @param scene Die QGraphicsScene zur Darstellung
     * @param scene The QGraphicsScene for rendering
     * @param scene 用于显示的 QGraphicsScene
     */
    virtual void draw(QGraphicsScene& scene) const;

    /**
     * @brief Gibt den Namen der Stadt zurück
     * @brief Returns the name of the city
     * @brief 返回城市名称
     * @return Stadtname
     * @return City name
     * @return 城市名称
     */
    QString getname();

    /**
     * @brief Gibt die X-Koordinate zurück
     * @brief Returns the X coordinate
     * @brief 返回 X 坐标
     * @return X-Koordinate
     * @return X coordinate
     * @return X 坐标
     */
    int get_x();

    /**
     * @brief Gibt die Y-Koordinate zurück
     * @brief Returns the Y coordinate
     * @brief 返回 Y 坐标
     * @return Y-Koordinate
     * @return Y coordinate
     * @return Y 坐标
     */
    int get_y();
};

#endif // CITY_H
