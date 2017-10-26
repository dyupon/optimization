#ifndef NELDERMID_ABSTRACTCRITERION_H
#define NELDERMID_ABSTRACTCRITERION_H


#include <vector>
#include <cstddef>

class AbstractCriterion {
public:
    virtual bool is_converged(const std::vector<double> &function) const = 0;

    virtual bool is_converged(size_t dim,
                              double eps,
                              const std::vector<double> &previous_approximation,
                              const std::vector<double> &new_approximation) const = 0;
};

#endif //NELDERMID_ABSTRACTCRITERION_H
