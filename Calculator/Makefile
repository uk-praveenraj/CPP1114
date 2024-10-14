# variables
CXX = g++
CXXFLAGS = -Wall -std=c++14
LDFLAGS = -lgtest -lgtest_main -pthread

# targets
all: CalculatorCLI unit_tests e2e_tests

CalculatorCLI: Calculator.o CalculatorCLI.o
	$(CXX) $(CXXFLAGS) -o CalculatorCLI Calculator.o CalculatorCLI.o

unit_tests: Calculator.o CalculatorTest.o
	$(CXX) $(CXXFLAGS) -o unit_tests Calculator.o CalculatorTest.o $(LDFLAGS)

e2e_tests: Calculator.o e2e-test.o
	$(CXX) $(CXXFLAGS) -o e2e-test Calculator.o e2e-test.o $(LDFLAGS)

# object files
Calculator.o: Calculator.cpp Calculator.h
	$(CXX) $(CXXFLAGS) -c Calculator.cpp

CalculatorCLI.o: CalculatorCLI.cpp
	$(CXX) $(CXXFLAGS) -c CalculatorCLI.cpp

CalculatorTest.o: tests/CalculatorTest.cpp
	$(CXX) $(CXXFLAGS) -c tests/CalculatorTest.cpp

e2e-test.o: tests/e2e-test.cpp
	$(CXX) $(CXXFLAGS) -c tests/e2e-test.cpp

# clean build files
clean:
	rm -f *.o CalculatorCLI unit_tests e2e_tests

# run unit tests
test: unit_tests
	./unit_tests

# run the Calculator CLI
run: CalculatorCLI
	./CalculatorCLI

# run end-to-end test
e2e: e2e_tests
	./e2e_tests

.PHONY: clean test run e2e
