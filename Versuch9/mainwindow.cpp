#include "mainwindow.h"
#include "mouse_control.h"
#include "ui_mainwindow.h"
#include "city.h"
#include "map.h"
#include "street.h"
#include "add_city.h"
#include "mapionrw.h"
#include "mapio.h"
#include "dijkstra.h"
#include "mapiofileinput.h"
#include "check.h"
#include "add_street.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QFileDialog>

#define TEST true

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent)
        , ui(new Ui::MainWindow)
{

    {
        ui->setupUi(this);
        scene = new QGraphicsScene(this);
        ui->graphicsView->setScene(scene);
    }
    ui->test->setVisible(false);
    ui->test_draw_city->setVisible(false);
    ui->draw_map->setVisible(false);
    ui->draw_street->setVisible(false);
    ui->from->setVisible(false);
    ui->from_combo->setVisible(false);
    ui->to->setVisible(false);
    ui->to_combo->setVisible(false);
    ui->confirm->setVisible(false);
    ui->fastmode->setVisible(false);
    ui->label_eingabe->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->fill_map->setVisible(false);
    map = new Map();
    mapIo = new MapIoNrw();


}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_test_clicked()
{
    qDebug()<<"Button pressed";
    QString line_text = ui->lineEdit->text();
    qDebug()<<line_text;
    ui->lineEdit->clear();
    // 随机生成坐标与尺寸
    int x = QRandomGenerator::global()->bounded(100);
    int y = QRandomGenerator::global()->bounded(100);
    int w = QRandomGenerator::global()->bounded(50, 70);
    int h = QRandomGenerator::global()->bounded(50, 60);

    // 使用成员变量 scene 添加矩形
    scene->addRect(x, y, w, h, QPen(Qt::red), QBrush(Qt::red));


    //QMessageBox::information(this,"important information","rect create successful");
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString line_text_return = ui->lineEdit->text();
    qDebug()<<line_text_return;
    ui->lineEdit->clear();

}


void MainWindow::on_actionexit_triggered()
{
    close();
}


void MainWindow::on_actionclear_Scene_triggered()
{
    scene->clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About",
                       "StreetPlanner\n\nEin Qt-Programm zur Darstellung und Bearbeitung von Versuch 9.\n\nErstellt von Jiakun Yu, RWTH Aachen, 2025.");

}


void MainWindow::on_test_draw_city_clicked()
{
    City aachen("Aachen",20,10);
    aachen.draw(*scene);
}


void MainWindow::on_draw_map_clicked()
{

    map->draw(*scene);
}


void MainWindow::on_draw_street_clicked()
{
    map->draw(*scene);
}


void MainWindow::on_check_test_clicked()
{
    bool checked = ui->check_test->isChecked();
    ui->test->setVisible(checked);
    ui->test_draw_city->setVisible(checked);
    ui->draw_map->setVisible(checked);
    ui->draw_street->setVisible(checked);
    ui->label_eingabe->setVisible(checked);
    ui->lineEdit->setVisible(checked);
    ui->fill_map->setVisible(checked);

}


void MainWindow::on_add_city_clicked()
{
    while (true) {
        add_city dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QString name = dialog.get_city_name();
            QString x = dialog.get_x();
            QString y = dialog.get_y();

            if (!check::check_city(name, x, y)) {
                QMessageBox::warning(this, "无效输入", "城市名不能包含数字或空格，坐标必须是整数！");
                continue;  // 再次弹出对话框
            }

            City* city = dialog.get_city();
            if (city) {
                map->addCity(city);
                scene->clear();
                map->draw(*scene);
            }
        }
        break;  // 成功添加后退出循环，或用户点击取消
    }
}



void MainWindow::on_fill_map_clicked()
{
    mapIo->fillMap(*map);
    map->draw(*scene);
}


