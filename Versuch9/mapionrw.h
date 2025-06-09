///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 9
///////////////////////////////////////////////////////////////////////////////

#ifndef MAPIONRW_H
#define MAPIONRW_H

#include "mapio.h"

/**
 * @class MapIoNrw
 * @brief Stellt eine fest kodierte Beispielkarte von NRW zur Verfügung
 * @brief Provides a hardcoded example map of NRW
 * @brief 提供硬编码的北莱茵-威斯特法伦地图示例类
 */
class MapIoNrw : public MapIo
{
public:
    /**
     * @brief Konstruktor
     * @brief Constructor
     * @brief 构造函数
     */
    MapIoNrw();

    /**
     * @brief Virtueller Destruktor
     * @brief Virtual destructor
     * @brief 虚析构函数
     */
    virtual ~MapIoNrw();

    /**
     * @brief Befüllt die Karte mit vordefinierten Städten und Straßen
     * @brief Fills the map with predefined cities and streets
     * @brief 使用预设的城市和街道填充地图
     * @param map Referenz auf die zu befüllende Karte
     * @param map Reference to the map to be filled
     * @param map 要填充的地图引用
     */
    virtual void fillMap(AbstractMap &map);
};

#endif // MAPIONRW_H
