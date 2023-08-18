#include <gtest/gtest.h>
#include "example.hpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(TriangleTypeTest, EquilateralTriangle)
{
    EXPECT_EQ(determineTriangleType(0, 0, 1, 0, 0.5, sqrt(3)), "TG deu");
}

TEST(TriangleTypeTest, IsoscelesTriangle)
{
    EXPECT_EQ(determineTriangleType(0, 0, 1, 0, 0.5, 1), "TG can");
    EXPECT_EQ(determineTriangleType(0, 0, 2, 0, 1, 2), "TG can");
}

TEST(TriangleTypeTest, RightTriangle)
{
    EXPECT_EQ(determineTriangleType(0, 0, 3, 0, 0, 4), "TG vuong");
}

TEST(TriangleTypeTest, ScaleneTriangle)
{
    EXPECT_EQ(determineTriangleType(0, 0, 3, 0, 1, 4), "TG thuong");
}
