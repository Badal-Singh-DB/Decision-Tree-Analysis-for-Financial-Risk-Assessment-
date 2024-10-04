#include "tree_visualizer.hpp"
#include <fstream>
#include <sstream>

void TreeVisualizer::visualizeTree(const std::shared_ptr<Node>& root, const std::string& filename) {
    generateDotFile(root, filename);
    std::string command = "dot -Tpng " + filename + ".dot -o " + filename + ".png";
    system(command.c_str());
}

void TreeVisualizer::generateDotFile(const std::shared_ptr<Node>& root, const std::string& filename) {
    std::ofstream file(filename + ".dot");
    file << "digraph Tree {" << std::endl;
    file << "    node [shape=circle];" << std::endl;

    int id = 0;
    addNodeToDot(file, root, id);

    file << "}" << std::endl;
    file.close();
}

void TreeVisualizer::addNodeToDot(std::ofstream& file, const std::shared_ptr<Node>& node, int& id) {
    int currentId = id++;
    file << "    " << currentId << " [label=\"" << node->getValue() << "\"];" << std::endl;

  for (const auto& child : node->getChildren()) {
        int childId = id;
        addNodeToDot(file, child, id);
        file << "    " << currentId << " -> " << childId << ";" << std::endl;
    }
}
