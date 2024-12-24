cmake_minimum_required(VERSION 3.29)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp
    AbstractFactoryMethod.cpp
    Adapter_pattern.cpp
    chain_of_responsibility.cpp
    Decorator_pattern.cpp
    FactoryMethod_pattern.cpp
    Observer_pattern.cpp
    Singleton_pattern.cpp
    Strategy_pattern.cpp)
