//
// Created by kevin on 12/5/24.
//
#include "metadataExtractor.h"
#include <iostream>
#include <qfileinfo.h>
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include "../Song/Song.h"

std::unique_ptr<Song> getMetadata(std::string filePath) {
    TagLib::FileRef file(filePath.c_str());
    std::unique_ptr<Song> song;

    if (!file.isNull() && file.tag()) {
        const TagLib::Tag *tag = file.tag();
        const TagLib::AudioProperties *properties = file.audioProperties();

        QFileInfo fileInfo(filePath.c_str());
        qint64 lastModified = fileInfo.lastModified().toSecsSinceEpoch();

        song = std::make_unique<Song>(
            filePath,
            tag->title(),
            tag->artist(),
            tag->album(),
            tag->genre(),
            tag->year(),
            properties->lengthInSeconds(),
            tag->track(),
            lastModified
        );
    } else {
        std::cerr << "Error: Could not open file!" << std::endl;
    }

    return song;
}

