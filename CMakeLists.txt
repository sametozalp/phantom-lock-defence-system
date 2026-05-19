cmake_minimum_required(VERSION 3.16)

project(phantom-lock-defence-system VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Location Positioning QuickWidgets)

set(PROJECT_SOURCES
        main.cpp
        presentation/screen/dashboardwindow.cpp
        presentation/screen/dashboardwindow.h
        presentation/ui/dashboardwindow.ui
        presentation/component/topbar.h presentation/component/topbar.cpp presentation/ui/topbar.ui
        presentation/component/vehicledetail.h presentation/component/vehicledetail.cpp presentation/ui/vehicledetail.ui
)

set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_CURRENT_SOURCE_DIR}/presentation/ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(phantom-lock-defence-system
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        presentation/component/map/Map.qml
        resources.qrc
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET phantom-lock-defence-system APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(phantom-lock-defence-system SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(phantom-lock-defence-system
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(phantom-lock-defence-system PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Location
    Qt${QT_VERSION_MAJOR}::Positioning
    Qt${QT_VERSION_MAJOR}::QuickWidgets
)

target_include_directories(phantom-lock-defence-system PRIVATE
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/presentation/screen
    ${CMAKE_SOURCE_DIR}/presentation/component
    ${CMAKE_SOURCE_DIR}/presentation/ui

)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.phantom-lock-defence-system)
endif()
set_target_properties(phantom-lock-defence-system PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS phantom-lock-defence-system
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(phantom-lock-defence-system)
endif()
