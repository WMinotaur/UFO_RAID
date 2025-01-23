# Dodanie katalogu z nagłówkami
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Pliki testowe
set(TEST_SOURCES
    ShipTests.cpp
    GameElementTests.cpp
    MissileTest.cpp
)

# Tworzenie pliku wykonywalnego dla testów
add_executable(RunTests ${TEST_SOURCES})

# Linkowanie z biblioteką Google Test i kodem projektu
target_link_libraries(RunTests gtest gtest_main Ufo_pierwsza_wersja)

# Dodanie testów do CTest
add_test(NAME RunTests COMMAND RunTests)