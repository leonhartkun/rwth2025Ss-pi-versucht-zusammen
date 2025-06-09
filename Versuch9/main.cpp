#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QMessageBox>

/**
 * @brief Einstiegspunkt der Anwendung
 * @brief Entry point of the application
 * @brief 应用程序入口函数
 *
 * Initialisiert die QApplication, lädt die passende Sprachdatei und zeigt das Hauptfenster an.
 *
 * Initializes QApplication, loads appropriate translation file, and shows the main window.
 *
 * 初始化 `QApplication`，加载合适的翻译文件，并显示主窗口。
 *
 * @param argc Anzahl der Befehlszeilenargumente
 * @param argc Number of command line arguments
 * @param argc 命令行参数个数
 * @param argv Array der Argumente
 * @param argv Array of arguments
 * @param argv 参数数组
 * @return Rückgabecode der Anwendung
 * @return Return code of the application
 * @return 应用程序返回值
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Spracherkennung und Lokalisierung / Language detection and localization / 语言自动识别与本地化
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Versuch9_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    // Hauptfenster erstellen und anzeigen / Create and show main window / 创建并显示主窗口

    a.setWindowIcon(QIcon("D:/rwth_eclipse_workstation/git_vision/logo.png")); // 使用资源文件路径

    MainWindow w;
    w.show();

    return a.exec();  // Qt 事件循环开始
}
