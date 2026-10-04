# LASSO Regression From Scratch — Week 1

## Project description

This project is a reusable C++17 library for implementing LASSO regression from scratch. LASSO, or Least Absolute Shrinkage and Selection Operator, extends linear regression by adding an L1 penalty to the cost function. The penalty encourages some coefficients to become exactly zero, which can perform feature selection.

This is the independent Week 1 submission. The goal this week is to establish the library structure, shared mathematical foundations, data contract, baseline regression, LASSO cost function, L1 concepts, and the work allocation for all 13 group members. Coordinate descent, complete model fitting, hyperparameter tuning, and final evaluation will be added in later weekly snapshots.

## Week 1 objectives

The group will create a library rather than a single monolithic program. The public API is separated from the implementation, foundational operations are reusable, input errors are checked, and the first tests and example are included from the beginning.

## Week 1 features implemented

- C++17 reusable-library structure.
- Vector dot product and matrix-vector multiplication.
- Soft-thresholding helper.
- LASSO objective function:

  `J(beta) = (1/(2n)) * sum((y - X beta)^2) + lambda * sum(abs(beta))`

- Ordinary linear-regression baseline for one feature.
- Basic numerical CSV loader with target in the first column.
- Tests for normal behavior and invalid input.
- CMake build configuration and example program.

## Project structure

```text
lasso-regression-week-01/
├── README.md
├── CMakeLists.txt
├── LICENSE
├── .gitignore
├── include/lasso/lasso_regression.hpp
├── src/lasso_regression.cpp
├── tests/test_lasso.cpp
├── examples/basic_example.cpp
├── data/input/sample.csv
└── reports/week-01.md
```

## Requirements and build

Requirements are a C++17 compiler and CMake 3.16 or newer. No external machine-learning library is used.

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
./build/lasso_example
```

## Week 1 API example

```cpp
#include "lasso/lasso_regression.hpp"

int main() {
    const auto baseline = lasso::linear_regression_baseline(
        {1, 2, 3, 4}, {3, 5, 7, 9});
    const double shrunk = lasso::soft_threshold(5.0, 2.0);
}
```

## Important design decisions

The first column of a CSV row is the target and the remaining columns are features. The Week 1 cost function accepts a feature matrix and coefficient vector of matching width. The intercept is not penalized by the future optimizer; the current cost helper represents the coefficient vector supplied by the caller, so the intercept convention must be documented when the fitting class is added.

SMOTE is not part of the LASSO topic shown in the supplied image. It should not be inserted unless the group receives a separate requirement and can justify it.

## Contributions

The names below are placeholders. Replace `Member 1` through `Member 13` with real names and student numbers before submission. Each member should create a focused branch or commit and continue developing the same module in Weeks 2 and 3.

The complete assignment table is in `reports/week-01.md`.

## Limitations and planned work

The Week 1 scaffold does not yet fit a LASSO model. It prepares the objective, soft-thresholding, data, and linear-algebra foundations. Week 2 will integrate the modules and implement coordinate descent and feature selection. Week 3 will add tuning, evaluation, prediction, and final integration. Week 4 will be used for final testing, reports, Git/GitHub review, presentation preparation, and packaging.
