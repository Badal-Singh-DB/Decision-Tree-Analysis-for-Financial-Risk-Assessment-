#pragma once
#include "../tree_diff/node.hpp"
#include <unordered_map>
#include <memory>

class DPOptimizer {
public:
    double optimizeTreeComparison(const std::shared_ptr<Node>& tree1, const std::shared_ptr<Node>& tree2);

private:
    double recursiveCompare(const std::shared_ptr<Node>& node1, const std::shared_ptr<Node>& node2);
    std::vector<std::vector<int>> generatePermutations(int n, int m);
    std::unordered_map<std::string, double> memo;
};
