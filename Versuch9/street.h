#ifndef STREET_H
#define STREET_H

#include "city.h"

/**
 * @class Street
 * @brief Repräsentiert eine allgemeine Straße zwischen zwei Städten
 * @brief Represents a general street between two cities
 * @brief 表示两座城市之间的一般街道
 */
class Street
{
protected:
    /**
     * @brief Startstadt der Straße
     * @brief Starting city of the street
     * @brief 街道的起点城市
     */
    City* start;

    /**
     * @brief Zielstadt der Straße
     * @brief Ending city of the street
     * @brief 街道的终点城市
     */
    City* end;

    /**
     * @brief Fiktive hohe Geschwindigkeit (z. B. für Testzwecke)
     * @brief Fictional high speed (e.g. for testing)
     * @brief 虚拟高速值（例如用于测试）
     */
    int fastspeed = 1030;

    /**
     * @brief Normale Geschwindigkeit
     * @brief Normal speed
     * @brief 正常速度值
     */
    int slowspeed = 50;

public:
    /**
     * @brief Konstruktor für eine Straße zwischen zwei Städten
     * @brief Constructor for a street between two cities
     * @brief 创建一条连接两个城市的街道的构造函数
     * @param city1 Erste Stadt
     * @param city1 First city
     * @param city1 第一个城市
     * @param city2 Zweite Stadt
     * @param city2 Second city
     * @param city2 第二个城市
     */
    Street(City* city1, City* city2);

    /**
     * @brief Zeichnet die Straße in Schwarz
     * @brief Draws the street in black
     * @brief 以黑色绘制街道
     * @param scene Zielszene
     * @param scene Target scene
     * @param scene 目标图形场景
     */
    virtual void draw_street(QGraphicsScene& scene) const;

    /**
     * @brief Zeichnet die Straße in Rot
     * @brief Draws the street in red
     * @brief 以红色绘制街道
     * @param scene Zielszene
     * @param scene Target scene
     * @param scene 目标图形场景
     */
    void draw_red_street(QGraphicsScene& scene) const;

    /**
     * @brief Gibt die Startstadt zurück
     * @brief Returns the starting city
     * @brief 返回街道起点城市
     * @return Zeiger auf die Startstadt
     * @return Pointer to the starting city
     * @return 起点城市的指针
     */
    City* get_start() const;

    /**
     * @brief Gibt die Zielstadt zurück
     * @brief Returns the ending city
     * @brief 返回街道终点城市
     * @return Zeiger auf die Zielstadt
     * @return Pointer to the ending city
     * @return 终点城市的指针
     */
    City* get_end() const;

    /**
     * @brief Zeichnet die Straße in Blau
     * @brief Draws the street in blue
     * @brief 以蓝色绘制街道
     * @param scene Zielszene
     * @param scene Target scene
     * @param scene 目标图形场景
     */
    void draw_blue_street(QGraphicsScene& scene) const;

    /**
     * @brief Berechnet die Länge der Straße (euklidischer Abstand)
     * @brief Calculates the length of the street (Euclidean distance)
     * @brief 计算街道的长度（欧几里得距离）
     * @return Länge der Straße
     * @return Length of the street
     * @return 街道长度
     */
    double getLength() const;

    /**
     * @brief Gibt die durchschnittliche Geschwindigkeit auf dieser Straße zurück
     * @brief Returns the average speed on this street
     * @brief 返回该街道的平均速度
     * @return Durchschnittsgeschwindigkeit
     * @return Average speed
     * @return 平均速度
     */
    virtual int getAverageSpeed() const;
};

#endif // STREET_H
