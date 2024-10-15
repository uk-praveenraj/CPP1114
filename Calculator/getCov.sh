
#!/bin/sh
#Run this from Calculator directory

# create a dir
mkdir cov
#create gcov file
gcov Calculator.o CalculatorCLI.o
lcov --directory . --capture --output-file app.info

mv *.gcno cov/
mv *.gcda cov/

cd cov

#Create html files
lcov --directory . --capture --output-file app.info

# Generate HTML view:
genhtml app.info
