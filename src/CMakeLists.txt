# A1_Maze_CPP C++ zekkoaem & stranger

cmake_minimum_required(VERSION 3.5)

project(A1_Maze_CPP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(build)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(Qt6 REQUIRED COMPONENTS Gui)

# --------------------------------------------------------------------------------------- Libraries

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# --------------------------------------------------------------------------------- Declaring files

set(MODEL_SOURCES
    model/common/includes/create.hpp
    model/common/includes/data.hpp
    model/common/includes/load.hpp
    model/common/includes/save.hpp
    model/common/includes/solve.hpp

    model/common/modules/common.cpp

    model/cave/includes/cave_data.hpp
    model/cave/includes/cave_load.hpp
    model/cave/includes/cave_save.hpp
    model/cave/includes/cellular_automaton.hpp

    model/cave/modules/cave_data.cpp
    model/cave/modules/cave_load.cpp
    model/cave/modules/cave_save.cpp
    model/cave/modules/cellular_automaton.cpp

    model/maze/includes/bfs_algorithm.hpp
    model/maze/includes/dfs_algorithm.hpp
    model/maze/includes/eller_algorithm.hpp
    model/maze/includes/maze_data.hpp
    model/maze/includes/maze_load.hpp
    model/maze/includes/maze_save.hpp
    model/maze/includes/q_learning.hpp

    model/maze/modules/bfs_algorithm.cpp
    model/maze/modules/dfs_algorithm.cpp
    model/maze/modules/eller_algorithm.cpp
    model/maze/modules/maze_data.cpp
    model/maze/modules/maze_load.cpp
    model/maze/modules/maze_save.cpp
    model/maze/modules/q_learning.cpp
)

set(CONTROLLER_SOURCES
    controller/controller.hpp
)

set(VIEW_SOURCES
    view/modules/base_widget.cpp
    view/modules/cave_widget.cpp
    view/modules/maze_widget.cpp
    view/modules/menu_widget.cpp

    view/main.cpp
)

set(MOC_HEADERS
    view/includes/base_widget.hpp
    view/includes/cave_widget.hpp
    view/includes/maze_widget.hpp
    view/includes/menu_widget.hpp
)

set(UIS
    view/uis/cave_widget.ui
    view/uis/maze_widget.ui
    view/uis/menu_widget.ui
)

set(QRC
    view/fonts/fonts.qrc
    view/images/images.qrc
)

set(PROJECT_SOURCES
    ${CONTROLLER_SOURCES}
    ${MODEL_SOURCES}
    ${VIEW_SOURCES}

    ${QRC}

    ${MOC_HEADERS}
    ${UIS}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(A1_Maze_CPP
        MANUAL_FINALIZATION
	${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET A1_Maze_CPP APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(A1_Maze_CPP SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(A1_Maze_CPP
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(A1_Maze_CPP PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(A1_Maze_CPP PRIVATE Qt6::Gui)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.A1_Maze_CPP)
endif()
set_target_properties(A1_Maze_CPP PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS A1_Maze_CPP
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(A1_Maze_CPP)
endif()
