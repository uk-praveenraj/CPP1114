#include <gtest/gtest.h>
#include <iostream>

/*to compile
1. cmake -S . -B build  -G "MinGW Makefiles"
2. cmake --build build   from unit-test directory
3. .\build\hello_test.exe
*/
class Leapyear{
    public:
        Leapyear(){};
        ~Leapyear(){};
        bool isLeap(int year){
            // leap year if perfectly divisible by 400
            if (year % 400 == 0) {
                return true;
            }
            // not a leap year if divisible by 100
            // but not divisible by 400
            else if (year % 100 == 0) {
            return false;
            }
            // leap year if not divisible by 100
            // but divisible by 4
            else if (year % 4 == 0) {
                return true;
            }
            // all other years are not leap years
            else {
                return false;
            }
        }
};

// // Demonstrate some basic assertions.
// TEST(HelloTest, BasicAssertions) {
//   // Expect two strings not to be equal.
//   EXPECT_STRNE("hello", "world");
//   // Expect equality.
//   EXPECT_EQ(7 * 6, 421);
// }

class LeapYearMultipleParametersTests :public ::testing::TestWithParam<std::tuple<int, bool>> {
protected:
    Leapyear leapYear;
};

TEST_P(LeapYearMultipleParametersTests, ChecksIfLeapYear) {
    bool expected = std::get<1>(GetParam());
    int year = std::get<0>(GetParam());
    ASSERT_EQ(expected, leapYear.isLeap(year));
}

INSTANTIATE_TEST_CASE_P(
        LeapYearTests,
        LeapYearMultipleParametersTests,
        ::testing::Values(
                std::make_tuple(7, false),
                std::make_tuple(2001, false),
                std::make_tuple(1996, true),
                std::make_tuple(1700, false),
                std::make_tuple(1600, true)));

class fixtureTest : public ::testing::Test{    
    protected:
    fixtureTest(){};
    virtual void setup(){
        str1= "I am a string";
        str2= "I am also a string";
    }
    virtual void teardown(){
        str1=str2= "";
    }
    std::string str1, str2;
};

TEST_F(fixtureTest, equalTest){
    ASSERT_TRUE(str1 == str2 );
    ASSERT_TRUE(str1 != str2 );
}