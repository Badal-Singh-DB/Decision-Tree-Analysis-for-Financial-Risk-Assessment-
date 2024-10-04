#include "data_loader.hpp"
#include <fstream>
#include <sstream>
#include <random>
#include <algorithm>

DataLoader::DataLoader(const std::string& dataPath) : dataPath(dataPath) {}

Eigen::MatrixXd DataLoader::loadData() const {
    std::ifstream file(dataPath);
    std::vector<std::vector<double>> data;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<double> row;
        std::string value;

        while (std::getline(iss, value, ',')) {
            row.push_back(std::stod(value));
        }

        data.push_back(row);
    }

    Eigen::MatrixXd result(data.size(), data[0].size());
    for (size_t i = 0; i < data.size(); ++i) {
        result.row(i) = Eigen::VectorXd::Map(&data[i][0], data[i].size());
    }

    return result;
}

std::tuple<Eigen::MatrixXd, Eigen::MatrixXd, Eigen::VectorXd, Eigen::VectorXd> DataLoader::splitData(const Eigen::MatrixXd& data, int targetColumn, double testSize) const {
    int numSamples = data.rows();
    int numFeatures = data.cols() - 1;

    std::vector<int> indices(numSamples);
    std::iota(indices.begin(), indices.end(), 0);
    std::shuffle(indices.begin(), indices.end(), std::mt19937{std::random_device{}()});

    int testSamples = static_cast<int>(numSamples * testSize);
    int trainSamples = numSamples - testSamples;

    Eigen::MatrixXd X_train(trainSamples, numFeatures);
    Eigen::VectorXd y_train(trainSamples);
    Eigen::MatrixXd X_test(testSamples, numFeatures);
    Eigen::VectorXd y_test(testSamples);

    for (int i = 0; i < trainSamples; ++i) {
        X_train.row(i) = data.row(indices[i]).leftCols(numFeatures);
        y_train(i) = data(indices[i], targetColumn);
    }

    for (int i = 0; i < testSamples; ++i) {
        X_test.row(i) = data.row(indices[trainSamples + i]).leftCols(numFeatures);
        y_test(i) = data(indices[trainSamples + i], targetColumn);
    }

    return std::make_tuple(X_train, X_test, y_train, y_test);
}
