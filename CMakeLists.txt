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

add_library(TestTitle SHARED)
target_sources(TestTitle
PRIVATE
    src/TestTitle.cpp
PUBLIC
    FILE_SET headers
    TYPE HEADERS
    BASE_DIRS include
    FILES
        include/TestTitle.h
)
add_library(CommonInterface INTERFACE)
target_link_libraries(CommonInterface INTERFACE TestTitle)

add_library(TypeErasurePattern SHARED)
target_sources(TypeErasurePattern
PRIVATE
    src/TypeErasurePattern.cpp
PUBLIC
    FILE_SET headers
    TYPE HEADERS
    BASE_DIRS include
    FILES
        include/TypeErasurePattern.h
)

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

add_library(AbstractFactoryPattern SHARED)
target_sources(AbstractFactoryPattern
PRIVATE
    src/AbstractFactoryPattern.cpp
PUBLIC
    FILE_SET headers
    TYPE HEADERS
    BASE_DIRS include
    FILES
        include/AbstractFactoryPattern.h
)

add_library(PrototypePattern SHARED)
target_sources(PrototypePattern
PRIVATE
    src/PrototypePattern.cpp
PUBLIC
    FILE_SET headers
    TYPE HEADERS
    BASE_DIRS include
    FILES
        include/PrototypePattern.h
)

add_library(CompositorPattern SHARED)
target_sources(CompositorPattern
PRIVATE
    src/CompositorPattern.cpp
PUBLIC
    FILE_SET headers
    TYPE HEADERS
    BASE_DIRS include
    FILES
        include/CompositorPattern.h
)

add_executable(exec)
target_sources(exec
PRIVATE
    src/main.cpp
)

target_link_libraries(AbstractFactoryPattern PRIVATE TestTitle)
target_link_libraries(FactoryMethodPattern PRIVATE TestTitle)
target_link_libraries(AdaptorPattern PRIVATE TestTitle)
target_link_libraries(CommandPattern PRIVATE TestTitle)
target_link_libraries(StrategyPattern PRIVATE TestTitle)
target_link_libraries(PrototypePattern PRIVATE TestTitle)
target_link_libraries(TypeErasurePattern PRIVATE TestTitle)
target_link_libraries(CompositorPattern PRIVATE TestTitle)

target_link_libraries(exec
PRIVATE
    AbstractFactoryPattern
    FactoryMethodPattern
    AdaptorPattern
    CommandPattern
    StrategyPattern
    PrototypePattern
    TypeErasurePattern
    CompositorPattern
)