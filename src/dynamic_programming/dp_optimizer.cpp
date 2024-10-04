#include "dp_optimizer.hpp"
#include <algorithm>
#include <cmath>

double DPOptimizer::optimizeTreeComparison(const std::shared_ptr<Node>& tree1, const std::shared_ptr<Node>& tree2) {
    memo.clear();
    return recursiveCompare(tree1, tree2);
}

double DPOptimizer::recursiveCompare(const std::shared_ptr<Node>& node1, const std::shared_ptr<Node>& node2) {
    if (!node1 && !node2) return 0;
    if (!node1 || !node2) return std::numeric_limits<double>::infinity();

    std::string key = std::to_string(reinterpret_cast<uintptr_t>(node1.get())) + "," + std::to_string(reinterpret_cast<uintptr_t>(node2.get()));
    if (memo.find(key) != memo.end()) return memo[key];

    double cost = std::abs(node1->getValue() - node2->getValue());

    const auto& children1 = node1->getChildren();
    const auto& children2 = node2->getChildren();

    if (children1.empty() && children2.empty()) {
        memo[key] = cost;
        return cost;
    }

    double minCost = std::numeric_limits<double>::infinity();
    for (const auto& perm : generatePermutations(children1.size(), children2.size())) {
        double permCost = cost;
        for (size_t i = 0; i < perm.size(); ++i) {
            if (perm[i] != -1) {
                permCost += recursiveCompare(children1[i], children2[perm[i]]);
            } else {
                permCost += recursiveCompare(children1[i], nullptr);
            }
        }
        minCost = std::min(minCost, permCost);
    }

    memo[key] = minCost;
    return minCost;
}

std::vector<std::vector<int>> DPOptimizer::generatePermutations(int n, int m) {
    std::vector<std::vector<int>> perms;
    std::vector<int> perm(n, -1);
    std::vector<bool> used(m, false);

    std::function<void(int)> backtrack = [&](int idx) {
        if (idx == n) {
            perms.push_back(perm);
            return;
        }
        for (int i = 0; i < m; ++i) {
            if (!used[i]) {
                used[i] = true;
                perm[idx] = i;
                backtrack(idx + 1);
                used[i] = false;
                perm[idx] = -1;
            }
        }
        backtrack(idx + 1);
    };

    backtrack(0);
    return perms;
}
