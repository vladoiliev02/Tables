cmake_minimum_required(VERSION 3.19)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        Cell
        Cell/Tests
        Table
        Expression
        Expression/Tests
        Commands
        StringNumber
        StringNumber/Tests
        Table_File
        "C:/Users/User/Desktop/Uni/Year 1/OOP/Git")

set(Table
        Cell/Cell.cpp
        Table/Table.cpp
        Expression/Expression.cpp
        Commands/Commands.cpp
        StringNumber/StringNumber.cpp
        Table_File/Table_File.cpp)

add_executable(CSV
        main.cpp
        ${Table})
set_target_properties(
        CSV
        PROPERTIES
        OUTPUT_NAME "CSV Table Editor"
        SUFFIX ".exe")


add_executable(Table_Tests
        Table/Tests/Table_Tests.cpp
        ${Table})

add_executable(Expression_Tests
        Expression/Tests/Expression_Tests.cpp
        ${Table})

add_executable(StringNumber_Tests
        StringNumber/Tests/StringNumber_Tests.cpp
        StringNumber/StringNumber.cpp)

add_executable(Cell_Tests
        Cell/Tests/Cell_Tests.cpp
        ${Table})