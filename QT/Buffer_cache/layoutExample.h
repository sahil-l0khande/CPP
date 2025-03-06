#ifndef MYLAYOUT_H
#define MYLAYOUT_H
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLabel>
class layoutExample : public QWidget
{
    Q_OBJECT
public:
    layoutExample();
private:
    QPushButton *but01[3], *but02[3],
        *but03[3], *but04[3];
    QVBoxLayout* AllBox;
    QVBoxLayout* VBox;
    QHBoxLayout* HBox;
    QGridLayout* Grid;
    QGroupBox* VGroup;
    QGroupBox* HGroup;
    QGroupBox* GridGroup;
    QLabel* label = new QLabel("Sahil");
};

#endif // LAYOUTEXAMPLE_H
