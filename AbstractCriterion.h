#ifndef NELDERMID_ABSTRACTCRITERION_H
#define NELDERMID_ABSTRACTCRITERION_H


#include <vector>

class AbstractCriterion {
public:
    virtual bool is_converged(std::vector<double> function) = 0;
    virtual bool is_converged(int dim, double eps, std::vector<double> previous_approximation, std::vector<double> new_approximation) = 0;
};



#endif //NELDERMID_ABSTRACTCRITERION_H
