#include "bigtown.h"
#include <QDebug>
#include <QGraphicsTextItem>

/**
 * @brief Konstruktor für BigTown
 * @brief Constructor for BigTown
 * @brief BigTown 的构造函数
 * @param name Name der Stadt
 * @param name Name of the city
 * @param name 城市名称
 * @param x X-Koordinate der Stadt
 * @param x X coordinate of the city
 * @param x 城市 X 坐标
 * @param y Y-Koordinate der Stadt
 * @param y Y coordinate of the city
 * @param y 城市 Y 坐标
 */
BigTown::BigTown(QString name, int x, int y) : City(name, x, y) {}

/**
 * @brief Zeichnet die große Stadt in die Szene
 * @brief Draws the big town into the scene
 * @brief 将大城市绘制到图形场景中
 * @param scene Zielszene zur Darstellung
 * @param scene Target scene for rendering
 * @param scene 用于绘制的目标场景
 */
void BigTown::draw(QGraphicsScene& scene) const {
    int r = 16;
    scene.addEllipse(x - r / 2, y - r / 2, r, r, QPen(Qt::red), QBrush(Qt::red));

    // 添加名称文字 / Add label / 添加城市名称标签
    QGraphicsTextItem* text = scene.addText(name);
    text->setPos(x + r + 5, y - r - 10);  // 在点右上方显示名称 / Display name above right of point

    // 控制台输出调试信息 / Debug output / 输出调试信息
    qDebug() << "Drawing big city:" << name << "at" << "(" << x << "," << y << ")";
}
