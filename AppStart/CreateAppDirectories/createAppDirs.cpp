//
// Created by kevin on 12/6/24.
//

#include "createAppDirs.h"

#include <fstream>
#include <QStandardPaths>
#include <QDir>

#include "../../BackendFunctions/Indexing/SongLibraryCache/LibraryUpdater/LibraryUpdater.h"

QString appDataPath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation) +
                      QDir::separator() + ".waves_config" + QDir::separator();

bool createAppDirs() {
    QDir dir;

    if (dir.exists(appDataPath)) {
        return true;
    }

    if (!dir.mkdir(appDataPath)) {
        throw std::runtime_error("Failed to create directory");
    }
    return false;
}

void createFirstRunFile(bool firstRunStatus) {
    QString fullPath = appDataPath + "firstRunStatus.txt";
    std::ofstream fileOutput(fullPath.toStdString());
    bool status = firstRunStatus;

    try {
        fileOutput << status;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    fileOutput.close();
}

void changeFirstRunStatus(bool firstRunStatus) {
    QString fullPath = appDataPath + "firstRunStatus.txt";
    std::ofstream fileOutput(fullPath.toStdString());

    bool status = !firstRunStatus;

    try {
        fileOutput << status;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    fileOutput.close();
}


void createDBFile(DBManager dbManager) {
    QString fullPath = appDataPath + dbManager.getDatabaseName() + ".db";
    std::cout << fullPath.toStdString();
    dbManager.setDatabaseName(fullPath);

    dbManager.createDB();
}

bool readFirstRunFile() {
    QString fullPath = appDataPath + "firstRunStatus.txt";
    std::ifstream fileInput(fullPath.toStdString());
    bool status = true;

    try {
        fileInput >> status;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    fileInput.close();
    return status;

}
