#include <gtest/gtest.h>
#include "../src/dynamic_programming/dp_optimizer.hpp"

TEST(DPOptimizerTest, OptimizeSameTrees) {
    auto tree1 = std::make_shared<Node>(1.0);
    auto tree2 = std::make_shared<Node>(1.0);

    DPOptimizer optimizer;
    double score = optimizer.optimizeTreeComparison(tree1, tree2);

    EXPECT_DOUBLE_EQ(score, 0.0);
}

TEST(DPOptimizerTest, OptimizeDifferentTrees) {
    auto tree1 = std::make_shared<Node>(1.0);
    tree1->addChild(std::make_shared<Node>(2.0));

    auto tree2 = std::make_shared<Node>(1.0);
    tree2->addChild(std::make_shared<Node>(3.0));

    DPOptimizer optimizer;
    double score = optimizer.optimizeTreeComparison(tree1, tree2);

    EXPECT_GT(score, 0.0);
}
