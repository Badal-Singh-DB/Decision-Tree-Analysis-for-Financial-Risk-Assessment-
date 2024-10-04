#pragma once
#include "../tree_diff/node.hpp"
#include <memory>
#include <string>

class TreeVisualizer {
public:
    void visualizeTree(const std::shared_ptr<Node>& root, const std::string& filename);

private:
    void generateDotFile(const std::shared_ptr<Node>& root, const std::string& filename);
    void addNodeToDot(std::ofstream& file, const std::shared_ptr<Node>& node, int& id);
};
