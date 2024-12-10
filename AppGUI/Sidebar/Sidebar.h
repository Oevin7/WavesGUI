//
// Created by kevin on 12/5/24.
//

#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <qboxlayout.h>
#include <QFrame>
#include <qwidget.h>
#include <QLabel>


class Sidebar : public QWidget {
    Q_OBJECT
public:
    Sidebar(QWidget *parent = nullptr);

    void addWidget(QWidget *widget);

private:
    QVBoxLayout *layout;
    QLabel *logo;
};



#endif //SIDEBAR_H
