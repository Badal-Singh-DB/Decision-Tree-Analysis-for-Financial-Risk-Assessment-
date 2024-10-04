#include "tree_diff_algorithm.hpp"

std::vector<std::tuple<std::string, std::shared_ptr<Node>, std::shared_ptr<Node>>> TreeDiffAlgorithm::compareTrees(const std::shared_ptr<Node>& tree1, const std::shared_ptr<Node>& tree2) {
    changes.clear();
    compareNodes(tree1, tree2);
    return changes;
}

void TreeDiffAlgorithm::compareNodes(const std::shared_ptr<Node>& node1, const std::shared_ptr<Node>& node2) {
    if (!node1 && !node2) return;
    if (!node1) {
        changes.emplace_back("ADD", nullptr, node2);
        return;
    }
    if (!node2) {
        changes.emplace_back("DELETE", node1, nullptr);
        return;
    }
    if (node1->getValue() != node2->getValue()) {
        changes.emplace_back("MODIFY", node1, node2);
    }

    const auto& children1 = node1->getChildren();
    const auto& children2 = node2->getChildren();

    size_t i = 0, j = 0;
    while (i < children1.size() && j < children2.size()) {
        compareNodes(children1[i], children2[j]);
        ++i;
        ++j;
    }

    while (i < children1.size()) {
        changes.emplace_back("DELETE", children1[i], nullptr);
        ++i;
    }

    while (j < children2.size()) {
        changes.emplace_back("ADD", nullptr, children2[j]);
        ++j;
    }
}
