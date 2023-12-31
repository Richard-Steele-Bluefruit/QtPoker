cmake_minimum_required(VERSION 3.5)

project(PokerTimeTests LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
    test_player_hand.h
    test_player_hand.cpp
    test_deck.h
    test_deck.cpp
    ../player_hand.h
    ../player_hand.cpp
    ../card.h
    ../cards.h
    ../deck.h
    ../deck.cpp
    ../community_cards.h
    ../community_cards.cpp
    ../hands.h
)

add_executable(PokerTimeTests
    main.cpp
    ${SOURCE_FILES}
    ${TEST_FILES}
)

add_test(NAME PokerTimeTests COMMAND PokerTimeTests)

target_link_libraries(PokerTimeTests PRIVATE Qt${QT_VERSION_MAJOR}::Test)


