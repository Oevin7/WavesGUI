#include <iostream>
#include "AppStart/run.h"
#include "BackendFunctions/Metadata/metadataExtractor.h"
#include "BackendFunctions/Indexing/indexMusicLib.h"

int main(int argc, char *argv[]) {
    //try {
        //indexMusicLib("/home/kevin/Music");
    //} catch (const std::exception& e) {
        //std::cerr << "Critical error: " << e.what() << std::endl;
    //}
    return run(argc, argv);
}
