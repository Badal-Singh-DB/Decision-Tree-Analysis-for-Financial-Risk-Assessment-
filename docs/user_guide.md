# User Guide

## Getting Started

1. Install the required dependencies:
   - C++17 compatible compiler
   - CMake (version 3.12 or higher)
   - Eigen3 library
   - Google Test framework

2. Clone the repository and build the project as described in the README.md file.

3. Create a `config.ini` file in the project root directory with the following content:

4. Prepare your S&P 500 dataset (SP500.csv) with the following columns:
- Date
- Open
- High
- Low
- Close
- Volume
- Target (e.g., next day's closing price)

## Running the Application

1. Navigate to the build directory:

4. Prepare your S&P 500 dataset (SP500.csv) with the following columns:
- Date
- Open
- High
- Low
- Close
- Volume
- Target (e.g., next day's closing price)

## Running the Application

1. Navigate to the build directory:

4. Prepare your S&P 500 dataset (SP500.csv) with the following columns:
- Date
- Open
- High
- Low
- Close
- Volume
- Target (e.g., next day's closing price)

## Running the Application

1. Navigate to the build directory:

4. Prepare your S&P 500 dataset (SP500.csv) with the following columns:
- Date
- Open
- High
- Low
- Close
- Volume
- Target (e.g., next day's closing price)

## Running the Application

1. Navigate to the build directory:
2. 
4. Prepare your S&P 500 dataset (SP500.csv) with the following columns:
- Date
- Open
- High
- Low
- Close
- Volume
- Target (e.g., next day's closing price)

## Running the Application

1. Navigate to the build directory:

2. Run the main application:

3. The application will perform the following steps:
- Load and preprocess the S&P 500 data
- Train a market prediction model
- Generate and compare sample decision trees
- Optimize tree comparisons using dynamic programming
- Visualize the decision trees

4. Check the console output and the log file for results and any error messages.

## Interpreting Results

- The Market Predictor R2 Score indicates how well the model fits the data. A score closer to 1.0 indicates better performance.
- The number of changes detected between trees shows how different the generated sample trees are.
- The tree comparison optimization score represents the cost of transforming one tree into another. A lower score indicates more similar trees.

## Customizing the Application

- Modify the `generateSampleTree()` function in `main.cpp` to create more complex decision trees based on your specific financial risk assessment criteria.
- Adjust the machine learning model in `MarketPredictor` class to use more advanced algorithms or incorporate additional features.
- Extend the `DataLoader` class to handle different data formats or preprocess the data according to your needs.

## Troubleshooting

- If you encounter any issues with loading the data, ensure that your CSV file is formatted correctly and the path in `config.ini` is correct.
- For visualization issues, make sure you have Graphviz installed on your system, as it's required to generate the tree images.
- If you experience performance issues with large datasets, consider optimizing the data loading process or using a more efficient machine learning algorithm.

For any additional help or feature requests, please open an issue on the project's GitHub repository.


Now, to run this project in Visual Studio Code:

(i) Install the C/C++ extension for VS Code.
(ii) Install the CMake Tools extension for VS Code.
(iii) Open the project folder in VS Code.
(iV) Create a .vscode folder in the project root if it doesn't exist.
(V) Create a settings.json file in the .vscode folder with the following content:
{
    "cmake.configureOnOpen": true,
    "cmake.buildDirectory": "${workspaceFolder}/build"
}

6. Create a launch.json file in the .vscode folder with the following content:
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/FinancialRiskAssessment",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "build",
            "miDebuggerPath": "/usr/bin/gdb"
        }
    ]
}

7. Create a tasks.json file in the .vscode folder with the following content:

{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "build",
            "command": "cmake",
            "args": [
                "--build",
                "${workspaceFolder}/build",
                "--config",
                "Debug",
                "--target",
                "all"
            ],
            "options": {
                "cwd": "${workspaceFolder}/build"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}

8. Open the Command Palette (Ctrl+Shift+P) and run "CMake: Configure" to configure the project.
9. To build the project, use the Command Palette and run "CMake: Build" or press F7.
10. To run the project, use the Command Palette and run "CMake: Run Without Debugging" or press Ctrl+F5.
11. To debug the project, set breakpoints in your code and press F5 to start debugging.
