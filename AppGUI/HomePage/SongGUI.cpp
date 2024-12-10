//
// Created by kevin on 12/6/24.
//

#include "SongGUI.h"

#include <QLabel>

SongGUI::SongGUI(QString title, SongWidget* song, QWidget *parent) {
    this->title = title;
    this->image = QImage("/home/kevin/CLionProjects/Waves/AppGUI/icons/Untitled design.svg");
    this->song = song;

    QImage *image = new QImage(this->image);
    QLabel *imageLabel = new QLabel();

    imageLabel->setPixmap(QPixmap::fromImage(*image));

    QLabel *label = new QLabel(title);

    QLabel *songTitle = new QLabel(song->getSongTitle());
    QLabel *songArtist = new QLabel(song->getArtist());

    hLayout.addWidget(imageLabel);
    vLayout.addWidget(songTitle);
    hLayout.addWidget(songArtist);

}
