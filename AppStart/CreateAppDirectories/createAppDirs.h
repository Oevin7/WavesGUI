//
// Created by kevin on 12/6/24.
//

#ifndef CREATEAPPDIRS_H
#define CREATEAPPDIRS_H
#include "../../BackendFunctions/DBManager.h"

bool createAppDirs();

void createFirstRunFile(bool firstRunStatus);
void changeFirstRunStatus(bool firstRunStatus);

void createDBFile(DBManager dbManager);
void writeAppPathToDisk();

bool readFirstRunFile();

#endif //CREATEAPPDIRS_H
