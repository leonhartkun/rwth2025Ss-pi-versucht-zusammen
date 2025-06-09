#include "city.h"

#include <QDebug>
#include <QGraphicsTextItem>

/**
 * @brief Konstruktor der Klasse City
 * @brief Constructor of the City class
 * @brief City 类的构造函数
 * @param name Name der Stadt
 * @param name Name of the city
 * @param name 城市名称
 * @param x X-Koordinate
 * @param x X coordinate
 * @param x 城市 X 坐标
 * @param y Y-Koordinate
 * @param y Y coordinate
 * @param y 城市 Y 坐标
 */
City::City(QString name, int x, int y) : name(name), x(x), y(y) {
    // 可选：调试输出 / Optional debug output / 可选：调试输出
    qDebug() << "City created: " << name << "(" << x << "," << y << ")";
}

/**
 * @brief Zeichnet die Stadt als roten Punkt mit Namen
 * @brief Draws the city as a red point with label
 * @brief 将城市以红点和文字的形式绘制到场景中
 * @param scene Zielszene zur Darstellung
 * @param scene Target scene for rendering
 * @param scene 用于绘图的目标场景
 */
void City::draw(QGraphicsScene& scene) const {
    int r = 6;
    scene.addEllipse(x - r / 2, y - r / 2, r, r, QPen(Qt::red), QBrush(Qt::red));

    QGraphicsTextItem* text = scene.addText(name);
    text->setPos(x + 10, y - 10 - 2 * r);

    qDebug() << "Drawing city:" << name << "at" << "(" << x << "," << y << ")";
}

/**
 * @brief Gibt den Namen der Stadt zurück
 * @brief Returns the name of the city
 * @brief 返回城市名称
 * @return Stadtname
 * @return City name
 * @return 城市名称
 */
QString City::getname()
{
    return name;
}

/**
 * @brief Gibt die X-Koordinate der Stadt zurück
 * @brief Returns the X coordinate of the city
 * @brief 返回城市的 X 坐标
 * @return X-Koordinate
 * @return X coordinate
 * @return X 坐标
 */
int City::get_x()
{
    return x;
}

/**
 * @brief Gibt die Y-Koordinate der Stadt zurück
 * @brief Returns the Y coordinate of the city
 * @brief 返回城市的 Y 坐标
 * @return Y-Koordinate
 * @return Y coordinate
 * @return Y 坐标
 */
int City::get_y()
{
    return y;
}
