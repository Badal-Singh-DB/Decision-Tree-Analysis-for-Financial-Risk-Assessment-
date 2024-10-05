#include <gtest/gtest.h>
#include "../src/machine_learning/market_predictor.hpp"

TEST(MarketPredictorTest, TrainAndPredict) {
    Eigen::MatrixXd X_train(3, 2);
    X_train << 1, 2,
               3, 4,
               5, 6;
    Eigen::VectorXd y_train(3);
    y_train << 3, 7, 11;

    MarketPredictor predictor;
    predictor.train(X_train, y_train);

    Eigen::MatrixXd X_test(1, 2);
    X_test << 7, 8;

    Eigen::VectorXd prediction = predictor.predict(X_test);
    EXPECT_NEAR(prediction(0), 15, 1e-6);
}

TEST(MarketPredictorTest, Evaluate) {
    Eigen::MatrixXd X(4, 2);
    X << 1, 2,
         3, 4,
         5, 6,
         7, 8;
    Eigen::VectorXd y(4);
    y << 3, 7, 11, 15;

    MarketPredictor predictor;
    predictor.train(X, y);

    double score = predictor.evaluate(X, y);
    EXPECT_GT(score, 0.9);
}
