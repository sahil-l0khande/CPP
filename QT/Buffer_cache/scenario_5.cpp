#include "mainwindow.h"


void MainWindow::search_blk_99()
{
    // QGraphicsView *view = new QGraphicsView(scene, this);
    // setCentralWidget(view);

    //scene = new QGraphicsScene(this);
    scene->clear();
    //scene->setSceneRect(0, 0, 800, 600);

    // Assign scene to the QGraphicsView in UI if available

    // Create the boxes and lines
    int initialYOffset = 30;
    Box *leftColumn[4];
    int leftX = -150;
    int leftYPositions[4] = {50, 200, 350, 500};
    QString leftLabels[4] = {"blkno 0 mod 4", "blkno 1 mod 4", "blkno 2 mod 4", "blkno 3 mod 4"};
    for (int i = 0; i < 4; ++i) {
        leftColumn[i] = new Box(leftX, leftYPositions[i], 100, 50, leftLabels[i]);
        scene->addItem(leftColumn[i]);
    }

    // Free list
    Box *freeleftColumn;
    int freeleftX = -150;
    int freeleftYPositions = 600;
    QString freeleftLabel = "Freelist header";
    freeleftColumn = new Box(freeleftX, freeleftYPositions, 100, 50, freeleftLabel);
    scene->addItem(freeleftColumn);

    // a vertical line between the left column and the 3x3 grid
    QGraphicsLineItem *verticalLine = new QGraphicsLineItem(
        10, initialYOffset, 10, initialYOffset + 550);
    verticalLine->setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    scene->addItem(verticalLine);

    // Create the 12 boxes
    Box *boxes[12];
    int xPositions[12] = {50, 300, 550, 50, 300, 550, 50, 300, 550, 50, 300, 550};
    int yPositions[12] = {50, 50, 50, 200, 200, 200, 350, 350, 350, 500, 500, 500};
    QString labels[12] = {"28", "4", "64", "17", "5", "97", "98", "50", "10", "3", "35", "99"};
    for (int i = 0; i < 12; ++i) {
        boxes[i] = new Box(xPositions[i], yPositions[i], 100, 50, labels[i]);
        scene->addItem(boxes[i]);
    }

    // Define curvy lines
    QGraphicsItem *lines[] = {
        new CurvyLine(QPointF(150, 525), QPointF(300, 225)),
        new CurvyLine(QPointF(150, 90), QPointF(550, 245)),
        new CurvyLine(QPointF(freeleftX + 95, freeleftYPositions + 25), QPointF(50 + 5, initialYOffset + 2 * 235 + 25)),
        new BezierCurvyLine(QPointF(300, 75), QPointF(125, 100), QPointF(600, 200), QPointF(400, 225)),
        new BezierCurvyLine(QPointF(xPositions[1] + 100, yPositions[1] + 25), QPointF(xPositions[1] + 170, yPositions[1] - 50), QPointF(xPositions[0] - 80, yPositions[0] - 50), QPointF(xPositions[0] + 3, yPositions[0] + 25)),
        new BezierCurvyLine(QPointF(xPositions[5] + 100, yPositions[5] + 25), QPointF(xPositions[5] + 300, yPositions[5] + 150), QPointF(xPositions[8] - 250, yPositions[8] - 50), QPointF(xPositions[8] + 5, yPositions[8] + 25)),
        new BezierCurvyLine(QPointF(xPositions[8] + 100, yPositions[8] + 25), QPointF(xPositions[8] + 500, yPositions[8] + 250), QPointF(freeleftX + 200, freeleftYPositions + 100), QPointF(freeleftX + 95, freeleftYPositions + 40))
    };

    // Pen for dotted horizontal lines
    QPen dottedPen(Qt::red);         // Red color
    dottedPen.setStyle(Qt::DotLine); // Dotted line style
    dottedPen.setWidth(2);           // Thickness of the line


    // Define y-offset for horizontal lines and box spacing
    int lineHeightOffset = 25; // Adjust height offset to match the box centers

    // Loop through the boxes for horizontal lines and labels
    for (int i = 0; i < 12; ++i) {
        // Define the start and end points for each horizontal line
        QPointF lineStart(xPositions[i] - 50, yPositions[i] + lineHeightOffset); // Start slightly left of the box
        QPointF lineEnd(xPositions[i] + 200, yPositions[i] + lineHeightOffset);  // Extend beyond the box's right edge

        // Create the horizontal dotted line
        QGraphicsLineItem *dottedLine = new QGraphicsLineItem(QLineF(lineStart, lineEnd));
        dottedLine->setPen(dottedPen);
        dottedLine->setZValue(-1); // Send dotted line to the background
        scene->addItem(dottedLine);


        // Create the box
        QGraphicsRectItem *box = new QGraphicsRectItem(xPositions[i], yPositions[i], 100, 50); // Example box
        box->setBrush(Qt::blue); // Set the color of the box
        box->setZValue(1);       // Bring the box to the foreground
        scene->addItem(box);

        // Add label on the box
        QGraphicsTextItem *label = new QGraphicsTextItem(labels[i]);
        label->setDefaultTextColor(Qt::white); // Label color
        label->setFont(QFont("Arial", 14, QFont::Bold)); // Label font
        label->setPos(xPositions[i] + 30, yPositions[i] + 10); // Position label inside the box
        label->setZValue(2); // Ensure the label is on top of everything
        scene->addItem(label);
    }

    // Add the lines to the scene
    for (auto line : lines) {
        scene->addItem(line);
    }

    QGraphicsTextItem *delayLabel = new QGraphicsTextItem("Busy");
    delayLabel->setDefaultTextColor(Qt::white); // Set text color
    delayLabel->setFont(QFont("Arial", 12, QFont::Bold)); // Set font style
    delayLabel->setPos(xPositions[11] + 30, yPositions[9] + 60); // Position slightly below box "3"
    scene->addItem(delayLabel);
    // QGraphicsTextItem *delayLabel2 = new QGraphicsTextItem("delay");
    // delayLabel2->setDefaultTextColor(Qt::white); // Set text color
    // delayLabel2->setFont(QFont("Arial", 12, QFont::Bold)); // Set font style
    // delayLabel2->setPos(xPositions[4] + 30, yPositions[4] + 60); // Position slightly below box "3"
    // scene->addItem(delayLabel2);
}
