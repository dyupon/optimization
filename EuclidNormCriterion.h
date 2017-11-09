/** \brief Inherits from AbstractCriterion class to implement Euclid norm based stopping criterion **/

#ifndef NELDERMID_EUCLIDNORMCRITERIA_H
#define NELDERMID_EUCLIDNORMCRITERIA_H


#include "AbstractCriterion.h"

class EuclidNormCriterion : public AbstractCriterion {
public:
    explicit EuclidNormCriterion(double _eps);

    bool isConverged(const std::vector<double> &function, double dim) const override {
        return false;
    }

    bool isConverged(size_t dim,
                     const std::vector<double> &previousApproximation,
                     const std::vector<double> &newApproximation) const override;

    bool isConverged(size_t dim,
                     const std::vector<double> &previousApproximation,
                     const std::vector<double> &newApproximation,
                     FunctionImplementation *function) const override {
        return false;
    }

private:
    double eps;
    const int MAX_ITER_COUNT = 50000; /** Upper bound for probable amount of iterations for avoiding infinite looping**/
    mutable int iterCount; /** Keeps the number of iterations done while optimizing the function **/
};


#endif //NELDERMID_EUCLIDNORMCRITERIA_H
