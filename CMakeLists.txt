cmake_minimum_required(VERSION 3.16)

project(PokerTime VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appPokerTime
    resource.qrc
    main.cpp
)

qt_add_qml_module(appPokerTime
    URI PokerTime
    VERSION 1.0
    QML_FILES Main.qml
    SOURCES
    card.h
    cards.h
    deck.h
    deck.cpp
    community_cards.h
    community_cards.cpp
    player_hand.h
    player_hand.cpp
    hands.h
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appPokerTime PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPokerTime
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPokerTime
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appPokerTime
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
