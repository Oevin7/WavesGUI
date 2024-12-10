//
// Created by kevin on 12/5/24.
//

#include "LibraryUpdater.h"

LibraryUpdater::LibraryUpdater(const QString path, DBManager dbManager, QObject *parent) : QObject(parent), path(path),
    dbManager(dbManager) {
    watcher = new QFileSystemWatcher(this);
    watcher->addPath(path);
    this->dbManager = dbManager;

    connect(watcher, &QFileSystemWatcher::directoryChanged, this, &LibraryUpdater::onDirectoryChanged);
    connect(watcher, &QFileSystemWatcher::fileChanged, this, &LibraryUpdater::onFileChanged);
};
