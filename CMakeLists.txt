cmake_minimum_required(VERSION 3.22)
project(kgpt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# export compile_commands.json for IDEs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(QT_QML_GENERATE_QMLLS_INI ON)

find_package(Qt6 REQUIRED COMPONENTS
    Gui Qml Quick QuickControls2 WebEngineQuick)
# Find individual KDE Frameworks6 components
find_package(KF6CoreAddons REQUIRED)
find_package(KF6GlobalAccel REQUIRED)
find_package(KF6Kirigami REQUIRED)

qt_standard_project_setup(REQUIRES 6.8)

add_executable(appkgpt
    src/main.cpp
    src/PanelWindow.cpp
    src/HotkeyHelper.cpp
    src/SettingsManager.cpp
    resources/panel.qrc)

target_include_directories(appkgpt PRIVATE src)

target_link_libraries(appkgpt PRIVATE
    Qt6::Gui Qt6::Qml Qt6::Quick Qt6::QuickControls2 Qt6::WebEngineQuick
    KF6::CoreAddons KF6::GlobalAccel KF6::Kirigami)

# install for AppImage/Flatpak later
install(TARGETS appkgpt RUNTIME DESTINATION bin)