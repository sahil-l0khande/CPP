#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // Layouts
    mainLayout = new QHBoxLayout();
    menuLayout = new QVBoxLayout();
    // Parent Button
    QPushButton *parentButton = new QPushButton("Getblk");
    menuLayout->addWidget(parentButton);

    // Child Buttons (Initially Hidden)
    QPushButton *childButton1 = new QPushButton("Search blk 4");
    QPushButton *childButton2 = new QPushButton("Remove blk 4");
    QPushButton *childButton3 = new QPushButton("Search blk 18");
    QPushButton *childButton4 = new QPushButton("Assign to 18");
    QPushButton *childButton5 = new QPushButton("Search blk 18 (delayed)");
    QPushButton *childButton6 = new QPushButton("Reassign 4 to 18");
    QPushButton *childButton7 = new QPushButton("Search 18 empty list");
    QPushButton *childButton8 = new QPushButton("Search 99");
    QPushButton *backButton = new QPushButton("Back");

    // Set button sizes to medium (150x50)
    parentButton->setFixedSize(170, 50);
    childButton1->setFixedSize(170, 50);
    childButton2->setFixedSize(170, 50);
    childButton3->setFixedSize(170, 50);
    childButton4->setFixedSize(170, 50);
    childButton5->setFixedSize(170, 50);
    childButton6->setFixedSize(170, 50);
    childButton7->setFixedSize(170, 50);
    childButton8->setFixedSize(170, 50);
    backButton->setFixedSize(170, 50);

    childButton1->setVisible(false);
    childButton2->setVisible(false);
    childButton3->setVisible(false);
    childButton4->setVisible(false);
    childButton5->setVisible(false);
    childButton6->setVisible(false);
    childButton7->setVisible(false);
    childButton8->setVisible(false);
    backButton->setVisible(false);

    menuLayout->addWidget(childButton1);
    menuLayout->addWidget(childButton2);
    menuLayout->addWidget(childButton3);
    menuLayout->addWidget(childButton4);
    menuLayout->addWidget(childButton5);
    menuLayout->addWidget(childButton6);
    menuLayout->addWidget(childButton7);
    menuLayout->addWidget(childButton8);
    menuLayout->addWidget(backButton);
    menuLayout->setSpacing(30);  // Space between buttons

    menuLayout->setAlignment(Qt::AlignLeft);  // Align menu to the left


    // Graphics Scene and View
    scene = new QGraphicsScene();
    graphicsView = new QGraphicsView(scene);
    graphicsView->setFixedSize(1300, 750);  // Set fixed size for scene view

    // Add layouts to main layout
    mainLayout->addLayout(menuLayout);
    mainLayout->addWidget(graphicsView);

    // Set layout to central widget
    centralWidget->setLayout(mainLayout);

    // Parent Button Click: Show Child Buttons
    connect(parentButton, &QPushButton::clicked, this, [=]() {
        childButton1->setVisible(true);
        childButton2->setVisible(true);
        childButton3->setVisible(true);
        childButton4->setVisible(true);
        childButton5->setVisible(true);
        childButton6->setVisible(true);
        childButton7->setVisible(true);
        childButton8->setVisible(true);
        backButton->setVisible(true);
        parentButton->setVisible(false);
    });

    // Back Button Click: Hide Child Buttons, Show Parent Button
    connect(backButton, &QPushButton::clicked, this, [=]() {
        childButton1->setVisible(false);
        childButton2->setVisible(false);
        childButton3->setVisible(false);
        childButton4->setVisible(false);
        childButton5->setVisible(false);
        childButton6->setVisible(false);
        childButton7->setVisible(false);
        childButton8->setVisible(false);
        backButton->setVisible(false);
        parentButton->setVisible(true);
        scene->clear();  // Clear the graphics when going back
    });

    // Child Buttons Click: Show Different Shapes
    connect(childButton1, &QPushButton::clicked, this, [=]() { scenario_1(); });
    connect(childButton2, &QPushButton::clicked, this, [=]() { scenario_2(); });
    connect(childButton3, &QPushButton::clicked, this, [=]() { search_blk_18(); });
    connect(childButton4, &QPushButton::clicked, this, [=]() { assign_blk_18(); });
    connect(childButton5, &QPushButton::clicked, this, [=]() { search_blk_18_delayed(); });
    connect(childButton6, &QPushButton::clicked, this, [=]() { reassign_blk_to_18(); });
    connect(childButton7, &QPushButton::clicked, this, [=]() { search_blk_18_in_emptylist(); });
    connect(childButton8, &QPushButton::clicked, this, [=]() { search_blk_99(); });
    //introduction();

}


