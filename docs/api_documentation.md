# API Documentation

## TreeDiffAlgorithm

### `compareTrees(const std::shared_ptr<Node>& tree1, const std::shared_ptr<Node>& tree2)`

Compares two decision trees and returns a list of changes.

- Parameters:
  - `tree1`: The first tree to compare
  - `tree2`: The second tree to compare
- Returns: A vector of tuples containing the change type and the affected nodes

## DPOptimizer

### `optimizeTreeComparison(const std::shared_ptr<Node>& tree1, const std::shared_ptr<Node>& tree2)`

Optimizes the comparison of two decision trees using dynamic programming.

- Parameters:
  - `tree1`: The first tree to compare
  - `tree2`: The second tree to compare
- Returns: A score representing the optimal comparison cost

## MarketPredictor

### `train(const Eigen::MatrixXd& X, const Eigen::VectorXd& y)`

Trains the market prediction model.

- Parameters:
  - `X`: Input features matrix
  - `y`: Target values vector

### `predict(const Eigen::MatrixXd& X) const`

Makes predictions using the trained model.

- Parameters:
  - `X`: Input features matrix for prediction
- Returns: A vector of predicted values

### `evaluate(const Eigen::MatrixXd& X, const Eigen::VectorXd& y) const`

Evaluates the model's performance.

- Parameters:
  - `X`: Input features matrix
  - `y`: True target values
- Returns: The R-squared score of the model

## DataLoader

### `loadData() const`

Loads data from the specified CSV file.

- Returns: An Eigen::MatrixXd containing the loaded data

### `splitData(const Eigen::MatrixXd& data, int targetColumn, double testSize = 0.2) const`

Splits the data into training and testing sets.

- Parameters:
  - `data`: The input data matrix
  - `targetColumn`: The index of the target column
  - `testSize`: The proportion of data to use for testing (default: 0.2)
- Returns: A tuple containing X_train, X_test, y_train, and y_test

## TreeVisualizer

### `visualizeTree(const std::shared_ptr<Node>& root, const std::string& filename)`

Generates a visualization of the decision tree.

- Parameters:
  - `root`: The root node of the tree to visualize
  - `filename`: The base name for the output files (without extension)

## Logger

### `log(LogLevel level, const std::string& message)`

Logs a message with the specified log level.

- Parameters:
  - `level`: The log level (DEBUG, INFO, WARNING, or ERROR)
  - `message`: The message to log

## ConfigManager

### `loadConfig(const std::string& filename)`

Loads the configuration from the specified file.

- Parameters:
  - `filename`: The path to the configuration file

### `getValue(const std::string& key) const`

Retrieves a configuration value.

- Parameters:
  - `key`: The configuration key
- Returns: The corresponding configuration value
