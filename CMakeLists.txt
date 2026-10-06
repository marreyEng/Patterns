cmake_minimum_required(VERSION 4.2)

project(Patterns)

set(CMAKE_CXX_SCAN_FOR_MODULES OFF)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(PROJECT_IS_TOP_LEVEL)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink 
        "${CMAKE_BINARY_DIR}/compile_commands.json" 
        "${CMAKE_SOURCE_DIR}/compile_commands.json"
    )
endif()

add_library(CommandPattern SHARED)
target_sources(CommandPattern
PRIVATE
    src/CommandPattern.cpp
PUBLIC
    FILE_SET headers
    TYPE HEADERS
    BASE_DIRS include
    FILES
        include/CommandPattern.h
)

add_library(StrategyPattern SHARED)
target_sources(StrategyPattern
PRIVATE
    src/StrategyPattern.cpp
PUBLIC
    FILE_SET headers
    TYPE HEADERS
    BASE_DIRS include
    FILES
        include/StrategyPattern.h
)


add_library(AdaptorPattern SHARED)
target_sources(AdaptorPattern
PRIVATE
    src/AdaptorPattern.cpp
PUBLIC
    FILE_SET headers
    TYPE HEADERS
    BASE_DIRS include
    FILES
        include/AdaptorPattern.h
)

add_library(FactoryMethodPattern SHARED)
target_sources(FactoryMethodPattern
PRIVATE
    src/FactoryMethodPattern.cpp
PUBLIC
    FILE_SET headers
    TYPE HEADERS
    BASE_DIRS include
    FILES
        include/FactoryMethodPattern.h
)

add_executable(exec)
target_sources(exec
PRIVATE
    src/main.cpp
)
target_link_libraries(exec
PRIVATE
    FactoryMethodPattern
    AdaptorPattern
    CommandPattern
    StrategyPattern
)