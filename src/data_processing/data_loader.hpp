#pragma once
#include <string>
#include <Eigen/Dense>
#include <tuple>

class DataLoader {
public:
    DataLoader(const std::string& dataPath);
    Eigen::MatrixXd loadData() const;
    std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd> splitData(const Eigen::MatrixXd& data, int targetColumn, double testSize = 0.2) const;

private:
    std::string dataPath;
};
