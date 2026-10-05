# Week 1 Progress Report — LASSO Regression From Scratch

## Project topic

The project topic: LASSO regression from scratch. The group will build a reusable C++17 library, following the C++ Group Project Instructions. LASSO is a regularized linear-regression method that uses an L1 penalty to shrink coefficients and select useful features. In simple terms LASSO is a method that helps choose tte most important variables in a data set.

## Parts taken from the given topic

The image lists the following 13 project parts. The group has 9 members, so the different parts were assigned to each member. Each member began the assigned part in Week 1 and will continue adding to, testing, documenting, and integrating that same part in Weeks 2 and 3.

## Work contribution of memebers for week 1

KALID ALIAS  | Dataset loading , Define the CSV format, target/feature convention, and invalid-file cases. 

Karungi Mary Gorret| Data preprocessing .. Define missing-value, malformed-row, and input-validation rules.

Nantale Pauline | Feature scaling and Feature selection | Compare standardization and min-max scaling; define API and leakage rules and Define how zero/non-zero coefficients will be reported. 

Alinda Larry Musiimenta| Matrix and vector operations, | Define `Vector`, `Matrix`, dot product, and matrix-vector requirements. 

Mutonyi Mercy Jesca| Linear regression baseline | Define the unregularized baseline and reference metrics.

Ssenabulya Samuel | LASSO cost function | Document the squared-error term, lambda, and L1 penalty.

Mawanda Hakim| L1 regularization,Prediction  | Explain why absolute-value penalties shrink coefficients and may produce zeros, Define the prediction API and input-dimension validation.

Asiimwe Mary | Coordinate descent optimization,Model evaluation | Study the coordinate-wise update and convergence requirements,  Select MSE, RMSE, MAE, R², and train/validation/test reporting. 

Bukenya Ivan Lubega| Soft-thresholding, Hyperparameter tuning | Define and test the soft-threshold operator used by coordinate descent, Define lambda candidates, validation strategy, and reproducibility rules. 


## Completed
- Created a reusable C++17 project structure with `include/`, `src/`, `tests/`, `examples/`, `reports/`, and `data/` directories.
- Defined initial `Vector`, `Matrix`, `Dataset`, and baseline-result types.
- Implemented dot product and matrix-vector multiplication with dimension validation.
- Implemented the soft-thresholding helper.
- Implemented the LASSO cost function with squared-error and L1 terms.
- Implemented a one-feature ordinary linear-regression baseline.
- Implemented a basic numerical CSV loader.
- Added a CMake configuration, example, and Week 1 tests.

## Challenges/Blockers
- Scaling must be learned from training data only; using all data before the split would cause leakage.
- Debugging errors: identifying and fixing syntax, logical, and run time errors in the code 
- Testing: Testing different inputs and situations to ensure the program behaves as expected 
- Input validation: Handling invalid or unexpected user inputs without the program crashing

## Next Week

- Implement data preprocessing and feature scaling.
- Implement the linear-regression baseline as a reusable model.
- Complete and test the LASSO cost function and L1 regularization support.
- Implement coordinate descent using soft-thresholding.
- Add feature-selection reporting and prediction APIs.
- Merge member branches through reviewed pull requests.

## AI Use

Tool: Manus AI assistant.
Purpose: Help in debugging the codes in the example, tests and include. 
Reason: The ai was used to indentify the errors, explain why they were occuring, and suggest possible corrections. We reviewed and the implemented the relevant corrections ourselves.