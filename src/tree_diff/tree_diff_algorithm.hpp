#pragma once
#include "node.hpp"
#include <vector>
#include <tuple>
#include <string>

class TreeDiffAlgorithm {
public:
    std::vector<std::tuple<std::string, std::shared_ptr<Node>, std::shared_ptr<Node>>> compareTrees(const std::shared_ptr<Node>& tree1, const std::shared_ptr<Node>& tree2);

private:
    void compareNodes(const std::shared_ptr<Node>& node1, const std::shared_ptr<Node>& node2);
    std::vector<std::tuple<std::string, std::shared_ptr<Node>, std::shared_ptr<Node>>> changes;
};
