#ifndef ADD_STREET_H
#define ADD_STREET_H

#include "map.h"
#include <QDialog>

namespace Ui {
class add_street;
}

/**
 * @brief Dialogklasse zum Hinzufügen einer Straße
 * @brief Dialog class for adding a street
 * @brief 添加街道的对话框类
 */
class add_street : public QDialog
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
    explicit add_street(QWidget *parent = nullptr);

    /**
     * @brief Destruktor
     * @brief Destructor
     * @brief 析构函数
     */
    ~add_street();

    /**
     * @brief Gibt die Startstadt der Straße zurück
     * @brief Returns the starting city of the street
     * @brief 获取街道起点城市
     * @return Name der Startstadt
     * @return Name of the starting city
     * @return 起点城市名称
     */
    QString get_from_city();

    /**
     * @brief Gibt die Zielstadt der Straße zurück
     * @brief Returns the destination city of the street
     * @brief 获取街道终点城市
     * @return Name der Zielstadt
     * @return Name of the destination city
     * @return 终点城市名称
     */
    QString get_to_city();

    QString get_street_type();
    /**
     * @brief Setzt die ComboBox mit verfügbaren Städten
     * @brief Populates the combo boxes with available cities
     * @brief 用已有城市设置下拉框内容
     * @param map Zeiger auf die Karte mit Städten
     * @param map Pointer to the map with cities
     * @param map 包含城市信息的地图指针
     */
    void set_combo(Map* map);

private slots:
    /**
     * @brief Slot-Funktion beim Klick auf den "Straße hinzufügen"-Button
     * @brief Slot function triggered when "Add Street" button is clicked
     * @brief 点击“添加街道”按钮时触发的槽函数
     */
    void on_add_street_button_clicked();

private:
    /// @brief Zeiger auf das UI-Objekt
    /// @brief Pointer to the UI object
    /// @brief 指向UI对象的指针
    Ui::add_street *ui;

    /// @brief Name der Startstadt
    /// @brief Name of the starting city
    /// @brief 起点城市名称
    QString city_from;

    /// @brief Name der Zielstadt
    /// @brief Name of the destination city
    /// @brief 终点城市名称
    QString city_to;

    QString street_type;
};

#endif // ADD_STREET_H
