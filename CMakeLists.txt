# Minimalna wersja CMake
cmake_minimum_required(VERSION 3.28)

project(Ufo_pierwsza_wersja LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#ustawienie katalogu ze źródłami

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    message(FATAL_ERROR "Building for 32-bit is required, but a 64-bit generator is being used. Please specify a 32-bit generator (e.g., -A Win32).")
endif()

include_directories("External/SFML/include")

add_subdirectory(tests)

link_directories("External/SFML/lib")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# target_include_directories(Ufo_pierwsza_wersja PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/Background.cpp
    src/FriendlyMissile.cpp
    src/GameElement.cpp
    src/Missile.cpp
    src/Pointer.cpp
    src/Ship.cpp
    src/StaticBackground.cpp
    src/AbstractMissile.cpp
)

add_executable(Ufo_pierwsza_wersja ${SOURCES})
#add_library(Ufo_pierwsza_wersja ${SOURCES})

set(DEBUG_LIBS
    "sfml-graphics-d.lib"
    "sfml-window-d.lib"
    "sfml-audio-d.lib"
    "sfml-network-d.lib"
    "sfml-system-d.lib"
    GTest::gtest_main
)
set(RELEASE_LIBS
    "sfml-graphics.lib"
    "sfml-window.lib"
    "sfml-audio.lib"
    "sfml-network.lib"
    "sfml-system.lib"
)


target_link_libraries(Ufo_pierwsza_wersja
  PRIVATE
    $<IF:$<CONFIG:Debug>,${DEBUG_LIBS},${RELEASE_LIBS}>
)

if(WIN32)
    set(THREADS_PREFER_PTHREAD_FLAG OFF)
endif()

find_package(Threads REQUIRED)


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
