cmake_minimum_required(VERSION 3.16)
project(Sentiment_Analyzer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sentiment_Analyzer
        src/main.cpp
        src/Sentiment_Analyzer.cpp
        src/DSString.cpp
        src/Tweet.cpp

        src/test/catch.hpp
        src/test/testDSString.cpp
)