#include "lasso/lasso_regression.hpp"
#include <cassert>
#include <cmath>
#include <iostream>
#include <stdexcept>
 using namespace lasso;
using namespace std;

int main() {
    assert(std::abs(dot({1, 2, 3}, {4, 5, 6}) - 32.0) < 1e-12);
    const auto product = matrix_vector_product({{1, 2}, {3, 4}}, {2, 1});
    assert(product.size() == 2 && product[0] == 4.0 && product[1] == 10.0);
    assert(soft_threshold(5.0, 2.0) == 3.0);
    assert(soft_threshold(-5.0, 2.0) == -3.0);
    assert(soft_threshold(1.0, 2.0) == 0.0);

    const Matrix features{{1, 2}, {2, 1}};
    const Vector target{5, 4};
    const Vector coefficients{1, 2};
    assert(abs(lasso_cost(features, target, coefficients, 0.5) - 1.5) < 1e-12);

    const auto baseline = lasso::linear_regression_baseline({1, 2, 3, 4}, {3, 5, 7, 9});
    assert(abs(baseline.intercept - 1.0) < 1e-12);
    assert(abs(baseline.slope - 2.0) < 1e-12);
    assert(baseline.mse < 1e-12);

    lasso::LassoModel model;
    model.fit_baseline({1, 2, 3}, {3, 5, 7});
    assert(abs(model.predict(4.0) - 9.0) < 1e-12);

    bool rejected = false;
    try { dot({1}, {1, 2}); }
    catch (const invalid_argument&) { rejected = true; }
    assert(rejected);
    cout << "All LASSO Week 1 tests passed.\n";
}
