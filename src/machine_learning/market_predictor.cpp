#include "market_predictor.hpp"
#include <algorithm>
#include <numeric>

void MarketPredictor::train(const Eigen::MatrixXd& X, const Eigen::VectorXd& y) {
    weights = (X.transpose() * X).ldlt().solve(X.transpose() * y);
}

Eigen::VectorXd MarketPredictor::predict(const Eigen::MatrixXd& X) const {
    return X * weights;
}

double MarketPredictor::evaluate(const Eigen::MatrixXd& X, const Eigen::VectorXd& y) const {
    Eigen::VectorXd predictions = predict(X);
    double sse = (y - predictions).array().square().sum();
    double sst = (y.array() - y.mean()).square().sum();
    return 1 - sse / sst;
}

std::vector<std::pair<std::string, double>> MarketPredictor::featureImportance() const {
    std::vector<std::pair<std::string, double>> importance;
    for (int i = 0; i < weights.size(); ++i) {
        importance.emplace_back(featureNames[i], std::abs(weights(i)));
    }
    std::sort(importance.begin(), importance.end(),
              [](const auto& a, const auto& b) { return a.second > b.second; });
    return importance;
}

void MarketPredictor::setFeatureNames(const std::vector<std::string>& names) {
    featureNames = names;
}
