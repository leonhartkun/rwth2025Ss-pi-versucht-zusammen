#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mapio.h"
#include "map.h"
#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief Hauptfenster der Anwendung zur Kartenverwaltung und Pfadsuche
 * @brief Main window of the application for map management and pathfinding
 * @brief 用于地图管理与路径搜索的应用程序主窗口类
 */
class MainWindow : public QMainWindow
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
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destruktor
     * @brief Destructor
     * @brief 析构函数
     */
    ~MainWindow();

private slots:

    /**
     * @brief Slot für Testknopf
     * @brief Slot for test button
     * @brief 测试按钮的槽函数
     */
    void on_test_clicked();

    /**
     * @brief Slot bei Eingabe in Start-Stadtfeld
     * @brief Slot triggered when return is pressed in start city input
     * @brief 在起点城市输入框中按下回车触发
     */
    void on_lineEdit_returnPressed();

    /**
     * @brief Slot zum Beenden der Anwendung
     * @brief Slot to exit the application
     * @brief 退出应用程序的槽函数
     */
    void on_actionexit_triggered();

    /**
     * @brief Slot zum Löschen der Szene
     * @brief Slot to clear the scene
     * @brief 清空图形场景的槽函数
     */
    void on_actionclear_Scene_triggered();

    /**
     * @brief Slot zur Anzeige von Informationen über das Programm
     * @brief Slot to show about information
     * @brief 显示“关于”信息的槽函数
     */
    void on_actionAbout_triggered();

    /**
     * @brief Slot zum Zeichnen einer Teststadt
     * @brief Slot to draw a test city
     * @brief 绘制测试城市的槽函数
     */
    void on_test_draw_city_clicked();

    /**
     * @brief Slot zum Zeichnen der gesamten Karte
     * @brief Slot to draw the entire map
     * @brief 绘制整张地图的槽函数
     */
    void on_draw_map_clicked();

    /**
     * @brief Slot zum Zeichnen von Straßen
     * @brief Slot to draw streets
     * @brief 绘制街道的槽函数
     */
    void on_draw_street_clicked();

    /**
     * @brief Slot zur Ausführung eines Validierungstests
     * @brief Slot to perform a validation test
     * @brief 执行验证测试的槽函数
     */
    void on_check_test_clicked();

    /**
     * @brief Slot zum Öffnen des "Stadt hinzufügen"-Dialogs
     * @brief Slot to open the "add city" dialog
     * @brief 打开“添加城市”对话框的槽函数
     */
    void on_add_city_clicked();

    /**
     * @brief Slot zum automatischen Befüllen der Karte
     * @brief Slot to fill the map automatically
     * @brief 自动填充地图的槽函数
     */
    void on_fill_map_clicked();

    /**
     * @brief Slot zur Ausführung des Pfadsuchalgorithmus
     * @brief Slot to perform path finding
     * @brief 执行路径查找算法的槽函数
     */
    void on_find_way_clicked();

    /**
     * @brief Slot zur Bestätigung von Benutzereingaben
     * @brief Slot to confirm user inputs
     * @brief 确认用户输入的槽函数
     */
    void on_confirm_clicked();

    /**
     * @brief Slot zum Einlesen einer Karte aus Datei
     * @brief Slot to read a map from file
     * @brief 从文件读取地图的槽函数
     */
    void on_read_document_clicked();

    /**
     * @brief Slot zum Öffnen des "Straße hinzufügen"-Dialogs
     * @brief Slot to open the "add street" dialog
     * @brief 打开“添加街道”对话框的槽函数
     */
    void on_add_street_clicked();

private:
    /**
     * @brief Zeiger auf die Benutzeroberfläche
     * @brief Pointer to the user interface
     * @brief 指向用户界面的指针
     */
    Ui::MainWindow *ui;

    /**
     * @brief Zeiger auf die grafische Szene
     * @brief Pointer to the graphics scene
     * @brief 指向图形场景的指针
     */
    QGraphicsScene* scene;

    /**
     * @brief Zeiger auf das aktuelle MapIo-Objekt zur Dateiverwaltung
     * @brief Pointer to the current MapIo object for file handling
     * @brief 指向当前用于文件处理的 MapIo 对象的指针
     */
    MapIo* mapIo;

    /**
     * @brief Zeiger auf die aktuelle Karte
     * @brief Pointer to the current map
     * @brief 指向当前地图的指针
     */
    Map* map = new Map();
    /**
     * @brief Focus on the city point
     * @brief 聚焦城市
     */
    void zoom_to_point(const QPointF &scene_point, qreal factor);

};

#endif // MAINWINDOW_H
