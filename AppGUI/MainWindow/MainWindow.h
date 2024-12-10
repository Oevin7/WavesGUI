//
// Created by kevin on 12/5/24.
//

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qwidget.h>
#include <QHBoxLayout>
#include <QSplitter>
#include <QMainWindow>

#include "../Sidebar/Sidebar.h"


class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void addComponent(QWidget *widget);

    QSize getSize();

private:
    QFrame frame;
    QFrame *sidebarFrame;
    QSplitter *splitter;
    Sidebar *sidebar;
};



#endif //MAINWINDOW_H
