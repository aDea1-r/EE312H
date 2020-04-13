#include "test_helper.h"
#include "MazeParams.h"
#include "Maze.h"
#include "Recursion.h"

TEST(TestMin, test1)
{
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    EXPECT_EQ(minRec1(nums, 10), 1);
    nums[3] = -1;
    EXPECT_EQ(minRec1(nums, 10), -1);
}

TEST(TestMin, test2)
{
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    EXPECT_EQ(minRec2(nums, 10), 1);
    nums[3] = -1;
    EXPECT_EQ(minRec2(nums, 10), -1);
}

TEST(TestSqrt, test1)
{
    double vals[] = { 25.0, 26.0, 2.0 };
    testSquareRoot(vals, ARRAYSIZE(vals), sqrtRec);
}

TEST(TestString, test1)
{
    char *s1, *s2;

    // strCompare Tests
    s1 = (char *)"apple\0\0";
    s2 = (char *)"apricot";
    EXPECT_LT(strCompare(s1, s2), 0);

    s1 = (char *)"Apple";
    s2 = (char *)"apple";
    EXPECT_LT(strCompare(s1, s2), 0);

    s1 = (char *)"baby boy";
    s2 = (char *)"banana\0\0";
    EXPECT_LT(strCompare(s1, s2), 0);

    s1 = (char *)"a rather silly string";
    s2 = (char *)"a rather silly string";
    EXPECT_EQ(strCompare(s1, s2), 0);
}

TEST(TestString, test2)
{
    char *s1, *s2;

    // strCompare Tests
    s1 = (char *)"12345";
    s2 = (char *)"12345";
    EXPECT_EQ(strCompare(s1, s2), 0);

    s1 = (char *)"Numbers: 12345";
    s2 = (char *)"12345\0\0\0\0\0\0\0\0\0";
    EXPECT_GT(strCompare(s1, s2), 0);

    s1 = (char *)"Texas\0\0\0\0\0";
    s2 = (char *)"California";
    EXPECT_GT(strCompare(s1, s2), 0);
}

TEST(TestString, test3)
{
    char *s1, *s2;

    // strCompare2 Tests
    s1 = (char *)"apple\0\0";
    s2 = (char *)"Apricot";
    EXPECT_LT(strCompare2(s1, s2), 0);

    s1 = (char *)"Batman!\0";
    s2 = (char *)"bat man\0";
    EXPECT_EQ(strCompare2(s1, s2), 0);

    s1 = (char *)"OMG, WTF?\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    s2 = (char *)"oh my goodness, what the heck?";
    EXPECT_GT(strCompare2(s1, s2), 0);
}
