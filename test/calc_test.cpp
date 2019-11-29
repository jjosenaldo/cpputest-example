// t/test.cpp
#include "CppUTest/TestHarness.h"
#include "calc.h"


TEST_GROUP(TestCalc)
{
};

TEST(TestCalc, testSum)
{
  CHECK_EQUAL(sum(5,4), 9);
}

TEST(TestCalc, testProd)
{
  CHECK_EQUAL(prod(5,4), 20);
}
