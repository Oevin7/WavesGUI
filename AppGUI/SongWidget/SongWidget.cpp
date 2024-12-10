//
// Created by kevin on 12/5/24.
//

#include "SongWidget.h"

SongWidget::SongWidget(Song *song, QWidget *parent) : QWidget(parent) {
    if (song != nullptr) {
        this->setSongTitle(QString(song->getTitle().toCString()));
        this->setArtist(QString(song->getArtist().toCString()));
        this->setAlbum(QString(song->getAlbum().toCString()));
    }
}