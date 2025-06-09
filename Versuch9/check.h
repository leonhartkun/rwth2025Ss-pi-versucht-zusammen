#ifndef CHECK_H
#define CHECK_H

#include <QString>
#include "map.h"

/**
 * @class check
 * @brief Stellt statische Validierungsfunktionen für Städte und Straßen bereit
 * @brief Provides static validation functions for cities and streets
 * @brief 提供城市和街道的静态验证函数
 */
class check
{
public:
    /**
     * @brief Konstruktor ist gelöscht, da nur statische Methoden verwendet werden
     * @brief Constructor is deleted since only static methods are used
     * @brief 构造函数被禁用，因为只使用静态方法
     */
    check() = delete;

    /**
     * @brief Überprüft, ob eine Straße zwischen zwei Städten gültig hinzugefügt werden kann
     * @brief Checks whether a street between two cities can be validly added
     * @brief 检查两个城市之间是否可以合法添加一条街道
     * @param map Zeiger auf die aktuelle Karte
     * @param map Pointer to the current map
     * @param map 当前地图的指针
     * @param city_from Name der Startstadt
     * @param city_from Name of the starting city
     * @param city_from 起点城市的名称
     * @param city_to Name der Zielstadt
     * @param city_to Name of the destination city
     * @param city_to 终点城市的名称
     * @return true, wenn gültig; sonst false
     * @return true if valid, false otherwise
     * @return 若合法则返回 true，否则返回 false
     */
    static bool check_street(Map* map, const QString city_from, const QString city_to);

    /**
     * @brief Überprüft, ob eine Stadt mit den gegebenen Parametern gültig ist
     * @brief Checks whether a city with the given parameters is valid
     * @brief 检查具有给定参数的城市是否合法
     * @param cityname Name der Stadt
     * @param cityname Name of the city
     * @param cityname 城市名称
     * @param x X-Koordinate als Zeichenkette
     * @param x X coordinate as string
     * @param x 字符串形式的X坐标
     * @param y Y-Koordinate als Zeichenkette
     * @param y Y coordinate as string
     * @param y 字符串形式的Y坐标
     * @return true, wenn gültig; sonst false
     * @return true if valid, false otherwise
     * @return 若合法则返回 true，否则返回 false
     */
    static bool check_city(const QString& cityname, const QString& x, const QString& y);
};

#endif // CHECK_H
