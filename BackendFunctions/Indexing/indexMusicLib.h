//
// Created by kevin on 12/5/24.
//

#ifndef INDEXMUSICLIB_H
#define INDEXMUSICLIB_H
#include <iostream>
#include <memory>
#include <qstring.h>
#include <vector>

#include "../DBManager.h"
#include "../Song/Song.h"

void indexMusicLib(std::string pathToMusicDir, DBManager dbManager);

#endif //INDEXMUSICLIB_H
