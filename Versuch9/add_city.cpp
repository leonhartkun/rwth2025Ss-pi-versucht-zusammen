#include "add_city.h"
#include "ui_add_city.h"
#include "city.h"
#include <QString>

/**
 * @brief Konstruktor des Dialogs zum Hinzufügen einer Stadt
 * @brief Constructor for the dialog to add a city
 * @brief 添加城市对话框的构造函数
 * @param parent Übergeordnetes Widget
 * @param parent Parent widget
 * @param parent 父窗口
 */
add_city::add_city(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_city)
{
    ui->setupUi(this);
}

/**
 * @brief Destruktor des Dialogs
 * @brief Destructor of the dialog
 * @brief 对话框析构函数
 */
add_city::~add_city()
{
    delete ui;
}

/**
 * @brief Slot-Funktion beim Klick auf den „Stadt hinzufügen“-Button
 * @brief Slot function triggered when the "Add City" button is clicked
 * @brief 点击“添加城市”按钮后的槽函数
 */
void add_city::on_add_city_butten_clicked()
{
    cityname = ui->city_name->text();
    x = ui->x->text();
    y = ui->y->text();

    accept();  // 确认并关闭对话框
}

/**
 * @brief Gibt ein neu erzeugtes City-Objekt zurück
 * @brief Returns a newly created City object
 * @brief 返回一个新创建的 City 对象
 * @return Zeiger auf die Stadt
 * @return Pointer to the city
 * @return 城市对象指针
 */
City* add_city::get_city() const{
    City* tmp_city = new City(cityname, x.toInt(), y.toInt());
    return tmp_city;
}

/**
 * @brief Gibt den eingegebenen Stadtnamen zurück
 * @brief Returns the entered city name
 * @brief 返回输入的城市名称
 * @return Stadtname
 * @return City name
 * @return 城市名称
 */
QString add_city::get_city_name(){
    return cityname;
}

/**
 * @brief Gibt den X-Wert als Zeichenkette zurück
 * @brief Returns the X value as a string
 * @brief 返回 X 坐标的字符串形式
 * @return X-Wert
 * @return X value
 * @return X 坐标字符串
 */
QString add_city::get_x(){
    return x;
}

/**
 * @brief Gibt den Y-Wert als Zeichenkette zurück
 * @brief Returns the Y value as a string
 * @brief 返回 Y 坐标的字符串形式
 * @return Y-Wert
 * @return Y value
 * @return Y 坐标字符串
 */
QString add_city::get_y(){
    return y;
}
