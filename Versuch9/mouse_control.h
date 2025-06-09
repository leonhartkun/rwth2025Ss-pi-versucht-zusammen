#ifndef MOUSE_CONTROL_H
#define MOUSE_CONTROL_H

#include <QGraphicsView>
#include <QWheelEvent>

/**
 * @class mouse_control
 * @brief Erweiterte QGraphicsView mit Zoomfunktion per Mausrad
 * @brief Extended QGraphicsView with zoom functionality via mouse wheel
 * @brief 支持鼠标滚轮缩放的扩展 QGraphicsView 类
 */
class mouse_control : public QGraphicsView
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktor für mouse_control
     * @brief Constructor for mouse_control
     * @brief mouse_control 的构造函数
     * @param parent Übergeordnetes Widget
     * @param parent Parent widget
     * @param parent 父窗口
     */
    explicit mouse_control(QWidget* parent = nullptr);

protected:
    /**
     * @brief Verarbeitet das Mausradereignis für Zoom-In/Out
     * @brief Handles the mouse wheel event for zooming in/out
     * @brief 处理鼠标滚轮事件以实现缩放功能
     * @param event Zeiger auf das Mausradereignis
     * @param event Pointer to the wheel event
     * @param event 鼠标滚轮事件指针
     */
    void wheelEvent(QWheelEvent* event) override;
};

#endif // MOUSE_CONTROL_H
