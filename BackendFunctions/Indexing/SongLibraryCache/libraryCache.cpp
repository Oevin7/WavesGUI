//
// Created by kevin on 12/5/24.
//

#include <QFileSystemWatcher>
#include "libraryCache.h"

#include <iostream>
#include <QApplication>
#include <sqlite3.h>

#include "../../DBManager.h"
#include "../../Song/Song.h"

void cacheLibrary(DBManager dbManager, std::vector<std::unique_ptr<Song>> &songs) {
    for (auto& song : songs) {
        dbManager.insertSong(song);
    }
}


