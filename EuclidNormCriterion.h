//
// Created by User on 10/12/2017.
//

#ifndef NELDERMID_EUCLIDNORMCRITERIA_H
#define NELDERMID_EUCLIDNORMCRITERIA_H


#include "AbstractCriterion.h"

class EuclidNormCriterion: public AbstractCriterion {
public:
    EuclidNormCriterion();
    bool is_converged(std::vector<double> function) const override;
    bool is_converged(int dim, double eps, std::vector<double> previous_approximation, std::vector<double> new_approximation) const override;
private:
    const int MAX_ITER_COUNT = 50000;
    mutable int iter_count;
};


#endif //NELDERMID_EUCLIDNORMCRITERIA_H
