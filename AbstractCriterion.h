/** \brief Abstract base class for criterion of stopping **/

#ifndef NELDERMID_ABSTRACTCRITERION_H
#define NELDERMID_ABSTRACTCRITERION_H


#include <vector>
#include <cstddef>

class AbstractCriterion {
public:
    virtual bool isConverged(
            const std::vector<double> &function) const = 0; /** Checks if the current approximation is good enough based on eps-difference between function meanings **/

    virtual bool isConverged(size_t dim,
                             double eps,
                             const std::vector<double> &previous_approximation,
                             const std::vector<double> &new_approximation) const = 0; /** Checks if the current approximation is good enough considering eps-meaning of the Euclid norm of function meanings difference **/
};

#endif //NELDERMID_ABSTRACTCRITERION_H
