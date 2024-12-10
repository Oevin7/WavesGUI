//
// Created by kevin on 12/5/24.
//
#include "indexMusicLib.h"
#include <filesystem>
#include <unordered_set>

#include "../DBManager.h"
#include "../Song/Song.h"
#include "../Metadata/metadataExtractor.h"

void indexMusicLib(std::string pathToMusicDir, DBManager dbManager) {
    std::filesystem::path musicDir(pathToMusicDir);
    std::vector<std::unique_ptr<Song>> returnVec = std::vector<std::unique_ptr<Song>>();

    const std::unordered_set<std::string> audioExtensions = {
        ".mp3", ".flac", ".wav", ".aac"
    };

    int id = 0;
    for (const auto& entry : std::filesystem::directory_iterator(musicDir)) {
        if (entry.is_directory()) {
            indexMusicLib(entry.path(), dbManager);
        } else {
            if (audioExtensions.find(entry.path().extension().string()) != audioExtensions.end()) {
                try {
                    id += 1;
                    std::unique_ptr<Song> song = getMetadata(entry.path());
                    dbManager.insertSong(song);
                } catch (const std::exception& e) {
                    std::cerr << "Standard error processing file " << entry.path() << ": " << e.what() << std::endl;
                } catch (...) {
                    std::cerr << "Unknown error processing file " << entry.path() << std::endl;
                }
            }
        }
    }
}