MainWindow::~MainWindow() {}

// void MainWindow::introduction()
// {
//     // Clear previous scene items
//     scene->clear();

//     // Adjustments
//     int initialYOffset = 70; // Increased to move diagram down
//     int leftX = -150;
//     int leftYPositions[4] = {50 + 40, 170 + 40, 290 + 40, 410 + 40}; // Shifted down
//     QString leftLabels[4] = {"blkno 0 mod 4", "blkno 1 mod 4", "blkno 2 mod 4", "blkno 3 mod 4"};

//     // Left column boxes
//     Box *leftColumn[4];
//     for (int i = 0; i < 4; ++i) {
//         leftColumn[i] = new Box(leftX, leftYPositions[i], 100, 50, leftLabels[i]);
//         scene->addItem(leftColumn[i]);
//     }

//     // Free list header
//     int freeleftYPositions = 640; // Moved down
//     Box *freeleftColumn = new Box(leftX, freeleftYPositions, 100, 50, "Freelist header");
//     scene->addItem(freeleftColumn);

//     // Vertical separator line
//     QGraphicsLineItem *verticalLine = new QGraphicsLineItem(10, initialYOffset, 10, initialYOffset + 550);
//     verticalLine->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
//     scene->addItem(verticalLine);

//     // Adjusted positions for 12 boxes (closer spacing)
//     int xPositions[12] = {50, 250, 450, 50, 250, 450, 50, 250, 450, 50, 250, 450};
//     int yPositions[12] = {50 + 40, 50 + 40, 50 + 40, 170 + 40, 170 + 40, 170 + 40,
//                           290 + 40, 290 + 40, 290 + 40, 410 + 40, 410 + 40, 410 + 40};
//     QString labels[12] = {"28", "4", "64", "17", "5", "97", "98", "50", "10", "3", "35", "99"};

//     // Create smaller boxes
//     Box *boxes[12];
//     for (int i = 0; i < 12; ++i) {
//         boxes[i] = new Box(xPositions[i], yPositions[i], 80, 40, labels[i]); // Reduced size
//         scene->addItem(boxes[i]);
//     }

//     // Dotted horizontal lines
//     QPen dottedPen(Qt::red);
//     dottedPen.setStyle(Qt::DotLine);
//     dottedPen.setWidth(2);
//     int lineHeightOffset = 20;

//     for (int i = 0; i < 12; ++i) {
//         QPointF lineStart(xPositions[i] - 40, yPositions[i] + lineHeightOffset);
//         QPointF lineEnd(xPositions[i] + 180, yPositions[i] + lineHeightOffset);

//         QGraphicsLineItem *dottedLine = new QGraphicsLineItem(QLineF(lineStart, lineEnd));
//         dottedLine->setPen(dottedPen);
//         dottedLine->setZValue(-1);
//         scene->addItem(dottedLine);

//         // Blue box with label
//         QGraphicsRectItem *box = new QGraphicsRectItem(xPositions[i], yPositions[i], 80, 40);
//         box->setBrush(Qt::blue);
//         box->setZValue(1);
//         scene->addItem(box);

//         QGraphicsTextItem *label = new QGraphicsTextItem(labels[i]);
//         label->setDefaultTextColor(Qt::white);
//         label->setFont(QFont("Arial", 12, QFont::Bold));
//         label->setPos(xPositions[i] + 20, yPositions[i] + 10);
//         label->setZValue(2);
//         scene->addItem(label);
//     }
// }

// Override `paintEvent` to draw inside `GraphicsWidget`
void GraphicsWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw Example Shapes
    painter.setBrush(Qt::blue);
    painter.drawEllipse(100, 100, 100, 100);

    painter.setBrush(Qt::green);
    painter.drawRect(200, 150, 150, 75);
}

// void MainWindow::showParentScreen()
// {
//     stackedWidget->setCurrentWidget(parentScreen);
// }

// void MainWindow::showChildScreen()
// {
//     stackedWidget->setCurrentWidget(childScreen);
// }
