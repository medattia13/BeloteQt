cmake_minimum_required(VERSION 3.16)

project(Belote
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(Belote
    src/main.cpp

    # Game
    src/model/Card.cpp
    src/model/Card.h

    src/model/Deck.cpp
    src/model/Deck.h

    src/model/Player.cpp
    src/model/Player.h

    src/model/Team.cpp
    src/model/Team.h

    src/model/Trick.cpp
    src/model/Trick.h

    src/model/Game.cpp
    src/model/Game.h

    src/model/BeloteRules.cpp
    src/model/BeloteRules.h

    src/model/GameState.h

    # Controller
    src/controller/GameController.cpp
    src/controller/GameController.h

    # UI
    src/ui/MainWindow.cpp
    src/ui/MainWindow.h

    src/ui/StartScreen.cpp
    src/ui/StartScreen.h

    src/ui/GameWidget.cpp
    src/ui/GameWidget.h

    src/ui/CardWidget.cpp
    src/ui/CardWidget.h

    src/ui/PlayerHandWidget.cpp
    src/ui/PlayerHandWidget.h

    src/ui/PlayerWidget.cpp
    src/ui/PlayerWidget.h

    src/ui/TrickWidget.cpp
    src/ui/TrickWidget.h

    src/ui/ScoreWidget.cpp
    src/ui/ScoreWidget.h

    src/ui/TrumpSelectionWidget.cpp
    src/ui/TrumpSelectionWidget.h

    src/ui/ResultsWidget.cpp
    src/ui/ResultsWidget.h
    src/ui/SettingsWidget.h src/ui/SettingsWidget.cpp
)

target_include_directories(Belote PRIVATE
    src
    src/game
    src/controller
    src/ui
)

target_link_libraries(Belote PRIVATE
    Qt6::Widgets
)
