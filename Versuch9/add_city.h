#ifndef ADD_CITY_H
#define ADD_CITY_H

#include <QDialog>
#include "city.h"

namespace Ui {
class add_city;
}

/**
 * @brief Dialogklasse zum Hinzufügen einer Stadt
 * @brief Dialog class for adding a city
 * @brief 添加城市的对话框类
 */
class add_city : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor
     * @brief Constructor
     * @brief 构造函数
     * @param parent Übergeordnetes Widget
     * @param parent Parent widget
     * @param parent 父窗口
     */
    explicit add_city(QWidget *parent = nullptr);

    /**
     * @brief Destruktor
     * @brief Destructor
     * @brief 析构函数
     */
    ~add_city();

    /**
     * @brief Gibt das erstellte Stadtobjekt zurück
     * @brief Returns the created city object
     * @brief 获取创建的城市对象
     * @return Zeiger auf die Stadt
     * @return Pointer to the city
     * @return 城市指针
     */
    City* get_city() const;

    /**
     * @brief Gibt den Stadtnamen zurück
     * @brief Returns the city name
     * @brief 获取城市名称
     * @return Stadtnamen
     * @return City name
     * @return 城市名称
     */
    QString get_city_name();

    /**
     * @brief Gibt die X-Koordinate der Stadt zurück
     * @brief Returns the X coordinate of the city
     * @brief 获取城市的X坐标
     * @return X-Koordinate als Zeichenkette
     * @return X coordinate as string
     * @return X坐标字符串
     */
    QString get_x();

    /**
     * @brief Gibt die Y-Koordinate der Stadt zurück
     * @brief Returns the Y coordinate of the city
     * @brief 获取城市的Y坐标
     * @return Y-Koordinate als Zeichenkette
     * @return Y coordinate as string
     * @return Y坐标字符串
     */
    QString get_y();

private slots:
    /**
     * @brief Slot-Funktion beim Klick auf den "Stadt hinzufügen"-Button
     * @brief Slot function triggered when the "Add City" button is clicked
     * @brief 点击“添加城市”按钮时触发的槽函数
     */
    void on_add_city_butten_clicked();

private:
    /// @brief Zeiger auf das UI-Objekt
    /// @brief Pointer to the UI object
    /// @brief 指向UI对象的指针
    Ui::add_city *ui;

    /// @brief Temporäres Stadtobjekt
    /// @brief Temporary city object
    /// @brief 临时城市对象
    City* tmp_city = nullptr;

    /// @brief Name der Stadt
    /// @brief Name of the city
    /// @brief 城市名称
    QString cityname;

    /// @brief X-Koordinate
    /// @brief X coordinate
    /// @brief X坐标
    QString x;

    /// @brief Y-Koordinate
    /// @brief Y coordinate
    /// @brief Y坐标
    QString y;
};

#endif // ADD_CITY_H
