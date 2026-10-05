## LASSO Regression From Scratch — Week 1

## What this project is about

This project is a small reusable C++ library for learning how LASSO regression works from the beginning. We are not using a ready-made machine-learning library. Instead, we are building the important parts ourselves using the C++ ideas we have learned: vectors, simple classes, functions, loops, calculations, file input, and error handling.

The project will eventually use LASSO to predict a numerical value from several input features. For example, it could predict an exam score from study hours, attendance, and assignment marks, or predict a house price from house size, bedrooms, and location-related measurements.

The Week 1 version is the foundation. It does not yet contain the complete coordinate-descent LASSO training algorithm. It prepares the data structures, calculations, baseline model, LASSO cost function, soft-thresholding function, tests, and project structure that will be extended in Weeks 2 and 3.

## What  is LASSO 

LASSO stands for Least Absolute Shrinkage and Selection Operator. It is a form of linear regression with an additional penalty.

Ordinary linear regression tries to find coefficients that make predictions close to the actual target values:

# #Plain Text
y = b0 + b1*x1 + b2*x2 + ... + bk*xk
LASSO adds a penalty based on the absolute values of the coefficients:

## Plain Text
LASSO cost = prediction error + lambda * sum of absolute coefficients

The penalty encourages unnecessary coefficients to become zero. When a coefficient becomes zero, the corresponding feature is not used by the model. This is why LASSO can perform feature selection as well as prediction.

The value lambda controls the strength of the penalty. A value of zero gives ordinary regression. A larger value produces more shrinkage and may remove more features. Choosing lambda will be added in a later week.

##  The problem we are solving
Given a dataset containing a target and one or more features, the final project should:
1.Load the numerical data.
2.Check that the data is valid.
3.Preprocess and scale the features.
4.Start with a linear-regression baseline.
5.Calculate the LASSO cost.
6.Use L1 regularization and coordinate descent to learn coefficients.
7.Use soft-thresholding to shrink coefficients.
8.Identify features whose coefficients become zero.
9.Tune lambda and evaluate the model.
10.Use the final coefficients to make predictions.

## What the current Week 1 code does

## Vector and matrix types

The header defines two simple type names:

C++
using Vector = std::vector<double>;
using Matrix = std::vector<Vector>;

A Vector is a list of decimal numbers. A Matrix is a list of vectors, so it can represent rows and columns of numerical data.
The matrix contains two rows:
1  2
3  4

## The Dataset structure

The Dataset structure is a user defined data type stores different data types under a single name:
C++
struct Dataset {
    Matrix features;
    Vector target;
};

features contains the input columns. target contains the value that we want to predict. Each target value must match the feature row at the same position.
For example:
Plain Text
features row 0 -> target 0
features row 1 -> target 1
features row 2 -> target 2

Keeping the rows and targets aligned is important. If they are mixed up, the model learns the wrong relationship.

## The LassoModel class
The project includes a beginner-level class as put below:
C++
class LassoModel {
public:
    void fit_baseline(const Vector& x, const Vector& y);
    double predict(double x) const;
    double intercept() const;
    double slope() const;
};
The class stores the intercept, the slope, and whether the model has been fitted. This introduces encapsulation: the model keeps its learned values inside the object and provides functions for using them.
In Week 1 part, the class stores a simple one-feature linear-regression baseline. 

## Fitting the baseline
The example creates a model object:
C++
lasso::LassoModel model;
Then it fits the baseline using input and target vectors:

C++
model.fit_baseline(
    {1, 2, 3, 4, 5},
    {52, 55, 61, 66, 70}
);
The program calculates the best straight line for the data:
 from, y = intercept + slope*x

The values are calculated using means, differences from the means, a numerator, and a denominator. The code uses simple loops so the calculation can be followed by a beginner.

## Making a prediction
After fitting, the program would now predict a value:
C++
double answer = model.predict(6.0);
The calculation is:
46.700 + 4.700 * 6 = 74.900
The example prints:
prediction for x=6 = 74.900

## The LASSO cost function
The function:
C++

double lasso_cost(
    const Matrix& features,
    const Vector& target,
    const Vector& coefficients,
    double lambda
);
calculates two parts:

1.The squared prediction error.
2.The L1 penalty, which is lambda multiplied by the sum of the absolute coefficient values.
The formula used is:
cost = squared_error / (2*n) + lambda * sum(abs(coefficients))

For Week 1, this function evaluates a set of coefficients supplied by the caller. It does not yet search for the best coefficients. Coordinate descent will repeatedly change the coefficients and call a similar calculation in Week 2.

## Soft-thresholding
The function:
C++
double soft_threshold(double value, double threshold);
shrinks a value toward zero:

soft_threshold(5, 2) = 3
soft_threshold(-5, 2) = -3
soft_threshold(1, 2) = 0

It is implemented with simple if statements. If the value is larger than the threshold, the threshold is subtracted. If the value is smaller than the negative threshold, the threshold is added. Otherwise, the result is zero.

This function is one of the main ideas behind LASSO feature selection. Small coefficients can become exactly zero.

## CSV loading

The function:
C++
Dataset load_csv(const std::string& path, bool has_header = true);

opens a CSV file, optionally skips the header row, reads each line, converts the cells to numbers, and stores the first value as the target. The remaining values become the feature row.

The sample file is:
target,feature_1,feature_2
5,1,2
4,2,1
7,3,2
The first row after the header is interpreted as:

target = 5
features = [1, 2]

The current loader is intentionally simple. More complete preprocessing, missing-value handling, and feature scaling will be developed by the assigned group members.

## How to run the project
Requirements:
A C++17 compiler such as GCC, Clang, or MSVC.
CMake 3.16 
Recommended CMake method

From inside the project directory, run:
Bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
./build/lasso_example

The commands have following meanings:
cmake -S . -B build reads CMakeLists.txt and prepares a build directory.
cmake --build build compiles the library, tests, and example.
ctest --test-dir build --output-on-failure runs the automated tests.
./build/lasso_example runs the demonstration program.
Direct g++ method

## What the tests check

tests/test_lasso.cpp checks the normal and invalid cases of the Week 1 foundation.

The tests verify that:
The dot product returns 32 for [1,2,3] and [4,5,6].
Matrix-vector multiplication returns [4,10] for the sample matrix.
Soft-thresholding shrinks positive and negative values correctly.
Values inside the threshold become zero.
The LASSO cost includes the L1 penalty.
The baseline regression recovers the relationship y = 1 + 2x.
The LassoModel class predicts correctly after fitting.
Invalid vector sizes produce std::invalid_argument.

Tests are important because successful compilation alone does not prove that numerical calculations are correct.

## Project folders
include/: public header files that users include.
src/: implementation files containing the calculations.
tests/: automated tests for expected and invalid behavior.
examples/: small programs showing how to use the library.
data/input/: sample input data.
data/output/: reserved for generated output in later weeks.
reports/: weekly progress reports and assignment information.
CMakeLists.txt: build instructions for CMake.


## License

This is an academic group project created for educational purposes.
See the `LICENSE` file for details.
