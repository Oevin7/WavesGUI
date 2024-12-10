//
// Created by kevin on 12/5/24.
//

#ifndef METADATAEXTRACTOR_H
#define METADATAEXTRACTOR_H
#include <string>
#include "../Song/Song.h"

std::unique_ptr<Song> getMetadata(std::string filePath);

#endif //METADATAEXTRACTOR_H
