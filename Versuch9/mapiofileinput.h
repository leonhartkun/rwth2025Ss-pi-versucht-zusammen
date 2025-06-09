///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 9
///////////////////////////////////////////////////////////////////////////////

#ifndef MAPIOFILEINPUT_H
#define MAPIOFILEINPUT_H

#include "mapio.h"

/**
 * @class MapIoFileinput
 * @brief Implementiert das Einlesen von Stadt- und Straßendaten aus Dateien
 * @brief Implements reading city and street data from files
 * @brief 从文件读取城市和街道数据的实现类
 */
class MapIoFileinput : public MapIo
{
public:
    /**
     * @brief Konstruktor mit Pfadangabe für Eingabedateien
     * @brief Constructor with paths for input files
     * @brief 带输入文件路径的构造函数
     * @param pathToCityFile Pfad zur Datei mit Städtedaten
     * @param pathToCityFile Path to the city data file
     * @param pathToCityFile 城市数据文件路径
     * @param pathToStreetFile Pfad zur Datei mit Straßendaten
     * @param pathToStreetFile Path to the street data file
     * @param pathToStreetFile 街道数据文件路径
     */
    MapIoFileinput(QString pathToCityFile, QString pathToStreetFile);

    /**
     * @brief Destruktor
     * @brief Destructor
     * @brief 析构函数
     */
    ~MapIoFileinput();

    /**
     * @brief Liest die Karteninformationen aus Dateien und befüllt die Karte
     * @brief Reads map information from files and fills the map
     * @brief 从文件读取地图信息并填充地图对象
     * @param map Referenz auf die zu befüllende Karte
     * @param map Reference to the map to be filled
     * @param map 要填充的地图引用
     */
    virtual void fillMap(AbstractMap &map);

protected:
    /**
     * @brief Pfad zur Datei mit Städtedaten
     * @brief Path to the city data file
     * @brief 城市数据文件的路径
     */
    QString pathToCityFile;

    /**
     * @brief Pfad zur Datei mit Straßendaten
     * @brief Path to the street data file
     * @brief 街道数据文件的路径
     */
    QString pathToStreetFile;
};

#endif // MAPIOFILEINPUT_H
