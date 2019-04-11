cmake_minimum_required(VERSION 2.6)
project(polygonial)

add_executable(polygonial
        main.cpp
        src/FactsEngine.h src/FactsEngine.cpp
        src/InferenceEngine.h src/InferenceEngine.cpp
        src/Record.h
        src/RulesEngine.h src/RulesEngine.cpp
        src/Node.h src/Node.cpp
        src/UnfilledRecordException.hpp)

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
