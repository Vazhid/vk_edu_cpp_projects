#include <gtest/gtest.h>
#include "filtering.hpp"

TEST(CosSimilarityCalculatorTest, EmptyVectors) {
    std::vector<double> first {};
    std::vector<double> second {};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = 1;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};

TEST(CosSimilarityCalculatorTest, EqualVectors) {
    std::vector<double> first {1, 2, 3, 4, 5};
    std::vector<double> second {1, 2, 3, 4, 5};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = 1.0;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};

TEST(CosSimilarityCalculatorTest, VeryCloseVectors) {
    std::vector<double> first {1, 2, 2, 4, 5};
    std::vector<double> second {1, 2, 3, 4, 7};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = 0.99;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};

TEST(CosSimilarityCalculatorTest, CloseVectors) {
    std::vector<double> first {1, 2, 2, 4, 5};
    std::vector<double> second {-3, 0, 4, 7, 9};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = 0.88;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};

TEST(CosSimilarityCalculatorTest, OppositeVectors) {
    std::vector<double> first {1, 2, 3, 4, 5};
    std::vector<double> second {-1, -2, -3, -4, -5};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = -1;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};

TEST(CosSimilarityCalculatorTest, SomeVectors1) {
    std::vector<double> first {1,-1, 3, 3};
    std::vector<double> second {0, 1, 2, 0};
    CosSimilarityCalculator calculator(first, second);
    calculator.calculate();
    double expect_similarity = 0.5;
    EXPECT_EQ(calculator.get_similarity(), expect_similarity);
};