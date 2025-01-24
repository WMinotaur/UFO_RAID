
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

link_directories("../External/SFML/lib")
link_directories("../")

set(TEST_SOURCES
    ShipTests.cpp
    GameElementTests.cpp
    MissileTest.cpp
#    ../src/main.cpp
    ../src/Game.cpp
    ../src/Background.cpp
    ../src/FriendlyMissile.cpp
    ../src/GameElement.cpp
    ../src/Missile.cpp
    ../src/Pointer.cpp
    ../src/Ship.cpp
    ../src/StaticBackground.cpp
    ../src/AbstractMissile.cpp
)

add_executable(RunTests ${TEST_SOURCES})


add_test(NAME RunTests COMMAND RunTests)

set(DEBUG_LIBS
    "sfml-graphics-d.lib"
    "sfml-window-d.lib"
    "sfml-audio-d.lib"
    "sfml-network-d.lib"
    "sfml-system-d.lib"
    "gtest"
    "gtest_main"
)
set(RELEASE_LIBS
    "sfml-graphics.lib"
    "sfml-window.lib"
    "sfml-audio.lib"
    "sfml-network.lib"
    "sfml-system.lib"
     "gtest"
    "gtest_main"
)

target_link_libraries(RunTests
  PRIVATE
    $<IF:$<CONFIG:Debug>,${DEBUG_LIBS},${RELEASE_LIBS}>
)

