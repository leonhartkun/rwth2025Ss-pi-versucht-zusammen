#ifndef MAP_H
#define MAP_H

#include "abstractmap.h"
#include "city.h"
#include "street.h"

/**
 * @class Map
 * @brief Konkrete Implementierung einer Karte mit Städten und Straßen
 * @brief Concrete implementation of a map with cities and streets
 * @brief 含城市与街道的地图类具体实现
 */
class Map : public AbstractMap
{
private:
    /**
     * @brief Liste der Städte auf der Karte
     * @brief List of cities on the map
     * @brief 地图中的城市列表
     */
    QVector<City*> cities;

    /**
     * @brief Liste der Straßen auf der Karte
     * @brief List of streets on the map
     * @brief 地图中的街道列表
     */
    QVector<Street*> streets;

public:
    /**
     * @brief Konstruktor
     * @brief Constructor
     * @brief 构造函数
     */
    Map();

    /**
     * @brief Fügt eine Stadt zur Karte hinzu
     * @brief Adds a city to the map
     * @brief 向地图添加一个城市
     * @param city Zeiger auf das hinzuzufügende Stadtobjekt
     * @param city Pointer to the city object to add
     * @param city 要添加的城市对象指针
     */
    void addCity(City* city) override;

    /**
     * @brief Zeichnet die Karte mit allen Städten und Straßen
     * @brief Draws the map including all cities and streets
     * @brief 绘制包括所有城市和街道的地图
     * @param scene Zielszene für die Darstellung
     * @param scene Target scene for rendering
     * @param scene 用于绘图的目标场景
     */
    void draw(QGraphicsScene& scene) const;

    /**
     * @brief Fügt eine Straße zur Karte hinzu
     * @brief Adds a street to the map
     * @brief 向地图添加一条街道
     * @param street Zeiger auf die Straße
     * @param street Pointer to the street
     * @param street 要添加的街道指针
     * @return true bei Erfolg, false bei Fehler
     * @return true if successful, false if failed
     * @return 成功返回 true，否则返回 false
     */
    bool addStreet(Street* street) override;

    /**
     * @brief Findet eine Stadt anhand ihres Namens
     * @brief Finds a city by its name
     * @brief 根据城市名称查找城市
     * @param cityname Name der gesuchten Stadt
     * @param cityname Name of the city to search for
     * @param cityname 要查找的城市名称
     * @return Zeiger auf die Stadt oder nullptr, wenn nicht gefunden
     * @return Pointer to the city or nullptr if not found
     * @return 若找到则返回城市指针，否则返回 nullptr
     */
    City* findCity(const QString cityname) const override;

    /**
     * @brief Gibt die Liste aller mit der Stadt verbundenen Straßen zurück
     * @brief Returns the list of all streets connected to the city
     * @brief 返回与指定城市相连的所有街道
     * @param city Zeiger auf die Stadt
     * @param city Pointer to the city
     * @param city 要查询的城市指针
     * @return Liste der Straßen
     * @return List of streets
     * @return 街道列表
     */
    QVector<Street*> getStreetList(const City* city) const override;

    /**
     * @brief Gibt die gegenüberliegende Stadt einer Straße zurück
     * @brief Returns the opposite city of a street
     * @brief 返回一条街道的对向城市
     * @param street Zeiger auf die Straße
     * @param street Pointer to the street
     * @param street 街道指针
     * @param city Aktuelle Stadt
     * @param city Current city
     * @param city 当前城市
     * @return Zeiger auf die gegenüberliegende Stadt oder nullptr
     * @return Pointer to the opposite city or nullptr
     * @return 对向城市的指针或 nullptr
     */
    City* getOppositeCity(const Street* street, const City* city) const override;

    /**
     * @brief Berechnet die Länge einer Straße
     * @brief Calculates the length of a street
     * @brief 计算一条街道的长度
     * @param street Zeiger auf die Straße
     * @param street Pointer to the street
     * @param street 街道指针
     * @return Länge der Straße
     * @return Length of the street
     * @return 街道长度
     */
    double getLength(const Street* street) const override;

    /**
     * @brief Löscht alle Städte und Straßen von der Karte
     * @brief Clears all cities and streets from the map
     * @brief 清除地图上所有的城市和街道
     */
    void clear();

    /**
     * @brief Gibt die aktuelle Liste der Städte zurück
     * @brief Returns the current list of cities
     * @brief 返回当前城市列表
     * @return Liste von Stadtzeigern
     * @return List of city pointers
     * @return 城市对象指针列表
     */
    QVector<City*> get_city_list() const;

    /**
     * @brief Setzt den Kostenmodus für die Pfadberechnung
     * @brief Sets the cost mode for path calculation
     * @brief 设置路径计算的代价模式
     * @param mode Der zu setzende Modus
     * @param mode The mode to set
     * @param mode 要设置的模式
     */
    void set_cost_mode(CostMode mode) override;

    void draw_city(QGraphicsScene& scene) const;

    void draw_street(QGraphicsScene& scene) const;
};

#endif // MAP_H
