//
// Created by kevin on 12/5/24.
//

#ifndef LIBRARYUPDATER_H
#define LIBRARYUPDATER_H
#include <QFileSystemWatcher>
#include <qobject.h>
#include "../../../Indexing/indexMusicLib.h"
#include <fstream>
#include <QDir>
#include <QStandardPaths>


class LibraryUpdater : public QObject {
    Q_OBJECT
    QString path;
    QFileSystemWatcher *watcher;
    bool fileChanged = false;
    bool directoryChanged = false;
    bool firstRun = true;
    QString firstRunFilePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + QDir::separator()
    + ".waves_config" + QDir::separator() + "firstRunInfo" + QDir::separator();
    DBManager dbManager;

public:
    std::vector<std::unique_ptr<Song>> songs;

    explicit LibraryUpdater(QString path, DBManager dbManager, QObject *parent = nullptr);

    bool updateLibrary() {
        return fileChanged || directoryChanged;
    }

    void firstIndex() {
        indexMusicLib(this->path.toStdString(), this->dbManager);
        this->firstRun = false;
    }

    bool getFirstRunInfo() {
        return firstRun;
    }

private slots:
    void onFileChanged() {
        fileChanged = true;
        indexMusicLib(this->path.toStdString(), this->dbManager);
    }

    void onDirectoryChanged() {
        directoryChanged = true;
        indexMusicLib(this->path.toStdString(), this->dbManager);
    }
};



#endif //LIBRARYUPDATER_H
