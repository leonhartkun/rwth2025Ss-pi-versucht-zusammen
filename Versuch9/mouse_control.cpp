#include "mouse_control.h"
#include <QScrollBar>
#include <QDebug>

/**
 * @brief Konstruktor: Initialisiert die Maussteuerung für die grafische Ansicht.
 * @brief Constructor: Initializes mouse control for the graphical view.
 * @brief 构造函数：初始化图形视图的鼠标控制行为。
 *
 * @param parent Das übergeordnete Widget / The parent widget / 父部件
 */
mouse_control::mouse_control(QWidget* parent)
    : QGraphicsView(parent)
{
    setDragMode(QGraphicsView::ScrollHandDrag); ///< Ermöglicht das Verschieben mit der Maus
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse); ///< Zoom-Zentrum ist die Mausposition
}

/**
 * @brief Ereignisbehandlung für das Mausrad – Zoom und horizontales Scrollen.
 * @brief Handles mouse wheel events for zooming and horizontal scrolling.
 * @brief 鼠标滚轮事件处理：支持缩放与横向滚动。
 *
 * @param event Das Mausrad-Ereignis / The wheel event / 鼠标滚轮事件
 */
void mouse_control::wheelEvent(QWheelEvent* event)
{
    if (event->modifiers() == Qt::ControlModifier) {
        double scale_factor = 1.15;
        if (event->angleDelta().y() > 0)
            scale(scale_factor, scale_factor);
        else
            scale(1.0 / scale_factor, 1.0 / scale_factor);
    } else if (event->modifiers() == Qt::ShiftModifier) {
        int delta = event->angleDelta().y();
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta);
    } else {
        QGraphicsView::wheelEvent(event);
    }
}
