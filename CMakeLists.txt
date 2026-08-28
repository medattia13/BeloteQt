cmake_minimum_required(VERSION 3.16)

project(Belote
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# ============================================================
# Qt
# ============================================================

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Widgets
    Test
)

# ============================================================
# Model library
# ============================================================

add_library(BeloteModel STATIC
    src/model/Card.cpp
    src/model/Deck.cpp
    src/model/Player.cpp
    src/model/Team.cpp
    src/model/Trick.cpp
    src/model/BeloteRules.cpp
    src/model/Game.cpp
)

target_include_directories(BeloteModel PUBLIC
    src
    src/model
)

target_link_libraries(BeloteModel PUBLIC
    Qt6::Core
)

# ============================================================
# Game application
# ============================================================

add_executable(Belote
    src/main.cpp
    ressources/ressources.qrc
)

target_link_libraries(Belote PRIVATE
    BeloteModel
    Qt6::Widgets
)

# ============================================================
# Tests
# ============================================================

enable_testing()

# ------------------------------------------------------------
# Card tests
# ------------------------------------------------------------

add_executable(tst_card
    tests/tst_card.cpp
)

target_link_libraries(tst_card PRIVATE
    BeloteModel
    Qt6::Test
)

add_test(
    NAME tst_card
    COMMAND tst_card
)

# ------------------------------------------------------------
# Deck tests
# ------------------------------------------------------------

add_executable(tst_deck
    tests/tst_deck.cpp
)

target_link_libraries(tst_deck PRIVATE
    BeloteModel
    Qt6::Test
)

add_test(
    NAME tst_deck
    COMMAND tst_deck
)

# ------------------------------------------------------------
# Player tests
# ------------------------------------------------------------

add_executable(tst_player
    tests/tst_player.cpp
)

target_link_libraries(tst_player PRIVATE
    BeloteModel
    Qt6::Test
)

add_test(
    NAME tst_player
    COMMAND tst_player
)

# ------------------------------------------------------------
# Trick tests
# ------------------------------------------------------------

add_executable(tst_trick
    tests/tst_trick.cpp
)

target_link_libraries(tst_trick PRIVATE
    BeloteModel
    Qt6::Test
)

add_test(
    NAME tst_trick
    COMMAND tst_trick
)

# ------------------------------------------------------------
# Team tests
# ------------------------------------------------------------

add_executable(tst_team
    tests/tst_team.cpp
)

target_link_libraries(tst_team PRIVATE
    BeloteModel
    Qt6::Test
)

add_test(
    NAME tst_team
    COMMAND tst_team
)

# ------------------------------------------------------------
# BeloteRules tests
# ------------------------------------------------------------

add_executable(tst_beloterules
    tests/tst_beloterules.cpp
)

target_link_libraries(tst_beloterules PRIVATE
    BeloteModel
    Qt6::Test
)

add_test(
    NAME tst_beloterules
    COMMAND tst_beloterules
)

# ------------------------------------------------------------
# Game tests
# ------------------------------------------------------------

add_executable(tst_game
    tests/tst_game.cpp
)

target_link_libraries(tst_game PRIVATE
    BeloteModel
    Qt6::Test
)

add_test(
    NAME tst_game
    COMMAND tst_game
)
