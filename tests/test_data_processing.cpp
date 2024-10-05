#include <gtest/gtest.h>
#include "../src/data_processing/data_loader.hpp"
#include <fstream>

class DataLoaderTest : public ::testing::Test {
protected:
    void SetUp() override {
        std::ofstream testFile("test_data.csv");
        testFile << "1,2,3\n4,5,6\n7,8,9\n";
        testFile.close();
    }

    void TearDown() override {
        std::remove("test_data.csv");
    }
};

TEST_F(DataLoaderTest, LoadData) {
    DataLoader loader("test_data.csv");
    Eigen::MatrixXd data = loader.loadData();

    EXPECT_EQ(data.rows(), 3);
    EXPECT_EQ(data.cols(), 3);
    EXPECT_DOUBLE_EQ(data(0, 0), 1);
    EXPECT_DOUBLE_EQ(data(1, 1), 5);
    EXPECT_DOUBLE_EQ(data(2, 2), 9);
}

TEST_F(DataLoaderTest, SplitData) {
    DataLoader loader("test_data.csv");
    Eigen::MatrixXd data = loader.loadData();

    auto [X_train, X_test, y_train, y_test] = loader.splitData(data, 2, 0.33);

    EXPECT_EQ(X_train.rows(), 2);
    EXPECT_EQ(X_train.cols(), 2);
    EXPECT_EQ(X_test.rows(), 1);
    EXPECT_EQ(X_test.cols(), 2);
    EXPECT_EQ(y_train.size(), 2);
    EXPECT_EQ(y_test.size(), 1);
}
