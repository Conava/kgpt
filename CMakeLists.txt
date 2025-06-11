set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.16)

project(kgpt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS
    Gui
    Qml
    Quick
)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appkgpt
    main.cpp
)

qt_add_qml_module(appkgpt
    URI kgpt
    VERSION 1.0
    QML_FILES
        Main.qml
)

set_target_properties(appkgpt PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appkgpt PRIVATE
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appkgpt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
