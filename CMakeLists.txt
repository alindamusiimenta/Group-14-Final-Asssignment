cmake_minimum_required(VERSION 3.16)
project(lasso_regression VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(lasso_regression src/lasso_regression.cpp)
target_include_directories(lasso_regression PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_options(lasso_regression PRIVATE -Wall -Wextra -Wpedantic)

add_executable(lasso_example examples/basic_example.cpp)
target_link_libraries(lasso_example PRIVATE lasso_regression)

add_executable(lasso_tests tests/test_lasso.cpp)
target_link_libraries(lasso_tests PRIVATE lasso_regression)
enable_testing()
add_test(NAME lasso_tests COMMAND lasso_tests)
