/** \brief Abstract base class for criterion of stopping **/

#ifndef NELDERMID_ABSTRACTCRITERION_H
#define NELDERMID_ABSTRACTCRITERION_H


#include <vector>
#include <cstddef>
#include "FunctionImplementation.h"

class AbstractCriterion {
public:
    explicit AbstractCriterion(double _eps) : eps(_eps), iterCount(0) {

    }

    virtual bool isConverged(
            const std::vector<double> &function,
            double dim) const = 0; /** Checks if the current approximation is good enough based on eps-difference between function meanings **/

    virtual bool isConverged(size_t dim,
                             const std::vector<double> &previousApproximation,
                             const std::vector<double> &newApproximation) const = 0; /** Checks if the current approximation is good enough considering eps-meaning of the Euclid norm of approximation points difference **/

    virtual bool isConverged(size_t dim,
                             const std::vector<double> &previousApproximation,
                             const std::vector<double> &newApproximation,
                             FunctionImplementation *function) const = 0;

protected:
    double eps;
    const int MAX_ITER_COUNT = 50000; /** Upper bound for probable amount of iterations for avoiding infinite looping**/
    mutable int iterCount; /** Keeps the number of iterations done while optimizing the function **/


};

#endif //NELDERMID_ABSTRACTCRITERION_H
