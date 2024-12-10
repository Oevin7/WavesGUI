//
// Created by kevin on 12/5/24.
//

#ifndef SONG_H
#define SONG_H
#include <iostream>
#include <qdatetime.h>
#include <string>
#include <taglib/tag.h>


class Song {
    int id;
    std::string pathToSong;
    TagLib::String title;
    TagLib::String artist;
    TagLib::String album;
    TagLib::String genre;
    u_int year = 0;
    int duration = 0;
    int trackNum = 0;
    qint64 lastModified;

public:
    Song();
    Song(std::string pathToSong, TagLib::String title,
                  TagLib::String artist, TagLib::String album, TagLib::String genre,
                  u_int year, int duration, int songId, qint64 lastModified);

    void setSongPath(std::string pathToSong);

    void setAlbumArt(std::string albumArt);

    void setSong(std::string song);

    void setTitle(std::string title);

    void setArtist(std::string artist);

    void setAlbum(std::string album);

    void setGenre(std::string genre);

    void setYear(std::string year);

    void setDuration(std::string duration);

    std::string getSongPath();

    TagLib::String getTitle();

    TagLib::String getArtist();

    TagLib::String getAlbum();

    TagLib::String getGenre();

    u_int getYear();

    int getDuration();

    int getTrackNum();

    std::string toString();

    void printSongInfo() const;

    qint64 getLastModified();
};



#endif //SONG_H
