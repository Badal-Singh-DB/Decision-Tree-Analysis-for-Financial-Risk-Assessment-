#include <gtest/gtest.h>
#include "../src/tree_diff/tree_diff_algorithm.hpp"

TEST(TreeDiffTest, CompareSameTrees) {
    auto tree1 = std::make_shared<Node>(1.0);
    auto tree2 = std::make_shared<Node>(1.0);

    TreeDiffAlgorithm treeDiff;
    auto changes = treeDiff.compareTrees(tree1, tree2);

    EXPECT_EQ(changes.size(), 0);
}

TEST(TreeDiffTest, CompareDifferentTrees) {
    auto tree1 = std::make_shared<Node>(1.0);
    tree1->addChild(std::make_shared<Node>(2.0));

    auto tree2 = std::make_shared<Node>(1.0);
    tree2->addChild(std::make_shared<Node>(3.0));

    TreeDiffAlgorithm treeDiff;
    auto changes = treeDiff.compareTrees(tree1, tree2);

    EXPECT_EQ(changes.size(), 1);
    EXPECT_EQ(std::get<0>(changes[0]), "MODIFY");
}
