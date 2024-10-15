# Calculator

## Dependency
Install google test library, if not already available

## Build Instructions
1. Clone the repository or extract the archive.
2. Run the following command to build the project:
   ```bash
      make
   ```

Note: Build and tested in Linux (Ubuntu)

Usage:
1. Run the calculator
    ```bash
    make run
    ```    
2. To run unit-tests (gtest)
    ```bash
    make test
    ```
3. To run End to End test cases (gtest)
    ```bash
    make e2e
    ```
4. To cleanup 
    ```bash
    make clean
    ```

## Code Coverage
Ensure lcov is installed 
1. Enable the flags in Makefile 
    ```bash
    -fprofile-arcs -ftest-coverage
    ```
2. Run the below commands to make it with coverage info
    ```bash
    make all
    make tests
    make e2e
    ```
3. Run getCov.sh
    ```bash
    ./getCov.sh
    ```
4. The html report can be found in the file: cov/index.html

