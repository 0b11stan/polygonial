cmake_minimum_required(VERSION 2.6)
project(polygonial)
add_executable(polygonial
        src/main.cpp
        src/FactsEngine.h src/FactsEngine.cpp
        src/InferenceEngine.h src/InferenceEngine.cpp
        src/Record.h src/Record.cpp
        src/RulesEngine.h src/RulesEngine.cpp)