void MainWindow::on_find_way_clicked()
{
    ui->find_way->setVisible(false);
    ui->from->setVisible(true);
    ui->from_combo->setVisible(true);
    ui->from_combo->clear();
    ui->to->setVisible(true);
    ui->to_combo->setVisible(true);
    ui->to_combo->clear();
    ui->confirm->setVisible(true);
    ui->fastmode->setVisible(true);
    scene->clear();
    map->draw(*scene);
    ui->from_combo->clear();
    ui->to_combo->clear();
    QVector<City*> citylist = map->get_city_list();
    if (citylist.isEmpty())
    {
        QMessageBox::warning(this,"waring","Citylist is empty!");
        ui->find_way->setVisible(true);
        ui->from->setVisible(false);
        ui->from_combo->setVisible(false);
        ui->to->setVisible(false);
        ui->to_combo->setVisible(false);
        ui->confirm->setVisible(false);
        ui->fastmode->setVisible(false);
        return;
    }
    for (City* city : map->get_city_list())
    {
        ui->from_combo->addItem(city->getname());
        ui->to_combo->addItem(city->getname());
    }
}


void MainWindow::on_confirm_clicked()
{
    ui->find_way->setVisible(true);
    ui->from->setVisible(false);
    ui->from_combo->setVisible(false);
    ui->to->setVisible(false);
    ui->to_combo->setVisible(false);
    ui->confirm->setVisible(false);
    ui->fastmode->setVisible(false);
    bool fast = ui->fastmode->isChecked();
    QString startCity = ui->from_combo->currentText();
    QString targetCity = ui->to_combo->currentText();

    if (startCity == targetCity)
    {
        QMessageBox::warning(this, "Warning", "City can't be SAME");
        return;
    }

    if (fast)
    {
        map->set_cost_mode(CostMode::Time);
    }

    QVector<Street*> shortestPath = Dijkstra::search(*map, startCity, targetCity);

    if (shortestPath.isEmpty()) {
        QMessageBox::information(this, "Ergebnis", "Kein Pfad gefunden.");
    } else {
        for (Street* s : shortestPath) {
            qDebug() << "Street from"
                     << (s->get_start()->getname())
                     << "to"
                     << (s->get_end()->getname());
            if (fast)
            {
                s->draw_blue_street(*scene);
                continue;
            }
            s->draw_red_street(*scene);
        }
    }
}




void MainWindow::on_read_document_clicked()
{
    QStringList files = QFileDialog::getOpenFileNames(
        this,
        "Bitte wählen Sie Stadt- und Straßen-Datei",
        "D:/rwth_eclipse_workstation/Versuch9/txtFiles",
        "Textdateien (*.txt);;Alle Dateien (*)"
        );

    if (files.size() != 2) {
        QMessageBox::warning(this, "Fehler", "Bitte wählen Sie genau **zwei** Dateien aus!");
        return;
    }

    QString file_city, file_street;
    for (const QString& path : files) {
        if (path.contains("city", Qt::CaseInsensitive))
            file_city = path;
        else if (path.contains("street", Qt::CaseInsensitive))
            file_street = path;
    }

    if (file_city.isEmpty() || file_street.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Dateien müssen 'city' und 'street' im Namen enthalten.");
        return;
    }

    //QString fileName_city ="D:/rwth_eclipse_workstation/Versuch9_gross_programm/txtFiles/city_file.txt";
    //QString fileName_street ="D:/rwth_eclipse_workstation/Versuch9_gross_programm/txtFiles/street_file.txt";
    MapIo* file_reader = new MapIoFileinput(file_city, file_street);

    file_reader -> fillMap(*map);
    map->draw(*scene);

}


void MainWindow::on_add_street_clicked()
{
    while (true)
    {
        add_street dialog(this);
        dialog.set_combo(map);
        if (dialog.exec() == QDialog::Accepted)
        {
            QString city_from = dialog.get_from_city();
            QString city_to = dialog.get_to_city();

            if (!check::check_street(map, city_from, city_to))
            {
                QMessageBox::warning(this, "Invalid Input","Unknow City Name");
                continue;
            }
            Street* tmp_street = new Street(map->findCity(city_from),map->findCity(city_to));
            if (tmp_street)
            {
                map->addStreet(tmp_street);
                scene->clear();
                map->draw(*scene);
            }

        }
        break;
    }
}


