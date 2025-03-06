#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsPathItem>
#include <QGraphicsTextItem>
#include <QPainterPath>
#include <QPen>
#include <QScreen>
#include <QDialog>
#include <QPainter>
#include <QPaintEvent>
#include <QGraphicsEllipseItem>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/*
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showParentScreen();
    void showChildScreen();

private:
    QStackedWidget *stackedWidget;
    QWidget *parentScreen;
    QWidget *childScreen;
};
*/
class GraphicsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit GraphicsWidget(QWidget *parent = nullptr) : QWidget(parent) {}

protected:
    void paintEvent(QPaintEvent *event) override;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //void introduction();  // Updates graphics scene
    void scenario_1();
    void scenario_2();

    // Scenario 2

    void search_blk_18();
    void assign_blk_18();
    void reassign_blk_to_18();
    void search_blk_18_delayed();
    void search_blk_18_in_emptylist();
    void search_blk_99();



private:
    QWidget *centralWidget;
    QVBoxLayout *menuLayout;
    QHBoxLayout *mainLayout;
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
};

class Box : public QGraphicsRectItem {
public:
    QGraphicsTextItem *label; // Text label for the box

    Box(qreal x, qreal y, qreal width, qreal height, const QString &text, QGraphicsItem *parent = nullptr)
        : QGraphicsRectItem(x, y, width, height, parent) {
        setBrush(QBrush(Qt::blue));  // Optional: Color the box
        setFlag(QGraphicsItem::ItemIsMovable); // Make the box draggable
        setFlag(QGraphicsItem::ItemIsSelectable); // Allow selection

        // Create a text label and add it to the box
        label = new QGraphicsTextItem(text, this);
        label->setDefaultTextColor(Qt::white); // Set text color
        qreal textX = (width - label->boundingRect().width()) / 2; // Center horizontally
        qreal textY = (height - label->boundingRect().height()) / 2; // Center vertically
        label->setPos(x + textX, y + textY);
    }
};

class CurvyLine : public QGraphicsPathItem {
public:
    CurvyLine(QPointF startPoint, QPointF endPoint, QGraphicsItem *parent = nullptr)
        : QGraphicsPathItem(parent) {
        drawCurve(startPoint, endPoint);
    }

    void drawCurve(QPointF startPoint, QPointF endPoint) {
        QPainterPath path;
        path.moveTo(startPoint);

        // Create control points for the Bézier curve
        QPointF controlPoint1(startPoint.x() + 50, startPoint.y() - 50);
        QPointF controlPoint2(endPoint.x() - 50, endPoint.y() - 50);

        // Add the curve to the path
        path.cubicTo(controlPoint1, controlPoint2, endPoint);

        // Set the path
        setPath(path);

        // Set the pen for the curve
        setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
};

class BezierCurvyLine : public QGraphicsPathItem {
public:
    BezierCurvyLine(QPointF startPoint, QPointF controlPoint1, QPointF controlPoint2, QPointF endPoint, QGraphicsItem *parent = nullptr)
        : QGraphicsPathItem(parent) {
        QPainterPath path(startPoint);
        path.cubicTo(controlPoint1, controlPoint2, endPoint); // Use cubic Bézier curve
        setPath(path);

        setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    }
};


#endif // MAINWINDOW_H
