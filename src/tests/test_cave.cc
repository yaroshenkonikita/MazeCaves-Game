#include <gtest/gtest.h>

#include "../MazeCaves/Cave/cave.h"

TEST(Cave, GenerateCave) {
    int height = 50;
    int width = 30;
    s21::Cave cave;
    cave.GenerateCave(height, width);

    EXPECT_EQ(cave.GetCaveMatrix().GetRows(), height);
    EXPECT_EQ(cave.GetCaveMatrix().GetColumns(), width);

    s21::Matrix matrix = cave.GetCaveMatrix();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            EXPECT_TRUE(matrix(i,j) == 1 || matrix(i, j) == 0);
        }
    }
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

TEST(Cave, ConstructorDefault) {
    s21::Cave cave;
    EXPECT_EQ(cave.GetBirthLimit(), 3);
    EXPECT_EQ(cave.GetDeathLimit(), 3);
    EXPECT_EQ(cave.GetChanceToSpawn(), 0.3);
}

TEST(Cave, Setters) {
    s21::Cave cave;
    cave.SetBirthLimit(6);
    cave.SetDeathLimit(1);
    cave.SetChanceToSpawn(0.55);
    EXPECT_EQ(cave.GetBirthLimit(), 6);
    EXPECT_EQ(cave.GetDeathLimit(), 1);
    EXPECT_EQ(cave.GetChanceToSpawn(), 0.55);
}

TEST(Cave, Setters_exception) {
    s21::Cave cave;
    EXPECT_ANY_THROW(cave.SetBirthLimit(100));
    EXPECT_ANY_THROW(cave.SetDeathLimit(-100));
    EXPECT_ANY_THROW(cave.SetChanceToSpawn(2));
}

TEST(Cave, SaveCave) {
    int height = 30;
    int width = 30;
    s21::Cave cave;
    cave.GenerateCave(height, width);
    cave.SaveToFile("tests/SavedCave.txt");

    s21::Cave loadCave;
    loadCave.LoadFromFile("tests/SavedCave.txt");
    EXPECT_TRUE(cave.GetCaveMatrix() == loadCave.GetCaveMatrix());
}

TEST(Cave, LoadCave) {
    s21::Cave cave;
    cave.LoadFromFile("tests/cave.txt");

    s21::Matrix matrix = cave.GetCaveMatrix();
    for (int i = 0; i < matrix.GetRows(); ++i) {
        for (int j = 0; j < matrix.GetColumns(); ++j) {
            EXPECT_TRUE(matrix(i,j) == 1 || matrix(i, j) == 0);
        }
    }
}

TEST(Cave, LoadCaveNoExists) {
    s21::Cave cave;
    EXPECT_ANY_THROW(cave.LoadFromFile("tests/no_exist.txt"));

    s21::Matrix matrix = cave.GetCaveMatrix();
    for (int i = 0; i < matrix.GetRows(); ++i) {
        for (int j = 0; j < matrix.GetColumns(); ++j) {
            EXPECT_TRUE(matrix(i,j) == 1 || matrix(i, j) == 0);
        }
    }
}

TEST(Cave, LoadCaveInvalid) {
    s21::Cave cave;
    EXPECT_ANY_THROW(cave.LoadFromFile("tests/cave_invalid.txt"));

    s21::Matrix matrix = cave.GetCaveMatrix();
    for (int i = 0; i < matrix.GetRows(); ++i) {
        for (int j = 0; j < matrix.GetColumns(); ++j) {
            EXPECT_TRUE(matrix(i,j) == 1 || matrix(i, j) == 0);
        }
    }
}

TEST(Cave, LoadCaveInvalidSize) {
    s21::Cave cave;
    EXPECT_ANY_THROW(cave.LoadFromFile("tests/cave_invalid_size.txt"));

    s21::Matrix matrix = cave.GetCaveMatrix();
    for (int i = 0; i < matrix.GetRows(); ++i) {
        for (int j = 0; j < matrix.GetColumns(); ++j) {
            EXPECT_TRUE(matrix(i,j) == 1 || matrix(i, j) == 0);
        }
    }
}

TEST(Cave, CaveIteration) {
    s21::Cave cave;
    cave.LoadFromFile("tests/cave.txt");

    cave.IterateCave();

    s21::Matrix matrix_suppose(4,4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrix_suppose(i, j) = 1;
            if ((i == 1 && j == 1) || (i == 2 && j == 1)) {
                matrix_suppose(i, j) = 0;
            }
        }
    }

    s21::Matrix matrix = cave.GetCaveMatrix();
    for (int i = 0; i < matrix.GetRows(); ++i) {
        for (int j = 0; j < matrix.GetColumns(); ++j) {
            EXPECT_TRUE(matrix(i,j) == 1 || matrix(i, j) == 0);
        }
    }
    
    EXPECT_TRUE(matrix_suppose == matrix);
}
