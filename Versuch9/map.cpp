#include "map.h"
#include <cmath>
#include <QDebug>
/**
 * @brief Standardkonstruktor der Karte
 * @brief Default constructor for the map
 * @brief 地图类的默认构造函数
 */
Map::Map() {}

/**
 * @brief Fügt eine Stadt zur internen Liste hinzu
 * @brief Add a city to the internal list
 * @brief 向内部城市列表添加一个城市
 */
void Map::addCity(City* city)
{
    cities.append(city);
    qDebug()<<"add city";
}

/**
 * @brief Zeichnet alle Städte und Straßen
 * @brief Draws all cities and streets
 * @brief 绘制所有城市与街道
 */
void Map::draw(QGraphicsScene& scene) const
{
    for (auto it = cities.begin(); it != cities.end(); ++it)
    {
        (*it)->draw(scene);
    }
    for (auto it = streets.begin(); it != streets.end(); ++it)
    {
        (*it)->draw_street(scene);
    }
}

void Map::draw_city(QGraphicsScene& scene) const
{
    for (auto it = cities.begin(); it != cities.end(); ++it)
    {
        (*it)->draw(scene);
    }
}

void Map::draw_street(QGraphicsScene& scene) const
{
    for (auto it = streets.begin(); it != streets.end(); ++it)
    {
        (*it)->draw_street(scene);
    }
}
/**
 * @brief Sucht eine Stadt nach ihrem Namen
 * @brief Searches for a city by its name
 * @brief 根据名称查找城市
 */
City* Map::findCity(const QString cityname) const
{
    qDebug()<<"find city"<< cityname;
    for (City* city : cities) {
        if (city->getname() == cityname) {
            qDebug() << "find the city" << cityname;
            return city;
        }
    }

    return nullptr;
}

/**
 * @brief Fügt eine Straße hinzu, wenn beide Städte existieren
 * @brief Add a street if both cities exist
 * @brief 若起止城市都存在，则添加街道
 */
bool Map::addStreet(Street* s) {
    if (!cities.contains(s->get_start()) || !cities.contains(s->get_end())) {
        qDebug() << "Street rejected: one or both cities not in the map.";
        return false;
    }
    streets.append(s);
    return true;
}

/**
 * @brief Gibt alle Straßen (derzeit ohne Filter) zurück
 * @brief Returns all streets (currently unfiltered)
 * @brief 返回所有街道（当前未过滤）
 */
QVector<Street*> Map::getStreetList(const City* city) const{
    return streets;
}

/**
 * @brief Liefert die gegenüberliegende Stadt einer Straße
 * @brief Returns the opposite city of a given street
 * @brief 返回街道另一端的城市
 */
City* Map::getOppositeCity(const Street* street, const City* city) const{
    City* city1 = street->get_start();
    City* city2 = street->get_end();

    if (city == city1) return city2;
    if (city == city2) return city1;

    return nullptr;
}

/**
 * @brief Gibt die Länge oder Zeitkosten einer Straße zurück
 * @brief Returns the distance or time cost of a street
 * @brief 返回街道的长度或耗时（取决于模式）
 */
double Map::getLength(const Street* street) const{
    City* city1 = street->get_start();
    City* city2 = street->get_end();

    if (cost_mode == CostMode::Length)
        return street->getLength();
    else
        return street->getLength() / street->getAverageSpeed();
}

/**
 * @brief Löscht alle Städte und Straßen
 * @brief Deletes all cities and streets
 * @brief 清空所有城市与街道
 */
void Map::clear(){
    for (Street* street : streets)
    {
        delete street;
    }
    streets.clear();
    for (City* city : cities)
    {
        delete city;
    }
    cities.clear();
}

/**
 * @brief Gibt die aktuelle Stadtliste zurück
 * @brief Returns the current list of cities
 * @brief 返回当前城市列表
 */
QVector<City*> Map::get_city_list() const{
    return cities;
}

/**
 * @brief Setzt das Kostenkriterium (Länge oder Zeit)
 * @brief Sets the cost mode (distance or time)
 * @brief 设置代价模式（长度或时间）
 */
void Map::set_cost_mode(CostMode mode)
{
    cost_mode = mode;
}
