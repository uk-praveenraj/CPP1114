#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <string>

const std::string RESULT{"Result: "};

std::string runCalculatorWithArgs(const std::string& input) {
    // Write to temp file
    std::ofstream inputFile("input.txt");
    inputFile << input;
    inputFile.close();

    // Run and redirect to output.txt
    std::system("./CalculatorCLI < input.txt > output.txt");

    // Read the result from output file
    std::ifstream outputFile("output.txt");
    std::string output((std::istreambuf_iterator<char>(outputFile)),
                        std::istreambuf_iterator<char>());
    outputFile.close();

    // Cleanup
    std::remove("input.txt");
    std::remove("output.txt");

    return output;
}

TEST(EndToEndTest, AdditionTestInt) {
    std::string input = "2 + 3\n";  // fake input
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"5") != std::string::npos);
}

TEST(EndToEndTest, AdditionTestNegative) {
    std::string input = "-2 + 3\n";  // fake input
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"1") != std::string::npos);
}

TEST(EndToEndTest, AdditionTestDouble) {
    std::string input = "2.0 + 3.5\n";
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"5.5") != std::string::npos);
}

TEST(EndToEndTest, SubtractionTestInt) {
    std::string input = "10 - 6\n";
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"4") != std::string::npos);
}

TEST(EndToEndTest, SubtractionTestNegative) {
    std::string input = "-10 - -6\n";
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"-4") != std::string::npos);
}

TEST(EndToEndTest, SubtractionTestDouble) {
    std::string input = "10.0 - 5.5\n";
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"4.5") != std::string::npos);
}

TEST(EndToEndTest, MultiplicationTestInt) {
    std::string input = "5 * 3\n";
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"15") != std::string::npos);
}

TEST(EndToEndTest, MultiplicationTestNegative) {
    std::string input = "-5 * -2.6\n";
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"13") != std::string::npos);

    input = "5 * -2.6\n";
    output = runCalculatorWithArgs(input);
    EXPECT_TRUE(output.find(RESULT+"-13") != std::string::npos);
}

TEST(EndToEndTest, MultiplicationTestDouble) {
    std::string input = "5.2 * 2.6\n";
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"13.52") != std::string::npos);
}

TEST(EndToEndTest, DivisionTestInt) {
    std::string input = "5 / 3\n";
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"1.66667") != std::string::npos);
}

TEST(EndToEndTest, DivisionTestDouble) {
    std::string input = "20.50 / 2.2\n";
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"9.31818") != std::string::npos);
}

TEST(EndToEndTest, DivisionTestNegative) {
    std::string input = "-10 / -2\n";
    std::string output = runCalculatorWithArgs(input);

    EXPECT_TRUE(output.find(RESULT+"5") != std::string::npos);

    input = "-10 / 2\n";
    output = runCalculatorWithArgs(input);
    EXPECT_TRUE(output.find(RESULT+"-5") != std::string::npos);
}

TEST(EndToEndTest, DivisionByZeroTest) {    
    std::string input = "4.0 / 0.0\n";
    std::string output;
    try{
        output = runCalculatorWithArgs(input);
    } catch(const std::invalid_argument& e){
        EXPECT_STREQ( "Divide by zero error", e.what() );
    }
}


