cmake_minimum_required(VERSION 2.6)
project(polygonial)

add_executable(polygonial
        main.cpp
        src/cli/cli.cpp
        src/core/FactsEngine.h src/core/FactsEngine.cpp
        src/core/InferenceEngine.h src/core/InferenceEngine.cpp
        src/core/Record.h
        src/core/RulesEngine.h src/core/RulesEngine.cpp
        src/core/Node.h src/core/Node.cpp
        src/core/UnfilledRecordException.hpp)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE tests/catch.hpp)

add_executable(tests
        tests/test-main.cpp
        tests/test-record.cpp
        tests/test-node.cpp
        tests/test-factsengine.cpp
        tests/test-rulesengine.cpp
        tests/test-inferenceengine.cpp)

target_link_libraries(tests Catch)
enable_testing()
add_test(NAME PolygonialTest COMMAND tests)
