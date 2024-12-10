//
// Created by kevin on 12/5/24.
//

#include "MainWindow.h"

#include "../../BackendFunctions/Metadata/metadataExtractor.h"
#include "../../BackendFunctions/Song/Song.h"
#include "../HomePage/Home.h"
#include "../Sidebar/Sidebar.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle(QString("Waves"));
    setMinimumSize(QSize(800, 600));

    splitter = new QSplitter(Qt::Horizontal, this);
    sidebarFrame = new QFrame();
    sidebarFrame->setFrameShape(QFrame::StyledPanel);
    sidebarFrame->setFrameShadow(QFrame::Plain);
    sidebarFrame->setStyleSheet("background-color: rgb(18, 21, 32);");
    sidebarFrame->setMaximumWidth(250);

    sidebar = new Sidebar(sidebarFrame);

    Home *home = new Home(this);
    splitter->addWidget(sidebarFrame);
    splitter->addWidget(home);

    Song *scratch = getMetadata("/home/kevin/CLionProjects/Waves/BackendFunctions/Metadata/Scratch.flac").get();
    SongWidget *widget = new SongWidget(scratch);
    SongGUI *songDisplay1 = new SongGUI("Recommended", widget);

    home->addElement(songDisplay1);

    setCentralWidget(splitter);
}
