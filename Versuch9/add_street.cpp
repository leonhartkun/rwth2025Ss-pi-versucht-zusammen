#include "add_street.h"
#include "ui_add_street.h"

/**
 * @brief Konstruktor des Dialogs zum Hinzufügen einer Straße
 * @brief Constructor of the dialog for adding a street
 * @brief 添加街道对话框的构造函数
 * @param parent Übergeordnetes Widget
 * @param parent Parent widget
 * @param parent 父窗口
 */
add_street::add_street(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_street)
{
    ui->setupUi(this);
}

/**
 * @brief Destruktor des Dialogs
 * @brief Destructor of the dialog
 * @brief 对话框析构函数
 */
add_street::~add_street()
{
    delete ui;
}

/**
 * @brief Slot-Funktion beim Klick auf den „Straße hinzufügen“-Button
 * @brief Slot function triggered when the "Add Street" button is clicked
 * @brief 点击“添加街道”按钮时的槽函数
 */
void add_street::on_add_street_button_clicked()
{
    city_from = ui->from_combo->currentText();
    city_to = ui->to_combo->currentText();
    street_type = ui->type_combo->currentText();

    accept();  // 确认并关闭对话框
}

/**
 * @brief Gibt die ausgewählte Startstadt zurück
 * @brief Returns the selected starting city
 * @brief 返回所选的起点城市
 * @return Name der Startstadt
 * @return Name of the starting city
 * @return 起点城市名称
 */
QString add_street::get_from_city(){
    return city_from;
}

/**
 * @brief Gibt die ausgewählte Zielstadt zurück
 * @brief Returns the selected destination city
 * @brief 返回所选的终点城市
 * @return Name der Zielstadt
 * @return Name of the destination city
 * @return 终点城市名称
 */
QString add_street::get_to_city(){
    return city_to;
}

QString add_street::get_street_type(){
    return street_type;
}

/**
 * @brief Füllt die Kombinationsfelder mit verfügbaren Städten aus der Karte
 * @brief Populates the combo boxes with available cities from the map
 * @brief 将地图中的可用城市填充到下拉框中
 * @param map Zeiger auf die Karte mit Städten
 * @param map Pointer to the map containing cities
 * @param map 包含城市的地图指针
 */
void add_street::set_combo(Map* map)
{
    QVector<City*> city_list = map->get_city_list();
    ui->from_combo->clear();
    ui->to_combo->clear();

    for (City* city : city_list)
    {
        QString cityname = city->getname();
        ui->to_combo->addItem(cityname);
        ui->from_combo->addItem(cityname);
    }
    ui->type_combo->addItem("Stateroad");
    ui->type_combo->addItem("motorway");
}
