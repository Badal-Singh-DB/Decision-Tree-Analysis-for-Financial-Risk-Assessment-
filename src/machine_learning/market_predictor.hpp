#pragma once
#include <vector>
#include <string>
#include <Eigen/Dense>

class MarketPredictor {
public:
    void train(const Eigen::MatrixXd& X, const Eigen::VectorXd& y);
    Eigen::VectorXd predict(const Eigen::MatrixXd& X) const;
    double evaluate(const Eigen::MatrixXd& X, const Eigen::VectorXd& y) const;
    std::vector<std::pair<std::string, double>> featureImportance() const;
    void setFeatureNames(const std::vector<std::string>& featureNames);

private:
    Eigen::VectorXd weights;
    std::vector<std::string> featureNames;
};
