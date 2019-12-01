#include "CppUTest/TestHarness.h"
#include "calc.h"


TEST_GROUP(TestCalc)
{
};

TEST(TestCalc, testSumOverflow)
{
  CHECK_EQUAL(INT_MAX, sum(INT_MAX - 50, 100));
}

TEST(TestCalc, testSumUnderflow)
{
  CHECK_EQUAL(INT_MIN, sum(-10,INT_MIN));
}

TEST(TestCalc, testRegularSum){
    CHECK_EQUAL(10, sum(6,4));
}