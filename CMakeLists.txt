cmake_minimum_required(VERSION 3.12)
project(FinancialRiskAssessment)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

include_directories(src)

add_executable(FinancialRiskAssessment
    src/main.cpp
    src/tree_diff/node.cpp
    src/tree_diff/tree_diff_algorithm.cpp
    src/dynamic_programming/dp_optimizer.cpp
    src/machine_learning/market_predictor.cpp
    src/data_processing/data_loader.cpp
    src/visualization/tree_visualizer.cpp
    src/utils/logger.cpp
    src/utils/config_manager.cpp
)

target_link_libraries(FinancialRiskAssessment Eigen3::Eigen)

# Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(RunTests
    tests/test_tree_diff.cpp
    tests/test_dp_optimizer.cpp
    tests/test_market_predictor.cpp
    tests/test_data_processing.cpp
    src/tree_diff/node.cpp
    src/tree_diff/tree_diff_algorithm.cpp
    src/dynamic_programming/dp_optimizer.cpp
    src/machine_learning/market_predictor.cpp
    src/data_processing/data_loader.cpp
)
target_link_libraries(RunTests ${GTEST_LIBRARIES} pthread Eigen3::Eigen)

add_test(NAME UnitTests COMMAND RunTests)
