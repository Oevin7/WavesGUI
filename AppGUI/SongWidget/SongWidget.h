//
// Created by kevin on 12/5/24.
//

#ifndef SONGWIDGET_H
#define SONGWIDGET_H
#include <qicon.h>
#include <qwidget.h>
#include "../../BackendFunctions/Song/Song.h"

class SongWidget : public QWidget {
    Q_OBJECT
public:
    explicit SongWidget(Song *song, QWidget *parent = nullptr);

    void setSongTitle(QString songTitle);

    void setArtist(QString artist);

    void setAlbum(QString album);

    void setGenre(QString genre);

    void setDuration(int duration);

    QIcon getSongArt();

    QString getSongTitle();

    QString getArtist();

    QString getAlbum();

    QString getGenre();

    QString getDuration();

private:
    QString songTitle;
    QString artist;
    QString album;
    QString duration;
};



#endif //SONGWIDGET_H
