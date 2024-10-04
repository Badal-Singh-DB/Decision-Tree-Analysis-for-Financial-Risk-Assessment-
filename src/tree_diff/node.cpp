#include "node.hpp"

Node::Node(double value) : value(value) {}

void Node::addChild(std::shared_ptr<Node> child) {
    children.push_back(child);
}

double Node::getValue() const {
    return value;
}

const std::vector<std::shared_ptr<Node>>& Node::getChildren() const {
    return children;
}
