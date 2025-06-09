#include "check.h"
#include <QString>
#include "map.h"
#include <QDebug>

/**
 * @brief Überprüft, ob die eingegebenen Stadtdaten gültig sind
 * @brief Checks if the entered city data is valid
 * @brief 检查输入的城市数据是否合法
 *
 * Diese Methode überprüft, ob die X- und Y-Koordinaten ganze Zahlen sind
 * und ob der Stadtname keine Zahlen oder Leerzeichen enthält.
 *
 * This function checks whether the X and Y values are valid integers
 * and whether the city name contains no digits or whitespace.
 *
 * 此函数检查 X 和 Y 是否为有效整数，城市名称中是否不包含数字或空格。
 *
 * @param cityname Name der Stadt
 * @param cityname Name of the city
 * @param cityname 城市名称
 * @param x X-Koordinate als Zeichenkette
 * @param x X coordinate as string
 * @param x X 坐标字符串
 * @param y Y-Koordinate als Zeichenkette
 * @param y Y coordinate as string
 * @param y Y 坐标字符串
 * @return true, wenn alle Werte gültig sind
 * @return true if all values are valid
 * @return 若所有值均合法，返回 true
 */
bool check::check_city(const QString& cityname, const QString& x, const QString& y) {
    bool ok_x, ok_y;

    int x_val = x.toInt(&ok_x);
    qDebug() << x_val << cityname;
    int y_val = y.toInt(&ok_y);
    qDebug() << y_val;

    std::string cityname_std = cityname.toStdString();
    bool valid_city_name = cityname_std.find_first_of("0123456789 \t\n\r") == std::string::npos;

    return ok_x && ok_y && valid_city_name;
}

/**
 * @brief Überprüft, ob beide Städte in der Karte existieren
 * @brief Checks whether both cities exist in the map
 * @brief 检查地图中是否存在起点与终点城市
 *
 * Diese Funktion wird verwendet, um sicherzustellen, dass sowohl city_from als auch city_to
 * gültige und vorhandene Städte in der aktuellen Map sind.
 *
 * This function ensures that both `city_from` and `city_to` exist in the given map.
 *
 * 本函数用于确认传入的 `city_from` 和 `city_to` 是否都在地图中存在。
 *
 * @param map Zeiger auf die Karte
 * @param map Pointer to the map
 * @param map 地图对象指针
 * @param city_from Name der Startstadt
 * @param city_from Name of the starting city
 * @param city_from 起点城市名称
 * @param city_to Name der Zielstadt
 * @param city_to Name of the destination city
 * @param city_to 终点城市名称
 * @return true, wenn beide Städte vorhanden sind
 * @return true if both cities are found
 * @return 若两个城市都存在，返回 true
 */
bool check::check_street(Map* map, const QString city_from, const QString city_to)
{
    bool ok_from = false;
    if (map->findCity(city_from) != nullptr) {
        ok_from = true;
    }

    bool ok_to = false;
    if (map->findCity(city_to) != nullptr) {
        ok_to = true;
    }

    return ok_from && ok_to;
}
