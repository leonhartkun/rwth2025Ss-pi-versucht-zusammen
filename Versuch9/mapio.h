///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
///////////////////////////////////////////////////////////////////////////////

#ifndef MAPIO_H
#define MAPIO_H

#include "abstractmap.h"

/**
 * @class MapIo
 * @brief Abstrakte Klasse zum Hinzufügen von Städten und Straßen zu einer Karte
 * @brief Abstract class for adding cities and streets to a map
 * @brief 用于向地图添加城市和街道的抽象类
 */
class MapIo
{
public:
    /**
     * @brief Virtueller Destruktor
     * @brief Virtual destructor
     * @brief 虚析构函数
     */
    virtual ~MapIo();

    /**
     * @brief Fügt einer übergebenen Karte Städte und Straßen hinzu
     * @brief Adds cities and streets to the provided map
     * @brief 向给定的地图添加城市和街道
     * @param map Referenz auf eine Karte, die befüllt werden soll
     * @param map Reference to the map to be filled
     * @param map 要填充的地图引用
     */
    virtual void fillMap(AbstractMap &map) = 0;
};

#endif // MAPIO_H
