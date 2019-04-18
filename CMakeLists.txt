cmake_minimum_required(VERSION 3.1.0)
project(polygonial)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets CONFIG REQUIRED)
add_executable(polygonial
        main.cpp
        src/cli/cli.cpp
        src/gui/mainwindow.h src/gui/mainwindow.cpp
        src/gui/mainwindow.ui
        src/core/FactsEngine.h src/core/FactsEngine.cpp
        src/core/InferenceEngine.h src/core/InferenceEngine.cpp
        src/core/Record.h
        src/core/RulesEngine.h src/core/RulesEngine.cpp
        src/core/Node.h src/core/Node.cpp
        src/core/UnfilledRecordException.hpp)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE tests/catch.hpp)

add_executable(tests
        tests/cli/test-cli.cpp
        tests/core/test-main.cpp
        tests/core/test-record.cpp
        tests/core/test-node.cpp
        tests/core/test-factsengine.cpp
        tests/core/test-rulesengine.cpp
        tests/core/test-inferenceengine.cpp)

target_link_libraries(tests Catch)
target_link_libraries(polygonial Qt5::Widgets)
enable_testing()
add_test(NAME PolygonialTest COMMAND tests)
