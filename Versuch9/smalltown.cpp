#include "smalltown.h"
#include <QString>
#include <QDebug>
#include <QGraphicsTextItem>
#include <QGraphicsScene>

/**
 * @brief Konstruktor für eine SmallTown, leitet an die Basisklasse City weiter.
 * @brief Constructor for a SmallTown, forwards to the base class City.
 * @brief 小镇的构造函数，参数传递给基类 City。
 *
 * @param name Name der Stadt / Name of the town / 城市名称
 * @param x X-Koordinate / X coordinate / X 坐标
 * @param y Y-Koordinate / Y coordinate / Y 坐标
 */
SmallTown::SmallTown(QString name, int x, int y) : City(name, x, y) {}


/**
 * @brief Zeichnet die SmallTown in die gegebene Szene ein.
 * @brief Draws the small town onto the given scene.
 * @brief 将小镇绘制到指定的图形场景中。
 *
 * @param scene Die Zielszene / The target scene / 图形目标场景
 */
void SmallTown::draw(QGraphicsScene& scene) const {
    int r = 4;
    scene.addEllipse(x-r/2, y-r/2, r, r, QPen(Qt::red), QBrush(Qt::red));
    // 添加名称文字
    QGraphicsTextItem* text = scene.addText(name);
    text->setPos(x + r +5, y - r - 10); // 在点右上方显示名称

    // 控制台输出调试信息
    qDebug() << "Drawing small city:" << name << "at" << "(" << x << "," << y << ")";
}
