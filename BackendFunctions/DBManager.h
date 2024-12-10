//
// Created by kevin on 12/5/24.
//

#ifndef DBMANAGERT_H
#define DBMANAGERT_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QDir>

#include "Song/Song.h"


class DBManager : public QSqlDatabase {
    QSqlDatabase db;
    QString dbName;

public:
    explicit DBManager();

    bool openDB();

    void insertSong(std::unique_ptr<Song> &song);

    void closeDB();

    void createDB();

    void setDatabaseName(QString dbName);

    QString getDatabaseName();

    void addDatabase(QString dbType);
};



#endif //DBMANAGERT_H
