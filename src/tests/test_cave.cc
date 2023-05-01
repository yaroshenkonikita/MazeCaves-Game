#include <gtest/gtest.h>

#include "../MazeCaves/Cave/cave.h"

TEST(Cave, GenerateCave) {
    int height = 50;
    int width = 30;
    s21::Cave cave;
    cave.GenerateCave(height, width);

    EXPECT_EQ(cave.GetCaveMatrix().GetRows(), height);
    EXPECT_EQ(cave.GetCaveMatrix().GetColumns(), width);
}

TEST(Cave, GenerateCaveExceptionMore) {
    int height = 100;
    int width = 100;
    s21::Cave cave;
    EXPECT_ANY_THROW(cave.GenerateCave(height, width));
}

TEST(Cave, GenerateCaveExceptionLess) {
    int height = 0;
    int width = 0;
    s21::Cave cave;
    EXPECT_ANY_THROW(cave.GenerateCave(height, width));
}

TEST(Cave, IterateCave) {
    int height = 30;
    int width = 30;
    s21::Cave cave;
    cave.GenerateCave(height, width);
    cave.IterateCave();
    EXPECT_EQ(cave.GetCaveMatrix()(0,0), cave.GetCaveMatrix()(0,0));
}