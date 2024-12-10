//
// Created by kevin on 12/5/24.
//

#ifndef LIBRARYCACHE_H
#define LIBRARYCACHE_H
#include "../../DBManager.h"
#include "../../Song/Song.h"

void cacheLibrary(DBManager dbManager, std::vector<std::unique_ptr<Song>> &songs);

#endif //LIBRARYCACHE_H
