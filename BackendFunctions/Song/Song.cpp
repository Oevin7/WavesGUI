//
// Created by kevin on 12/5/24.
//

#include "Song.h"

#include <utility>

Song::Song() {}

Song::Song(std::string pathToSong, TagLib::String title,
                  TagLib::String artist, TagLib::String album, TagLib::String genre,
                  u_int year, int duration, int trackNum, qint64 lastModified) {
    this->pathToSong = std::move(pathToSong);
    this->title = title;
    this->artist = artist;
    this->album = album;
    this->genre = genre;
    this->year = year;
    this->duration = duration;
    this->trackNum = trackNum;
    this->lastModified = lastModified;
}

void Song::setArtist(std::string title) {
    this->artist = title;
}

void Song::setTitle(std::string title) {
    this->title = title;
}

void Song::printSongInfo() const {
    std::cout << title << std::endl;
    std::cout << artist << std::endl;
    std::cout << album << std::endl;
    std::cout << genre << std::endl;
    std::cout << year << std::endl;
    std::cout << duration << std::endl;
}

void Song::setSongPath(std::string pathToSong) {
    this->pathToSong = std::move(pathToSong);
}

std::string Song::getSongPath() {
    return this->pathToSong;
}

TagLib::String Song::getTitle() {
    return this->title;
}

TagLib::String Song::getArtist() {
    return this->artist;
}

TagLib::String Song::getAlbum() {
    return this->album;
}

TagLib::String Song::getGenre() {
    return this->genre;
}

u_int Song::getYear() {
    return year;
}

int Song::getDuration() {
    return duration;
}

int Song::getTrackNum() {
    return this->trackNum;
}

qint64 Song::getLastModified() {
    return this->lastModified;
}
