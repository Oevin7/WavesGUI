//
// Created by kevin on 12/6/24.
//

#ifndef SONGDISPLAY_H
#define SONGDISPLAY_H
#include <qwidget.h>

#include "../SongWidget/SongWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>


class SongGUI: public QWidget {
    Q_OBJECT

    QString title;
    QImage image;
    SongWidget *song;

    QVBoxLayout vLayout;
    QHBoxLayout hLayout;

    public:
    explicit SongGUI(QString title, SongWidget *song, QWidget *parent = 0);
};



#endif //SONGDISPLAY_H
