#include "lasso/lasso_regression.hpp"
#include <iomanip>
#include <iostream>
using namespace lasso;
using namespace std;
int main(){

    LassoModel model;
    model.fit_baseline({1, 2, 3, 4, 5}, {52, 55, 61, 66, 70});
             cout <<fixed <<setprecision(3)
              << "baseline: y = " << model.intercept() << " + " << model.slope() << "x\n"
              << "prediction for x=6 = " <<model.predict(6.0) << "\n"
              << "soft threshold(5, 2) = " <<soft_threshold(5.0, 2.0) << "\n";
}
