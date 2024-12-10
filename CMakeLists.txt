cmake_minimum_required(VERSION 3.29)
project(Waves)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Sql
        REQUIRED)

find_package(TagLib REQUIRED)

find_package(Qt6Sql REQUIRED)

include_directories(/usr/include/taglib)

add_executable(Waves main.cpp
        AppGUI/MainWindow/MainWindow.cpp
        AppGUI/MainWindow/MainWindow.h
        AppStart/run.cpp
        AppStart/run.h
        AppGUI/Sidebar/Sidebar.cpp
        AppGUI/Sidebar/Sidebar.h
        AppGUI/Sidebar/SidebarButtons/SidebarButtons.cpp
        AppGUI/Sidebar/SidebarButtons/SidebarButtons.h
        AppGUI/HomePage/Home.cpp
        AppGUI/HomePage/Home.h
        AppGUI/SongWidget/SongWidget.cpp
        AppGUI/SongWidget/SongWidget.h
        BackendFunctions/Metadata/metadataExtractor.cpp
        BackendFunctions/Metadata/metadataExtractor.h
        BackendFunctions/Song/Song.cpp
        BackendFunctions/Song/Song.h
        BackendFunctions/Indexing/indexMusicLib.cpp
        BackendFunctions/Indexing/indexMusicLib.h
        BackendFunctions/Indexing/SongLibraryCache/libraryCache.cpp
        BackendFunctions/Indexing/SongLibraryCache/libraryCache.h
        BackendFunctions/Indexing/SongLibraryCache/LibraryUpdater/LibraryUpdater.cpp
        BackendFunctions/Indexing/SongLibraryCache/LibraryUpdater/LibraryUpdater.h
        BackendFunctions/DBManager.cpp
        BackendFunctions/DBManager.h
        AppStart/CreateAppDirectories/createAppDirs.cpp
        AppStart/CreateAppDirectories/createAppDirs.h
        AppGUI/HomePage/SongGUI.cpp
        AppGUI/HomePage/SongGUI.h
)
target_link_libraries(Waves PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        /usr/lib/libtag.so
        Qt6::Sql
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fsanitize=address")
