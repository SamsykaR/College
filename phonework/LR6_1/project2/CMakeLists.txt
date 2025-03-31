cmake_minimum_required(VERSION 3.16)

project(project2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appproject2
    main.cpp
)

qt_add_qml_module(appproject2
    URI project2
    VERSION 1.0
    QML_FILES main.qml
    QML_FILES pages/home.qml
            QML_FILES pages/profile.qml
            QML_FILES pages/about.qml
            QML_FILES pages/editProfile.qml
)

set_target_properties(appproject2 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appproject2
    PRIVATE Qt6::Quick)

install(TARGETS appproject2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
