# Minimalna wersja CMake
cmake_minimum_required(VERSION 3.28)

# Nazwa projektu
project(Ufo_pierwsza_wersja LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Ustawienie katalogu dla plików wykonywalnych
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#ustawienie katalogu ze źródłami

# Wymuszenie architektury 32-bitowej
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "Building for 32-bit is required, but a 64-bit generator is being used. Please specify a 32-bit generator (e.g., -A Win32).")
endif()

# Dodanie ścieżki do nagłówków SFML
include_directories("External/SFML/include")

# Dodanie ścieżki do bibliotek SFML
link_directories("External/SFML/lib")

# Pliki źródłowe projektu
set(SOURCES
    Ufo_pierwsza_wersja/main.cpp
    Ufo_pierwsza_wersja/Game.cpp
    Ufo_pierwsza_wersja/Background.cpp
    Ufo_pierwsza_wersja/FriendlyMissile.cpp
    Ufo_pierwsza_wersja/GameElement.cpp
    Ufo_pierwsza_wersja/Missile.cpp
    Ufo_pierwsza_wersja/Pointer.cpp
    Ufo_pierwsza_wersja/Ship.cpp
    Ufo_pierwsza_wersja/StaticBackground.cpp
    Ufo_pierwsza_wersja/AbstractMissile.cpp
)

# Tworzenie pliku wykonywalnego
add_executable(Ufo_pierwsza_wersja ${SOURCES})

# Set up libraries for different build types
set(DEBUG_LIBS
    "sfml-graphics-d.lib"
    "sfml-window-d.lib"
    "sfml-audio-d.lib"
    "sfml-network-d.lib"
    "sfml-system-d.lib"
)
set(RELEASE_LIBS
    "sfml-graphics.lib"
    "sfml-window.lib"
    "sfml-audio.lib"
    "sfml-network.lib"
    "sfml-system.lib"
)

# Use generator expressions to link the appropriate libraries based on the build type
target_link_libraries(Ufo_pierwsza_wersja
  PRIVATE
    $<IF:$<CONFIG:Debug>,${DEBUG_LIBS},${RELEASE_LIBS}>
)

# Dodanie tekstur do katalogu budowy

file(COPY "Textures" DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Ufo_pierwsza_wersja/sfml-audio-2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Ufo_pierwsza_wersja/sfml-audio-d-2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Ufo_pierwsza_wersja/sfml-graphics-2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Ufo_pierwsza_wersja/sfml-graphics-d-2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Ufo_pierwsza_wersja/sfml-network-2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Ufo_pierwsza_wersja/sfml-network-d-2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Ufo_pierwsza_wersja/sfml-system-2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Ufo_pierwsza_wersja/sfml-system-d-2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Ufo_pierwsza_wersja/sfml-window-2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Ufo_pierwsza_wersja/sfml-window-d-2.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${CMAKE_BUILD_TYPE}/)
