//
// Created by kevin on 12/5/24.
//

#include "DBManager.h"
#include <filesystem>
#include <fstream>

DBManager::DBManager() {
    if (openDB()) {
        this->createDB();  // Ensure table creation
    }
}

void DBManager::createDB() {
    if (openDB()) {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS musicIdx ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                    "path TEXT,"
                    "title TEXT,"
                    "artist TEXT,"
                    "album TEXT,"
                    "genre TEXT,"
                    "year INTEGER,"
                    "duration INTEGER,"
                    "trackNum INTEGER,"
                    "lastModified INTEGER)");
    }
}

bool DBManager::openDB() {
    return db.open();
}

void DBManager::closeDB() {
    db.close();
}

void DBManager::insertSong(std::unique_ptr<Song> &song) {

    if (openDB()) {
        song->printSongInfo();

        QSqlQuery query;
        if(!query.prepare("INSERT INTO musicIdx (path, title, artist, album, genre, year, duration, trackNum, lastModified)"
                      "VALUES (:path, :title, :artist, :album, :genre, :year, :duration, :trackNum, :lastModified)")) {
            qDebug() << "Error inserting into database file" << query.lastError().text();
                      }
        query.bindValue(":path", song->getSongPath().c_str());
        query.bindValue(":title", song->getTitle().toCString());
        query.bindValue(":artist", song->getArtist().toCString());
        query.bindValue(":album", song->getAlbum().toCString());
        query.bindValue(":genre", song->getGenre().toCString());
        query.bindValue(":year", song->getYear());
        query.bindValue(":duration", song->getDuration());
        query.bindValue(":trackNum", song->getTrackNum());
        query.bindValue(":lastModified", song->getLastModified());

        if (!query.exec()) {
            qDebug() << "Error inserting song data" << query.lastError();
        }
    }
}

void DBManager::setDatabaseName(QString dbName) {
    this->dbName = dbName;
    db.setDatabaseName(this->dbName);
}



QString DBManager::getDatabaseName() {
    return this->dbName;
}

void DBManager::addDatabase(QString dbType) {
    this->db = QSqlDatabase::addDatabase(dbType);
}

