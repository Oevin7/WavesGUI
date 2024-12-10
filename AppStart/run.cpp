//
// Created by kevin on 12/5/24.
//

#include "run.h"

#include <iostream>
#include <QApplication>
#include <qfile.h>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>

#include "../AppGUI/MainWindow/MainWindow.h"
#include "../BackendFunctions/Indexing/SongLibraryCache/libraryCache.h"
#include "../BackendFunctions/Indexing/SongLibraryCache/LibraryUpdater/LibraryUpdater.h"
#include "../AppStart/CreateAppDirectories/createAppDirs.h"
#include <QFileSelector>

void performIntitialSetup(LibraryUpdater &libraryUpdater, DBManager &dbManager) {

    dbManager.addDatabase(QString("QSQLITE"));
    dbManager.openDB();

    try {
        createAppDirs();
        createFirstRunFile(libraryUpdater.getFirstRunInfo());
        createDBFile(dbManager);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    if (readFirstRunFile()) {
        libraryUpdater.updateLibrary();
        changeFirstRunStatus(libraryUpdater.getFirstRunInfo());
        indexMusicLib("/home/kevin/Music", dbManager);
    } else if (libraryUpdater.updateLibrary()) {
        std::cout << "We got here" << std::endl;
        indexMusicLib("/home/kevin/Music", dbManager);
    }
}

int run(int argc, char **argv) {
    std::unique_ptr<QApplication> app = std::make_unique<QApplication>(argc, argv);
    DBManager dbManager;
    dbManager.setDatabaseName("musicIdx");

    LibraryUpdater libraryUpdater = LibraryUpdater("/home/kevin/Music", dbManager);

    QFuture<void> future = QtConcurrent::run(performIntitialSetup, std::ref(libraryUpdater), std::ref(dbManager));

    std::unique_ptr<MainWindow> window = std::make_unique<MainWindow>();

    window->show();

    return QApplication::exec();
}