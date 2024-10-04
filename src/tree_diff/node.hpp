#pragma once
#include <vector>
#include <memory>

class Node {
public:
    Node(double value);
    void addChild(std::shared_ptr<Node> child);
    double getValue() const;
    const std::vector<std::shared_ptr<Node>>& getChildren() const;

private:
    double value;
    std::vector<std::shared_ptr<Node>> children;
};
