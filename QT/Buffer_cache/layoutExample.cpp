#include "layoutExample.h"

layoutExample::layoutExample()
{
    // Create 3 times 4 buttons
    for( int j = 0; j < 3; ++j ) {
        but01[j] = new QPushButton("Button01");
        but02[j] = new QPushButton("Button02");
        but03[j] = new QPushButton("Button03");
        but04[j] = new QPushButton("Button04");
    }


    // Arrange buttons vertically
    // VBox = new QVBoxLayout;
    // VBox->addWidget(but01[0]);
    // VBox->addWidget(but02[0]);
    // VBox->addWidget(but03[0]);
    // VBox->addWidget(but04[0]);
    // // a box with a label around the buttons
    // VGroup = new QGroupBox("QVBoxLayout");
    // // the vertical box with the buttons
    // // put in the group box
    // VGroup->setLayout(VBox);
    // Arrange buttons horizontally
    HBox = new QHBoxLayout;
    HBox->addWidget(but01[1]);
    HBox->addWidget(but02[1]);
    HBox->addWidget(but03[1]);
    HBox->addWidget(but04[1]);
    // // a box with a label around the buttons
     HGroup = new QGroupBox("QHBoxLayout");
    // // the horizon. Box with the buttons
    // // put in the group box
    HGroup->setLayout(HBox);
    // // Arrange buttons on a grid
    // Grid = new QGridLayout;
    // Grid->addWidget(but01[2], 0, 0);
    // Grid->addWidget(but02[2], 0, 1);
    // Grid->addWidget(but03[2], 1, 0);
    // Grid->addWidget(but04[2], 1, 1);
    // // a box with a label around the buttons
    // GridGroup = new QGroupBox("QGridGroup");
    // // die Raster-Box mit den Buttons
    // // in die Group-Box stecken
    // GridGroup->setLayout(Grid);
    // create a vertical box
     AllBox = new QVBoxLayout(this);
    // // all group boxes vertically. Stuck box
    // AllBox->addWidget(VGroup);
     AllBox->addWidget(HGroup);
    // AllBox->addWidget(GridGroup);
    // set layout
    setLayout(AllBox);
    // Specify the window title
    setWindowTitle("Basic Layouts");

}
