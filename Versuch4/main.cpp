/**
 * @file main.cpp
 * @brief Iterative Berechnung der maximalen Sichtweite ohne trigonometrische Formeln.
 * @zh_CN 本程序在不使用 acos 或勾股公式的前提下，通过迭代判断视线是否与地心向量垂直，
 *        找出观察者能看到的最远点，并输出对应视距与角度。
 * @de_DE Dieses Programm berechnet die Sichtweite iterativ ohne trigonometrische Funktionen,
 *        indem geprüft wird, wann der Sichtstrahl tangential zur Erdoberfläche verläuft.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <windows.h>
#include "Vektor.h"

/**
 * @brief Berechnet den Winkel zwischen zwei Vektoren in Grad (mithilfe von acos).
 * @param line1 Erster Vektor
 * @param line2 Zweiter Vektor
 * @param erde_center Mittelpunkt der Erde
 * @return Winkel in Grad zwischen den beiden Vektoren
 * 
 * @zh_CN 计算两个向量之间的夹角（单位：角度），
 *        用于判断视线与地心连线是否垂直。
 * @de_DE Berechnet den Winkel (in Grad) zwischen zwei Vektoren,
 *        um zu bestimmen, ob der Sichtstrahl senkrecht zur Verbindungslinie zum Erdmittelpunkt steht.
 */
float lld(Vektor line1, Vektor line2, Vektor erde_center) {
    return acos(line1.skalarProd(line2) / (line1.laenge(erde_center) * line2.laenge(erde_center))) * 180 / M_PI;
}

// ======================== 主函数 Hauptfunktion ========================
/**
 * @brief Hauptfunktion zur iterativen Berechnung der maximalen Sichtweite.
 * @return 0 bei erfolgreicher Ausführung
 * 
 * @zh_CN 主函数，设置初始条件并通过旋转查找视线与地球切线垂直时的最远可见点。
 * @de_DE Hauptfunktion, die die Anfangsbedingungen setzt und durch Rotation den maximal sichtbaren Punkt sucht.
 */
int main() {
    SetConsoleOutputCP(CP_UTF8);  ///< 设置控制台编码为 UTF-8 / Setzt die Konsolenausgabe auf UTF-8

    // === 参数 Parameter ===
    const double R = 6371000.0;          ///< 地球半径 / Erdradius (in Meter)
    const double plattform = 555.7;      ///< 平台高度 / Plattformhöhe (in Meter)
    const double mensch = 1.7;           ///< 人的身高 / Körpergröße (in Meter)
    const double h = plattform + mensch; ///< 总高度 = 平台 + 人 / Gesamthöhe = Plattform + Mensch
    const double sichtRadius = R + h;    ///< 从地心到观察点的距离 / Sichtstrahl-Radius

    // === 向量定义 Vektorinitialisierung ===
    Vektor erde_center(0, 0, 0);     ///< 地心坐标 / Mittelpunkt der Erde
    Vektor man(0, R+h, 0);           ///< 观察者位置向量 / Vektor zum Beobachter
    Vektor erde_point(0, R, 0);      ///< 初始地面点（正北方向）/ Anfangspunkt auf der Erdoberfläche (Norden)

    // === 迭代旋转查找视线刚好与地球切线垂直 Iterative Suche ===
    long double winkel = 0.0;             ///< 当前角度 / Aktueller Winkel (in Grad)
    const long double step = 5e-6;        ///< 每步旋转的微小角度 / Schrittweite der Rotation (in Grad)
    const int max_iter = 1000000;         ///< 最大迭代次数 / Maximale Anzahl von Schritten
    int iter = 0;                          ///< 当前迭代计数器 / Iterationszähler

    std::cout << std::setprecision(10);   ///< 设置浮点数输出精度 / Setzt die Ausgabepräzision

    float min_deg = 180.0;  ///< 最小角度记录（未使用） / Kleinster gemessener Winkel (nicht genutzt)
    int num = 0;            ///< 实际步数计数 / Zähler für die Schritte

    while (true) {
        erde_point.rotiereUmZ(step);  ///< 将地面点绕 Z 轴旋转 / Dreht den Punkt um die Z-Achse

        Vektor line1 = erde_point.sub(man);          ///< 从人到地面的视线向量 / Sichtstrahl
        Vektor line2 = erde_point.sub(erde_center);  ///< 从地面点到地心的向量 / Verbindung zum Erdmittelpunkt

        float deg_line = lld(line1, line2, erde_center);  ///< 计算夹角 / Berechnet den Winkel

        num += 1;

        if (deg_line < 90) {
            std::cout << "Sie können " << man.laenge(erde_point) / 1000 << " Km weit sehen." << std::endl;
            std::cout << "Sie sind " << h << " Meter hoch." << std::endl;
            std::cout << "Der Winkel beträgt " << step * num << " Grad." << std::endl;
            std::cout << "Anzahl Schritte: " << num << std::endl;
            break;
        }

        std::cout << step * num << std::endl;  ///< 输出当前角度（调试用）/ Ausgabe des aktuellen Winkels (Debugzweck)
    }

    return 0;  ///< 程序正常结束 / Programm beendet erfolgreich
}
