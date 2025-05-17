/**
 * @file Vektor.cpp
 * @brief Implementierung der Klasse Vektor
 * @note 文件：Vektor.cpp
 * 中文：Vektor 类的实现文件
 */

#include "Vektor.h"
/**
 * @brief Konstruktor: Initialisiert den Vektor mit x-, y- und z-Komponenten.
 * @param inX X-Komponente
 * @param inY Y-Komponente
 * @param inZ Z-Komponente
 * @note 构造函数：用 x、y 和 z 分量初始化向量。
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{
}

/**
 * @brief Destruktor
 * @note 析构函数
 */
Vektor::~Vektor()
{
}

/**
 * @brief Berechnet die Länge (Betrag) des Vektors und gibt diese auf der Konsole aus.
 * @return Länge des Vektors
 * @note 计算向量的模长（大小）并在控制台输出。
 */
double Vektor::laenge(const Vektor& input) const
{
    double lange = 0;
    lange = std::sqrt(std::pow((x-input.x),2)+std::pow((y-input.y),2)+std::pow((z-input.z),2));
    return lange;
}

/**
 * @brief Berechnet die Differenz zwischen dem aktuellen Vektor und einem Eingabevektor.
 * @param input Der Vektor, der abgezogen wird.
 * @return Neuer Vektor mit der Differenz
 * @note 计算当前向量与输入向量的差，返回差值向量。
 */
Vektor Vektor::sub(const Vektor& input) const
{
    return Vektor(x - input.x, y - input.y, z - input.z);
}

/**
 * @brief Berechnet das Skalarprodukt (inneres Produkt) mit einem anderen Vektor.
 * @param input Der andere Vektor
 * @return Das Skalarprodukt
 * @note 计算当前向量与另一个向量的点积（内积）。
 */
double Vektor::skalarProd(const Vektor& input) const
{
    return x * input.x + y * input.y + z * input.z;
}

/**
 * @brief Berechnet den Winkel (in Grad) zwischen diesem Vektor und einem anderen.
 *
 * Gibt bei fehlerhaften Eingaben (z. B. Nullvektor) 0 zurück.
 * Es wird sichergestellt, dass der Wert für acos im gültigen Bereich liegt.
 *
 * @param input Der andere Vektor
 * @return Winkel in Grad
 * @note 计算当前向量与另一个向量之间的夹角（单位：度）。如果输入向量长度为 0，返回 0。
 * 并对 acos 输入值进行有效性处理，避免超出定义域。
 */
double Vektor::winkel(const Vektor& input) const
{
    Vektor ursprung(0,0,0);
    if (this->laenge(ursprung)*input.laenge(ursprung) == 0) {
        return 0;
    }
    return acos(this->skalarProd(input)/(this->laenge(ursprung)*input.laenge(ursprung)));
}

/**
 * @brief Rotiert den Vektor um die Z-Achse im Uhrzeigersinn.
 * @param rad Rotationswinkel im Bogenmaß (Radian)
 * @note 将向量绕 Z 轴顺时针旋转，角度以弧度为单位。
 */
long double Vektor::rotiereUmZ(const long double deg) {
    long double rad = deg * M_PI / 180;
    x = x*cos(rad)-y*sin(rad);
    y = x*sin(rad)+y*cos(rad);
    return rad;
}


/**
 * @brief Gibt die Komponenten des Vektors auf der Konsole aus.
 * @note 在控制台输出向量的各分量（x，y，z）。
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief 向量加法的实现：this + input
 * @details 每个分量逐个相加，返回一个新建的 Vektor 实例。
 *
 * 中文：执行向量加法，返回新向量，不改变当前对象。
 * Deutsch: Führt eine komponentenweise Addition durch und gibt das Ergebnis als neuen Vektor zurück.
 *
 * @param input 要加的另一个向量 / Der Vektor, der addiert wird.
 * @return 加法结果向量 / Der resultierende Vektor nach der Addition.
 */
