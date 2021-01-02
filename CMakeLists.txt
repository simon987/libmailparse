cmake_minimum_required(VERSION 3.17)
project(mailparse)

set(CMAKE_C_STANDARD 11)

set(BUILD_TESTS on)

add_library(mailparse src/library.c src/library.h)
set_target_properties(mailparse PROPERTIES LINKER_LANGUAGE C)

if (BUILD_TESTS)
    find_package(GTest CONFIG REQUIRED)

    add_executable(mailparse_test test/main.cpp)
    target_compile_options(mailparse_test
            PRIVATE
            -g
            -fsanitize=address
            -fno-omit-frame-pointer)
    target_link_libraries(mailparse_test
            PRIVATE
            GTest::gtest
            GTest::gtest_main
            -fsanitize=address
            stdc++
            mailparse)
endif ()
